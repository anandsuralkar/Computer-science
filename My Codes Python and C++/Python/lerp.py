from matplotlib.backend_bases import MouseButton
import matplotlib.pyplot as plt
import numpy as np

t = np.arange(0.0, 1.0, 0.01)
s = np.sin(2 * np.pi * t)
fig, ax = plt.subplots()
ax.plot(t, s)


def on_move(event):
    # get the x and y pixel coords
    x, y = event.x, event.y
    if event.inaxes:
        ax = event.inaxes  # the axes instance
        print('data coords %f %f' % (event.xdata, event.ydata))


def on_click(event):
    if event.button is MouseButton.LEFT:
        print('disconnecting callback')
        plt.disconnect(binding_id)


binding_id = plt.connect('motion_notify_event', on_move)
plt.connect('button_press_event', on_click)



def lerp(a,b,t):
    return ((1-t)*a[0]+t*b[0],(1-t)*a[1]+t*b[1])
p0=(0,0)
p1=(0,1)
p2=(1,1)
p3=(1,0)

t=0
l=[]
k=[]
x=[]
y=[]
while(t<1.02):
    a=lerp(p0,p1,t)
    b=lerp(p1,p2,t)
    c=lerp(p2,p3,t)
    d=lerp(a,b,t)
    e=lerp(b,c,t)
    p=lerp(d,e,t)
    l.append(p[0])
    k.append(p[1])
    t+=0.02
x.append(p0[0])
x.append(p1[0])
x.append(p2[0])
x.append(p3[0])
y.append(p0[1])
y.append(p1[1])
y.append(p2[1])
y.append(p3[1])
plt.plot(l,k)
plt.scatter(x,y)
plt.show()
