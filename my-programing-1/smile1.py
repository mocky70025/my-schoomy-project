import cv2
face = cv2.CascadeClassifier(cv2.data.haarcascades+"haarcascade_frontalface_default.xml")
cap = cv2.VideoCapture(0) # ←0が駄目なら1に修正
while cv2.waitKey(1)<0:
  ret, frame = cap.read()
  faces = face.detectMultiScale(cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY),1.3,5)
  for(x,y,w,h) in faces:
    cv2.rectangle(frame,(x,y),(x+w,y+h),(0,0,255),2)
    cv2.imshow("Smile Camera",frame)