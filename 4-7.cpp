///* 원하는 색만 출력하기 */
//
//#include <opencv2\opencv.hpp>
//#include <iostream>
//#define SCALE 0.2
//using namespace std;
//using namespace cv;
//
//int main(int argc, char **argv)
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
//	//resize(inputImg, inputImg, Size(), SCALE, SCALE, CV_INTER_AREA);
//	if (inputImg.empty())
//	{
//		cout << "Unable to open file" << endl;
//		return 0;
//	}
//
//	vector<Mat> bgr_images(3);
//	split(inputImg, bgr_images);
//
//	
//	Mat gImg;
//	bgr_images[0] = bgr_images[2].clone(); // deep copy
//	bgr_images[1] = bgr_images[2].clone();
//	merge(bgr_images, gImg);
//	
//	for (int i = 0; i < inputImg.size().height; i++)
//	{
//		for (int j = 0; j < inputImg.size().width; j++)
//		{
//			uchar B = inputImg.at<Vec3b>(i, j)[0];
//			uchar G = inputImg.at<Vec3b>(i, j)[1];
//			uchar R = inputImg.at<Vec3b>(i, j)[2];
//
//			if (B < 80 && G <80&& R>80)
//			{
//				gImg.at<Vec3b>(i, j)[0] = B;
//				gImg.at<Vec3b>(i, j)[1] = G;
//				gImg.at<Vec3b>(i, j)[2] = R;
//
//			}
//		}
//	}
//
//
//	imshow("Original", inputImg);
//	imshow("onOffImg", gImg);
//
//	waitKey(0);
//	return 0;
//}