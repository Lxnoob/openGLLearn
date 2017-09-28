#pragma once
#include<qgl.h>

class NewAGLWidget : public QGLWidget
{
	Q_OBJECT

public:
	NewAGLWidget(QWidget* parent = NULL,const char* name = NULL,bool fs = false);
	~NewAGLWidget();

protected:
 	void initializeGL();//�趨���ڲ���ѡ��
 	void paintGL();//���´���
 	void resizeGL(int width,int height);//��Ӧ���ڱ仯
 	void keyPressEvent(QKeyEvent* e);

protected:
	bool fullScreen;
	GLfloat fTri;//�����εĽǶ�
	GLfloat rQuad;//�ı��εĽǶ�
};
