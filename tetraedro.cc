/*
 * Luis Ángel Cotelo Leyva 
 * cotelus@correo.ugr.es
 */

#include <vector>
#include "objeto3D.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include "tetraedro.h"

Tetraedro::Tetraedro(){

	this->caras.resize(0);
	this->vertices.resize(0);
	this->colores.resize(0);
	this->tecla = '0';
	this->valido = false;
}

// El constructor principal comprueba que al menos lo que se recibe como parametros parece ser un tetraedro, si no lo parece,
// llama al constructor por defecto que lo deja en un estado invalido ( no se pinta ni se hace nada con el )
Tetraedro::Tetraedro(std::vector<int>ccaras, std::vector<float>cvertices, std::vector<float>ccolores){
	if(ccaras.size() == 12 && cvertices.size() == 12 && ccolores.size() == 12){
		this->caras = ccaras;
		this->vertices = cvertices;
		this->colores = ccolores;
		this->tecla = '0';
		this->valido = true;
	}
	else Tetraedro();

}

void Tetraedro::setValido(bool cvalido){
	this->valido = cvalido;
}

bool Tetraedro::getValido(){
	return this->valido;
}

void Tetraedro::setTecla(unsigned char nuevaTecla){
	this->tecla = nuevaTecla;
}
unsigned char Tetraedro::getTecla(){
	return this->tecla;
}

void Tetraedro::dibuja(){
	if(valido) Objeto3D::dibuja();
}