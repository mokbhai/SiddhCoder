from sklearn.linear_model import LinearRegression
import numpy as np

# Sample data
X = np.array([1, 2, 3, 4, 5]).reshape(-1, 1)  # Feature matrix
y = np.array([2, 3, 4, 5, 6])  # Target variable

# Create and fit the model
model = LinearRegression()
model.fit(X, y)

# Print the coefficients
print('Slope (m):', model.coef_[0])
print('Intercept (b):', model.intercept_)

# Predict for new values
new_x = np.array([[6], [7]])  # New data points
predicted_y = model.predict(new_x)
print('Predicted y for new x:', predicted_y)
