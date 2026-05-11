import cv2
import numpy as np

# 分類器
face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')
eye_cascade  = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_eye.xml')

# 丸く切り抜く関数
def circular_masked_image(img):
    h, w = img.shape[:2]
    mask = np.zeros((h, w), dtype=np.uint8)
    cv2.circle(mask, (w // 2, h // 2), min(w, h) // 2, 255, -1)
    result = cv2.bitwise_and(img, img, mask=mask)
    return result

# カメラ起動
cap = cv2.VideoCapture(0)
if not cap.isOpened():
    raise RuntimeError("カメラが開けません")

while True:
    ret, frame = cap.read()
    if not ret:
        break

    frame = cv2.flip(frame, 1)
    gray  = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    faces = face_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=5)

    for (x, y, w, h) in faces:
        face_roi_gray  = gray[y:y+h, x:x+w]
        face_roi_color = frame[y:y+h, x:x+w]

        eyes = eye_cascade.detectMultiScale(face_roi_gray, scaleFactor=1.2, minNeighbors=5)
        if len(eyes) == 0:
            continue

        # 最初の目だけ使う
        ex, ey, ew, eh = eyes[0]
        eye_img = face_roi_color[ey:ey+eh, ex:ex+ew]

        # 丸く切り抜き
        eye_circular = circular_masked_image(eye_img)

        # 顔サイズにリサイズ
        eye_resized = cv2.resize(eye_circular, (w, h))

        # マスクもリサイズ
        mask = cv2.cvtColor(eye_resized, cv2.COLOR_BGR2GRAY)
        _, mask = cv2.threshold(mask, 1, 255, cv2.THRESH_BINARY)

        # 合成
        roi = frame[y:y+h, x:x+w]
        bg = cv2.bitwise_and(roi, roi, mask=cv2.bitwise_not(mask))
        fg = cv2.bitwise_and(eye_resized, eye_resized, mask=mask)
        frame[y:y+h, x:x+w] = cv2.add(bg, fg)

    cv2.imshow('Circular Eye Face', frame)

    if cv2.waitKey(1) != -1:
        break

cap.release()
cv2.destroyAllWindows()
