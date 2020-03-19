xset('window',1);
x1=[0:0.01:2];
plot2d(x1,sin(2*%pi*x1),6);
plot2d(x1,cos(2*%pi*x1),7);
plot2d(x1,sin(2*%pi*x1)+cos(2*%pi*x1),9);
legend(['sinx','cosx','sinx+cosx']);


xset('window',2);
x=[0:0.01:3.5];
y=sin(x);
for i = 1:7
    y=sin(i*x);
    plot2d(x,y,9);
end
title(['sin with change in frequency']);


xset('window',3);
x=[0:0.001:20];
y=sin(x);
plot(x,y);
for i = 1:20
    y=sin(x+i);
    plot2d(x,y,i);
end
title(['sin with phase diff']);


xset('window',4);
x=[0:0.001:20];
y=sin(x);
plot(x,y);
for i = 1:20
    y=i*sin(x);
    plot2d(x,y,i);
end
title(['sin with amplitude diff']);