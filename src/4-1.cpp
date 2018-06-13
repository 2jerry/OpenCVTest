#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
	VideoCapture cap(argv[1]);
	if (!cap.isOpened())
	{
		cout << "Error opening video stream or file" << endl;
		return -1;
	}

	while (1)
	{
		Mat frame;
		cap >> frame;

		if (frame.empty())
			break;

		imshow("Frame", frame);
		char c = (char)waitKey(1);
		if (c == 27)
			break;
	}

	cap.release();

	destroyAllWindows();
}