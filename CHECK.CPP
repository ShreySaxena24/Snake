//#############################-HEADER FILES-###############################
#include<fstream.h>
#include<conio.h>
#include<graphics.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<dos.h>
#include<string.h>
//#############################-USER DEFINED FUNCTIONS-#######################
void fsnake();
void controls();
void addition();
void display();
void search();
void deletion();
void modification();
void highsnake();
int idgen();
//##############################-GLOBAL VARIABLES-#############################
fstream file;
fstream file2;
fstream file3;
fstream sf1;

//###############################-EMPLOYEE-##################################
struct tade
{
	int dd;
	int mm;
	int yy;
};
class employee
{
	public:
	char name[40];
	tade d1;
	int idno;
	void display_str();
	void dateval();

}e1;
//class employee's functions.............
void employee::display_str()
{
		cout<<idno<<"\t"<<name<<"\t\t"<<d1.dd<<"/"<<d1.mm<<"/"<<d1.yy<<endl;
}
void employee::dateval()
{
	while(1)
	{
		cout<<"Enter your joining date dd/mm/yy"<<endl;
		cin>>d1.dd;
		cin>>d1.mm;
		cin>>d1.yy;
		if(d1.yy>0)
		{
			if(d1.mm<=12)
			{
				if(d1.mm==4||d1.mm==6||d1.mm==9||d1.mm==11)
				{
					if(d1.dd>0&&d1.dd<=30)
					{
						break;
					}
					else
					{
						cout<<"invalid date try again"<<endl;
						getch();
						continue;
					}

				}
				if(d1.mm==2)
				{
					if(d1.yy%4==0)
					{
						if(d1.dd>0&&d1.dd<=29)
						{
							break;
						}
						else
						{
							cout<<"invalid date try again"<<endl;
							getch();
							continue;
						}
					}
					else
					{
						if(d1.dd>0&&d1.dd<=28)
						{
							break;
						}
						else
						{
							cout<<"invalid date try again"<<endl;
							getch();
							continue;
						}
					}
				}
				if(d1.mm==1||d1.mm==3||d1.mm==5||d1.mm==7||d1.mm==8||d1.mm==10||d1.mm==12)
				{
					if(d1.dd>0&&d1.dd<=31)
					{
						break;
					}
					else
					{
						cout<<"invalid date try again"<<endl;
						getch();
						continue;
					}
				}
				else
				{
					cout<<"invalid date try again"<<endl;
					getch();
					continue;
				}
			}
			else
			{
				cout<<"invalid date try again"<<endl;
				getch();
				continue;
			}
		}
		else
		{
			cout<<"invalid date try again"<<endl;
			getch();
			continue;
		}
	}
}
//############################-MAIN FRAME OF PROJECT-##############################
class mf
{
	private:
		char a;
		int b;
		int c;
	public:
		mf()
		{
			a='w';
			b=1;
			c=1;
		}
		int make(int,int);
		int menu();
		void ent();
		void storage();
		void data();
		void modify();
		void body();
		void typemaster();
		void snakemenu();
		~mf()
		{}
};
//........................class mf's functions..........................................................
int mf::make(int x=1,int y=0)
{
	char box1[20],box2[20],box3[20];
	cleardevice();
	setbkcolor(BLACK);
	setcolor(WHITE);
	if(y==1)
	{
		strcpy(box1,"storage");
		strcpy(box2,"entertaiment");
		strcpy(box3,"exit");
	}
	if(y==2)
	{
		strcpy(box1,"enter a new employee");
		strcpy(box2,"stored data");
		strcpy(box3,"back to menu");
	}
	if(y==3)
	{
		strcpy(box1,"snake the game");
		strcpy(box2,"typemaster");
		strcpy(box3,"back to menu");
	}
	if(y==4)
	{
		strcpy(box1,"watch stored data");
		strcpy(box2,"change a employee");
		strcpy(box3,"back");
	}
	if(y==5)
	{
		strcpy(box1,"delete a employee");
		strcpy(box2,"modify a employee");
		strcpy(box3,"back");
	}
	if(y==6)
	{
		strcpy(box1,"play");
		strcpy(box2,"scores");
		strcpy(box3,"back");
	}
	outtextxy(120,120,box1);
	rectangle(100,100,400,150);
	outtextxy(120,270,box2);
	rectangle(100,250,400,300);
	outtextxy(120,420,box3);
	rectangle(100,400,400,450);
	setfillstyle(1,RED);
	if(x==1)
	{
		floodfill(250,129,WHITE);
	}
	if(x==2)
	{
		floodfill(250,279,WHITE);
	}
	if(x==3)
	{
		floodfill(250,429,WHITE);
	}
	return 0;
}
//................................................................................
void mf::snakemenu()
{
	cleardevice();
	b=1;
	c=6;
	int value4=1;
	make(b,c);
	a=getch();
	while(1)
	{
		a=getch();
		if(a=='w')
		{
			if(b>1)
				b--;
			make(b,c);
			value4=1;
		}
		if(a=='s')
		{
			if(b<3)
				b++;
			make(b,c);
			value4=1;
		}
		if(a==' ')
		{
			if(b==1)
			{
				cleardevice();
				fsnake();
				b=1;
				c=6;
			      //	break;
			      value4=1;
			}
			if(b==2)
			{
				cleardevice();
				cout<<"scores"<<endl;
				highsnake();
				b=2;
				c=6;
			      //	break;
			      value4=1;
			}
			if(b==3)
			{
				value4=0;
			}
		}
		if(value4==1)
			continue;
		if(value4==0)
			break;
	}
}
//..................................................................................
void mf::data()
{
	cleardevice();
	b=1;
	c=4;
	int value2=1;
	make(b,c);
	a=getch();
	while(1)
	{
		make(b,c);
		a=getch();
		if(a=='w')
		{
			if(b>1)
				b--;
			make(b,c);
			value2=1;
		}
		if(a=='s')
		{
			if(b<3)
				b++;
			make(b,c);
			value2=1;
		}
		if(a==' ')
		{
			if(b==1)
			{
				cleardevice();
				display();
			      //	break;
			      value2=1;
			}
			if(b==2)
			{
				cleardevice();
				char pas[10];
				int pl=3,proof=0;
				while(1)
				{
					clrscr();
					if(pl>0)
					{
						cleardevice();
						if(pl==3)
							setcolor(GREEN);
						if(pl==2)
							setcolor(YELLOW);
						if(pl==1)
							setcolor(RED);
						outtextxy(0,80,"enter password");
						cout<<"\n\n\n\n\n\n"<<endl;
						for(int i=0;i<10;i++)
						{

							if(i==0)
							{
								cout<<" ";
								setcolor(WHITE);
								rectangle(0,100,300,130);
							}
							pas[i]=getch();
							cout<<'*';
							if(pas[0]=='1' && pas[1]=='1' && pas[2]=='1')
							{
								proof=1;
								break;
							}
						}
						if(proof!=1)
						{
							pl--;
						}
					}
					outtextxy(0,140,"loading");
					sleep(1);
					outtextxy(60,140,".");
					sleep(1);
					outtextxy(67,140,".");
					sleep(1);
					outtextxy(74,140,".");
					sleep(1);
					outtextxy(81,140,".");
					sleep(1);
					if(pas[0]=='1' && pas[1]=='1' && pas[2]=='1')
					{
						modify();
						pl=3;
					}
					if(pl==3)
						break;
					if(pl<3 && pl>0)
					{
						clrscr();
						cleardevice();
						cout<<endl<<"\t\twrong password"<<endl;
						cout<<endl<<"you have "<<pl<<"chances remaining"<<endl;
						getch();
					}
					if(pl==0)
					{
						clrscr();
						cleardevice();
						cout<<endl<<"no chances remaining"<<endl;
						getch();
						break;
					}

				}
				b=1;
				c=4;
			      //	break;
				value2=1;
			}
			if(b==3)
			{
				value2=0;
			}
		}
		if(value2==1)
			continue;
		if(value2==0)
			break;
	}
}
//....................................................................................
void mf::modify()
{
	cleardevice();
	b=1;
	c=5;
	int value3=1;
	make(b,c);
	a=getch();
	while(1)
	{
		make(b,c);
		a=getch();
		if(a=='w')
		{
			if(b>1)
				b--;
			make(b,c);
			value3=1;
		}
		if(a=='s')
		{
			if(b<3)
				b++;
			make(b,c);
			value3=1;
		}
		if(a==' ')
		{
			if(b==1)
			{
				cleardevice();
				deletion();
			      //	break;
			      value3=1;
				getch();
			}
			if(b==2)
			{
				cleardevice();
				modification();
			      //	break;
			      value3=1;
				 getch();
			}
			if(b==3)
			{
				value3=0;
			}
		}
		if(value3==0)
			break;
		if(value3==1)
			continue;
	}
}
//..................................................................................
void mf::storage()
{
	cleardevice();
	b=1;
	c=2;
	int value1=1;
	make(b,c);
	a=getch();
	while(1)
	{
		make(b,c);
		a=getch();
		if(a=='w')
		{
			if(b>1)
				b--;
			make(b,c);
			value1=1;
		}
		if(a=='s')
		{
			if(b<3)
				b++;
			make(b,c);
			value1=1;
		}
		if(a==' ')
		{
			if(b==1)
			{
				cleardevice();
				addition();
				value1=1;
			      //	break;
			}
			if(b==2)
			{
				cleardevice();
				data();
				b=1;
				c=2;
				value1=1;
			      //	break;
			}
			if(b==3)
			{
				value1=0;
			}
		}
		if(value1==0)
			break;
		if(value1==1)
			continue;
	}
}
//.............................................................................
void mf::ent()
{
	cleardevice();
	b=1;
	c=3;
	cout<<"welcome to ent.."<<endl;
	make(b,c);
	while(1)
	{
		make(b,c);
		a=getch();
		if(a=='w')
		{
			if(b>1)
				b--;
			make(b,c);
		}
		if(a=='s')
		{
			if(b<3)
				b++;
			make(b,c);
		}
		if(a==' ')
		{
			if(b==1)
			{
				cleardevice();
				snakemenu();
			      //	break;
			}
			if(b==2)
			{
				cleardevice();
				typemaster();
			      //	break;
			}
			if(b==3)
			{
				return;
			}
		}
	}
}
//....................................................................................
void mf::typemaster()
{
	closegraph();
	clrscr();
	int le=0;
	clock_t start,end;
	char wl[38],cl[38];
	strcpy(cl,"the quick fox jumped over the lazy dog");
	cout<<"\t\t\twelcome to the type master";
	cout<<endl<<endl<<"start writting the given paragraph right after pressing any key"<<endl;
	getch();
	cout<<"\n\n\n"<<cl<<"\n\n";
	start=clock();
	gets(wl);
	end=clock();
	cout<<endl<<"\t\t\t\tloading";
	for(int i=0;i<3;i++)
	{
		sleep(1);
		cout<<'.';
	}
	for(int j=0;j<38;j++)
	{
		if(wl[j]!=cl[j])
			le++;
	}
	clreol();
	cout<<endl<<"your time was "<<(end-start)/CLK_TCK<<" seconds"<<endl;
	cout<<"no. of incorrect words are "<<le;
	getch();
	int gdriver=DETECT, gmode;
	initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
}
//...................................................................................
int mf::menu()
{
	int value=1;
	make(b,c);
	a=getch();
	if(a=='w')
	{
		if(b>1)
			b--;
		make(b,c);
		value=1;
	}
	if(a=='s')
	{
		if(b<3)
			b++;
		make(b,c);
		value=1;
	}
	if(a==' ')
	{
		if(b==1)
		{
			storage();
			b=1;
			c=1;
			value=1;
		}
		if(b==2)
		{
			ent();
			b=1;
			c=1;
			value=1;
		}
		if(b==3)
		{
			cleardevice();
			settextstyle(1,0,1);
			outtextxy(100,100,"thankyou");
			getch();
			value=0;
		}
	}
	if(value==0)
		return 0;
	if(value==1)
		return 1;
	else
		return 1;
}
//..................................................................................
void mf::body()
{
	b=1;
	c=1;
	int ce=0;
	controls();
	while(1)
	{
	       ce=menu();
	       if(ce==0)
			break;
	}
}
//#################################-SNAKE-#####################################//
class snake
{
	private:
	int xf[16];
	int yf[16];
	int f[16];
	public:
	int x;
	int y;
	int k;
	void acceptsnk()
	{
		x=100;
		y=100;
		k=0;
	}
	void accfood();
	int food(int,int);
	char move(char);
	void snkcontrols();
};
//...........class to store information of the player.............................................
class snakeinfo
{       public:
	char sname[20];
	int stime;
	void display()
	{
		cout<<" * "<<sname<<"\t"<<stime<<" sec"<<endl;
	}
}si1;
//.........................................................................................
void snake :: accfood()
{
	int n;
	srand(time(0));
	for (n=0;n<16;n++)
	{
		xf[n]=(1+(rand()%18))*25;
		yf[n]=(1+(rand()%18))*25;
	}
	for(n=0;n<16;n++)
	{
		f[n]=0;
	}
}
//...................................................................................
int snake:: food(int x,int y)
{
	for(int q=0;q<16;q++)
	{
		setcolor(RED);
		setfillstyle(1,RED);
		if(f[q]==0)
		{
			circle(xf[q],yf[q],3);
			floodfill(xf[q],yf[q],RED);
		}
		setcolor(WHITE);
	}
	for(q=0;q<16;q++)
	{
		if(x==xf[q] && y==yf[q])
		{
			f[q]=1;
			k++;
		}
	}
	return 0;
}
//.....................................................................................
char snake::move(char mo)
{
	 int j;
	if(mo=='w')
	{
		for(j=0;j<5;j++)
		{
			if(x>0&&y>0)
			{	x=x;
				y=y-5;
			}
			circle(x,y,3);
			setfillstyle(1,GREEN);
			floodfill(x,y,WHITE);
			food(x,y);
			delay(100);
				if(j<1)
			cleardevice();
		}
	}
	if(mo=='s')
	{
		for(j=0;j<5;j++)
		{
			if(x<getmaxx()&&y<getmaxy())
			{
				x=x;
				y=y+5;
			}
			circle(x,y,3);
			setfillstyle(1,GREEN);
			floodfill(x,y,WHITE);
			food(x,y);
			delay(100);
			if(j<1)
				cleardevice();
		}
	}
	if(mo=='a')
	{
		for(j=0;j<5;j++)
		{
			if(x>0&&y>0)
			{
				x=x-5;
				y=y;
			}
			circle(x,y,3);
			setfillstyle(1,GREEN);
			floodfill(x,y,WHITE);
			food(x,y);
			delay(100);
			if(j<1)
				cleardevice();
		}
	}
	if(mo=='d')
	{
		for(j=0;j<5;j++)
		{
			if(x<getmaxx()&&y<getmaxy())
			{
				x=x+5;
				y=y;
			}
			circle(x,y,3);
			setfillstyle(1,GREEN);
			floodfill(x,y,WHITE);
			food(x,y);
			delay(100);
			if(j<1)
				cleardevice();
		}
	}
	return 0;
}
//.................................................................................
void highsnake()
{
	sf1.open("snk.dat",ios::in|ios::binary);
	cout<<" NAMES    TIME      "<<endl;
	while(sf1.read((char*)&si1,sizeof(si1)))
	{
		si1.display();
	}
	sf1.close();
}
//..................................................................................
void snake::snkcontrols()
{
	cleardevice();
	setbkcolor(BLUE);
	settextstyle(6,0,0);
	setcolor(RED);
	outtextxy(50,50,"1. use W to move up");
	outtextxy(50,100,"2. use s to move down");
	outtextxy(50,150,"3. use A to move left");
	outtextxy(50,200,"4. use D to move right");
	outtextxy(50,250,"5. EAT ALL the apples to finish");
	outtextxy(50,300,"6. the time starts just after the controls");
	settextstyle(0,0,1);
	outtextxy(400,400,"press any key to continue...");
	getch();
}


//##################################-MAIN FUNCTION-############################//
void main()
{       //small main func.//
	int gdriver=DETECT, gmode;
	initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
	mf m1;
	m1.body();
}
//#######################-USER DEFINED FUNCTIONS_###############################
void modification()
{
	closegraph();
	char ch2;
	int tempid1;
	int modidno;
	tempid1=idgen();
	file.open("employee.dat",ios::in|ios::binary);
	file3.open("temp.dat",ios::out|ios::binary);
	cout<<"enter the employee no. to modify"<<endl;
	cin>>modidno;
	while(file.read((char*)&e1,sizeof(e1)))
	{
		file.read((char*)&e1,sizeof(e1));
		if(modidno!=e1.idno)
		{
			file3.write((char*)&e1,sizeof(e1));
		}
		if(modidno==e1.idno)
		{
			e1.display_str();
			cout<<"is this the employee you want to modify"<<endl;
			cin>>ch2;
			ch2=tolower(ch2);
			if(ch2=='n')
			{
				file3.write((char*)&e1,sizeof(e1));
			}
			if(ch2=='y')
			{
				cout<<"enter changed data"<<endl;
				e1.idno=tempid1;
				cout<<"id no. of new employee is"<<e1.idno<<endl;
				e1.dateval();
				cout<<"Enter your name"<<endl;
				gets(e1.name);
			}
		}
	}
	file.close();
	file3.close();
	remove("employee.dat");
	rename("temp.dat","employee.dat");
	file.open("employee.dat",ios::in|ios::binary);
	cout<<"IDNO"<<"\tNAME"<<"\t\tDATE OF JOINING"<<endl;
	while(file.read((char*)&e1,sizeof(e1)))
	{
		e1.display_str();
	}
	file.close();
	int gdriver=DETECT, gmode;
	initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
}
//..............................................................................
void search()
{
	closegraph();
	int f=1;
	int seaidno;
	clrscr();
	file.open("employee.dat",ios::in|ios::binary);
	cout<<"Enter the idno of the record to be searched"<<endl;
	cin>>seaidno;
	while(file.read((char*)&e1,sizeof(e1)))
	{
		file.read((char*)&e1,sizeof(e1));
		if(seaidno==e1.idno)
		{
			f=0;
			cout<<"The record is present "<<endl;
			getch();							clrscr();
			cout<<"IDNO"<<"\tNAME"<<"\t\tDATE OF JOINING"<<endl;
			e1.display_str();
		}
	}
	if(f==1)
	{
		cout<<"record not found"<<endl;
	}
	int gdriver=DETECT, gmode;
	initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
}
//....................................................................................
void deletion()
{
	closegraph();
	char ch1;
	int delidno;
	cout<<"enter the employee no. of the employee to be deleted"<<endl;
	cin>>delidno;
	file.open("employee.dat",ios::in|ios::binary);
	file2.open("temp.dat",ios::out);
	while(!file.eof())
	{
		file.read((char*)&e1,sizeof(e1));
		if(delidno==e1.idno)
		{
			e1.display_str();
			cout<<"is this the employee you want to delete"<<endl;
			cin>>ch1;
			tolower(ch1);
			if(ch1=='y')
			{
				cout<<"employee deleted"<<endl;
			}
			if(ch1=='n')
			{
				file2.write((char*)&e1,sizeof(e1));
			}
		}
		if(delidno!=e1.idno)
		{
			file2.write((char*)&e1,sizeof(e1));
		}
	}
	file.close();
	file2.close();
	remove("employee.dat");
	rename("temp.dat","employee.dat");
	file.open("employee.dat",ios::in);
	cout<<"displaying data"<<endl;
	cout<<"IDNO"<<"\tNAME"<<"\t\tDATE OF JOINING"<<endl;
	while(file.read((char*)&e1,sizeof(e1)))
	{
		file.read((char*)&e1,sizeof(e1));
		e1.display_str();
	}
	file.close();
	getch();
	int gdriver=DETECT, gmode;
	initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
}
//..................................................................................
void display()
{
	closegraph();
	clrscr();
	file.open("employee.dat",ios::in|ios::binary);
	cout<<"IDNO"<<"\tNAME"<<"\t\tDATE OF JOINING"<<endl;
	while(file.read((char*)&e1,sizeof(e1)))
	{
		e1.display_str();
	}
	file.close();
	getch();
	int gdriver=DETECT, gmode;
	initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
}
//.........................................................................................
void addition()
{
	closegraph();
	int tempid;
	tempid=idgen();
	file.open("employee.dat",ios::app|ios::binary);
	e1.idno=tempid;
	cout<<"your id number is"<<e1.idno<<endl;
	e1.dateval();
	cout<<"Enter your name"<<endl;
	gets(e1.name);
	file.write((char*)&e1,sizeof(e1));
	cout<<"record added"<<endl;
	file.close();
	int gdriver=DETECT, gmode;
	initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
}
//..................................................................................
int idgen()
{
	int g;
	file.open("employee.dat",ios::in||ios::binary);
	while(file.read((char*)&e1,sizeof(e1)))
	{
		file.read((char*)&e1,sizeof(e1));

		g=e1.idno+1;
	}
	file.close();
	return g;
}
//.................................................................................
void controls()
{
	setbkcolor(BLUE);
	settextstyle(6,0,0);
	setcolor(RED);
	outtextxy(50,100,"1. use W to switch to option given above");
	outtextxy(50,200,"2. use S to switch to option given below");
	outtextxy(50,300,"3. use spacebar to choose given option");
	settextstyle(0,0,1);
	outtextxy(400,400,"press any key to continue...");
	getch();
}
//.....................................................................................
void fsnake()
{
	snake s1;
	s1.snkcontrols();
	s1.acceptsnk();
	circle(s1.x,s1.y,3);
	char ch;
	s1.accfood();
	int time=0;
	clock_t start,end;
	start=clock();
	while(1)
	{
		ch=getch();
		if(ch=='w')
			s1.move('w');
		if(ch=='s')
		       s1.move('s');
		if(ch=='d')
			s1.move('d');
		if(ch=='a')
			s1.move('a');
		if(s1.k==16)
			break;
	}
	end=clock();
	cleardevice();
	time=(end-start)/CLK_TCK;
	cout<<"the time was "<<time<<"seconds"<<endl;
	sf1.open("snk.dat",ios::app|ios::binary);
	si1.stime=time;
	cout<<"enter your name"<<endl;
	gets(si1.sname);
	sf1.write((char*)&si1,sizeof(si1));
	sf1.close();
	sf1.open("snk.dat",ios::in|ios::binary);
	while(sf1.read((char*)&si1,sizeof(si1)))
	{
		sf1.read((char*)&si1,sizeof(si1));
		si1.display();
	}
	sf1.close();
}
//#############################-END OF PROGRAM-#####################################