a=[1;0;1;0;1;1;0];
x=[0.01:0.01:length(a)];
y=x;
amp=5;
for i=[1:length(a)]
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
xtitle("NRZ-I line coding scheme(input=1010110)","time","voltage");