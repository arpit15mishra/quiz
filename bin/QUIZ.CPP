#include"interface.cpp"
#include<fstream.h>
#include<stdlib.h>



	int menu(char **menu,int);
	void mainmenu()
	{
		int i = 0;
		int choice;
		while (1)
		{
			cleardevice();

			char *menu[30] = { "1-student","2-teacher","3-HOD","4-administration","5-exit" };
			choice =::menu("student",menu, 5);
			switch (choice)
			{
			case 1:
			{


				       student s;


			}
			break;
			case 2:
			{ teacher t;}
			break;
			case 3:
			{

				       HOD h;

			}
			break;
			case 4:
			{

					admin a;

			}
			break;
			case 5:exit(0);
			break;

			default:popup_message("please enter a valid choice...", 8);
			}
		}
	}



void main()
{
      int GDriver = DETECT; int Gmode;
      initgraph(&GDriver, &Gmode, "C:\\TURBOC3\\BGI");
//introduction();
mainmenu();
end();
}


