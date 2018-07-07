#include<graphics.h>
#include<dos.h>
#include<conio.h>
void circularbox(int x,int y,char *string,int color,int size)
{
       settextstyle(1, 0, size);
	setcolor(8);
	ellipse(x,y,0,360,textwidth(string)/2+20,textheight(string)/2+20);
	ellipse(x,y,0,360,textwidth(string)/2+18,textheight(string)/2+18);
	setfillstyle(1,color);
	fillellipse(x,y,textwidth(string)/2+18,textheight(string)/2+18);

	setcolor(0);
	outtextxy(x-(textwidth(string)/2),y-((textheight(string)*2)/3), string);


}

void rectbox(int x, int y, char *string,int color,int size )
{
	int x1,y1,x2,y2;
	int pts[8];
	settextstyle(1, 0, size);
	pts[0]=x1=(x-(textwidth(string)/2)-20);
	pts[1]=y1=(y-textheight(string)/2-10);
	pts[2]=(x+(textwidth(string)/2)+20);
	pts[3]=(y-textheight(string)/2-10);
	pts[4]=x2=(x+(textwidth(string)/2+20));
	pts[5]=y2=(y+textheight(string)/2+10);
	pts[6]=(x-(textwidth(string)/2)-20);
	pts[7]=(y+textheight(string)/2+10);


	setcolor(8);
	rectangle(x1,y1 ,x2,y2 );
	rectangle(x1+1,y1+1,x2-1,y2-1);
	setfillstyle(1,color);
	fillpoly(4,pts);
	setcolor(0);

	outtextxy(x-(textwidth(string)/2),y-((textheight(string)*2)/3), string);

}

void popup_message(char *string,int color)
{
	int x1,y1,x2,y2;
	char *s[10];
	settextstyle(1, 0, 1);
	x1=(getmaxx()/2-(textwidth(string)/2)-40);
	y1=(getmaxy()/2-textheight(string)/2-20);
	x2=(getmaxx()/2+(textwidth(string)/2+40));
	y2=(getmaxy()/2+textheight(string)/2+20);
	setcolor(8);
	rectangle(x1-1,y1-1 ,x2+1,y2+1 );
	rectangle(x1,y1 ,x2,y2 );
	rectangle(x1+1,y1+1,x2-1,y2-1);
	setfillstyle(1,color);
	floodfill(x1+3, y1+3,8);
	setcolor(0);

	outtextxy(getmaxx()/2-(textwidth(string)/2),getmaxy()/2-((textheight(string)*2)/3), string);

	getch();

}
