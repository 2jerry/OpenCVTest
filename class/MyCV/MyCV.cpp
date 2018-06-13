#include "MyCV.hpp"

MyCV::MyCV(string _fname)
{
	my = new MyOpenCV(_fname);
}

Mat& MyCV::getEdgedDetectedImage()
{
	Mat &resize = my->getResizedImg(0.5);
	cvtColor(resize, resize, COLOR_BGR2GRAY);
	Canny(resize, resize, 100, 200, 3);

	return resize;
}

Mat& MyCV::getImage()
{
	Mat &resize = my->getResizedImg(0.5);

	return resize;
}

void MyCV::addSaltAndPepperNoise(Mat &img, double noise_ratio)
{
	int rows = img.rows;
	int cols = img.cols;
	int ch = img.channels();
	int num_of_noise_pixels = (int)((double)(rows*cols*ch)*noise_ratio);

	for (int i = 0; i < num_of_noise_pixels; i++)
	{
		int r = rand() % rows;
		int c = rand() % cols;
		int _ch = rand() % ch;

		uchar* pixel = img.ptr<uchar>(r) + (c*ch) + _ch;

		*pixel = (rand() % 2 == 1) ? 255 : 0;
	}
}