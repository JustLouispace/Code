import numpy as np

def GaussianForwardElimination(A,b): #A,b are numpy array of size (n,n) and n for equation Ax=b
    m,n = A.shape
    bn, = b.shape
    assert n==m==bn
    Aans = A.copy()
    bans = b.copy()
    
    for i in range(n-1):
        for j in range(i+1,n):
            m = Aans[j,i]/Aans[i,i]
            bans[j] = bans[j] - m*bans[i]
            for k in range(i,n):
                Aans[j,k] = Aans[j,k] - m*Aans[i,k]

    return Aans, bans

def GaussianBacksubstitution(A,b):
    m,n = A.shape
    bn, = b.shape
    assert n==m==bn
    x = np.zeros(n,dtype=np.float64)
    
    for i in range(n-1,-1,-1):
        x[i] = b[i]
        for j in range(i+1,n):
            x[i] = x[i] - A[i,j]*x[j]
        x[i] = x[i]/A[i,i]

    return x

def Problem1(A,b): 
    Aelem, belem = GaussianForwardElimination(A,b)
    x = GaussianBacksubstitution(Aelem,belem)
    return x


# n = 4
# Aa = [[6,-2,2,4],[12,-8,6,10],[3,-13,9,3],[-6,4,1,-18]]
# bb = [16,26,-19,-34]
# A = np.array(Aa,dtype=np.float64)
# b = np.array(bb, dtype=np.float64)
# x = Problem1(A,b)
# print(x)
# assert ( np.absolute(x - np.array([ 3.,  1., -2.,  1.]) )<1e-5).all()