# Graphics-Snake-Game-ProjectUBIT
Marked Project for Semester 2 UBIT

Project Members: Muhammad Mubashir Wasi     (EB22210006088)
                 Daud Siddiqui              (EB22210006076)
                 Abdullah Qazi              (EB22210006063)
                 Syed Ebad Hussain          (EB22210006131)
                 Hassan Ahmed               (EB22210006045)

Class:           BSCS Semester-II Scetion 'B'

Instructor:      Syeda Faiza Adnan

Assignment:      Snake Game with added graphics

DESCRIPTION: 
    1) int x[100], y[100] are arrays of size 100 bits will be used in almost all parts of code from food to snake to movement to respawninig of food
    2) int rx and ry are the axis on which the food will spawn
    3) int gm and gd are graphics mode and graphics drivers they are either to be detected via gm, gd = DETECT or detectgraph(&gm,&gd) where &gm and &gd are the memory adresses of the mode and drivers files
    4) int l will be used in loop for making the size of snake
    5) int d = 2 will be used in if else conditions for 

initgraph() initilizez the graphics system by loading a graphics driver from disk i.e. opens BGI
closegraph() function closes the graphics mode and deallocates all memory allocated by graphics system i.e. closes BGI
BGI = Borland graphics interface
setfillstyle(x,y) sets pattern and color x = pattern, y = color
floodfill(x,y) fills the color at location, (x,y) within border color
bar(a,b,c,d,) makes a bar in the BGI interface a = left, b = right, c = right, d = bottom 
line(a,b,c,d) makes a line in the BGI interface a = x1, b =  y1, c = x2, d = y2
circle(a,b,c) makes a circle in BGI interface a = x, b = y, c = radius
//file still in working
