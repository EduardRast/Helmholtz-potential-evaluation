#!/usr/bin/env python
import matplotlib.pyplot as plt
import numpy as np

# build up the numpy logo
n_voxels = np.zeros((10, 10, 10), dtype=bool)
for i in range(len(n_voxels)):
    n_voxels[1,0,1] = 1
n_voxels[1,0,1] = 1
n_voxels[1,9,9] = 1
n_voxels[1,0,2] = 1
n_voxels[2,0,1] = 1
n_voxels[1,9,1] = 1


spatial_axes = [len(n_voxels), len(n_voxels), len(n_voxels)]
colors = np.empty(spatial_axes + [4], dtype=np.float32)
alpha = .05
colors = [alpha, alpha, alpha, alpha]

x, y, z = np.indices((len(n_voxels)+1,len(n_voxels)+1,len(n_voxels)+1))*10

class point:
    def __init__(self,Xp,Yp,Zp):
        self.x = Xp
        self.y = Yp
        self.z = Zp
    x
    y
    z

point1 = point(100,20,40)
points = []
for i in range(10):
    points.append(point(i*3.14,i*9,i*5))


ax = plt.figure().add_subplot(projection='3d')
ax.voxels(x, y, z, n_voxels,facecolors=colors, edgecolors = 'k')
ax.set_aspect('equal')

ax.scatter(point1.x,point1.y,point1.z, c='red', marker='.')
for j in range(len(points)):
    ax.scatter(points[j].x,points[j].y,points[j].z, c='red', marker='.')
plt.show()
