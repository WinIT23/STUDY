x=[0:0.001:20];
y=sin(x);
plot(x,y);
for i = 1:20
    y=i*sin(x);
    plot2d(x,y,i);
end
title(['sin with amplitude diff']);