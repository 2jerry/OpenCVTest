//#include "MyOpenCV.hpp"
//
//int main(int argc, char *argv[])
//{
//	if (argc < 2)
//		cout << "Image file name is missing" << endl;
//	
//	MyOpenCV *m = new MyOpenCV(argv[1]);
//	Mat input = m->getResizedImg(0.2);
//
//	m->drawRect(input);
//
//	imshow("Result", input);
//
//	waitKey(0);
//}
////
////#include "MyCV.hpp"
////int main(int argc, char *argv[])
////{
////	if (argc < 2)
////		cout << "Image file name is missing" << endl;
////	
////	MyCV *m = new MyCV(argv[1]);
////
////	imshow("Result", m->getEdgeDetectedImage());
////
////	waitKey(0);
////}
