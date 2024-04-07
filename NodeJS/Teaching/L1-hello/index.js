const express = require("express");
const bodyParser = require("body-parser"); // Require body-parser

const app = express();

// Parse application/json
app.use(bodyParser.json());

app.get("/", (req, res) => {
  res.send("Hello mokshit");
});

app.post("/", (req, res) => {
  const body = req.body;
  console.log(body);
  res.status(200).send(body);
});

app.listen(3000, () => {
  console.log("Server running on port 3000");
});
