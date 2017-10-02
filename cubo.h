/*
 * Luis Ángel Cotelo Leyva 
 * cotelus@correo.ugr.es
 */

#ifndef _CUBO_H
#define _CUBO_H

#include <vector>
#include "objeto3D.h"

class Cubo : public Objeto3D{
public:
	/* Solo con los dos constructores y la clase padre "Objeto3D" ya tendriamos la estructura del cubo.
	 Simplemente tiene un array de flotantes en el que almacena los distintos vertices de forma secuencial 
	 De la manera Vn = ((K-1) * 3); En el que Vn es la posicion real del vertice deseado, y K el vertice ( vertice 4, p.e.)
	 	EJEMPLO DE USO:
	 		VECTOR DE VERTICES = ( 1.0, 0.0, 0.0, 0.0, 0.1, 0.0, 0.0, 0.0, 0.1)
	 		Si se quiere buscar el vertice 2: (0.0, 0.1, 0.0)
	 		Vn = (2-1) * 3 = 3; La posicion 3 (incluida) del vector y dos posiciones mas, es el vertice 2.
	 */
	Cubo();
	Cubo(std::vector<int>ccaras, std::vector<float>cvertices, std::vector<float>ccolores);

	void setTecla(unsigned char nuevaTecla);
	unsigned char getTecla();
	void setValido(bool cvalido);
	bool getValido();

	void dibuja();
};

#endif