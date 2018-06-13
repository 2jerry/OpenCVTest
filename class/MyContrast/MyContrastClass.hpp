#pragma once
#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;


class MyContrastClass
{
private:
	Mat *image;
	Mat resImage;

public:
	MyContrastClass(Mat* _image);
	MyContrastClass() {}
	~MyContrastClass() {}
	Mat& getContrastedImage(int _value);
};


