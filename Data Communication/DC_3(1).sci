x=[0:0.01:3.5];
y=sin(x);
for i = 1:7
    y=sin(i*x);
    plot2d(x,y,9);
end
title(['sin with change in frequency']);