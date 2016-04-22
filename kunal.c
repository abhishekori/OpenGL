#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

GLfloat x = 0.0, y = 0.0, x1 = 0.0, x2 = 0.0, y2 = 0.0, x3 = 0.0, y3 = 0.0, x4 = 0.0, y4 = 0.0, x5 = 0.0, y5 = 0.0;
GLfloat x6 = 0.0, y6 = 0.0, x7 = 0.0, y7 = 0.0, x8 = 0.0, y8 = 0.0, x9 = 0.0, y9 = 0.0, x10 = 0.0, y10 = 0.0;
GLfloat x11 = 0.0, y11 = 0.0, x12 = 0.0, y12 = 0.0;
GLfloat z1 = 0.0, z3 = 0.0, z2 = 0.0, z4 = 0.0, z5 = 0.0, z6 = 0.0, z7 = 0.0, z8 = 0.0;

bool drawpacket = true, drawpacket1 = true, drawpacket2 = true, drawpacket3 = true, drawpacket4 = true, drawpacket5 = true;
bool drawpacket6 = true, drawpacket7 = true, drawpacket8 = true, drawpacket9 = true, drawpacket10 = true, drawpacket11 = true;
bool drawpacket12 = true, drawpacket20 = true;

GLint cntr = 40, cntr1 = 40, cntr2 = 0, cntr3 = 0, cntr4 = 0, cntr5 = 0, cntr6 = 0, cntr7 = 0, cntr12 = 0, cntr18 = 0, cntr20 = 0;
GLint cntr25 = 0, cntr26 = 0, cntr28 = 0, cntr17 = 0, cntr30 = 0, cntr35 = 0, cntr36 = 0, cntr37 = 0, cntr38 = 0, cntr40 = 0;

GLint new1 = 0, new2 = 0, new3 = 0, new4 = 0, new5 = 0, new6 = 0;


void display();

void menu1();
void menu2();
void menu3();
void option1();
void option2();

void keybox(GLint, GLint, GLint, GLint);
void square(GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint);

void dining_text();

void circle(GLfloat, GLfloat, GLdouble);

void cylinder_draw(GLint, GLint, GLint);
void circle_draw(GLint, GLint, GLint);
void plot_pixel(GLint, GLint, GLint, GLint);
void draw_pixel(GLint, GLint);

void plate(GLfloat, GLfloat, GLdouble);
void stool(float, float, double);
void legs(GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint);
void chopsticks(GLint, GLint, GLint, GLint);

void draw_line11(GLint,GLint,GLint,GLint,GLint);
void draw_line21(GLfloat, GLfloat, GLfloat, GLfloat, GLint);
void draw_line31(GLfloat, GLfloat, GLfloat, GLfloat, GLint);
void man();
void hand_move();
void hand_move2();

void chopstick1_move();
void chopstick2_move();
void window();

void philo_walls();
void dine_light();
void rice();
void clock();

void sky();
void buildings();
void wires();
void objects();
void bush();
void roads();
void light_pole();

void packet1();
void packet1_move();
void packet12_move();
void packet13_move();

void packet21_move();
void packet22_move();

void packet31_move();
void packet32_move();

void packet41_move();
void packet42_move();

void step();
void step1();
void step2();
void step3();
void step4();
void step5();

int f = 1;

void *fonts[] = { GLUT_BITMAP_9_BY_15,
				  GLUT_BITMAP_TIMES_ROMAN_10,
				  GLUT_BITMAP_TIMES_ROMAN_24,
				  GLUT_BITMAP_HELVETICA_18,
                  GLUT_BITMAP_HELVETICA_12 };

void myMenu(int id)
{
	switch (id)
	{
	case 1: glutDisplayFunc(menu1);
		break;
	case 2: glutDisplayFunc(option1);
		break;
	case 3: //menu14();
		//glutDisplayFunc(option2);
		break;
	case 4: exit(0);
		break;
	}
}

				//**********printing_text**********//

void output(int x, int y, char *string, void *font)
{
	int len, i;
	glRasterPos2f(x, y);
	len = (int)strlen(string);
	for (i = 0; i<len; i++)
	{
		glutBitmapCharacter(font, string[i]);
	}
}

				//**********first_window**********//

void menu1()
{
	glColor3f(0.545098039, 0.211764705, 0.149019607);
	output(300, 550, "Dining Philosophers Problem & Flooding Algorithm", fonts[2]);

	glColor3f(0.545098039, 0.270588235, 0.074509803);
	output(440, 450, "SUBMITTED BY", fonts[0]);

	glColor3f(0.545098039, 0.270588255, 0.0);
	output(360, 400, "Kunal Kumar Gupta", fonts[3]);
	output(360, 360, "Rahul Chanda", fonts[3]);
	output(360, 320, "Rakshitha V.N.", fonts[3]);

	glColor3f(0.545098039, 0.270588255, 0.0);
	output(525, 400, "1DS12CS044", fonts[0]);
	output(525, 360, "1DS12CS072", fonts[0]);
	output(525, 320, "1DS12CS074", fonts[0]);

	glColor3f(0.545098039, 0.270588235, 0.074509803);
	output(380, 200, " Press any key to continue", fonts[0]);
}

				//**********second_window**********//

void menu2()
{
	glColor3f(0.545098039, 0.211764705, 0.149019607);
	output(300, 550, "Dining Philosophers Problem & Flooding Algorithm", fonts[2]);

	glColor3f(0.545098039, 0.101960784, 0.101960784);
	output(450, 450, "MENU", fonts[3]);

	glColor3f(0.545098039, 0.298039215, 0.223529411);
	output(430, 420, "1. START", fonts[0]);
	output(430, 380, "2. INTRODUCTION", fonts[0]);
	output(430, 340, "3. HELP", fonts[0]);
	output(430, 300, "4. EXIT", fonts[0]);

	glColor3f(0.545098039, 0.270588235, 0.074509803);
	output(380, 200, " Press any key to continue", fonts[0]);
}

				//**********third_window**********//

void menu3()
{
	glColor3f(0.545098039, 0.211764705, 0.149019607);
	output(110, 550, "Dining Philosophers Problem", fonts[2]);
	output(650, 550, "Flooding Algorithm", fonts[2]);

	glColor3f(0.62745098, 0.321568627, 0.176470588);
	output(60, 450, "The Dining Philosophers Problem is a classic example for the", fonts[3]);
	output(60, 430, "synchronisation problem. This problem is a simple example to", fonts[3]);
	output(60, 410, "show the deadlock process in the operating system.", fonts[3]);
	output(60, 370, "Semaphores are used to solve this synchronisation problem.", fonts[3]);
	output(550, 450, "Flooding algorithm is used in computer networks. It is a", fonts[3]);
	output(550, 430, "technique to route the packets in the network.", fonts[3]);
	output(550, 390, "The node transmits the packet to all the other nodes in the network", fonts[3]);
	output(550, 370, "except from which it has already received packets from.", fonts[3]);

	glColor3f(0.545098039, 0.270588235, 0.074509803);
	output(330, 180, " Press 'p' or 'P' for Philosopher Dining Problem", fonts[0]);
	output(365, 150, " Press 'd' or 'D' for Flooding Algorithm", fonts[0]);
}

				//**********dining_philosophers**********//

void option1()
{
	glColor3f(0.545098039, 0.211764705, 0.149019607);
	output(100, 580, "Dininig Philosophers Problem", fonts[2]);
	philo_walls();

	glColor3f(0.647059, 0.164706, 0.164706);
	cylinder_draw(480, 250, 100);
	circle(480,300,100);			//table

	glColor3f(1.0, 1.0, 1.0);
	circle(480,300,35);				//main_plate

	plate(410,320,20);				//1st plate
	plate(550,320,20);				//2nd plate
	plate(480,370,20);				//3rd plate
	plate(435, 245, 20);			//4th plate
	plate(525,245,20);				//5th plate

	clock();

	legs(340, 310, 270, 350, 310, 260, 360, 310, 270);
	legs(600, 310, 270, 610, 310, 260, 620, 310, 270);
	legs(470, 400, 450, 480, 400, 455, 490, 400, 465);
	legs(360, 190, 120, 370, 190, 110, 380, 190, 120);
	legs(580, 190, 120, 590, 190, 110, 600, 190, 120);

	stool(350, 325, 25);
	stool(610, 325, 25);
	stool(480, 450, 25);
	stool(370, 175, 25);
	stool(590, 175, 25);

	rice();

	glColor3f(0.803921568, 0.745098039, 0.439215686);
	chopsticks(515, 345, 540, 370);

	chopstick1_move();
	chopstick2_move();

	hand_move();
	hand_move2();

	dining_text();

	man();
}

				//**********flooding_algorithm**********//

void option2()
{
	sky();
	bush();
	roads();
	buildings();
	objects();
	wires();
	light_pole();

	packet1();
	packet1_move();
	packet12_move();
	packet13_move();

	if (new1 == 1)
		packet21_move();

	if (new2 == 1)
		packet22_move();

	if (new3 == 1)
		packet31_move();

	if (new4 == 1)
		packet32_move();

	if (new5 == 1)
		packet41_move();

	if (new6 == 1)
		packet42_move();

	glColor3f(0.545098039, 0.211764705, 0.149019607);
	output(450, 600, "Flooding Algorithm", fonts[2]);
}

				//**********introduction_window**********//

void intro()
{

	//glColor3f(0.8, .1, .2);
	glColor3f(0.545098039, 0.211764705, 0.149019607);
	output(415, 550, "INTRODUCTION", fonts[2]);
	//glColor3f(1, 0, 1);
	glColor3f(0.62745098, 0.321568627, 0.176470588);
	output(210, 420, "The Philosophers Dining Problem gives the user an example of the synchronisation problem.", fonts[3]);
	output(210, 385, "This synchronisation problem is solved using semaphore.", fonts[3]);
	output(210, 345, "The Flooding Algorithm is a simple algorithm for the transfer of data packets between different nodes.", fonts[3]);
	//glColor3f(0.1, 0.1, 0.1);
	glColor3f(0.545098039, 0.270588235, 0.074509803);
	output(385, 180, "Press 'ENTER' key to continue", fonts[0]);
	output(475, 150, "OR", fonts[0]);
	output(375, 120, "Press 'b' or 'B' key to continue", fonts[0]);
	glColor3f(0.5, .6, .1);
}

				//**********help_window**********//

void help()
{

	//glColor3f(0.8, .1, .2);
	glColor3f(0.545098039, 0.211764705, 0.149019607);
	output(470, 400, "HELP", fonts[2]);
	//glColor3f(1, 0, 1);
	glColor3f(0.62745098, 0.321568627, 0.176470588);
	output(330, 350, "Select anyone algorithm by pressing 'p' or 'P' and 'd' or 'D'.", fonts[3]);
	//glColor3f(0.1, 0.1, 0.1);
	glColor3f(0.545098039, 0.270588235, 0.074509803);
	output(410, 180, " Press 'ENTER' to continue", fonts[0]);
	output(485, 150, "OR", fonts[0]);
	output(390, 120, "Press 'b' or 'B' key to continue", fonts[0]);
	glColor3f(0.5, .6, .1);

}

				//**********line_drawing_function**********//

void keybox(GLint x5, GLint y5, GLint x6, GLint y6)
{
	glBegin(GL_LINES);
	glVertex2f(x5, y5);
	glVertex2f(x6, y6);
	glEnd();
}

				//**********polygon_drawing_function**********//

void square(GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3, GLint x4, GLint y4)
{
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
}

				//**********text_for_philosophers**********//

void dining_text()
{
	//glColor3f(0.0, 0.0, 0.0);
	glColor3f(0.545098039, 0.211764705, 0.149019607);
	output(110, 550, "Dining Philosophers Problem", fonts[2]);
	glColor3f(0.0, 0.0, 0.0);

	//glColor3f(1.0, 1.0, 1.0);
	glColor3f(0.62745098, 0.321568627, 0.176470588);
	output(750, 430, "Two Philosophers pick up the ", fonts[3]);
	output(750, 410, "chopsticks and the other 3 cannot eat.", fonts[3]);
	//output(750, 390, "and the other 3 cannot eat.", fonts[3]);
	output(750, 390, "This is a simple example of a deadlock", fonts[3]);
	output(750, 370, "condition.", fonts[3]);
	output(750, 330, "The other philosophers can eat only", fonts[3]);
	output(750, 310, "when the chopsticks become free.", fonts[3]);
	//output(750, 340, "become free.", fonts[3]);
}

				//**********circle_draw**********//

void circle(GLfloat r1, GLfloat r2, GLdouble r3)
{
	float x1, y1, x2, y2;
	float angle;
	double radius = r3;
	x1 = r1, y1 = r2;
	glPointSize(2.0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1, y1);
	for (angle = 1.0; angle < 361.0f; angle += 0.2)
	{
		x2 = x1 + sin(angle)*radius;
		y2 = y1 + cos(angle)*radius;
		glVertex2f(x2, y2);
	}
	glEnd();
}

				//**********plate_draw**********//

void plate(GLfloat t1, GLfloat t2, GLdouble t3)
{
	float x1, y1, x2, y2;
	float angle;
	double radius = t3;
	x1 = t1, y1 = t2;
	glColor3f(1.0, 1.0, 1.0);
	glPointSize(2.0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1, y1);
	for (angle = 1.0; angle < 361.0f; angle += 0.2)
	{
		x2 = x1 + sin(angle)*radius;
		y2 = y1 + cos(angle)*radius;
		glVertex2f(x2, y2);
	}
	glEnd();
}

				//**********window_draw**********//

void window(GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3, GLint x4, GLint y4)
{
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(5.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
}

			//**********men_in_dining_philosophers**********//

void man()
{
	glLineWidth(4.0);
	glColor3f(0.0,0.0,0.0);			//man1
	circle(360, 428, 20);			//face

	keybox(360, 380, 360, 420);		//neck

	square(350, 380, 370, 410, 370, 335, 350, 300);			//body

	glColor3f(0.0, 0.0, 0.0);
	keybox(350, 380, 360, 310);
	keybox(370, 408, 395, 380);

	glColor3f(1.0, 0.0, 0.0);
	keybox(350, 300, 370, 300);
	keybox(370, 300, 368, 280);

	glColor3f(1.0, 0.0, 0.0);
	keybox(368, 333, 382, 331);
	keybox(382, 331, 378, 300);

	glLineWidth(4.0);
	glColor3f(0.0, 0.0, 0.0);			//man2
	circle(600, 430, 20);				//face

	keybox(600, 380, 600, 420);			//neck

	square(590, 410, 610, 380, 610, 300, 590, 335);		//body

	glColor3f(0.0, 0.0, 0.0);
	keybox(590, 410, 565, 380);				//left_hand
	keybox(565, 380, 520, 370);
	glColor3f(0.0, 0.0, 0.0);
	keybox(610, 380, 585, 345);				//right_hand
	keybox(585, 345, 540, 335);

	glColor3f(1.0, 0.0, 0.0);
	keybox(592, 335, 575, 335);
	keybox(575, 335, 585, 315);

	glColor3f(1.0, 0.0, 0.0);
	keybox(610, 300, 590, 300);
	keybox(590, 300, 605, 280);

	glLineWidth(4.0);
	glColor3f(0.0, 0.0, 0.0);			//man3
	circle(480, 540, 20);				//face

	keybox(480, 520, 480, 500);			//neck

	square(465,500,495,500,495,440,465,440);

	glColor3f(1.0, 0.0, 0.0);
	keybox(465, 440, 465, 420);
	keybox(465, 420, 470, 400);
	keybox(495, 440, 497, 420);
	keybox(497, 420, 490, 400);

	glColor3f(0.0, 0.0, 0.0);
	keybox(465, 500, 455, 470);
	keybox(455, 470, 455, 430);

	glColor3f(0.0, 0.0, 0.0);
	keybox(495, 500, 505, 470);
	keybox(505, 470, 505, 430);

	glLineWidth(4.0);
	glColor3f(0.0, 0.0, 0.0);			//man4
	circle(370, 250, 20);				//face

	keybox(370, 250, 370, 220);			//neck

	glColor3f(0.0, 0.0, 0.0);
	keybox(355, 220, 365, 200);
	keybox(365, 200, 400, 250);
	glColor3f(0.0, 0.0, 0.0);
	keybox(385, 220, 395, 200);
	keybox(395, 200, 435, 220);

	glColor3f(0.0, 0.0, 0.0);
	square(355, 225, 385, 220, 385, 160, 355, 165);



	glColor3f(1.0, 0.0, 0.0);
	keybox(385, 160, 395, 185);
	keybox(395, 185, 400, 150);


	glLineWidth(4.0);
	glColor3f(0.0, 0.0, 0.0);			//man5
	circle(590, 250, 20);				//face

	keybox(590, 250, 590, 220);			//neck


	glColor3f(0.0, 0.0, 0.0);
	square(575, 220, 605, 225, 605, 170, 575, 165);

	glColor3f(0.0, 0.0, 0.0);			//hand
	keybox(575, 220, 575, 200);


	glColor3f(1.0, 0.0, 0.0);
	keybox(575, 165, 565, 185);
	keybox(565, 185, 555, 150);
}

			//**********rice_in_plates**********//

void rice()
{
	glColor3f(1.0, 0.5647058824, 0.0);

	glPointSize(3.0);
	glBegin(GL_POINTS);

	glVertex2f(475, 320);
	glVertex2f(485, 330);
	glVertex2f(495, 320);
	glVertex2f(500, 315);
	glVertex2f(500, 305);
	glVertex2f(500, 300);
	glVertex2f(490, 315);
	glVertex2f(485, 310);
	glVertex2f(500, 312);
	glVertex2f(500, 305);
	glVertex2f(490, 295);
	glVertex2f(497, 285);
	glVertex2f(475, 315);
	glVertex2f(490, 300);
	glVertex2f(478, 300);
	glVertex2f(458, 300);
	glVertex2f(455, 315);
	glVertex2f(465, 300);

	glVertex2f(465, 285);
	glVertex2f(475, 295);
	glVertex2f(485, 285);

	glVertex2f(490, 310);
	glVertex2f(500, 320);
	glVertex2f(510, 290);

	glVertex2f(400, 310);
	glVertex2f(410, 320);
	glVertex2f(420, 310);

	glVertex2f(405, 325);
	glVertex2f(415, 335);
	glVertex2f(425, 325);

	glVertex2f(540, 310);
	glVertex2f(550, 320);
	glVertex2f(560, 310);

	glVertex2f(545, 325);
	glVertex2f(555, 335);
	glVertex2f(565, 325);

	glVertex2f(470, 360);
	glVertex2f(480, 370);
	glVertex2f(490, 360);

	glVertex2f(465, 370);
	glVertex2f(475, 380);
	glVertex2f(485, 370);

	glVertex2f(425, 245);
	glVertex2f(435, 245);
	glVertex2f(445, 235);
	glVertex2f(445, 242);
	glVertex2f(430, 245);
	glVertex2f(440, 235);
	glVertex2f(420, 240);
	glVertex2f(425, 250);
	glVertex2f(435, 240);

	glVertex2f(515, 235);
	glVertex2f(525, 245);
	glVertex2f(535, 235);

	glVertex2f(510, 240);
	glVertex2f(515, 250);
	glVertex2f(525, 240);
	glEnd();
}

			//**********functions_for_table_base**********//

void cylinder_draw(GLint z1, GLint z2, GLint z3)
{
	GLint xc = z1, yc = z2, r = z3;
	glColor3f(0.36, 0.25, 0.20);
	GLint i, n = 50;
	for (i = 0; i<n; i += 3)
		circle_draw(xc, yc + i, r);
}

void circle_draw(GLint h, GLint k, GLint r)
{
	GLint d = 1 - r, x = 0, y = r;
	while (y>x)
	{
		plot_pixel(h, k, x, y);
		if (d<0)  d += 2 * x + 3;
		else
		{
			d += 2 * (x - y) + 5;
			--y;
		} ++x;
	}
	plot_pixel(h, k, x, y);
}

void plot_pixel(GLint h, GLint k, GLint x, GLint y)
{
	draw_pixel(x + h, y + k);
	draw_pixel(-x + h, y + k);
	draw_pixel(x + h, -y + k);
	draw_pixel(-x + h, -y + k);
	draw_pixel(y + h, x + k);
	draw_pixel(-y + h, x + k);
	draw_pixel(y + h, -x + k);
	draw_pixel(-y + h, -x + k);
}

void draw_pixel(GLint cx, GLint cy)
{

	glBegin(GL_POINTS);
	glVertex2f(cx, cy);
	glEnd();
}

							//**********stool_draw_function**********//

void stool(float a, float b, double r)
{
	float x1, y1, x2, y2;
	float angle;
	double radius = r;
	x1 = a, y1 = b;
	glColor3f(1.0, 1.0, 1.0);
	glPointSize(2.0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1, y1);
	for (angle = 1.0; angle < 361.0f; angle += 0.2)
	{
		x2 = x1 + sin(angle)*radius;
		y2 = y1 + cos(angle)*radius;
		glVertex2f(x2, y2);
	}
	glEnd();
}

							//**********legs_of_stool**********//

void legs(GLint m, GLint n, GLint p, GLint q, GLint r, GLint s, GLint t, GLint u, GLint v)
{
	GLint x1 = m, y1 = n, y2 = p;
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(4.0);
	glBegin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x1, y2);
	glEnd();

	GLint x3 = q, y3 = r, y4 = s;
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(4.0);
	glBegin(GL_LINES);
	glVertex2i(x3, y3);
	glVertex2i(x3, y4);
	glEnd();

	GLint x5 = t, y5 = u, y6 = v;
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(4.0);
	glBegin(GL_LINES);
	glVertex2i(x5, y5);
	glVertex2i(x5, y6);
	glEnd();
}

							//**********chopsticks_draw**********//

void chopsticks(GLint p1, GLint p2, GLint p3, GLint p4)
{
	GLint g = p1, h = p2, k = p3, l = p4;
//	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(4.0);
	glBegin(GL_LINES);
	glVertex2i(g, h);
	glVertex2i(k, l);
	glEnd();
}

							//**********buildings**********//

void buildings()
{
	glColor3f(1.0, 0.0, 0.0);			//1st building
	glLineWidth(3.0);
	glBegin(GL_POLYGON);
	glVertex2i(150, 350);
	glVertex2i(150, 550);
	glVertex2i(170, 570);
	glVertex2i(310, 570);
	glVertex2i(310, 370);
	glVertex2i(290, 350);
	glVertex2i(290, 550);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(150, 350);
	glVertex2i(150, 550);
	glVertex2i(170, 570);
	glVertex2i(310, 570);
	glVertex2i(310, 370);
	glVertex2i(290, 350);
	glVertex2i(290, 550);
	glVertex2i(150, 550);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(290, 550);
	glVertex2i(310, 570);
	glVertex2i(290, 350);
	glVertex2i(150, 350);
	glEnd();

	glColor3f(0.752941, 0.752941, 0.752941);			//2nd building
	glBegin(GL_POLYGON);
	glVertex2i(750, 350);
	glVertex2i(750, 550);
	glVertex2i(770, 570);
	glVertex2i(910, 570);
	glVertex2i(910, 370);
	glVertex2i(890, 350);
	glVertex2i(890, 550);
	glVertex2i(750, 550);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(750, 350);
	glVertex2i(750, 550);
	glVertex2i(770, 570);
	glVertex2i(910, 570);
	glVertex2i(910, 370);
	glVertex2i(890, 350);
	glVertex2i(890, 550);
	glVertex2i(750, 550);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(890, 550);
	glVertex2i(910, 570);
	glVertex2i(890, 350);
	glVertex2i(750, 350);
	glEnd();

	glColor3f(0.59, 0.41, 0.31);			//3rd building
	glBegin(GL_POLYGON);
	glVertex2i(130, 50);
	glVertex2i(130, 250);
	glVertex2i(150, 270);
	glVertex2i(290, 270);
	glVertex2i(290, 70);
	glVertex2i(270, 50);
	glVertex2i(270, 270);
	//glVertex2i(150, 200);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(130, 50);
	glVertex2i(130, 250);
	glVertex2i(150, 270);
	glVertex2i(290, 270);
	glVertex2i(290, 70);
	glVertex2i(270, 50);
	glVertex2i(270, 250);
	glVertex2i(130, 250);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(270, 250);
	glVertex2i(290, 270);
	glVertex2i(270, 50);
	glVertex2i(130, 50);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);			//4th building
	glBegin(GL_POLYGON);
	glVertex2i(730, 50);
	glVertex2i(730, 250);
	glVertex2i(750, 270);
	glVertex2i(890, 270);
	glVertex2i(890, 70);
	glVertex2i(870, 50);
	glVertex2i(870, 250);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(730, 50);
	glVertex2i(730, 250);
	glVertex2i(750, 270);
	glVertex2i(890, 270);
	glVertex2i(890, 70);
	glVertex2i(870, 50);
	glVertex2i(870, 250);
	glVertex2i(730, 250);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(870, 250);
	glVertex2i(890, 270);
	glVertex2i(870, 50);
	glVertex2i(730, 50);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);			//pole1
	glBegin(GL_POLYGON);
	glVertex2i(380, 350);
	glVertex2i(380, 490);
	glVertex2i(390, 500);
	glVertex2i(405, 500);
	glVertex2i(405, 360);
	glVertex2i(395, 350);
	glVertex2i(395, 490);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(380, 350);
	glVertex2i(380, 490);
	glVertex2i(390, 500);
	glVertex2i(405, 500);
	glVertex2i(405, 360);
	glVertex2i(395, 350);
	glVertex2i(395, 490);
	glVertex2i(380, 490);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(395, 490);
	glVertex2i(405, 500);
	glVertex2i(395, 350);
	glVertex2i(380, 350);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);			//pole1_top
	glBegin(GL_TRIANGLES);
	glVertex2i(370, 480);
	glVertex2i(390, 510);
	glVertex2i(410, 480);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2i(390, 510);
	glVertex2i(400, 520);
	glVertex2i(420, 490);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(390, 510);
	glVertex2i(400, 520);
	glVertex2i(420, 490);
	glVertex2i(410, 480);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);			//pole2
	glBegin(GL_POLYGON);
	glVertex2i(680, 350);
	glVertex2i(680, 490);
	glVertex2i(690, 500);
	glVertex2i(705, 500);
	glVertex2i(705, 360);
	glVertex2i(695, 350);
	glVertex2i(695, 490);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(680, 350);
	glVertex2i(680, 490);
	glVertex2i(690, 500);
	glVertex2i(705, 500);
	glVertex2i(705, 360);
	glVertex2i(695, 350);
	glVertex2i(695, 490);
	glVertex2i(680, 490);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(695, 490);
	glVertex2i(705, 500);
	glVertex2i(695, 350);
	glVertex2i(680, 350);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);			//pole2_top
	glBegin(GL_TRIANGLES);
	glVertex2i(670, 480);
	glVertex2i(690, 510);
	glVertex2i(710, 480);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2i(690, 510);
	glVertex2i(700, 520);
	glVertex2i(720, 490);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(690, 510);
	glVertex2i(700, 520);
	glVertex2i(720, 490);
	glVertex2i(710, 480);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);			//pole3
	glBegin(GL_POLYGON);
	glVertex2i(340, 50);
	glVertex2i(340, 190);
	glVertex2i(350, 200);
	glVertex2i(365, 200);
	glVertex2i(365, 60);
	glVertex2i(355, 50);
	glVertex2i(355, 190);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(340, 50);
	glVertex2i(340, 190);
	glVertex2i(350, 200);
	glVertex2i(365, 200);
	glVertex2i(365, 60);
	glVertex2i(355, 50);
	glVertex2i(355, 190);
	glVertex2i(340, 190);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(355, 190);
	glVertex2i(365, 200);
	glVertex2i(355, 50);
	glVertex2i(340, 50);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);			//pole3_top
	glBegin(GL_TRIANGLES);
	glVertex2i(330, 180);
	glVertex2i(350, 210);
	glVertex2i(370, 180);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2i(350, 210);
	glVertex2i(360, 220);
	glVertex2i(380, 190);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(350, 210);
	glVertex2i(360, 220);
	glVertex2i(380, 190);
	glVertex2i(370, 180);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);			//pole4
	glBegin(GL_POLYGON);
	glVertex2i(640, 50);
	glVertex2i(640, 190);
	glVertex2i(650, 200);
	glVertex2i(665, 200);
	glVertex2i(665, 60);
	glVertex2i(655, 50);
	glVertex2i(655, 190);
	glVertex2i(640, 190);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(640, 50);
	glVertex2i(640, 190);
	glVertex2i(650, 200);
	glVertex2i(665, 200);
	glVertex2i(665, 60);
	glVertex2i(655, 50);
	glVertex2i(655, 190);
	glVertex2i(640, 190);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(655, 190);
	glVertex2i(665, 200);
	glVertex2i(655, 50);
	glVertex2i(640, 50);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);			//pole4_top
	glBegin(GL_TRIANGLES);
	glVertex2i(630, 180);
	glVertex2i(650, 210);
	glVertex2i(670, 180);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2i(650, 210);
	glVertex2i(660, 220);
	glVertex2i(680, 190);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(650, 210);
	glVertex2i(660, 220);
	glVertex2i(680, 190);
	glVertex2i(670, 180);
	glEnd();

	glColor3f(0.647059, 0.164706, 0.164706);
	glLineWidth(3.0);
	glBegin(GL_POLYGON);			//door1
	glVertex2i(195, 350);
	glVertex2i(195, 375);
	glVertex2i(245, 375);
	glVertex2i(245, 350);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	square(195, 350, 210, 360, 210, 365, 195, 375);
	square(245, 350, 230, 360, 230, 365, 245, 375);

	glBegin(GL_LINE_LOOP);			//1st floor window no1
	glVertex2i(165, 385);
	glVertex2i(165, 415);
	glVertex2i(195, 415);
	glVertex2i(195, 385);
	glEnd();

	glBegin(GL_LINE_LOOP);			//1st floor window no2
	glVertex2i(205, 385);
	glVertex2i(205, 415);
	glVertex2i(235, 415);
	glVertex2i(235, 385);
	glEnd();

	glBegin(GL_LINE_LOOP);			//1st floor window no3
	glVertex2i(245, 385);
	glVertex2i(245, 415);
	glVertex2i(275, 415);
	glVertex2i(275, 385);
	glEnd();

	glBegin(GL_LINE_LOOP);			//1st floor window no4
	glVertex2i(295, 385);
	glVertex2i(295, 415);
	glVertex2i(305, 425);
	glVertex2i(305, 395);
	glEnd();

	glBegin(GL_LINE_LOOP);			//2nd floor window no1
	glVertex2i(165, 425);
	glVertex2i(165, 455);
	glVertex2i(195, 455);
	glVertex2i(195, 425);
	glEnd();

	glBegin(GL_LINE_LOOP);			//2nd floor window no2
	glVertex2i(205, 425);
	glVertex2i(205, 455);
	glVertex2i(235, 455);
	glVertex2i(235, 425);
	glEnd();

	glBegin(GL_LINE_LOOP);			//2nd floor window no3
	glVertex2i(245, 425);
	glVertex2i(245, 455);
	glVertex2i(275, 455);
	glVertex2i(275, 425);
	glEnd();

	glBegin(GL_LINE_LOOP);			//2nd floor window no4
	glVertex2i(295, 425);
	glVertex2i(295, 455);
	glVertex2i(305, 465);
	glVertex2i(305, 435);
	glEnd();


	glBegin(GL_LINE_LOOP);			//3rd floor window no1
	glVertex2i(165, 465);
	glVertex2i(165, 495);
	glVertex2i(195, 495);
	glVertex2i(195, 465);
	glEnd();

	glBegin(GL_LINE_LOOP);			//3rd floor window no2
	glVertex2i(205, 465);
	glVertex2i(205, 495);
	glVertex2i(235, 495);
	glVertex2i(235, 465);
	glEnd();

	glBegin(GL_LINE_LOOP);			//3rd floor window no3
	glVertex2i(245, 465);
	glVertex2i(245, 495);
	glVertex2i(275, 495);
	glVertex2i(275, 465);
	glEnd();

	glBegin(GL_LINE_LOOP);			//3rd floor window no4
	glVertex2i(295, 465);
	glVertex2i(295, 495);
	glVertex2i(305, 505);
	glVertex2i(305, 475);
	glEnd();
	glBegin(GL_LINE_LOOP);			//4th floor window no1
	glVertex2i(165, 505);
	glVertex2i(165, 535);
	glVertex2i(195, 535);
	glVertex2i(195, 505);
	glEnd();

	glBegin(GL_LINE_LOOP);			//4th floor window no2
	glVertex2i(205, 505);
	glVertex2i(205, 535);
	glVertex2i(235, 535);
	glVertex2i(235, 505);
	glEnd();

	glBegin(GL_LINE_LOOP);			//4th floor window no3
	glVertex2i(245, 505);
	glVertex2i(245, 535);
	glVertex2i(275, 535);
	glVertex2i(275, 505);
	glEnd();

	glBegin(GL_LINE_LOOP);			//2nd floor window no4
	glVertex2i(295, 505);
	glVertex2i(295, 535);
	glVertex2i(305, 545);
	glVertex2i(305, 515);
	glEnd();


	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);    //door2
	glVertex2i(795, 350);
	glVertex2i(795, 375);
	glVertex2i(845, 375);
	glVertex2i(845, 350);
	glEnd();

	//glColor3f(0.0, 0.0, 0.0);
	glColor3f(0.647059, 0.164706, 0.164706);
	square(795, 350, 810, 360, 810, 365, 795, 375);
	square(845, 350, 830, 360, 830, 365, 845, 375);

	glBegin(GL_LINE_LOOP);			//1st floor window no1
	glVertex2i(765, 385);
	glVertex2i(765, 415);
	glVertex2i(795, 415);
	glVertex2i(795, 385);
	glEnd();

	glBegin(GL_LINE_LOOP);			//1st floor window no2
	glVertex2i(805, 385);
	glVertex2i(805, 415);
	glVertex2i(835, 415);
	glVertex2i(835, 385);
	glEnd();

	glBegin(GL_LINE_LOOP);			//1st floor window no3
	glVertex2i(845, 385);
	glVertex2i(845, 415);
	glVertex2i(875, 415);
	glVertex2i(875, 385);
	glEnd();

	glBegin(GL_LINE_LOOP);			//1st floor window no4
	glVertex2i(895, 385);
	glVertex2i(895, 415);
	glVertex2i(905, 425);
	glVertex2i(905, 395);
	glEnd();

	glBegin(GL_LINE_LOOP);			//2nd floor window no1
	glVertex2i(765, 425);
	glVertex2i(765, 455);
	glVertex2i(795, 455);
	glVertex2i(795, 425);
	glEnd();

	glBegin(GL_LINE_LOOP);			//2nd floor window no2
	glVertex2i(805, 425);
	glVertex2i(805, 455);
	glVertex2i(835, 455);
	glVertex2i(835, 425);
	glEnd();

	glBegin(GL_LINE_LOOP);			//2nd floor window no3
	glVertex2i(845, 425);
	glVertex2i(845, 455);
	glVertex2i(875, 455);
	glVertex2i(875, 425);
	glEnd();

	glBegin(GL_LINE_LOOP);			//2nd floor window no4
	glVertex2i(895, 425);
	glVertex2i(895, 455);
	glVertex2i(905, 465);
	glVertex2i(905, 435);
	glEnd();

	glBegin(GL_LINE_LOOP);			//3rd floor window no1
	glVertex2i(765, 465);
	glVertex2i(765, 495);
	glVertex2i(795, 495);
	glVertex2i(795, 465);
	glEnd();

	glBegin(GL_LINE_LOOP);			//3rd floor window no2
	glVertex2i(805, 465);
	glVertex2i(805, 495);
	glVertex2i(835, 495);
	glVertex2i(835, 465);
	glEnd();

	glBegin(GL_LINE_LOOP);			//3rd floor window no3
	glVertex2i(845, 465);
	glVertex2i(845, 495);
	glVertex2i(875, 495);
	glVertex2i(875, 465);
	glEnd();

	glBegin(GL_LINE_LOOP);			//3rd floor window no4
	glVertex2i(895, 465);
	glVertex2i(895, 495);
	glVertex2i(905, 505);
	glVertex2i(905, 475);
	glEnd();

	glBegin(GL_LINE_LOOP);			//4th floor window no1
	glVertex2i(765, 505);
	glVertex2i(765, 535);
	glVertex2i(795, 535);
	glVertex2i(795, 505);
	glEnd();

	glBegin(GL_LINE_LOOP);			//4th floor window no2
	glVertex2i(805, 505);
	glVertex2i(805, 535);
	glVertex2i(835, 535);
	glVertex2i(835, 505);
	glEnd();

	glBegin(GL_LINE_LOOP);			//4th floor window no3
	glVertex2i(845, 505);
	glVertex2i(845, 535);
	glVertex2i(875, 535);
	glVertex2i(875, 505);
	glEnd();

	glBegin(GL_LINE_LOOP);			//4th floor window no4
	glVertex2i(895, 505);
	glVertex2i(895, 535);
	glVertex2i(905, 545);
	glVertex2i(905, 515);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);       //door3
	glVertex2i(175, 50);
	glVertex2i(175, 75);
	glVertex2i(225, 75);
	glVertex2i(225, 50);
	glEnd();

	//glColor3f(0.0, 0.0, .0);
	glColor3f(0.647059, 0.164706, 0.164706);
	square(175, 50, 190, 60, 190, 65, 175, 75);
	square(225, 50, 210, 60, 210, 65, 225, 75);

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);			//1st floor window no1
	glVertex2i(145, 85);
	glVertex2i(145, 115);
	glVertex2i(175, 115);
	glVertex2i(175, 85);
	glEnd();

	glBegin(GL_LINE_LOOP);			//1st floor window no2
	glVertex2i(185, 85);
	glVertex2i(185, 115);
	glVertex2i(215, 115);
	glVertex2i(215, 85);
	glEnd();

	glBegin(GL_LINE_LOOP);			//1st floor window no3
	glVertex2i(225, 85);
	glVertex2i(225, 115);
	glVertex2i(255, 115);
	glVertex2i(255, 85);
	glEnd();

	glBegin(GL_LINE_LOOP);			//1st floor window no4
	glVertex2i(275, 85);
	glVertex2i(275, 115);
	glVertex2i(285, 125);
	glVertex2i(285, 95);
	glEnd();

	glBegin(GL_LINE_LOOP);			//2nd floor window no1
	glVertex2i(145, 125);
	glVertex2i(145, 155);
	glVertex2i(175, 155);
	glVertex2i(175, 125);
	glEnd();

	glBegin(GL_LINE_LOOP);			//2nd floor window no2
	glVertex2i(185, 125);
	glVertex2i(185, 155);
	glVertex2i(215, 155);
	glVertex2i(215, 125);
	glEnd();

	glBegin(GL_LINE_LOOP);			//2nd floor window no3
	glVertex2i(225, 125);
	glVertex2i(225, 155);
	glVertex2i(255, 155);
	glVertex2i(255, 125);
	glEnd();

	glBegin(GL_LINE_LOOP);			//2nd floor window no4
	glVertex2i(275, 125);
	glVertex2i(275, 155);
	glVertex2i(285, 165);
	glVertex2i(285, 135);
	glEnd();

	glBegin(GL_LINE_LOOP);			//3rd floor window no1
	glVertex2i(145, 165);
	glVertex2i(145, 195);
	glVertex2i(175, 195);
	glVertex2i(175, 165);
	glEnd();

	glBegin(GL_LINE_LOOP);			//3rd floor window no2
	glVertex2i(185, 165);
	glVertex2i(185, 195);
	glVertex2i(215, 195);
	glVertex2i(215, 165);
	glEnd();

	glBegin(GL_LINE_LOOP);			//3rd floor window no3
	glVertex2i(225, 165);
	glVertex2i(225, 195);
	glVertex2i(255, 195);
	glVertex2i(255, 165);
	glEnd();

	glBegin(GL_LINE_LOOP);			//3rd floor window no4
	glVertex2i(275, 165);
	glVertex2i(275, 195);
	glVertex2i(285, 205);
	glVertex2i(285, 175);
	glEnd();


	glBegin(GL_LINE_LOOP);			//4th floor window no1
	glVertex2i(145, 205);
	glVertex2i(145, 235);
	glVertex2i(175, 235);
	glVertex2i(175, 205);
	glEnd();

	glBegin(GL_LINE_LOOP);			//4th floor window no2
	glVertex2i(185, 205);
	glVertex2i(185, 235);
	glVertex2i(215, 235);
	glVertex2i(215, 205);
	glEnd();

	glBegin(GL_LINE_LOOP);			//4th floor window no3
	glVertex2i(225, 205);
	glVertex2i(225, 235);
	glVertex2i(255, 235);
	glVertex2i(255, 205);
	glEnd();

	glBegin(GL_LINE_LOOP);			//4th floor window no4
	glVertex2i(275, 205);
	glVertex2i(275, 235);
	glVertex2i(285, 245);
	glVertex2i(285, 215);
	glEnd();

	glColor3f(0.647059, 0.164706, 0.164706);
	glBegin(GL_POLYGON);			//door4
	glVertex2i(775, 50);
	glVertex2i(775, 75);
	glVertex2i(825, 75);
	glVertex2i(825, 50);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	square(775, 50, 790, 60, 790, 65, 775, 75);
	square(825, 50, 810, 60, 810, 65, 825, 75);


	glColor3f(0.647059, 0.164706, 0.164706);
	glBegin(GL_LINE_LOOP);			//1st floor window no1
	glVertex2i(745, 85);
	glVertex2i(745, 115);
	glVertex2i(775, 115);
	glVertex2i(775, 85);
	glEnd();

	glBegin(GL_LINE_LOOP);			//1st floor window no2
	glVertex2i(785, 85);
	glVertex2i(785, 115);
	glVertex2i(815, 115);
	glVertex2i(815, 85);
	glEnd();

	glBegin(GL_LINE_LOOP);			//1st floor window no3
	glVertex2i(825, 85);
	glVertex2i(825, 115);
	glVertex2i(855, 115);
	glVertex2i(855, 85);
	glEnd();

	glBegin(GL_LINE_LOOP);			//1st floor window no4
	glVertex2i(875, 85);
	glVertex2i(875, 115);
	glVertex2i(885, 125);
	glVertex2i(885, 95);
	glEnd();


	glBegin(GL_LINE_LOOP);			//2nd floor window no1
	glVertex2i(745, 125);
	glVertex2i(745, 155);
	glVertex2i(775, 155);
	glVertex2i(775, 125);
	glEnd();

	glBegin(GL_LINE_LOOP);			//2nd floor window no2
	glVertex2i(785, 125);
	glVertex2i(785, 155);
	glVertex2i(815, 155);
	glVertex2i(815, 125);
	glEnd();

	glBegin(GL_LINE_LOOP);			//2nd floor window no3
	glVertex2i(825, 125);
	glVertex2i(825, 155);
	glVertex2i(855, 155);
	glVertex2i(855, 125);
	glEnd();

	glBegin(GL_LINE_LOOP);			//2nd floor window no4
	glVertex2i(875, 125);
	glVertex2i(875, 155);
	glVertex2i(885, 165);
	glVertex2i(885, 135);
	glEnd();

	glBegin(GL_LINE_LOOP);			//3rd floor window no1
	glVertex2i(745, 165);
	glVertex2i(745, 195);
	glVertex2i(775, 195);
	glVertex2i(775, 165);
	glEnd();

	glBegin(GL_LINE_LOOP);			//3rd floor window no2
	glVertex2i(785, 165);
	glVertex2i(785, 195);
	glVertex2i(815, 195);
	glVertex2i(815, 165);
	glEnd();

	glBegin(GL_LINE_LOOP);			//3rd floor window no3
	glVertex2i(825, 165);
	glVertex2i(825, 195);
	glVertex2i(855, 195);
	glVertex2i(855, 165);
	glEnd();

	glBegin(GL_LINE_LOOP);			//3rd floor window no4
	glVertex2i(875, 165);
	glVertex2i(875, 195);
	glVertex2i(885, 205);
	glVertex2i(885, 175);
	glEnd();

	glBegin(GL_LINE_LOOP);			//4th floor window no1
	glVertex2i(745, 205);
	glVertex2i(745, 235);
	glVertex2i(775, 235);
	glVertex2i(775, 205);
	glEnd();

	glBegin(GL_LINE_LOOP);			//4th floor window no2
	glVertex2i(785, 205);
	glVertex2i(785, 235);
	glVertex2i(815, 235);
	glVertex2i(815, 205);
	glEnd();

	glBegin(GL_LINE_LOOP);			//4th floor window no3
	glVertex2i(825, 205);
	glVertex2i(825, 235);
	glVertex2i(855, 235);
	glVertex2i(855, 205);
	glEnd();

	glBegin(GL_LINE_LOOP);			//4th floor window no4
	glVertex2i(875, 205);
	glVertex2i(875, 235);
	glVertex2i(885, 245);
	glVertex2i(885, 215);
	glEnd();
}

							//**********wires**********//

void wires()
{
	glColor3f(0.0, 0.0, 0.0);			//pole_wires
	glLineWidth(4.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(390, 490);				//first_building
	glVertex2i(690, 490);
	glVertex2i(650, 190);				//second_building
	glVertex2i(350, 190);
	glVertex2i(390, 490);				//third_building
	glVertex2i(650, 190);
	glVertex2i(690, 490);				//fourth_building
	glVertex2i(350, 190);
	glEnd();

	glLineWidth(4.0);
	glBegin(GL_LINES);					//wire_to_building
	glVertex2i(295, 490);				//first_building
	glVertex2i(390, 490);
	glVertex2i(685, 490);				//second_building
	glVertex2i(765, 490);
	glVertex2i(275, 190);				//third_building
	glVertex2i(350, 190);
	glVertex2i(650, 190);				//fourth_building
	glVertex2i(745, 190);
	glEnd();
}

							//**********sky**********//

void sky()
{
	glColor3f(0.0, 0.95, 0.95);			//sky
	glBegin(GL_POLYGON);
	glVertex2i(0, 475);
	glVertex2i(0, 728);
	glVertex2i(1350, 728);
	glVertex2i(1350, 475);
	glVertex2i(0, 600);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);			//cloud_1
	glBegin(GL_POLYGON);
	glVertex2i(50, 600);
	glVertex2i(45, 605);
	glVertex2i(43, 607);
	glVertex2i(41, 609);
	glVertex2i(39, 611);
	glVertex2i(41, 613);
	glVertex2i(43, 615);
	glVertex2i(45, 617);
	glVertex2i(52, 619);
	glVertex2i(58, 621);
	glVertex2i(60, 623);
	glVertex2i(62, 630);
	glVertex2i(65, 635);
	glVertex2i(70, 640);
	glVertex2i(75, 632);
	glVertex2i(80, 640);
	glVertex2i(85, 635);
	glVertex2i(90, 644);
	glVertex2i(95, 645);
	glVertex2i(100, 645);
	glVertex2i(105, 642);
	glVertex2i(110, 638);
	glVertex2i(114, 636);
	glVertex2i(121, 638);
	glVertex2i(125, 635);
	glVertex2i(135, 629);
	glVertex2i(140, 620);
	glVertex2i(134, 605);
	glVertex2i(130, 590);
	glVertex2i(125, 588);
	glVertex2i(119, 580);
	glVertex2i(112, 585);
	glVertex2i(106, 572);
	glVertex2i(65, 575);
	glEnd();

	glBegin(GL_POLYGON);			//cloud_2
	glVertex2i(500, 550);
	glVertex2i(490, 555);
	glVertex2i(485, 560);
	glVertex2i(482, 564);
	glVertex2i(485, 570);
	glVertex2i(490, 575);
	glVertex2i(490, 578);
	glVertex2i(495, 584);
	glVertex2i(502, 587);
	glVertex2i(514, 580);
	glVertex2i(526, 586);
	glVertex2i(530, 588);
	glVertex2i(538, 582);
	glVertex2i(545, 575);
	glVertex2i(550, 566);
	glVertex2i(545, 560);
	glVertex2i(545, 565);
	glVertex2i(540, 555);
	glVertex2i(534, 562);
	glVertex2i(522, 570);
	glEnd();

	glBegin(GL_POLYGON);			//cloud_3
	glVertex2i(790, 600);
	glVertex2i(785, 605);
	glVertex2i(780, 610);
	glVertex2i(780, 615);
	glVertex2i(780, 620);
	glVertex2i(780, 625);
	glVertex2i(783, 620);
	glVertex2i(785, 625);
	glVertex2i(790, 630);
	glVertex2i(790, 640);
	glVertex2i(790, 635);
	glVertex2i(795, 645);
	glVertex2i(800, 647);
	glVertex2i(810, 649);
	glVertex2i(830, 643);
	glVertex2i(835, 635);
	glVertex2i(850, 625);
	glVertex2i(855, 618);
	glVertex2i(855, 612);
	glVertex2i(842, 605);
	glVertex2i(840, 600);
	glVertex2i(836, 595);
	glVertex2i(820, 587);
	glEnd();
}

							//**********objects_inside_buildings**********//

void objects()
{
	//******************1st building*****************//
	glColor3f(0.0, 0.0, 0.0);				//1st floor 1st window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(165, 385);
	glVertex2i(170, 390);
	glVertex2i(170, 390);
	glVertex2i(195, 390);
	glEnd();
	keybox(170, 390, 170, 415);
	keybox(185, 390, 185, 415);

	glColor3f(0.0, 0.0, 0.0);				//1st floor 2nd window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(205, 385);
	glVertex2i(210, 400);
	glVertex2i(210, 400);
	glVertex2i(235, 400);
	glEnd();

	glLineWidth(1.0);
	glColor3f(0.752941, 0.752941, 0.752941);
	square(212, 388, 212, 392, 222, 392, 222, 388);
	keybox(217, 392, 217, 398);
	square(212, 398, 212, 410, 222, 410, 222, 398);
	glColor3f(1.0, 1.0, 1.0);
	square(224, 388, 224, 404, 230, 404, 230, 388);

	glColor3f(0.0, 0.0, 0.0);				//1st floor 3rd window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(245, 385);
	glVertex2i(250, 390);
	glVertex2i(250, 390);
	glVertex2i(275, 390);
	glEnd();
	keybox(250, 390, 250, 415);
	keybox(265, 390, 265, 415);

	glColor3f(0.0, 0.0, 0.0);				//2nd floor 1st window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(165, 425);
	glVertex2i(170, 440);
	glVertex2i(170, 440);
	glVertex2i(195, 440);
	glEnd();

	glLineWidth(1.0);
	glColor3f(0.752941, 0.752941, 0.752941);
	square(172, 428, 172, 432, 182, 432, 182, 428);
	keybox(177, 432, 177, 438);
	square(172, 438, 172, 450, 182, 450, 182, 438);
	glColor3f(1.0, 1.0, 1.0);
	square(184, 428, 184, 444, 190, 444, 190, 428);

	glColor3f(0.0, 0.0, 0.0);				//2nd floor 2nd window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(205, 425);
	glVertex2i(210, 440);
	glVertex2i(210, 440);
	glVertex2i(235, 440);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
	square(215, 428, 215, 438, 222, 438, 222, 428);
	glColor3f(1.0, 1.0, 1.0);
	square(217, 430, 217, 440, 224, 440, 222, 430);
	glColor3f(0.752941, 0.752941, 0.752941);
	square(219, 432, 219, 442, 226, 442, 226, 432);

	glColor3f(0.0, 0.0, 0.0);				//2nd floor 3rd window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(245, 425);
	glVertex2i(250, 430);
	glVertex2i(250, 430);
	glVertex2i(275, 430);
	glEnd();
	keybox(250, 430, 250, 455);
	keybox(265, 430, 265, 455);

	glColor3f(0.0, 0.0, 0.0);				//3rd floor 1st window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(165, 465);
	glVertex2i(170, 470);
	glVertex2i(170, 470);
	glVertex2i(195, 470);
	glEnd();
	keybox(170, 470, 170, 495);
	keybox(185, 470, 185, 495);


	glColor3f(0.0, 0.0, 0.0);				//3rd floor 2nd window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(205, 465);
	glVertex2i(210, 480);
	glVertex2i(210, 480);
	glVertex2i(235, 480);
	glEnd();

	glLineWidth(1.0);
	glColor3f(0.752941, 0.752941, 0.752941);
	square(212, 468, 212, 472, 222, 472, 222, 468);
	keybox(217, 472, 217, 478);
	square(212, 478, 212, 490, 222, 490, 222, 478);
	glColor3f(1.0, 1.0, 1.0);
	square(224, 468, 224, 484, 230, 484, 230, 468);

	glColor3f(0.0, 0.0, 0.0);				//3rd floor 3rd window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(245, 465);
	glVertex2i(250, 480);
	glVertex2i(250, 480);
	glVertex2i(275, 480);
	glEnd();

	glLineWidth(1.0);
	glColor3f(0.752941, 0.752941, 0.752941);
	square(252, 468, 252, 472, 262, 472, 262, 468);
	keybox(257, 472, 257, 478);
	square(252, 478, 252, 490, 262, 490, 262, 478);
	glColor3f(1.0, 1.0, 1.0);
	square(264, 468, 264, 484, 270, 484, 270, 468);

	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(270, 484);
	glVertex2i(275, 490);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);				//4th floor 1st window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(165, 505);
	glVertex2i(170, 520);
	glVertex2i(170, 520);
	glVertex2i(195, 520);
	glEnd();

	glLineWidth(1.0);
	glColor3f(0.752941, 0.752941, 0.752941);
	square(172, 508, 172, 512, 182, 512, 182, 508);
	keybox(177, 512, 177, 518);
	square(172, 518, 172, 530, 182, 530, 182, 518);
	glColor3f(1.0, 1.0, 1.0);
	square(184, 508, 184, 524, 190, 524, 190, 508);

	glColor3f(0.0, 0.0, 0.0);				//4th floor 2nd window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(205, 505);
	glVertex2i(210, 520);
	glVertex2i(210, 520);
	glVertex2i(235, 520);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
	square(215, 508, 215, 518, 222, 518, 222, 508);
	glColor3f(1.0, 1.0, 1.0);
	square(217, 510, 217, 520, 224, 520, 222, 510);
	glColor3f(0.752941, 0.752941, 0.752941);
	square(219, 512, 219, 522, 226, 522, 226, 512);

	glColor3f(0.0, 0.0, 0.0);				//4th floor 3rd window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(245, 505);
	glVertex2i(250, 520);
	glVertex2i(250, 520);
	glVertex2i(275, 520);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
	square(255, 508, 255, 518, 262, 518, 262, 508);
	glColor3f(1.0, 1.0, 1.0);
	square(257, 510, 257, 520, 264, 520, 264, 510);
	glColor3f(0.752941, 0.752941, 0.752941);
	square(259, 512, 259, 522, 266, 522, 266, 512);

	//***********************2nd building************************

	glColor3f(0.0, 0.0, 0.0);				//1st floor 1st window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(765, 385);
	glVertex2i(770, 390);
	glVertex2i(770, 390);
	glVertex2i(795, 390);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(770, 390);
	glVertex2i(770, 415);
	glVertex2i(785, 390);
	glVertex2i(785, 415);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);				//1st floor 2nd window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(805, 385);
	glVertex2i(810, 400);
	glVertex2i(810, 400);
	glVertex2i(835, 400);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
	square(815, 388, 815, 398, 822, 398, 822, 388);
	glColor3f(1.0, 1.0, 1.0);
	square(824, 388, 824, 398, 831, 398, 831, 388);
	glColor3f(0.0, 0.0, 1.0);
	square(810, 405, 810, 410, 820, 410, 820, 405);

	glColor3f(0.0, 0.0, 0.0);				//1st floor 3rd window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(845, 385);
	glVertex2i(850, 395);
	glVertex2i(850, 395);
	glVertex2i(875, 395);
	glEnd();
    square(855, 390, 855, 410, 865, 410, 865, 390);

	glColor3f(0.0, 0.0, 0.0);				//2nd floor 1st window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(765, 425);
	glVertex2i(770, 440);
	glVertex2i(770, 440);
	glVertex2i(795, 440);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
	square(775, 428, 775, 438, 782, 438, 782, 428);
	glColor3f(1.0, 1.0, 1.0);
	square(777, 430, 777, 440, 784, 440, 784, 430);
	glColor3f(0.0, 0.0, 1.0);
	square(779, 432, 779, 442, 786, 442, 786, 432);

	glColor3f(0.0, 0.0, 0.0);				//2nd floor 2nd window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(805, 425);
	glVertex2i(810, 440);
	glVertex2i(810, 440);
	glVertex2i(835, 440);
	glEnd();

	glLineWidth(1.0);
	glColor3f(0.0, 0.0, 0.0);
	square(812, 428, 812, 444, 818, 444, 818, 428);
	glColor3f(0.0, 0.0, 0.0);
	square(820, 428, 820, 432, 830, 432, 830, 428);
	keybox(825, 432, 825, 440);
	square(820, 438, 820, 450, 830, 450, 830, 438);

	glColor3f(0.0, 0.0, 0.0);				//2nd floor 3rd window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(845, 425);
	glVertex2i(850, 430);
	glVertex2i(850, 430);
	glVertex2i(875, 430);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(850, 430);
	glVertex2i(850, 455);
	glVertex2i(865, 430);
	glVertex2i(865, 455);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);				//3rd floor 1st window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(765, 465);
	glVertex2i(770, 480);
	glVertex2i(770, 480);
	glVertex2i(795, 480);
	glEnd();

	glLineWidth(1.0);
	glColor3f(1.0, 1.0, 1.0);
	square(772, 468, 772, 484, 778, 484, 778, 468);
	glColor3f(0.0, 0.0, 0.0);
	square(780, 468, 780, 472, 790, 472, 790, 468);
	keybox(785, 472, 785, 478);
	square(780, 478, 780, 490, 790, 490, 790, 478);

	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(772, 484);
	glVertex2i(765, 490);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);				//3rd floor 2nd window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(805, 465);
	glVertex2i(810, 480);
	glVertex2i(810, 480);
	glVertex2i(835, 480);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
	square(815, 468, 815, 478, 822, 478, 822, 468);
	glColor3f(1.0, 1.0, 1.0);
	square(817, 470, 817, 480, 824, 480, 824, 470);
	glColor3f(0.0,0.0,1.0);
	square(819, 472, 819, 482, 826, 482, 826, 472);

	glColor3f(0.0, 0.0, 0.0);				//3rd floor 3rd window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(845, 465);
	glVertex2i(850, 470);
	glVertex2i(850, 470);
	glVertex2i(875, 470);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(850, 470);
	glVertex2i(850, 495);
	glVertex2i(865, 470);
	glVertex2i(865, 495);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);				//4th floor 1st window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(765, 505);
	glVertex2i(770, 515);
	glVertex2i(770, 515);
	glVertex2i(795, 515);
	glEnd();
	square(775, 510, 775, 530, 785, 530, 785, 510);

	glColor3f(0.0, 0.0, 0.0);				//4th floor 2nd window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(805, 505);
	glVertex2i(810, 520);
	glVertex2i(810, 520);
	glVertex2i(835, 520);
	glEnd();

	glLineWidth(1.0);
	glColor3f(1.0, 1.0, 1.0);
	square(812, 508, 812, 524, 818, 524, 818, 508);
	glColor3f(0.0, 0.0, 0.0);
	square(820, 508, 820, 512, 830, 512, 830, 508);
	keybox(825, 512, 825, 518);
	square(820, 518, 820, 530, 830, 530, 830, 518);

	glColor3f(0.0, 0.0, 0.0);				//4th floor 3rd window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(845, 505);
	glVertex2i(850, 520);
	glVertex2i(850, 520);
	glVertex2i(875, 520);
	glEnd();

	glLineWidth(1.0);
	glColor3f(0.0, 0.0, 0.0);
	square(852, 508, 852, 524, 858, 524, 858, 508);
	glColor3f(0.0, 0.0, 0.0);
	square(860, 508, 860, 512, 870, 512, 870, 508);
	keybox(865, 512, 865, 518);
	square(860, 518, 860, 530, 870, 530, 870, 518);

	//*******************3rd building*******************

	glColor3f(0.0, 0.0, 0.0);				//1st floor 1st window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(145, 85);
	glVertex2i(150, 90);
	glVertex2i(150, 90);
	glVertex2i(175, 90);
	glEnd();
	keybox(150, 90, 150, 115);
	keybox(165, 90, 165, 115);

	glColor3f(0.0, 0.0, 0.0);				//1st floor 2nd window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(185, 85);
	glVertex2i(190, 100);
	glVertex2i(190, 100);
	glVertex2i(215, 100);
	glEnd();

	glLineWidth(1.0);
	glColor3f(0.752941, 0.752941, 0.752941);
	square(192, 88, 192, 98, 199, 98, 199, 88);
	glColor3f(0.0, 0.0, 1.0);
	square(194, 90, 194, 100, 201, 100, 201, 90);
	glColor3f(1.0, 1.0, 1.0);
	square(196, 92, 196, 102, 203, 102, 203, 92);
	glColor3f(1.0, 1.0, 0.0);
	square(201, 100, 201, 90, 207, 90, 207, 100);
	glColor3f(0.0, 1.0, 1.0);
	square(205, 95, 205, 105, 212, 105, 212, 95);


	glColor3f(0.0, 0.0, 0.0);				//1st floor 3rd window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(225, 85);
	glVertex2i(230, 100);
	glVertex2i(230, 100);
	glVertex2i(255, 100);
	glEnd();

	glLineWidth(1.0);
	glColor3f(0.752941, 0.752941, 0.752941);
	square(232, 88, 232, 92, 242, 92, 242, 88);
	keybox(237, 92, 237, 98);
	square(232, 98, 232, 110, 242, 110, 242, 98);
	glColor3f(0.752941, 0.752941, 0.752941);
	square(244, 88, 244, 104, 250, 104, 250, 88);

	glColor3f(0.0, 0.0, 0.0);				//2nd floor 1st window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(145, 125);
	glVertex2i(150, 140);
	glVertex2i(150, 140);
	glVertex2i(175, 140);
	glEnd();

	glLineWidth(1.0);
	glColor3f(0.752941, 0.752941, 0.752941);
	square(152, 128, 152, 132, 162, 132, 162, 128);
	keybox(157, 132, 157, 138);
	square(152, 138, 152, 150, 162, 150, 162, 138);
	glColor3f(0.752941, 0.752941, 0.752941);
	square(164, 128, 164, 144, 170, 144, 170, 128);

	glColor3f(0.0, 0.0, 0.0);				//2nd floor 2nd window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(185, 125);
	glVertex2i(190, 130);
	glVertex2i(190, 130);
	glVertex2i(215, 130);
	glEnd();
	keybox(190, 130, 190, 155);
	keybox(205, 130, 205, 155);

	glColor3f(0.0, 0.0, 0.0);				//2nd floor 3rd window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(225, 125);
	glVertex2i(230, 135);
	glVertex2i(230, 135);
	glVertex2i(255, 135);
	glEnd();

	square(235, 130, 235, 150, 245, 150, 245, 130);

	glColor3f(0.0, 0.0, 0.0);				//3rd floor 1st window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(145, 165);
	glVertex2i(150, 170);
	glVertex2i(150, 170);
	glVertex2i(175, 170);
	glEnd();
	keybox(150, 170, 150, 195);
	keybox(165, 170, 165, 195);

	glColor3f(0.0, 0.0, 0.0);				//3rd floor 2nd window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(185, 165);
	glVertex2i(190, 175);
	glVertex2i(190, 175);
	glVertex2i(215, 175);
	glEnd();
	square(195, 170, 195, 190, 205, 190, 205, 170);

	glColor3f(0.0, 0.0, 0.0);				//3rd floor 3rd window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(225, 165);
	glVertex2i(230, 180);
	glVertex2i(230, 180);
	glVertex2i(255, 180);
	glEnd();

	glLineWidth(1.0);
	glColor3f(0.752941, 0.752941, 0.752941);
	square(232, 168, 232, 172, 242, 172, 242, 168);
	keybox(237, 172, 237, 178);
	square(232, 178, 232, 190, 242, 190, 242, 178);
	glColor3f(0.752941, 0.752941, 0.752941);
	square(244, 168, 244, 184, 250, 184, 250, 168);

	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(250, 184);
	glVertex2i(255, 190);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);				//4th floor 1st window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(145, 205);
	glVertex2i(150, 220);
	glVertex2i(150, 220);
	glVertex2i(175, 220);
	glEnd();

	glLineWidth(1.0);
	glColor3f(0.752941, 0.752941, 0.752941);
	square(152, 208, 152, 212, 162, 212, 162, 208);
	keybox(157, 212, 157, 218);
	square(152, 218, 152, 230, 162, 230, 162, 218);
	glColor3f(0.752941, 0.752941, 0.752941);
	square(164, 208, 164, 224, 170, 224, 170, 208);

	glColor3f(0.0, 0.0, 0.0);				//4th floor 2nd window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(185, 205);
	glVertex2i(190, 220);
	glVertex2i(190, 220);
	glVertex2i(215, 220);
	glEnd();

	glLineWidth(1.0);
	glColor3f(0.752941, 0.752941, 0.752941);
	square(192, 208, 192, 212, 202, 212, 202, 208);
	keybox(197, 212, 197, 218);
	square(192, 218, 192, 230, 202, 230, 202, 218);
	glColor3f(0.752941, 0.752941, 0.752941);
	square(204, 208, 204, 224, 210, 224, 210, 208);

	glColor3f(0.0, 0.0, 0.0);				//4th floor 3rd window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(225, 205);
	glVertex2i(230, 220);
	glVertex2i(230, 220);
	glVertex2i(255, 220);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
	square(235, 208, 235, 218, 242, 218, 242, 208);
	glColor3f(1.0, 1.0, 1.0);
	square(237, 210, 237, 220, 244, 220, 244, 210);
	glColor3f(0.752941, 0.752941, 0.752941);
	square(239, 212, 239, 222, 246, 222, 246, 212);

	//*******************4th building******************

	glColor3f(0.0, 0.0, 0.0);				//2nd floor 1st window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(745, 125);
	glVertex2i(750, 130);
	glVertex2i(750, 130);
	glVertex2i(775, 130);
	glEnd();
	keybox(750, 130, 750, 155);
	keybox(765, 130, 765, 155);

	glColor3f(0.0, 0.0, 0.0);				//2nd floor 2nd window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(785, 125);
	glVertex2i(790, 135);
	glVertex2i(790, 135);
	glVertex2i(815, 135);
	glEnd();
	square(795, 130, 795, 150, 805, 150, 805, 130);

	glColor3f(0.0, 0.0, 0.0);				//2nd floor 3rd window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(825, 125);
	glVertex2i(830, 140);
	glVertex2i(830, 140);
	glVertex2i(855, 140);
	glEnd();

	glLineWidth(1.0);
	glColor3f(0.0, 0.0, 0.0);
	square(832, 128, 832, 144, 838, 144, 838, 128);
	glColor3f(0.0, 0.0, 0.0);
	square(840, 128, 840, 132, 850, 132, 850, 128);
	keybox(845, 132, 845, 140);
	square(840, 138, 840, 150, 850, 150, 850, 138);

	glColor3f(0.0, 0.0, 0.0);				//1st floor 1st window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(745, 85);
	glVertex2i(750, 90);
	glVertex2i(750, 90);
	glVertex2i(775, 90);
	glEnd();
	keybox(750, 90, 750, 115);
	keybox(765, 90, 765, 115);

	glColor3f(0.0, 0.0, 0.0);				//1st floor 2nd window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(785, 85);
	glVertex2i(790, 100);
	glVertex2i(790, 100);
	glVertex2i(815, 100);
	glEnd();

	glLineWidth(1.0);
	glColor3f(0.0, 0.0, 0.0);
	square(792, 88, 792, 104, 798, 104, 798, 88);
	glColor3f(0.0,0.0,0.0);
	square(800, 88, 800, 92, 810, 92, 810, 88);
	keybox(805, 92, 805, 98);
	square(800, 98, 800, 110, 810, 110, 810, 98);


	glColor3f(0.0, 0.0, 0.0);				//1st floor 3rd window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(825, 85);
	glVertex2i(830, 100);
	glVertex2i(830, 100);
	glVertex2i(855, 100);
	glEnd();

	glLineWidth(1.0);
	glColor3f(0.0, 0.0, 0.0);
	square(832, 88, 832, 98, 838, 98, 838, 88);
	glColor3f(1.0, 0.0, 0.0);
	square(834, 90, 834, 100, 840, 100, 840, 90);
	glColor3f(0.0, 0.0, 1.0);
	square(836, 92, 836, 102, 842, 102, 842, 92);
	glColor3f(1.0, 0.5, 0.0);
	square(840, 90, 840, 100, 846, 100, 846, 90);

	glColor3f(0.0, 0.0, 0.0);				//3rd floor 1st window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(745, 165);
	glVertex2i(750, 180);
	glVertex2i(750, 180);
	glVertex2i(775, 180);
	glEnd();

	glLineWidth(1.0);
	glColor3f(0.0, 0.0, 0.0);
	square(752, 168, 752, 184, 758, 184, 758, 168);
	glColor3f(0.0, 0.0, 0.0);
	square(760, 168, 760, 172, 770, 172, 770, 168);
	keybox(765, 172, 765, 178);
	square(760, 178, 760, 190, 770, 190, 770, 178);

	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(752, 184);
	glVertex2i(745, 190);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);				//3rd floor 2nd window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(785, 165);
	glVertex2i(790, 180);
	glVertex2i(790, 180);
	glVertex2i(815, 180);
	glEnd();

	glLineWidth(1.0);
	glColor3f(0.0, 0.0, 0.0);
	square(792, 168, 792, 184, 798, 184, 798, 168);
	glColor3f(0.0, 0.0, 0.0);
	square(800, 168, 800, 172, 810, 172, 810, 168);
	keybox(805, 172, 805, 178);
	square(800, 178, 800, 190, 810, 190, 810, 178);

	glColor3f(0.0, 0.0, 0.0);				//3rd floor 3rd window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(825, 165);
	glVertex2i(830, 170);
	glVertex2i(830, 170);
	glVertex2i(855, 170);
	glEnd();

	glLineWidth(2.0);
	glColor3f(0.0, 0.0, 0.0);
	keybox(830,170,830,195);
	keybox(845, 170, 845, 195);

	glColor3f(0.0, 0.0, 0.0);				//4th floor 1st window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(745, 205);
	glVertex2i(750, 220);
	glVertex2i(750, 220);
	glVertex2i(775, 220);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	square(755, 208, 755, 218, 762, 218, 762, 208);
	glColor3f(0.0, 1.0, 0.0);
	square(757, 210, 757, 220, 764, 220, 764, 210);
	glColor3f(0.647059, 0.164706, 0.164706);
	square(759, 212, 759, 222, 766, 222, 766, 212);


	glColor3f(0.0, 0.0, 0.0);				//4th floor 2nd window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(785, 205);
	glVertex2i(790, 210);
	glVertex2i(790, 210);
	glVertex2i(815, 210);
	glEnd();

	glLineWidth(2.0);
	glColor3f(0.0, 0.0, 0.0);
	keybox(790, 210, 790, 235);
	keybox(805, 210, 805, 235);

	glColor3f(0.0, 0.0, 0.0);				//4th floor 3rd window
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(825, 205);
	glVertex2i(830, 220);
	glVertex2i(830, 220);
	glVertex2i(855, 220);
	glEnd();

	glLineWidth(1.0);
	glColor3f(0.0, 0.0, 0.0);
	square(832, 208, 832, 224, 838, 224, 838, 208);
	glColor3f(0.0, 0.0, 0.0);
	square(840, 208, 840, 212, 850, 212, 850, 208);
	keybox(845, 212, 845, 218);
	square(840, 218, 840, 230, 850, 230, 850, 218);
}

							//**********bush_on_land**********//

void bush()
{
	glColor3f(0.137255, 0.556863, 0.137255);
	glBegin(GL_POLYGON);
	glVertex2i(40, 70);
	glVertex2i(20, 95);
	glVertex2i(55, 80);
	glVertex2i(65, 110);
	glVertex2i(85, 80);
	glVertex2i(110, 95);
	glVertex2i(90, 70);
	glEnd();

	glColor3f(0.137255, 0.556863, 0.137255);
	glBegin(GL_POLYGON);
	glVertex2i(930, 70);
	glVertex2i(915, 95);
	glVertex2i(940, 85);
	glVertex2i(955, 110);
	glVertex2i(975, 80);
	glVertex2i(995, 95);
	glVertex2i(975, 70);
	glEnd();

	glColor3f(0.137255, 0.556863, 0.137255);
	glBegin(GL_POLYGON);
	glVertex2i(50, 370);
	glVertex2i(30, 395);
	glVertex2i(65, 380);
	glVertex2i(75, 410);
	glVertex2i(95, 380);
	glVertex2i(120, 395);
	glVertex2i(100, 370);
	glEnd();

	glColor3f(0.137255, 0.556863, 0.137255);
	glBegin(GL_POLYGON);
	glVertex2i(930, 370);
	glVertex2i(915, 395);
	glVertex2i(940, 385);
	glVertex2i(955, 410);
	glVertex2i(975, 380);
	glVertex2i(995, 395);
	glVertex2i(975, 370);
	glEnd();
}

void light_pole()
{
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(4.0);
	keybox(490, 400, 490, 440);
	keybox(490, 440, 510, 440);
	glColor3f(1.0, 1.0, 0.0);

	glLineWidth(1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(510, 440);
	glVertex2f(505, 435);
	glVertex2f(500, 440);
	glEnd();

	glLineWidth(4.0);
	glColor3f(0.0, 0.0, 0.0);
	keybox(575, 400, 575, 440);
	keybox(575, 440, 555, 440);

	glColor3f(1.0, 1.0, 0.0);
	glLineWidth(1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(555, 440);
	glVertex2f(560, 435);
	glVertex2f(565, 440);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(4.0);
	keybox(470, 230, 470, 270);
	keybox(470, 270, 490, 270);

	glColor3f(1.0, 1.0, 0.0);
	glLineWidth(1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(490, 270);
	glVertex2f(485, 265);
	glVertex2f(480, 270);
	glEnd();

	glLineWidth(4.0);
	glColor3f(0.0, 0.0, 0.0);
	keybox(552, 230, 552, 270);
	keybox(552, 270, 532, 270);

	glColor3f(1.0, 1.0, 0.0);
	glLineWidth(1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(532, 270);
	glVertex2f(537, 265);
	glVertex2f(542, 270);
	glEnd();
	glLineWidth(4.0);
	glColor3f(0.0, 0.0, 0.0);
	keybox(455, 110, 455, 150);
	keybox(455, 150, 475, 150);

	glColor3f(1.0, 1.0, 0.0);
	glLineWidth(1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(475, 150);
	glVertex2f(470, 145);
	glVertex2f(465, 150);
	glEnd();

	glLineWidth(4.0);
	glColor3f(0.0, 0.0, 0.0);
	keybox(538, 110, 538, 150);
	keybox(538, 150, 518, 150);

	glColor3f(1.0, 1.0, 0.0);
	glLineWidth(1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(518, 150);
	glVertex2f(523, 145);
	glVertex2f(528, 150);
	glEnd();

	glLineWidth(4.0);
	glColor3f(0.0, 0.0, 0.0);
	keybox(138, 350, 138, 390);
	keybox(138, 390, 128, 370);

	glColor3f(1.0, 1.0, 0.0);
	glLineWidth(1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(128, 370);
	glVertex2f(133, 375);
	glVertex2f(133, 370);
	glEnd();

	glLineWidth(4.0);
	glColor3f(0.0, 0.0, 0.0);
	keybox(358, 350, 358, 390);
	keybox(358, 390, 348, 370);

	glColor3f(1.0, 1.0, 0.0);
	glLineWidth(1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(348, 370);
	glVertex2f(353, 375);
	glVertex2f(353, 370);
	glEnd();

	glLineWidth(4.0);
	glColor3f(0.0, 0.0, 0.0);
	keybox(948, 350, 948, 390);
	keybox(948, 390, 938, 370);

	glColor3f(1.0, 1.0, 0.0);
	glLineWidth(1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(938, 370);
	glVertex2f(943, 375);
	glVertex2f(943, 370);
	glEnd();

	glLineWidth(4.0);
	glColor3f(0.0, 0.0, 0.0);
	keybox(738, 350, 738, 390);
	keybox(738, 390, 728, 370);

	glColor3f(1.0, 1.0, 0.0);
	glLineWidth(1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(728, 370);
	glVertex2f(733, 375);
	glVertex2f(733, 370);
	glEnd();

	glLineWidth(4.0);
	glColor3f(0.0, 0.0, 0.0);
	keybox(68, 350, 68, 390);
	keybox(68, 390, 58, 370);

	glColor3f(1.0, 1.0, 0.0);
	glLineWidth(1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(58, 370);
	glVertex2f(63, 375);
	glVertex2f(63, 370);
	glEnd();

	glLineWidth(4.0);
	glColor3f(0.0, 0.0, 0.0);
	keybox(638, 350, 638, 390);
	keybox(638, 390, 628, 370);

	glColor3f(1.0, 1.0, 0.0);
	glLineWidth(1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(628, 370);
	glVertex2f(633, 375);
	glVertex2f(633, 370);
	glEnd();

	glLineWidth(4.0);
	glColor3f(0.0, 0.0, 0.0);
	keybox(438, 350, 438, 390);
	keybox(438, 390, 428, 370);

	glColor3f(1.0, 1.0, 0.0);
	glLineWidth(1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(428, 370);
	glVertex2f(433, 375);
	glVertex2f(433, 370);
	glEnd();

	glLineWidth(4.0);
	glColor3f(0.0, 0.0, 0.0);
	keybox(98, 270, 98, 310);
	keybox(98, 310, 108, 325);

	glColor3f(1.0, 1.0, 0.0);
	glLineWidth(1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(108, 325);
	glVertex2f(108, 315);
	glVertex2f(104, 315);
	glEnd();

	glLineWidth(4.0);
	glColor3f(0.0, 0.0, 0.0);
	keybox(398, 270, 398, 310);
	keybox(398, 310, 408, 325);

	glColor3f(1.0, 1.0, 0.0);
	glLineWidth(1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(408, 325);
	glVertex2f(408, 315);
	glVertex2f(404, 315);
	glEnd();

	glLineWidth(4.0);
	glColor3f(0.0, 0.0, 0.0);
	keybox(598, 270, 598, 310);
	keybox(598, 310, 608, 325);

	glColor3f(1.0, 1.0, 0.0);
	glLineWidth(1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(608, 325);
	glVertex2f(608, 315);
	glVertex2f(604, 315);
	glEnd();

	glLineWidth(4.0);
	glColor3f(0.0, 0.0, 0.0);
	keybox(898, 270, 898, 310);
	keybox(898, 310, 908, 325);

	glColor3f(1.0, 1.0, 0.0);
	glLineWidth(1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(908, 325);
	glVertex2f(908, 315);
	glVertex2f(904, 315);
	glEnd();

	glLineWidth(4.0);
	glColor3f(0.0, 0.0, 0.0);
	keybox(28, 270, 28, 310);
	keybox(28, 310, 38, 325);

	glColor3f(1.0, 1.0, 0.0);
	glLineWidth(1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(38, 325);
	glVertex2f(38, 315);
	glVertex2f(32, 315);
	glEnd();

	glLineWidth(4.0);
	glColor3f(0.0, 0.0, 0.0);
	keybox(308, 270, 308, 310);
	keybox(308, 310, 318, 325);

	glColor3f(1.0, 1.0, 0.0);
	glLineWidth(1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(318, 325);
	glVertex2f(318, 315);
	glVertex2f(312, 315);
	glEnd();

	glLineWidth(4.0);
	glColor3f(0.0, 0.0, 0.0);
	keybox(698, 270, 698, 310);
	keybox(698, 310, 708, 325);

	glColor3f(1.0, 1.0, 0.0);
	glLineWidth(1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(708, 325);
	glVertex2f(708, 315);
	glVertex2f(702, 315);
	glEnd();
}

							//**********hand_movement**********//

void hand_move()
{
	glColor3f(0.0, 0.0, 0.0);			//hand

	for (GLint f = 0; f < 500; f++)
	{
		for (GLint hm = 0; hm < 10; hm += 10)
		{
				glPushMatrix();
				glTranslatef(z3, z1, 0.0);
				//keybox(605 + hm, 225 + hm, 595 + hm, 200 + hm);
				keybox(595 + hm, 200 + hm, 560 + hm, 260 + hm);
				//keybox(575+hm, 220+hm, 565+hm, 200+hm);
				keybox(590+hm, 190+hm, 515+hm, 220+hm);
				glPopMatrix();
				glEnd();
		}
	}
	if (cntr35 >= 0 && cntr35 <= 18)
	{
		z1 += 0.5;
		z3 -= 0.5;
		cntr35++;
	}

	if (cntr35 == 18)
	{
		z1 = 3;
		z3 = 3;
	}
		//glEnd();
		//drawpacket20 = !drawpacket20;
	//glEnd();
	glutPostRedisplay();
}

void hand_move2()
{
	glColor3f(0.0, 0.0, 0.0);			//hand

	for (GLint f1 = 0; f1 < 50000; f1++)
	{
		for (GLint hm1 = 0; hm1 < 10; hm1 += 10)
		{
			glPushMatrix();
			glTranslatef(z4, z2, 0.0);
			/*//keybox(605 + hm, 225 + hm, 595 + hm, 200 + hm);
			keybox(595 + hm, 200 + hm, 560 + hm, 260 + hm);
			//keybox(575+hm, 220+hm, 565+hm, 200+hm);
			keybox(590 + hm, 190 + hm, 515 + hm, 220 + hm);*/
			//keybox(350+hm1, 380+hm1, 375+hm1, 360+hm1);
			glColor3f(0.0, 0.0, 0.0);
			keybox(355+hm1, 325+hm1, 420+hm1, 300+hm1);
			//keybox(370+hm1, 408+hm1, 395+hm1, 385+hm1);
			keybox(388+hm1, 385+hm1, 440+hm1, 350+hm1);
			glPopMatrix();
			glEnd();
		}
	}
	if (cntr36 >= 0 && cntr36 <= 15)
	{
		z2 -= 0.5;
		z4 += 0.5;
		cntr36++;
	}

	if (cntr36 == 15)
	{
		z2 = 0;
		z4 = 0;
	}
	//glEnd();
	//drawpacket20 = !drawpacket20;
	//glEnd();
	glutPostRedisplay();
}

							//**********chopstick_movement**********//

void chopstick1_move()
{
	//glColor3f(1.0, 1.0, 0.0);			//hand
	//glColor3f(1.0, 0.980392156, 0.803921568);
	glColor3f(0.803921568, 0.745098039, 0.439215686);
	for (GLint f12 = 0; f12 < 50000; f12++)
	{
		for (GLint cm = 0; cm < 10; cm += 10)
		{
			glPushMatrix();
			glTranslatef(z6, z5, z7);
			//keybox(605 + hm, 225 + hm, 595 + hm, 200 + hm);
			//keybox(595 + hm, 200 + hm, 560 + hm, 260 + hm);
			//keybox(575+hm, 220+hm, 565+hm, 200+hm);
			//keybox(590 + hm, 190 + hm, 515 + hm, 220 + hm);
			chopsticks(525 + cm, 210 + cm, 490 + cm, 255 + cm);
			chopsticks(525 + cm, 290 + cm, 560 + cm, 265 + cm);
			//chopsticks(515, 345+cm, 540+cm, 370+cm);
			glPopMatrix();
			glEnd();
		}
	}

	if (cntr38 >= 0 && cntr38 <= 18)
	{
		z5 -= 0.5;
		z6 += 0.5;
		//z7 += 0.5;
		cntr38++;
	}

	if (cntr38 == 18)
	{
		z5 = 0;
		z6 = 0;
		z7 = 0;
		cntr38++;
	}

	if (cntr38 == 40)
	{
		z5 = -9;
		z6 = -9;
	}
	glutPostRedisplay();
}

void chopstick2_move()
{
	//glColor3f(1.0, 1.0, 0.0);			//hand
	//glColor3f(1.0, 0.980392156, 0.803921568);
	glColor3f(0.803921568, 0.745098039, 0.439215686);
	for (GLint f = 0; f < 50000; f++)
	{
		for (GLint cm1 = 0; cm1 < 10; cm1 += 10)
		{
			glPushMatrix();
			glTranslatef(z8, z7, 0.0);
			//keybox(605 + hm, 225 + hm, 595 + hm, 200 + hm);
			//keybox(595 + hm, 200 + hm, 560 + hm, 260 + hm);
			//keybox(575+hm, 220+hm, 565+hm, 200+hm);
			//keybox(590 + hm, 190 + hm, 515 + hm, 220 + hm);
			chopsticks(450+cm1, 345+cm1, 405+cm1, 365+cm1);
			chopsticks(385+cm1, 290+cm1, 430+cm1, 290+cm1);
			glPopMatrix();
			glEnd();
		}
	}
	/*if (cntr35 >= 0 && cntr35 <= 30)
	{
		z7 += 0.5;
		z8 -= 0.5;
		cntr35++;
	}

	if (cntr35 == 30)
	{
		z7 = 3;
		z8 = 3;
	}
	//glEnd();
	//drawpacket20 = !drawpacket20;
	//glEnd();
	glutPostRedisplay();*/

	if (cntr40 >= 0 && cntr40 <= 18)
	{
		z7 += 0.5;
		z8 -= 0.5;
		//z7 += 0.5;
		cntr40++;
	}

	if (cntr40 == 18)
	{
		z7 = 0;
		z8 = 0;
		//z7 = 0;
		cntr40++;
	}

	if (cntr40 == 40)
	{
		z7 = -9;
		z8 = -9;
	}
	glutPostRedisplay();
}

							//**********intial_packets**********//

void packet1()
{
	glColor3f(1.0,	1.0, 1.0);					//3_packets_start_1st_building

			for (GLint k = 0; k < 500; k++)
			{
					for (GLint i = 0; i < 50; i += 50)
					{
						if (drawpacket)
						{
							glPushMatrix();

							for (GLint j = 0; j < 3; j++)
							{
								glTranslatef(x, y, 0.0);
								glBegin(GL_POLYGON);
								glVertex2i(264 + i, 486 + i);
								glVertex2i(264 + i, 490 + i);
								glVertex2i(270 + i, 490 + i);
								glVertex2i(270 + i, 486 + i);
								glEnd();
							}
						}
					}
					glPopMatrix();
				}
	y += 1;
	x += 1;
	if (x == 4 && y == 4)
		drawpacket = !drawpacket;
	glutPostRedisplay();
}

void packet1_move()
{
	glColor3f(1.0, 1.0, 0.0);							//yellow_packet_going_straight
		for (GLint j = 0; j < 10; j += 10)
		{
			for (GLint f = 0; f < 500; f++)
			if (drawpacket1)
			{
				glPushMatrix();
				glTranslatef(x2, 0.0, 0.0);
				glBegin(GL_POLYGON);
				glVertex2i(308 + j, 494 + j);
				glVertex2i(308 + j, 508 + j);
				glVertex2i(328 + j, 508 + j);
				glVertex2i(328 + j, 494 + j);
				glEnd();
				glPopMatrix();

		}
	}
	x2 += 6;
	if (x2 == 450)
	{
		drawpacket1 = !drawpacket1;
		new1 = 1;
		new2 = 1;
	}
}

void packet12_move()
{
	glColor3f(0.0, 0.0, 1.0);							//blue_packet_going_diagonal

	for (GLint p = 0; p < 150; p += 150)
	{
		cntr2++;
		for (GLint c = 0; c < 50000; c++)
		for (GLint s = 0; s < 500; s++);

		if (drawpacket3)
		{
			glPushMatrix();
			glTranslatef(x3, y3, 0.0);
			glBegin(GL_POLYGON);
			glVertex2i(296 + p, 494 + p);
			glVertex2i(296 + p, 508 + p);
			glVertex2i(316 + p, 508 + p);
			glVertex2i(316 + p, 494 + p);
			glEnd();
			glPopMatrix();
			step();
		}
	}
	if (cntr2 == 120)
	{
		drawpacket3 = !drawpacket3;
		new5 = 1;
		new6 = 1;
	}
}

void packet13_move()
{
	glColor3f(1.0, 0.0, 0.0);							//red_packet_going_down

	for (GLint q = 0; q < 205; q += 205)
	{
		cntr3++;
		for (GLint t = 0; t < 500; t++)
		for (GLint u = 0; u < 500; u++);
		if (drawpacket4)
		{
			glPushMatrix();
			glTranslatef(x4, y4, 0.0);
			glBegin(GL_POLYGON);
			glVertex2i(320 + q, 494 + q);
			glVertex2i(320 + q, 508 + q);
			glVertex2i(340 + q, 508 + q);
			glVertex2i(340 + q, 494 + q);
			glEnd();
			glPopMatrix();
			step1();
		}
	}
	if (cntr3 == 205)
	{
		drawpacket4 = !drawpacket4;
		new3 = 1;
		new4 = 1;
	}
}

							//**********functions_for_initiat_packet_movement**********//

void step()
{
		if (cntr >= 40 && cntr <= 80)
		{
			x3 += 2;
			cntr++;
		}
		else if (cntr >= 80 && cntr <= 130)
		{
			x3 += 6;
			y3 -= 6;
			cntr++;
		}
		else if (cntr >= 130 && cntr <= 160)
		{
			x3 += 2;
			cntr++;
		}
}

void step1()
{
	if (cntr1 >= 40 && cntr1 <= 80)
	{
		x4 += 2;
		cntr1++;
	}
	else if (cntr1 >= 80 && cntr1 <=230)
	{
		x4 -= 0.5;
		y4 -= 2.0;
		cntr1++;
	}
	else if (cntr1 >= 230 && cntr1 <= 270)
	{
		x4 -= 6;
		cntr1++;
	}
}

							//**********wall_clock**********//

void clock()
{
	GLint r = 600, p = 300;

	glColor3f(0.98, 0.91, 0.71);
	glBegin(GL_POLYGON);
	glVertex2f(200 + r, 200 + p);
	glVertex2f(200 + r, 290 + p);
	glVertex2f(250 + r, 290 + p);
	glVertex2f(250 + r, 200 + p);
	glEnd();


	//glColor3f(0.0,0.0,1.0);
	glColor3f(0.98, 0.91, 0.71);
	glBegin(GL_TRIANGLES);
	glVertex2f(185 + r, 290 + p);
	glVertex2f(265 + r, 290 + p);
	glVertex2f(225 + r, 330 + p);
	glEnd();

	glColor3f(0.49, 0.04, 0.01);
	glLineWidth(4.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(200 + r, 200 + p);
	glVertex2f(200 + r, 290 + p);
	glVertex2f(185 + r, 290 + p);
	glVertex2f(225 + r, 330 + p);
	glVertex2f(265 + r, 290 + p);
	glVertex2f(250 + r, 290 + p);
	glVertex2f(250 + r, 200 + p);
	glEnd();

	glColor3f(0.49, 0.04, 0.01);
	glLineWidth(2.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(205 + r, 205 + p);
	glVertex2f(205 + r, 285 + p);
	glVertex2f(245 + r, 285 + p);
	glVertex2f(245 + r, 205 + p);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glPointSize(7.0);
	glBegin(GL_POINTS);
	glVertex2f(225 + r, 207 + p);
	glVertex2f(207 + r, 245 + p);
	glVertex2f(225 + r, 283 + p);
	glVertex2f(243 + r, 245 + p);
	glVertex2f(225 + r, 245 + p);
	glEnd();

	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2f(225 + r, 245 + p);
	glVertex2f(225 + r, 265 + p);
	glVertex2f(225 + r, 245 + p);
	glVertex2f(240 + r, 220 + p);
	glEnd();
}

							//**********yellow_packets_movement**********//

void packet21_move()
{
	glColor3f(1.0, 1.0, 0.0);

	for (GLint p = 0; p < 180; p += 180)
	{
		cntr5++;
		cntr25++;
		for (GLint c = 0; c < 500; c++)
		for (GLint s = 0; s < 500; s++);

		if (drawpacket6)
		{
			glPushMatrix();
			glTranslatef(x6, y6, 0.0);
			glBegin(GL_POLYGON);
			glVertex2i(726 + p, 494 + p);
			glVertex2i(726 + p, 508 + p);
			glVertex2i(746 + p, 508 + p);
			glVertex2i(746 + p, 494 + p);
			glEnd();
			glPopMatrix();
			step3();
		}
	}
	if (cntr25 == 180)
		drawpacket6 = !drawpacket6;
}

void step3()
{
	if (cntr5 >= 40 && cntr5 <= 80)
	{
		x6 -= 2;
		cntr5++;
	}
	else if (cntr5 >= 80 && cntr5 <= 180)
	{
		x6 -= 6;
		y6 -= 6;
		cntr5++;
	}
	else if (cntr5 >= 180 && cntr5 <= 330)
	{
		x6 -= 2;
		cntr5++;
	}
}

void packet22_move()
{
	glColor3f(1.0, 1.0, 0.0);

	for (GLint q = 0; q < 250; q += 250)
	{
		cntr4++;
		cntr26++;
		for (GLint t = 0; t < 500; t++)
		for (GLint u = 0; u < 500; u++);
		if (drawpacket5)
		{
			glPushMatrix();
			glTranslatef(x5, y5, 0.0);
			glBegin(GL_POLYGON);
			glVertex2i(750 + q, 494 + q);
			glVertex2i(750 + q, 508 + q);
			glVertex2i(770 + q, 508 + q);
			glVertex2i(770 + q, 494 + q);
			glEnd();
			glPopMatrix();
			step2();
		}
	}
	if (cntr26 == 250)
		drawpacket5 = !drawpacket5;
}

void step2()
{
	if (cntr4 >= 40 && cntr4 <= 80)
	{
		x5 -= 2;
		cntr4++;
	}
	else if (cntr4 >= 80 && cntr4 <= 380)
	{
		x5 -= 0.5;
		y5 -= 2.0;
		cntr4++;
	}
	else if (cntr4 >= 380 && cntr4 <= 480)
	{
		x5 += 2;
		cntr4++;
	}
}

							//**********red_packets_movement**********//

void packet31_move()
{
	glColor3f(1.0, 0.0, 0.0);
	for (GLint j = 0; j < 10; j += 10)
	{
		for (GLint f = 0; f < 500; f++)
		if (drawpacket8)
		{
			glPushMatrix();
			glTranslatef(x8, y8, 0.0);
			glBegin(GL_POLYGON);
			glVertex2i(300 + j, 194 + j);
			glVertex2i(300 + j, 208 + j);
			glVertex2i(320 + j, 208 + j);
			glVertex2i(320 + j, 194 + j);
			glEnd();
			glPopMatrix();
		}
	}
	x8 += 6;
	if (x8 == 450)
		drawpacket8 = !drawpacket8;
	glutPostRedisplay();
}

void packet32_move()
{
	glColor3f(1.0, 0.0, 0.0);

	for (GLint p = 0; p < 160; p += 160)
	{
		cntr6++;
		cntr28++;
		for (GLint c = 0; c < 50000; c++)
		for (GLint s = 0; s < 500; s++);

		if (drawpacket9)
		{
			glPushMatrix();
			glTranslatef(x9, y9, 0.0);
			glBegin(GL_POLYGON);
			glVertex2i(312 + p, 194 + p);
			glVertex2i(312 + p, 208 + p);
			glVertex2i(332 + p, 208 + p);
			glVertex2i(332 + p, 194 + p);
			glEnd();
			glPopMatrix();
			step4();
		}
	}
	if (cntr28 == 160)
		drawpacket9 = !drawpacket9;
}

void step4()
{
	if (cntr6 >= 40 && cntr6 <= 80)
	{
		x9 += 2;
		cntr6++;
	}
	else if (cntr6 >= 80 && cntr6 <= 180)
	{
		x9 += 6;
		y9 += 6;
		cntr6++;
	}
	else if (cntr6 >= 180 && cntr6 <= 235)
	{
		x9 += 2;
		cntr6++;
	}
}

							//**********blue_packets_movement**********//

void packet41_move()
{
	glColor3f(0.0, 0.0, 1.0);
	for (GLint j = 0; j < 10; j += 10)
	{
		for (GLint f = 0; f < 500; f++)
		if (drawpacket11)
		{
			glPushMatrix();
			glTranslatef(x11, y11, 0.0);
			glBegin(GL_POLYGON);
			glVertex2i(734 + j, 172 + j);
			glVertex2i(734 + j, 186 + j);
			glVertex2i(754 + j, 186 + j);
			glVertex2i(754 + j, 172 + j);
			glEnd();
			glPopMatrix();
		}
	}
	x11 -= 10;
	if (x11 == -500)
		drawpacket11 = !drawpacket11;
	glutPostRedisplay();
}

void packet42_move()
{
	glColor3f(0.0, 0.0, 1.0);

	for (GLint q = 0; q < 300; q += 300)
	{
		cntr30++;
		cntr7++;
		for (GLint t = 0; t < 500; t++)
		for (GLint u = 0; u < 500; u++);
		if (drawpacket12)
		{
			glPushMatrix();
			glTranslatef(x12, y12, 0.0);
			glBegin(GL_POLYGON);
			glVertex2i(712 + q, 172 + q);
			glVertex2i(712 + q, 186 + q);
			glVertex2i(732 + q, 186 + q);
			glVertex2i(732 + q, 172 + q);
			glEnd();
			glPopMatrix();
			step5();
		}
	}
	if (cntr30 == 300)
		drawpacket12 = !drawpacket12;
}

void step5()
{
	if (cntr7 >= 40 && cntr7 <= 120)
	{
		x12 -= 2;
		cntr7++;
	}
	else if (cntr7 >= 80 && cntr7 <= 445)
	{
		y12 += 2.0;
		cntr7++;
	}
	else if (cntr7 >= 445 && cntr7 <= 550)
	{
		x12 += 2;
		cntr7++;
	}
}

								//**********roads_function**********//

void roads()
{
	glColor3f(0.184314, 0.309804, 0.309804);
	square(445,0,505,475,575,475,515,0);
	square(0, 280, 0, 340, 1350, 340, 1350, 280);

	glColor3f(1.0, 1.0, 1.0);
	square(475, 20, 480, 60, 495, 60, 490, 20);
	square(485, 100, 490, 140, 505, 140, 500, 100);
	square(495, 180, 500, 220, 515, 220, 510, 180);
	square(505, 260, 510, 300, 525, 300, 520, 260);
	square(515, 340, 520, 380, 535, 380, 530, 340);
	square(525, 420, 530, 460, 545, 460, 540, 420);

	square(10, 305, 15, 312, 40, 312, 35, 305);
	square(60, 305, 65, 312, 90, 312, 85, 305);
	square(110, 305, 115, 312, 140, 312, 135, 305);
	square(160, 305, 165, 312, 190, 312, 185, 305);
	square(210, 305, 215, 312, 240, 312, 235, 305);
	square(260, 305, 265, 312, 290, 312, 285, 305);
	square(310, 305, 315, 312, 340, 312, 335, 305);
	square(360, 305, 365, 312, 390, 312, 385, 305);
	square(410, 305, 415, 312, 440, 312, 435, 305);
	square(460, 305, 465, 312, 490, 312, 485, 305);
	square(510, 305, 515, 312, 540, 312, 535, 305);
	square(560, 305, 565, 312, 590, 312, 585, 305);
	square(610, 305, 615, 312, 640, 312, 635, 305);
	square(660, 305, 665, 312, 690, 312, 685, 305);
	square(710, 305, 715, 312, 740, 312, 735, 305);
	square(760, 305, 765, 312, 790, 312, 785, 305);
	square(810, 305, 815, 312, 840, 312, 835, 305);
	square(860, 305, 865, 312, 890, 312, 885, 305);
	square(910, 305, 915, 312, 940, 312, 935, 305);
	square(960, 305, 965, 312, 990, 312, 985, 305);
}

							//**********philosophers_walls_carpet**********//

void philo_walls()
{

	GLint i = 3;
	glColor3f(1.00, 0.43, 0.78); // blue

	square(130 * i, 150 * i, 130 * i, 450 * i, 370 * i, 450 * i, 370 * i, 150 * i);
	glColor3f(0.30, 0.30, 1.00);

	square(0 * i, 0 * i, 0 * i, 500 * i, 130 * i, 450 * i, 130 * i, 150 * i);//side wall1

	glColor3f(0.8, 0.8, 0.8);//grey80
	square(0 * i, 0 * i, 130 * i, 150 * i, 370 * i, 150 * i, 500 * i, 0 * i);

	glColor3f(0.77, 0.85, 0.89);
	window(65 * 2, 200 * 2, 65 * 2, 240 * 2, 95 * 2, 265 * 2, 95 * 2, 226.5 * 2); //window

	glColor3f(1.0, 1.0, 1.0);
	square(155, 468, 155, 498, 165, 507, 165, 477);
	square(132, 440, 132, 450, 188, 495, 188, 485);
	square(162, 400, 132, 400, 192, 454, 222, 454);
	glColor3f(0.51, 0.0, 0.0); //deep maroon carpet
	square(60 * i, 30 * i, 130 * i, 120 * i, 230 * i, 120 * i, 180 * i, 30 * i);

	glColor3f(0.98, 0.84, 0.65);
	square(75 * i, 40 * i, 130 * i, 110 * i, 218 * i, 110 * i, 177 * i, 40 * i);

	//carpet strings
	draw_line11(180, 90, 170, 80, 360);//bottom
	draw_line11(384, 360, 394, 365, 300);//top
	draw_line21(540, 90, 550, 85, 122);//right
	draw_line31(180, 90, 170, 88, 72);//left

	dine_light();
}

void draw_line11(GLint x1, GLint y1, GLint x2, GLint y2, GLint m)
{
	for (GLint k = 0; k < m; k++)
	{
		k = k + 8;
		glColor3f(0.51, 0.0, 0.0);
		glLineWidth(2.0);
		glBegin(GL_LINES);
		glVertex2f(x1 + k, y1);
		glVertex2f(x2 + k, y2);
		glVertex2f(x1 + k, y1);
		glVertex2f(x2 + 3 + k, y2);
		glEnd();
	}
}

void draw_line21(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLint m)
{
	for (GLint k = 0; k < m; k++)
	{
		k = k + 2;
		glColor3f(0.51, 0.0, 0.0);
		glLineWidth(2.0);
		glBegin(GL_LINES);
		glVertex2f(x1 + k*1.2, y1 + k*1.2 + k);
		glVertex2f(x2 + k*1.2, y2 + k*1.2 + k);
		glVertex2f(x1 + k*1.2, y1 + k*1.2 + k);
		glVertex2f(x2 + 2 + k*1.2, y2 + 2 + k*1.2 + k);
		glEnd();
	}
}

void draw_line31(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLint m)
{
	for (GLint k = 0; k < m; k++)
	{
		k = k + 1;
		glColor3f(0.51, 0.0, 0.0);
		glLineWidth(2.0);
		glBegin(GL_LINES);
		glVertex2f(x1 + k*2.9, y1 + k*2.75 + k);
		glVertex2f(x2 + k*2.9, y2 + k*2.75 + k);
		glVertex2f(x1 + k*2.9, y1 + k*2.75 + k);
		glVertex2f(x2 + 2 + k*2.9, y2 + 2 + k*2.75 + k);
		glEnd();
	}
}

							//**********light_lamp**********//

void dine_light()
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);

	glVertex2f(580, 600);
	glVertex2f(600, 630);
	glVertex2f(620, 600);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(600, 580);
	glVertex2f(600, 650);
	glEnd();

	glColor3f(1.0, 1.0, 0.2);
	circle(600, 590, 15);
}

							//**********display_function**********//

void display()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(0, 1000, 0.0, 650, -2000, 1500);
	glMatrixMode(GL_MODELVIEW);

	glClearColor(1.0, 0.509803921, 0.278431372,0.0);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	if (f == 0)
		menu3();

	else if (f == 1)
		menu1();

	else if (f == 2)
		menu2();

	else if (f == 3)
		help();

	else if (f == 4)
		intro();

	else if (f == 5)
	{
		glClearColor(0.623529, 0.623529, 0.372549, 0.0);
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		option1();
	}
	else if (f == 6)
	{
		glClearColor(0.5, 1.0, 0.5, 0.0);
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		option2();
	}
	glFlush();
	glutSwapBuffers();
}
							//**********NormalKey_function**********//

void NormalKey(GLubyte key, GLint x, GLint y)
{
	if (key == 27)
		exit(0);
	if (f == 1)
	{
		f = 2;
		glutPostRedisplay();
	}
	else if (f == 2)	//menu
	{
		switch (key)
		{
		case 13:
		case '1':f = 0;	break;
		case '2':f = 4;	break;
		case '3':f = 3;	break;
		case 'b':
		case 'B':f = 1;	break;
		case '4':	exit(0);
		}
		glutPostRedisplay();
	}

	else if (f == 3)	//help
	{
		if (key == 'b' || key == 'B')
			f = 2;
		else if (key == 13)			//"enter" ASCII
			f = 0;
		glutPostRedisplay();
	}

	else if (f == 4)	//intro
	{
		if (key == 'b' || key == 'B')
			f = 2;
		else if (key == 13)
			f = 0;
		glutPostRedisplay();
	}

	else if (f == 0)	//start
	{
		switch (key)
		{
		case 'P':
		case 'p':f = 5;	break;
		case 'D':
		case 'd':f = 6;	break;
		case '4':	exit(0);
		glutPostRedisplay();
		}

		if (key == 'b' || key == 'B')
			f = 2;
		else if (key == 13)
			f = 2;
		glutPostRedisplay();
	}

	else if (f == 5)	//philosophers
	{
		if (key == 'b' || key == 'B')
			f = 0;
		else if (key == 13)
			f = 0;
		glutPostRedisplay();
	}

	else if (f == 6)	//flooding
	{
		if (key == 'b' || key == 'B')
			f = 0;
		else if (key == 13)
			f = 0;
		glutPostRedisplay();
	}

	display();
}

							//**********main_function**********//

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(1350, 728);				//window size
	glutInitWindowPosition(0, 0);
	glutCreateWindow("PROJECT");				//creating window
	glutDisplayFunc(display);						//calling display function
	glOrtho(0.0, 0.0, 0.0, 728.0, 0.0, 1.0);
	glutKeyboardFunc(NormalKey);         /*Normal key is pressed */

	glutCreateMenu(myMenu);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutAddMenuEntry("Main Menu", 1);
	glutAddMenuEntry("Philosophers", 2);
	glutAddMenuEntry("Flooding", 3);
	glutAddMenuEntry("Exit", 4);
	glutMainLoop();
	return 1;
}
