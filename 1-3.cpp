//#include <opencv2/opencv.hpp>
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
//int main(int argc, char** argv)
//{
//	if (argc != 2)
//	{
//		cout << "Provide image name to read" << endl;
//		return -1;
//	}
//
//	Mat inputImg;
//
//	inputImg = imread(argv[1], IMREAD_UNCHANGED);
//
//	if (inputImg.empty())
//	{
//		cout << "Unable to open file" << endl;
//		return 0;
//	}
//
//	Mat grayOne;
//	cvtColor(inputImg, grayOne, COLOR_BGR2GRAY); // 이미지 색 바꾸기
//	//							 BGR->GRAY 로 
//	imshow("Original", grayOne);
//
//	waitKey(0); // 2초 있다가 꺼짐
//	return 0;
//}