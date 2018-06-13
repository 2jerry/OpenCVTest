#pragma once
#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;

#define RHO (double) 1
#define THETA CV_PI / 180


class HoughLineDetection
{
private:
	

public:
	HoughLineDetection(Mat& _img,string _fname);
	HoughLineDetection() {}
	~HoughLineDetection() {}
	Mat image2binary(Mat _inputImg);
	vector<Vec2f> findHoughLines(Mat _inputImg,int value);
	void drawHoughLines(Mat _input, Mat& _output, vector<Vec2f>lines, int nline);
};