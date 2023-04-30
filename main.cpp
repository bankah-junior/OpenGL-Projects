#include<GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#define SPEED 50.0

float i=0.0,m=0.0,n=0.0,o=0.0,c=0.0,red=0.0,green=0.0,blue=0.0,redb=1.0,greenb=1.0,blueb=1.0,redw=0.349,greenw=0.396,bluew=0.427;

int light=1,day=1,plane=0,comet=0,xm=900,train=0;
char ch;

void declare(char *string)
{
     while(*string)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *string++);
}

void draw_pixel(GLint cx, GLint cy)
{
	glBegin(GL_POINTS);
		glVertex2i(cx,cy);
	glEnd();
}

void plotpixels(GLint h,GLint k, GLint x,GLint y)
{
	draw_pixel(x+h,y+k);
	draw_pixel(-x+h,y+k);
	draw_pixel(x+h,-y+k);
	draw_pixel(-x+h,-y+k);
	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(y+h,-x+k);
	draw_pixel(-y+h,-x+k);
}


void draw_circle(GLint h, GLint k, GLint r)
{
	GLint d=1-r, x=0, y=r;
	while(y>x)
	{		plotpixels(h,k,x,y);
		if(d<0) d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(h,k,x,y);
}

void traffic_light()
{
	int l;
    if(light==1)
    {
        for(l=0;l<=20;l++)
        {
            glColor3f(0.0,0.0,0.0);
            draw_circle(1065,475,l);

            glColor3f(0.0,0.7,0.0);
            draw_circle(1065,375,l);
        }
    }   else
        {
            for(l=0;l<=20;l++)
            {
                glColor3f(1.0,0.0,0.0);
                draw_circle(1065,475,l);

                glColor3f(0.0,0.0,0.0);
                draw_circle(1065,375,l);
            }
       }
}

void draw_object()
{
    int l;
    if(day==1)
    {
        red = 0.0;
        green = 0.0;
        blue = 0.0;

        //sky
        glColor3f(0.45098,0.8745,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(0,380);
        glVertex2f(0,700);
        glVertex2f(1100,700);
        glVertex2f(1100,380);
        glEnd();

        //sun
        for(l=0;l<=35;l++)
        {
            glColor3f(0.97647,0.84313,0.1098);
            draw_circle(100,625,l);
        }

        //plane
        if(plane==1)
        {
            glColor3f(1.0,1.0,1.0);
            glBegin(GL_POLYGON);
            glVertex2f(925+n,625+o);
            glVertex2f(950+n,640+o);
            glVertex2f(1015+n,640+o);
            glVertex2f(1030+n,650+o);
            glVertex2f(1050+n,650+o);
            glVertex2f(1010+n,625+o);
            glEnd();

            glColor3f(0.8,0.8,0.8);
            glBegin(GL_LINE_LOOP);
            glVertex2f(925+n,625+o);
            glVertex2f(950+n,640+o);
            glVertex2f(1015+n,640+o);
            glVertex2f(1030+n,650+o);
            glVertex2f(1050+n,650+o);
            glVertex2f(1010+n,625+o);
            glEnd();
        }

        //cloud 1
        for(l=0;l<=20;l++)
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(160+m,625,l);
        }
        for(l=0;l<=35;l++)
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(200+m,625,l);
            draw_circle(225+m,625,l);
        }
        for(l=0;l<=20;l++)
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(265+m,625,l);
        }

        //cloud 2
        for(l=0;l<=20;l++)
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(370+m,615,l);
        }
        for(l=0;l<=35;l++)
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(410+m,615,l);
            draw_circle(435+m,615,l);
            draw_circle(470+m,615,l);
        }
        for(l=0;l<=20;l++)
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(500+m,615,l);
        }

        //grass
        glColor3f(0.0,0.9,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(0,160);
        glVertex2f(0,380);
        glVertex2f(1100,380);
        glVertex2f(1100,160);
        glEnd();

    }   else
    {
        red = 1.0;
        green = 0.733333;
        blue = 0.45098;

        //sky
        glColor3f(0.0,0.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(0,380);
        glVertex2f(0,700);
        glVertex2f(1100,700);
        glVertex2f(1100,380);
        glEnd();

        //moon
        int l;
        for(l=0;l<=35;l++)
        {
            glColor3f(0.941176,0.941176,0.941176);
            draw_circle(1000,625,l);
        }
        for(l=0;l<=35;l++)
        {
            glColor3f(0,0,0);
            draw_circle(970,625,l);
        }

        //star 1
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(575,653);
        glVertex2f(570,645);
        glVertex2f(580,645);
        glVertex2f(575,642);
        glVertex2f(570,650);
        glVertex2f(580,650);
        glEnd();

        //star 2
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(975,643);
        glVertex2f(970,635);
        glVertex2f(980,635);
        glVertex2f(975,632);
        glVertex2f(970,640);
        glVertex2f(980,640);
        glEnd();

        //star 3
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(875,543);
        glVertex2f(870,535);
        glVertex2f(880,535);
        glVertex2f(875,532);
        glVertex2f(870,540);
        glVertex2f(880,540);
        glEnd();

        //star 4
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(375,598);
        glVertex2f(370,590);
        glVertex2f(380,590);
        glVertex2f(375,587);
        glVertex2f(370,595);
        glVertex2f(380,595);
        glEnd();

        //star 5
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(750,628);
        glVertex2f(745,620);
        glVertex2f(755,620);
        glVertex2f(750,618);
        glVertex2f(745,625);
        glVertex2f(755,625);
        glEnd();

        //star 6
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(200,628);
        glVertex2f(195,620);
        glVertex2f(205,620);
        glVertex2f(200,618);
        glVertex2f(195,625);
        glVertex2f(205,625);
        glEnd();

        //star 7
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(100,528);
        glVertex2f(95,520);
        glVertex2f(105,520);
        glVertex2f(100,518);
        glVertex2f(95,525);
        glVertex2f(105,525);
        glEnd();

        //star 8
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(300,468);
        glVertex2f(295,460);
        glVertex2f(305,460);
        glVertex2f(300,458);
        glVertex2f(295,465);
        glVertex2f(305,465);
        glEnd();

        //star 9
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(500,543);
        glVertex2f(495,535);
        glVertex2f(505,535);
        glVertex2f(500,532);
        glVertex2f(495,540);
        glVertex2f(505,540);
        glEnd();


        //comet
        if(comet==1)
        {
            for(l=0;l<=7;l++)
            {
                glColor3f(1.0,1.0,1.0);
                draw_circle(300+c,675,l);
            }

            glColor3f(1.0,1.0,1.0);
            glBegin(GL_TRIANGLES);
            glVertex2f(200+c,675);
            glVertex2f(300+c,682);
            glVertex2f(300+c,668);
            glEnd();
        }

        //Plane
        if(plane==1)
        {
            for(l=0;l<=1;l++)
            {
                glColor3f(1.0,0.0,0.0);
                draw_circle(950+n,625+o,l);
                glColor3f(1.0,1.0,0.0);
                draw_circle(954+n,623+o,l);
            }
        }

        //grass
        glColor3f(0.0,0.3,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(0,160);
        glVertex2f(0,380);
        glVertex2f(1100,380);
        glVertex2f(1100,160);
        glEnd();

    }

    //track boundary
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(0,150);
    glVertex2f(0,160);
    glVertex2f(1100,160);
    glVertex2f(1100,150);
    glEnd();

    //platform
    glColor3f(0.717647,0.67843,0.639215);
    glBegin(GL_POLYGON);
    glVertex2f(0,160);
    glVertex2f(0,250);
    glVertex2f(1100,250);
    glVertex2f(1100,160);
    glEnd();

    //below track
    glColor3f(0.88627,0.85098,0.80392);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0,150);
    glVertex2f(1100,150);
    glVertex2f(1100,0);
    glEnd();

    //Railway track
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-100,0);
    glVertex2f(-100,20);
    glVertex2f(1100,20);
    glVertex2f(1100,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-100,80);
    glVertex2f(-100,100);
    glVertex2f(1100,100);
    glVertex2f(1100,80);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0,80);
    glVertex2f(10,80);
    glVertex2f(10,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(80,0);
    glVertex2f(80,80);
    glVertex2f(90,80);
    glVertex2f(90,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(150,0);
    glVertex2f(150,80);
    glVertex2f(160,80);
    glVertex2f(160,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(220,0);
    glVertex2f(220,80);
    glVertex2f(230,80);
    glVertex2f(230,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(290,0);
    glVertex2f(290,80);
    glVertex2f(300,80);
    glVertex2f(300,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(360,0);
    glVertex2f(360,80);
    glVertex2f(370,80);
    glVertex2f(370,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(430,0);
    glVertex2f(430,80);
    glVertex2f(440,80);
    glVertex2f(440,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(500,0);
    glVertex2f(500,80);
    glVertex2f(510,80);
    glVertex2f(510,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(570,0);
    glVertex2f(570,80);
    glVertex2f(580,80);
    glVertex2f(580,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(640,0);
    glVertex2f(640,80);
    glVertex2f(650,80);
    glVertex2f(650,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(710,0);
    glVertex2f(710,80);
    glVertex2f(720,80);
    glVertex2f(720,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(770,0);
    glVertex2f(770,80);
    glVertex2f(780,80);
    glVertex2f(780,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(840,0);
    glVertex2f(840,80);
    glVertex2f(850,80);
    glVertex2f(850,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(900,0);
    glVertex2f(900,80);
    glVertex2f(910,80);
    glVertex2f(910,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(970,0);
    glVertex2f(970,80);
    glVertex2f(980,80);
    glVertex2f(980,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(1040,0);
    glVertex2f(1040,80);
    glVertex2f(1050,80);
    glVertex2f(1050,0);
    glEnd();

    //track boundary
    glColor3f(0.50196,0.0,0.12549);
    glBegin(GL_POLYGON);
    glVertex2f(-100,100);
    glVertex2f(-100,150);
    glVertex2f(1100,150);
    glVertex2f(1100,100);
    glEnd();

    //railway station building
    glColor3f(0.97647,0.898,0.7372549);
    glBegin(GL_POLYGON);
    glVertex2f(50,250);
    glVertex2f(50,450);
    glVertex2f(950,450);
    glVertex2f(950,250);
    glEnd();

    //roof of railway station building
    glColor3f(0.77647,0.7098,0.63137);
    glBegin(GL_POLYGON);
    glVertex2f(5,450);
    glVertex2f(105,500);
    glVertex2f(900,500);
    glVertex2f(1000,450);
    glEnd();

    glColor3f(0.7921568,0.0,0.1647);
    glBegin(GL_POLYGON);
    glVertex2f(75,250);
    glVertex2f(75,250);
    glVertex2f(75,400);
    glVertex2f(100,425);
    glVertex2f(375,425);
    glVertex2f(400,400);
    glVertex2f(400,250);
    glEnd();

    // Board Light
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex2f(75,400);
    glVertex2f(90,400);
    glVertex2f(103,415);
    glVertex2f(100,425);
    glEnd();

    if (day != 1) {
        // Board Light on
        red = 1.0;
        green = 1.0;
        blue = 1.0;
        glColor3f(red,green,blue);
        glBegin(GL_POLYGON);
        glVertex2f(90,400);
        glVertex2f(103,415);
        glVertex2f(400,400);
        glVertex2f(400,250);
        glVertex2f(75,250);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(75,250);
        glVertex2f(50,225);
        glVertex2f(425,225);
        glVertex2f(400,250);
        glEnd();
    }

    glColor3f(redb,greenb,blueb);
     glRasterPos2f(180,390);
     declare("RAILWAY STATION");
     glRasterPos2f(180,380);
     declare("----------------");
     glRasterPos2f(90,350);
     declare("RED = 'R' / 'r'");
     glRasterPos2f(90,320);
     declare("GREEN = 'G' / 'g'");
     glRasterPos2f(90,290);
     declare("DAY = 'D' / 'd'");
     glRasterPos2f(90,260);
     declare("NIGHT = 'N' / 'n'");
     glRasterPos2f(240,350);
     declare("TRAIN ARRIVES = 'T' / 't'");
     glRasterPos2f(240,320);
     declare("RIGHT CLICK = 'Menu'");
     glRasterPos2f(240,290);
     declare("LEFT CLICK = 'Exit'");

    glColor3f(0.7921568,0.0,0.1647);
    glBegin(GL_POLYGON);
    glVertex2f(425,250);
    glVertex2f(425,250);
    glVertex2f(425,400);
    glVertex2f(450,425);
    glVertex2f(550,425);
    glVertex2f(575,400);
    glVertex2f(575,250);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(600,250);
    glVertex2f(600,400);
    glVertex2f(625,425);
    glVertex2f(725,425);
    glVertex2f(750,400);
    glVertex2f(750,250);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(775,250);
    glVertex2f(775,400);
    glVertex2f(800,425);
    glVertex2f(900,425);
    glVertex2f(925,400);
    glVertex2f(925,250);
    glEnd();

    //window 1 of railway station building
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(450,300);
    glVertex2f(450,375);
    glVertex2f(550,375);
    glVertex2f(550,300);
    glEnd();

    glColor3f(redw,greenw,bluew);
    glBegin(GL_POLYGON);
    glVertex2f(460,310);
    glVertex2f(460,365);
    glVertex2f(540,365);
    glVertex2f(540,310);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(500,375);
    glVertex2f(500,300);
    glEnd();


    //window 2 of railway station building
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(800,300);
    glVertex2f(800,375);
    glVertex2f(900,375);
    glVertex2f(900,300);
    glEnd();

    glColor3f(redw,greenw,bluew);
    glBegin(GL_POLYGON);
    glVertex2f(810,310);
    glVertex2f(810,365);
    glVertex2f(890,365);
    glVertex2f(890,310);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(850,375);
    glVertex2f(850,300);
    glEnd();

    //door of railway station building
    glColor3f(0.5098,0.28627,0.043137);
    glBegin(GL_POLYGON);
    glVertex2f(620,250);
    glVertex2f(620,385);
    glVertex2f(730,385);
    glVertex2f(730,250);
    glEnd();

    glColor3f(red,green,blue);
    glBegin(GL_POLYGON);
    glVertex2f(625,255);
    glVertex2f(625,380);
    glVertex2f(725,380);
    glVertex2f(725,255);
    glEnd();

    glColor3f(0.5098,0.28627,0.043137);
    glBegin(GL_POLYGON);
    glVertex2f(635,265);
    glVertex2f(635,370);
    glVertex2f(725,380);
    glVertex2f(725,255);
    glEnd();

    if (day != 1) {
        // Reflection from door
        red = 1;
        green = 1;
        blue = 1;
        glColor3f(red,green,blue);
        glBegin(GL_POLYGON);
        glVertex2f(625,255);
        glVertex2f(625,250);
        glVertex2f(600,225);
        glVertex2f(750,225);
        glVertex2f(725,250);
        glVertex2f(725,255);
        glEnd();
    }

    // Traffic light
	glColor3f(0.6,0.0588,0.007843);
	glBegin(GL_POLYGON);
    glVertex2f(1060,160);
	glVertex2f(1060,350);
	glVertex2f(1070,350);
	glVertex2f(1070,160);
	glEnd();


	glColor3f(0.749,0.749,0.749);
	glBegin(GL_POLYGON);
	glVertex2f(1040,350);
	glVertex2f(1040,500);
	glVertex2f(1090,500);
	glVertex2f(1090,350);
	glEnd();

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.0,0.0);
		draw_circle(1065,475,l);
		glColor3f(1.0,1.0,0.0);
		draw_circle(1065,425,l);
		glColor3f(0.0,0.0,0.0);
		draw_circle(1065,375,l);
	}

    // Chair
    glColor3f(1.0,0.498039,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(840,190);
    glVertex2f(840,210);
    glVertex2f(855,210);
    glVertex2f(855,190);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(860,207);
    glVertex2f(860,227);
    glVertex2f(875,227);
    glVertex2f(875,207);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(1020,227);
    glVertex2f(1020,207);
    glVertex2f(1005,207);
    glVertex2f(1005,227);
    glEnd();

    glColor3f(0.2,0.2,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(850,227);
    glVertex2f(850,232);
    glVertex2f(1030,232);
    glVertex2f(1030,227);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(850,236);
    glVertex2f(850,241);
    glVertex2f(1030,241);
    glVertex2f(1030,236);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(850,245);
    glVertex2f(850,250);
    glVertex2f(1030,250);
    glVertex2f(1030,245);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(850,254);
    glVertex2f(850,259);
    glVertex2f(1030,259);
    glVertex2f(1030,254);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(850,263);
    glVertex2f(850,268);
    glVertex2f(1030,268);
    glVertex2f(1030,263);
    glEnd();

    glColor3f(0.2,0.2,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(840,218);
    glVertex2f(840,223);
    glVertex2f(1040,223);
    glVertex2f(1040,218);
    glEnd();

    glColor3f(0.2,0.2,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(830,210);
    glVertex2f(830,215);
    glVertex2f(1050,215);
    glVertex2f(1050,210);
    glEnd();

    glColor3f(1.0,0.498039,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(1025,190);
    glVertex2f(1025,210);
    glVertex2f(1040,210);
    glVertex2f(1040,190);
    glEnd();

    if(train==1)
    {
        //train base
        glColor3f(0.31372549,0.31372549,0.3333333333);
        glBegin(GL_POLYGON);
        glVertex2f(350+i-xm,50);
        glVertex2f(250+i-xm,135);
        glVertex2f(250+i-xm,205);
        glVertex2f(350+i-xm,125);
        glVertex2f(755+i-xm,125);
        glVertex2f(820+i-xm,50);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(250+i-xm,135);
        glVertex2f(250+i-xm,205);
        glVertex2f(655+i-xm,205);
        glVertex2f(720+i-xm,135);
        glEnd();

        //train engine
        glColor3f(0.63137,0.6745,0.298);
        glBegin(GL_POLYGON);
        glVertex2f(560+i-xm,125);
        glVertex2f(560+i-xm,225);
        glVertex2f(755+i-xm,225);
        glVertex2f(755+i-xm,125);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(460+i-xm,175);
        glVertex2f(460+i-xm,270);
        glVertex2f(655+i-xm,270);
        glVertex2f(655+i-xm,175);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(460+i-xm,270);
        glVertex2f(560+i-xm,225);
        glVertex2f(755+i-xm,225);
        glVertex2f(655+i-xm,270);
        glEnd();

        glColor3f(0.0,0.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(580+i-xm,125);
        glVertex2f(580+i-xm,225);
        glVertex2f(590+i-xm,225);
        glVertex2f(590+i-xm,125);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(580+i-xm,225);
        glVertex2f(480+i-xm,270);
        glVertex2f(490+i-xm,270);
        glVertex2f(590+i-xm,225);
        glEnd();

        glColor3f(0.0,0.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(600+i-xm,125);
        glVertex2f(600+i-xm,225);
        glVertex2f(610+i-xm,225);
        glVertex2f(610+i-xm,125);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(600+i-xm,225);
        glVertex2f(500+i-xm,270);
        glVertex2f(510+i-xm,270);
        glVertex2f(610+i-xm,225);
        glEnd();

        glColor3f(0.0,0.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(735+i-xm,125);
        glVertex2f(735+i-xm,225);
        glVertex2f(745+i-xm,225);
        glVertex2f(745+i-xm,125);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(735+i-xm,225);
        glVertex2f(635+i-xm,270);
        glVertex2f(645+i-xm,270);
        glVertex2f(745+i-xm,225);
        glEnd();

        //train control chamber
        glColor3f(0.49,0.5333333,0.321568);
        glBegin(GL_POLYGON);
        glVertex2f(360+i-xm,125);
        glVertex2f(360+i-xm,325);
        glVertex2f(560+i-xm,325);
        glVertex2f(560+i-xm,125);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(260+i-xm,205);
        glVertex2f(260+i-xm,370);
        glVertex2f(460+i-xm,370);
        glVertex2f(460+i-xm,205);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(360+i-xm,125);
        glVertex2f(360+i-xm,325);
        glVertex2f(260+i-xm,390);
        glVertex2f(260+i-xm,205);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(350+i-xm,125);
        glVertex2f(360+i-xm,125);
        glVertex2f(260+i-xm,205);
        glVertex2f(250+i-xm,205);
        glEnd();

        //window
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(375+i-xm,175);
        glVertex2f(375+i-xm,315);
        glVertex2f(545+i-xm,315);
        glVertex2f(545+i-xm,175);
        glEnd();

        //train top
        glColor3f(0.309804,0.184314,0.184314);
        glBegin(GL_POLYGON);
        glVertex2f(350+i-xm,325);
        glVertex2f(350+i-xm,350);
        glVertex2f(570+i-xm,350);
        glVertex2f(570+i-xm,325);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(250+i-xm,370);
        glVertex2f(250+i-xm,395);
        glVertex2f(470+i-xm,395);
        glVertex2f(470+i-xm,370);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(350+i-xm,325);
        glVertex2f(350+i-xm,350);
        glVertex2f(250+i-xm,395);
        glVertex2f(250+i-xm,370);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(350+i-xm,350);
        glVertex2f(570+i-xm,350);
        glVertex2f(470+i-xm,395);
        glVertex2f(250+i-xm,395);
        glEnd();

        //train smoke
        glColor3f(0.31372549,0.31372549,0.3333333333);
        glBegin(GL_POLYGON);
        glVertex2f(635+i-xm,240);
        glVertex2f(635+i-xm,290);
        glVertex2f(685+i-xm,290);
        glVertex2f(685+i-xm,240);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(620+i-xm,245);
        glVertex2f(620+i-xm,295);
        glVertex2f(670+i-xm,295);
        glVertex2f(670+i-xm,245);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(635+i-xm,240);
        glVertex2f(635+i-xm,290);
        glVertex2f(620+i-xm,295);
        glVertex2f(620+i-xm,245);
        glEnd();

        glColor3f(0.309804,0.184314,0.184314);
        glBegin(GL_POLYGON);
        glVertex2f(625+i-xm,290);
        glVertex2f(625+i-xm,315);
        glVertex2f(695+i-xm,315);
        glVertex2f(695+i-xm,290);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(610+i-xm,295);
        glVertex2f(610+i-xm,320);
        glVertex2f(685+i-xm,320);
        glVertex2f(685+i-xm,295);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(625+i-xm,290);
        glVertex2f(625+i-xm,315);
        glVertex2f(610+i-xm,320);
        glVertex2f(610+i-xm,295);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(695+i-xm,315);
        glVertex2f(695+i-xm,290);
        glVertex2f(685+i-xm,295);
        glVertex2f(685+i-xm,320);
        glEnd();

        //train head-light
        glColor3f(1.0,1.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(755+i-xm,225);
        glVertex2f(765+i-xm,225);
        glVertex2f(765+i-xm,185);
        glVertex2f(755+i-xm,185);
        glEnd();

        glColor3f(0.0,0.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(755+i-xm,225);
        glVertex2f(785+i-xm,225);
        glVertex2f(755+i-xm,205);
        glEnd();

        // train connector
        glColor3f(0.309804,0.184314,0.184314);
        glBegin(GL_POLYGON);
        glVertex2f(345+i-xm,85);
        glVertex2f(345+i-xm,105);
        glVertex2f(295+i-xm,105);
        glVertex2f(295+i-xm,85);
        glEnd();

        //train wheels
        for(l=0;l<50;l++)
           {
            glColor3f(0.35,0.16,0.14);
            draw_circle(425+i-xm,50,l);
            draw_circle(700+i-xm,50,l);
           }

        for(l=0;l<40;l++)
           {
            glColor3f(0,0,0);
            draw_circle(425+i-xm,50,l);
            draw_circle(700+i-xm,50,l);
           }

        // train carrier back 1
        glColor3f(0.258824,0.435294,0.258824);
        glBegin(GL_POLYGON);
        glVertex2f(200+i-xm,135);
        glVertex2f(200+i-xm,385);
        glVertex2f(-800+i-xm,385);
        glVertex2f(-800+i-xm,135);
        glEnd();

        //top back
        glColor3f(0.309804,0.184314,0.184314);
        glBegin(GL_POLYGON);
        glVertex2f(210+i-xm,385);
        glVertex2f(210+i-xm,395);
        glVertex2f(-810+i-xm,395);
        glVertex2f(-810+i-xm,385);
        glEnd();

        // carrier 1 back Wheels
        for(l=0;l<50;l++)
        {
            glColor3f(0.35,0.16,0.14);
            draw_circle(-610+i-xm,130,l);
            draw_circle(-710+i-xm,130,l);
        }
        for(l=0;l<40;l++)
        {
            glColor3f(0,0,0);
            draw_circle(-610+i-xm,130,l);
            draw_circle(-710+i-xm,130,l);
        }

        // train carrier front 1
        glColor3f(0.258824,0.435294,0.258824);
        glBegin(GL_POLYGON);
        glVertex2f(300+i-xm,50);
        glVertex2f(300+i-xm,300);
        glVertex2f(-700+i-xm,300);
        glVertex2f(-700+i-xm,50);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(-700+i-xm,50);
        glVertex2f(-700+i-xm,300);
        glVertex2f(-800+i-xm,385);
        glVertex2f(-800+i-xm,135);
        glEnd();

        //top front
        glColor3f(0.309804,0.184314,0.184314);
        glBegin(GL_POLYGON);
        glVertex2f(310+i-xm,300);
        glVertex2f(310+i-xm,310);
        glVertex2f(-710+i-xm,310);
        glVertex2f(-710+i-xm,300);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(310+i-xm,310);
        glVertex2f(-710+i-xm,310);
        glVertex2f(-810+i-xm,395);
        glVertex2f(210+i-xm,395);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(-710+i-xm,300);
        glVertex2f(-710+i-xm,310);
        glVertex2f(-810+i-xm,395);
        glVertex2f(-810+i-xm,385);
        glEnd();

        // Windows
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(75+i-xm,175);
        glVertex2f(75+i-xm,285);
        glVertex2f(-85+i-xm,285);
        glVertex2f(-85+i-xm,175);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(285+i-xm,175);
        glVertex2f(285+i-xm,285);
        glVertex2f(125+i-xm,285);
        glVertex2f(125+i-xm,175);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(-510+i-xm,175);
        glVertex2f(-510+i-xm,285);
        glVertex2f(-670+i-xm,285);
        glVertex2f(-670+i-xm,175);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(-290+i-xm,175);
        glVertex2f(-290+i-xm,285);
        glVertex2f(-450+i-xm,285);
        glVertex2f(-450+i-xm,175);
        glEnd();

        // GHANA FLAG
        glColor3f(0,0,0);
        glBegin(GL_POLYGON);
        glVertex2f(-108+i-xm,103);
        glVertex2f(-108+i-xm,287);
        glVertex2f(-272+i-xm,287);
        glVertex2f(-272+i-xm,103);
        glEnd();
        glColor3f(1.0,0,0);
        glBegin(GL_POLYGON);
        glVertex2f(-110+i-xm,225);
        glVertex2f(-110+i-xm,285);
        glVertex2f(-270+i-xm,285);
        glVertex2f(-270+i-xm,225);
        glEnd();
        glColor3f(1.0,1.0,0);
        glBegin(GL_POLYGON);
        glVertex2f(-110+i-xm,165);
        glVertex2f(-110+i-xm,225);
        glVertex2f(-270+i-xm,225);
        glVertex2f(-270+i-xm,165);
        glEnd();
        glColor3f(0,0.50196,0);
        glBegin(GL_POLYGON);
        glVertex2f(-110+i-xm,105);
        glVertex2f(-110+i-xm,165);
        glVertex2f(-270+i-xm,165);
        glVertex2f(-270+i-xm,105);
        glEnd();
        // Star
        glColor3f(0,0,0);
        glBegin(GL_TRIANGLES);
        glVertex2f(-190+i-xm,185);
        glVertex2f(-205+i-xm,200);
        glVertex2f(-175+i-xm,200);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex2f(-175+i-xm,190);
        glVertex2f(-205+i-xm,190);
        glVertex2f(-190+i-xm,205);
        glEnd();

        // carrier 1 front Wheels
        for(l=0;l<50;l++)
        {
            glColor3f(0.35,0.16,0.14);
            draw_circle(50+i-xm,50,l);
            draw_circle(225+i-xm,50,l);
            draw_circle(-200+i-xm,50,l);
            draw_circle(-400+i-xm,50,l);
            draw_circle(-600+i-xm,50,l);
        }
        for(l=0;l<40;l++)
        {
            glColor3f(0,0,0);
            draw_circle(50+i-xm,50,l);
            draw_circle(225+i-xm,50,l);
            draw_circle(-200+i-xm,50,l);
            draw_circle(-400+i-xm,50,l);
            draw_circle(-600+i-xm,50,l);
        }

        // wheel connector
        glColor3f(0.35,0.16,0.14);
        glBegin(GL_POLYGON);
        glVertex2f(-600+i-xm,47);
        glVertex2f(225+i-xm,47);
        glVertex2f(225+i-xm,53);
        glVertex2f(-600+i-xm,53);
        glEnd();
    }

     if(day == 1) {
        redb = 1.0;
        greenb = 1.0;
        blueb = 1.0;
        redw = 0.349;
        greenw = 0.396;
        bluew = 0.427;
     } else {
        redb = 0.0;
        greenb = 0.0;
        blueb = 0.0;
        redw = 0.615686;
        greenw = 0.6588;
        bluew = 0.6862745;
     }

    glFlush();
}

void idle()
{
    glClearColor(1.0,1.0,1.0,1.0);
    if(light==0 && (i>=0 && i<=1150))
    {
        i+=SPEED/10;
        m+=SPEED/150;
        n-=2;
        o+=0.2;
        c+=2;
    }

     if(light==0 && (i>=2600 && i<=3000))
     {
        i+=SPEED/10;
        m+=SPEED/150;
        n-=2;
        o+=0.2;
        c+=2;
     }

    if(light==0)
    {
        i=i;
        m+=SPEED/150;
        n-=2;
        o+=0.2;
        c+=2;
    }   else
        {
            i+=SPEED/10;
            m+=SPEED/150;
            n-=2;
            o+=0.2;
            c+=2;
        }

    if(i>3500)
         i=0.0;
    if(m>1100)
         m=0.0;
    if( o>75)
    {
       plane=0;
    }
    if(c>500)
    {
        comet=0;
    }

    glutPostRedisplay();

}

void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_UP)
exit(0);
}

void keyboardFunc( unsigned char key, int x, int y )
{
switch( key )
    {
    case 'g':
    case 'G':
        light=1;
        break;
	case 'r':
	case 'R':
		light=0;
		break;
    case 'd':
	case 'D':
		day=1;
		break;
	case 'n':
    case 'N':
		day=0;
		break;
	case 't':
    case 'T':
		train=1;
		i=0;
		break;
    };
}

void main_menu(int index)
{
	switch(index)
	{
	case 1:
	if(index==1)
	 {
	plane=1;
		 o=n=0.0;
	 }
	break;

	case 2:
	if(index==2)
	 {
		comet=1;
		 c=0.0;
	 }
	break;
	}
}

void myinit()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(0.0,0.0,1.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,1100.0,0.0,700.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    draw_object();
    traffic_light();
    glFlush();
}

int main(int argc,char** argv)
{
    int c_menu;
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1100.0,700.0);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Train Station");
	glutDisplayFunc(display);
    glutIdleFunc(idle);
	glutKeyboardFunc(keyboardFunc);
	glutMouseFunc(mouse);
	myinit();
	c_menu=glutCreateMenu(main_menu);
	glutAddMenuEntry("Aeroplane",1);
	glutAddMenuEntry("Comet",2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}

/*
* ANSWERS
*(1) OpenGL (C++ programming language)
*
*(2) Some reasons for choosing this technology are:
*   I.   OpenGL is a cross-platform compatibility: it is available on wide range of platforms, including Windows, macOS,
         Linux, and mobile platforms such as iOS and Android.

*   II.  Wide adoption: OpenGL is widely used in the industry and has a large community of developers who share knowledge
         and create tools and resources for the API.

*   III. Flexibility: OpenGL is a low-level API that gives developers a lot of control over the graphics pipeline. This
         allows for the implementation of custom rendering algorithms and optimizations that may not be possible with
         higher-level API.

*   IV.  Performance: OpenGL is known for its high performance and efficiency. It is design to work directly with graphics
         hardware, allowing for fast rendering of complex scenes and animations.

*   V.   Compatibility with other technologies: OpenGL can be used in conjunction with other technologies, such as OpenCL for
         general-purpose computing on the GPU, and OpenAL for 3D audio processing.
*/
