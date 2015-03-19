function circle(R)
alpha=0:pi/50:2*pi;
x = R*cos(alpha);
y = 2*sin(alpha);
plot(x,y,'-')
axis equal