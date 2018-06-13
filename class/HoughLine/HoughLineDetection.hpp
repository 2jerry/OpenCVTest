#pragma once
#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;

#define RHO (double) 1
#define THETA CV_PI / 180


class HoughLineDetection
{
private:
	Mat *image;
	Mat resImage;
	vector<Vec2f>lines;

public:
	HoughLineDetection(Mat* _img);
	HoughLineDetection() {}
	~HoughLineDetection() {}

	Mat& edgeDetection();
	Mat& changeHoughPixels(Mat _input, int _nline);
	void findWhitePixel(vector<Point>& _pixel, Mat _img);

};