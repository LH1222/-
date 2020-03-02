#include <iostream>
#include <conio.h>
#include <stdlib.h> 
#include <windows.h>
#include <cstdlib>
#include "point.h"
#include "point.cpp"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int high,width;
int score; 
int isFired=0;

point bullet;			//子弹 
point plane;			//飞机 
point enemy;			//敌机 

void gotoxy(int x,int y){			//光标移动到xy位置 
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(handle,pos);
}
 
void startup(){	          //初始化 
	high=18;
	width=30;
	score=0;
	plane.set_x(high/2);
	plane.set_y(width/2);
	
	bullet.set_x(-1);
	bullet.set_y(width/2);
	
	enemy.set_x(0);
	enemy.set_y(width/2);
}

void show(){
	gotoxy(0,0);
	if(score<0){
		cout<<"游戏结束";
		exit(0); 		//用于结束进程 
	}
	int i,j;
	

	for(i=0;i<=high;i++){
		for(j=0;j<=width;j++){
			if(i==plane.get_x()&&j==plane.get_y())	cout<<"*";
			else if(i==bullet.get_x()&&j==bullet.get_y())	cout<<"|";			//子弹 
			else if(i==enemy.get_x()&&j==enemy.get_y())	cout<<"@";	
			else if(j==width)	cout<<"|";
			else if(i==high)	cout<<"_";	
			else cout<<" ";	
		}
		cout<<endl;
	}
	cout<<"得分："<<score;
}

void updateWithoutInput(){
	if(bullet.get_x()==enemy.get_x()&&bullet.get_y()==enemy.get_y()){
		score++;
		enemy.set_x(0);
		enemy.set_y(rand()%width);
		bullet.set_x(-1);
	}	
	if(bullet.get_x()>-1)	bullet.change_x(-1);
	if(enemy.get_x()==plane.get_x()&&enemy.get_y()==plane.get_y()){
		score-=10;
	}
	static int speed=0;
	{
		if(speed<10)	speed++;			//敌机下落速度控制 
		if(speed==10){
			if(enemy.get_x()>high){
			enemy.set_x(0);
			enemy.set_y(rand()%width);
			}else	enemy.change_x(1);
			speed=0;
		}
		
	}
	
}


void updateWithInput(){
	char input;
	if(kbhit()){
		input=getch();
		if(input=='s'&&plane.get_x()<high-1)	plane.change_x(1);
		if(input=='w'&&plane.get_x()>0)	plane.change_x(-1);		//控制边界及移动 
		if(input=='a'&&plane.get_y()>0)	plane.change_y(-1);
		if(input=='d'&&plane.get_y()<width-1)	plane.change_y(1);
		if(input==' '){
			bullet.set_x(plane.get_x());
			bullet.set_y(plane.get_y());
		}
	}
}	



int main(int argc, char** argv) {
	
	startup();
	while(1){
		show();					//显示画面 
		updateWithoutInput();	//与用户无关的更新 
		updateWithInput();		//输入有关更新 
	}
	return 0;
}
