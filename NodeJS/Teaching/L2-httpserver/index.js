// const http = require("http");
// const fs = require("fs");

// const server = http.createServer((req, res) => {
//   const date = new Date().toString();
//   const log = date + " " + req.method + " " + req.url + "\n";
//   fs.appendFile("log.txt", log, (err, data) => {
//     console.log(err);
//   });
//   //   console.log(req);
//   if (req.url === "/home") {
//     res.end("Hello Home!\n");
//   } else if (req.url === "/about") {
//     res.end("Hello about!\n");
//   } else {
//     res.end("Not Found!\n");
//   }
// });

// server.listen(3000, () => {
//   console.log("Server running on port 3000");
// });

// same with expresss

const express = require("express");
const bodyParser = require("body-parser");
const app = express();

// middle ware
app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

app.get("/home", (req, res) => {
  res.send("<h2>hello home</h2>");
});

app.get("/signup", (req, res) => {
  res.send(
    '<form action="#" method="post">' +
      '<label for="username">Username:</label>' +
      '<input type="text" id="username" name="username" required>' +
      '<label for="password">Password:</label>' +
      '<input type="password" id="password" name="password" required>' +
      '<input type="submit" value="Sign Up">' +
      "</form>"
  );
});
app.post("/signup", (req, res) => {
  // db query
  const { username, password } = req.body;
  res.send({ username, password });
});
app.listen(3000, () => {
  console.log("Server running on 3000");
});
