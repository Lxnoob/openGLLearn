#pragma once
#include<qgl.h>

class NewAGLWidget : public QGLWidget
{
	Q_OBJECT

public:
	NewAGLWidget(QWidget* parent = NULL,const char* name = NULL,bool fs = false);
	~NewAGLWidget();

protected:
 	void initializeGL();//设定窗口部件选项
 	void paintGL();//更新窗口
 	void resizeGL(int width,int height);//响应窗口变化
 	void keyPressEvent(QKeyEvent* e);

protected:
	bool fullScreen;
	GLfloat fTri;//三角形的角度
	GLfloat rQuad;//四边形的角度
};
