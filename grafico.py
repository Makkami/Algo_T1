from matplotlib import pyplot as plt

s = list()
n = list()
with open("tiempos.txt", "r") as arc:
    a = arc.read()

a = a.strip().split("\n\n")
for k in a:
    k=k.strip().split("\n")[1:]
    for i in k:
        tipo, elem = i.split("=")
        if tipo.strip() == "s":
            s.append(float(elem)/1000000)
        else:
            n.append(int(elem)/1000000)

plt.plot([2**i for i in range(2, 11)], s[18:], label="strassen")
plt.plot([2**i for i in range(2, 11)], n[18:], label="naive")
plt.legend()
plt.title("k=4")
plt.grid()
plt.xlabel("Valor de n")
plt.ylabel("Tiempo [s]")
plt.ticklabel_format(style="plain")
plt.xlim(0, 1024)
plt.ylim(0)
plt.show()