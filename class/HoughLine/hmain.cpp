#include "HoughLineDetection.hpp"
//
void trackBarChanged(int value, void *param)
{
	Mat dst,canny;
	HoughLineDetection *hld = new HoughLineDetection((Mat *)param);
	dst = hld->changeHoughPixels(hld->edgeDetection(),value);

	//hld.drawHoughLines(*_canny, dst, hld.findHoughLines(*_canny, value), 10);
	imshow("result", dst);
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		cout << "No image name" << endl;
		return -1;
	}

	Mat image = imread(argv[1], IMREAD_UNCHANGED);

	if (image.empty() == true)
	{
		cout << "Unable to read image" << endl;
		return -1;
	}
	
	int threshold_value = 50;
	imshow("result", image);
	createTrackbar("MyTrackbar", "result", &threshold_value,200, trackBarChanged, &image);

	waitKey(0);

	return 0;
}