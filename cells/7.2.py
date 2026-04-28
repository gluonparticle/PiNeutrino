#Prog 7 in house loaded datasets

# Program 7
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.datasets import fetch_california_housing, load_diabetes
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import PolynomialFeatures, StandardScaler
from sklearn.pipeline import make_pipeline
from sklearn.metrics import mean_squared_error, r2_score

def linear_regression_california():
    housing = fetch_california_housing(as_frame=True)
    X, y = housing.data[["AveRooms"]], housing.target
    
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
    
    model = LinearRegression().fit(X_train, y_train)
    y_pred = model.predict(X_test)
    
    plt.scatter(X_test, y_test, color="blue", alpha=0.5, label="Actual")
    plt.plot(X_test, y_pred, color="red", label="Predicted")
    plt.xlabel("Average number of rooms")
    plt.ylabel("Median value of homes")
    plt.title("Linear Regression - California Housing")
    plt.legend()
    plt.show()
    
    print("Linear Regression - California Housing Dataset")
    print(f"Mean Squared Error: {mean_squared_error(y_test, y_pred):.4f}")
    print(f"R^2 Score: {r2_score(y_test, y_pred):.4f}\n")

def polynomial_regression_diabetes():
    diabetes = load_diabetes(as_frame=True)
    X = diabetes.data[["bmi"]].values 
    y = diabetes.target.values
    
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
    
    poly_model = make_pipeline(PolynomialFeatures(degree=2), StandardScaler(), LinearRegression())
    poly_model.fit(X_train, y_train)
    
    X_seq = np.linspace(X_test.min(), X_test.max(), 300).reshape(-1, 1)
    y_seq = poly_model.predict(X_seq)
    
    plt.scatter(X_test, y_test, color="blue", alpha=0.5, label="Actual")
    plt.plot(X_seq, y_seq, color="red", linewidth=3, label="Polynomial Fit")
    plt.xlabel("Body Mass Index (BMI)")
    plt.ylabel("Disease Progression Score")
    plt.title("Polynomial Regression - Diabetes Dataset")
    plt.legend()
    plt.show()
    
    y_pred = poly_model.predict(X_test)
    print("Polynomial Regression - Diabetes Dataset")
    print(f"Mean Squared Error: {mean_squared_error(y_test, y_pred):.4f}")
    print(f"R^2 Score: {r2_score(y_test, y_pred):.4f}")

if __name__ == "__main__":
    print("Demonstrating Linear and Polynomial Regression (Offline Version)\n")
    linear_regression_california()
    polynomial_regression_diabetes()