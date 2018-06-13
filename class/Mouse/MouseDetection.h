#pragma once
#include <opencv2\opencv.hpp>

#define WIN_NAME "image"
#define RED Scalar(0,0,255)
#define GREEN Scalar(0,255,0)
#define BLUE Scalar(255,0,0)

#define BIN 1
#define CANNY 2


using namespace std;
using namespace cv;

class MouseDetection
{
private:
	Mat img;
	Point start_xy, end_xy;

public:
	MouseDetection() {};
	~MouseDetection() {};
	MouseDetection(string fname);
	Mat SetRoi(Mat &_img, Point _start, Point _end);
	Mat imageProcessing(Mat&, int _mode);
	void onMouse(int event, int x, int y);
	static void onMouse(int event, int x, int y, int flags, void *userdata);
};

