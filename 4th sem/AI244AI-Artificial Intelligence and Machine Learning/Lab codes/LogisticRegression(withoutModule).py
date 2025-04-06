import math

# Sigmoid function
def sigmoid(z):
    return 1 / (1 + math.exp(-z))

# Dot product
def dot(x, w):
    return sum(xi * wi for xi, wi in zip(x, w))

# Normalize data
def normalize(data):
    cols = len(data[0])
    mins = [min(col) for col in zip(*data)]
    maxs = [max(col) for col in zip(*data)]
    return [[(val - mins[i]) / (maxs[i] - mins[i]) for i, val in enumerate(row)] for row in data]

# Logistic Regression class
class LogisticRegression:
    def __init__(self, input_dim, lr=0.1):
        self.weights = [0.0 for _ in range(input_dim)]
        self.bias = 0.0
        self.lr = lr

    def predict_prob(self, x):
        return sigmoid(dot(x, self.weights) + self.bias)

    def predict(self, x):
        return 1 if self.predict_prob(x) >= 0.5 else 0

    def train(self, X, y, epochs=1000):
        for epoch in range(epochs):
            total_loss = 0
            for i in range(len(X)):
                x_i = X[i]
                y_i = y[i]
                z = dot(x_i, self.weights) + self.bias
                y_hat = sigmoid(z)
                loss = - (y_i * math.log(y_hat) + (1 - y_i) * math.log(1 - y_hat))
                total_loss += loss

                dz = y_hat - y_i
                for j in range(len(self.weights)):
                    self.weights[j] -= self.lr * dz * x_i[j]
                self.bias -= self.lr * dz

            if epoch % 100 == 0:
                print(f"Epoch {epoch}: Loss = {total_loss / len(X)}")

# Input data: [age, income]
X_raw = [
    [22, 20000],
    [25, 22000],
    [47, 50000],
    [52, 52000],
    [46, 49000],
    [56, 60000],
    [23, 21000],
    [28, 25000]
]

# Labels
y = [0, 0, 1, 1, 1, 1, 0, 0]

# Normalize data
X = normalize(X_raw)

# Train the model
model = LogisticRegression(input_dim=2, lr=0.5)
model.train(X, y, epochs=1000)

# Test predictions
print("\nPredictions:")
for i, xi in enumerate(X):
    print(f"Person {i+1}: Predicted = {model.predict(xi)}, Actual = {y[i]}")
