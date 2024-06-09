
class Student:
    def __init__(self,name='', usn='',marks = []):
        self.name =   name
        self.usn  =    usn
        self.marks =   marks

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
x.getDetails() 
x.getMarks() 
x.display()