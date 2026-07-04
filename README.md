# Linear Regression From Scratch in C++

A complete implementation of **Linear Regression** from scratch using **Gradient Descent** in modern **C++**, without relying on external Machine Learning libraries.

## Overview

This project demonstrates how Linear Regression works internally by implementing every step manually, including:

- Hypothesis Function
- Cost Function (Mean Squared Error)
- Gradient Descent Optimization
- Model Training
- Prediction
- Model Evaluation

The goal is to understand the mathematical foundations behind Linear Regression instead of using ready-made libraries.

---

## Features

- Linear Regression from scratch
- Batch Gradient Descent
- Mean Squared Error (MSE)
- Cost calculation
- Prediction on new values
- Model evaluation
- Simple and readable implementation
- No external Machine Learning libraries

---

## Technologies

- C++
- STL (Standard Template Library)
- Visual Studio

---

## Project Structure

```
Project/
│
├── main.cpp
├── LinearRegressionModel.h
├── README.md
└── .gitignore
```

---

## Example Output

```
Final Theta0 = 1.99851
Final Theta1 = 3.00021

Predict Value For 20:
62.0028

Evaluation (MSE):
3.70472e-06
```

---

## Mathematical Background

Hypothesis Function

h(x) = θ₀ + θ₁x

Cost Function

J(θ) = (1 / 2m) Σ(h(x) − y)²

Gradient Descent

θ := θ − α ∂J/∂θ

---

## Future Improvements

- Multiple Linear Regression
- Feature Scaling
- Polynomial Regression
- Logistic Regression
- Saving and Loading Models
- CSV Dataset Support
- Mini Machine Learning Library

---

## License

This project is released under the MIT License.

---

## Author

**Ebrahim Hammad**

GitHub:
https://github.com/EbrahimHammad360
