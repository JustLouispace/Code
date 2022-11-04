import numpy as np

def GaussianSwapForwardElimination(A,b):
    m,n = A.shape
    bn, = b.shape
    assert n==m==bn
    Aans = A.copy()
    bans = b.copy()
    l = list(range(n))
    sl = np.abs(A).max(axis=1)

    for i in range(n-1):
        for j in range(i+1,n):
            m = Aans[j,i]/Aans[i,i]
            bans[j] = bans[j] - m*bans[i]
            for k in range(i,n):
                Aans[j,k] = Aans[j,k] - m*Aans[i,k]
        p = np.argmax(np.abs(Aans[i:,i])/sl[i:])
        if p != 0:
            Aans[[i,i+p]] = Aans[[i+p,i]]
            bans[[i,i+p]] = bans[[i+p,i]]
            l[i],l[i+p] = l[i+p],l[i]
            sl[i],sl[i+p] = sl[i+p],sl[i]

    return Aans, bans, l

def GaussianSwapBacksubstitution(A,b,l):
    m,n = A.shape
    bn, = b.shape
    assert n==m==bn
    x = np.zeros(n,dtype=np.float64)

    for i in range(n-1,-1,-1):
        x[i] = b[i]
        for j in range(i+1,n):
            x[i] = x[i] - A[i,j]*x[j]
        x[i] = x[i]/A[i,i]
    x = x[l]

    return x


def Problem2(A,b):
    Aselem,bselem,l = GaussianSwapForwardElimination(A,b)
    x = GaussianSwapBacksubstitution(Aselem,bselem,l)
    return x

# n = 4
# Aa = [[3,-13,9,3],[-6,4,1,-18],[6,-2,2,4],[12,-8,6,10]]
# bb = [-19,-34,16,26]
# A = np.array(Aa,dtype=np.float64)
# b = np.array(bb, dtype=np.float64)
# x = Problem2(A,b)
# print(x)
# assert ( np.absolute(x - np.array([ 3.,  1., -2.,  1.]) )<1e-5).all()
