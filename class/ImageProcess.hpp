#pragma once
#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

class ImageProcess 
{
private:
	Size imgSize;
public:
	ImageProcess(Mat& _frame, Size _imgSize);
	ImageProcess() { /* �⺻ ������ */ }
	~ImageProcess() { /* �Ҹ��� */ } 
	void ROI2Binary(Mat& _image, Point _xy, Size _size, int _mode);
	void startProcessing(Mat& _frame);

};

