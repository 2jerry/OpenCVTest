#include "MyOpenCV.hpp"



MyOpenCV::MyOpenCV(string _fname)
{
	origin = imread(_fname, IMREAD_UNCHANGED);

}

Mat& MyOpenCV::getResizedImg(float _size)
{
	resize(origin, processing,Size(), _size, _size);

	return processing;
}
