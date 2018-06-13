#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

void trackBarChanged(int value, void *param)
{
	Mat* _grayImage = (Mat *)param;
	Mat resImage;
	threshold(*_grayImage, resImage, value, 255, CV_THRESH_BINARY);
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

	Mat grayImage;
	cvtColor(image, grayImage, COLOR_BGR2GRAY);

	int initialValue = 100;

	Mat binImage;
	threshold(grayImage, binImage, initialValue, 255, CV_THRESH_BINARY);

	
	imshow("MyImage", binImage);
	createTrackbar("MyTrackbar", "MyImage", &initialValue, 200, trackBarChanged,&grayImage);
	waitKey(0);
	return 0;

}