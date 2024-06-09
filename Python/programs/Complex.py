class Complex:
    def __init__(s,r=0,i=0):
        s.r=r
        s.i=i
    
    def __add__(a,b):
        return Complex(a.r+b.r,a.i+b.i)
    
    def __str__(s):
        return "%d + i%d"%(s.r,s.i)

c1 = Complex(2,3)
c2 = Complex(4,5)
print("ca+cb=",c1+c2)

list = []

N = int(input("How many complex numbers do you want to add?"))

for i in range(N):
    m,n = map(float,input("Enter them").split())
    list.append(Complex(m,n))

S = Complex()

for i in list:
    S += i

print(S)