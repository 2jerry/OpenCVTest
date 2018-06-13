/* 원하는 색만 출력하기 */

#include <opencv2\opencv.hpp>
#include <iostream>
#define SCALE 0.2
using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		cout << "Provide image name to read" << endl;
		return -1;
	}

	Mat inputImg;

	inputImg = imread(argv[1], IMREAD_UNCHANGED);
	//resize(inputImg, inputImg, Size(), SCALE, SCALE, CV_INTER_AREA);
	if (inputImg.empty())
	{
		cout << "Unable to open file" << endl;
		return 0;
	}

	Mat cannyImg;
	cvtColor(inputImg, inputImg, COLOR_BGR2GRAY);
	Canny(inputImg, cannyImg, 100, 200);
	
	imshow("Original", inputImg);
	imshow("onOffImg", cannyImg);

	waitKey(0);
	return 0;
}