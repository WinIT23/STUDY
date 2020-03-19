memory = []
while True:
    inp = int(input("enter memory block size(enter ''-1' to exit): "))
    if inp == -1:
        break
    memory.append(inp)

req = []
while True:
    inp = int(input("enter process size(enter ''-1' to exit): "))
    if inp == -1:
        break
    req.append(inp)

for i in range(len(req)):
    max = -99999
    flag = False
    for j in range(len(memory)):
        if memory[j] > req[i] and memory[j] > max:
            max = memory[j]
            index = j
            flag = True
    if not flag:
        print("!!!!!!!!!!process ",str(j+1),"can't be allocated memory:!!!!!!!!!!")
    if flag:
        memory[index] -= req[i]

print(memory)
