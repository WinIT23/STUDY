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
print(len(arrivalTime))
finishTime = [0]*len(arrivalTime)

finishTime[0] = arrivalTime[0] + burstTime[0]

for i in range(1,len(arrivalTime)):
    if finishTime[i-1] < arrivalTime[i]:
        finishTime[i] = arrivalTime[i] + burstTime[i]
    else:
        finishTime[i] = finishTime[i-1] + burstTime[i]

turnAroundTime = [0]*len(arrivalTime)
waitingTime = [0]*len(arrivalTime)
avgTAT = 0
avgWT = 0

for i in range(0,len(arrivalTime)):
    turnAroundTime[i] = finishTime[i] - arrivalTime[i]
    avgTAT = avgTAT + turnAroundTime[i]
    waitingTime[i] = turnAroundTime[i] - burstTime[i]
    avgWT = avgWT + waitingTime[i]

avgTAT = avgTAT/len(arrivalTime)
avgWT = avgWT/len(arrivalTime)

printResult = []
for i in range(len(arrivalTime)):
    temp = []
    temp.extend([arrivalTime[i],burstTime[i],finishTime[i],turnAroundTime[i],waitingTime[i]])
    printResult.append(temp)

print(tabulate(printResult,headers=['AT', 'BT', "FT","TAT","WT"]))
print("average turn around time =",avgTAT,"average waiting time =",avgWT)
