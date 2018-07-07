#include<graphics.h>
#include<dos.h>
#include<conio.h>
#include"mainmenu.cpp"
#include<fstream.h>


void mainmenu();

class questionsheet
{

      question q[30];
      int size;



public:
questionsheet(){size=0;}

	 void getquestions()
	  {
		  char choice = 'y';
		  int i = 0;
		  fstream f;
		  f.open("questionsheet",ios::out|ios::binary|ios::in|ios::ate);
		  while (choice == 'y' || choice == 'Y')
		  {
			  getquizinterface(&q[i]);
			  f.write((char*)&q[i],sizeof(q[i]));
			  i++;
			  size++;
			  cleardevice();
			  popup_message("do you enter more question (Y/N):",8);
			  cin >> choice;
		  }

	      f.close();
	  }


int print_question()
{    int choice;
int marks=0;


for (int i=0;i<size;i++)
{
choice=quizinterface(&q[i]);
if (choice == 1)
		{

			marks++;
		}
		else
		{

			marks--;
		}

}
/*
fstream f;
f.open("questionsheet",ios::out|ios::binary|ios::in|ios::ate);
question ques;
	while (!f.eof())
	{
		f.read((char*)&ques, sizeof(ques));
		choice=quizinterface(ques);

		if (choice == 1)
		{

			marks++;
		}
		else
		{

			marks--;
		}
	}

		f.close();
		*/
		return marks;
	}

};
questionsheet q;

class student
		{

			int score;
			char feedbacks[500];
			int size;
		public:

		student()
		{
		  score=0;
		  size=3;
		 displaymenu();
		}
		void displaymenu()
		{
		char *menus[30]={"take the test","give the feedback","XXXXXX"};

		int choice;
			do {
				choice =menu("STUDENT",menus,size);
				if (choice == 1)
				{
					taketest();
					::mainmenu();
				}
				else if (choice == 2)
				{
					feedback();
					::mainmenu();
				}

			}while(choice!=1||choice!=2);
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




			void taketest()
			{

			  score=q.print_question();
			  char ch=48+score;
			  char chr[2]=" \0";
			  chr[0]=ch;
			  cleardevice();
			  popup_message("your score in quiz is    :",8);
			  outtextxy(getmaxx()/2+textheight("your score in quiz is  :")/2,getmaxy()/2,chr);
			  getch();

			 }

			 void feedback()
			 { char ch;
			 cleardevice();
			 setbkcolor(WHITE);
			 int maxx=getmaxx();
			 setcolor(8);
			  rectangle(0+40,20,getmaxx()-40,50);
			   settextstyle(0,0,3);
			    outtextxy(maxx/2-90,22,"feed back");
			     rectbox(maxx/2,80," ",RED,3);
			      ch=getch();

			 strcpy(feedbacks," ");
			 char chr[2]=" \0";
			  ch=getch();
			  int i=0;
			  while(ch!='\n'||ch!='\r')
			  { if(ch=='\n'||ch=='\r')
			  {::mainmenu();}
			   chr[0]=ch;

			  strcat(feedbacks,chr);
			   rectbox(maxx/2,80+i*textheight(feedbacks),feedbacks,RED,3);
			   ch=getch();}





	     }

};

class teacher
		{


			int score ;
			char feedbacks[500];
			int size ;
		public:
		 teacher()
		 {

		       score=0;
		       size=3;
		       displaymenu();
		       }

		       void displaymenu()
		 {
		   char *menus[30]={"prepare the test","give the feedback","XXXXXX"};

		 int choice=0;
		 do{
		    choice=menu("TEACHER",menus,size);
		    if(choice==1)
		    {prepare_test();
		    ::mainmenu();}
		    else if(choice==2)
		    {feedback();
		    ::mainmenu();
		    }

		 } while (choice != 1 || choice != 2);
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





			void prepare_test()
			{

			  q.getquestions();

			 }

			 void feedback()
			 { char ch;
			 cleardevice();
			 int maxx=getmaxx();
			 setbkcolor(WHITE);
			 setcolor(8);
			  rectangle(0+40,20,maxx-40,50);
			   settextstyle(0,0,3);
			    outtextxy(maxx/2-90,22,"feed back");
			     rectbox(maxx/2,80," ",RED,3);
			      ch=getch();


			 char chr[2]=" \0";
			  ch=getch();
			  int i=0;
			  strcpy(feedbacks," ");
			  while(ch!='\n'||ch!='\r')
			  { if(ch=='\n'||ch=='\r')
			  {::mainmenu();

			  }
			   chr[0]=ch;

			  strcat(feedbacks,chr);
			   rectbox(maxx/2,80+i*textheight(feedbacks),feedbacks,RED,3);
			   ch=getch();}




	     }

};

class HOD
		{

			int score ;
			char feedbacks[500];
			int size;
		public:
		 HOD()
		 {


		       score=0;
		       size=3;
		       displaymenu();
		  }


		 void displaymenu()
		 {
		 char *menus[30]={"prepare the test","give the feedback","XXXXXX"};

		 int choice =0;
		 do{
		 choice=menu("HOD",menus,size);
		 if(choice==1)
		    {prepare_test();
		    ::mainmenu();}
		    else if(choice==2)
		    {feedback();
		    ::mainmenu();
		    }

		 } while (choice != 1 || choice != 2) ;
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






			void prepare_test()
			{

			  q.getquestions();

			 }

			 void feedback()
			 { char ch;
			 cleardevice();
			 int maxx=getmaxx();
			 setbkcolor(WHITE);
			 setcolor(8);
			  rectangle(0+40,20,maxx-40,50);
			   settextstyle(0,0,3);
			    outtextxy(maxx/2-90,22,"feed back");
			     rectbox(maxx/2,80," ",RED,3);
			      ch=getch();

			  strcpy(feedbacks," ");
			 char chr[2]=" \0";
			  ch=getch();
			  int i=0;
			  while(ch!='\n'||ch!='\r')
			  {  if(ch=='\n'||ch=='\r')
			  {::mainmenu();}

			   chr[0]=ch;

			  strcat(feedbacks,chr);
			   rectbox(maxx/2,80+i*textheight(feedbacks),feedbacks,RED,3);
			   ch=getch();}




	     }

} ;
class admin
		{

			int score;
			char feedbacks[500];
			int size;
		public:
		 admin()
		 {

		       score=0;
		       size=3;

		       displaymenu();
		 }

		 void displaymenu()
		 {
		 char *menus[30]={"prepare the test","give the feedback","take the test"};
		 int choice =0;
		 do{
		 choice=menu("ADMIN",menus,size);
		 if(choice==1)
		    {prepare_test();
		    ::mainmenu();}
		    else if(choice==2)
		    {feedback();
		    ::mainmenu();
		    }
			else if (choice == 3)
			{
				taketest();
				::mainmenu();
			}


		 }while (choice != 1 || choice != 2||choice!=3);
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





			void prepare_test()
			{

			  q.getquestions();

			 }

				void taketest()
			{

			  score=q.print_question();
			  char ch=48+score;
			  char chr[2]=" \0";
			  chr[0]=ch;
			  cleardevice();
			  popup_message("your score in quiz is    :",8);
			  outtextxy(getmaxx()/2+textheight("your score in quiz is  :")/2,getmaxy()/2,chr);
			  getch();
			 }

			 void feedback()
			 { char ch;
			 cleardevice();
			 int maxx=getmaxx();
			 setbkcolor(WHITE);
			 setcolor(8);
			  rectangle(0+40,20,maxx-40,50);
			   settextstyle(0,0,3);
			    outtextxy(maxx/2-90,22,"feed back");
			     rectbox(maxx/2,80," ",RED,3);
			      ch=getch();

			  strcpy(feedbacks," ");
			 char chr[2]=" \0";
			  ch=getch();
			  int i=0;
			  while(ch!='\n'||ch!='\r')
			  {
			    if(ch=='\n'||ch=='\r')
			    {::mainmenu();}
			   chr[0]=ch;

			   strcat(feedbacks,chr);
			   rectbox(maxx/2,80+i*textheight(feedbacks),feedbacks,RED,3);
			   ch=getch();}




	     }

};