#include "main.h"

void MyGlDraw(void)
{
	tColor cor0 = {255,255,255,255};
	tColor cor1 = {255,0,0,0};
	tColor cor2 = {0,255,0,0};
	tColor cor3 = {0,0,255,0};
	Coordenadas * p0 = (struct Coordenadas *) malloc(sizeof(Coordenadas));
	Coordenadas * p1 = (struct Coordenadas *) malloc(sizeof(Coordenadas));
	Coordenadas * p2 = (struct Coordenadas *) malloc(sizeof(Coordenadas));
	Coordenadas * p3 = (struct Coordenadas *) malloc(sizeof(Coordenadas));
	
	for(int i = 0; i<= 512; i+=10){
	PutPixel(i,i,&cor3);
	};	
	for(int i = 0; i<= 512; i+=10){
	int j= 512 - i;
	PutPixel(j,i,&cor1);
	};	
	for(int i = 0; i<= 512; i+=10){
	PutPixel(i,256,&cor2);
	};
	
	p0->coordenadaX = 0;
	p0->coordenadaY = 0;
	p1->coordenadaX = 512;
	p1->coordenadaY = 512;
	drawLine(p0,&cor2,p1,&cor3);
	p0->coordenadaX = 512;
	p0->coordenadaY = 0;
	p1->coordenadaX = 0;
	p1->coordenadaY = 512;
	//drawLine(p0,&cor1,p1,&cor2);
	p0->coordenadaX = 0;
	p0->coordenadaY = 256;
	p1->coordenadaX = 512;
	p1->coordenadaY = 256;
	//drawLine(p0,&cor1,p1,&cor3);	
	p0->coordenadaX = 0;
	p0->coordenadaY = 60;
	p1->coordenadaX = 512;
	p1->coordenadaY = 462;
	//drawLine(p0,&cor0,p1,&cor3);
	p0->coordenadaX = 30;
	p0->coordenadaY = 30;
	p1->coordenadaX = 480;
	p1->coordenadaY = 30;
	p2->coordenadaX = 256;
	p2->coordenadaY = 480;
	drawTriangle(p0,&cor3,p1,&cor2,p2,&cor1);
	
}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}
