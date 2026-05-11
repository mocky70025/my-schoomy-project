import cv2
import subprocess

face = cv2.CascadeClassifier(cv2.data.haarcascades + "haarcascade_frontalface_default.xml")
smile = cv2.CascadeClassifier(cv2.data.haarcascades + "haarcascade_smile.xml")
cap = cv2.VideoCapture(0)  # ←0が駄目なら1に修正

while cv2.waitKey(1) < 0:
    ret, frame = cap.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    faces = face.detectMultiScale(gray, 1.3, 5)

    smiles = []  # ループの外で初期化
    for (x, y, w, h) in faces:
        roi = gray[y:y + h, x:x + w]  # 顔の中だけ
        smiles = smile.detectMultiScale(roi, 1.7, 20)  # 笑顔検出
        color = (0, 255, 0) if len(smiles) > 0 else (0, 0, 255)  # 緑
        cv2.rectangle(frame, (x, y), (x + w, y + h), color, 2)  # 枠線

        cv2.imshow("Smile Camera", frame)

    # ----以下の行を追加する----
    if len(smiles) > 0:
        break  # 笑顔を認識したら撮影処理へ

cv2.imwrite("smile.jpg", frame)  # JPEGで保存
subprocess.call(["osascript", "smile.scpt"])