#include "MouseDetection.h"

MouseDetection::MouseDetection(string _fname)
{
	img = imread(_fname, IMREAD_UNCHANGED);
	resize(img, img, Size(), 0.2, 0.2);
	if (img.empty())
	{
		cout << "file load error" << endl;
		return ;
	}
	
	imshow(WIN_NAME, img);

	setMouseCallback(WIN_NAME, onMouse, this);
	
	waitKey(0);
}

Mat MouseDetection::SetRoi(Mat &_img,Point _start,Point _end)
{
	Rect r = Rect(_start.x, _start.y, _end.x - _start.x, _end.y - _start.y);
	cout << _start.x << ", " << _start.y << endl;
	return _img(r);
}

Mat MouseDetection::imageProcessing(Mat &_img,int _mode)
{
	Mat gray,tmp,result;
	switch (_mode)
	{
	case BIN:
		cvtColor(_img, gray, COLOR_BGR2GRAY);
		threshold(gray, tmp, 127, 255, THRESH_OTSU);
		cvtColor(tmp, result, COLOR_GRAY2BGR);
		break;
	case CANNY:
		cvtColor(_img, gray, COLOR_BGR2GRAY);
		Canny(gray, tmp, 100, 200, 3);
		cvtColor(tmp, result, COLOR_GRAY2BGR);
		break;
	default:
		break;
	}
	return result;
}

void MouseDetection::onMouse(int event, int x, int y, int flags, void *userdata)
{
	MouseDetection *m = (MouseDetection *)userdata;
	m->onMouse(event, x, y);
}

void MouseDetection::onMouse(int event, int x, int y)
{
	Rect r;
	Mat roi;
	switch (event)
	{
	case EVENT_LBUTTONDOWN:
		cout << "Left Button Click at (" << x << ", " << y << ")" << endl;
		start_xy = Point(x, y);
		break;

	case EVENT_LBUTTONUP:
		cout << "Left Button Click at end(" << x << ", " << y << ")" << endl;
		end_xy = Point(x, y);

		roi = Mat(SetRoi(img, start_xy, end_xy));
		imageProcessing(roi, CANNY).copyTo(roi);

		imshow(WIN_NAME, img);

		break;

	case EVENT_RBUTTONDOWN:
		cout << "Left Button Click at (" << x << ", " << y << ")" << endl;
		start_xy = Point(x, y);
		break;

	case EVENT_RBUTTONUP:
		cout << "Left Button Click at end(" << x << ", " << y << ")" << endl;
		end_xy = Point(x, y);

		roi = Mat(SetRoi(img, start_xy, end_xy));
		imageProcessing(roi, BIN).copyTo(roi);

		imshow(WIN_NAME, img);
		break;

	default:
		break;
	}

}