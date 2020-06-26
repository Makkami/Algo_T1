tablaR = []
N = int(input())
atr = input()
atr_R = atr.split(" ")


NR = int(input())
for i in range(NR):
    fila_str = input()
    fila_ls = list(map(int, fila_str.split(" ")))
    tablaR.append(fila_ls)

tablaS = []
M = int(input())
atr = input()
atr_S = atr.split(" ")

NS = int(input())
for i in range(NS):
    fila_str = input()
    fila_ls = list(map(int, fila_str.split(" ")))
    tablaS.append(fila_ls)

atr_iguales = list(set(atr_R) & set(atr_S))
atr_iguales.sort()
L = len(atr_iguales)
atr_T = list(set(atr_R) | set(atr_S))
atr_T.sort()
P = len(atr_T)

if L == 0:
    print(P)
    print(" ".join(atr_T).strip())
    print(0)
    raise SystemExit

tablaT = []
posAtrR = []
posAtrS = []

pos_r = 0
pos_s = 0
for elem in atr_iguales:
    pos_r = atr_R.index(elem, pos_r)
    pos_s = atr_S.index(elem, pos_s)
    posAtrR.append(pos_r)
    posAtrS.append(pos_s)

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
print(atr_T.strip())
print(len(tablaT))
for row in tablaT:
    row = list(map(str, row))
    print(" ".join(row))