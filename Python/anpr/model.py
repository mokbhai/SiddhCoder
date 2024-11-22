import numpy as np
from flask import Flask, request, jsonify, render_template
import torch
import cv2 as cv
import easyocr

app = Flask(__name__)

# Load YOLOv5 model
yolo = torch.hub.load('ultralytics/yolov5', 'custom', path='./yolov5/runs/train/exp/weights/best.pt')

# Initialize EasyOCR reader
reader = easyocr.Reader(['en'])

def read_plate_number(results, frame):
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
            blurred = cv.bilateralFilter(gray, 17, 15, 15)

            # OCR
            text = reader.readtext(blurred)
            text = ' '.join([t[1] for t in text])

            return text.strip()  # Return the detected text

    return None  # No plate detected

@app.route('/plate_recognition', methods=['POST'])
def plate_recognition():
    try:
        if 'image' not in request.files:
            return jsonify({'error': 'No image provided'}), 400

        image = request.files['image']
        img = cv.imdecode(np.frombuffer(image.read(), np.uint8), cv.IMREAD_COLOR)
        img = cv.cvtColor(img, cv.COLOR_BGR2RGB)

        results = yolo(img)
        coordinates = results.xyxy[0][:, :-1].cpu().numpy()  # Convert to numpy array

        plate_text = read_plate_number(coordinates, img)

        if plate_text:
            return jsonify({'plate_text': plate_text}), 200
        else:
            return jsonify({'error': 'No plate detected'}), 200

    except Exception as e:
        return jsonify({'error': str(e)}), 500

@app.route('/', methods=['GET'])
def html():
    try:
        return render_template('index.html'), 200
    except Exception as e:
        return jsonify({'error': str(e)}), 500

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=3008)  # Run on all interfaces