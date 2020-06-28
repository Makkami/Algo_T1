#Definicion de funcion Join de Pregunta 1,
#recibiendo por parametros las entradas requeridas.
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
        
'''Comienzo programa Pregunta 2:'''

#Lista que almacena los inputs
Tabla = list()
#Lista que almacena los triangulos encontrados
matches = list() 

#Solicitud de inputs
arco = input("Ingrese arco: ")

while arco!='EOF':
    arcos = list(map(int, arco.split(" ")))
    Tabla.append(arcos)
    arco = input("Ingrese arco: ")

if len(Tabla)!=0:
    #Uso de la funcion Join con los inputs
    tablaT = Join(2, 2, [0,1], [1,2], Tabla, Tabla)
    #Recorremos solucion de lo que entrega Join
    for a, b, c in tablaT:
        #Ya que existe a->b y b->c, buscamos el tercer arco dirigido necesario c->a.
        #Si lo encuentra lo agrega a lista matches.
        if ([b,c,a] in tablaT) or ([c,a,b] in tablaT):
            matches.append([a,b,c])

#Entrega del resultado
print (int(len(matches)/3))
#Se divide en 3 puesto que al hacer el Join, cada triangulo tiene asociado
#sus tres combinaciones posibles.
