#include <opencv2\opencv.hpp>
#define WIN_NAME "MouseEvent1"

using namespace cv;
using namespace std;


void onMouse(int event, int x, int y, int flag, void *userdata);

int main(void)
{
	Mat image = Mat(200, 300, CV_8UC3);
	image.setTo(Scalar(255, 255, 255));

	imshow(WIN_NAME, image);
	setMouseCallback(WIN_NAME, onMouse, &image);
	waitKey(0);
}

void onMouse(int event, int x, int y, int flags, void *param)
{
	Mat *_img = (Mat *)param;
	switch (event)
	{
	case EVENT_LBUTTONDOWN:
		cout << "Left Button Click at (" << x << ", " << y << ")" << endl;
		circle(*_img, Point(x, y), 10, Scalar(0, 0, 255), -1);
		imshow(WIN_NAME, *_img);
		break;
	case EVENT_RBUTTONDOWN:
		cout << "Right Button Click at (" << x << ", " << y << ")" << endl;
		break;
	default:
		break;
	}
}
