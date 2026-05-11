import cv2 # OpenCVライブラリの読み込み
cap = cv2.VideoCapture(0)   # ←0で駄目なら1に修正する
assert cap.isOpened(), "カメラを起動できませんでした"
while cv2.waitKey(1) == -1: # キーが押されるまで繰返
  ret, frame = cap.read()   # 毎回フレームを読み込む
  assert ret, "フレームを読み込めませんでした"
  cv2.imshow("Smile Camera", frame) # 画面の表示