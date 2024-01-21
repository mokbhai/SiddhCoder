var name = document.getElementById("name").value;
var email = document.getElementById("email").value;

// JavaScript Validation Functions
function validateForm() {
  // Reset error message
  document.getElementById("errorMessage").innerText = "";

  // Validate name
  validateName(name);

  // Validate email
  validateEmail(email);

  // Form submission successful
  alert("Event registration successful!");
  return true;
}

function validateName(name) {
  if (name.trim() === "") {
    displayError("Name cannot be empty");
    return false;
  }
}

function validateEmail(email) {
  if (!isValidEmail(email)) {
    displayError("Invalid email address");
    return false;
  }
}

function isValidEmail(email) {
  // Simple email validation regex
  var emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
  return emailRegex.test(email);
}

function displayError(message) {
  // Display error message
  var errorMessage = document.getElementById("errorMessage");
  errorMessage.innerText = message;
}
