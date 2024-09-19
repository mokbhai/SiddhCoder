const express = require("express");
const path = require("path");
const app = express();
const port = 4001;

// Set the view engine to EJS
app.set("view engine", "ejs");

// Middleware to parse JSON bodies
app.use(express.json());

// Serve static files
app.use(express.static(path.join(__dirname, "public")));

// GET route to render the payment page
app.get("/", (req, res) => {
  // For demonstration purposes, hardcoding the amount and id
  const amount = 200;
  const id = 123456;

  // Validate the input
  if (!amount || !id) {
    return res.status(400).send("Payment amount and ID are required");
  }

  // Render the EJS template with payment details
  res.render("payment", { amount, id });
});

// POST route to handle success button click
app.post("/payment-success", (req, res) => {
  const { amount, id } = req.body;
  // Handle the success logic here
  res.json({ message: `Payment of ${amount} with ID ${id} was successful.` });
});

// POST route to handle failed button click
app.post("/payment-failed", (req, res) => {
  const { amount, id } = req.body;
  // Handle the failure logic here
  res.json({ message: `Payment of ${amount} with ID ${id} failed.` });
});

app.listen(port, () => {
  console.log(`Server running at http://localhost:${port}`);
});
