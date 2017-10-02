/*
 * Luis Ángel Cotelo Leyva 
 * cotelus@correo.ugr.es
 */

#include <vector>
#include "objeto3D.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include "octaedro.h"

Octaedro::Octaedro(){

	this->caras.resize(0);
	this->vertices.resize(0);
	this->colores.resize(0);
	this->tecla = '0';
	this->valido = false;

}

// El constructor principal comprueba que al menos lo que se recibe como parametros parece ser un OctaedroRegular, si no lo parece,
// llama al constructor por defecto que lo deja en un estado invalido ( no se pinta ni se hace nada con el )
Octaedro::Octaedro(std::vector<int>ccaras, std::vector<float>cvertices, std::vector<float>ccolores){
	if(ccaras.size() == 24 && cvertices.size() == 18 && ccolores.size() == 18){
		this->caras = ccaras;
		this->vertices = cvertices;
		this->colores = ccolores;
		this->tecla = '0';
		this->valido = true;
	}
	else Octaedro();

}

void Octaedro::setTecla(unsigned char nuevaTecla){
	this->tecla = nuevaTecla;
}
unsigned char Octaedro::getTecla(){
	return this->tecla;
}

void Octaedro::setValido(bool cvalido){
	this->valido = cvalido;
}

bool Octaedro::getValido(){
	return this->valido;
}

void Octaedro::dibuja(){
	Objeto3D::dibuja();
}