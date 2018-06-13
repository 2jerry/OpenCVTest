#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int agrc,char ** argv)
{
	Mat inputImg;
	Mat hlsImg;

	inputImg = imread(argv[1], IMREAD_UNCHANGED);

	if (inputImg.empty() == true)
	{
		cout << "Unable to open the image" << endl;
		return -1;
	}

	vector<Mat> bgr_images(3);
	split(inputImg, bgr_images);

	imshow("Original", inputImg);
	imshow("B", bgr_images[0]);
	imshow("G", bgr_images[1]);
	imshow("R", bgr_images[2]);

	waitKey(0);
	return 0;
}