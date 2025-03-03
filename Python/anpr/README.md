# Automatic Number Plate Recognition (ANPR) System

This project implements an Automatic Number Plate Recognition system using YOLOv5 for license plate detection and EasyOCR for text recognition.

## Features

- License plate detection using YOLOv5
- Text recognition using EasyOCR
- Web interface for uploading and processing images
- Real-time processing capabilities

## Prerequisites

- Python 3.8 or higher
- pip (Python package installer)
- Virtual environment (recommended)

## Installation

1. Clone the repository:

```bash
git clone https://github.com/mokbhai/SiddhCoder
cd SiddhCoder/Python/anpr
```

2. Create and activate a virtual environment (recommended):

```bash
python -m venv .venv
# On Windows
.venv\Scripts\activate
# On macOS/Linux
source .venv/bin/activate
```

3. Install the required dependencies:

```bash
pip install -r requirements.txt
```

Note: To use pytesseract, you'll also need to install the Tesseract OCR engine on your system:
For macOS: brew install tesseract
For Ubuntu/Debian: sudo apt-get install tesseract-ocr
For Windows: Download and install from the official GitHub releases

## Usage

1. Start the Flask application:

```bash
python model.py
```

2. Open your web browser and navigate to:

```
http://localhost:5000
```

3. Upload an image containing a license plate through the web interface.

4. The system will process the image and display the detected license plate number.

## Project Structure

- `model.py`: Main application file containing the ANPR logic and Flask server
- `requirements.txt`: List of Python dependencies
- `templates/`: Directory containing HTML templates for the web interface
- `yolov5/`: YOLOv5 model files
- `saved_data/`: Directory for storing processed data
- `anpr-with-yolo-easyocr.ipynb`: Jupyter notebook with development and testing code

## Dependencies

- Flask: Web framework
- PyTorch: Deep learning framework
- OpenCV: Computer vision library
- EasyOCR: Optical Character Recognition library
- Ultralytics: YOLOv5 implementation
- NumPy: Numerical computing library

## Notes

- Make sure you have sufficient disk space for the YOLOv5 model weights
- The system performs best with clear, well-lit images of license plates
- Processing time may vary depending on your hardware configuration