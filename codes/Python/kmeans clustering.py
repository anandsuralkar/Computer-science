from sklearn.cluster import KMeans
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd



Iris = pd.read_csv('F:/working folder/kmeans_clustering_algorithm-master/iris.csv')
x1 = np.array(Iris['SepalLengthCm'])
x2 = np.array(Iris['PetalWidthCm'])

plt.plot()
plt.title('Dataset')
plt.scatter(x1, x2)
plt.show()

# create new plot and data

X = np.array(list(zip(x1, x2)))
colors = ['b', 'g', 'r']
markers = ['o', 'v', 's']
plt.ylabel('Length')


kmeans = KMeans(n_clusters=3).fit(X)
plt.scatter(kmeans.cluster_centers_[:, 0], kmeans.cluster_centers_[:, 1], s = 200, c = 'yellow', label = 'Centroids')


for i, l in enumerate(kmeans.labels_):
    plt.plot(x1[i], x2[i], color=colors[l], marker=markers[l])
plt.xlabel('Width')
plt.legend()
plt.show()
