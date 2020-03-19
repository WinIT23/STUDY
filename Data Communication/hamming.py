import math
msg = input("enter msg bits: ")
N = len(msg)
psize = math.floor(math.log(N,2))+1
print(psize)

a = [0]*(N+psize)
parity = [int(0)]*int(psize)

for i in range(psize):
    parity[i]=int(math.pow(2,i))
print(parity)

for i in parity:
    a[i-1]=1

print(a)

k=0
for i in range(N+psize):
    if(a[i]==1):
        continue
    else:
        a[i]=int(msg[k])
        print(msg[k])
        k=k+1
print(a)

for i in parity:
    if(i==1):
        a[i-1]=a[2]^a[4]^a[6]  
    elif(i==2):
        a[i-1]=a[2]^a[5]^a[6]
    else:
        a[i-1]=a[4]^a[5]^a[6]
print(a)
