/*
 * Luis Ángel Cotelo Leyva 
 * cotelus@correo.ugr.es
 */

#include <vector>
#include "objeto3D.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include "cubo.h"

Cubo::Cubo(){

	this->caras.resize(0);
	this->vertices.resize(0);
	this->colores.resize(0);
	this->tecla = '0';
	this->valido = false;

}

// El constructor principal comprueba que al menos lo que se recibe como parametros parece ser un cubo, si no lo parece,
// llama al constructor por defecto que lo deja en un estado invalido ( no se pinta ni se hace nada con el )
Cubo::Cubo(std::vector<int>ccaras, std::vector<float>cvertices, std::vector<float>ccolores){
	if(ccaras.size() == 36 && cvertices.size() == 24 && ccolores.size() == 24){
		this->caras = ccaras;
		this->vertices = cvertices;
		this->colores = ccolores;
		this->tecla = '0';
		this->valido = true;
	}
	else Cubo();

}

void Cubo::setTecla(unsigned char nuevaTecla){
	this->tecla = nuevaTecla;
}
unsigned char Cubo::getTecla(){
	return this->tecla;
}

void Cubo::setValido(bool cvalido){
	this->valido = cvalido;
}

bool Cubo::getValido(){
	return this->valido;
}

void Cubo::dibuja(){
	Objeto3D::dibuja();
}