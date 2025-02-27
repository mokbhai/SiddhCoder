import numpy as np
from flask import Flask, request, jsonify, render_template
import torch
import cv2 as cv
from flask_cors import CORS  # Import CORS
import pytesseract
import os
from datetime import datetime

app = Flask(__name__)
CORS(app)

# Add new constants
SAVE_DIR = 'saved_data'
IMAGES_DIR = os.path.join(SAVE_DIR, 'images')
LABELS_DIR = os.path.join(SAVE_DIR, 'labels')

# Create directories if they don't exist
os.makedirs(IMAGES_DIR, exist_ok=True)
os.makedirs(LABELS_DIR, exist_ok=True)

# Load YOLOv5 model
yolo = torch.hub.load('ultralytics/yolov5', 'custom', path='./yolov5/runs/train/exp/weights/best.pt')

def upscale_image(image, scale_percent=200):
    """
    Upscale the image by a given percentage.
    """
    width = int(image.shape[1] * scale_percent / 100)
    height = int(image.shape[0] * scale_percent / 100)
    dim = (width, height)
    return cv.resize(image, dim, interpolation=cv.INTER_CUBIC)

import re

def read_plate_number(results, frame):
    """
    Extract and read the license plate number from the detected bounding boxes.
    """
    n = len(results)
    x_shape, y_shape = frame.shape[1], frame.shape[0]
    coordinates = results

    for i in range(n):
        row = coordinates[i]  # Iterate through each detection
        if row[4] >= 0.5:  # Confidence threshold
            xmin, ymin, xmax, ymax = map(int, row[:4])
            plate = frame[ymin:ymax, xmin:xmax]

            # Preprocess Plate
            gray = cv.cvtColor(plate, cv.COLOR_BGR2GRAY)
            blurred = cv.bilateralFilter(gray, 13, 15, 15)

            # Upscale the image
            upscaled = upscale_image(blurred, scale_percent=200)

            # OCR using PyTesseract
            text = pytesseract.image_to_string(upscaled, config='--psm 11')
            # Remove non-alphanumeric characters
            cleaned_text = re.sub(r'[^A-Za-z0-9]', '', text.strip())
            return cleaned_text  # Return the cleaned text

    return None  # No plate detected

def save_detection_data(image, coordinates, plate_text):
    """
    Save the image and its corresponding coordinates for future training.
    """
    try:
        # Generate timestamp for unique filename
        timestamp = datetime.now().strftime('%Y%m%d_%H%M%S_%f')
        
        # Save the image
        image_filename = f'plate_{timestamp}.jpg'
        image_path = os.path.join(IMAGES_DIR, image_filename)
        cv.imwrite(image_path, cv.cvtColor(image, cv.COLOR_RGB2BGR))
        
        # Save the coordinates and plate text
        label_filename = f'plate_{timestamp}.txt'
        label_path = os.path.join(LABELS_DIR, label_filename)
        
        with open(label_path, 'w') as f:
            # Save each detection's coordinates and confidence
            for coord in coordinates:
                # Convert to YOLO format (normalized coordinates)
                x_center = ((coord[0] + coord[2]) / 2) / image.shape[1]
                y_center = ((coord[1] + coord[3]) / 2) / image.shape[0]
                width = (coord[2] - coord[0]) / image.shape[1]
                height = (coord[3] - coord[1]) / image.shape[0]
                confidence = coord[4] if len(coord) > 4 else 1.0
                
                # Save in YOLO format: class x_center y_center width height confidence
                f.write(f"0 {x_center} {y_center} {width} {height} {confidence}\n")
            
            # Save the detected plate text as a comment
            f.write(f"# Detected plate text: {plate_text}\n")
            
        return True
    except Exception as e:
        print(f"Error saving detection data: {str(e)}")
        return False

@app.route('/plate_recognition', methods=['POST'])
def plate_recognition():
    """
    Flask route to handle license plate recognition.
    """
    try:
        if 'image' not in request.files:
            return jsonify({'error': 'No image provided'}), 400

        image = request.files['image']
        img = cv.imdecode(np.frombuffer(image.read(), np.uint8), cv.IMREAD_COLOR)
        img = cv.cvtColor(img, cv.COLOR_BGR2RGB)

        results = yolo(img)
        coordinates = results.xyxy[0][:, :-1].cpu().numpy()

        plate_text = read_plate_number(coordinates, img)
        
        # Save the detection data
        if plate_text:
            save_detection_data(img, coordinates, plate_text)
            return jsonify({'plate_text': plate_text}), 200
        else:
            return jsonify({'error': 'No plate detected'}), 200

    except Exception as e:
        return jsonify({'error': str(e)}), 500

@app.route('/', methods=['GET'])
def html():
    """
    Flask route to render the HTML page.
    """
    try:
        return render_template('index.html'), 200
    except Exception as e:
        return jsonify({'error': str(e)}), 500

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=3008)  # Run on all interfaces
