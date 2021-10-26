import numpy as np
import pandas as pd
import sklearn.cluster as clst
import matplotlib.pyplot as plt
#from google.colab import drive
#drive.mount('/gdrive')
#%cd /gdrive
#cd /gdrive/My Drive/Colab Notebooks/ML- Workshop
df = pd.read_csv("Jupyter-Notebooks-and-Data/clusters-3.csv")
print(df)
plt.plot(df['x'], df['y'], "y.")
plt.show()
kmn = clst.KMeans(n_clusters=4,init='random')
kmn.fit(df[['x','y']])
pred = kmn.predict(df[['x','y']])
print(pred)
grp0 = pred == 0
grp1 = pred == 1
grp2 = pred == 2
grp3 = pred == 3
grp4 = pred == 4
grp5 = pred == 5
grp6 = pred == 6
plt.plot(df['x'][grp0], df['y'][grp0], "r.")
plt.plot(df['x'][grp1], df['y'][grp1], "b.")
plt.plot(df['x'][grp2], df['y'][grp2], "g.")
plt.plot(df['x'][grp3], df['y'][grp3], "y.")
plt.plot(df['x'][grp4], df['y'][grp4], "m.")
plt.plot(df['x'][grp5], df['y'][grp5], "k.")
plt.plot(df['x'][grp6], df['y'][grp6], "c.")
plt.show()
