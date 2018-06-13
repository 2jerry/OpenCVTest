#include <opencv2\opencv.hpp>
#include <iostream>
#define SCALE 1.0
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
	//threshold(grayImg, binImg, 128, 255, THRESH_BINARY);
	threshold(grayImg, binImg, 128, 255, THRESH_OTSU);
	//adaptiveThreshold(grayImg, binImg, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY,23, 3.0);
	
	imshow("Original", dispImg);
	imshow("Gray", grayImg);
	imshow("Binary", binImg);

	waitKey(0);
	return 0;

}