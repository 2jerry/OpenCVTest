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
		Mat gray_frame;
		Mat binary_frame;
		Mat cannyImg;
		
		//	
		
		cap >> frame;
		cvtColor(frame, gray_frame, COLOR_BGR2GRAY);
		//threshold(gray_frame, binary_frame, 128, 255, THRESH_BINARY); // binary ¿ÃπÃ¡ˆ
		Canny(gray_frame, cannyImg, 100, 200);

		if (cannyImg.empty())
			break;

		imshow("Frame", cannyImg);
		char c = (char)waitKey(1);
		if (c == 27)
			break;
	}

	cap.release();

	destroyAllWindows();
}