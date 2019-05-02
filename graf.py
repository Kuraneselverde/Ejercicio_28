import numpy as np
import matplotlib.pyplot as plt

temp = np.loadtxt("datos.dat")
tcero=temp[0]
tfinal=temp[-1]
lon=len(tcero)
x=np.linspace(1,lon,lon)

plt.figure(figsize=(10,5))
plt.subplot(121)
plt.imshow(temp)
plt.colorbar(label="Temperatura")
plt.axis('equal')
plt.ylabel("Indice T")
plt.xlabel("Indice X")

plt.subplot(122)
plt.plot(x,tcero)
plt.plot(x,tfinal)
plt.ylabel("Temperatura")
plt.xlabel("Indice X")
plt.axis('equal')
plt.savefig("imagenes.png")
