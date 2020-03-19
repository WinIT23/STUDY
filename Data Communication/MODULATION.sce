t=linspace(0,7,500)
Am=5;
Ac=10;
Fm=2;
Fc=10;
K=2;
Em=Am*sin(2*%pi*Fm*t);
Ec=Ac*sin(2*%pi*Fc*t);
Ef=Em;

//-----------------------------------------------------------------------//

scf(1)
subplot(311)
title("modulating signal")
plot2d(t,Em)

subplot(312)
title("carrier signal")
plot2d(t,Ec)

Af=Em+Ac;
Ef=Af.*sin(2*%pi*Fc*t);

subplot(313)
title("amplitude modulation")
plot2d(t,Ef);

//------------------------------------------------------------------------//

scf(2)
subplot(311)
title("modulating signal")
plot2d(t,Em)

subplot(312)
title("carrier signal")
plot2d(t,Ec)

subplot(313)
title("frequency modulation")


Ef=Ac.*(sin(2*%pi*Fc*t + (Am/Fm)*sin(2*%pi*Fm*t)));
plot2d(t,Ef);

//------------------------------------------------------------------------//

Fm=0.5;
Am=5;
Ac=10;
Fc=2;
scf(3)
subplot(311)
title("modulating signal")
plot2d(t,Em)

subplot(312)
title("carrier signal")
plot2d(t,Ec)

subplot(313)
title("phase modulation")

x=Em*2;
Ef=Ac*sin(2*%pi*Fc*t + x);

plot2d(t,Ef);

//------------------------------------------------------------------------//
