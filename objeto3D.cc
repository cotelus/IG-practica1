/*
 * Luis Ángel Cotelo Leyva 
 * cotelus@correo.ugr.es
 */

#include <GL/gl.h>
#include <GL/glut.h>
#include "objeto3D.h"
#include <string>

void Objeto3D::dibujaLineas(){
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, &colores[0]);
	glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
	glDrawElements( GL_TRIANGLES, caras.size(), GL_UNSIGNED_INT, &caras[0]);

	glDisableClientState(GL_COLOR_ARRAY);	
	glDisableClientState(GL_VERTEX_ARRAY);
}

void Objeto3D::dibujaPuntos(){
	glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	glPointSize(10);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, &colores[0]);
	glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
	glDrawElements( GL_TRIANGLES, caras.size(), GL_UNSIGNED_INT, &caras[0]);

	glDisableClientState(GL_COLOR_ARRAY);	
	glDisableClientState(GL_VERTEX_ARRAY);
}

void Objeto3D::dibujaTriangulos(){
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, &colores[0]);
	glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
	glDrawElements( GL_TRIANGLES, caras.size(), GL_UNSIGNED_INT, &caras[0]);

	glDisableClientState(GL_COLOR_ARRAY);	
	glDisableClientState(GL_VERTEX_ARRAY);
}

/* 
	Dibuja las caras pares del color original que tiene el vertice, y las caras impares del color negativo
	al que tiene el vertice, y además se le dice que pinte toda la cara del color que tenga el ultimo vertice
	de cada cara, para que así no haya gradientes de ningun tipo y todas las caras tengan un color solido
*/
void Objeto3D::dibujaAjedrez(){
	std::vector<int>carasPares;
	std::vector<int>carasImpares;
	carasPares.resize(0);
	carasImpares.resize(0);
	std::vector<float>coloresNegativos;
	coloresNegativos.resize(0);

	for (int i = 0; i <= this->colores.size(); i += 3){
		// El color negativo es (255 - colorOriginal) en r, g y b
		int r = 0, g = 0, b = 0;
		r = 255 - colores[i];
		g = 255 - colores[i + 1];
		b = 255 - colores[i + 2];

		coloresNegativos.push_back(r);
		coloresNegativos.push_back(g);
		coloresNegativos.push_back(b);
	}

	for (int i = 0; i <= this->caras.size(); i += 3){
		if (i%2 == 0){
			carasPares.push_back(caras[i]);
			carasPares.push_back(caras[i + 1]);
			carasPares.push_back(caras[i + 2]);
		}
		else{
			carasImpares.push_back(caras[i]);
			carasImpares.push_back(caras[i + 1]);
			carasImpares.push_back(caras[i + 2]);
		}

	}
	glPolygonMode(GL_FRONT, GL_FILL);
	//glShadeModel(GL_FLAT);
	glEnable(GL_CULL_FACE);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	// CarasPares
	glColorPointer(3, GL_FLOAT, 0, &colores[0]);
	glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
	glDrawElements( GL_TRIANGLES, carasPares.size(), GL_UNSIGNED_INT, &carasPares[0]);
	// CarasImpares
	glColorPointer(3, GL_FLOAT, 0, &coloresNegativos[0]);
	glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
	glDrawElements( GL_TRIANGLES, carasImpares.size(), GL_UNSIGNED_INT, &carasImpares[0]);

	glDisableClientState(GL_COLOR_ARRAY);	
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisable(GL_CULL_FACE);
}

void Objeto3D::dibuja(){
	if(valido){
		switch(this->tecla){
			case 'P':this->dibujaPuntos();break;
			case 'L':this->dibujaLineas();break;
			case 'F':this->dibujaTriangulos();break;
			case 'C':this->dibujaAjedrez();break;
		}	
	}
}