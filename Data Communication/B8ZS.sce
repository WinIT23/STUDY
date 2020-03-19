x = [1;1;0;0;0;0;0;0;0;0;0;0;0;1];
l = length(x);
y=[];
count = 0;
last = 0;
if(x(1)==1) then 
    y(1) = 5;
    last = 5;
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
    end
    if(count==8)
        for j=(i-7):i
            if(j-i+8==4) then
                y(j) = last;
            else if(j-i+8==5) then 
                    y(j) = -last;
                else if(j-i+8==7) then
                        y(j) = -last;
                    else if(j-i+8==8) then
                            y(j) = last;
                        end
                    end
                end
            end
        end
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
