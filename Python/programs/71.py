
ifile = open('sam.txt')
ofile = open('samu.txt', mode= 'w')
word_list =[]
line=ifile.readlines()
for li in line:
    words=li.split()
    for word in words:
        word_list.append(word)
word_list.sort()
print(word_list)
for word in word_list:
    ofile.write(word+' ')
ofile.close()








import zipfile,os
def backupToZip(folder):
    folder = os.path.abspath('NEWWWWWWWWWWWWW')
    number = 1
    while True:
        zipFilename = os.path.basename (folder) + str(number) + '.zip'
        if not os.path. exists (zipFilename):
            break
    number = number+1
    print('creating %s . . . '% (zipFilename))
    backupZip = zipfile.ZipFile(zipFilename, 'w')
    for foldername, subfolders, filenames in os.walk(folder):
        print('Adding files in %s . . .'% (foldername))
        backupZip.write(foldername)
        for filename in filenames:
            if filename.startswith (os.path.basename (folder)) and filename.endswith('.zip'):
                continue
            backupZip.write(os.path.join(foldername, filename))
    backupZip.close()
    print('done')

backupToZip (r'anaconda3')















def DivExp(a,b):
    try:
        assert a>0,"Number is negative." 
        if b==0:
            raise ZeroDivisionError("division error")
        c=a/b
        return c
    except AssertionError as x:
        print("Assertion failure: "+str(x))
    except ZeroDivisionError as x:
        print(x)
x,y = map(int,input("Enter two integers: ").split())
DivExp(x,y)





















class Complex:
    def __init__(self,real,imag):
        self.real = real
        self.imag = imag
    def ___add__(c1,c2):
        return Complex(c1.real+c2.real,c1.imag+c2.imag)
    def ___str__(self):
        return "%d + i%d"%(self.real,self.imag)
    

c1 = Complex(-2,-5)
c2 = Complex(5,6)
print("ca+cb=",c1+c2)
print(type(c1), id(c1))
complex_list = [ ]
N = int(input("How many complex numbers do you want to add?"))
for i in range(N):
    m,n=map(float,input("enter real and imaginary values of complex number").split()) 
    complex_list.append(Complex(m,n))
sum_series= Complex()
for x in complex_list: 
    sum_series += x
print("The sum of given complex number is", sum_series)





















class Student:
def __init__(self,name=" ', usn="", marks = []):
self.name = name
self.usn usn
self.marks = marks
def getMarks (self):
x=map(int,input("enter 3 subjects marks").split())
self.marks=list(x)
print(self.marks)
def getDetails(self):
self.name = input("Enter name:")
self.usn = input("Enter usn:")
def display (self):
print("name:", self.name)
print("usn:", self.usn)
print("marks:", self.marks)
total = 0
for x in self.marks:
total +=x
print("Total Marks: ", total, "\nPercentage:", total/3, "%")
x = Student()
x.getDetails() x.getMarks() x.display()
