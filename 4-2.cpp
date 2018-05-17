//#include <opencv2\opencv.hpp>
//#include <iostream>
//
//using namespace std;
//using namespace cv;
//
//int main(int argc, char **argv)
//{
//	VideoCapture cap(argv[1]);
//	if (!cap.isOpened())
//	{
//		cout << "Error opening video stream or file" << endl;
//		return -1;
//	}
//
//	while (1)
//	{
//		Mat frame;
//		Mat gray_frame;
//		Mat binary_frame;
//
//		
//		cap >> frame;
//		cvtColor(frame, gray_frame, COLOR_BGR2GRAY);
//		threshold(gray_frame, binary_frame, 128, 255, THRESH_BINARY); // binary ¿ÃπÃ¡ˆ
//
//
//		if (binary_frame.empty())
//			break;
//
//		imshow("Frame", binary_frame);
//		char c = (char)waitKey(1);
//		if (c == 27)
//			break;
//	}
//
//	cap.release();
//
//	destroyAllWindows();
//}