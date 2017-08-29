import sys
import cv2
cap = cv2.VideoCapture(sys.argv[1])
if( cap.isOpened() ) :
    ret,img = cap.read()
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_alt.xml')
faces = face_cascade.detectMultiScale(img, 1.3, 5, cv2.cv.CV_HAAR_SCALE_IMAGE)
print len(faces)
