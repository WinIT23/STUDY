a=[1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1];
x=[0.01:0.01:length(a)];
y=x;
b=0;
ctr=1;
k=1;
for i=[1:1:length(a)-7]
while(a(1,i)==0)
            if(ctr==1)
                k=i;
            end
            ctr=ctr+1;
            i=i+1;
        end
        if(((ctr-1)/8)==1) then
            a(1,k-2+ctr)=1;
            a(1,k-2+ctr-1)=-1;
            a(1,k-2+ctr-3)=1;
            a(1,k-2+ctr-4)=-1;
         end
i=k;
ctr=1;
end
i=1;
k=1;
for i=[1:length(a)]
    b=i;
    for j=1:100
        if(a(1,i)==0)
            y(1,j+100*(i-1))=0;
        end
        if(a(1,i)==1)
            y(1,j+100*(i-1))=3;
        end
            if(a(1,i)==1 & i~=1)
                k=i-1;
                while (a(1,k)~=1 & k>0) then
                    b=k;
                    k=k-1;
                end
                l=y(1,j+(100*(b-2)));
                y(1,j+100*(i-1))=-1*l;
            end
            if(a(1,i)==-1 & i~=1)
                k=i-1;
                while (a(1,k)~=1 & k>0) then
                    b=k;
                    k=k-1;
                end
                l=y(1,j+(100*(b-2)));
                y(1,j+100*(i-1))=l;
            end
    end
end
plot(x,y);
plot(0,7);
plot(0,-7);
xtitle("differential manchester line coding scheme(input=101011001)","time","voltage");