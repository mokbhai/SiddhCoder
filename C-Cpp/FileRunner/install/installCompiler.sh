if [ -f "./install/installComplier.py" ]; then
    python3 ./install/installComplier.py "$1"
else
    echo "Error: installComplier.py not found."
    exit 1
fi