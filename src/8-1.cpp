#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;

#define RHO (double) 1
#define THETA CV_PI / 180

void draw_houghLines(Mat src, Mat& dst, vector<Vec2f> lines, int nline)
{
	cvtColor(src, dst, CV_GRAY2BGR);
	for (int i = 0; i < min((int)lines.size(), nline); i++)
	{
		float rho = lines[i][0];
		float theta = lines[i][1];
		double a = cos(theta);
		double b = sin(theta);

		Point2d pt(a*rho, b*rho);
		Point2d delta(1000 * -b, 1000 * a);
		line(dst, pt + delta, pt - delta, Scalar(0, 255, 0), 1, LINE_AA);
	}
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
	Canny(canny, canny, 100, 150, 3);

	int threshold_value = 10;
	vector<Vec2f> lines;
	HoughLines(canny, lines, RHO, THETA, threshold_value);
	draw_houghLines(canny, dst, lines, 10);

	imshow("original", img);
	imshow("canny", canny);
	imshow("hough", dst);

	createTrackbar("MyTrackbar","MyImage", &threshold_value, 100, trackBarChanged, &canny);


	waitKey(0);
	return 0;
}