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
//	Mat resizeOne; // ���� ������ ��
//	resize(inputImg, resizeOne, Size(), 0.5,0.5);
//	//	   �����̹���, ���κ����Ҿ�, ����ִ� ������, ����,����
//
//	imshow("Original", resizeOne);
//
//	waitKey(2000); // 2�� �ִٰ� ����
//	return 0;
//}