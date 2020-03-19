a=[1;0;1;0;1;1;0;0;1];
x=[0.01:0.01:length(a)];
y=x;
for i=[1:length(a)]
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
xtitle("manchester line coding scheme(input=101011001)","time","voltage");
