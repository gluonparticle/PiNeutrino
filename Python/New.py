
ifile = open('sam.txt')

ofile = open('sam1.txt', mode= 'w')

word_list =[]

line-ifile.readlines()

for li in line:

words li.split()

for word in words:

word_list.append(word)

word_list.sort()

print(word_list)

for word in word_list:

ofile.write(word+' ')

ofile.close()





