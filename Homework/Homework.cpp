#include <GL/glut.h>
#include <iostream>

float clickedPt[100][3];//x,y,color(1=red, 2=green, 3=blue, 0= white)
int index = 0;

int color_idx = 0;

int red;
int green;
int blue;

void renderScene(void) {

	for (int a = 0; a < 100; a++)
	{
		for (int b = 0; b < 3; b++)
		{
			std::cout << clickedPt[a][b] << " ";
		}
		std::cout << "\n";
	}



	std::cout << "renderscene시작---------------\n";
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPointSize(5);
	std::cout << "renderscene시의 index" << int(index)<<"\n";

	for (int i = 0; i < int(index); i++) {
		std::cout << "renderscene시의 i" << i << "\n";

		if (clickedPt[i][2] == 0) {
			red = 255;
			green = 255;
			blue = 255;
		}
		if (clickedPt[i][2] == 1) {
			red = 255;
			green = 0;
			blue = 0;
		}
		if (clickedPt[i][2] == 2) {
			red = 0;
			green = 255;
			blue = 0;
		}
		if (clickedPt[i][2] == 3) {
			red = 0;
			green = 0;
			blue = 255;
		}
		glBegin(GL_POINTS);
		glColor3f(red, green, blue);
		glVertex2f(clickedPt[i][0], clickedPt[i][1]);
		std::cout << clickedPt[i]<<"\n";
		std::cout << int(clickedPt[i][0])<<"\n";
		std::cout << int(clickedPt[i][1]) << "\n";
		std::cout << int(clickedPt[i][2]) << "\n";
	}
	glEnd();
	glutSwapBuffers();
}

void processMouse(int button, int state, int x, int y) {
	std::cout << "pocessMouse시작---------------\n";
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		clickedPt[index][0] = ((float)x - 160.0) / 160.0;
		clickedPt[index][1] = -((float)y - 160.0) / 160.0;
		clickedPt[index++][2] = color_idx;
		std::cout <<"index"<< index << "의 color_idx는" << int(clickedPt[index][2])<< "\n";

	}
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	std::cout << "keyboard시작---------------\n";
	switch (key) {
	case '1': 
		//change drawing mode
		glutMouseFunc(processMouse);
		glutPostRedisplay();
		break;
		
	case '2':
		std::cout << "keyboard-case2 시작---------------\n";
		std::cout << "	2눌렀고, clickedPt[index][2]는";
		clickedPt[index][2] = color_idx;
		std::cout << int(clickedPt[index][2])<< "\n";
		color_idx++;
		color_idx %= 4;
		break;

	case 'c':
		//Clear the scene
		glutPostRedisplay();
		break;


		//When key ’ + ’ or ‘ - ’ is pressed
		//	In the Point mode : Change the size of point being drawn(1 ≤ point size ≤ 10)
		//	In the Line mode : Change the width of line being drawn(1 ≤ line width ≤ 10)

		//	When the arrow key is pressed
		//	Move all primitives by 0.1.

		//	Draw the expected result(guiding lines) – Optional(Look at Google)
		//	Use glutPassiveMotionFunc().


	default:
		break;
	}
}

int main(int argc, char** argv) {
	std::cout << "main시작---------------\n";
	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(320, 320);
	glutCreateWindow("OpenGL Sample 01");

	// register callbacks
	glutDisplayFunc(renderScene);
	std::cout << "main-renderscene-------------- - \n";
	glutKeyboardFunc(keyboard);
	std::cout << "main-keyboard------------- - \n";
	glutMouseFunc(processMouse);
	std::cout << "main-processmouse-------------- - \n";


	// enter GLUT event processing cycle
	glutMainLoop();

	return 0;

}