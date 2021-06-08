#include <stdio.h>
#include <stdlib.h>
#include<dos.h>
#include<graphics.h>
#include<conio.h>

void Print();
void death();
void smiley();
void win();
void pause();
void delete1();
void create();
void atend();
void score();
void load();
void level4(struct node*);
void level3(struct node*);
void level2(struct node*);
void level1(struct node*);
int count=5;
int scre=0;
struct node*temp;

//*****Structure node******

struct node
{
    int x;
    int y;
    struct node* next;
};

//*****WELCOME PAGE*****

void Print()
{
	int i;
	while(1)
	{
		if(!kbhit())
		{

			//To generate the random circles

			circle(random(getmaxx()),random(getmaxy()),1/2);

			//To set the background color

			setbkcolor(MAGENTA);
			int a=getmaxy()/2;
			int b=getmaxx()/2-120;

			//To generate the boundary

			rectangle(0,0,getmaxx(),getmaxy());
			outtextxy(b,a,"Welcome to the mini Snake game");
			outtextxy(b+10,a+30,"Press any Key to continue!!");
			delay(100);
		}
		else
		{
			goto q;
		}
	}
	//******To print INSTRUCTIONS******

	q:
	cleardevice();
	setbkcolor(1);
	textbackground(1);
	setcolor(1);
	outtextxy(130,60,"Game instructions:");
	setcolor(2);
	outtextxy(150,90,"-> Use arrow keys to move the snake.");
	setcolor(3);
	outtextxy(150,110,"-> You will be provided foods at the several coordinates");
	setcolor(3);
	outtextxy(150,120,"   of the screen which you have to eat.");
	setcolor(5);
	outtextxy(150,140,"-> Everytime you eat a food the length of the snake");
	setcolor(5);
	outtextxy(150,150,"   will increase by 1 element and thus the score.");
	setcolor(7);
	outtextxy(150,170,"-> Here you are provided with FOUR lives.");
	setcolor(8);
	outtextxy(150,190,"-> Your life will decrease when you will hit the wall.");
	setcolor(4);
	outtextxy(150,210,"->There are FOUR levels in this game.");
	setcolor(9);
	outtextxy(150,230,"->After scoring a certain predecided score you.");
	outtextxy(150,240,"are promoted to next level.With each passing");
	outtextxy(150,250,"the difficulty increases.");
	setcolor(5);
	outtextxy(200,300,"->Press ESC to exit the game.");
	if(getch()==27)
	{
		exit(0);
	}
	getch();


}

//*****Function to display LOADING*****

void load()
{
	setbkcolor(BROWN);
	int row,col,r,c,q,k=10;
	while(1)
	{
		if(!kbhit())
		{
			if(k>=20)
			goto p ;
			gotoxy(36,14);
			printf("loading...");
			gotoxy(30,15);
			for(r=1; r<=k; r++)
			{
				for(q=0; q<=10000; q++); //to display the character slowly
				printf("%c",177);
			}
			k=k+2;
		}
		else goto p;
		delay(1000);
		cleardevice();
	}
	p:
}


//*****Function to generate smiley's********

void smiley()
{
	int y=0;
	int p=20;
	int q=500;
	int a;
	setbkcolor(RED);
	while(!kbhit())
	{
		y=y+60;
		if(y>=400)
		{
			y=0;
		}
		cleardevice();

		for(q=500;q>=60;q=q-120)
		{
			a=q;
			if(q-y<=0)
			q=500+q-y;
			for(p=20;p<getmaxx()-20;p=p+120)
			{
				setcolor(YELLOW);
				setfillstyle(SOLID_FILL,YELLOW);

				circle(p,q-y,20);
				/*make the main part of the smiley face*/

				floodfill(p,q-y,YELLOW);
				/*fill the circle with yellow color RED color here shows the border of circle*/

				setcolor(BLACK);

				ellipse(p-10,q-10-y,0,360,3,5);
				/*create right eye of smiley face*/

				ellipse(p+10,q-10-y,0,360,3,5);
				/*create left eye of smiley face*/

				arc(p+10,q-10-y,0,180,3);
				/*create lips of smiley face*/

				arc(p-10,q-10-y,0,180,3);
				/*create lower part of left eye of smiley face*/

				setcolor(RED);
				arc(p,q+5-y,180,360,6);
				/*create lower part of right eye of smiley face*/

			}

			y=y+60;

			for(p=80;p<getmaxx()-20;p=p+120)
			{
				setcolor(YELLOW);
				setfillstyle(SOLID_FILL,YELLOW);

				circle(p,q-y,20);

				/*make the main part of the smiley face*/

				floodfill(p,q-y,YELLOW);

				/*fill the circle with yellow color RED color here shows the border of circle*/

				setcolor(BLACK);

				/*create right eye of smiley face*/

				ellipse(p-10,q-10-y,0,360,3,5);

				/*create right eye of smiley face*/

				ellipse(p+10,q-10-y,0,360,3,5);

				/*create right eye of smiley face*/


				arc(p+10,q-10-y,0,180,3);

				/*create right eye of smiley face*/

				arc(p-10,q-10-y,0,180,3);

				setcolor(RED);

				/*create right eye of smiley face*/

				arc(p,q+5-y,180,360,6);

			}
			y=y-60;
			q=a;
		}

		delay(500);

	}

	getch();
	exit(0);
}

//*****Score function******

void score()
{
	char buf[5],buf2[5];
	outtextxy(getmaxx()*3/4+10,20,"Score:");
	sprintf(buf,"%d",scre);
	outtextxy(getmaxx()*3/4+60,20,buf);
	outtextxy(getmaxx()*3/4+10,60,"Life:");
	sprintf(buf2,"%d",count);
	outtextxy(getmaxx()*3/4+60,60,buf2);
}

//*****Function to reset the Snake's length******

void delete1(struct node* ptr1)
{
	while(ptr1!=NULL)
	{
		ptr1=ptr1->next;
		free(ptr1);
	}
}

//******Function to pause*************

void pause()
{
	circle(random(getmaxx()),random(getmaxy()),1/2);
	outtextxy(getmaxx()/4+25,getmaxy()/2,"PRESS ANY ARROW KEY TO CONTINUE");
	getch();
}

//******Function to display death******

void death()
{
	int p=getmaxx()/2,q=getmaxy()/2-40,y=0;
	cleardevice();
	while(1)
	{
		if(!kbhit())
		{
			cleardevice();
			setcolor(YELLOW);
			setfillstyle(SOLID_FILL,YELLOW);

			circle(p,q,20);

			/*make the main part of the smiley face*/

			floodfill(p,q,YELLOW);

			/*fill the circle with yellow color RED color here shows the border of circle*/

			setcolor(BLACK);

			/*create right eye of smiley face*/

			ellipse(p-10,q-10,0,360,3,5);

			//To create tears

			circle(p-10,q-10+7+y,1/2);

			/*create right eye of smiley face*/

			ellipse(p+10,q-10,0,360,3,5);

			//To create tears

			circle(p+10,q-10+7+y,1/2);

			/*create right eye of smiley face*/

			arc(p+10,q-10,0,180,3);

			/*create right eye of smiley face*/

			arc(p-10,q-10,0,180,3);

			setcolor(RED);

			/*create right eye of smiley face*/

			arc(p,q+15,0,180,6);


			y=y+1;
			if(y==17)
			{
				y=0;
			}
			outtextxy(getmaxx()/2-50,getmaxy()/2,"ONE LIFE LOST...");
		}
		else goto h;
		delay(50);
	}
	h:
}

//******Function to increase Snake's Length******

void atend(struct node* ptr)
{
	int num,i,k;
	struct node* temp;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	temp=(struct node *)malloc(sizeof(struct node));
	temp->x=ptr->x;
	temp->y=ptr->y;
	temp->next=NULL;
	ptr->next=temp;

}

//*****Page to be displayed when the user wins the game******

void win()
{
	cleardevice();
	while(1)
	{
		if(!kbhit())
		{
			circle(random(getmaxx()),random(getmaxy()),1/2);
			settextstyle(DEFAULT_FONT,0,3);
			outtextxy(getmaxx()/2-100,getmaxy()/2,"You Win :)");
		}
		else goto b;
		delay(50);

	     }
	     b:
	     cleardevice();

		if(kbhit())
		{
			getch();
			FILE* fp;
			char name[100];
			fp=fopen("Score.txt","a");
			settextstyle(DEFAULT_FONT,0,1);
			outtextxy(0,0,"Enter your name-");
			gets(name);
			fprintf(fp,"%s\n",name);
			fprintf(fp,"%d\n",scre);
			fclose(fp);
			char nm[100];
			int s,t=0;
			fp=fopen("score.txt","r");
			settextstyle(DEFAULT_FONT,0,1);
			outtextxy(400,10,"The Scores are :");
			while(!feof(fp))
			{
				fscanf(fp,"%s%d",nm,&s);
				outtextxy(400,50+t,nm);
				sprintf(nm,"%d",s);
				outtextxy(400+60,50+t,nm);
				t+=50;
			}
			fclose(fp);
			getch();
			exit(0);

		}


}

//******Function for Level 4******

void level4(struct node* ptr)
{
	int a;
	int b;
	int a1;
	int b1;
	int i=0;
	int j=0;
	int x2;
	int y2;

	randomize();
	x2=random(3*getmaxx()/20)*5;
	y2=random(getmaxy()/5)*5;
	char ch;
	temp=ptr;
	setbkcolor(RED);
	setcolor(YELLOW);
	while(1)
	{
		score();
		if(scre==80)
		{
			win();
		}

		rectangle(0,0,3*getmaxx()/4,getmaxy());
		setcolor(YELLOW);
		setfillstyle(SOLID_FILL,YELLOW);
		rectangle(250,250,300,300);
		floodfill(275,275,YELLOW);
		a= ptr->x;
		b=ptr->y;
		ptr->x=ptr->x+i;
		ptr->y=ptr->y+j;
		while(ptr->next!=NULL)
		{
			a1=a;
			b1=b;
			a=ptr->next->x;
			b=ptr->next->y;
			ptr->next->x=a1;
			ptr->next->y=b1;
			ptr=ptr->next;
		}
		ptr=temp;
		while(ptr!=NULL)
		{
			outtextxy(ptr->x,ptr->y,"*");
			ptr=ptr->next;
		}
		ptr=temp;
		outtextxy(x2,y2,"@");

		if(ptr->x==x2&&ptr->y==y2)
		{
			scre=scre+5;
			atend(ptr);
			q:
			x2=random(3*getmaxx()/20)*5;
			y2=random(getmaxy()/5)*5;
		}
		if((x2>=250&&x2<=300 && y2>=250 && y2<=300))
		{
			goto q;
		}
		if((ptr->x>=3*getmaxx()/4||ptr->x<=0||ptr->y>=getmaxy()||ptr->y<=0)||(ptr->x>=250&&ptr->x<=300&&ptr->y>=250&&ptr->y<=300))
		{
			if(count==0)
			goto d;
			setbkcolor(BROWN);
			death();
			count--;
			delete1(temp);
			create();

		}
		delay(30);
		cleardevice();
		if(kbhit())
		{
			ch=getch();
			if(ch==27)
			{
				exit(0);
			}
		}
		if(ch==75)
		{
			i=-5;
			j=0;
		}
		if(ch==80)
		{
			i=0;
			j=5;
		}
		if(ch==72)
		{
			i=0;
			j=-5;
		}
		if(ch==77)
		{
			i=5;
			j=0;
		}
		if(ch==32)
		{
			pause();
		}

	}
	d:

	settextstyle(DEFAULT_FONT,0,3);
	for(i=0;i<3*getmaxx()/4-20;i+=10)
	{
		outtextxy(i,getmaxy()/2,"Game Over!");
		delay(1000);
		cleardevice();

		if(kbhit())
		{
			getch();
			FILE* fp;
			char name[100];
			fp=fopen("Score.txt","a");
			settextstyle(DEFAULT_FONT,0,1);
			outtextxy(1,1,"Enter your name-");

			gets(name);
			fprintf(fp,"%s\n",name);
			fprintf(fp,"%d\n",scre);
			fclose(fp);
			char nm[100];
			int s,t=0;
			fp=fopen("score.txt","r");
			settextstyle(DEFAULT_FONT,0,1);
			outtextxy(400,10,"The Scores are :");
			while(!feof(fp))
			{
				fscanf(fp,"%s%d",nm,&s);
				outtextxy(400,50+t,nm);
				sprintf(nm,"%d",s);
				outtextxy(400+60,50+t,nm);
				t+=50;
			}
			fclose(fp);
			getch();
			smiley();
			getch();
			exit(0);
		}

	}
}

//*****Function for level 3*****

void level3(struct node* ptr)
{
	int a;
	int b;
	int a1;
	int b1;
	int i=0;
	int j=0;
	int x2;
	int y2;

	randomize();
	x2=random(3*getmaxx()/20)*5;
	y2=random(getmaxy()/5)*5;

	char ch;

	temp=ptr;
	setbkcolor(BLACK);
	setcolor(WHITE);
	while(1)
	{
		score();
		if(scre==75)
		{
			delete1(temp);
			create();
		}

		rectangle(0,0,3*getmaxx()/4,getmaxy());
		setcolor(YELLOW);
		setfillstyle(SOLID_FILL,YELLOW);
		rectangle(350,350,400,400);
		floodfill(375,375,YELLOW);
		setcolor(YELLOW);
		setfillstyle(SOLID_FILL,YELLOW);
		rectangle(150,150,200,200);
		floodfill(175,175,YELLOW);
		a= ptr->x;
		b=ptr->y;
		ptr->x=ptr->x+i;
		ptr->y=ptr->y+j;
		while(ptr->next!=NULL)
		{
			a1=a;
			b1=b;
			a=ptr->next->x;
			b=ptr->next->y;
			ptr->next->x=a1;
			ptr->next->y=b1;
			ptr=ptr->next;
		}
		ptr=temp;
		while(ptr!=NULL)
		{
			outtextxy(ptr->x,ptr->y,"*");
			ptr=ptr->next;
		}
		ptr=temp;
		outtextxy(x2,y2,"@");

		if(ptr->x==x2&&ptr->y==y2)
		{
			scre=scre+5;
			atend(ptr);
			q:
			x2=random(3*getmaxx()/20)*5;
			y2=random(getmaxy()/5)*5;
			if((x2>=350&&x2<=400 && y2>=350 && y2<=400)||(x2>=150&&x2<=200 && y2>=150&&y2<=200))
			{
				goto q;
			}
		}
		if(ptr->x>=3*getmaxx()/4||ptr->x<=0||ptr->y>=getmaxy()||ptr->y<=0||(ptr->x>=350&&ptr->x<=400&&ptr->y>=350&&ptr->y<=400)||(ptr->x>=150&&ptr->x<=200&&ptr->y>=150&&ptr->y<=200))
		{
			if(count==0)
		       {
				goto d;
		       }
			death();
			count--;
			delete1(temp);
			create();

		}
		delay(30);
		cleardevice();

		if(kbhit())
		{
			ch=getch();
			if(ch==27)
				exit(0);
		}

		if(ch==75)
		{
			i=-5;
			j=0;
		}

		if(ch==80)
		{
			i=0;
			j=5;
		}
		if(ch==72)
		{
			i=0;
			j=-5;
		}
		if(ch==77)
		{
			i=5;
			j=0;
		}
		if(ch==32)
		{
			pause();
		}

	}
	d:

	settextstyle(DEFAULT_FONT,0,3);
	for(i=0;i<3*getmaxx()/4-20;i+=10)
	{
		outtextxy(i,getmaxy()/2,"Game Over!");
		delay(1000);
		cleardevice();
		if(kbhit())
		{
			getch();

			FILE* fp;
			char name[100];
			fp=fopen("Score.txt","a");
			outtextxy(1,1,"Enter your name-");
			gets(name);
			fprintf(fp,"%s\n",name);
			fprintf(fp,"%d\n",scre);
			fclose(fp);
			char nm[100];
			int s;
			int t=0;
			fp=fopen("score.txt","r");
			settextstyle(DEFAULT_FONT,0,1);
			outtextxy(400,10,"The Scores are :");
			while(!feof(fp))
			{
				fscanf(fp,"%s%d",nm,&s);
				outtextxy(400,50+t,nm);
				sprintf(nm,"%d",s);
				outtextxy(400+60,50+t,nm);
				t+=50;
			}
			fclose(fp);
			getch();
			smiley();
			getch();
			exit(0);
		}

	}
}

 //*****Function for Level 2******

void level2(struct node* ptr)
{
	int a;
	int b;
	int a1;
	int b1;
	int i=0;
	int j=0;
	int x2;
	int y2;

	 randomize();
	 x2=random(3*getmaxx()/20)*5;
	y2=random(getmaxy()/5)*5;

	char ch;

	 temp=ptr;
	setbkcolor(GREEN);
	setcolor(WHITE);
	while(1)
	{

		score();
		if(scre==50)
		{
			delete1(temp);
			create();
		}
		rectangle(0,0,3*getmaxx()/4,getmaxy());
		a= ptr->x;
		b=ptr->y;
		ptr->x=ptr->x+i;
		ptr->y=ptr->y+j;
		while(ptr->next!=NULL)
		{

			a1=a;
			b1=b;
			a=ptr->next->x;
			b=ptr->next->y;
			ptr->next->x=a1;
			ptr->next->y=b1;
			ptr=ptr->next;

		}
		ptr=temp;
		while(ptr!=NULL)
		 {
			 outtextxy(ptr->x,ptr->y,"*");
			  ptr=ptr->next;

		  }
		 ptr=temp;
		 outtextxy(x2,y2,"@");

		if(ptr->x==x2&&ptr->y==y2)
		 {
			 scre=scre+5;
			 atend(ptr);
			 x2=random(3*getmaxx()/20)*5;
			 y2=random(getmaxy()/5)*5;

		  }
		if(ptr->x>=3*getmaxx()/4||ptr->x<=0||ptr->y>=getmaxy()||ptr->y<=0)
		{
			if(count==0)
			 goto d;
			 death();
			 count--;
			 delete1(temp);
			create();
		 }
		delay(90);
		 cleardevice();
		if(kbhit())
		  {
			 ch=getch();
			 if(ch==27)
			 exit(0);
		   }
		 if(ch==75)
		  {
			i=-5;
			j=0;
		  }
		if(ch==80)
		  {
			i=0;
			j=5;
		  }
		if(ch==72)
		{
			 i=0;
			 j=-5;
		}
		if(ch==77)
		{
			i=5;
			j=0;
		}
		 if(ch==32)
		{
			 pause();
		 }
		}
		 d:

		 settextstyle(DEFAULT_FONT,0,3);
		 for(i=0;i<3*getmaxx()/4-20;i+=10)
		 {
			 outtextxy(i,getmaxy()/2,"Game Over!");
			 delay(1000);
			 cleardevice();
			 if(kbhit())
			{
				getch();

				FILE* fp;
				char name[100];
				fp=fopen("Score.txt","a");
				settextstyle(DEFAULT_FONT,0,1);
				outtextxy(1,1,"Enter your name-\n");;
				gets(name);
				fprintf(fp,"%s\n",name);
				fprintf(fp,"%d\n",scre);
				fclose(fp);
				char nm[100];
				int s,t=0;
				fp=fopen("score.txt","r");
				outtextxy(400,10,"The Scores are :");
				while(!feof(fp))
				{
					 fscanf(fp,"%s%d",nm,&s);
					 outtextxy(400,50+t,nm);
					 sprintf(nm,"%d",s);
					 outtextxy(400+60,50+t,nm);
					 t+=50;
				 }
				 fclose(fp);
				 getch();
				 smiley();
				 getch();
				 exit(0);
			 }

		 }
	 }

 //*****Function for Level 1*****

void level1(struct node* ptr)
{
	int a;
	int b;
	int a1;
	int b1;
	int i=0;
	int j=0;
	int x2;
	int y2;

	 randomize();
	 x2=random(3*getmaxx()/20)*5;
	y2=random(getmaxy()/5)*5;

	char ch;

	 temp=ptr;
	setbkcolor(CYAN);
	setcolor(8);
	while(1)
	{

		score();
		if(scre==25)
		{
			delete1(temp);
			create();
		}
		rectangle(0,0,3*getmaxx()/4,getmaxy());
		a= ptr->x;
		b=ptr->y;
		ptr->x=ptr->x+i;
		ptr->y=ptr->y+j;
		while(ptr->next!=NULL)
		{

			a1=a;
			b1=b;
			a=ptr->next->x;
			b=ptr->next->y;
			ptr->next->x=a1;
			ptr->next->y=b1;
			ptr=ptr->next;

		}
		ptr=temp;
		while(ptr!=NULL)
		 {
			 outtextxy(ptr->x,ptr->y,"*");
			  ptr=ptr->next;

		  }
		 ptr=temp;
		 outtextxy(x2,y2,"@");

		if(ptr->x==x2&&ptr->y==y2)
		 {
			 scre=scre+5;
			 atend(ptr);
			 x2=random(3*getmaxx()/20)*5;
			 y2=random(getmaxy()/5)*5;

		  }
		if(ptr->x>=3*getmaxx()/4||ptr->x<=0||ptr->y>=getmaxy()||ptr->y<=0)
		{
			if(count==0)
			 goto d;
			 death();
			 count--;
			 delete1(temp);
			create();
		 }
		delay(100);
		 cleardevice();
		if(kbhit())
		  {
			 ch=getch();
			 if(ch==27)
			 exit(0);
		   }
		 if(ch==75)
		  {
			i=-5;
			j=0;
		  }
		if(ch==80)
		  {
			i=0;
			j=5;
		  }
		if(ch==72)
		{
			 i=0;
			 j=-5;
		}
		if(ch==77)
		{
			i=5;
			j=0;
		}
		 if(ch==32)
		{
			 pause();
		 }
		}
		 d:

		 settextstyle(DEFAULT_FONT,0,3);
		 for(i=0;i<3*getmaxx()/4-20;i+=10)
		 {
			 outtextxy(i,getmaxy()/2,"Game Over!");
			 delay(1000);
			 cleardevice();
			 if(kbhit())
			{
				getch();

				FILE* fp;
				char name[100];
				fp=fopen("Score.txt","a");
				settextstyle(DEFAULT_FONT,0,1);
				outtextxy(1,1,"Enter your name-\n");
				gets(name);
				fprintf(fp,"%s\n",name);
				fprintf(fp,"%d\n",scre);
				fclose(fp);
				char nm[100];
				int s,t=0;
				fp=fopen("score.txt","r");
				outtextxy(400,10,"The Scores are :");
				while(!feof(fp))
				{
					 fscanf(fp,"%s%d",nm,&s);
					 outtextxy(400,50+t,nm);
					 sprintf(nm,"%d",s);
					 outtextxy(400+60,50+t,nm);
					 t+=50;
				 }
				 fclose(fp);
				 getch();
				 smiley();
				 getch();
				 exit(0);
			 }

		 }
	 }

 //*****Function to create Snake in the beginning*****

void create()
{
    struct node* ptr;
    struct node* head;
    int ch;
    int i;
    ptr=(struct node *)malloc(sizeof(struct node));
    head=ptr;
    ptr->x=20;
    ptr->y=20;
    ptr->next=NULL;
    if(scre>=25&&scre<50)
    level2(head);
    if(scre>=50&&scre<75)
    level3(head);
    if(scre>=75)
    level4(head);
    if(scre>=0&&scre<25)
    level1(head);
}

//****Main function****//

void main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    Print();
    delay(1000);
    cleardevice();
    load();
    create();
    getch();
}
