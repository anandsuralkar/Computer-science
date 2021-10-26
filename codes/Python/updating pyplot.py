import time
from matplotlib.backend_bases import MouseButton
from matplotlib import pyplot as plt
import numpy as np

def live_update_demo(event):

    plt.subplot(2, 1, 1)
    h1 = plt.imshow(np.random.randn(30, 30))
    redraw_figure()
    plt.subplot(2, 1, 2)
    h2, = plt.plot(np.random.randn(50))
    redraw_figure()

    t_start = time.time()
    while(event.button is MouseButton.LEFT):
        h1.set_data(np.random.randn(30, 30))
        redraw_figure()
        h2.set_ydata(np.random.randn(50))
        redraw_figure()
        print ('Mean Frame Rate: %.3gFPS') # ((i+1) / (time.time() - t_start))

def redraw_figure():
    plt.draw()
    plt.pause(0.0001)

def on_move(event):
    # get the x and y pixel coords
    x, y = event.x, event.y
    if event.inaxes:
        ax = event.inaxes  # the axes instance
        print('data coords %f %f' % (event.xdata, event.ydata))
def on_click(event):
    if event.button is MouseButton.LEFT:
        plt.disconnect(binding_id)

binding_id = plt.connect('motion_notify_event', live_update_demo)
plt.connect('button_press_event', on_click)    
live_update_demo(event)
