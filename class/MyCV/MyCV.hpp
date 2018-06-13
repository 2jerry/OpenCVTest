#pragma once
#include "MyOpenCV.hpp"

class MyCV : public MyOpenCV
{
private:
	MyOpenCV * my;
public:
	MyCV(string _fname);
	MyCV() {}
	~MyCV() {}

	Mat& getEdgedDetectedImage();
	Mat& getImage();
	void addSaltAndPepperNoise(Mat& a, double _size);
};

