import sys

import tkinter

from matplotlib.backends.backend_tkagg import (
    FigureCanvasTkAgg, NavigationToolbar2Tk)
# Implement the default Matplotlib key bindings.
from matplotlib.backend_bases import key_press_handler
from matplotlib.figure import Figure
import matplotlib.pyplot as plt
import numpy as np
sys.path.append('./BO')
from BO.myBO import lgx_BO

from geo.point import Point
from geo.coordinates_hash import CoordinatesHash
from geo.segment import Segment
from bo import bentley_ottmann

root = tkinter.Tk()
root.wm_title("Embedding in Tk")


fig = Figure(figsize=(5, 4), dpi=100)
canvas = FigureCanvasTkAgg(fig, master=root)  # A tk.DrawingArea.
canvas.get_tk_widget().pack(side=tkinter.TOP, fill=tkinter.BOTH, expand=1)
ax = fig.add_subplot(111)
ax.set_xlim([0, 10])
ax.set_ylim([0, 10])


point = []
point_list = []

def _quit(): 
    root.quit()     # 停止主循环
    root.destroy()

def onclick(event):
    if event.xdata and event.ydata:
        global fig,ax,canvas
        global point
        point.extend([event.xdata, event.ydata])
        ax.scatter(event.xdata, event.ydata, s=10, c='r')
        if len(point) == 4:
            ax.plot([point[0],point[2]],[point[1],point[3]])
            point_list.append(point.copy())
            point.clear()
        canvas.draw()


fig.canvas.mpl_connect('button_press_event', onclick)

frm_1 = tkinter.Frame(master=root)             

button = tkinter.Button(master=frm_1, text="Quit", command=_quit)
button.pack(side=tkinter.RIGHT)
frm_1.pack(side=tkinter.BOTTOM)
tkinter.mainloop()