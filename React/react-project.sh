#!/bin/bash

# Check if a project name is provided as an argument
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <project_name>"
    exit 1
fi

# Define variables
project_name="$1"
template_dir="basic-template"
target_dir="$project_name"

# Check if the target directory already exists
if [ -d "$target_dir" ]; then
    echo "Error: Directory '$target_dir' already exists."
    exit 1
fi

# Copy files from the template directory to the target directory
cp -r "$template_dir" "$target_dir"

# Modify the package.json file with the new project name
sed -i '' "s/basic-template/$project_name/g" "$target_dir/package.json"

# Add project name to README.md
echo "# $project_name" > "$target_dir/README.md"

# Change to the target directory
cd "$target_dir" || exit

# Run npm install
npm install

npm start

# echo "Project setup completed successfully."
