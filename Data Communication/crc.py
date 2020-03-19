def crc(data,divisor):
    temp = ''

    n = len(divisor)-1
    for i in range(n):
        data+='0'

    n+=1
    print("data after appending zeroes:",data)
    data +='0'

    k = 0
    #data = '10001100'
    temp = data[k:k+n]

    for t in range(len(data)-n+1):
        i = temp
        temp = ''
        for j in range(1,n):
            if(i[j]== str(int(i[0]) * int(divisor[j]))):
                temp+='0'
            else:
                temp+='1'
        if(not(t==len(data)-n)):
            temp+=data[k+n]
        k+=1
    print('Remainder =',i[:n-1])

data=input("enter data bits:")
divisor=input("enetr divisor:")
crc(data,divisor)
data=input("enter data bits for verification:")
crc(data,divisor)

