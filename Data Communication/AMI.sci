a=[1;0;1;0;1;1;0;0;1];
x=[0.01:0.01:length(a)];
y=x;
b=0;
for i=[1:length(a)]
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
xtitle("differential manchester line coding scheme(input=101011001)","time","voltage");