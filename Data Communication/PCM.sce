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
