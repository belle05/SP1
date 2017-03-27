BASE = {'1':1,'2':2,...,'A':10}


base = int(raw_input("enter base"))
if (base>16 or base<2):
	print "error!!"
baseb = 10
num = raw_input("enter a num to convert")
#check num is in base a
#check is baseA or baseB are 10
baseA = {char:i for i in xrange(base)}
sum1 = 0

#convert to 10
for i,char in num: #reverse order
	sum1 += BASE[char]*(base**i)

arr = []
while(sum1!=1):
	arr.append(sum1%baseB)
	sum1 = int(sum1/baseB)

arr.reverse()
new_num = str(arr)
