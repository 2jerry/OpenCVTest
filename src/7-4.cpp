#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

void trackBarChanged(int value, void *param)
{
	Mat* _image = (Mat *)param;
	Mat resImage;

	int var_contrast = value - 100;
	double a, b;

	if (var_contrast > 0)
	{
		double delta = 127.0*var_contrast / 100.0;
		a = 255.0 / (255 - delta * 2);
		b = a* (-delta);
	}
	else
	{
		double delta = -128.0*var_contrast / 100.0;
		a = (256.0 - delta * 2.0) / 255.0;
		b = delta;
	}

	_image->convertTo(resImage, _image->type(), a, b);
	imshow("MyImage", resImage);
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		cout << "No image name" << endl;
		return -1;
	}

	Mat image = imread(argv[1], IMREAD_UNCHANGED);
	resize(image, image, Size(), 0.3, 0.3);

	if (image.empty() == true)
	{
		cout << "Unable to read image" << endl;
		return -1;
	}

	int initialValue = 100;
	Mat gray_image;
	cvtColor(image, gray_image, COLOR_BGR2GRAY);

	imshow("MyImage", gray_image);
	createTrackbar("MyTrackbar", "MyImage", &initialValue, 200, trackBarChanged, &gray_image);
	waitKey(0);
	return 0;

}