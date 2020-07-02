#Se reciben los atributos de la tabla R
tablaR = []
N = int(input())
atr = input()
atr_R = atr.split(" ")

#Se recibe la cantidad de filas de la tabla R
NR = int(input())
#Cada fila se lee y se guarda como una lista dentro de tablaR
for i in range(NR):
    fila_str = input()
    fila_ls = list(map(int, fila_str.split(" ")))
    tablaR.append(fila_ls)

#Se reciben los atributos de la tabla S
tablaS = []
M = int(input())
atr = input()
atr_S = atr.split(" ")

#Se recibe la cantidad de filas de la tabla S
NS = int(input())
#Cada fila se lee y se guarda como una lista dentro de tablaS
for i in range(NS):
    fila_str = input()
    fila_ls = list(map(int, fila_str.split(" ")))
    tablaS.append(fila_ls)

#Se crea una lista con los atributos en comun de ambas tablas
atr_iguales = list(set(atr_R) & set(atr_S))
atr_iguales.sort()
#Cantidad de atributos comunes
L = len(atr_iguales)
#Atributos de la nueva tabla T
atr_T = list(set(atr_R) | set(atr_S))
atr_T.sort()
#Cantidad de atributos de la tabla T
P = len(atr_T)

#Si no existen atributos comunes se muestran los atributos de T y se sale del programa
if L == 0:
    print(P)
    print(" ".join(atr_T).strip())
    print(0)
    raise SystemExit

tablaT = [] #Contiene los filas de la tabla T
posAtrR = [] #Contiene la posición de los atributos de R
posAtrS = [] #Contiene la posición de los atributos de S


pos_r = 0
pos_s = 0
#Se obtiene la posición que tienen los atributos comunes dentro de sus respectivas
#tablas almacenandolos de posAtrR y posAtrS
for elem in atr_iguales:
    pos_r = atr_R.index(elem, pos_r)
    pos_s = atr_S.index(elem, pos_s)
    posAtrR.append(pos_r)
    posAtrS.append(pos_s)

#Busqueda de filas con elementos iguales en las columnas de los atributos comunes
for filaR in tablaR:
    for filaS in tablaS:
        c = 0
        for i in range(L):
            #Se compara el elemento de la filaR con el de la filaS 
            if filaR[posAtrR[i]] == filaS[posAtrS[i]]:
                #Si son iguales se aumenta el contador en 1
                c += 1
            else:
                #Si no son iguales, se busca en la siguiente fila
                break
        if c == L:
            #Se verifica que el contador es igual a la cantidad de atributos en comun
            temp = []
            #Se guardan tuplas de los elementos de la filas encontradas con sus atributos
            for j in range(N):
                temp.append((atr_R[j], filaR[j]))
            for k in range(M):
                temp.append((atr_S[k], filaS[k]))
            
            #Se crea una lista de las tuplas y se ordena
            ls_tuplas = list(set(temp))
            ls_tuplas.sort()
            #Se guarda la nueva fila en la tabla T
            filaT = [tupla[1] for tupla in ls_tuplas]
            tablaT.append(filaT)

#Se muestran los atributos en pantalla
print("\n")
atr_T = " ".join(atr_T)
print(P)
print(atr_T.strip())
print(len(tablaT))
#Se muestra la tablaT
for row in tablaT:
    row = list(map(str, row))
    print(" ".join(row))