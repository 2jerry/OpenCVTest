//#include "MyCV.hpp"
//
//int main(int argc, char *argv[])
//{
//	if (argc < 2)
//	{
//		cout << "Image file name is missing" << endl;
//	}
//
//	MyCV* m = new MyCV(argv[1]);
//	Mat salt = m->getImage().clone();
//	m->addSaltAndPepperNoise(salt, 0.05);
//
//	imshow("Canny", m->getEdgedDetectedImage());
//	imshow("salt", salt);
//
//	waitKey(0);
//}