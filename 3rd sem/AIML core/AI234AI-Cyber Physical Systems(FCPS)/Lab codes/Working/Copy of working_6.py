import cv2
from pushbullet import Pushbullet
from time import sleep 
from tkinter import messagebox
from tkinter import *

cam = cv2.VideoCapture(0)
image = 0

def CaptureImage():
	print("Capturing Image :")
	ret, image = cam.read()
	k = cv2.waitKey(10000)
	print("Image Capture successfully")
	cv2.imwrite('/home/pi/Desktop/testimage.jpg',image)
	cam.release()
	cv2.destroyAllWindows()
	print("Sending the Notification")

def SendNotification():
	root = Tk()
	root.geometry("50x70")
	pb = Pushbullet("o.l6F21M1FcdV5MVGqUNI3K81EGOR0KhmH")
	dev = pb.get_device("Samsung SM-M315F")
	with open('/home/pi/Desktop/testimage.jpg','rb') as pic:
		file_data = pb.upload_file(pic,"Picture.jpg")
		push = pb.push_file(**file_data)
		Value = push["active"]
		if Value == True:
			messagebox.showinfo("showinfo","Messagesent successfully...")
		else:
			messagebox.showwarning("showwarning","Sending Message Failed..")

CaptureImage()
SendNotification()
