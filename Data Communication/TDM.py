N=int(input("enter no. of total msgs: "))
lines=[""]*N

for i in range(N):
    lines[i]=input("enter msg:")

frames = []
s=''

max = len(lines[0])
for i in lines:
    if(len(i)>max):
        max = len(i)

for i in range(N):
    if(len(lines[i])<max):
        for j in range(max-len(lines[i])):
            lines[i]+='-'

n = int(input("Enter no. of characters from each line: "))
k=0

for j in range(int(max/n)):
    s=''
    for i in lines:
        s+= i[k:n+k]
    k=k+n
    frames.append(s)

print(frames)
