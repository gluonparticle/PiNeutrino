soda = open('read.txt','r')
apple = open('write.txt','w')

line=soda.readlines()
l=[]
for i in line:
    j=i.split()
    for k in j:
        l.append(k)
        
l.sort()

for i in l:
    apple.write(i+' ')

soda.close()