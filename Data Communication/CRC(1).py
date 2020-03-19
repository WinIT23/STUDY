data = ''
divisor = ''

data=input("enter data/msg bits:")
divisor=input("enter divisor bits:")

temp = ''

n = len(divisor)-1
for i in range(n):
    data+='0'

n+=1
k = 0
temp = data[k:k+n]

for t in range(len(data)-n+1):
    i = temp
    temp = ''
    print('i = ',i)
    for j in range(1,n):
        if(i[j]== str(int(i[0]) * int(divisor[j]))):
            temp+='0'
        else:
            temp+='1'
    if(not(t==len(data)-n)):
        temp+=data[k+n]
    k+=1
    print("temp =",temp)

print('Remainder =',i[1:])

data = data[:-len(i)+1]
data=data+i[1:len(i)]
print("delivered msg =",data)
