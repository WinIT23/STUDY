a=[1;0;1;0;1;1;0];
x=[0.01:0.01:length(a)];
y=x;
for i=[1:length(a)]
    for j=(100*(i-1))+1:100*i
        y(j,1)=a(i,1)*3;
    end
end
plot(x,y);
plot(0,-2);
xtitle("unipolar line coding scheme(input=1010110)","time","voltage");
