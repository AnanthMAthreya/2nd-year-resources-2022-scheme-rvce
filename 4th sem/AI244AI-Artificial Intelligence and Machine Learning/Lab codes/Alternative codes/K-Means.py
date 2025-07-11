import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
#from google.colab import drive

# Custom KMeans Implementation
class KMeansCustom:
    def __init__(self, n_clusters=3, max_iterations=100):
        self.n_clusters = n_clusters
        self.max_iterations = max_iterations

    def initialize_centroids(self, data):
        indices = np.random.choice(data.shape[0], self.n_clusters, replace=False)
        return data[indices]

    def assign_to_clusters(self, data, centroids):
        distances = np.linalg.norm(data[:, np.newaxis] - centroids, axis=2)
        return np.argmin(distances, axis=1)

    def update_centroids(self, data, labels):
        new_centroids = []
        for i in range(self.n_clusters):
            cluster_points = data[labels == i]
            if len(cluster_points) > 0:
                centroid = np.mean(cluster_points, axis=0)
            else:
                centroid = np.zeros(data.shape[1])  # handle empty cluster
            new_centroids.append(centroid)
        return np.array(new_centroids)

    def fit(self, data):
        self.centroids = self.initialize_centroids(data)
        for _ in range(self.max_iterations):
            labels = self.assign_to_clusters(data, self.centroids)
            new_centroids = self.update_centroids(data, labels)
            if np.allclose(self.centroids, new_centroids):
                break
            self.centroids = new_centroids
        self.labels = labels


# Load Dataset from Drive
#drive.mount('/content/drive')
iris = pd.read_csv(r"https://raw.githubusercontent.com/AnanthMAthreya/2nd-year-resources-2022-scheme-rvce/main/4th%20sem/AI244AI-Artificial%20Intelligence%20and%20Machine%20Learning/Lab%20codes/iris_csv%20(1).csv")
#iris = pd.read_csv('/content/drive/MyDrive/Datasets/iris_csv (1).csv')

# We'll use Petal Length and Petal Width for clustering
data = iris.iloc[:, 2:4].values

# Run Custom KMeans
k = 4
model = KMeansCustom(n_clusters=k)
model.fit(data)

# Plot Results
plt.figure(figsize=(8,6))
plt.scatter(data[:, 0], data[:, 1], c=model.labels, cmap='viridis', alpha=0.7)
plt.scatter(model.centroids[:, 0], model.centroids[:, 1], marker='X', s=300, c='red', label='Centroids')
plt.xlabel('Petal Length (cm)')
plt.ylabel('Petal Width (cm)')
plt.title(f'Custom K-Means Clustering (k={k}) on Iris Dataset')
plt.legend()
plt.grid(True)
plt.show()
