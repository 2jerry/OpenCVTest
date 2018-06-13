#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		cout << "Provide image name to read" << endl;
		return -1;
	}

	Mat inputImg;

	inputImg = imread(argv[1], IMREAD_UNCHANGED);

	Mat hlsOne;
	cvtColor(inputImg, hlsOne, COLOR_BGR2HLS);

	for (int row = 0; row < hlsOne.size().height; row++)
	{
		for (int col = 0; col < hlsOne.size().width; col++)
		{
			uchar H = hlsOne.at<Vec3b>(row, col)[0];
			uchar L = hlsOne.at<Vec3b>(row, col)[1];
			uchar S = hlsOne.at<Vec3b>(row, col)[2];

			double LS_ratio = ((double)L) / ((double)S);
			bool skin_pixel = (S >= 50) && (LS_ratio > 0.5) && (LS_ratio < 3.0) && ((H <= 14) || (H >= 165));

			if (skin_pixel == false)
			{
				hlsOne.at<Vec3b>(row, col) = Vec3b(0, 0, 0);
			}
		}
	}
	Mat rgbImg;
	cvtColor(hlsOne, rgbImg, COLOR_HLS2BGR);

	imshow("Original", rgbImg);

	waitKey(0);
	return 0;
}