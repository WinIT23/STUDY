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
