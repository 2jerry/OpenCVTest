#include "MyContrastClass.hpp"

void trackBarChanged(int value, void *param)
{
	MyContrastClass *mcc = new MyContrastClass((Mat *)param);
	imshow("MyImage", mcc->getContrastedImage(value));
	delete(mcc);
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		cout << "No image name" << endl;
		return -1;
	}

	Mat image = imread(argv[1], IMREAD_UNCHANGED);
	resize(image, image, Size(), 0.3, 0.3);

	if (image.empty() == true)
	{
		cout << "Unable to read image" << endl;
		return -1;
	}

	int initialValue = 100;

	/*Mat gray_image;
	cvtColor(image, gray_image, COLOR_BGR2GRAY);

	imshow("MyImage", gray_image);
	createTrackbar("MyTrackbar", "MyImage", &initialValue, 200, trackBarChanged, &gray_image);*/
	
	imshow("MyImage", image);
	createTrackbar("MyTrackbar", "MyImage", &initialValue, 200, trackBarChanged, &image);
	waitKey(0);
	return 0;

}