import numpy as np
from flask import Flask, request, jsonify, render_template
import torch
import cv2 as cv
from flask_cors import CORS  # Import CORS
import pytesseract

app = Flask(__name__)
CORS(app)

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
            return text.strip()  # Return the detected text

    return None  # No plate detected

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

        if plate_text:
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