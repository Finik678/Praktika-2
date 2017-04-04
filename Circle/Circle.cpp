#include "Circle.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std; // ������������� ������������ ���

Circle::Circle(double radius)
	{
		set_the_radius(radius);
	}

void Circle::set_the_radius(double radius)
	{
		�->radius = radius; // ����� �������� �� ���������, �������� ������� radius
		�->ference = 2*(M_PI)*radius; 
		 �->area = M_PI*pow(radius, 2);
		//cout << radius << "," << ference << "," << area << endl;
	}

void Circle::set_the_ference(double ference)
	{
		�->ference = ference;
		�->radius = ference/(2*M_PI);
		�->area = 2*pow(radius, 2);
		//cout << radius << ",   " << ference << ",   " << area << endl;
	}

void Circle::set_the_area(double area)
	{
		�->area = area;
		�->radius = sqrt(area*M_PI);
		 �->ference = 2*M_PI*radius;
		//cout << radius << "," << ference << "," << area << endl;
	}

double Circle::get_radius()
	{
		return radius;
	}

double Circle::get_area()
	{
		return area;
	}

double Circle::get_ference()
	{
		return ference;
	}

	Circle::Circle()
	{
		set_the_radius(0);
}
