#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"
#include <math.h>


typedef struct Color{
  float R;
  float G;
  float B;
  float A;
}tColor; 

typedef struct Coordenadas{
  int coordenadaX;
  int coordenadaY;
}tCoordenadas ; 

void PutPixel(int coordenadaX, int coordenadaY, Color *cor){

  int byte = (coordenadaX* 4) + (coordenadaY * IMAGE_WIDTH * 4);
  FBptr[byte] = cor->R;
  FBptr[byte + 1] = cor->G;
  FBptr[byte + 2] = cor->B;
  FBptr[byte + 3] = cor->A;

}

void DrawLineBresenham(Coordenadas * p0, Coordenadas * p1, Color * corInicial, Color * corFinal)
{
	int dX = p1->coordenadaX - p0->coordenadaX, 
	    dY = p1->coordenadaY - p0->coordenadaY,
	    x = 1, y = 1,
	    d,coordX, coordY,i;          

	Color * corAuxiliar = (struct Color *) malloc(sizeof(Color));
	corAuxiliar->R = corInicial->R;
	corAuxiliar->G = corInicial->G;
	corAuxiliar->B = corInicial->B;
	corAuxiliar->A = corInicial->A;

	if(dX < 0) x = -x;
	if(dY < 0) y = -y;

	dX = abs(dX);
	dY = abs(dY);

	float deltaR = (corFinal->R - corAuxiliar->R),
          deltaG = (corFinal->G - corAuxiliar->G),
          deltaB = (corFinal->B - corAuxiliar->B),
          deltaA = (corFinal->A - corAuxiliar->A);

	coordX = p0->coordenadaX;
	coordY = p0->coordenadaY;

	if (dX > dY) {
		d = (dY << 1) - dX;
		deltaR /= dX;
    	deltaG /= dX;
	    deltaB /= dX;
    	deltaA /= dX;

		for(i = 0; i < dX; i++) {

			corAuxiliar->R += deltaR;
			corAuxiliar->G += deltaG;
			corAuxiliar->B += deltaB;
			corAuxiliar->A += deltaA;

			PutPixel(coordX,coordY,corAuxiliar);

			if(d < 0)
				d += dY << 1;
			else {
				coordY += y;
				d += (dY - dX) << 1;
			}
			coordX += x;
		}
	}
  else {
		d = (dX << 1) - dY;
		deltaR /= dY;
	    deltaG /= dY;
    	deltaB /= dY;
    	deltaA /= dY;

	    for(i = 0; i < dY; i++) {
				corAuxiliar->R += deltaR;
				corAuxiliar->G += deltaG;
				corAuxiliar->B += deltaB;
				corAuxiliar->A += deltaA;

	      PutPixel(coordX,coordY,corAuxiliar);
	      if(d < 0)
	      d += dX << 1;
	      else {
	        coordX += x;
	        d += (dX - dY) << 1;
	      }
			coordY += y;
	    }
	}
}
void drawLine(Coordenadas * p0, Color * cor1, Coordenadas * p1, Color * cor2){
DrawLineBresenham(p0,p1,cor1,cor2);
}
void drawTriangle(Coordenadas * pontoInicial, Color * cor1, Coordenadas * pontoIntermediario, Color * cor2, Coordenadas * pontoFinal, Color * cor3) {
     DrawLineBresenham(pontoInicial,pontoIntermediario,cor1,cor2);
	 DrawLineBresenham(pontoIntermediario,pontoFinal,cor2,cor3);
	 DrawLineBresenham(pontoFinal,pontoInicial,cor3,cor1);
}
	
#endif // _MYGL_H_
