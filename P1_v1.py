tablaR = []
N = int(input("Cantidad N de atributos de R: "))
atr = input("Atributos de R: ")
atr_R = atr.split(" ")


NR = int(input("Cantidad de tuplas de R: "))
for i in range(NR):
    fila_str = input("Ingrese tupla " + str(i+1) +": ")
    fila_ls = list(map(int, fila_str.split(" ")))
    tablaR.append(fila_ls)

tablaS = []
M = int(input("Cantidad M de atributos de S: "))
atr = input("Atributos de S: ")
atr_S = atr.split(" ")

NS = int(input("Cantidad de tuplas de S: "))
for i in range(NS):
    fila_str = input("Ingrese tupla " + str(i+1) +": ")
    fila_ls = list(map(int, fila_str.split(" ")))
    tablaS.append(fila_ls)

atr_iguales = list(set(atr_R) & set(atr_S))
atr_iguales.sort()
L = len(atr_iguales)
atr_T = list(set(atr_R) | set(atr_S))
atr_T.sort()
P = len(atr_T)

tablaT = []
posAtrR = []
posAtrS = []
for elem in atr_iguales:
    posAtrR.append(atr_R.index(elem))
    posAtrS.append(atr_S.index(elem))

for filaR in tablaR:
    for filaS in tablaS:
        c = 0
        for i in range(L):
            if filaR[posAtrR[i]] == filaS[posAtrS[i]]:
                c += 1
            else:
                break
        if c == L:
            temp = []
            for j in range(N):
                temp.append((atr_R[j], filaR[j]))
            for k in range(M):
                temp.append((atr_S[k], filaS[k]))
                
            ls_tuplas = list(set(temp))
            ls_tuplas.sort()
            filaT = [tupla[1] for tupla in ls_tuplas]
            tablaT.append(filaT)
        
atr_T = " ".join(atr_T)
print(P)
print(atr_T)
print(len(tablaT))
for row in tablaT:
    row = list(map(str, row))
    print(" ".join(row))
