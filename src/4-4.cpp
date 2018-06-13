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
	if (inputImg.empty())
	{
		cout << "Unable to open file" << endl;
		return 0;
	}

	vector<Mat> bgr_images(3);
	split(inputImg, bgr_images);

#define FROM 0
#define TO 1
	
	Mat temp;
	temp = bgr_images[FROM];
	bgr_images[FROM] = bgr_images[TO];
	bgr_images[TO] = temp;

	Mat switchedImg;
	merge(bgr_images, switchedImg);

	imshow("Original", inputImg);
	imshow("Switched", switchedImg);

	waitKey(0);
	return 0;
}