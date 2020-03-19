subplot(231);
len=0;
len=input("enter the size of data.");
a=zeros(len,1);
for i=1:len
    a(i,1)=input("enter ith data element.");
end
x=[0.01:0.01:len];
y=x;
for i=[1:len]
    for j=(100*(i-1))+1:100*i
        y(j,1)=a(i,1)*3;
    end
end
plot(x,y);
plot(0,-2);
xtitle("unipolar line coding scheme  ","time","voltage");

subplot(232);

x=[0.01:0.01:len];
y=x;
amp=3;
for i=[1:len]
        if(a(i,1)==0)
            for j=(i-1)*100+1:100*i
                y(j,1)=amp;
            end
        elseif(a(i,1)==1)
            amp=amp*(-1);
            for j=(i-1)*100+1:100*i
                y(j,1)=amp;
            end
        end
end
plot(x,y);
plot(0,-7);
xtitle("NRZ-I line coding scheme","time","voltage");


subplot(233);

x=[0.01:0.01:len];
y=x;
for i=[1:len]
    for j=(100*(i-1))+1:100*i
        if(a(i,1)==0)
            y(j,1)=3;
        elseif(a(i,1)==1)
            y(j,1)=-3;
            end
    end
end
plot(x,y);
plot(0,-7);
xtitle("NRZ-L line coding scheme  ","time","voltage");

subplot(234);

x=[0.01:0.01:len];
y=x;
for i=[1:len]
    for j=1:50
        if(a(i,1)==0)
            y(j+100*(i-1),1)=3;
        end
        if(a(i,1)==1)
            y(j+100*(i-1),1)=-3;
        end
    end
    for j=51:100
        if(a(i,1)==0)
            y(j+100*(i-1),1)=-3;
        end
        if(a(i,1)==1)
            y(j+100*(i-1),1)=3;
        end
    end
end
plot(x,y);
xtitle("manchester line coding scheme ","time","voltage");



subplot(235);

x=[0.01:0.01:len];
y=x;
b=0;
for i=[1:len]
    b=i;
    for j=1:50
        if(a(i,1)==0)
            y(j+100*(i-1),1)=3;
        end
        if(a(i,1)==1)
            y(j+100*(i-1),1)=-3;
        end
            if(a(i,1)==0 & i~=1)
                b=i-1;
                l=y(j+100*(b-1),1);
                y(j+100*(i-1),1)=l;
            end
            if(a(i,1)==1 & i~=1)
                b=i-1;
                l=y(j+100*(b-1),1);
                y(j+100*(i-1),1)=-1*l;
            end
            
    end
     for j=51:100
        if(a(i,1)==0)
            y(j+100*(i-1),1)=-3;
        end
        if(a(i,1)==1)
            y(j+100*(i-1),1)=3;
        end
            if(a(i,1)==0 & i~=1)
                k=i-1;
                b=k;
                l=y(j+100*(b-1),1);
                y(j+100*(i-1),1)=l;
            end
            if(a(i,1)==1 & i~=1)
                k=i-1;
                b=k;
                l=y(j+100*(b-1),1);
                y(j+100*(i-1),1)=-1*l;
            end
    end
end
plot(x,y);
xtitle("differential manchester line coding scheme","time","voltage");



subplot(236);

x=[0.01:0.01:len];
y=x;
b=0;
for i=[1:len]
    b=i;
    for j=1:100
        if(a(i,1)==0)
            y(j+100*(i-1),1)=0;
        end
        if(a(i,1)==1)
            y(j+100*(i-1),1)=3;
        end
            if(a(i,1)==1 & i~=1)
                k=i-1;
                while (a(k,1)~=1 & k>0) then
                    b=k;
                    k=k-1;
                end
                l=y(j+(100*(b-2)),1);
                y(j+100*(i-1),1)=-1*l;
            end
    end
end
plot(x,y);
xtitle("AMI line coding scheme ","time","voltage");



x = [1;1;0;0;0;0;0;0;0;0;0;0;0;1];
l = length(x);
y=[];
count = 0;
last = 0;
if(x(1)==1) then 
    y(1) = 5;
    last = 5;
else
    count = count+1;
    y(1) = 0;
end

for i=2:l
    if(x(i)==0) then 
        count = count+1;
        y(i) = 0;
    else
        count = 0;
        y(i) = -last;
        last = y(i);
    end
    if(count==8)
        for j=(i-7):i
            if(j-i+8==4) then
                y(j) = last;
            else if(j-i+8==5) then 
                    y(j) = -last;
                else if(j-i+8==7) then
                        y(j) = -last;
                    else if(j-i+8==8) then
                            y(j) = last;
                        end
                    end
                end
            end
        end
        count = 0;
    end
end

y(l+1) = 0;
for i=1:l
    plot2d2 ([i-1,i],[y(i),y(i+1)]);
end




x = [1;1;1;0;0;0;0;0;0;0;0;0;0;0;1];
l = length(x);
y=[];
peak = 0;  //for counting total 1s
count = 0;  //for counting consecutive 0s
last = 0;
if(x(1)==1) then
    y(1) = 5;
    last = 5;
    peak = peak+1;
else
    count = count+1;
    y(1) = 0;
end

for i=2:l
    if(x(i)==0) then
        count = count+1;
        y(i) = 0;
    else
        count = 0;
        y(i) = -last;
        last = y(i);
        peak = peak +1;
    end
    if(count==4) then
        if(modulo(peak,2)==0) then
            y(i-3) = -last;
            last = y(i-3);
            peak = peak+1;
        end
        y(i) = last;
        peak = peak+1;
        count = 0;
    end
end
//a = gca();
//a.box="off";
//a.x_location="middle";
y(l+1) = 0;
for i=1:l
    plot2d2 ([i-1,i],[y(i),y(i+1)]);
end
disp(y);





t=linspace(0,7,500)
Am=5;
Ac=10;
Fm=2;
Fc=10;
K=2;
Em=Am*sin(2*%pi*Fm*t);
Ec=Ac*sin(2*%pi*Fc*t);
Ef=Em;

//-----------------------------------------------------------------------//

scf(1)
subplot(311)
title("modulating signal")
plot2d(t,Em)

subplot(312)
title("carrier signal")
plot2d(t,Ec)

Af=Em+Ac;
Ef=Af.*sin(2*%pi*Fc*t);

subplot(313)
title("amplitude modulation")
plot2d(t,Ef);

//------------------------------------------------------------------------//

scf(2)
subplot(311)
title("modulating signal")
plot2d(t,Em)

subplot(312)
title("carrier signal")
plot2d(t,Ec)

subplot(313)
title("frequency modulation")


Ef=Ac*(sin(2*%pi*Fc*t + (Am/Fm)*sin(2*%pi*Fm*t)));
plot2d(t,Ef);

//------------------------------------------------------------------------//

Fm=0.5;
Am=5;
Ac=10;
Fc=2;
scf(3)
subplot(311)
title("modulating signal")
plot2d(t,Em)

subplot(312)
title("carrier signal")
plot2d(t,Ec)

subplot(313)
title("phase modulation")

x=Em*K;
Ef=Ac*sin(2*%pi*Fc*t + x);

plot2d(t,Ef);

//------------------------------------------------------------------------//





clear
clc
t=linspace(0,20,2000);
A=input("enter maximum amplitude of signal: ");
Y=A*sin(t);
level=8;
gap=2*A/level;
msg="";
SRate=input("enter the sampling rate: ");  //we'll take 5 samples per second
k=100/SRate;
for i=1:length(t)
    if(modulo(i,k)==0)
        sam=Y(1,i);
        mprintf("for amplitue = %lf     =>    ",sam);
        sam=floor(sam/gap);
        select sam
        case 0 msg=" 000 "
        case 1 msg=" 001 "
        case 2 msg=" 010 "
        case 3 msg=" 011 "
        case 4 msg=" 011 " //particularly for sam=20(same as of 15 to 19.99)
        case -1 msg=" 100 "
        case -2 msg=" 101 "
        case -3 msg=" 110 "
        case -4 msg=" 111 "
        end
        mprintf("encoded binary bits = %s \n",msg)
    end
end



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

n = int(input("Enter no. of characters from each line: "))


for i in range(N):
    if(len(lines[i])<=max):
        for j in range(max+(max%n)-len(lines[i])):
            lines[i]+='-'

print(lines)
k=0
for j in range(int(max/n)+1):
    s=''
    for i in lines:
        s+= i[k:n+k]
    k=k+n
    frames.append(s)

print(frames)




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


