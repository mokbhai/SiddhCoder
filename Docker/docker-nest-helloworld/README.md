# Docker with NestJs

Welcome to Dockerizing your NestJs application! This guide will walk you through the steps to containerize your NestJs project and run it seamlessly using Docker.

## Step 1: Setting up NestJs

- First, ensure you have NestJs CLI installed globally:
  ```bash
  npm i -g @nestjs/cli
  ```
- Create a new NestJs project:
  ```bash
  nest new project-name
  ```
- To run your project:
  ```bash
  npm install
  npm run start
  ```
- Access your site at [http://localhost:3000/](http://localhost:3000/)

## Step 2: Configuring Dockerfile

- Set up your `Dockerfile` for development:

  ```Dockerfile
  # Specify the Node.js version
  FROM node:latest

  # Set the working directory
  WORKDIR /usr/src/app

  # Copy all files into the Docker image
  COPY . .

  # Install dependencies
  RUN npm install

  # Start the application
  CMD ["npm", "run", "start:dev"]
  ```

- Set up your `Dockerfile.prod` for production environment:

  ```Dockerfile
  # Specify the Node.js version
  FROM node:latest

  # Set the working directory
  WORKDIR /usr/src/app

  # Copy all files into the Docker image
  COPY . .

  # Install dependencies
  RUN npm install

  RUN npm run build

  # It's good practice to remove ./src files
  RUN rm -rf ./src

  # Start the application
  CMD ["npm", "run", "start:prod"]
  ```

## Step 3: Building and Running Docker Image

- Build your Docker image for development:

  ```bash
  docker build -t docker-nest .
  ```

  - `-t` assigns a tag, here `docker-nest` is the tag you choose
  - `.` specifies the location of your Dockerfile

- Build your Docker image for production:

  ```bash
  docker build -t docker-nest-prod -f Dockerfile.prod .
  ```

- Run your Docker image:
  ```bash
  docker run -p PORT:3000 docker-nest
  ```
  - Replace `PORT` with the desired port for your Docker image to operate on
  - `3000` is the port of the app within the Docker image
  - Example: `docker run -p 3000:3000 docker-nest`

## Step 4: Live changes

- Your NestJs application is now running smoothly within a Docker container! However, you may encounter an issue where live changes do not reflect automatically.
- To address this issue, you need to set up `docker-compose.yml` for dev:

  ```yml
  services:
    nestjs_api:
      build:
        context: .
        dockerfile: Dockerfile
      ports:
        - '3000:3000'
      environment:
        - PORT=3000
        - NODE_ENV=development
      volumes:
        - ./src:/usr/src/app/src
  ```

- prod

  ```yml
  services:
    nestjs_api:
      build:
        context: .
        dockerfile: Dockerfile
      ports:
        - '3001:3001'
      environment:
        - PORT=3001
        - NODE_ENV=Production
      volumes:
        - ./src:/usr/src/app/src
  ```

- Explanation:

  - `services`: Defines the services in the Docker Compose file.
  - `nestjs_api`: Name of the service.
  - `build`: Specifies how to build the service.
    - `context`: The build context, which is the current directory.
    - `dockerfile`: Specifies the Dockerfile to use for building the service.
  - `ports`: Maps port 3000 of the container to port 3000 of the host machine.
  - `environment`: Sets environment variables for the service.
    - `PORT=3000`: Specifies the port the application runs on.
    - `NODE_ENV=development`: Sets the environment to development.
  - `volumes`: Mounts the local `./src` directory to the container's `/usr/src/app/src` directory, allowing live changes to be reflected.

- Build and run via:

  ```bash
  docker-compose up --build
  ```

  - or

    ```bash
    docker-compose -f docker-compose.prod.yml up --build
    ```

  - Note if youwant operation to run in silent then use `-d` at the end

    ```bash
    docker-compose up --build -d
    ```

- If still there is issue (which is the case in windows) paste the following in `tsconfig.json`

  ```json
  "watchoptions": {
  // Use a dynamic polling instead of system's changes.
  "watchFile": "dynamicPriorityPolling",
  "watchDirectory": "dynamicPriorityPolling",
  "excludeDirectories": ["**/node_modules", "dist"]
  }
  ```

Now, your NestJs application will automatically reflect live changes as you develop, making the development process smoother and more efficient.
