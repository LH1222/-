#include <iostream>
#include <conio.h>
#include <stdlib.h> 
#include <windows.h>
#include <cstdlib>
#define Max 100

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int high,width;
int score; 
int bird_x,bird_y;		//С��λ�� 
int bar_y,bar_xTop,bar_xDown;			//ǽλ�� 





void gotoxy(int x,int y){			//����ƶ���xyλ�� 
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(handle,pos);
}
void HideCursor(){
	CONSOLE_CURSOR_INFO cursor_info={1,0};		//�ڶ���ֵΪ0��ʾ���� 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
} 
 
void startup(){	          //��ʼ�� 
	high=18;
	width=25;
	score=0;
	bird_x=high/2;
	bird_y=width/4;
	bar_y=width;
	bar_xTop=width/4;
	bar_xDown=width/2;	
	HideCursor();

}

void show(){
	gotoxy(0,0);
	if(score<0){
		cout<<"��Ϸ����";
		exit(0); 		//���ڽ������� 
	}
	int i,j;
	

	for(i=0;i<=high;i++){
		for(j=0;j<=width;j++){
			if(i==bird_x&&j==bird_y)	cout<<"@";
			else if(j==bar_y&&(i<=bar_xTop||i>=bar_xDown) )	cout<<"*";
			else if(j==width)	cout<<"|";		//�ұ߽� 
			else if(i==high+1)	cout<<"_";		//�±߽� 
			else cout<<" ";	
		}
		cout<<endl;
	}
	cout<<"�÷֣�"<<score;
}

void updateWithoutInput(){
	if(bird_y==bar_y){
		if(bird_x>bar_xTop&&bird_x<bar_xDown)	score++;
		else exit(0);
	}
	if(bird_x<=high)	bird_x++;
	else exit(0);
	if(bar_y>0)	bar_y--;
	else{
		bar_y=width;
		int randomPosition=rand()%(high-5);
		bar_xTop=randomPosition;
		bar_xDown=randomPosition+high/4;
	}
	Sleep(150); 
}


void updateWithInput(){
	char input;
	if(kbhit()){
		input=getch();

		if(input==' '&&bird_x>0){
			bird_x-=2;
		}	
	
	}
}	



int main(int argc, char** argv) {
	
	startup();
	while(1){
		show();					//��ʾ���� 
		updateWithoutInput();	//���û��޹صĸ��� 
		updateWithInput();		//�����йظ��� 
	}
	return 0;
}
