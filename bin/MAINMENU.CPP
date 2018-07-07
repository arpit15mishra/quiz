#include<object.h>
#include<conio.h>
#include<iostream.h>
#include<stdio.h>
#include<string.h>

class question
{     public:
      char ques[80];
      char choice[4][20];
      int correct_choice;

      int correctchoice()
      {return correct_choice;}
      question()
      {}
      question(const question &qs)
      {strcpy(ques,qs.ques);
      strcpy(choice[0],qs.choice[0]);
      strcpy(choice[1],qs.choice[1]);
      strcpy(choice[2],qs.choice[2]);
      strcpy(choice[3],qs.choice[3]);

      correct_choice=qs.correct_choice;
      }
};


int introduction()
{
	int choice;
	setbkcolor(3);
	int    midx=getmaxx()/2;
	int    midy=getmaxy()/2;
	for (int i = -100; i<midx - 120; i=i+10)
	{
		cleardevice();
		settextstyle(1, 0, 6);
		setcolor(RED);rectangle(0,midy-120,2*midx,midy+60);
		setfillstyle(1,YELLOW);
		floodfill(3,midy,RED);
		setcolor(1);
		outtextxy(i, midy, "QUIZ APPLICATION");
		outtextxy(midx - i, midy - 90, "WELCOME TO");
		delay(300);
	}
	settextstyle(1,0,1);
	outtextxy(midx + 20, midy + 200, "Press any key to continue.");
	choice=getch();
	return choice;


}

int menu( char *menuname,char **string,int size)
{int choice;
cleardevice();
int maxx=getmaxx();
int maxy=getmaxy();
 setbkcolor(WHITE);
 setcolor(8);
 rectangle(0+40,20,maxx-40,50);
 settextstyle(0,0,3);

 outtextxy(maxx/2-90,22,menuname);

 rectangle(0+40,0+60,maxx-40,maxy-20);
 setfillstyle(1,3);
 floodfill(40+3,60+5,8);

 rectangle(0+120,0+60+3,maxx-120,maxy-20-3);
 setfillstyle(2,6);
 floodfill(40+3,60+5,8);

 for(int i=0;i<size;i++)
 {

 rectbox(getmaxx()/2,(((440-(size+1)*10)/size)*i+(size*10)+60),string[i],i+1,3);

 }
	cin>>choice;
	return choice;

 }
 int quizinterface(question *Question)
 { int choice;
 int maxx=getmaxx();
  cleardevice();
   setbkcolor(WHITE);
 setcolor(8);
 rectangle(0+40,20,maxx-40,50);
 settextstyle(0,0,3);

 outtextxy(maxx/2-90,22,"QUESTION NO:");

 rectbox(maxx/2,80,Question->ques,RED,3);

  for(int i=0;i<2;i++)
 {
   for(int j=0;j<2;j++)
   {
 circularbox((getmaxx()/4)*(i*2+1),((getmaxy()-100)/4)*(j+1)+100,Question->choice[j+i*2],i+2,3);

 }
 }
 cin>>choice;
 cleardevice();
 if(choice==Question->correctchoice())
 {  setcolor(1);
   rectbox(getmaxx()/2,getmaxy()/2,"you entered correct answer",5,3);
   getch();
   return 1;
   }
   else
   {setcolor(1);
   outtextxy(getmaxx()/2,getmaxy()/2,"you entered wrong answer");
   getch();
   return 0;
   }


 }

  void getquizinterface(question *qu)
 { int choice;
 char ch;
 char chr[2]= " \0";
 char string[80]=" ";

 int maxx=getmaxx();
  cleardevice();
   setbkcolor(WHITE);
 setcolor(8);
 rectangle(0+40,20,maxx-40,50);
 settextstyle(0,0,3);
 outtextxy(maxx/2-90,22,"QUESTION NO:");
 rectbox(maxx/2,80,string,RED,3);
 ch=getch();
 while(ch!='\r')
 { chr[0]=ch;
 strcat(string,chr);
 rectbox(maxx/2,80,string,RED,3);
 ch=getch();}
strcpy( qu->ques,string);


  for(int i=0;i<2;i++)
 {
   for(int j=0;j<2;j++)
   { strcpy(string," ");

   circularbox((getmaxx()/4)*(i*2+1),((getmaxy()-100)/4)*(j+1)+100,string,i+1,3);
   ch=getch();
   while(ch!='\r')
   { chr[0]=ch;
    strcat(string,chr);
 circularbox((getmaxx()/4)*(i*2+1),((getmaxy()-100)/4)*(j+1)+100,string,i+1,3);
  ch=getch();
  }
  strcpy(qu->choice[2*i+j],string);

 }
 }
 setcolor(8);
 outtextxy(20,400,"enter the correct choice:");

 ch=getch();
choice=ch-48;
chr[0]=ch;
 outtextxy(20+textwidth("enter the correct choice:")+3,400,chr);
 qu->correct_choice=choice;

getch();
 cleardevice();

 }


 void end()
 {

	setbkcolor(3);
	int    midx=getmaxx()/2;
	int    midy=getmaxy()/2;
	for (int i = -(midx-20); i<0; i=i+10)
	{
		cleardevice();
		settextstyle(1, 0, 6);
		setcolor(RED);rectangle(0,midy-120,2*midx,midy+60);
		setfillstyle(1,YELLOW);
		floodfill(3,midy,RED);
		setcolor(1);

		outtextxy(midx + i, midy - 90, "END");
		delay(300);
	}
	settextstyle(1,0,1);
	outtextxy(midx + 20, midy + 200, "thank you for using the app.");
	getch();


 }



