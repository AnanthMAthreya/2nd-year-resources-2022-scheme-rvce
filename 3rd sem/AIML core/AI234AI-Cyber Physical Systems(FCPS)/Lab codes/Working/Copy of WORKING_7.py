import cv2

cam = cv2.VideoCapture(0)
image = 0


def CaptureImage():
	
	print("Capturing Image :")
	ret, image = cam.read()
	cv2.imshow('ImageTest',image)
	k = cv2.waitKey(10000)
	print("Image Capture successfully")
	cv2.imwrite('/home/pi/Desktop/testimage.jpg',image)
	cam.release()
	cv2.destroyAllWindows()

def AnnotateImage():
	print("print Annotation Completed..")
	ImageCopy = cv2.imread('/home/pi/Desktop/testimage.jpg')
	ImageDimension = ImageCopy.shape
	print("Dimension of the Image :",str(ImageDimension))
	Start = (250,0)
	End = ( 400,200)
	Start1 = (200,0)
	End1 = ( 800,400)
	cv2.rectangle(ImageCopy , Start,End,(0,0,255),thickness = 3, lineType = cv2.LINE_8)
	cv2.putText(ImageCopy, "0", (0,330), cv2.FONT_HERSHEY_SIMPLEX, 0.5,(255,0,0),1)
	cv2.rectangle(ImageCopy , Start1,End1,(0,255,0),thickness = 3, lineType = cv2.LINE_8)
	cv2.putText(ImageCopy, "1", (0,330), cv2.FONT_HERSHEY_SIMPLEX, 0.5,(255,0,0),1)
	
	cv2.imshow('AnnotatedImage', ImageCopy)
	cv2.waitKey(10000)

CaptureImage()
AnnotateImage()
