#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

void trackBarChanged(int value, void *)
{
	cout << "trackbar value is " << value << endl;
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

	imshow("MyImage", image);
	createTrackbar("MyTrackbar", "MyImage", &initialValue, 200, trackBarChanged);
	waitKey(0);
	return 0;

}