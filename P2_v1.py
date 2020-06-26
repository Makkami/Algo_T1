def Join(N, M, atr_R, atr_S, tablaR, tablaS):
    atr_iguales = list(set(atr_R) & set(atr_S))
    atr_iguales.sort()
    L = len(atr_iguales)
    atr_T = list(set(atr_R) | set(atr_S))
    atr_T.sort()

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
    return tablaT

Tabla = list()
cont_arcos = 0
conjunto = set()

arco = input("Ingrese arco: ")

while arco!='EOF':
    arcos = list(map(int, arco.split(" ")))
    Tabla.append(arcos)
    cont_arcos += 1
    arco = input("Ingrese arco: ")

tablaT = Join(2, 2, [0,1], [1,2], Tabla, Tabla)

for a, b, c in tablaT:
    if ([b,c,a] in tablaT) or ([c,a,b] in tablaT):
        lista = [a, b, c]
        lista.sort()
        conjunto.add(tuple(lista))
print (len(conjunto))
