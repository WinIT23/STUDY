from tabulate import tabulate

def sort_lists(list1, list2):
    zipped_pairs = zip(list1, list2)
    z = [x for _, x in sorted(zipped_pairs)]
    return z

arrivalTime = []
burstTime = []
while True:
    arrival = int(input("Enter Arrival Time...Enter -1 to exit:"))
    if arrival == -1:
        break
    arrivalTime.append(arrival)
    burst = int(input("Enter Burst Time:"))
    burstTime.append(burst)

burstTime = sort_lists(arrivalTime,burstTime)
arrivalTime.sort()
finishTime = [-1]*len(arrivalTime)

finishTime[0] = arrivalTime[0] + burstTime[0]

new = [[arrivalTime[0],burstTime[0],finishTime[0]]]
finishTime.pop(0)
arrivalTime.pop(0)
burstTime.pop(0)
i = 0
index = 0
while i < len(arrivalTime)-1:
    j = 0
    least = 99
    index = 0
    for j in range(0,len(arrivalTime)):
        if arrivalTime[0] > new[len(new)-1][2]:
            for k in range(j,len(arrivalTime)):
                if arrivalTime[k] != arrivalTime[0]:
                    break
            N = k
            for k in range(0,N):
                if burstTime[k] < least:
                    least = burstTime[k]
                    index = k
            finishTime[index] = arrivalTime[index] + burstTime[index]
        else:
            if arrivalTime[j] > new[len(new)-1][2]:
                break
            for k in range(0,j):
                if burstTime[k] < least:
                    least = burstTime[k]
                    index = k
            finishTime[index] = new[len(new)-1][2] + burstTime[index]
    new.append([arrivalTime[index],burstTime[index],finishTime[index]])
    finishTime.pop(index)
    arrivalTime.pop(index)
    burstTime.pop(index)

finishTime[0] = new[len(new)-1][2] + burstTime[0]
new.append([arrivalTime[0],burstTime[0],finishTime[0]])
finishTime.pop(0)
arrivalTime.pop(0)
burstTime.pop(0)
turnAroundTime = [0]*len(new)
waitingTime = [0]*len(new)
avgTAT = 0
avgWT = 0

for i in range(0,len(new)):
    turnAroundTime[i] = new[i][2] - new[i][0]
    avgTAT = avgTAT + turnAroundTime[i]
    waitingTime[i] = turnAroundTime[i] - new[i][1]
    avgWT = avgWT + waitingTime[i]

avgTAT = avgTAT/len(new)
avgWT = avgWT/len(new)

for i in range(len(new)):
    arrivalTime.append(new[i][0])
    burstTime.append(new[i][1])
    finishTime.append(new[i][2])
printResult = []
for i in range(len(new)):
    temp = []
    temp.extend([arrivalTime[i],burstTime[i],finishTime[i],turnAroundTime[i],waitingTime[i]])
    printResult.append(temp)

print(tabulate(printResult,headers=['AT', 'BT', "FT","TAT","WT"]))
print("average turn around time =",avgTAT,"average waiting time =",avgWT)
