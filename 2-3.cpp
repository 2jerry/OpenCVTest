//#include <opencv2/opencv.hpp>
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
//void addSaltAndPepperNoise(Mat& img, double noise_ratio)
//{
//	int rows = img.rows;
//	int cols = img.cols;
//	int ch = img.channels();
//	int num_of_noise_pixels = (int)((double)(rows*cols*ch)*noise_ratio);
//
//	for (int i = 0; i < num_of_noise_pixels; i++)
//	{
//		int r = rand() % rows;
//		int c = rand() % cols;
//		int _ch = rand() % ch;
//
//		uchar* pixel = img.ptr<uchar>(r) + (c*ch) + _ch;
//
//		*pixel = (rand() % 2 == 1) ? 255 : 0;
//	}
//}
//
//int main(int agrc,char ** argv)
//{
//	Mat inputImg;
//	Mat spImg;
//
//	inputImg = imread(argv[1], IMREAD_UNCHANGED);
//	resize(inputImg, inputImg, Size(), 0.25, 0.25, CV_INTER_AREA);
//	
//	spImg = inputImg.clone();
//	addSaltAndPepperNoise(spImg, 0.05);
//	
//	Mat localAvgImg;
//	blur(spImg, localAvgImg, Size(5, 5));
//
//	Mat gaussianSmoothedImg;
//	GaussianBlur(spImg, gaussianSmoothedImg, Size(5, 5), 1.5);
//
//	Mat medianFilteredImg;
//	medianBlur(spImg, medianFilteredImg,11);
//
//	imshow("Original", inputImg);
//	imshow("SaltAndPepper", spImg);
//	imshow("LocalAveraging", localAvgImg);
//	imshow("gaussianSmoothing", gaussianSmoothedImg);
//	imshow("medianFiltered", medianFilteredImg);
//
//
//
//	waitKey(0);
//	return 0;
//}