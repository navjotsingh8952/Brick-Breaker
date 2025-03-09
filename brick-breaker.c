#include<conio.h>
#include<dos.h>
int lefttray=24,life=6,colour1=1,left_dil=15,brick_count=0,left=27,top=23,del=100,offset=0,space,status=1,ball_left=0,ball_top=0,count=2,score=0;
int brick[40]={2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
char ch,chball,speed,close,reset,ball_option,finish_option,welcome_option,level='2';
char line[11]={223,223,223,223,223,223,223,223,223,223,'\0'};
int reflect_boundaries();    //1
int check1();                //2
int check2();                //3
int check3();                //4
int check4();                //5
int brick_reflect();         //6
int score_illusion();        //7
void smile(int left,int top);//8
void level_change();         //9
void exit_inst();            //10
void reset_inst();           //11
void speed_inst();           //12
void line_down(int left,int top, int length); //13
void rectangle(int left, int top, int leftnumber, int topnumber);  //14
void space_rectangle(int left, int top, int leftnumber, int topnumber);//15
void hard_rectangle(int left, int top, int leftnumber, int topnumber,int colour); //16
void soft_rectangle(int left, int top, int leftnumber, int topnumber,int colour); //17
void space_soft_hard_rectangle(int left, int top, int leftnumber, int topnumber); //18
void instruction();         //19
void level_option();        //20
void display1();            //21
void display2();            //22
void display3();            //23
void display4();            //24
void tray();                //25
void ball();                //26
void finish();              //27
void welcome();             //28
main()
{
	_setcursortype(_NOCURSOR);
	clrscr();
	welcome();
	getch();
	clrscr();
	instruction();
	getch();
	clrscr();
	level_option();
	clrscr();
	if(level=='1')display1();
	else if(level=='2')display2();
	else if(level=='3')display3();
	else if(level=='4')display4();

	up: if(ball_option== 32||ball_option==32)
		{
			if(score==0)
			{
				gotoxy(28,18);
				cprintf("                         ");
			}
			ball();
		}
		else if(ball_option=='e'||ball_option=='E')exit_inst();
	else{ ball_option=getch();goto up;   }
	tray();
	goto up;
}
void ball()
{
	while(1)
	{
		if(kbhit())break;
		gotoxy(left,top);
		textcolor(4);
		cprintf("o");
		delay(del);
		gotoxy(left,top);
		cprintf(" ");
		switch(status)
		{
			case 1:
			left++;
			top--;
			break;

			case 2:
			left++;
			top++;
			break;

			case 3:
			left--;
			top--;
			break;

			case 4:
			left--;
			top++;
			break;

		}
		status = reflect_boundaries();
		if(level=='1')status = check1();
		else if(level=='2')status = check2();
		else if(level=='3')status = check3();
		else if(level=='4')status = check4();
	}
}


void tray()
{
	_setcursortype(_NOCURSOR);
	while(1)
	{	if(kbhit())
		{

			chball = getch();
			if(chball == 'e' || chball == 'E')  //exit
			{
				exit_inst();
			}
			else if(chball == 32 )   //play and pause
			{
				textcolor(RED);
				gotoxy(left,top);
				cprintf("o");
				up: chball=getch();
				if(chball == 32)goto down;
				else goto up;
			}
			else if(chball == 'r' || chball == 'R')
			{
				reset_inst();
			}
			else if(chball=='s'||chball=='S')
			{
				speed_inst();
			}
		   /*	else if(chball == 'H' || chball == 'h')
			{
			}/**/
			else if(lefttray>2 && (chball == 'a' || chball == 'A' || chball == 75))
			{
				lefttray--;
				textcolor(WHITE);
				gotoxy(lefttray,24);
				cprintf("%s",line);
				delay(5);
				space = lefttray + 10;

				gotoxy(space,24);
				cprintf(" ");
				goto down;
			}
			else if(lefttray<68 && (chball == 'd' || chball == 'D' || chball == 77))
			{
				lefttray++;
				textcolor(WHITE);
				gotoxy(lefttray,24);
				cprintf("%s",line);
				delay(5);
				space = lefttray - 1 ;
				gotoxy(space,24);
				cprintf(" ");
				goto down;
			}
			else
			{
			  goto down;
			}
		}
	}
   down:
   level_change();
}
void display1()
{
	_setcursortype(_NOCURSOR);
 //	soft_rectangle( 1, 1,78,25, 8);//boundary

	soft_rectangle( 5, 3,14, 4,12);//brick0
	soft_rectangle(15, 3,24, 4,12);//brick1
	soft_rectangle(25, 3,34, 4,12);//brick2
	soft_rectangle(35, 3,44, 4,12);//brick3
	soft_rectangle(45, 3,54, 4,12);//brick4
	soft_rectangle(55, 3,64, 4,12);//brick5
	soft_rectangle(65, 3,74, 4,12);//brick6

	soft_rectangle( 5, 5,14, 6,13);//brick7
	soft_rectangle(15, 5,24, 6,13);//brick8
	soft_rectangle(25, 5,34, 6,13);//brick9
	soft_rectangle(35, 5,44, 6,13);//brick10
	soft_rectangle(45, 5,54, 6,13);//brick11
	soft_rectangle(55, 5,64, 6,13);//brick12
	soft_rectangle(65, 5,74, 6,13);//brick13

	soft_rectangle( 5, 7,14, 8,11);//brick14
	soft_rectangle(15, 7,24, 8,11);//brick15
	soft_rectangle(25, 7,34, 8,11);//brick16
	soft_rectangle(35, 7,44, 8,11);//brick17
	soft_rectangle(45, 7,54, 8,11);//brick18
	soft_rectangle(55, 7,64, 8,11);//brick19
	soft_rectangle(65, 7,74, 8,11);//brick20

	soft_rectangle( 5, 9,14,10,14);//brick21
	soft_rectangle(15, 9,24,10,14);//brick22
	soft_rectangle(25, 9,34,10,14);//brick23
	soft_rectangle(35, 9,44,10,14);//brick24
	soft_rectangle(45, 9,54,10,14);//brick25
	soft_rectangle(55, 9,64,10,14);//brick26
	soft_rectangle(65, 9,74,10,14);//brick27

	soft_rectangle( 5,11,14,12,15);//brick28
	soft_rectangle(15,11,24,12,15);//brick29
	soft_rectangle(25,11,34,12,15);//brick30
	soft_rectangle(35,11,44,12,15);//brick31
	soft_rectangle(45,11,54,12,15);//brick32
	soft_rectangle(55,11,64,12,15);//brick33
	soft_rectangle(65,11,74,12,15);//brick34/* */
	textcolor(RED);
	gotoxy(69,1);
	cprintf("Score: %d",score);

	textcolor(RED);
	if(score==0)
	{
		gotoxy(5,1);
		cprintf("Life:%c%c%c%c%c%c",3,3,3,3,3,3);
		textcolor(LIGHTBLUE);
		gotoxy(28,18);
		cprintf("Press SPACE BAR to start");
	}
	textcolor(RED);
	gotoxy(left,top);
	cprintf("o");
	textcolor(WHITE);
	gotoxy(lefttray,24);
	cprintf("%s",line);
}
void display2()
{
	_setcursortype(_NOCURSOR);
  //	soft_rectangle( 1, 1,78,25, 8);

	hard_rectangle( 5, 3,14, 4, 6);//brick0
	hard_rectangle(15, 3,24, 4, 6);//brick1
	hard_rectangle(25, 3,34, 4, 6);//brick2
	hard_rectangle(35, 3,44, 4, 6);//brick3
	hard_rectangle(45, 3,54, 4, 6);//brick4
	hard_rectangle(55, 3,64, 4, 6);//brick5
	hard_rectangle(65, 3,74, 4, 6);//brick6

	hard_rectangle( 5, 5,14, 6, 6);//brick7
	soft_rectangle(15, 5,24, 6,13);//brick8
	soft_rectangle(25, 5,34, 6,13);//brick9
	soft_rectangle(35, 5,44, 6,13);//brick10
	soft_rectangle(45, 5,54, 6,13);//brick11
	soft_rectangle(55, 5,64, 6,13);//brick12
	hard_rectangle(65, 5,74, 6, 6);//brick13

	hard_rectangle( 5, 7,14, 8, 6);//brick14
	soft_rectangle(15, 7,24, 8,13);//brick15
	soft_rectangle(25, 7,34, 8,13);//brick16
	soft_rectangle(35, 7,44, 8,13);//brick17
	soft_rectangle(45, 7,54, 8,13);//brick18
	soft_rectangle(55, 7,64, 8,13);//brick19
	hard_rectangle(65, 7,74, 8, 6);//brick20

	hard_rectangle( 5, 9,14,10, 6);//brick21
	soft_rectangle(15, 9,24,10,13);//brick22
	soft_rectangle(25, 9,34,10,13);//brick23
	soft_rectangle(35, 9,44,10,13);//brick24
	soft_rectangle(45, 9,54,10,13);//brick25
	soft_rectangle(55, 9,64,10,13);//brick26
	hard_rectangle(65, 9,74,10, 6);//brick27

	hard_rectangle( 5,11,14,12, 6);//brick28
	hard_rectangle(15,11,24,12, 6);//brick29
	hard_rectangle(25,11,34,12, 6);//brick30
	hard_rectangle(35,11,44,12, 6);//brick31
	hard_rectangle(45,11,54,12, 6);//brick32
	hard_rectangle(55,11,64,12, 6);//brick33
	hard_rectangle(65,11,74,12, 6);//brick34/* */
	textcolor(RED);
	gotoxy(69,1);
	cprintf("Score: %d",score);

	textcolor(RED);
	if(score==0)
	{
		gotoxy(5,1);
		cprintf("Life:%c%c%c%c%c%c",3,3,3,3,3,3);
		textcolor(LIGHTBLUE);
		gotoxy(28,18);
		cprintf("Press SPACE BAR to start");
	}
	textcolor(RED);
	gotoxy(left,top);
	cprintf("o");
	textcolor(WHITE);
	gotoxy(lefttray,24);
	cprintf("%s",line);
}
void display3()
{
	_setcursortype(_NOCURSOR);
  ///	soft_rectangle( 1, 1,78,25, 8);

	hard_rectangle(35, 3,44, 4, 6);  //brick0         2
	hard_rectangle(25, 5,34, 6, 6);  //brick1         2
	soft_rectangle(35, 5,44, 6,13);  //brick2         1
	hard_rectangle(45, 5,54, 6, 6);  //brick3         2
	hard_rectangle(15, 7,24, 8, 6);  //brick4         2
	soft_rectangle(25, 7,34, 8,13);  //brick5         1
	hard_rectangle(35, 7,44, 8, 6);  //brick6         2
	soft_rectangle(45, 7,54, 8,13);  //brick7         1
	hard_rectangle(55, 7,64, 8, 6);  //brick8         2
	hard_rectangle( 5, 9,14,10, 6);  //brick9         2
	soft_rectangle(15, 9,24,10,13);  //brick10        1
	hard_rectangle(25, 9,34,10, 6);  //brick11        2
	hard_rectangle(45, 9,54,10, 6);  //brick12        2
	soft_rectangle(55, 9,64,10,13);  //brick13        1
	hard_rectangle(65, 9,74,10, 6);  //brick14        2
	hard_rectangle(15,11,24,12, 6);  //brick15        2
	soft_rectangle(25,11,34,12,13);  //brick16        1
	hard_rectangle(35,11,44,12, 6);  //brick17        2
	soft_rectangle(45,11,54,12,13);  //brick18        1
	hard_rectangle(55,11,64,12, 6);  //brick19        2
	hard_rectangle(25,13,34,14, 6);  //brick20        2
	soft_rectangle(35,13,44,14,13);  //brick21        1
	hard_rectangle(45,13,54,14, 6);  //brick22        2
	hard_rectangle(35,15,44,16, 6);  //brick23        2
	textcolor(RED);
	gotoxy(69,1);
	cprintf("Score: %d",score);

	textcolor(RED);
	if(score==0)
	{
		gotoxy(5,1);
		cprintf("Life:%c%c%c%c%c%c",3,3,3,3,3,3);
		textcolor(LIGHTBLUE);
		gotoxy(28,18);
		cprintf("Press SPACE BAR to start");
	}
	textcolor(RED);
	gotoxy(left,top);
	cprintf("o");
	textcolor(WHITE);
	gotoxy(lefttray,24);
	cprintf("%s",line);
}
void display4()
{
	_setcursortype(_NOCURSOR);
   //	soft_rectangle( 1, 1,78,25, 8);//boundary

	soft_rectangle( 5, 3,14, 4,12);//brick0
	soft_rectangle(15, 3,24, 4,12);//brick1
	soft_rectangle(25, 3,34, 4,12);//brick2
	hard_rectangle(35, 3,44, 4, 3);//brick3
	soft_rectangle(45, 3,54, 4,12);//brick4
	soft_rectangle(55, 3,64, 4,12);//brick5
	soft_rectangle(65, 3,74, 4,12);//brick6

	soft_rectangle( 5, 5,14, 6,15);//brick7
	soft_rectangle(15, 5,24, 6,15);//brick8
	hard_rectangle(25, 5,34, 6, 3);//brick9
	hard_rectangle(45, 5,54, 6, 3);//brick10
	soft_rectangle(55, 5,64, 6,15);//brick11
	soft_rectangle(65, 5,74, 6,15);//brick12

	soft_rectangle( 5, 7,14, 8,15);//brick13
	hard_rectangle(15, 7,24, 8, 3);//brick14
	hard_rectangle(55, 7,64, 8, 3);//brick15
	soft_rectangle(65, 7,74, 8,15);//brick16

	hard_rectangle( 5, 9,14,10, 3);//brick17
	hard_rectangle(65, 9,74,10, 3);//brick18

	soft_rectangle( 5,11,14,12,12);//brick19
	soft_rectangle(15,11,24,12,12);//brick20
	soft_rectangle(25,11,34,12,12);//brick21
	soft_rectangle(35,11,44,12,12);//brick22
	soft_rectangle(45,11,54,12,12);//brick23
	soft_rectangle(55,11,64,12,12);//brick24
	soft_rectangle(65,11,74,12,12);//brick25

	soft_rectangle( 5,13,14,14,7);//brick26
	soft_rectangle(15,13,24,14,7);//brick27
	soft_rectangle(25,13,34,14,7);//brick28
	soft_rectangle(35,13,44,14,7);//brick29
	soft_rectangle(45,13,54,14,7);//brick30
	soft_rectangle(55,13,64,14,7);//brick31
	soft_rectangle(65,13,74,14,7);//brick32
	textcolor(RED);
	gotoxy(69,1);
	cprintf("Score: %d",score);
	textcolor(RED);
	if(score==0)
	{
		gotoxy(5,1);
		cprintf("Life:%c%c%c%c%c%c",3,3,3,3,3,3);
		textcolor(LIGHTBLUE);
		gotoxy(28,18);
		cprintf("Press SPACE BAR to start");
	}
	textcolor(RED);
	gotoxy(left,top);
	cprintf("o");
	textcolor(WHITE);
	gotoxy(lefttray,24);
	cprintf("%s",line);


}



int check1()
{
	if(top==13||top==12||top==11||top==10||top==9||top==8||top == 7 ||top == 6 || top==5 || top == 4 || top == 3 )
	{
		if(top == 3 || top == 4)
		{
			 if(left>= 5 && left<=14 && brick[0]!=1)
			 {
				space_soft_hard_rectangle( 5, 3,14, 4);
				sound(430);
				delay(50);
				nosound();
				brick[0]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=15 && left<=24 && brick[1]!=1)
			 {
				space_soft_hard_rectangle(15, 3,24, 4);
				sound(430);
				delay(50);
				nosound();
				brick[1]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=25 && left<=34 && brick[2]!=1)
			 {
				space_soft_hard_rectangle(25, 3,34, 4);
				sound(430);
				delay(50);
				nosound();
				brick[2]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=35 && left<=44 && brick[3]!=1)
			 {
				space_soft_hard_rectangle(35, 3,44, 4);
				sound(430);
				delay(50);
				nosound();
				brick[3]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=45 && left<=54 && brick[4]!=1)
			 {
				space_soft_hard_rectangle(45, 3,54, 4);
				sound(430);
				delay(50);
				nosound();
				brick[4]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=55 && left<=64 && brick[5]!=1)
			 {
				space_soft_hard_rectangle(55, 3,64, 4);
				sound(430);
				delay(50);
				nosound();
				brick[5]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=65 && left<=74 && brick[6]!=1)
			 {
				space_soft_hard_rectangle(65, 3,74, 4);
				sound(430);
				delay(50);
				nosound();
				brick[6]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		}
		else if(top==5 || top == 6)
		{
			 if(left>= 5 && left<=14 && brick[7]!=1)
			 {
				space_soft_hard_rectangle( 5, 5,14, 6);
				sound(430);
				delay(50);
				nosound();
				brick[7]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=15 && left<=24 && brick[8]!=1)
			 {
				space_soft_hard_rectangle(15, 5,24, 6);
				sound(430);
				delay(50);
				nosound();
				brick[8]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=25 && left<=34 && brick[9]!=1)
			 {
				space_soft_hard_rectangle(25, 5,34, 6);
				sound(430);
				delay(50);
				nosound();
				brick[9]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=35 && left<=44 && brick[10]!=1)
			 {
				space_soft_hard_rectangle(35, 5,44, 6);
				sound(430);
				delay(50);
				nosound();
				brick[10]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=45 && left<=54 && brick[11]!=1)
			 {
				space_soft_hard_rectangle(45, 5,54, 6);
				sound(430);
				delay(50);
				nosound();
				brick[11]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=55 && left<=64 && brick[12]!=1)
			 {
				space_soft_hard_rectangle(55, 5,64, 6);
				sound(430);
				delay(50);
				nosound();
				brick[12]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=65 && left<=74 && brick[13]!=1)
			 {
				space_soft_hard_rectangle(65, 5,74, 6);
				sound(430);
				delay(50);
				nosound();
				brick[13]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		}
		else if(top==7 || top == 8)
		{
			 if(left>= 5 && left<=14 && brick[14]!=1)
			 {
				space_soft_hard_rectangle( 5, 7,14, 8);
				sound(430);
				delay(50);
				nosound();
				brick[14]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=15 && left<=24 && brick[15]!=1)
			 {
				space_soft_hard_rectangle(15, 7,24, 8);
				sound(430);
				delay(50);
				nosound();
				brick[15]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=25 && left<=34 && brick[16]!=1)
			 {
				space_soft_hard_rectangle(25, 7,34, 8);
				sound(430);
				delay(50);
				nosound();
				brick[16]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=35 && left<=44 && brick[17]!=1)
			 {
				space_soft_hard_rectangle(35, 7,44, 8);
				sound(430);
				delay(50);
				nosound();
				brick[17]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=45 && left<=54 && brick[18]!=1)
			 {
				space_soft_hard_rectangle(45, 7,54, 8);
				sound(430);
				delay(50);
				nosound();
				brick[18]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=55 && left<=64 && brick[19]!=1)
			 {
				space_soft_hard_rectangle(55, 7,64, 8);
				sound(430);
				delay(50);
				nosound();
				brick[19]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=65 && left<=74 && brick[20]!=1)
			 {
				space_soft_hard_rectangle(65, 7,74, 8);
				sound(430);
				delay(50);
				nosound();
				brick[20]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		}
		else if(top==9 || top == 10)
		{
			 if(left>= 5 && left<=14 && brick[21]!=1)
			 {
				space_soft_hard_rectangle( 5, 9,14,10);
				sound(430);
				delay(50);
				nosound();
				brick[21]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=15 && left<=24 && brick[22]!=1)
			 {
				space_soft_hard_rectangle(15, 9,24,10);
				sound(430);
				delay(50);
				nosound();
				brick[22]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=25 && left<=34 && brick[23]!=1)
			 {
				space_soft_hard_rectangle(25, 9,34,10);
				sound(430);
				delay(50);
				nosound();
				brick[23]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=35 && left<=44 && brick[24]!=1)
			 {
				space_soft_hard_rectangle(35, 9,44,10);
				sound(430);
				delay(50);
				nosound();
				brick[24]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=45 && left<=54 && brick[25]!=1)
			 {
				space_soft_hard_rectangle(45, 9,54,10);
				sound(430);
				delay(50);
				nosound();
				brick[25]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=55 && left<=64 && brick[26]!=1)
			 {
				space_soft_hard_rectangle(55, 9,64,10);
				sound(430);
				delay(50);
				nosound();
				brick[26]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=65 && left<=74 && brick[27]!=1)
			 {
				space_soft_hard_rectangle(65, 9,74,10);
				sound(430);
				delay(50);
				nosound();
				brick[27]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		}
		else if(top==11 || top == 12)
		{
			 if(left>= 5 && left<=14 && brick[28]!=1)
			 {
				space_soft_hard_rectangle( 5,11,14,12);
				sound(430);
				delay(50);
				nosound();
				brick[28]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=15 && left<=24 && brick[29]!=1)
			 {
				space_soft_hard_rectangle(15,11,24,12);
				sound(430);
				delay(50);
				nosound();
				brick[29]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=25 && left<=34 && brick[30]!=1)
			 {
				space_soft_hard_rectangle(25,11,34,12);
				sound(430);
				delay(50);
				nosound();
				brick[30]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=35 && left<=44 && brick[31]!=1)
			 {
				space_soft_hard_rectangle(35,11,44,12);
				sound(430);
				delay(50);
				nosound();
				brick[31]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=45 && left<=54 && brick[32]!=1)
			 {
				space_soft_hard_rectangle(45,11,54,12);
				sound(430);
				delay(50);
				nosound();
				brick[32]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=55 && left<=64 && brick[33]!=1)
			 {
				space_soft_hard_rectangle(55,11,64,12);
				sound(430);
				delay(50);
				nosound();
				brick[33]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=65 && left<=74 && brick[34]!=1)
			 {
				space_soft_hard_rectangle(65,11,74,12);
				sound(430);
				delay(50);
				nosound();
				brick[34]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		}
   }

	ball_left=left;
	ball_top=top;
	return status;
}
int check2()
{
	if(top==13||top==12||top==11||top==10||top==9||top==8||top == 7 ||top == 6 || top==5 || top == 4 || top == 3 )
	{
		if(top == 3 || top == 4)
		{
			 if(left>= 5 && left<=14 && brick[0]!=1)
			 {
				if(brick[0]==2)
				{
					soft_rectangle( 5, 3,14, 4,13);
					sound(430);
					delay(100);
					nosound();
					brick[0]=3;
					score_illusion();//1
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle( 5, 3,14, 4);
					sound(430);
					delay(100);
					nosound();
					brick[0]=1;
					score_illusion();//2
					brick_count++;
					status=brick_reflect();
				}
			 }
		else if(left>=15 && left<=24 && brick[1]!=1)
			 {
				if(brick[1]==2)
				{
					soft_rectangle(15, 3,24, 4,13);
					sound(430);
					delay(100);
					nosound();
					brick[1]=3;
					score_illusion();
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(15, 3,24, 4);
					sound(430);
					delay(100);
					nosound();
					brick[1]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		else if(left>=25 && left<=34 && brick[2]!=1)
			 {
				if(brick[2]==2)
				{
					soft_rectangle(25, 3,34, 4,13);
					sound(430);
					delay(100);
					nosound();
					brick[2]=3;
					score_illusion();
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(25, 3,34, 4);
					sound(430);
					delay(100);
					nosound();
					brick[2]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		else if(left>=35 && left<=44 && brick[3]!=1)
			 {
				if(brick[3]==2)
				{
					soft_rectangle(35, 3,44, 4,13);
					sound(430);
					delay(100);
					nosound();
					brick[3]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(35, 3,44, 4);
					sound(430);
					delay(100);
					nosound();
					brick[3]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		else if(left>=45 && left<=54 && brick[4]!=1)
			 {
				if(brick[4]==2)
				{
					soft_rectangle(45, 3,54, 4,13);
					sound(430);
					delay(100);
					nosound();
					brick[4]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(45, 3,54, 4);
					sound(430);
					delay(100);
					nosound();
					brick[4]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		else if(left>=55 && left<=64 && brick[5]!=1)
			 {
				if(brick[5]==2)
				{
					soft_rectangle(55, 3,64, 4,13);
					sound(430);
					delay(100);
					nosound();
					brick[5]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(55, 3,64, 4);
					sound(430);
					delay(100);
					nosound();
					brick[5]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		else if(left>=65 && left<=74 && brick[6]!=1)
			 {
				if(brick[6]==2)
				{
					soft_rectangle(65, 3,74, 4,13);
					sound(430);
					delay(100);
					nosound();
					brick[6]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(65, 3,74, 4);
					sound(430);
					delay(100);
					nosound();
					brick[6]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		}
		else if(top==5 || top == 6)
		{
			 if(left>= 5 && left<=14 && brick[7]!=1)
			 {
				if(brick[7]==2)
				{
					soft_rectangle( 5, 5,14, 6,13);
					sound(430);
					delay(100);
					nosound();
					brick[7]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle( 5, 5,14, 6);
					sound(430);
					delay(100);
					nosound();
					brick[7]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		else if(left>=15 && left<=24 && brick[8]!=1)
			 {
				space_soft_hard_rectangle(15, 5,24, 6);
				sound(430);
				delay(100);
				nosound();
				brick[8]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=25 && left<=34 && brick[9]!=1)
			 {
				space_soft_hard_rectangle(25, 5,34, 6);
				sound(430);
				delay(100);
				nosound();
				brick[9]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=35 && left<=44 && brick[10]!=1)
			 {
				space_soft_hard_rectangle(35, 5,44, 6);
				sound(430);
				delay(100);
				nosound();
				brick[10]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=45 && left<=54 && brick[11]!=1)
			 {
				space_soft_hard_rectangle(45, 5,54, 6);
				sound(430);
				delay(100);
				nosound();
				brick[11]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=55 && left<=64 && brick[12]!=1)
			 {
				space_soft_hard_rectangle(55, 5,64, 6);
				sound(430);
				delay(100);
				nosound();
				brick[12]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=65 && left<=74 && brick[13]!=1)
			 {
				if(brick[13]==2)
				{
					soft_rectangle(65, 5,74, 6,13);
					sound(430);
					delay(100);
					nosound();
					brick[13]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(65, 5,74, 6);
					sound(430);
					delay(100);
					nosound();
					brick[13]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		}
		else if(top==7 || top == 8)
		{
			 if(left>= 5 && left<=14 && brick[14]!=1)
			 {
				if(brick[14]==2)
				{
					soft_rectangle( 5, 7,14, 8,13);
					sound(430);
					delay(100);
					nosound();
					brick[14]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle( 5, 7,14, 8);
					sound(430);
					delay(100);
					nosound();
					brick[14]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		else if(left>=15 && left<=24 && brick[15]!=1)
			 {
				space_soft_hard_rectangle(15, 7,24, 8);
				sound(430);
				delay(100);
				nosound();
				brick[15]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=25 && left<=34 && brick[16]!=1)
			 {
				space_soft_hard_rectangle(25, 7,34, 8);
				sound(430);
				delay(100);
				nosound();
				brick[16]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=35 && left<=44 && brick[17]!=1)
			 {
				space_soft_hard_rectangle(35, 7,44, 8);
				sound(430);
				delay(100);
				nosound();
				brick[17]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=45 && left<=54 && brick[18]!=1)
			 {
				space_soft_hard_rectangle(45, 7,54, 8);
				sound(430);
				delay(100);
				nosound();
				brick[18]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=55 && left<=64 && brick[19]!=1)
			 {
				space_soft_hard_rectangle(55, 7,64, 8);
				sound(430);
				delay(100);
				nosound();
				brick[19]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=65 && left<=74 && brick[20]!=1)
			 {
				if(brick[20]==2)
				{
					soft_rectangle(65, 7,74, 8,13);
					sound(430);
					delay(100);
					nosound();
					brick[20]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(65, 7,74, 8);
					sound(430);
					delay(100);
					nosound();
					brick[20]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		}
		else if(top==9 || top == 10)
		{
			 if(left>= 5 && left<=14 && brick[21]!=1)
			 {
				if(brick[21]==2)
				{
					soft_rectangle( 5, 9,14,10,13);
					sound(430);
					delay(100);
					nosound();
					brick[21]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle( 5, 9,14,10);
					sound(430);
					delay(100);
					nosound();
					brick[21]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		else if(left>=15 && left<=24 && brick[22]!=1)
			 {
				space_soft_hard_rectangle(15, 9,24,10);
				sound(430);
				delay(100);
				nosound();
				brick[22]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=25 && left<=34 && brick[23]!=1)
			 {
				space_soft_hard_rectangle(25, 9,34,10);
				sound(430);
				delay(100);
				nosound();
				brick[23]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=35 && left<=44 && brick[24]!=1)
			 {
				space_soft_hard_rectangle(35, 9,44,10);
				sound(430);
				delay(100);
				nosound();
				brick[24]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=45 && left<=54 && brick[25]!=1)
			 {
				space_soft_hard_rectangle(45, 9,54,10);
				sound(430);
				delay(100);
				nosound();
				brick[25]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=55 && left<=64 && brick[26]!=1)
			 {
				space_soft_hard_rectangle(55, 9,64,10);
				sound(430);
				delay(100);
				nosound();
				brick[26]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=65 && left<=74 && brick[27]!=1)
			 {
				if(brick[27]==2)
				{
					soft_rectangle(65, 9,74,10,13);
					sound(430);
					delay(100);
					nosound();
					brick[27]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(65, 9,74,10);
					sound(430);
					delay(100);
					nosound();
					brick[27]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		}
		else if(top==11 || top == 12)
		{
			 if(left>= 3 && left<=14 && brick[28]!=1)
			 {
				if(brick[28]==2)
				{
					soft_rectangle( 5,11,14,12,13);
					sound(430);
					delay(100);
					nosound();
					brick[28]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle( 5,11,14,12);
					sound(430);
					delay(100);
					nosound();
					brick[28]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		else if(left>=15 && left<=24 && brick[29]!=1)
			 {
				if(brick[29]==2)
				{
					soft_rectangle(15,11,24,12,13);
					sound(430);
					delay(100);
					nosound();
					brick[29]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(15,11,24,12);
					sound(430);
					delay(100);
					nosound();
					brick[29]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		else if(left>=25 && left<=34 && brick[30]!=1)
			 {
				if(brick[30]==2)
				{
					soft_rectangle(25,11,34,12,13);
					sound(430);
					delay(100);
					nosound();
					brick[30]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(25,11,34,12);
					sound(430);
					delay(100);
					nosound();
					brick[30]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		else if(left>=35 && left<=44 && brick[31]!=1)
			 {
				if(brick[31]==2)
				{
					soft_rectangle(35,11,44,12,13);
					sound(430);
					delay(100);
					nosound();
					brick[31]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(35,11,44,12);
					sound(430);
					delay(100);
					nosound();
					brick[31]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		else if(left>=45 && left<=54 && brick[32]!=1)
			 {
				if(brick[32]==2)
				{
					soft_rectangle(45,11,54,12,13);
					sound(430);
					delay(100);
					nosound();
					brick[32]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(45,11,54,12);
					sound(430);
					delay(100);
					nosound();
					brick[32]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		else if(left>=55 && left<=64 && brick[33]!=1)
			 {
				if(brick[33]==2)
				{
					soft_rectangle(55,11,64,12,13);
					sound(430);
					delay(100);
					nosound();
					brick[33]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(55,11,64,12);
					sound(430);
					delay(100);
					nosound();
					brick[33]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		else if(left>=65 && left<=74 && brick[34]!=1)
			 {
				if(brick[34]==2)
				{
					soft_rectangle(65,11,74,12,13);
					sound(430);
					delay(100);
					nosound();
					brick[34]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(65,11,74,12);
					sound(430);
					delay(100);
					nosound();
					brick[34]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();

				}
			 }
		}
   }

	ball_left=left;
	ball_top=top;
	return status;
}
int check3()
{
	if(top==16||top==15||top==14||top==13||top==12||top==11||top==10||top==9||top==8||top == 7 ||top == 6 || top==5 || top == 4 || top == 3 )
	{
		if(top == 4 || top==3)
		{
			if(left>=35 && left<=44 && brick[0]!=1)
			 {
				if(brick[0]==2)
				{
					soft_rectangle(35, 3,44, 4,13);
					sound(430);
					delay(100);
					nosound();
					brick[0]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(35, 3,44, 4);
					sound(430);
					delay(100);
					nosound();
					brick[0]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		}
		else if(top == 6 || top == 5)
		{
			 if(left>=25 && left<=34 && brick[1]!=1)
			 {
				if(brick[1]==2)
				{
					soft_rectangle(25, 5,34, 6,13);
					sound(430);
					delay(100);
					nosound();
					brick[1]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(25, 5,34, 6);
					sound(430);
					delay(100);
					nosound();
					brick[1]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		else if(left>=35 && left<=44 && brick[2]!=1)
			 {
				space_soft_hard_rectangle(35, 5,44, 6);
				sound(430);
				delay(100);
				nosound();
				brick[2]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=46 && left<=54 && brick[3]!=1)
			 {
				if(brick[3]==2)
				{
					soft_rectangle(45, 5,54, 6,13);
					sound(430);
					delay(100);
					nosound();
					brick[3]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(45, 5,54, 6);
					sound(430);
					delay(100);
					nosound();
					brick[3]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		}
		else if(top == 8 || top == 7)
		{
			if(left>=15 && left<=24 && brick[4]!=1)
			 {
				if(brick[4]==2)
				{
					soft_rectangle(15, 7,24, 8,13);
					sound(430);
					delay(100);
					nosound();
					brick[4]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(15, 7,24, 8);
					sound(430);
					delay(100);
					nosound();
					brick[4]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		else if(left>=25 && left<=34 && brick[5]!=1)
			 {
				space_soft_hard_rectangle(25, 7,34, 8);
				sound(430);
				delay(100);
				nosound();
				brick[5]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=35 && left<=44 && brick[6]!=1)
			 {
				if(brick[6]==2)
				{
					soft_rectangle(35, 7,44, 8,13);
					sound(430);
					delay(100);
					nosound();
					brick[6]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(35, 7,44, 8);
					sound(430);
					delay(100);
					nosound();
					brick[6]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		else if(left>=45 && left<=54 && brick[7]!=1)
			 {
				space_soft_hard_rectangle(45, 7,54, 8);
				sound(430);
				delay(100);
				nosound();
				brick[7]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=55 && left<=64 && brick[8]!=1)
			 {
				if(brick[8]==2)
				{
					soft_rectangle(55, 7,64, 8,13);
					sound(430);
					delay(100);
					nosound();
					brick[8]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(55, 7,64, 8);
					sound(430);
					delay(100);
					nosound();
					brick[8]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		}
		else if(top == 10 || top == 9)
		{
			 if(left>= 5 && left<=14 && brick[9]!=1)
			 {
				if(brick[9]==2)
				{
					soft_rectangle( 5, 9,14,10,13);
					sound(430);
					delay(100);
					nosound();
					brick[9]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle( 5, 9,14,10);
					sound(430);
					delay(100);
					nosound();
					brick[9]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		else if(left>=15 && left<=24 && brick[10]!=1)
			 {
				space_soft_hard_rectangle(15, 9,24,10);
				sound(430);
				delay(100);
				nosound();
				brick[10]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=25 && left<=34 && brick[11]!=1)
			 {
				if(brick[11]==2)
				{
					soft_rectangle(25, 9,34,10,13);
					sound(430);
					delay(100);
					nosound();
					brick[11]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(25, 9,34,10);
					sound(430);
					delay(100);
					nosound();
					brick[11]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		else if(left>=45 && left<=54 && brick[12]!=1)
			 {
				if(brick[12]==2)
				{
					soft_rectangle(45, 9,54,10,13);
					sound(430);
					delay(100);
					nosound();
					brick[12]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(45, 9,54,10);
					sound(430);
					delay(100);
					nosound();
					brick[12]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		else if(left>=55 && left<=64 && brick[13]!=1)
			 {
				space_soft_hard_rectangle(55, 9,64,10);
				sound(430);
				delay(100);
				nosound();
				brick[13]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=65 && left<=74 && brick[14]!=1)
			 {
				if(brick[14]==2)
				{
					soft_rectangle(65, 9,74,10,13);
					sound(430);
					delay(100);
					nosound();
					brick[14]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(65, 9,74,10);
					sound(430);
					delay(100);
					nosound();
					brick[14]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		}
		else if(top == 12 || top == 11)
		{
			 if(left>=15 && left<=24 && brick[15]!=1)
			 {
				if(brick[15]==2)
				{
					soft_rectangle(15,11,24,12,13);
					sound(430);
					delay(100);
					nosound();
					brick[15]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(15,11,24,12);
					sound(430);
					delay(100);
					nosound();
					brick[15]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		else if(left>=25 && left<=34 && brick[16]!=1)
			 {
				space_soft_hard_rectangle(25,11,34,12);
				sound(430);
				delay(100);
				nosound();
				brick[16]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=35 && left<=44 && brick[17]!=1)
			 {
				if(brick[17]==2)
				{
					soft_rectangle(35,11,44,12,13);
					sound(430);
					delay(100);
					nosound();
					brick[17]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(35,11,44,12);
					sound(430);
					delay(100);
					nosound();
					brick[17]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		else if(left>=45 && left<=54 && brick[18]!=1)
			 {
				space_soft_hard_rectangle(45,11,54,12);
				sound(430);
					delay(100);
					nosound();
				brick[18]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=55 && left<=64 && brick[19]!=1)
			 {
				if(brick[19]==2)
				{
					soft_rectangle(55,11,64,12,13);
					sound(430);
					delay(100);
					nosound();
					brick[19]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(55,11,64,12);
					sound(430);
					delay(100);
					nosound();
					brick[19]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		}
		else if(top==14 || top == 13)
		{
			 if(left>=25 && left<=34 && brick[20]!=1)
			 {
				if(brick[20]==2)
				{
					soft_rectangle(25,13,34,14,13);
					sound(430);
					delay(100);
					nosound();
					brick[20]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(25,13,34,14);
					sound(430);
					delay(100);
					nosound();
					brick[20]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		else if(left>=35 && left<=44 && brick[21]!=1)
			 {
				space_soft_hard_rectangle(35,13,44,14);
				sound(430);
				delay(100);
				nosound();
				brick[21]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=46 && left<=54 && brick[22]!=1)
			 {
				if(brick[22]==2)
				{
					soft_rectangle(45,13,54,14,13);
					sound(430);
					delay(100);
					nosound();
					brick[22]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(45,13,54,14);
					sound(430);
					delay(100);
					nosound();
					brick[22]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		}
		else if(top == 16 || top == 15)
		{
			if(left>=35 && left<=44 && brick[23]!=1)
			 {
				if(brick[23]==2)
				{
					soft_rectangle(35,15,44,16,13);
					sound(430);
					delay(100);
					nosound();
					brick[23]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(35,15,44,16);
					sound(430);
					delay(100);
					nosound();
					brick[23]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		}
   }

	ball_left=left;
	ball_top=top;
	return status;
}
int check4()
{
	if(top==14||top==13||top==12||top==11||top==10||top==9||top==8||top == 7 ||top == 6 || top==5 || top == 4 || top == 3 )
	{
		if(top == 3 || top == 4)
		{
			 if(left>= 5 && left<=14 && brick[0]!=1)
			 {
				space_soft_hard_rectangle( 5, 3,14, 4);
				sound(430);
				delay(100);
				nosound();
				brick[0]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=15 && left<=24 && brick[1]!=1)
			 {
				space_soft_hard_rectangle(15, 3,24, 4);
				sound(430);
				delay(100);
				nosound();
				brick[1]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=25 && left<=34 && brick[2]!=1)
			 {
				space_soft_hard_rectangle(25, 3,34, 4);
				sound(430);
				delay(100);
				nosound();
				brick[2]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=35 && left<=44 && brick[3]!=1)
			 {
				if(brick[3]==2)
				{
					soft_rectangle(35, 3,44, 4,12);
					sound(430);
					delay(100);
					nosound();
					brick[3]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(35, 3,44, 4);
					sound(430);
					delay(100);
					nosound();
					brick[3]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		else if(left>=45 && left<=54 && brick[4]!=1)
			 {

				space_soft_hard_rectangle(45, 3,54, 4);
				sound(430);
				delay(100);
				nosound();
				brick[4]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=55 && left<=64 && brick[5]!=1)
			 {
				space_soft_hard_rectangle(55, 3,64, 4);
				sound(430);
				delay(100);
				nosound();
				brick[5]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=65 && left<=74 && brick[6]!=1)
			 {
				space_soft_hard_rectangle(65, 3,74, 4);
				sound(430);
				delay(100);
				nosound();
				brick[6]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		}
		else if(top==5 || top == 6)
		{
			 if(left>= 5 && left<=14 && brick[7]!=1)
			 {
				space_soft_hard_rectangle( 5, 5,14, 6);
				sound(430);
				delay(100);
				nosound();
				brick[7]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=15 && left<=24 && brick[8]!=1)
			 {
				space_soft_hard_rectangle(15, 5,24, 6);
				sound(430);
				delay(100);
				nosound();
				brick[8]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=25 && left<=34 && brick[9]!=1)
			 {
				if(brick[9]==2)
				{
					soft_rectangle(25, 5,34, 6,13);
					sound(430);
					delay(100);
					nosound();
					brick[9]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(25, 5,34, 6);
					sound(430);
					delay(100);
					nosound();
					brick[9]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		else if(left>=45 && left<=54 && brick[10]!=1)
			 {
				if(brick[10]==2)
				{
					soft_rectangle(45, 5,54, 6,13);
					sound(430);
					delay(100);
					nosound();
					brick[10]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(45, 5,54, 6);
					sound(430);
					delay(100);
					nosound();
					brick[10]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		else if(left>=55 && left<=64 && brick[11]!=1)
			 {
				space_soft_hard_rectangle(55, 5,64, 6);
				sound(430);
				delay(100);
				nosound();
				brick[11]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=65 && left<=74 && brick[12]!=1)
			 {
				space_soft_hard_rectangle(65, 5,74, 6);
				sound(430);
				delay(100);
				nosound();
				brick[12]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		}
		else if(top==7 || top == 8)
		{
			 if(left>= 5 && left<=14 && brick[13]!=1)
			 {
				space_soft_hard_rectangle( 5, 7,14, 8);
				sound(430);
				delay(100);
				nosound();
				brick[13]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=15 && left<=24 && brick[14]!=1)
			 {
				if(brick[14]==2)
				{
					soft_rectangle(15, 7,24, 8,13);
					sound(430);
					delay(100);
					nosound();
					brick[14]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(15, 7,24, 8);
					sound(430);
					delay(100);
					nosound();
					brick[14]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		else if(left>=55 && left<=64 && brick[15]!=1)
			 {
				if(brick[15]==2)
				{
					soft_rectangle(55, 7,64, 8,13);
					sound(430);
					delay(100);
					nosound();
					brick[15]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(55, 7,64, 8);
					sound(430);
					delay(100);
					nosound();
					brick[15]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		else if(left>=65 && left<=74 && brick[16]!=1)
			 {
				space_soft_hard_rectangle(65, 7,74, 8);
				sound(430);
				delay(100);
				nosound();
				brick[16]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		}
		else if(top==9 || top == 10)
		{
			 if(left>= 5 && left<=14 && brick[17]!=1)
			 {
				if(brick[17]==2)
				{
					soft_rectangle( 5, 9,14,10,13);
					sound(430);
					delay(100);
					nosound();
					brick[17]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle( 5, 9,14,10);
					sound(430);
					delay(100);
					nosound();
					brick[17]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		else if(left>=65 && left<=74 && brick[18]!=1)
			 {
				if(brick[18]==2)
				{
					soft_rectangle(65, 9,74,10,13);
					sound(430);
					delay(100);
					nosound();
					brick[18]=3;
					score_illusion();//
					brick_count++;
					status=brick_reflect();
				}
				else
				{
					space_soft_hard_rectangle(65, 9,74,10);
					sound(430);
					delay(100);
					nosound();
					brick[18]=1;
					score_illusion();//count++;
					brick_count++;
					status=brick_reflect();
				}
			 }
		}
		else if(top==11 || top == 12)
		{
			 if(left>= 5 && left<=14 && brick[19]!=1)
			 {
				space_soft_hard_rectangle( 5,11,14,12);
				sound(430);
				delay(100);
				nosound();
				brick[19]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=15 && left<=24 && brick[20]!=1)
			 {
				space_soft_hard_rectangle(15,11,24,12);
				sound(430);
				delay(100);
				nosound();
				brick[20]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=25 && left<=34 && brick[21]!=1)
			 {
				space_soft_hard_rectangle(25,11,34,12);
				sound(430);
				delay(100);
				nosound();
				brick[21]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=35 && left<=44 && brick[22]!=1)
			 {
				space_soft_hard_rectangle(35,11,44,12);
				sound(430);
				delay(100);
				nosound();
				brick[22]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=45 && left<=54 && brick[23]!=1)
			 {
				space_soft_hard_rectangle(45,11,54,12);
				sound(430);
				delay(100);
				nosound();
				brick[23]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=55 && left<=64 && brick[24]!=1)
			 {
				space_soft_hard_rectangle(55,11,64,12);
				sound(430);
				delay(100);
				nosound();
				brick[24]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=65 && left<=74 && brick[25]!=1)
			 {
				space_soft_hard_rectangle(65,11,74,12);
				sound(430);
				delay(100);
				nosound();
				brick[25]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		}
		else if(top==13 || top == 14)
		{
			 if(left>= 5 && left<=14 && brick[26]!=1)
			 {
				space_soft_hard_rectangle( 5,13,14,14);
				sound(430);
				delay(100);
				nosound();
				brick[26]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=15 && left<=24 && brick[27]!=1)
			 {
				space_soft_hard_rectangle(15,13,24,14);
				sound(430);
				delay(100);
				nosound();
				brick[27]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=25 && left<=34 && brick[28]!=1)
			 {
				space_soft_hard_rectangle(25,13,34,14);
				sound(430);
				delay(100);
				nosound();
				brick[28]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=35 && left<=44 && brick[29]!=1)
			 {
				space_soft_hard_rectangle(35,13,44,14);
				sound(430);
				delay(100);
				nosound();
				brick[29]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=45 && left<=54 && brick[30]!=1)
			 {
				space_soft_hard_rectangle(45,13,54,14);
				sound(430);
				delay(100);
				nosound();
				brick[30]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=55 && left<=64 && brick[31]!=1)
			 {
				space_soft_hard_rectangle(55,13,64,14);
				sound(430);
				delay(100);
				nosound();
				brick[31]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		else if(left>=65 && left<=74 && brick[32]!=1)
			 {
				space_soft_hard_rectangle(65,13,74,14);
				sound(430);
				delay(100);
				nosound();
				brick[32]=1;
				score_illusion();//count++;
				brick_count++;
				status=brick_reflect();
			 }
		}
   }

	ball_left=left;
	ball_top=top;
	return status;


}





int brick_reflect()
{
		switch(status)
		{
			case 1:
			left++;
			top--;
			break;

			case 2:
			left++;
			top++;
			break;

			case 3:
			left--;
			top--;
			break;

			case 4:
			left--;
			top++;
			break;
		}

	if(ball_top>top)
	{
		if(ball_left>left)
		{
			ball_left=left;
			ball_top=top;
			left++;
			left++;
			top++;
			top++;
			return 4;
		}
		else
		{
			ball_left=left;
			ball_top=top;
			left--;
			left--;
			top++;
			top++;
			return 2;
		}
	}
	else if(ball_top<top)
	{
		if(ball_left>left)
		{
			ball_left=left;
			ball_top=top;
			left++;
			left++;
			top--;
			top--;
			return 3;
		}
		else
		{
			ball_left=left;
			ball_top=top;
			left--;
			left--;
			top--;
			top--;
			return 1;
		}
	}
	return status;
}
void welcome()
{
	_setcursortype(_NOCURSOR);
  //	soft_rectangle(3,1,76,25,11);      //boundary
	hard_rectangle(32, 2,47, 4,12);
	textcolor(7);
	gotoxy(35,3);
	cprintf("Brick Game");

	soft_rectangle( 6,2,14,3,1);
	soft_rectangle(15,2,23,3,2);
	soft_rectangle(24,2,31,3,3);
	soft_rectangle(48,2,55,3,6);
	soft_rectangle(56,2,64,3,7);
	soft_rectangle(65,2,73,3,14);

	soft_rectangle( 6,4,14,5,8);
	soft_rectangle(15,4,23,5,7);
	soft_rectangle(24,4,32,5,6);
	soft_rectangle(33,4,39,5,5);
	soft_rectangle(40,4,46,5,4);
	soft_rectangle(47,4,55,5,12);
	soft_rectangle(56,4,64,5,2);
	soft_rectangle(65,4,73,5,1);

	soft_rectangle(6,6,14,7,15);
	soft_rectangle(15,6,23,7,14);
	soft_rectangle(24,6,32,7,3);
	soft_rectangle(33,6,39,7,4);
	soft_rectangle(40,6,46,7,5);
	soft_rectangle(47,6,55,7,11);
	soft_rectangle(56,6,64,7,10);
	soft_rectangle(65,6,73,7,9);


	soft_rectangle(6,8,14,9,5);
	soft_rectangle(15,8,23,9,3);
	soft_rectangle(56,8,64,9,11);
	soft_rectangle(65,8,73,9,6);

	soft_rectangle(6,10,14,11,3);
	soft_rectangle(15,10,23,11,5);
	soft_rectangle(56,10,64,11,6);
	soft_rectangle(65,10,73,11,11);


	soft_rectangle(6,12,14,13,15);
	soft_rectangle(65,12,73,13,15);

	hard_rectangle(33,10,46,12,12);    //inst
	hard_rectangle(33,14,46,16,12);   //inst
	hard_rectangle(33,18,46,20,12);   //inst
	textcolor(WHITE);
	gotoxy(38,11);
	cprintf("Play");
	gotoxy(35,15);
	cprintf("High Score");
	gotoxy(38,19);
	cprintf("Help");

   //	soft_rectangle(7,22,19,23,7);
	textcolor(7);
	gotoxy(7,23);
	cprintf("%c%c%c%c%c%c%c%c%c%c",223,223,223,223,223,223,223,223,223,223);
	textcolor(RED);
	gotoxy(10,22);
	cprintf("o");

	textcolor(7);
	gotoxy(30,23);
	cprintf("Press any key to Play");
	while(!kbhit())
		{

			textcolor(colour1);
			gotoxy(35,3);
			cprintf("Brick Game");
			hard_rectangle(3,1,75,25,colour1); //boundary
			delay(40);
			colour1++;
			if(colour1==15)colour1=1;
		}
	/*welcome_option=getch();
	if(welcome_option == 'h' || welcome_option == 'H')
	{
	} /**/
}

void level_option()
{
	hard_rectangle(3,1,75,25,4);
	textcolor(6);
	gotoxy(32,3);
	cprintf("Brick Game");
	soft_rectangle(10,5,68,21,11);
	line_down(39,6,21);
	textcolor(9);
	gotoxy(18,6);
	cprintf("Level Selection");
	gotoxy(50,6);
	cprintf("High Score");
	textcolor(WHITE);
	gotoxy(21,8);
	cprintf("level 1");
	gotoxy(54,8);
	cprintf("-");
	gotoxy(21,10);
	cprintf("level 2");
	gotoxy(54,10);
	cprintf("-");
	gotoxy(21,12);
	cprintf("level 3");
	gotoxy(54,12);
	cprintf("-");
	gotoxy(21,14);
	cprintf("level 4");
	gotoxy(54,14);
	cprintf("-");
//	gotoxy(21,16);
//	cprintf("level 5");
//	gotoxy(54,16);
//	cprintf("-");
	textcolor(9);
	gotoxy(21,23);
	cprintf("Press (1-4) to play specific level");

	up:level = getch();
	if(level=='1'||level=='2'||level=='3'||level=='4');
	else
	{
		goto up;
	}
}
void instruction()
{
  //	soft_rectangle(3,1,76,25,11);   //boundary
	soft_rectangle(10,5,68,21,11);
	line_down(39,6,21);

	textcolor(7);
	gotoxy(34,3);
	cprintf("Brick Game");
//	textcolor(5);
//	gotoxy(32,6);
//	cprintf("Press * key");
	textcolor(WHITE);
	gotoxy(20,8);
	cprintf("Press a");
	gotoxy(43,8);
	cprintf("move tray left");
	gotoxy(20,10);
	cprintf("Press d");
	gotoxy(43,10);
	cprintf("move tray right");
	gotoxy(20,12);
	cprintf("Press s");
	gotoxy(43,12);
	cprintf("set speed sensitivity");
	gotoxy(20,14);
	cprintf("Press r");
	gotoxy(43,14);
	cprintf("reset the game");
	gotoxy(20,16);
	cprintf("Press space");
	gotoxy(43,16);
	cprintf("pause the game");
	gotoxy(43,17);
	cprintf("continue the game");
	gotoxy(20,19);
	cprintf("Press e");
	gotoxy(43,19);
	cprintf("exit the game");
	textcolor(9);
	gotoxy(29,23);
	cprintf("Press any key to play");
	while(!kbhit())
		{
			hard_rectangle(3,1,75,25,colour1); //boundary
			delay(40);
			colour1++;
			if(colour1==15)colour1=1;
		}
}


int score_illusion()
{
	int count=0;
	while(count<10)
	{
		count++;
		score++;
		delay(5);
		textcolor(RED);
		gotoxy(69,1);
		cprintf("Score: %d",score);
	 }
	 return score;
}

void finish()
{
	int colour=0;
	clrscr();
	_setcursortype(_NOCURSOR);
  //	hard_rectangle(32, 2,47, 4,12);
	textcolor(7);
	gotoxy(35,3);
	cprintf("Brick Game");
	gotoxy(50,23);
	cprintf("Made by : Navjot Singh");
	gotoxy(60,24);
	cprintf("Manish Mishra ");
	textcolor(YELLOW);
	gotoxy(33,9);
	cprintf("Your score: %d",score);
//	hard_rectangle(23,14,58,17,11);
	textcolor(RED);
	gotoxy(25,15);
	cprintf("Play Again");
	gotoxy(25,16);
	cprintf("Do you want to play again? (Y/N)");

	while(!kbhit())
	{
		hard_rectangle(3,1,75,25,colour); //boundary
		delay(40);
		textcolor(colour);
		gotoxy(26,3);
		cprintf("%c%c%c%c%c%c%c%c%c\n",254,196,254,196,254,196,254,196,254);
		gotoxy(45,3);
		cprintf("%c%c%c%c%c%c%c%c%c\n",254,196,254,196,254,196,254,196,254);

		colour++;
		if(colour==15)colour=1;
	}

	finish_option: finish_option=getch();
	if(finish_option=='y'||finish_option=='Y')
	{
		clrscr();
		lefttray=24;left=27;top=23;speed=100;ball_option='q';
		status=1;ball_left=0;ball_top=0;score=0;left_dil=15;life=6;
		while(offset<40)
		{
			brick[offset]=2;
			offset++;
		}
		offset=0;
		if(level=='1')display1();
		else if(level=='2')display2();
		else if(level=='3')display3();
		else if(level=='4')display4();

	/*	if(level=='1')check1();
		else if(level=='2')check2();
		else if(level=='3')check3();
		else if(level=='4')check4(); */


	}
	else if(finish_option=='n'||finish_option=='N')
	{
		clrscr();
		soft_rectangle(3,1,75,25,14); //boundary
		hard_rectangle(32, 2,47, 4,12);
		textcolor(7);
		gotoxy(35,3);
		cprintf("Brick Game");
		gotoxy(50,23);
		cprintf("Made by : Navjot Singh");
		textcolor(LIGHTBLUE);
		gotoxy(31,14);
		cprintf("Thanks for playing");
		smile(12,10);
		smile(59,10);
		while(!kbhit())
		{
			textbackground(BLACK);
			hard_rectangle(3,1,75,25,colour); //boundary
			delay(40);
			colour++;
			if(colour==15)colour=1;
			textcolor(colour);
			gotoxy(18,13);
			cprintf("o");
			delay(50
			);
			textcolor(colour);
			gotoxy(13,13);
			cprintf("%c",3);
			delay(50);
			textcolor(colour);
			gotoxy(65,13);
			cprintf("o");
			delay(50);
			textcolor(colour);
			gotoxy(60,13);
			cprintf("%c",3);
			delay(50);
		}

		exit(0);
	}
	else
	{
		gotoxy(30,18);
		cprintf("Invalid option");
		getch();
		gotoxy(30,18);
		cprintf("              ");
		goto finish_option;
	}
}
int reflect_boundaries()
{
	if(left <= 2)
	{
		if(ball_top>top)
		{
			ball_left=left;
			ball_top=top;
			return 1;
		}
		else
		{
			ball_left=left;
			ball_top=top;
			return 2;
		}
	}
	else if(left >= 76)
	{
		if(ball_top>top)
		{
			ball_left=left;
			ball_top=top;
			return 3;
		}
		else
		{
			ball_left=left;
			ball_top=top;
			return 4;
		}
	}
	else if(top <= 2)
	{
		if(ball_left>left)
		{
			ball_left=left;
			ball_top=top;
			return 4;
		}
		else
		{
			ball_left=left;
			ball_top=top;
			return 2;
		}
	}
	else if(top == 23 && left >= lefttray && left <= lefttray+10)
	{
		if(ball_left>left)
		{
			ball_left=left;
			ball_top=top;
			return 3;
		}
		else
		{
			ball_left=left;
			ball_top=top;
			return 1;
		}
	}
	else if(top>=24)
	{
		if(life==0)finish();
		else
		{
			while(count<78)
			{
				gotoxy(count,24);
				cprintf(" ");
				count++;
			}
			count=2;
			life--;
			gotoxy(left_dil,1);
			left_dil--;
			cprintf(" ");
			lefttray=24;left=27;top=23;speed=100;ball_option='q';
			status=1;ball_left=0;ball_top=0;
			textcolor(WHITE);
			gotoxy(lefttray,24);
			cprintf("%s",line);
			textcolor(RED);
			gotoxy(left,top);
			cprintf("o");
			up:ball_option=getch();
			if(ball_option == 32 || ball_option == 32)printf("");
			else if(ball_option == 'r' || ball_option == 'R')
			{
				reset_inst();
			}
			else if(ball_option == 'e' || ball_option == 'E')
			{
				exit_inst();
			}
			else
			{
				goto up;
			}
		 }
	}
	else
	{
		ball_top=top;
		ball_left=left;
		return status;
	}
   return status;
}
void line_down(int left,int top, int length)
{
	while(top<length)
	{
		gotoxy(left,top);
		cprintf("%c",179);
		top++;
	}
}
void rectangle(int left, int top, int leftnumber, int topnumber)
{
	int rightnumber, downnumber;
	rightnumber=left;
	downnumber=top;

	while(left<=leftnumber)
	{
		gotoxy(left,top);
		cprintf("*");
		left=left+2;
	}
	left=left-2;

	while(top<=topnumber)
	{
		gotoxy(left,top);
		cprintf("*");
		top++;
	}
	top--;
	while(left>=rightnumber)
	{
		gotoxy(left,top);
		cprintf("*");
		left=left-2;
	}
	left=left+2;
	while(top>=downnumber)
	{
		gotoxy(left,top);
		cprintf("*");
		top--;
	}
}
void space_rectangle(int left, int top, int leftnumber, int topnumber)
{
	int rightnumber, downnumber;
	rightnumber=left;
	downnumber=top;

	while(left<=leftnumber)
	{
		gotoxy(left,top);
		cprintf(" ");
		left=left+2;
	}
	left=left-2;

	while(top<=topnumber)
	{
		gotoxy(left,top);
		cprintf(" ");
		top++;
	}
	top--;
	while(left>=rightnumber)
	{
		gotoxy(left,top);
		cprintf(" ");
		left=left-2;
	}
	left=left+2;
	while(top>=downnumber)
	{
		gotoxy(left,top);
		cprintf(" ");
		top--;
	}
}
void soft_rectangle(int left, int top, int leftnumber, int topnumber,int colour)
{
	int rightnumber = left, downnumber = top;
	textcolor(colour);
	gotoxy(left,top);
	cprintf("%c",218);
	left = left++;
	while(left<leftnumber)
	{
		gotoxy(left,top);
		cprintf("%c",196);
		left=left++;
	}

	gotoxy(left,top);
	cprintf("%c",191);
	top = top++;
	while(top<topnumber)
	{
		gotoxy(left,top);
		cprintf("%c",179);
		top++;
	}

	gotoxy(left,top);
	cprintf("%c",217);
	left=left-1;
	while(left>rightnumber)
	{
		gotoxy(left,top);
		cprintf("%c",196);
		left=left-1;
	}

	gotoxy(left,top);
	cprintf("%c",192);
	top--;
	while(top>=downnumber+1)
	{
		gotoxy(left,top);
		cprintf("%c",179);
		top--;
	}
}

void hard_rectangle(int left, int top, int leftnumber, int topnumber,int colour)
{
	int rightnumber = left, downnumber = top;
	textcolor(colour);
	gotoxy(left,top);
	cprintf("%c",201);
	left = left++;
	while(left<leftnumber)
	{
		gotoxy(left,top);
		cprintf("%c",205);
		left=left++;
	}

	gotoxy(left,top);
	cprintf("%c",187);
	top = top++;
	while(top<topnumber)
	{
		gotoxy(left,top);
		cprintf("%c",186);
		top++;
	}
	textcolor(14);
	gotoxy(left,top);
	cprintf("%c",188);
	left=left-1;
	textcolor(colour);
	while(left>rightnumber)
	{
		gotoxy(left,top);
		cprintf("%c",205);
		left=left-1;
	}
	textcolor(14);
	gotoxy(left,top);
	cprintf("%c",200);
	top--;
	textcolor(colour);
	while(top>=downnumber+1)
	{
		gotoxy(left,top);
		cprintf("%c",186);
		top--;
	}

}


void space_soft_hard_rectangle(int left, int top, int leftnumber, int topnumber)
{
	int rightnumber = left, downnumber = top;

	gotoxy(left,top);
	printf(" ");
	left = left++;
	while(left<leftnumber)
	{
		gotoxy(left,top);
		cprintf(" ");
		left=left++;
	}

	gotoxy(left,top);
	cprintf(" ");
	top = top++;
	while(top<topnumber)
	{
		gotoxy(left,top);
		cprintf(" ");
		top++;
	}

	gotoxy(left,top);
	cprintf(" ");
	left=left-1;
	while(left>rightnumber)
	{
		gotoxy(left,top);
		cprintf(" ");
		left=left-1;
	}

	gotoxy(left,top);
	cprintf(" ");
	top--;
	while(top>=downnumber+1)
	{
		gotoxy(left,top);
		cprintf(" ");
		top--;
	}
}
void exit_inst()
{
	textcolor(RED);
	gotoxy(left,top);
	cprintf("o");
	gotoxy(49,20);
	cprintf("Exit");
	gotoxy(49,21);
	cprintf("Do you want to exit ?(Y/N)");

	close: close=getch();
	if(close == 'Y' || close == 'y')
	{
		finish();
	}
	else if(close == 'N' || close == 'n')
	{
		gotoxy(49,20);
		cprintf("     ");
		gotoxy(49,21);
		cprintf("                            ");
	   //	gotoxy(left,top);
	   //	printf(" ");
		if(level=='1')check1();
		else if(level=='2')check2();
		else if(level=='3')check3();
		else if(level=='4')check4();
	}
	else
	{
		gotoxy(51,22);
		cprintf("Invalid Input");
		getch();
		gotoxy(51,22);
		cprintf("             ");
		goto close;
	}
}
void reset_inst()
{
	if(score!=0)
	{
		gotoxy(49,20);
		cprintf("Reset");
		gotoxy(49,21);
		cprintf("Do you want to reset ?(Y/N)");
		reset: reset=getch();
		if(reset == 'Y' || reset == 'y')
		{
			gotoxy(49,20);
			cprintf("     ");
			gotoxy(49,21);
			cprintf("                           ");

			gotoxy(left,top);
			cprintf(" ");
			while(count<78)
			{
				gotoxy(count,24);
				cprintf(" ");
				count++;
			}
			count=2;

			lefttray=24;left=27;top=23;speed=100;ball_option='q';brick_count=0;
			status=1;ball_left=0;ball_top=0;score=0;life=6;left_dil=15;
			while(offset<40)
			{
				brick[offset]=2;
				offset++;
			}
			offset=0;
			if(level=='1')display1();
			else if(level=='2')display2();
			else if(level=='3')display3();
			else if(level=='4')display4();
			textcolor(WHITE);
			gotoxy(lefttray,24);
			cprintf("%s",line);
			textcolor(RED);
			gotoxy(left,top);
			cprintf("o");
			up:ball_option=getch();
			if(ball_option == 32)printf("");
			else if(ball_option == 'e' || ball_option =='E')exit_inst();
			else goto up;
			if(ball_option!=32)goto up;

		}
		else if(reset == 'N' || reset == 'n')
		{
			gotoxy(49,20);
			cprintf("     ");
			gotoxy(49,21);
			cprintf("                            ");
			check2();
		}
		else
		{
			gotoxy(51,22);
			cprintf("Invalid Input");
			getch();
			gotoxy(51,22);
			cprintf("             ");
			goto reset;
		}
	}
	else
	{
		gotoxy(35,21);
		cprintf("Game to start krle reset baad mai chalega");
		getch();
		gotoxy(35,21);
		cprintf("                                          ");
	}
}
void speed_inst()
{
	gotoxy(49,20);
	cprintf("Speed Sesitivity:");
	gotoxy(49,21);
	cprintf(" 1  2  3  4  5  6");
	speed: speed=getch();
	if(speed == '1' || speed == '2' || speed == '3' || speed == '4' || speed == '5' || speed == '6')
	{
		gotoxy(49,20);
		cprintf("                 ");
		gotoxy(49,21);
		cprintf("                 ");
		speed=speed-48;
		del=200/speed;
	}
	else
	{
		gotoxy(51,22);
		cprintf("Invalid Input");
		getch();
		gotoxy(51,22);
		cprintf("             ");
		goto speed;
	}
}
void level_change()
{
   if(level=='1'&&brick_count==35)
   {
		level='2';
		if(score==350)left=lefttray+2;
		lefttray=24;left=27;top=23;speed=100;ball_option='q';
		status=1;ball_left=0;ball_top=0;life+=2;brick_count=0;
		while(offset<40)
		{
			brick[offset]=2;
			offset++;
		}
		offset=0;
		while(count<78)
		{
			gotoxy(count,24);
			cprintf(" ");
			count++;
		}
		count=2;
		left_dil+=1;
		gotoxy(left_dil,1);
		cprintf("%c%c",3,3);
		left_dil+=1;

		display2();
   }
   else if(level=='2'&&brick_count==55)
   {
		lefttray=24;left=27;top=23;speed=100;ball_option='q';
		status=1;ball_left=0;ball_top=0;level='3';life+=1;brick_count=0;
		while(offset<40)
		{
		brick[offset]=2;
		offset++;
		}
		offset=0;
		while(count<78)
		{
			gotoxy(count,24);
			cprintf(" ");
			count++;
		}
		count=2;

		left_dil+=1;
		gotoxy(left_dil,1);
		cprintf("%c%c",3,3);
		left_dil+=1;

		display3();
   }
   else if(level=='3'&&brick_count==40)
   {
		lefttray=24;left=27;top=23;speed=100;ball_option='q';
		status=1;ball_left=0;ball_top=0;life+=1;brick_count=0;
		while(offset<40)
		{
			brick[offset]=2;
			offset++;
		}
		offset=0;
		level='4';
		while(count<78)
		{
			gotoxy(count,24);
			cprintf(" ");
			count++;
		}
		count=2;
		left_dil+=1;
		gotoxy(left_dil,1);
		cprintf("%c%c",3,3);
		left_dil+=1;

		display4();
   }
}
void smile(int left,int top)
{
	int leftnumber=left+7;
	int topnumber=top+4;
	textbackground(YELLOW);
 //	textcolor(RED);
	while(left<=leftnumber)
	{
		gotoxy(left,top);
		cprintf(" ");
		left++;
	}
	gotoxy(left--,top+=1);
	cprintf("  ");
	gotoxy(left+=3,top+=1);
	cprintf("  ");
	left+=2;
	while(top<=topnumber)
	{
		top++;
		gotoxy(left,top);
		cprintf("  ");
	}
	gotoxy(left-=2,top+=1);
	cprintf("  ");
	gotoxy(left-=2,top+=1);
	cprintf("  ");
	top++;
	while(left>=leftnumber-6)
	{
		left--;
		gotoxy(left,top);
		cprintf(" ");
	}
	gotoxy(left-=2,top-=1);
	cprintf("  ");
	gotoxy(left-=2,top-=1);
	cprintf("  ");
	left-=2;
	while(top>=topnumber)
	{
		top--;
		gotoxy(left,top);
		cprintf("  ");
	}
	gotoxy(left+=2,top-=1);
	cprintf("  ");
	gotoxy(left+=2,top-=1);
	cprintf("  ");

	gotoxy(left+=2,top+=4);
	cprintf("  ");
	gotoxy(left+=2,top+=1);
	cprintf("    ");
	gotoxy(left+=4,top-=1);
	cprintf("  ");
	textbackground(BLACK);
	textcolor(RED);
	gotoxy(left,top-=2);
	cprintf("o");
	gotoxy(left-=5,top);
	cprintf("o");
   /*	while(1)
	{
	 //	textbackground(BLACK);
		if(kbhit())break;
		gotoxy(left,top);
		cprintf("o");
		delay(100);
		textcolor(RED);
		gotoxy(left,top);
		cprintf("%c",3);
		delay(200);
	} */


}
