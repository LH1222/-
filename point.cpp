#include "point.h"

point::point()
{
}

point::~point()
{
}

point::set_x(int x){
	point_x=x;
}

point::set_y(int y){
	point_y=y;
}

point::change_x(int x){
	point_x+=x;
	
}

point::change_y(int y){
	point_y+=y;
	
}
