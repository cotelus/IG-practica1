/*
 * Luis Ángel Cotelo Leyva 
 * cotelus@correo.ugr.es
 */
#ifndef _OBJETO3D_H
#define _OBJETO3D_H

#include <vector>
#include <string>
#include <GL/gl.h>
#include <GL/glut.h>

class Objeto3D{

protected:
	std::vector<int>caras;
	std::vector<float>vertices;
	std::vector<float>colores;
	unsigned char tecla;
	bool valido;

public:

	void dibujaPuntos();
	void dibujaLineas();
	void dibujaTriangulos();
	void dibujaAjedrez();
	void dibuja();
};

#endif