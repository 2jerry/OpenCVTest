#include <opencv2\opencv.hpp>
#include <iostream>
#define SCALE 0.1
using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		cout << "Provide image name to read" << endl;
		return -1;
	}

	Mat inputImg, dispImg;
	Mat grayImg, binImg;

	inputImg = imread(argv[1], IMREAD_COLOR);

	if (inputImg.data == 0)
	{
		cout << "Unable to read" << argv[1] << endl;
		return 0;
	}

	resize(inputImg, dispImg, Size(), SCALE, SCALE, CV_INTER_AREA);

	cvtColor(dispImg, grayImg, COLOR_BGR2GRAY);

	threshold(grayImg, binImg, 128, 255, THRESH_BINARY);

	Mat dilatedImg, erodedImg, openedImg,closedImg;
	Mat kernel(3, 3, CV_8U);
	dilate(binImg, dilatedImg, kernel);
	erode(binImg, erodedImg, kernel);
	morphologyEx(binImg, openedImg, MORPH_OPEN, kernel);
	morphologyEx(binImg, closedImg, MORPH_CLOSE, kernel);

	
	imshow("Binary", binImg);
	imshow("Dilated", dilatedImg);
	imshow("Eroded", erodedImg);
	imshow("Opended", openedImg);
	imshow("Closed", closedImg);

	waitKey(0);
	return 0;

}