#include <opencv2\opencv.hpp>
#define WIN_NAME "MouseEvent1"
#define NEW_WIN "ROI"

using namespace cv;
using namespace std;


void onMouse(int event, int x, int y, int flag, void *userdata);

int main(int argc, char **argv)
{
	Mat image;
	image = imread(argv[1], IMREAD_UNCHANGED);

	imshow(WIN_NAME, image);
	setMouseCallback(WIN_NAME, onMouse, &image);
	waitKey(0);
}

void onMouse(int event, int x, int y, int flags, void *param)
{
	Mat _img = *(Mat *)param;
	Mat ROI;

	switch (event)
	{
	case EVENT_LBUTTONDOWN:
		cout << "\nLeft Button Click at (" << x << ", " << y << ")" << endl;
		break;
	case EVENT_RBUTTONDOWN:
		cout << "Right Button Click at (" << x << ", " << y << ")" << endl;
		break;
	case EVENT_LBUTTONUP:
		cout << "\nLeft Button Click up (" << x << ", " << y << ")" << endl;
		break;
	//case EVENT_MOUSEMOVE:
		//cout << "\nLeft Button Move (" << x << ", " << y << ")" << endl;
	default:
		break;
	}
}
