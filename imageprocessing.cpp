#include<opencv2/opencv.hpp>

using namespace cv;

int main()
{
	// Load the image
	Mat imgOriginal = imread("./image/c30c97416dcf2ce17a92b5d0545fb2a4.png", 1);

	//show the original image
	String pzOriginalImage = "Original Image";
	namedWindow(pzOriginalImage,WINDOW_NORMAL);
	imshow(pzOriginalImage, imgOriginal);

	String pzRotatedImage = "Rotated Image";
	namedWindow(pzRotatedImage, WINDOW_NORMAL);

	int iAngle = 180;
	createTrackbar("Angle", pzRotatedImage, &iAngle, 540);

	int iImageHieght = imgOriginal.rows / 2;
	int iImageWidth = imgOriginal.cols / 2;

	while (1)
	{
		Mat matRotation = getRotationMatrix2D(Point(iImageWidth, iImageHieght), (iAngle - 180), 1);

		// Rotate the image
		Mat imgRotated;
		warpAffine(imgOriginal, imgRotated, matRotation, imgOriginal.size());

		imshow(pzRotatedImage, imgRotated);

		int iRet = waitKey(10);
		if (iRet == 7)
		{
			break;
		}
	}
	destroyWindow(pzOriginalImage);
	destroyWindow(pzRotatedImage);
	return 0;
}
