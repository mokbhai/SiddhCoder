from gradio_client import Client, handle_file
import os

# Specify the path to the image using a raw string to avoid escape sequence issues
image_path = './image.png'

# Create a Gradio client
client = Client("pjdevelop/dinov2-currency_indian")

# Ensure the file exists
if os.path.exists(image_path):
    # Use the handle_file function to provide the file to the client
    result = client.predict(
        image=handle_file(image_path),
        api_name="/predict"
    )
    print(result)
else:
    print(f"File not found: {image_path}")