#include<graphics.h>						//used for literally everything, LOL
#include<time.h>						//used for delay function in loops and totally randomizing the rand function from srand
//stdlib.h not used as it is avaiable in time.h header		//here used for all calculations, int, char and much more
//conio.h not used as it is available in graphics.h		//here used for getch()
//windows.h not used as it is available in graphics.h		//here used for GetAsyncKeyState(),VK_RETURN, VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN
//strings.h not used as it is available in graphics.h		//here used for sprintf()
int main()
{
	int i,X[100],Y[100],rx,ry,gm,gd,l,d=1,s=16;
	char str[1000], quit_message[50];//may be removed
	srand(time(NULL));
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	setfillstyle(1,1); //border code starts
	bar(s-s/2,s-s/2,(s/2)+s*(1350/s),s+s/2); //top
	bar(s-s/2,(-s/2)+s*(700/s),(s/2)+s*(1350/s),(s/2)+s*(700/s)); //bottom
	bar(s-s/2,s-s/2,s+s/2,(s/2)+s*(700/s)); //left
	bar((-s/2)+s*(1350/s),s-s/2,(s/2)+s*(1350/s),(s/2)+s*(700/s)); //right
	bar(380,696,410,10);//supposedely the 2nd left bar
	X[0]=s*(1350/(2*s)); Y[0]=s*(700/(2*s));
    bar(X[0]-s/2,Y[0]-s/2,X[0]+s/2,Y[0]+s/2); //snake bar (1 square)
    l=5;
    for(i=1;i<l;i++) //for enlarging snake in initial state (4 blocks)
    {
        X[i]=X[0]-(i*s);
        Y[i]=Y[0];
        bar(X[i]-s/2,Y[i]-s/2,X[i]+s/2,Y[i]+s/2);
    }
    rx=s; ry=s; //food starts 
    setfillstyle(1,2); //food color and style
    while(getpixel(rx,ry)!=0)
	{
		rx=s*(1+rand()%(1350/s-1));//randomizing food on x-axis
		ry=s*(1+rand()%(700/s-1));//randomizing food on y-axis
	}
	// is the initial place where food is spawned as totally random can be anywhere
	bar(rx-s/2,ry-s/2,rx+s/2,ry+s/2);//bar i.e. small single square for food
    delay(2000); //delay start of the game by 2 seconds such that there is enought time for enralging the terminal windows
	while(1) //loops that is responsible for getting input via keys and updating the head for snake
	{
    	setfillstyle(1,0); //updating the snake
		bar(X[l-1]-s/2,Y[l-1]-s/2,X[l-1]+s/2,Y[l-1]+s/2);
		for(i=l-1;i>0;i--)
    	{
    		X[i]=X[i-1];
    		Y[i]=Y[i-1];
		}
    	if(d==0) //updating the head
			X[0]=X[0]-s;
		if(d==1)
			Y[0]=Y[0]-s;
    	else if(d==2)
			X[0]=X[0]+s;
		else if(d==3)
			Y[0]=Y[0]+s;
		if(getpixel(X[0],Y[0])==1) //terminating condition
			break;
		if((GetAsyncKeyState(VK_RIGHT))&&(d!=0)) //updating directions i.e. taking input from right arrow key
			d=2;
		else if((GetAsyncKeyState(VK_UP))&&(d!=3)) //updating directions i.e. taking input from up arrow key
			d=1;
		else if((GetAsyncKeyState(VK_LEFT))&&(d!=2)) //updating directions i.e. taking input from left arrow key
			d=0;
		else if((GetAsyncKeyState(VK_DOWN))&&(d!=1)) //updating directions i.e. taking input from down arrow key
			d=3;
		if(getpixel(X[0],Y[0])==2) //food taken ?
		// if taken spawining the food on another totally random position
		{
			rx=s; ry=s;
			setfillstyle(1,2);
			while(getpixel(rx,ry)!=0)
			{
				rx=s*(1+rand()%(1350/s-1));
				ry=s*(1+rand()%(700/s-1));
			}
			bar(rx-s/2,ry-s/2,rx+s/2,ry+s/2);
			l=l+1;
		}
		setfillstyle(1,1); //displaying the snake
		for(i=0;i<l;i++) //the main working loop with which it works, moves and displays score in real time
			bar(X[i]-s/2,Y[i]-s/2,X[i]+s/2,Y[i]+s/2);//the working condition of how the snake moves in the BGI screen
			delay(60);//is the delay with what we see the next pixel apear, increasing will slow the snake decreasing will fasten the movement of snake
			setfillstyle(1,2);//setting style for text (that dosent seem to work), LOL (unnecessary)
			sprintf(str,"Score: %d",l-5);//changing diffrent data type to string a = string name b = another datatype
			settextstyle(4,0,4);//used for setting text size, font and direction (that I dont understand) a = font, b = direction, c = size
			outtextxy(90,325,str);//give an output prompt on the BGI interface a = x-coordinate, b = y-coordinate, c = the string that is to be printed
    }
    settextstyle(8,0,9);//here to set style for quit message
    sprintf(quit_message, "GAME-OVER");//changing data type to string
    outtextxy(600,300,quit_message);//displays message in terminal
    delay(50);//keeps the message on BGI screen for 0.5 secs such that it apears immidiately after snake dies and dosent close the terminal immidiately
    printf("score : %d",l-5); //displaying the score in seperate terminal
	while(!GetAsyncKeyState(VK_RETURN)); //closing condition i.e. enter key
	closegraph(); //close the seperate BGI windows displaying the graphcis
	getch(); //hold terminal windows so the score is visible in terminal window that tbh is unnecessary
	return 0; //unnecessary
}
