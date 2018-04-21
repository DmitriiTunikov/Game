#include <iostream>
#include <glut.h>

#include "PhysicsEngine.h"
#include "BoundingCircle.h"

#define WIN_WIDTH 1820
#define WIN_HEIGHT 980

PhysicsEngine PhysEngine;

void Init(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, WIN_WIDTH, 0, WIN_HEIGHT, -5.0, 5.0);
}


void Draw(float x, float y, float r)
{
	glColor3f(1, 0, 0);
	glBegin(GL_LINE_LOOP);

	for (int i = 0; i < 10; i++)
	{
		float angle = 2.0 * 3.1415926 * float(i) / float(10);
		float dx = r * cosf(angle);
		float dy = r * sinf(angle);
		glVertex2f(x + dx, y + dy);
	}

	glEnd();
}

void DrawObjects()
{
	unsigned int i;

	for (i = 0; i < PhysEngine.GetNumObjects(); i++)
	{
		PhysicsObject &Cur = PhysEngine.GetObject(i);
		Vector2 pos = Cur.GetPosition();
		float r = Cur.GetRadius();
		Draw(pos.x, pos.y, r);
	}
}

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	DrawObjects();

	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();

}

void timerPhysicsUpdate(int value)
{
	glutPostRedisplay();

	PhysEngine.Simulate(1);
	PhysEngine.HandleCollisions();

	glutTimerFunc(3, timerPhysicsUpdate, 0);
}


int main(int argc, char ** argv)
{
	glutInit(&argc, argv);

	Vector2 position(170, 100);
	float radius = 50;
	Collider *colliderBullet = new BoundingCircle(position, radius);
	PhysicsObject phBullet(colliderBullet, Vector2(0.5, 0.5));
	PhysEngine.AddObject(phBullet);
	

	Vector2 position1(500, 500);
	float radius1 = 50;
	Collider *colliderBullet1 = new BoundingCircle(position1, radius1);
	PhysicsObject phBullet1(colliderBullet1, Vector2(-0.5, -0.5));
	PhysEngine.AddObject(phBullet1);


	Vector2 positio(250, 500);
	float radiu = 50;
	Collider *colliderBulle = new BoundingCircle(positio, radiu);
	PhysicsObject phBulle(colliderBulle, Vector2(0, -0.5));
	PhysEngine.AddObject(phBulle);



	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Python");

	Init();

	glutDisplayFunc(Display);
	glutTimerFunc(0, timerPhysicsUpdate, 0);
	glutMainLoop();

	return 0;
}