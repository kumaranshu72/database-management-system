//Header files used------------------------------------------------------------------
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<fstream>
#include<graphics.h>
#include<dos.h>
#include<process.h>
#include<iomanip.h>
#include<ctype.h>
using namespace std;
//imp functions sequence-------------------------------------------------------------
/*1.first()
   1.1make_pass()
   1.2create_database()
   1.3main_menu()
   1.4.getdatabase()
  2.security()
   2.1main_menu()
   2.2getdatabase();
*/
//secondary functions explanation---------------------------------------------------
/*1.basicdesi()-One of the most widely used function in program,used to reset screen
  2.getopt()-it provides the base of getting options from user.
*/
//The program uses graphics in c++ & file handling topics
//Some function's prototype------------------------------------------------------------
void create_database();
int getopt();
void main_menu();
//*********************************************************
//class-to store details of field name
class base
{
  char fnam[21];
  int type;
public:
  void gett()
  { cout<<"Enter Type Of The Field: \n1.Integer(Int)\n2.Character(Char)\n3.Decimal(Dec)"<<endl;
    cin>>type;
    cout<<"Enter The Field Name: ";
    gets(fnam);
  }
  int rett()
  {return type;}
  void show()
  {cout<<fnam;
  }
};
//----------function to write field in file---------------------------------------------
void fwrite(char *tabname)//storing entries into file
{

     fstream f(tabname,ios::out|ios::binary);
     base a;
     int ch;
     do
     { a.gett();
       f.write((char *)&a,sizeof(base));
       cout<<"Press 9 To Exit Or Press Any Other Key To Continue.... "<<endl;
       cin>>ch;
     }while(ch!=9);
    f.close();
}
//------------function to read field data from file--------------------------------
void fread(char *tabname)//reading entries from file
{

     fstream f(tabname,ios::in|ios::binary);
     base a;
     f.read((char*)&a,sizeof(base));
     gotoxy(0,5);
     while(!f.eof())
     {
      a.show();
      cout<<setw(10);
      f.read((char*)&a,sizeof(base));
     }
     f.close();
}
//------to display the basic design of the program------------------------------
void basicdesi()
{
 closegraph();
 clrscr();
 int gd=DETECT,gdr;
 initgraph(&gd,&gdr," ");
  struct dostime_t t;      //For display of time on side of screen
 _dos_gettime(&t);
  printf("\t\t\t\t\t\t\t\t\t   %2d:%2d\n", t.hour, t.minute);

 setbkcolor(9);
 setcolor(3);
 setcolor(GREEN);
 setfillstyle(SOLID_FILL,GREEN);
 bar3d(getmaxx()-40,17,getmaxx(),getmaxy(),0,0);
 setfillstyle(SOLID_FILL,BLUE);
 bar3d(0,0,getmaxx()-40,10,0,0);
 setcolor(11);
 for(int i =0;i<300;i=i+50)
 {circle(0,0,i+200);
 }
 settextstyle(6,0,1);
 setcolor(RED);
 outtextxy(getmaxx()-80,10,"9.Close");
 outtextxy( getmaxx()-80,25,"8.Back");
 setcolor(RED);
 for(i=0;i<=12;i=i+6)
 line(0,getmaxy()-i,getmaxx(),getmaxy()-i);
}
//---To ask for security option from user-------------------------------------
void make_pass()
{
  delay(100);
  basicdesi();
  char name[21];
  cout<<"\n\tPlease Enter Your Name: ";
  gets(name);
pos67:  cout<<"\n\tPlease Enter A Password: ";
  char passf[21];
  int f=1;
  int i=0;
  while(f)
  {
   passf[i]=getch();
   if(passf[i]==13)break;
   if(passf[i]==8)
   {
    basicdesi();
    goto pos67;
   }
   else
   { cout<<"*";
     i++;
   }
  }
  passf[i]='\0';
  for(i=0;passf[i]!='\0';i++) 						//encryption level 1
  {  passf[i]=passf[i]+2;
  }
  passf[i]='\0';
  fstream fpa("basexpa.txt",ios::out);					//password file
  fpa<<passf;
  fpa.close();
  fstream fna("basexname.txt",ios::out);					//name file
  fna<<name;
  fna.close();
  cout<<endl<<"Done!";
}
//---function called when program is run for the first time-------------------
void first()
{
  int gd=DETECT,gdr;
  initgraph(&gd,&gdr," ");
  setbkcolor(9);
  rectangle(0,20,300,40);
  cout<<"\nW E L C O M E ,\n We Are Here To Help You In Maintaining Your Data."<<endl;
  delay(500);
  gotoxy(70,2);
  cout<<endl;
  setcolor(5);
  for(int i=0;i<getmaxx()-70;i=i+10)
 { circle(i,getmaxy()-10,10);
   delay(0);

 }
 setcolor(11);
 for(i =0;i<300;i=i+50)
 {circle(0,0,i+200);
 }
 setcolor(YELLOW);
 settextstyle(3,0,3);
 outtextxy(getmaxx()-60,getmaxy()-26,"DAT");
  gotoxy(35,12);
  cout<<"Loading..."<<endl;
  setcolor(BLUE);
  for( i=0;i<10;i++)
  { circle(getmaxx()/2-50+(i*10),200,2);
    delay(300);
  }
  gotoxy(0,0);
  closegraph();
  clrscr();
  basicdesi();
  cout<<"\nMake This Program Yours!! "<<endl;
  for( i=0;i<getmaxx()-70;i=i+10)
 {
   circle(i,getmaxy()-10,10);
   delay(20);
 }
 setcolor(11);
 for(i =0;i<300;i=i+50)
 {circle(0,0,i+200);
 }
 setcolor(YELLOW);
 settextstyle(3,0,3);
 outtextxy(getmaxx()-60,getmaxy()-26,"DAT");

  delay(500);
      make_pass();
      basicdesi();
      create_database();
}
void create_database()
{
  cout<<"Enter Database Name:  ";
  char namedata[50];
  gets(namedata);
  fstream f1("basex89.txt",ios::app);				//stores names of databases
  f1<<namedata<<endl;
  cout<<"\n\t\t\t[  Database Created  ]"<<endl;
  delay(500);
  f1.close();
  strcat(namedata,".txt");
  fstream f2(namedata,ios::out);
  f2.close();
  main_menu();
}
//----------To work on databases---------------------------------------------------
void getdatabase()
{
pos:	basicdesi();
	fstream f("basex89.txt",ios::in);
	char data[21];
	int j=1;
	f>>data;
	cout<<"\n\n\nDatabases Present are :-"<<endl;
	if(data[0]=='\0')
	{
	  outtextxy(10,100,"No Database is Present !!");
	  getch();
	  main_menu();
	}
	else
	{
	while(!f.eof())
	{
	 cout<<"\t"<<j<<"."<<data<<endl;
	 f>>data;
	 j++;
	}
	f.close();
	int opt=getopt();
	if(opt==8)main_menu();
	if(opt==9)exit(0);
	if(opt<j)
	{
posy:	  char a[21];
	  fstream f("basex89.txt",ios::in);
	  strcpy(a,"");
	  for(int i=1;i<=opt;i++)
	  f>>a;
	  f.close();
	  basicdesi();
	  setcolor(GREEN);
	  outtextxy(0,40,a);
	  strcat(a,".txt");
	  fstream f1(a,ios::in);
	  int j=1;
	  char da[81];
	  f1>>da;
	  cout<<"\n\n\nTables:-"<<endl;
	  while(!f1.eof())
	 {
	  cout<<"\t"<<da<<endl;
	  f1>>da;
	  j++;
	 }
	  cout<<"\t"<<da<<endl;
	  f.close();
	  gotoxy(2,18);
	  cout<<"2.View Table    3.Add Tables    4.Delete Tables"<<endl;
	  int opt=getopt();
	  if(opt==8)goto pos;
	  if(opt==9)exit(0);
	  switch(opt)
	  {
	  default :cout<<"Wrong Option!!";
		    getch();
		    goto posy;
		    break;
	   case 4:basicdesi();
		  fstream f12(a,ios::in);
		  int k=1;
		  char t[81];
		  f12>>t;
		  cout<<"\n\n\nTables :-"<<endl;
		    if(t[0]=='\0')
		    {
		      outtextxy(10,100,"No Table is Present!!");
		      getch();
		      goto posy;
		    }
		   else
		   {
		 while(!f12.eof())
		 {
		   cout<<"\t"<<k<<"."<<t<<endl;
		   f12>>t;
		   k++;
		 }
		   cout<<"\t"<<k<<"."<<t<<endl;
		   f12.close();
		   int option=getopt();
		   if(option==8)goto posy;
		   if(option==9)exit(0);
		  else
		   {
		    char e[81];
		    fstream f13(a,ios::in);
		    strcpy(e,"");
		    for(int i=1;i<=option;i++)
		    f13>>e;
		    f13.close();
		    basicdesi();
		    outtextxy(0,40,"Table Selected : ");
		    cout<<e;
		    outtextxy(10,50,e);
		    settextstyle(3,0,6);
		    setcolor(YELLOW);
		    outtextxy(0,getmaxy()/2,"Press 1 To Delete This Table Or Press Any Other Key To Go Back...");
		    int opt=getopt();
		    if(opt==1)
		    {
		    fstream f14(a,ios::in);
		    fstream f15("tempx8.txt",ios::out);
		    char del[21];
		    while(!f14.eof())
		   {
		   f14>>del;
		   if(strcmp(del,e)==0)continue;
		   f15<<del<<endl;
		   }
		   char oep[21];
		   strcpy(oep,e);
		   strcat(e,".dat");
		   strcat(oep,"v.txt");
		   remove(e);
		   remove(oep);
		   f14.close();
		   f15.close();
		   remove(a);
		   rename("tempx8.txt",a);
		   outtextxy(100,200,"Done!");
		   goto posy;
	  }
		 }

		 }
		  break;
	   case 3:basicdesi();
		  cout<<"\t\t\t[ ADD Tables ]"<<endl;
		  cout<<"Enter Table Name : ";
		  char tabname[81];
		  gets(tabname);
		  cout<<"\n[ Success ]"<<endl;
		  delay(100);
		  fstream f1(a,ios::app);
		  f1<<endl<<tabname;
		  strcat(tabname,".dat");
		  fwrite(tabname);
		  cout<<"\t\t\t[ Table Created ]"<<endl;
		  delay(100);
		  goto posy;

	    case 2:
posx:     	    basicdesi();
		    fstream f7(a,ios::in);
		    int j=1;
		    char da[81];
		    f7>>da;
		    cout<<"\n\n\nTables Present Are :-"<<endl;
		    if(da[0]=='\0')
		    {
		      outtextxy(10,100,"No Table Is Present!!");
		      getch();
		      goto posy;
		    }
		    else
		    {
		    while(!f7.eof())
		 {
		   cout<<"\t"<<j<<"."<<da<<endl;
		   f7>>da;
		   j++;
		 }
		   cout<<"\t"<<j<<"."<<da<<endl;
		   f7.close();
		   int option=getopt();
		   if(option==8)
		   goto posy;
		   if(option==9)exit(0);
		   if(option<=j)
		   {
		   char nbt[80];
		   fstream f8(a,ios::in);
		   strcpy(nbt,"");
		   for(int i=1;i<=option;i++)
		   {  f8>>nbt; }
		   f8.close();
		   basicdesi();
		   outtextxy(0,40,nbt);
		   char nbtv[81];
		   strcpy(nbtv,nbt);
		   strcat(nbtv,"g.txt");
		   strcat(nbt,".dat");

posp:              fread(nbt);
		   fstream fxy(nbtv,ios::nocreate|ios::in);
		   int ch=0;
		    cout<<endl<<endl;
		    if(!fxy)
		   { cout<<endl<<"[  Sorry!  ] There Is No Data In This Table! "<<endl;
		    ch++;
		   }
		   fxy.close();
		   line(0,50,getmaxx(),50);
		   if(ch==0)
		   {
		      fstream f6(nbtv,ios::in);
		      char aa;
		      while(!f6.eof())
		      {
		       aa=f6.get();
		       cout<<aa;
		      }
		      f6.close();


		   }

		   gotoxy(2,18);
		   cout<<"1.Enter Record    2.Delete Record"<<endl;
		   int opt=getopt();
		   if(opt!=1&&opt!=2&&opt!=8&&opt!=9)
		   { cout<<"\n\t\t[ Wrong Option ! ]"<<endl;
		     delay(100);
		     basicdesi();
		     goto posp;

		   }
		   if(opt==8)goto posx;
		   if(opt==9)exit(0);
		   int op;
		   if(opt==1)
		   {
		    do

		   {
recpos:		     basicdesi();
		     fstream fxf(nbt,ios::in|ios::binary);
		     base ac;
		     fxf.read((char*)&ac,sizeof(base));
		     fstream f4(nbtv,ios::app);
		     char val[81];
		     while(!fxf.eof())
		   {
		     ac.show();
		     if(ac.rett()==1)
		     {
		     cout<<"(Int)\t:";
		     gets(val);
		     for(int ns=0;val[ns]!='\0';ns++)
		     if(isdigit(val[ns])==0)
		     {cout<<"\n Wrong Value Try Again!! ";
		     delay(100);
		     fxf.close();
		     f4.close();
		     goto recpos;
		     }
		     }
		     else
		     if(ac.rett()==2)
		     {
		     cout<<"(Char)\t:";
		     gets(val);
		     }
		     else
		     if(ac.rett()==3)
		     {
		     cout<<"(Dec)\t:";
		     gets(val);
		     for(int ns=0;val[ns]!='\0';ns++)
		     if(isdigit(val[ns])!=0||val[ns]=='.');
		     else
		     {cout<<"\n Wrong Value Try Again!! ";exit(0);}
		     }
		     f4<<val<<setw(10);
		     cout<<endl;
		     fxf.read((char*)&ac,sizeof(base));
		   }
		      f4<<endl;
		      cout<<"Press 8 To End Or Any Other Integer Key To Continue! "<<endl;
		      op=getopt();
		      f4.close();
		      fxf.close();
		     } while(op!=8);
		      f.close();
		      if(op==8){basicdesi();goto posp;}
		     }
		else
		if(opt==2)
		{
		  basicdesi();
		  fstream fz(nbtv,ios::in);
		  fstream fx("temp_tab.txt",ios::out);
		   char ab;
		   cout<<"Records Present, Please Choose Your Row No.: "<<endl;
		   while(!fz.eof())
		   {
		    ab=fz.get();

		    cout<<ab;
		   }
		   fz.close();
		   fstream fzz(nbtv,ios::in);
		   int tur=getopt();
		   cout<<"< WARNING! >,Do You Want To Delete Record No." <<tur<<", Press 1 To Continue... Or Any Other Key To Cancel!";
		   int sel=getopt();
		   if(sel==1)
		  {
		   int j=1;
		   char rec;
		      do
		     { rec=fzz.get();
		       if(rec=='\n')j++;
		       if(j!=tur)
		       fx<<rec;
		       if(fzz.eof()){break;}
		     }while(rec!=13);
		  fx.seekp(0,ios::beg);
		  fx.close();
		  fzz.close();
		  remove(nbtv);
		  rename("temp_tab.txt",nbtv);
		   basicdesi();
		   goto posp;
		  }
		}
		else goto posp;
	      }
	       else
	      {
	      cout<<"Wrong Option";
	      getch();
	      goto posy;
	      }
	     }
	 }
	}
	 else
	 {
	    cout<<"\tWrong Option!! ";
	    getch();
	    goto pos;
	  }
	  }
}
//first function to run,asks for password-------------------------------------------
void security()
{
   int gd=DETECT,gr;
   initgraph(&gd,&gr,"");
   setbkcolor(WHITE);
   setfillstyle(SOLID_FILL,LIGHTBLUE);
   setcolor(LIGHTBLUE);
   circle(getmaxx()/2,getmaxy()/2,50);
   line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
   floodfill(getmaxx()/2,getmaxy()/2-10,LIGHTBLUE);
   floodfill(getmaxx()/2,getmaxy()/2+10,LIGHTBLUE);
   settextstyle(3,0,2);
   setcolor(RED);
   outtextxy(getmaxx()/2-10,150,"DAT");
   delay(1200);
   closegraph();
pos: basicdesi();
 fstream fgetp("basexpa.txt",ios::in);
 char pass[21];
 fgetp>>pass;
 for(int i=0;pass[i]!='\0';i++)
 pass[i]=pass[i]-2;
 pass[i]='\0';
 fgetp.close();
 fstream fgnam("basexname.txt",ios::in);
 char name[21];
 fgnam>>name;
 fgnam.close();
  setcolor(RED);
 for(i=0;i<=320;i=i+80)
 circle(getmaxx(),getmaxy(),i);
 gotoxy(30,8);
 setcolor(5);
 circle(getmaxx()/2-10,120,60);
 circle(getmaxx()/2-5,120,50);
 cout<<" HELLO "<<strupr(name);
 setcolor(YELLOW);
 settextstyle(8,0,1);
 outtextxy(getmaxx()/2-50,getmaxy()/2-60,"Password: ");
 rectangle(getmaxx()/2-50,getmaxy()/2-20,getmaxx()/2+50,getmaxy()/2+5);
 gotoxy(35,15);
 char passf[21];
 i=0;
  while(1)
  {
   passf[i]=getch();
   if(passf[i]==13)break;
   if(passf[i]==8)
   {
    goto pos;
   }

   else
   { cout<<"*";
   i++;
   }
  }
  passf[i]='\0';
  int chk=1;
  i=0;
  while(pass[i]!='\0')
  {
   if(pass[i]!=passf[i]){chk=0;break;}
   i++;
  }
  setcolor(BLUE);
    for( i=0;i<8;i++)
  {
   circle(getmaxx()/2-50+(i*10),260,2);
    delay(100);
  }
  if(chk==1)
  {
   main_menu();
  }
  else
  {
   gotoxy(35,14);
   cout<<"Bye user! You Entered Wrong Password!";delay(2000);exit(0);
  }
}
//--Main menu function for program---------------------------------------
void main_menu()
{
  basicdesi();
  setcolor(YELLOW);
  settextstyle(3,0,3);
  circle(getmaxx()/2,10,6);
  outtextxy(getmaxx()/2-40,10,"DAT");
  setcolor(3);
  settextstyle(3,0,10);
  outtextxy(20,20,"WELCOME");
  gotoxy(2,18);
  cout<<"1.View Database     2.Create Database    3.Delete Database     5.Reset"<<endl;
  settextstyle(5,0,2);
  setcolor(YELLOW);
  outtextxy(getmaxx()-100,getmaxy()-50,"4.Credits");
  int opt=getopt();
  if(opt==9)exit(0);
  switch(opt)
  {
      case 1:getdatabase();
	     break;
      case 2:basicdesi();
	     create_database();
	     break;
      case 5:basicdesi();
	     cout<<"Press 1 to Delete!"<<endl;
	     int x=getopt();
	     if(x==1){remove("basex89.txt");exit(0);}
	     else main_menu();
	     break;
      case 4:basicdesi();
	     settextstyle(7,0,6);
	     setcolor(RED);
	     outtextxy(0,0,"CREDITS");
	     gotoxy(0,20);
	     cout<<"Developed By DAT , All Rights Reserved." ;
	     outtextxy(40,100,"CEO: Anshu Kuma,Tushar Garg & Dipali Dubeyr");
	     getch();
	     main_menu();
      case 3:basicdesi();
	fstream f("basex89.txt",ios::in);
	char data[21];
	int j=1;
	f>>data;
	cout<<"\n\n\nDatabase Present"<<endl;
	if(data[0]=='\0')
	{
	  outtextxy(15,100,"No Database Is Present!! ");
	  getch();
	  main_menu();
	}
	else
	{
	while(!f.eof())
	{
	 cout<<"\t"<<j<<"."<<data<<endl;
	 f>>data;
	 j++;
	}
	f.close();
	int opt=getopt();
	if(opt==8)main_menu();
	if(opt==9)exit(0);
	else
	{
	  char a[21];
	  fstream f("basex89.txt",ios::in);
	  strcpy(a,"");
	  for(int i=1;i<=opt;i++)
	  {  f>>a; }
	  f.close();
	  basicdesi();
	  outtextxy(0,40,"Database Selected : ");
	  outtextxy(10,50,a);
	  settextstyle(3,0,6);
	  setcolor(YELLOW);
	  outtextxy(0,getmaxy()/2,"Press 1 To Delete This Database Or Press Any Other Key To Go Back!");
	  int opt=getopt();
	  if(opt==1)
	 {
	  fstream f2("basex89.txt",ios::in);
	  fstream f3("tempx89.txt",ios::out);
	  char del[21];
	  while(!f2.eof())
	  {
	    f2>>del;
	    if(strcmp(del,a)==0){continue;}
	    f3<<del<<endl;
	  }
	  f2.close();
	  f3.close();
	  strcat(a,".txt");
	  remove(a);
	  remove("basex89.txt");
	  rename("tempx89.txt","basex89.txt");
	  outtextxy(100,200,"[ DONE ]");
	  delay(100);
	  main_menu();
	  }

	  else  main_menu();
    }
    }
  }
       defalut:cout<<"\tWrong Option!!";
	       getch();
	       main_menu();
}
//----to get option from user---------------------------------------------------
int getopt()
{
	gotoxy(2,20);
	textbackground(BLACK);
	textcolor(YELLOW);
	cout<<"Please Choose Your Option: ";
	int opt;
	cin>>opt;
	return opt;
}
//****************************************************
//main---
void main()
{
	clrscr();
	fstream fx1("basex89.txt",ios::nocreate|ios::app);
	if(!fx1)
	first();
	else
	security();
	getch();
}

