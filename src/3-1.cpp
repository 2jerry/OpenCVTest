//#include <opencv2/opencv.hpp>
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
//#define SCALE 0.5
//
//int main(int argc, char ** argv)
//{
//	if (argc != 2)
//	{
//		cout << " Provide image name to read" << endl;
//		return -1;
//	}
//
//	Mat inputImg, dispImg, disp2Img;
//	Mat hlsImg;
//
//	inputImg = imread(argv[1], IMREAD_COLOR);
//
//	if (inputImg.data == 0)
//	{
//		cout << "Unable to read " << argv[1] << endl;
//		return 0;
//	}
//
//	resize(inputImg, dispImg, Size(), SCALE, SCALE, CV_INTER_AREA);
//
//	cvtColor(dispImg, hlsImg, COLOR_BGR2HLS);
//
//	vector<Mat> channels(hlsImg.channels());
//	split(hlsImg, channels);
//	equalizeHist(channels[1], channels[1]);
//	merge(channels, hlsImg);
//	cvtColor(hlsImg, disp2Img, COLOR_HLS2BGR);
//
//	imshow("Original", dispImg);
//	imshow("After luminacense equalization",disp2Img);
//
//	waitKey(0);
//	return 0;
//}