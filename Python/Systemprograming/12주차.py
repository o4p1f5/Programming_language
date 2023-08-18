import cv2
import numpy as np
import show_imgs as si
IMG_PATH = "C:/Systemprograming/sample_imgs"


def hough_lines():
    img_names = [IMG_PATH + f"/bookshelf{i+1}.jpg" for i in range(3)]
    images = {}
    for i, name in enumerate(img_names):
        img = cv2.imread(name, cv2.IMREAD_COLOR)
        srcimg = cv2.resize(img, (200, 200))
        images[f"srcimg{i+1}"] = srcimg

        grayimg = cv2.cvtColor(srcimg, cv2.COLOR_BGR2GRAY)
        blurimg = cv2.GaussianBlur(grayimg, (3, 3), 0)
        cannyimg = cv2.Canny(blurimg, 100, 200)
        images[f"canny{i+1}"] = cannyimg

        lines = cv2.HoughLinesP(cannyimg, 1, np.pi/180, 50, None, 50, 10)
        print("lines", lines)
        result = images[f"srcimg{i+1}"].copy()
        for line in lines:
            x1, y1, x2, y2 = line[0]
            cv2.line(result, (x1, y1), (x2, y2), (0, 0, 255), 1)
        images[f"houghline{i+1}"] = result

    result_img = si.show_imgs(images, "hough lines", 3, 1200)

def hough_circles():
    img_names = [IMG_PATH + f"/mole{i+1}.jpg" for i in range(3)]
    images = {}
    for i, name in enumerate(img_names):
        img = cv2.imread(name, cv2.IMREAD_COLOR)
        srcimg = cv2.resize(img, (200, 200))
        images[f"srcimg{i+1}"] = srcimg

        gray = cv2.cvtColor(srcimg, cv2.COLOR_BGR2GRAY)
        gray = cv2.GaussianBlur(gray, (3, 3), 0)
        gray = cv2.GaussianBlur(gray, (3, 3), 0)

        cannyimg = cv2.Canny(gray, 100, 200)
        images[f"canny{i+1}"] = cannyimg

        circles = cv2.HoughCircles(gray, cv2.HOUGH_GRADIENT, 1, 30, None,
                                   param1=200, param2=50, maxRadius=60)
        circles = np.around(circles).astype(np.uint16)
        circles = circles[0]
        print("circles\n", circles)
        result = srcimg.copy()
        for circle in circles:
            result = cv2.circle(result, (circle[0], circle[1]), circle[2], (0,0,255), 2)
        images[f"houghline{i+1}"] = result

    result_img = si.show_imgs(images, "hough circles", 3, 1200)

def fill_lake():
    img = cv2.imread(IMG_PATH + "/sinjeong-lake.jpg", cv2.IMREAD_COLOR)
    srcimg = cv2.resize(img, (200, 200))
    images = {"original" : srcimg}
    seed = (int(srcimg.shape[1]/2), int(srcimg.shape[0]/2))

    fill_direct = srcimg.copy()
    mask = np.zeros((srcimg.shape[0]+2, srcimg.shape[1]+2), dtype=np.uint8)
    retval, fill_direct, mask, rect = \
        cv2.floodFill(fill_direct, mask, seed, newVal=(0,255,255),
                      loDiff=(2,2,2), upDiff=(2,2,2), flags=8)
    print(f"pixel area of lake WITHOUT preprocess={retval}, rect={rect}")
    fill_direct = cv2.circle(fill_direct, seed, 1, (0,0,255), 1)
    images["direct_floodfill"] = fill_direct

    fill_blur = srcimg.copy()
    fill_blur = cv2.GaussianBlur(fill_blur, (3,3), 0)
    fill_blur = cv2.medianBlur(fill_blur, 3)
    mask = np.zeros((srcimg.shape[0]+2, srcimg.shape[1]+2), dtype=np.uint8)
    retval, fill_direct, mask, rect = \
        cv2.floodFill(fill_blur, mask, seed, newVal=(0, 255, 255),
                      loDiff=(2, 2, 2), upDiff=(2, 2, 2), flags=8 | (255 << 8))
    print(f"pixel area of lake WITH preprocess={retval}, rect={rect}")
    fill_blur = cv2.circle(fill_blur, seed, 1, (0, 0, 255), 1)
    images["blur_n_floodfill"] = fill_blur

    images["final mask"] = cv2.cvtColor(mask[1:-1,1:-1], cv2.COLOR_GRAY2BGR)
    result_img = si.show_imgs(images, "fill the lake", 2)

def count_puzzle():
    img = cv2.imread(IMG_PATH + "/puzzle.jpg")
    ih, iw, ch = img.shape
    mask = np.zeros((ih+2, iw+2), dtype=np.uint8)
    images = {"original" : img.copy()}
    cv2.imshow("image", img)
    cv2.waitKey()
    count = 0
    for y in range(0, img.shape[0], 5):
        for x in range(0, img.shape[1], 5):
            if mask[y+1, x+1] == 0:
                color = np.random.randint(20,256,3).tolist()
                ret, img, mask, rect = cv2.floodFill(img, mask, (x,y), color,
                                                     loDiff=(10,10,10), upDiff=(10,10,10), flags=8)
                mask_show = mask*255
                print(f"area={ret}, rect={rect}, mask value={mask[y+1, x+1]}")
                if ret > 500:
                    cv2.imshow("image", img)
                    cv2.imshow("mask", mask_show)
                    cv2.waitKey(100)
                    count += 1
    print("total puzzle count:", count)
    cv2.destroyAllWindows()
    images["filled"] = img
    result_img = si.show_imgs(images, "floodfill", 2)
    cv2.imwrite(IMG_PATH + "/floodfill_puzzle.jpg", result_img)


if __name__ == "__main__":
    # hough_lines()
    # hough_circles()
    # fill_lake()
    count_puzzle()