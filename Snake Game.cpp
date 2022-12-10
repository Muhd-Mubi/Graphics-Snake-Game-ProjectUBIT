#include<graphics.h>						//used for literally everything, LOL
#include<time.h>						//used for delay function in loops and totally randomizing the rand function from srand
//stdlib.h not used as it is avaiable in time.h header		//here used for all calculations, int, char and much more
//conio.h not used as it is available in graphics.h		//here used for getch()
//windows.h not used as it is available in graphics.h		//here used for GetAsyncKeyState(),VK_RETURN, VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN
//strings.h not used as it is available in graphics.h		//here used for sprintf() in form of sstream in C++
int main()
{
	int i,X[100],Y[100],rx,ry,gm,gd,l,d=1,s=20;
	char str[1000], quit_message[50];//may be removed
	srand(time(NULL));
	detectgraph(&gd,&gm);//gd is for launching the BGI interface wherease gm is for the functions done in the BGI interface
	initgraph(&gd,&gm,NULL);
	setfillstyle(1,1); //border code starts
	bar(s-s/2,s-s/2,(s/2)+s*(1350/s),s+s/2); //top
	bar(s-s/2,(-s/2)+s*(700/s),(s/2)+s*(1350/s),(s/2)+s*(700/s)); //bottom
	bar(s-s/2,s-s/2,s+s/2,(s/2)+s*(700/s)); //left
	bar((-s/2)+s*(1350/s),s-s/2,(s/2)+s*(1350/s),(s/2)+s*(700/s)); //right
	X[0]=s*(1350/(2*s));//snake that is the be apreaed in X-axis
	Y[0]=s*(700/(2*s));//snake that is to be apeared in Y-azis
	//the above conditions will be used such that at initial state the snake is initiated at the centre of the BGI screen and not randomly anywhere
    bar(X[0]-s/2,Y[0]-s/2,X[0]+s/2,Y[0]+s/2); //snake bar (1 square)
    l=5;//this is the initiating condition of score and the snake size. l=6 will be score = 1 and 1 incrementation in the snake size
    for(i=1;i<l;i++) //for enlarging snake in initial state (4 blocks)
    //the addition of 4 blocks will be done to the single block of snake in this loop
    {
        X[i]=X[0]-(i*s);//the position of X-axis where the another pisel of snake will apear
        Y[i]=Y[0];//the position on Y-axis where the another pixel of snake will apear
        bar(X[i]-s/2,Y[i]-s/2,X[i]+s/2,Y[i]+s/2);//snake more blocks that are to be added
    }
    rx=s; ry=s; //food starts 
    setfillstyle(1,2); //food color and style to be visible in the intital state
    while(getpixel(rx,ry)!=0)
	{
		rx=s*(1+rand()%(1350/s-1));//randomizing food on x-axis (initial state displayed before even the game is started playing)
		ry=s*(1+rand()%(700/s-1));//randomizing food on y-axis (initial state displayed eve before the game is started playing)
	}
	// is the initial place where food is spawned as totally random can be anywhere
	bar(rx-s/2,ry-s/2,rx+s/2,ry+s/2);//bar i.e. small single square for food
    delay(2500); //delay start of the game by 2 seconds such that there is enought time for enralging the terminal windows
	while(1) //loops that is responsible for getting input via keys and updating the head for snake
	//while(1) here 1 represents TRUE and is a bolean value
	// 0 and 1's are boleans in C where 1 is true and 0 is false
	{
    	setfillstyle(1,0); //updating the snake
		bar(X[l-1]-s/2,Y[l-1]-s/2,X[l-1]+s/2,Y[l-1]+s/2);//this is the black bar to replace the blue bar when it moves a pixel in front so that a trail of snake is not left behind
		for(i=l-1;i>0;i--)//this loops is for runnig the upper condition in loop
    	{
    		X[i]=X[i-1];
    		Y[i]=Y[i-1];
		}
		if(d==0) //updating the head;
			X[0]=X[0]-s;
		if(d==1)
			Y[0]=Y[0]-s;
    	else if(d==2)
			X[0]=X[0]+s;
		else if(d==3)
			Y[0]=Y[0]+s;
		if(getpixel(X[0],Y[0])==1) //terminating condition when the snake collides in boundary
			break;
		if((GetAsyncKeyState(VK_RIGHT))&&(d!=0)) //updating directions i.e. taking input from right arrow key
			d=2;
		else if((GetAsyncKeyState(VK_UP))&&(d!=3)) //updating directions i.e. taking input from up arrow key
			d=1;
		else if((GetAsyncKeyState(VK_LEFT))&&(d!=2)) //updating directions i.e. taking input from left arrow key
			d=0;
		else if((GetAsyncKeyState(VK_DOWN))&&(d!=1)) //updating directions i.e. taking input from down arrow key
			d=3;
		if(getpixel(X[0],Y[0])==2) //food taken ? if yes proceed with loop other wise will be skipped to the for loop of snake movement
		// if taken spawining the food on another totally random position
		{
			rx=s; ry=s;
			setfillstyle(1,2);//is the pattern and color for the food in loop that will be displayed when the game is running
			while(getpixel(rx,ry)!=0)
			{
				rx=s*(1+rand()%(1350/s-1));//is for randomizing the food on the y-azis (final state)
				ry=s*(1+rand()%(700/s-1));//is for randomizing the food on x-axis (final state)
			}
			bar(rx-s/2,ry-s/2,rx+s/2,ry+s/2);//is the food bar (i.e. green square)
			l++;//here counts the score and the enhancing of the snake size as this loop will only be entered when the food on the screen is once consumed so its obvious the score needs to be incremented
		}
		setfillstyle(1,1); //displaying the snake
		for(i=0;i<l;i++) //the main working loop with which it works, moves and displays score in real time
			bar(X[i]-s/2,Y[i]-s/2,X[i]+s/2,Y[i]+s/2);//the working condition of how the snake moves in the BGI screen
			delay(50);//is the delay with what we see the next pixel apear, increasing will slow the snake decreasing will fasten the movement of snake
			sprintf(str,"Score: %d",l-5);//changing diffrent data type to string a = string name b = another datatype
			settextstyle(4,0,2);//used for seytting text size, font and direction (that I dont understand) a = font, b = direction, c = size
			outtextxy(90,325,str);//give an output prompt on the BGI interface a = x-coordinate, b = y-coordinate, c = the string that is to be printed
    }
    settextstyle(8,0,9);//here to set style for quit message
    sprintf(str,"Score: %d", l-5);
    sprintf(quit_message, "GAME-OVER");//changing data type to string
    outtextxy(400,250,str);
    outtextxy(400,350,quit_message);//displays message in terminal
    delay(50);//keeps the message on BGI screen for 0.5 secs such that it apears immidiately after snake dies and dosent close the terminal immidiately
	while(!GetAsyncKeyState(VK_RETURN)); //closing condition i.e. enter key
	closegraph(); //close the seperate BGI windows displaying the graphcis
	return 0; //unnecessary
}
