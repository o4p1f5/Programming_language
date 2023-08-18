# print("#######################################################################")
# import cv2
#
# image = cv2.imread("C:\Systemprograming\cat.jpg")
# cv2.imshow("cat", image)
# key = cv2.waitKey()
# print("key in:", key)
# cv2.destroyAllWindows()
# import numpy as np
#
# print("#######################################################################")
# import os
# import numpy as np
# import cv2
#
# # 파일명 만들기
# IMG_PATH = "C:/Systemprograming/sample_imgs"
# filename = os.path.join(IMG_PATH, "superson.jpg")
# print("filename:", filename)
# # 세 가지 형식으로 영상 불러오기
# img_color = cv2.imread(filename, cv2.IMREAD_COLOR)
# img_gray = cv2.imread(filename, cv2.IMREAD_GRAYSCALE)
# img_unchange = cv2.imread(filename, cv2.IMREAD_UNCHANGED)
# # 영상 보여주기
# cv2.imshow("superson-color", img_color)
# cv2.imshow("superson-gray", img_gray)
# cv2.imshow("superson-unchange", img_unchange)
# key = cv2.waitKey()
# print("key in:", key, "==", chr(key)) # chr : 유니코드 숫자를 문자로 변환
# # key가 's'이면 영상 저장
# # ord = 키 상태 받기
# if key == ord('s'):
#     filename = os.path.join(IMG_PATH, "superson-save.jpg")
#     cv2.imwrite(filename, img_color)
# cv2.destroyAllWindows()
#
# print("#######################################################################")
# import os
# import numpy as np
# import cv2
#
# import os
# import cv2
# # 동영상 파일 열기
# IMG_PATH = "C:/Systemprograming/sample_imgs"
# filename = os.path.join(IMG_PATH, "endgame.mp4")
# # VideoCapture(0)은 노트북 웹캠으로 연결됨
# cap = cv2.VideoCapture(filename)
# while 1:
#     # 프레임 한 장 읽기
#     ret, frame = cap.read()
#     if not ret:
#         break
#     cv2.imshow('frame', frame)
#     # 'q'를 누르면 종료
#     if cv2.waitKey(33) == ord('q'):
#         break
# # release = close
# cap.release()
#
# print("#######################################################################")
# import os
# import cv2
#
# # 원본 동영상 파일 열기
# IMG_PATH = "C:/Systemprograming/sample_imgs"
# filename = os.path.join(IMG_PATH, "endgame.mp4")
# cap = cv2.VideoCapture(filename)
# if not cap.isOpened():
#     raise FileNotFoundError()
# print(f'get video property: width={cap.get(cv2.CAP_PROP_FRAME_WIDTH)}, '
#       f'height={cap.get(cv2.CAP_PROP_FRAME_HEIGHT)}')
# # 영상의 20초부터 시작
# cap.set(cv2.CAP_PROP_POS_MSEC, 20000)
# # 저장할 동영상 파일 열기
# filename = os.path.join(IMG_PATH, "endgame_rsz.mp4")
# fourcc = cv2.VideoWriter_fourcc(*'mp4v')    # *'DIVX'
# new_size = (640, 360)						# 동영상을 저장할 해상도
# # filename, file type, 프레임 속도, 프레임 크기
# vout = cv2.VideoWriter(filename, fourcc, 30, new_size)
# if not vout.isOpened():
#     raise FileNotFoundError()
#
# while 1:
#     ret, frame = cap.read()
#     if not ret:
#         break
#     # 프레임 영상 크기 조절
#     frame_rsz = cv2.resize(frame, new_size)
#     cv2.imshow('frame', frame_rsz)
#     if cv2.waitKey(33) == ord('q'):
#         break
#     # 프레임 쓰기(저장)
#     vout.write(frame_rsz)
#
# cap.release()
# vout.release()
#
# print("#######################################################################")
# import os
import numpy as np
# import cv2
#
# # 파일명 만들기
# IMG_PATH = "C:/Systemprograming/sample_imgs"
# filename = os.path.join(IMG_PATH, "jjang.jpg")
# print("filename:", filename)
# # 세 가지 형식으로 영상 불러오기
# image = cv2.imread(filename)
#
# print(f"image info: shape ={image.shape}, dtype={image.dtype}, size={image.size}")
# # 영상 보여주기
# newimg = image.copy()
#
# # newimg[100,150,0] = 255 # white
# # cv2.imshow("jjangjeolmi", newimg)
# # cv2.waitKey()
# #
# # # blue, green, red
# # newimg[100,150,:] = (0,0,255) # red
# # cv2.imshow("jjangjeolmi", newimg)
# # cv2.waitKey()
# #
# # newimg[100] = (0,255,0) # green
# # newimg[:, 100] = (0,255,0) # green
# # cv2.imshow("jjangjeolmi", newimg)
# # cv2.waitKey()
# #
# # newimg[:10, :, :] = 255      # 위에 흰 줄
# # newimg[-10:, :, :] = 0       # 아래에 검은 줄
# # newimg[:, :10, 0] = 255      # 왼쪽에 파란 줄
# # newimg[:, :10, 1:] = 0
# # newimg[:, -10:, :] = (0, 0, 255)     # 오른쪽에 빨간 줄
# # cv2.imshow("jjangzeolmi", newimg)
# # cv2.waitKey()
#
# # 연습문제
# newimg[100, 100:150] = 255
# newimg[100:150, 100] = 255
# newimg[150, 100:150] = 255
# newimg[100:150, 150] = 255
# cv2.imshow("jjangzeolmi", newimg)
# cv2.waitKey()
#
# print("#######################################################################")
# import os
# import cv2
#
# IMG_PATH = "C:/Systemprograming/sample_imgs"
# filename = os.path.join(IMG_PATH, "makrae.jpg")
# srcimg = cv2.imread(filename)
# shapeimg = srcimg.copy()
# # 도형 그리기
# cv2.line(shapeimg, pt1=(50, 110), pt2=(105, 110), color=(255, 0, 0), thickness=2)
# cv2.circle(shapeimg, center=(33, 150), radius=20, color=(0, 0, 255), thickness=2)
# cv2.rectangle(shapeimg, pt1=(160, 20), pt2=(340, 240), color=(0, 255, 0), thickness=1)
# cv2.putText(shapeimg, text="Korea Grandma", org=(360, 100),
#             fontFace=cv2.FONT_HERSHEY_SCRIPT_SIMPLEX, fontScale=0.5, color=(50, 50, 50))
# # 보여주기
# cv2.imshow("original", srcimg)
# cv2.imshow("draw shape", shapeimg)
# cv2.waitKey()
#
# print("#######################################################################")
# import os
# import cv2
#
# class MouseEventHandler:
#     def __init__(self, title, image):
#         self.title = title
#         self.image = image.copy()
#         self.pt1 = (0, 0)
#
#     def on_mouse_event(self, event, x, y, flags, param):
#         if event == cv2.EVENT_LBUTTONDOWN:  # 마우스를 눌렀을 때
#             pass
#         elif event == cv2.EVENT_MOUSEMOVE:  # 마우스가 이동할 때
#             if flags == cv2.EVENT_FLAG_LBUTTON:
#                 self.image[y, x] = 255
#                 cv2.imshow(self.title, self.image)
#         elif event == cv2.EVENT_LBUTTONUP:  # 마우스 버튼을 땔 때
#             pass
#
# def draw_line():
#     IMG_PATH = "C:/Systemprograming/sample_imgs"
#     filename = os.path.join(IMG_PATH, "makrae.jpg")
#     srcimg = cv2.imread(filename)
#     window_name = "line_drawing"
#     cv2.imshow(window_name, srcimg)
#
#     mouse_hndl = MouseEventHandler(window_name, srcimg)
#     # 반드시 imshow()나 namedWindow()로 윈도우를 먼저 만든 후 실행할 것
#     cv2.setMouseCallback(window_name, mouse_hndl.on_mouse_event)
#     cv2.waitKey()
#
# if __name__ == "__main__":
#     draw_line()

print("#######################################################################")
import os
import cv2

IMG_PATH = "C:/Systemprograming/sample_imgs"
filename = os.path.join(IMG_PATH, "spiderman.jpg")

# BRG channels 이미지
bgrimg = cv2.imread(filename)

# BGR -> GRAY
grayimg = cv2.cvtColor(bgrimg, cv2.COLOR_BGR2GRAY)
print('grayimg shape :', grayimg.shape)

# GRAY -> BINARY
binaryimg = grayimg.copy()
binaryimg[grayimg < 120] = 0
binaryimg[grayimg >= 120] = 255

# 세 이미지 한번에 뽑기
grayimg = cv2.cvtColor(grayimg, cv2.COLOR_GRAY2BGR)
binaryimg = cv2.cvtColor(binaryimg, cv2.COLOR_GRAY2BGR)
concating = np.concatenate([binaryimg, grayimg, bgrimg], axis=1)
cv2.imshow('binary gray bgr', concating)
cv2.waitKey()

# blue, green, red 채널별로 이미지 모아서 뽑기
channels = np.concatenate([bgrimg[:,:,0], bgrimg[:,:,1], bgrimg[:,:,2]], axis=1)
cv2.imshow('BGR channels', bgrimg[:,:,0])
cv2.waitKey()
cv2.imshow('BGR channels', channels)
cv2.waitKey()
#
# print("#######################################################################")
# import os
# import cv2
#
# IMG_PATH = "C:/Systemprograming/sample_imgs"
# filename = os.path.join(IMG_PATH, "spiderman.jpg")
# bgrimg = cv2.imread(filename)
#
# hsvimg = cv2.cvtColor(bgrimg, cv2.COLOR_BGR2HSV)
#
# # channel 순서 => 색조, 채도, 명도
# channels = np.concatenate([hsvimg[:,:,0], hsvimg[:,:,1], hsvimg[:,:,2]], axis=1)
# cv2.imshow('HRV channels', channels)
# cv2.waitKey()
#
# # 얼굴, 몸 구분
# hueimg = hsvimg[:,:,0]
# valueimg = hsvimg[:,:,2]
#
# faceimg = np.zeros_like(bgrimg)
# # 인덱스에 T/F로 조건을 넣어주면 True인 부분만 출력
# # 색조만 고려해서 이후 RGB는 그대로 따라옴
# # faceimg에서 추출된 부분에 bgrimg의 추출된 부분을 덮어씌움
# faceimg[hueimg < 13, :] = bgrimg[hueimg < 13, :]
#
# bodyimg = np.zeros_like(bgrimg)
# bodyimg[hueimg > 170, :] = bgrimg[hueimg > 170, :]
# bodyimg[(hueimg>100) & (hueimg<130), :] = bgrimg[(hueimg>100) & (hueimg<130), :]
# bodyimg[valueimg>220] = 0 # 배경 제거
#
# segment = np.concatenate([faceimg, bodyimg], axis=1)
# cv2.imshow("segmented image", segment)
# cv2.waitKey()