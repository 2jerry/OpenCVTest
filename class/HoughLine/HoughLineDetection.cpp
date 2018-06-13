#include "HoughLineDetection.hpp"

HoughLineDetection::HoughLineDetection(Mat* _img)
{
	image = _img;
}

Mat& HoughLineDetection::edgeDetection() // 그레이 이미지만 넣어야함
{
	cvtColor(*image, resImage,COLOR_BGR2GRAY);
	GaussianBlur(resImage, resImage,Size(5,5),2,2);
	Canny(resImage, resImage, 100, 150, 3);

	return resImage;
}
void HoughLineDetection::findWhitePixel(vector<Point>& _pixel, Mat _img)
{
	for (int i = 0; i < _img.size().height; i++)
	{
		for (int j = 0; j < _img.size().width; j++)
		{

			uchar white_pixel = _img.at<uchar>(i, j);

			if (white_pixel > 0)
			{
				_pixel.push_back(Point(i, j));
			}
		}
	}
}

Mat& HoughLineDetection::changeHoughPixels(Mat _input,int nlines)
{
	vector<Vec2f>lines;
	HoughLines(_input, lines, RHO, THETA, 5);

	vector<Point> pixel;
	findWhitePixel(pixel, _input); // 흰색 픽셀 찾기

	cvtColor(_input, resImage, COLOR_GRAY2BGR); // 컬러이미지로 변환

	for (int i = 0; i < min((int)lines.size(), 1000); i++)
	{
		float rho = lines[i][0];
		float theta = lines[i][1];
		double a = cos(theta);
		double b = sin(theta);

		Point p = pixel[i];

		if (abs((float)p.y * a + (float)p.x*b - rho) <nlines)
		{
			resImage.at<Vec3b>(p.x, p.y)[0] = 0;
			resImage.at<Vec3b>(p.x, p.y)[1] = 0;
			resImage.at<Vec3b>(p.x, p.y)[2] = 255;
		}
	}

	return resImage;
}



