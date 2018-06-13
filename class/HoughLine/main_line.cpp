#include "HoughLineDetection_line.hpp"

void trackBarChanged(int value, void *param)
{
	Mat *_canny = (Mat *)param;
	Mat dst;

	HoughLineDetection hld;
	hld.drawHoughLines(*_canny, dst, hld.findHoughLines(*_canny, value), 10);
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
	resize(image, image, Size(), 0.3, 0.3);

	if (image.empty() == true)
	{
		cout << "Unable to read image" << endl;
		return -1;
	}
	Mat image;
	HoughLineDetection *hld = new HoughLineDetection(image,argv[1]);

	Mat canny = hld->image2binary(image);

	int threshold_value = 100;
	Mat result;
	hld->drawHoughLines(canny, result, hld->findHoughLines(canny, threshold_value), 10);

	imshow("result", result);

	createTrackbar("MyTrackbar", "result", &threshold_value, 300, trackBarChanged, &canny);

	waitKey(0);

	return 0;
}