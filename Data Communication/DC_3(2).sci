x=[0:0.001:20];
y=sin(x);
plot(x,y);
for i = 1:20
    y=sin(x+i);
    plot2d(x,y,i);
end
title(['sin with phase diff']);