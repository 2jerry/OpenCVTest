#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

void onMouse(int event, int x, int y, int flag, void *userdata);

int main(void)
{
	Mat image(200, 300, CV_8U);
	image.setTo(255);

	imshow("MouseEvent1", image);
	setMouseCallback("MouseEvent1", onMouse, 0);
	waitKey(0);
}

void onMouse(int event, int x, int y, int flags, void *param)
{
	switch (event)
	{
	case EVENT_LBUTTONDOWN:
		cout << "Left Button Click at ("<<x<<", "<<y<<")" << endl;
		break;
	case EVENT_RBUTTONDOWN:
		cout << "Right Button Click at (" << x<<", "<<y<<")"<<endl;
		break;
	default:
		break;
	}
}
