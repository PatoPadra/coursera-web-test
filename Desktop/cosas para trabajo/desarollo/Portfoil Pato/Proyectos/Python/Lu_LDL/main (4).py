import numpy as np


##1
def DescomposicionLD(A):
    D = np.eye(3)
    L = np.eye(3)

    D[0, 0] = A[0, 0]
    L[1, 0] = (1 / D[0, 0]) * (A[1, 0])
    L[2, 0] = (1 / D[0, 0]) * (A[2, 0])

    D[1, 1] = A[1, 1] - (L[1, 0] ** 2) * D[0, 0]
    L[2, 1] = (1 / D[1, 1]) * (A[2, 1] - (L[2, 0] * L[1, 0] * D[0, 0]))

    D[2, 2] = A[2, 2] - L[2, 0] * D[0, 0] - L[2, 1] * D[1, 1]
    return [L, D]


##2
def DescomposicionLU(A):
    fils = len(A[0, :])
    cols = len(A[:, 1])

    U = A.copy()
    L1 = np.eye(fils)

    for j in range(cols):

        if U[j, j] != 0:
            for i in range(j + 1, fils):
                factor = (-U[i, j] / U[j, j])
                L1[i, j] = -factor
                U[i, :] = U[i, :] + (-U[i, j] / U[j, j]) * U[j, :]
        elif U[j, j] == 0 and np.any(U[(j + 1):, j] != 0):
            U = None
            print('Queda un pivote nulo')
            break

    return [L1, U]


A = np.array([[4, 2, -2], [2, 5, 5], [-2, 5, 11]])
v = np.array([1, 0, -1])


# L1, U = DescomposicionLU(A)
# print(L1, U)

##Aux
def resolverTriangSup(T, b):
    n = np.size(T[0])
    x = np.zeros(n)
    aux = 0
    for i in range(n):
        if i > 0:
            for j in range(n - i, n):
                aux -= x[j] * A[n - i - 1][j]
        x[n - i - 1] = (b[n - i - 1] + aux) / A[n - i - 1, n - i - 1]
        aux = 0
    return (x)


##Aux
def resolverTriangInf(T, b):
    n = np.size(T[0])
    x = np.zeros(n)
    aux = 0
    for i in range(n):
        if i > 0:
            for j in range(0, 1 + i):
                aux -= x[j] * A[i][j]
        x[i] = (b[i] + aux) / A[i, i]
        aux = 0
    return (x)


##Aux
def invertirTriangInf(A):
    A = -(A)
    for i in range(np.size(A[0])):
        A[i, i] = -A[i, i]
    return A


##3
def resolucionEcuacionConLU(A, v):
    L1, U = DescomposicionLU(A)
    invertirTriangInf(L1)
    y = L1 @ v
    res = resolverTriangSup(U, y)
    print(res)
    return res


##resolucionEcuacionConLU(A, v)

##4
##A = np.array(np.random.rand(10, 10))
##b = np.array(np.random.rand(10))


def calculoErrorLU(A, b):
    F = resolucionEcuacionConLU(A, b)
    e = F
    error1 = np.linalg.norm(e, 1)
    print("error1 es :", error1)
    return error1


##calculoErrorLU(A, b)


##5
def DoscomposicionLDL_T(A):
    fils = len(A[:, 0])
    cols = len(A[1, :])

    D = np.eye(fils)
    L = np.eye(fils)

    sum1 = 0
    sum2 = 0

    for j in range(cols):
        for i in range(j, fils):
            D[j, j] = A[j, j]
            for k in range(1, j):
                sum1 += (L[j, k] ** 2) * D[k, k]
                sum2 += (L[i, k] * L[j, k] * D[k, k])
            D[j, j] -= (sum1)
            L[i, j] = (1 / (D[j, j]) * (A[i, j] - sum2))
    L_T = np.transpose(L)
    print(L, D, L_T)
    return [L, D, L_T]


A = np.array([[4, 2, -2], [2, 5, 5], [-2, 5, 11]])
DoscomposicionLDL_T(A)


##6
def resolucionD(A, v):
    if np.shape(A)[1] == 1:
        D = np.zeros(np.shape(A)[0], np.shape(A)[0])
        for i in range(len(A)):
            for j in range(A[0]):
                for k in range(A[1]):
                    if j == k:
                        D[j, k] = A[i]
    else:
        D = A.copy()
    res = resolverTriangSup(D, v)
    return (res)


##Aux
def es_definida_pos(A):
    fils = len(A[:, 0])
    res = True
    for k in range(fils):
        if np.linalg.det(A) < 0:
            res = False
            return (res)
        else:
            return (res)
    print(res)


##7
def definidaPositivaQ(A):
    Q = np.transpose(A) @ A
    res = es_definida_pos(Q)
    return res


##8
A = np.random.rand(10, 10)
b = np.random.rand(10)
Q = np.transpose(A) @ A


# Aux
def invertirD(A):
    for i in range(np.size(A[0])):
        for j in range(np.size(A[1])):
            A[i, i] = (1 / A[i, i])
            return A


def calculoErrorLDL_T(A, b):
    if es_definida_pos(A):
        L, D, L_T = DoscomposicionLDL_T(A)
        z = resolverTriangInf(L, b)
        y = invertirD(D) @ z
        x = resolverTriangSup(L_T, y)
        error2 = np.linalg.norm(x, 1)
        print("error2 es :", error2)

        return error2


calculoErrorLDL_T(Q, b)

##9
##print(DescomposicionLU(Q))
##print(DoscomposicionLDL_T(Q))
##??


##11
##def transponerN(A, n):
##    P = np.eye(np.size(A[0]))
##    for i in range(np.size(P[1])):
##        P[i + n] = P[]
##       A = A @ P
##    return A


##W = transponerN(Q, 5)
##calculoErrorLU(W, b)


##11
##c1 = np.linalg.cond(Q, 1)
##c2 = np.linalg.cond(W, 1)
##print( c1)
##print( c2)


##12
##sumaQ = 0
##sumaW = 0

##for i in range(100):
##    e1 = e2 = 0
##    A = np.random.rand(10, 10)
##   b = np.random.rand(10)
##    Q = np.transpose(A) @ A
##    e1 = calculoErrorLU(Q, b)
##    W = transponerN(Q, 50)
##    e2 = calculoErrorLU(W, b)
##    sumaQ += e1
##    sumaW += e2

##print(sumaW / 100)
##print(sumaQ / 100)
