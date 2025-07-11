import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score

# Euclidean Distance Function
def euclidean_distance(x1, x2):
    return np.sqrt(np.sum((x1 - x2) ** 2))

# KNN Classifier
class KNN:
    def __init__(self, k=3):
        self.k = k

    def fit(self, x, y):
        self.x = x
        self.y = y

    def predict_single(self, point):
        distances = []
        for data_point in self.x:
            distance = euclidean_distance(point, data_point)
            distances.append(distance)

        sorted_indices = np.argsort(distances)
        k_nearest_indices = sorted_indices[:self.k]
        k_nearest_labels = [self.y[i] for i in k_nearest_indices]

        predicted_label = np.argmax(np.bincount(k_nearest_labels))
        return predicted_label

    def predict(self, x):
        return [self.predict_single(point) for point in x]

# Load Dataset
df = pd.read_csv("https://raw.githubusercontent.com/AnanthMAthreya/2nd-year-resources-2022-scheme-rvce/main/4th%20sem/AI244AI-Artificial%20Intelligence%20and%20Machine%20Learning/Lab%20codes/iris_csv%20(1).csv")

# Label Encoding
label_map = {'Iris-versicolor': 1, 'Iris-virginica': 2, 'Iris-setosa': 3}
df['class'] = df['class'].map(label_map)

# Feature Matrix and Labels
x = df.iloc[:, :-1].values
y = df.iloc[:, -1].values

# Train-Test Split
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2, random_state=7)

# Model Training
model = KNN(k=3)
model.fit(x_train, y_train)

# Predictions on Test Set
y_pred = model.predict(x_test)

# Evaluation Metrics
print("Test Set Evaluation:")
print("Accuracy: ", accuracy_score(y_test, y_pred))
print("Precision: ", precision_score(y_test, y_pred, average='macro'))
print("Recall: ", recall_score(y_test, y_pred, average='macro'))
print("F1 Score: ", f1_score(y_test, y_pred, average='macro'))


# Validation with Random Sample

valid = df.sample(n=20, random_state=42)
x_valid = valid.iloc[:, :-1].values
y_valid = valid.iloc[:, -1].values  # Already numeric due to earlier mapping

y_predict = model.predict(x_valid)

print("\nValidation Set Accuracy (on random 20 samples):", accuracy_score(y_valid, y_predict))
