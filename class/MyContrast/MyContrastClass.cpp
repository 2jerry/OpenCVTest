#include "MyContrastClass.hpp"



MyContrastClass::MyContrastClass(Mat* _image)
{
	image = _image;
}



Mat& MyContrastClass::getContrastedImage(int _value)
{
	int var_contrast = _value - 100;
	double a, b;

	if (var_contrast > 0)
	{
		double delta = 127.0*var_contrast / 100.0;
		a = 255.0 / (255 - delta * 2);
		b = a * (-delta);
	}
	else
	{
		double delta = -128.0*var_contrast / 100.0;
		a = (256.0 - delta * 2.0) / 255.0;
		b = delta;
	}

	image->convertTo(resImage,image->type(), a, b);

	return resImage;

}