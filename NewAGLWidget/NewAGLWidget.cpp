/*****************************
*9.15 ��ɹ��캯��
*****************************/

#include "NewAGLWidget.h"
#include <GL/glu.h>
#include <QKeyEvent>

NewAGLWidget::NewAGLWidget(QWidget* parent,const char* name,bool fs)
	: QGLWidget(parent)
{
	fullScreen = fs;
	GLfloat fTri = 0.2;
	GLfloat rQuad = 0.0;
	setGeometry(50, 50, 640, 480);
	setWindowTitle("OpenGL Window");//���ô��ڱ���
	if (fs)
	{
		showFullScreen();
	}
}

NewAGLWidget::~NewAGLWidget()
{

}

void NewAGLWidget::initializeGL()
{
	//����smooth shading����Ӱƽ��������Ӱƽ��ͨ������ξ�ϸ�Ļ��ɫ�ʣ�
	//�����ⲿ����ƽ����
	glShadeModel(GL_SMOOTH);

	//���������Ļ����ɫ����Χ0-1
	glClearColor(0.0, 0.0, 0.0, 0.0);

	//������Ȼ���
	glClearDepth(1.0);

	//������Ȳ���
	glDepthFunc(GL_DEPTH_TEST);

	/*�����������ܶ��ǹ���depth buffer����Ȼ��棩������Ȼ�������Ϊ��Ļ����Ĳ㡣
	��Ȼ��治�ϵĶ����������Ļ�ڲ��ж�����и��١�Ŀǰ��δ����ʹ����Ȼ��档
	������������Ļ����ʾ3D����OpenGL����ʹ����Ȼ��棬������������ĸ������Ȼ���*/

	//������ϸ��͸��������ϣ��������õ�͸����������ʮ����΢��Ӱ�����ܡ�
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void NewAGLWidget::paintGL()
{
	//�����Ļ����Ȼ���
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//���õ�ǰ��ģ�͹۲����
	//�˲��Ὣ��ǰ���ƶ�����Ļ���ģ�X��������ң�Y������µ��ϣ�Z������ﵽ�⡣
	glLoadIdentity();

	//������ϵ�ƶ�
	glTranslatef(-1.5, 0.0, -6.0);
	//fTri��ת�Ƕ�  ��ת��
	glRotatef(fTri, 0.0, 1.0, 0.0);

	//��ʼ����������
	glBegin(GL_TRIANGLES);
		//ǰ����
		glColor3f(1.0,0.0,0.0);
		glVertex3f(0.0, 1.0, 0.0);

		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(-1.0, -1.0, 1.0);

		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(1.0, -1.0,1.0);

		//�Ҳ���
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.0, 1.0, 0.0);

		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(1.0, -1.0, 1.0);

		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(1.0, -1.0, -1.0);

		//�����
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.0, 1.0, 0.0);

		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(-1.0, -1.0, -1.0);

		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(1.0, -1.0, -1.0);

		//�����
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.0, 1.0, 0.0);

		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(-1.0, -1.0, -1.0);

		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(-1.0, -1.0, 1.0);
	//�����λ��ƽ���
	glEnd();

	glLoadIdentity();
	glTranslatef(1.5, 0.0, -6.0);
	glRotatef(rQuad, 1.0, 0.0, 0.0);

	glColor3f(0.5, 0.5, 1.0);
	glBegin(GL_QUADS);
		//ǰ��
		glVertex3f(-1.0, 1.0, 1.0);
		glVertex3f(1.0, 1.0, 1.0);
		glVertex3f(1.0, -1.0, 1.0);
		glVertex3f(-1.0, -1.0, 1.0);
	
		//����
		glVertex3f(-1.0, 1.0, -1.0);
		glVertex3f(1.0, 1.0, -1.0);
		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f(1.0, -1.0, -1.0);

		//����
		glVertex3f(-1.0, 1.0, -1.0);
		glVertex3f(-1.0, 1.0, 1.0);
		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f(-1.0, -1.0, 1.0);
		
		//����
		glVertex3f(1.0, 1.0, 1.0);
		glVertex3f(1.0, 1.0, -1.0);
		glVertex3f(1.0, -1.0, -1.0);
		glVertex3f(1.0, -1.0, 1.0);

		//����
		glVertex3f(-1.0, 1.0, 1.0);
		glVertex3f(-1.0, 1.0, -1.0);
		glVertex3f(1.0, 1.0, -1.0);
		glVertex3f(1.0, 1.0, 1.0);

		//����
		glVertex3f(-1.0, -1.0, 1.0);
		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f(1.0, -1.0, -1.0);
		glVertex3f(1.0, -1.0, 1.0);


	glEnd();

 	fTri += 0.2;
 	rQuad -= 0.15;
}

void NewAGLWidget::resizeGL(int width, int height)
{
	if (height == 0)
	{
		height = 1;
	}

	//���õ�ǰ���ӿ�
	glViewport(0, 0, (GLint)width, (GLint)height);

	//ѡ��ͶӰ����
	glMatrixMode(GL_PROJECTION);

	//����ͶӰ����
	glLoadIdentity();

	//����͸��ͶӰ����
	gluPerspective(45.0, (GLfloat)width / (GLfloat)height, 0.1, 100);
	
	//ѡ��ģ�͹۲����
	glMatrixMode(GL_MODELVIEW);

	//����ģ�͹۲����
	glLoadIdentity();

}

void NewAGLWidget::keyPressEvent(QKeyEvent* e)
{
	switch (e->key())
	{
	case Qt::Key_F2:
		fullScreen = !fullScreen;
		if (fullScreen)
		{
			showFullScreen();
		}
		else
		{
			showNormal();
			setGeometry(0,0,640,480);
		}
		updateGL();
		break;
	case Qt::Key_Escape:
		close();
		break;
	default:
		break;
	}
}

