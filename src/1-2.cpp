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
//	Mat resizeOne; // 새로 변경할 꺼
//	resize(inputImg, resizeOne, Size(), 0.5,0.5);
//	//	   넣을이미지, 새로변경할애, 비어있는 사이즈, 세로,가로
//
//	imshow("Original", resizeOne);
//
//	waitKey(2000); // 2초 있다가 꺼짐
//	return 0;
//}