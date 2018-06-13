#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

void trackBarChanged(int value, void *param)
{
	value = value - 128;
	Mat* _image = (Mat *)param;
	Mat resImage;
	_image->convertTo(resImage, _image->type(), 1.0, (double)value);
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

	Mat resImage;
	image.convertTo(resImage, image.type(),1.0, (double)initialValue);


	imshow("MyImage", resImage);
	createTrackbar("MyTrackbar", "MyImage", &initialValue, 255, trackBarChanged, &resImage);
	waitKey(0);
	return 0;

}