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
    for j in range(len(memory)):
        if req[i] < memory[j]:
            memory[j] = memory[j] - req[i]
            break

print(memory)
