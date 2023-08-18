print("########################################################################")
# mean filter : 평균 필터
# Gaussian filter : 점을 퍼뜨림 : 평균 필터보다 부드러운 블러링
# Median filter : 노이즈를 없앤 블러링
# bilateral filter : 픽셀과의 거리와 색상 차이 고려
# Edge detection : 엣지의 강도와 방향을 고려 : Sobel() : Laplacian() : Canny()
# Mophology : 바이너리 영상 : 침식과 팽창 : getStruchturingElement : erode : dilate : morphologyEx

import cv2
import numpy as np
# show_imgs = matplotlib처럼 사진 여러개를 한번에 보여줌
import show_imgs as si
IMG_PATH = "C:/Systemprograming/sample_imgs"


def blur():
    image = cv2.imread(IMG_PATH + "/yumi-cells.jpg")
    kernel_sizes = [(1, 1), (3, 3), (5, 5), (7, 7), (7, 1), (1, 7)]
    filter_imgs = {}
    blur_imgs = {}

    # filter2D() vs blur() 비교
    for ksize in kernel_sizes:
        title = f"ksize: {ksize}"
        kernel = np.ones(ksize)
        kernel /= kernel.size
        filter_imgs[title] = cv2.filter2D(image, -1, kernel)
        # ksize는 너비, 높이 순서가 달라서 filter2D와 blur의 (7,1) (1,7) 결과가 반대됨
        blur_imgs[title] = cv2.blur(image, ksize)
    resimg = si.show_imgs(filter_imgs, "cv2.filter2D", 3)
    resimg = si.show_imgs(blur_imgs, "cv2.blur", 3)

# 좀 더 부드러운 블러
def gaussian():
    image = cv2.imread(IMG_PATH + "/yumi-cells.jpg")
    kernel_size = (5, 5)
    blur_imgs = {}
    blur_imgs["original"] = image
    blur_imgs["blur"] = cv2.blur(image, kernel_size)
    blur_imgs["GaussianBlur"] = cv2.GaussianBlur(image, kernel_size, 0)
    result_img = si.show_imgs(blur_imgs, "GaussianBlur", 3, 1000)


def median():
    image = cv2.imread(IMG_PATH + "/ann.jpg")
    median_imgs = dict()
    median_imgs["original"] = image
    median_imgs["median (3)"] = cv2.medianBlur(image, 3)
    median_imgs["median (5)"] = cv2.medianBlur(image, 5)
    result_img = si.show_imgs(median_imgs, "Median Filter", 3)


def bilateral():
    image = cv2.imread(IMG_PATH + "/road.jpg")
    kernel_size = (5, 5)
    blur_imgs = {}
    blur_imgs["original"] = image
    blur_imgs["gaussian"] = cv2.GaussianBlur(image, kernel_size, 0)
    blur_imgs["bilateral (5,50,50)"] = cv2.bilateralFilter(image, 5, 50, 50)
    blur_imgs["bilateral (5,150,150)"] = cv2.bilateralFilter(image, 5, 150, 150)
    result_img = si.show_imgs(blur_imgs, "Bilateral Filter", 2)


def sobel():
    # 커널에 대각선 성분이 없기 때문에 엣지가 더 얇게 나온다
    image = cv2.imread(IMG_PATH + "/yumi-cells.jpg", cv2.IMREAD_GRAYSCALE)
    sobel_imgs = {"original" : image}
    sobel_imgs["Sobel dx"] = cv2.Sobel(image, ddepth=-1, dx=1, dy=0,ksize=3)
    sobel_imgs["Sobel dy"] = cv2.Sobel(image, ddepth=-1, dx=0, dy=1,ksize=3)
    sobel_imgs["Sobel dx+dy"] = cv2.add(sobel_imgs["Sobel dx"], sobel_imgs["Sobel dy"])
    # 샤르 엣지 : 소벨 엣지에서 엣지 방향의 정확도를 개선한 필터
    sobel_imgs["Scharr dx"] = cv2.Scharr(image, ddepth=-1, dx=1, dy=0)
    sobel_imgs["Scharr dy"] = cv2.Scharr(image, ddepth=-1, dx=0, dy=1)
    result_img = si.show_imgs(sobel_imgs, "Sobel & Scharr", 3)


def laplacian():
    image = cv2.imread(IMG_PATH + "/yumi-cells.jpg", cv2.IMREAD_GRAYSCALE)
    lapla_imgs = {"original": image}
    sobel_dx = cv2.Sobel(image, ddepth=-1, dx=1, dy=0, ksize=3)
    sobel_dy = cv2.Sobel(image, ddepth=-1, dx=0, dy=1, ksize=3)
    lapla_imgs["Sobel dx+dy"] = cv2.add(sobel_dx, sobel_dy)
    lapla_imgs["Laplacian"] = cv2.Laplacian(image, -1)
    result_img = si.show_imgs(lapla_imgs, "Laplacian", 3)

def canny():
    # 끊어지지않는 윤곽선을 제공
    # 가장 많이 쓰이는 필터
    image = cv2.imread(IMG_PATH + "/arya.jpg", cv2.IMREAD_GRAYSCALE)
    canny_imgs = {"original": image}
    canny_imgs["Laplacian"] = cv2.Laplacian(image, -1, scale=2)
    canny_imgs["Canny (100, 200)"] = cv2.Canny(image, 100, 200)
    canny_imgs["Canny (200, 255)"] = cv2.Canny(image, 150, 255)
    result_img = si.show_imgs(canny_imgs, "Canny", 2)


def erode_and_dilate():
    srcimg = cv2.imread(IMG_PATH + "/marvel.jpg", cv2.IMREAD_GRAYSCALE)
    srcimg = salt_and_pepper_noise(srcimg)
    # erode and dilate, and then show them
    images = {"original": srcimg}
    # 구조화 요소
    kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (3, 3))
    # 침식
    images["erode"] = cv2.erode(srcimg, kernel)
    # 팽창
    images["dilate"] = cv2.dilate(srcimg, kernel)
    result_img = si.show_imgs(images, "Erode and Dilate", 1)


def morphologies():
    srcimg = cv2.imread(IMG_PATH + "/marvel.jpg", cv2.IMREAD_GRAYSCALE)
    srcimg = salt_and_pepper_noise(srcimg)
    # erode and dilate, and then show them
    images = {"original": srcimg}
    kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (3, 3))
    images["opening"] = cv2.morphologyEx(srcimg, cv2.MORPH_OPEN, kernel)
    images["closing"] = cv2.morphologyEx(srcimg, cv2.MORPH_CLOSE, kernel)
    # 엣지 구하기
    images["gradient"] = cv2.morphologyEx(srcimg, cv2.MORPH_GRADIENT, kernel)
    # 이 두개는 교수님도 잘 모르심
    images["tophat"] = cv2.morphologyEx(srcimg, cv2.MORPH_TOPHAT, kernel)
    images["blackhat"] = cv2.morphologyEx(srcimg, cv2.MORPH_BLACKHAT, kernel)
    result_img = si.show_imgs(images, "Morphology Ops", 2)


def salt_and_pepper_noise(image): # 노이즈 추가
    towhite = np.unravel_index(np.random.randint(0, image.size, 100), image.shape)
    toblack = np.unravel_index(np.random.randint(0, image.size, 100), image.shape)
    image[towhite] = 255
    image[toblack] = 0
    return image


if __name__ == "__main__":
    # blur()
    # gaussian()
    # median()
    # bilateral()
    # sobel()
    # laplacian()
    # canny()
    erode_and_dilate()
    morphologies()