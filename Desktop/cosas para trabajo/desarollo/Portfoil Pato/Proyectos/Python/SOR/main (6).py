import numpy as np


def jacobi(A, b, x0, s):
    x = x0
    D = np.diag(np.diag(A))
    L = np.tril(A, -1)
    U = np.triu(A, 1)
    normb = np.linalg.norm(b)
    Iter = 0
    resto = 1
    D1 = (np.linalg.inv(D))
    LU = (L + U)
    DIU = np.dot(D1, LU)
    DIBU = np.dot(D1, b)
    while resto > (10 ^ -8) and Iter < s:
        y = np.dot(- DIU, x) + DIBU
        Iter += 1
        resto = np.linalg.norm(np.dot(A, y) - b) / normb
        x = y

    print(x, Iter)
    return (x, Iter)


##np.tril = L, np.triu = D y np.diag = U

A = np.array([[4, 2, 1], [1, 4, 1], [2, 1, 5]])
b = np.array([9, 5, 0])

jacobi(A, b, (1, 1, 1), 50)


def SOR(A, b, x0, w, s):
    x = x0
    D = np.diag(np.diag(A))
    L = np.tril(A)
    U = np.triu(A)
    Iter = 0
    DwL = D + w * L
    DwL1 = np.linalg.inv(DwL)
    Bw = DwL1 @ ((1 - w) * D - w * U)
    M = (DwL1 * w @ b)
    resto = 1
    normb = np.linalg.norm(b)

    while resto > (10 ^ -8) and Iter < s:
        y = Bw + M
        Iter += 1
        resto = np.linalg.norm(np.dot(A, y) - b) / normb
        x = y

    print(x, Iter)
    return (x, Iter)


SOR(A, b, (1, 1, 1), 1, 50)
SOR(A, b, (1, 1, 1), 1.5, 50)
SOR(A, b, (1, 1, 1), 2.5, 50)
