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
//	//bgr_images[2] = Mat::ones(bgr_images[2].size(), bgr_images[2].type())*225.0;
//	//bgr_images[2] = Mat::ones(bgr_images[2].size(), bgr_images[2].type())*225.0;
//	bgr_images[2] = Mat::zeros(bgr_images[0].size(), bgr_images[0].type());
//	bgr_images[0] = Mat::ones(bgr_images[2].size(), bgr_images[2].type())*225.0;
//
//	Mat onOffImg;
//	merge(bgr_images, onOffImg);
//
//	imshow("Original", inputImg);
//	imshow("onOffImg", onOffImg);
//
//	waitKey(0);
//	return 0;
//}