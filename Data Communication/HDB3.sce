x = [1;1;1;0;0;0;0;0;0;0;0;0;0;0;1];
l = length(x);
y=[];
peak = 0;  //for counting total 1s
count = 0;  //for counting consecutive 0s
last = 0;
if(x(1)==1) then
    y(1) = 5;
    last = 5;
    peak = peak+1;
else
    count = count+1;
    y(1) = 0;
end

for i=2:l
    if(x(i)==0) then
        count = count+1;
        y(i) = 0;
    else
        count = 0;
        y(i) = -last;
        last = y(i);
        peak = peak +1;
    end
    if(count==4) then
        if(modulo(peak,2)==0) then
            y(i-3) = -last;
            last = y(i-3);
            peak = peak+1;
        end
        y(i) = last;
        peak = peak+1;
        count = 0;
    end
end
//a = gca();
//a.box="off";
//a.x_location="middle";
y(l+1) = 0;
for i=1:l
    plot2d2 ([i-1,i],[y(i),y(i+1)]);
end
disp(y);
