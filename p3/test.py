import numpy as np

c = np.zeros((4, 4), dtype=str)
a = np.array([["a1", "b1", "c1", "d1"], ["e1", "f1", "g1", "h1"], ["","","",""], ["","","",""]])
b = np.array([["a2", "b2", "c2", "d2"], ["e2", "f2", "g2", "h2"], ["","","",""], ["","","",""]])

#print(a.dot(b))

for i in range(a.shape[0]):
    for j in range(b.shape[1]):
        for k in range(len(c)):
            c[i, j] += a[k, i]+b[j, k]
print(c)