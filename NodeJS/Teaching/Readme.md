## Node.js

From [YTVideo by Piyush Garg](https://www.youtube.com/playlist?list=PLinedj3B30sDby4Al-i13hQJGQoRQDfPo)

Node.js is a runtime environment for JavaScript, commonly used for building server-side applications. It allows developers to run JavaScript code outside of a web browser.

Node.js is built on the V8 JavaScript runtime engine, which is developed by Google for use in the Chrome web browser.

Node.js operates on a single-threaded event loop architecture, where all I/O operations are handled asynchronously.

You can install Node.js from the [official website](https://nodejs.org/en). Once installed, you can check your Node.js version using the following command:

```bash
node --version
```

## npm - Node Package Manager

npm is the default package manager for Node.js. It allows developers to install, share, and manage dependencies efficiently. To check your npm version, use the following command:

```bash
npm --version
```

## Creating a Node.js Project

To create a Node.js project, you can follow these steps:

1. **Create a Directory**: Start by creating a new directory for your project. You can do this using the `mkdir` command in your terminal:

```bash
mkdir my-nodejs-project
```

2. **Navigate to the Directory**: Move into the newly created directory using the `cd` command:

```bash
cd my-nodejs-project
```

3. **Initialize the Project**: Use `npm init` command to initialize a new Node.js project. This command will prompt you to provide some information about your project (such as name, version, description, entry point, etc.), or you can simply press Enter to accept the default values:

```bash
npm init
```

4. **Install Dependencies**: If your project requires any dependencies (external packages), you can install them using `npm install`. For example, to install the `express` framework:

```bash
npm install express
```

5. **Create Files**: Create your JavaScript files within the project directory. For example, you might create an `index.js` file as the entry point for your application:

```javascript
const express = require("express");
const app = express();

app.get("/", (req, res) => {
  res.send("Hello, Node.js!");
});

app.listen(3000, () => {
  console.log("Server is running on port 3000");
});
```

6. **Run the Application**: You can run your Node.js application by executing the main file using the `node` command. For example, to run the `index.js` file:

```bash
node index.js
```

7. **Test the Application**: Once your application is running, you can test it by opening a web browser and navigating to `http://localhost:3000` (assuming your application is listening on port 3000 as in the example).

That's it! You've created and run a basic Node.js project. From here, you can continue building and expanding your application as needed.

## [L1-HELLOWORLD](./L1-HelloWorld)
