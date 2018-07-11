from PIL import Image
import os
import cv2

src = '.'
full_video_path = 'L2_M_55X7500F_XX_516.mp4'
cap  = cv2.VideoCapture(full_video_path)

success = True
frame_count = 1

while(success):
    filename = src + '/cropped/frameByframe/' + bytes(frame_count) + '.jpg' 
    success, frame = cap.read()
    print 'Read a new frame: ', success
	
    cropped = frame[200:450, 700:780]
    cv2.imwrite(filename, cropped)
	
    frame_count = frame_count + 1
cap.release()
