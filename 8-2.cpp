#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;

#define RHO (double) 1
#define THETA CV_PI / 180
//
//void draw_houghLines(Mat src, Mat& dst, vector<Vec2f> lines, int nline)
//{
//	cvtColor(src, dst, CV_GRAY2BGR);
//	for (int i = 0; i < min((int)lines.size(), nline); i++)
//	{
//		float rho = lines[i][0];
//		float theta = lines[i][1];
//		double a = cos(theta);
//		double b = sin(theta);
//
//		Point2d pt(a*rho, b*rho);
//		Point2d delta(1000 * -b, 1000 * a);
//		line(dst, pt + delta, pt - delta, Scalar(0, 255, 0), 1, LINE_AA);
//	}
//}

void draw_houghLines(Mat src, Mat& dst, vector<Vec2f> lines, int nline)
{
	
}
void trackBarChanged(int value, void *param)
{
	Mat* _canny = (Mat *)param;
	Mat res;
	HoughLines(*_canny, res, RHO, THETA, value);
	imshow("hough", res);
}



int main(int argc, char *argv[])
{
	Mat img = imread(argv[1], IMREAD_UNCHANGED);

	if (img.empty() == true)
	{
		cout << "Unable to read image" << endl;
		return -1;
	}


	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);

	Mat canny, dst;
	GaussianBlur(gray, canny, Size(5, 5), 2, 2);
	Canny(canny, canny, 100, 150, 3); // canny¿§Áö¿¡¼­ Èò»öÀÎ ¾Öµé¸¸ 
	
	vector<Point> pixel;

	for (int i = 0; i < canny.size().height; i++)
	{
		for (int j = 0; j < canny.size().width; j++)
		{

			uchar white_pixel = canny.at<uchar>(i, j);

			if (white_pixel > 0)
			{
				pixel.push_back(Point(i, j));
			}
		}
	}


	int threshold_value = 5;
	vector<Vec2f> lines;
	HoughLines(canny, lines, RHO, THETA, threshold_value);

	cvtColor(canny, dst, CV_GRAY2BGR);
	for (int i = 0; i <min((int)lines.size(),1000); i++)
	{
		float rho = lines[i][0];
		float theta = lines[i][1];
		double a = cos(theta);
		double b = sin(theta);

		Point p = pixel[i];
	
		if (abs((float)p.y * a + (float)p.x*b - rho) <100)
		{
			dst.at<Vec3b>(p.x, p.y)[0] = 0;
			dst.at<Vec3b>(p.x, p.y)[1] = 0;
			dst.at<Vec3b>(p.x, p.y)[2] = 255;
		}
		
	}
	imshow("original", img);
	imshow("canny", canny);
	imshow("hough", dst);

	createTrackbar("MyTrackbar", "MyImage", &threshold_value, 100, trackBarChanged, &canny);


	waitKey(0);
	return 0;
}