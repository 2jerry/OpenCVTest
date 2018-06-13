#include "HoughLineDetection_line.hpp"

HoughLineDetection::HoughLineDetection(Mat& _img,string _fname)
{
	_img = imread(_fname, IMREAD_UNCHANGED);

	if (_img.empty() == true)
	{
		cout << "Unable read to image" << endl;
		return;
	}
}

Mat HoughLineDetection::image2binary(Mat inputImg) // 그레이 이미지만 넣어야함
{
	Mat grayImg,resImg;
	cvtColor(inputImg, grayImg,COLOR_BGR2GRAY);
	GaussianBlur(grayImg, resImg,Size(5,5),2,2);
	Canny(resImg, resImg, 100, 150, 3);

	return resImg;
}

vector<Vec2f> HoughLineDetection::findHoughLines(Mat inputImg,int value)
{
	vector<Vec2f>lines;
	Mat res;
	HoughLines(inputImg, lines, RHO, THETA, value);

	return lines;
}

void HoughLineDetection::drawHoughLines(Mat _input, Mat& _output, vector<Vec2f>lines, int nline)
{
	cvtColor(_input, _output, COLOR_GRAY2BGR);
	for (int i = 0; i < min((int)lines.size(), nline); i++)
	{
		float rho = lines[i][0];
		float theta = lines[i][1];
		double a = cos(theta);
		double b = sin(theta);

		Point2d pt(a*rho, b*rho);
		Point2d delta(1000 * -b, 1000 * a);
		line(_output, pt + delta, pt - delta, Scalar(0, 255, 0), 1, LINE_AA);
	}
}



