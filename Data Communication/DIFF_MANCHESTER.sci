a=[1;0;1;0;1;1;0;0;1];
x=[0.01:0.01:length(a)];
y=x;
b=0;
for i=[1:length(a)]
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
xtitle("differential manchester line coding scheme(input=101011001)","time","voltage");