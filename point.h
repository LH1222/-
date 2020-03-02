#ifndef POINT_H
#define POINT_H

class point
{
	public:
		point();
		virtual ~point();
		int get_x(){
			return point_x;
		};
		int get_y(){
			return point_y;
		};
		set_x(int x);
		set_y(int y);
		change_x(int x);
		change_y(int y);
	protected:
		int point_x;		//飞机位置 
		int point_y;
};

#endif
