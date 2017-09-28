/*****************************
*9.15 完成构造函数
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
	setWindowTitle("OpenGL Window");//设置窗口标题
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
	//启用smooth shading（阴影平滑）。阴影平滑通过多边形精细的混合色彩，
	//并对外部进行平滑，
	glShadeModel(GL_SMOOTH);

	//设置清除屏幕的颜色。范围0-1
	glClearColor(0.0, 0.0, 0.0, 0.0);

	//设置深度缓存
	glClearDepth(1.0);

	//启用深度测试
	glDepthFunc(GL_DEPTH_TEST);

	/*上面三个功能都是关于depth buffer（深度缓存）。将深度缓存设想为屏幕后面的层。
	深度缓存不断的对物体进入屏幕内部有多深进行跟踪。目前并未真正使用深度缓存。
	几乎所有在屏幕上显示3D场景OpenGL程序都使用深度缓存，它的排序决定哪个物体先画。*/

	//真正精细的透视修正。希望进行最好的透视修正。会十分轻微的影响性能。
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void NewAGLWidget::paintGL()
{
	//清除屏幕和深度缓存
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//重置当前的模型观察矩阵
	//此步会将当前点移动到屏幕中心，X坐标从左到右，Y坐标从下到上，Z坐标从里到外。
	glLoadIdentity();

	//沿坐标系移动
	glTranslatef(-1.5, 0.0, -6.0);
	//fTri旋转角度  旋转轴
	glRotatef(fTri, 0.0, 1.0, 0.0);

	//开始绘制三角形
	glBegin(GL_TRIANGLES);
		//前侧面
		glColor3f(1.0,0.0,0.0);
		glVertex3f(0.0, 1.0, 0.0);

		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(-1.0, -1.0, 1.0);

		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(1.0, -1.0,1.0);

		//右侧面
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.0, 1.0, 0.0);

		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(1.0, -1.0, 1.0);

		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(1.0, -1.0, -1.0);

		//后侧面
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.0, 1.0, 0.0);

		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(-1.0, -1.0, -1.0);

		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(1.0, -1.0, -1.0);

		//左侧面
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.0, 1.0, 0.0);

		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(-1.0, -1.0, -1.0);

		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(-1.0, -1.0, 1.0);
	//三角形绘制结束
	glEnd();

	glLoadIdentity();
	glTranslatef(1.5, 0.0, -6.0);
	glRotatef(rQuad, 1.0, 0.0, 0.0);

	glColor3f(0.5, 0.5, 1.0);
	glBegin(GL_QUADS);
		//前面
		glVertex3f(-1.0, 1.0, 1.0);
		glVertex3f(1.0, 1.0, 1.0);
		glVertex3f(1.0, -1.0, 1.0);
		glVertex3f(-1.0, -1.0, 1.0);
	
		//后面
		glVertex3f(-1.0, 1.0, -1.0);
		glVertex3f(1.0, 1.0, -1.0);
		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f(1.0, -1.0, -1.0);

		//左面
		glVertex3f(-1.0, 1.0, -1.0);
		glVertex3f(-1.0, 1.0, 1.0);
		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f(-1.0, -1.0, 1.0);
		
		//右面
		glVertex3f(1.0, 1.0, 1.0);
		glVertex3f(1.0, 1.0, -1.0);
		glVertex3f(1.0, -1.0, -1.0);
		glVertex3f(1.0, -1.0, 1.0);

		//上面
		glVertex3f(-1.0, 1.0, 1.0);
		glVertex3f(-1.0, 1.0, -1.0);
		glVertex3f(1.0, 1.0, -1.0);
		glVertex3f(1.0, 1.0, 1.0);

		//下面
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

	//重置当前的视口
	glViewport(0, 0, (GLint)width, (GLint)height);

	//选择投影矩阵
	glMatrixMode(GL_PROJECTION);

	//重置投影矩阵
	glLoadIdentity();

	//建立透视投影矩阵
	gluPerspective(45.0, (GLfloat)width / (GLfloat)height, 0.1, 100);
	
	//选择模型观察矩阵
	glMatrixMode(GL_MODELVIEW);

	//重置模型观察矩阵
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

