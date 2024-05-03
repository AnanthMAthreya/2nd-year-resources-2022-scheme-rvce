from tkinter import *
from time import sleep

root = Tk()
root.geometry('600x150')

def rotate():
	from gpiozero import AngularServo
	from time import sleep
	servo = AngularServo(17, min_angle = -90, max_angle = 90)
	angle = V1.get()
	while True:
		servo.angle = angle
		sleep(20)

V1 = DoubleVar()
TitleLabel = Label(root,text = "select the angle of rotation using slider")
TitleLabel.config(font = ('helvetica',15))
TitleLabel.config(fg = "#DE3163")
                                                                                                                                                                                                                                                                                                                                                                            
Slider = Scale(root, variable = V1,from_ = -90, to=90, length=720,tickinterval=15,orient = HORIZONTAL)
SubmitBtn = Button(root,text = "Click here to rotate ",command = rotate, bg= 'Yellow')
TitleLabel.pack(anchor = CENTER)
Slider.pack(anchor = CENTER)
SubmitBtn.pack(anchor = CENTER)
root.mainloop()
