#include <opencv2\opencv.hpp>
#define WIN_NAME "MouseEvent1"

using namespace cv;
using namespace std;


void onMouse(int event, int x, int y, int flag, void *userdata);

int main(int argc,char **argv)
{
	Mat image;
	image = imread(argv[1], IMREAD_UNCHANGED);

	imshow(WIN_NAME, image);
	setMouseCallback(WIN_NAME, onMouse, &image);
	waitKey(0);
}

void onMouse(int event, int x, int y, int flags, void *param)
{
	Mat *_img = (Mat *)param;
	Vec3b bgr = 0;

	switch (event)
	{
	case EVENT_LBUTTONDOWN:
		cout << "\nLeft Button Click at (" << x << ", " << y << ")" << endl;
		bgr = _img->at<Vec3b>(y, x);
		cout << "BGR value is " << bgr << endl;
		cout << "BLUE value is " << (int)bgr[0] << endl;
		cout << "GREEN value is " << (int)bgr[1] << endl;
		cout << "RED value is " << (int)bgr[2] << endl;
		break;
	case EVENT_RBUTTONDOWN:
		cout << "Right Button Click at (" << x << ", " << y << ")" << endl;
		break;
	default:
		break;
	}
}
