import numpy as np

def triband(a,d,c,b):
    n = len(d)
    assert len(a) == len(c) == n-1
    assert len(b) == n
    x = np.zeros_like(b)

    for i in range(1,n):
        m = a[i-1]/d[i-1]
        d[i] = d[i] - m*c[i-1]
        b[i] = b[i] - m*b[i-1]
        
    x[n-1] = b[n-1]/d[n-1]
    
    for i in range(n-2,-1,-1):
        x[i] = (b[i] - c[i]*x[i+1])/d[i]
        

    return x

def Problem3(a,d,c,b):
    return triband(a,d,c,b)

# d = np.ones((4,),dtype =np.float64)
# a = 0.5*np.ones((3,),dtype =np.float64)
# c = 0.5*np.ones((3,),dtype =np.float64)
# b = np.array([1.5,2,2,1.5],dtype = np.float64)
# x = Problem3(a,d,c,b)
# print(x)



# d = np.ones((100,),dtype =np.float64)
# a = 0.5*np.ones((99,),dtype =np.float64)
# c = 0.5*np.ones((99,),dtype =np.float64)
# b = np.array([1.5 if i==0 or i==99 else 2.0 for i in range(100)],dtype =np.float64)
# x = Problem3(a,d,c,b)
# print(x)