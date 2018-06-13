#include "ImageProcess.hpp"

ImageProcess::ImageProcess(Mat& _frame,Size _videoSize)
{
	imgSize = _videoSize;
}


// �̹��� ó���� ���� ������ (ROI(Region Of Interesting) ����)
void ImageProcess::ROI2Binary(Mat &_image, Point _xy, Size _size, int _mode)
{
	Mat imageROI = _image(Rect(_xy, _size)); // ROI
	if (_mode == 0)
		threshold(imageROI, imageROI, 0, 0, THRESH_BINARY);
	else
		adaptiveThreshold(imageROI, imageROI, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 11, 9.0);
		
}

void ImageProcess::startProcessing(Mat& _frame)
{
	// ������ �׷���
	
	ROI2Binary(_frame, Point(0, imgSize.height / 2.2), Size(imgSize.width, imgSize.height / 2.2), 1); // ���ɿ��� ���� (����)
	ROI2Binary(_frame, Point(0, 0), Size(imgSize.width, imgSize.height / 2.2), 0);  // ���ɿ��� ���� (�ϴ�)
	ROI2Binary(_frame, Point(0, 0), Size(imgSize.width / 2.8, imgSize.height), 0);  // ���ɿ��� ���� (�ϴ�)
	ROI2Binary(_frame, Point(0, imgSize.height / 1.3), Size(imgSize.width, imgSize.height - imgSize.height / 1.3), 0); // ���ɿ��� ���� (�ڵ���)
	
	Mat morphImg;
	//morphologyEx(_frame, _frame, MORPH_TOPHAT, Mat(9, 9, CV_8U));
	morphologyEx(_frame, _frame, MORPH_BLACKHAT, Mat(9, 9, CV_8U));
}