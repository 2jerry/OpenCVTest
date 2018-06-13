#pragma once
#include "ImageProcess.hpp"

#define GRAY 0
#define COLOR 1
#define VIDEO 2
#define IMAGE 3

class BlackBox 
{
private:
	Mat frame;
	VideoCapture cap;
	Size videoSize;
	ImageProcess *p;

public:
	BlackBox(string fname, int _format);
	BlackBox() { /* �⺻ ������ */ }
	~BlackBox() { /* �Ҹ��� */ }

	void drawRect(Mat& _frame, Size _xy, Size _size);
	void playVideo(int _mode);
	bool numberDetect(Size* _point);
	Size* findRectPoint(vector<Point> _poly);
	void detectRectangle(Mat& _frame);
};
