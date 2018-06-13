#pragma once
#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

class MyOpenCV
{
private:
	Mat origin;
	Mat processing;

public:
	MyOpenCV() {}
	MyOpenCV(string _fname);
	~MyOpenCV() {}
	Mat&  getResizedImg(float _size);
};

