#include<graphics.h>
#include<time.h>

int main()
{
	int i,X[100],Y[100],rx,ry,gm,gd,l,d=2,s=16;
	srand(time(NULL));
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	setfillstyle(1,1); //border code starts
	bar(s-s/2,s-s/2,(s/2)+s*(1350/s),s+s/2); //top
	bar(s-s/2,(-s/2)+s*(700/s),(s/2)+s*(1350/s),(s/2)+s*(700/s)); //bottom
	bar(s-s/2,s-s/2,s+s/2,(s/2)+s*(700/s)); //left
	bar((-s/2)+s*(1350/s),s-s/2,(s/2)+s*(1350/s),(s/2)+s*(700/s)); //right
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
    setfillstyle(1,2);
    while(getpixel(rx,ry)!=0)
	{
		rx=s*(1+rand()%(1350/s-1));
		ry=s*(1+rand()%(700/s-1));
	}
	bar(rx-s/2,ry-s/2,rx+s/2,ry+s/2);
    delay(2000);
	while(1)
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
		if((GetAsyncKeyState(VK_RIGHT))&&(d!=0)) //updating directions i.e. taking input
			d=2;
		else if((GetAsyncKeyState(VK_UP))&&(d!=3))
			d=1;
		else if((GetAsyncKeyState(VK_LEFT))&&(d!=2))
			d=0;
		else if((GetAsyncKeyState(VK_DOWN))&&(d!=1))
			d=3;
		if(getpixel(X[0],Y[0])==2) //food taken ?
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
		for(i=0;i<l;i++)
       		bar(X[i]-s/2,Y[i]-s/2,X[i]+s/2,Y[i]+s/2);	
		delay(100);
    }
    printf("score : %d",l-5); //displaying the score in seperate terminal
	while(!GetAsyncKeyState(VK_RETURN)); //closing condition i.e. enter key
	closegraph(); //close the seperate BGI windows displaying the graphcis 
	getch(); //hold terminal windows so the score is visible
	return 0;	
}