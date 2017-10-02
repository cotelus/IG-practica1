/*
 * Luis Ángel Cotelo Leyva 
 * cotelus@correo.ugr.es
 */

#ifdef _WIN32
#include <windows.h>
#endif
#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "escena.h"
#include "tetraedro.h"
#include <vector>
#include "cubo.h"
#include "octaedro.h"

Escena::Escena(){
    Front_plane=50;
    Back_plane=2000;
    Observer_distance = 4*Front_plane;
    Observer_angle_x = Observer_angle_y=0;
    ejes.changeAxisSize(5000);

    // Podria inicializar los objetos como en los apuntes o con la funcion push_back
    // pero he decidido ponerlo así porque es mas visible, al menos para mi

    // INICIALIZACION DEL OBJETO TETRAEDRO
    // Vector de vertices, caras y colores del tetraedro
    std::vector<int> carasTetraedro(12, 0);
    std::vector<float> verticesTetraedro(12, 0);
    // El color de cada vertice
    std::vector<float> coloresTetraedro(12,0);

    verticesTetraedro[0] = 0.0;
    verticesTetraedro[1] = 100.0;
    verticesTetraedro[2] = 0.0;
    verticesTetraedro[3] = 0.0;
    verticesTetraedro[4] = 0.0;
    verticesTetraedro[5] = 100.0;
    verticesTetraedro[6] = 100.0;
    verticesTetraedro[7] = 0.0;
    verticesTetraedro[8] = -50.0;
    verticesTetraedro[9] = -100.0;
    verticesTetraedro[10] = 0.0;
    verticesTetraedro[11] = -50.0;

    carasTetraedro[0] = 1;
    carasTetraedro[1] = 2;
    carasTetraedro[2] = 0;
    carasTetraedro[3] = 3;
    carasTetraedro[4] = 1;
    carasTetraedro[5] = 0;
    carasTetraedro[6] = 2;
    carasTetraedro[7] = 3;
    carasTetraedro[8] = 0;
    carasTetraedro[9] = 3;
    carasTetraedro[10] = 2;
    carasTetraedro[11] = 1;

    coloresTetraedro[0] = 255;
    coloresTetraedro[1] = 0;
    coloresTetraedro[2] = 0;
    coloresTetraedro[3] = 255;
    coloresTetraedro[4] = 0;
    coloresTetraedro[5] = 0;
    coloresTetraedro[6] = 255;
    coloresTetraedro[7] = 0;
    coloresTetraedro[8] = 0;
    coloresTetraedro[9] = 255;
    coloresTetraedro[10] = 0;
    coloresTetraedro[11] = 0;

    miTetraedro = new Tetraedro(carasTetraedro, verticesTetraedro, coloresTetraedro);


    // INICIALIZACION DEL OBJETO CUBO
    // Vector de vertices, caras y colores del cubo
    std::vector<int> carasCubo(36, 0);
    std::vector<float> verticesCubo(24, 0);
    // El color de cada vertice
    std::vector<float> coloresCubo(24,0);

    verticesCubo[0] = -50.0;	
    verticesCubo[1] = -50.0;
    verticesCubo[2] = 50.0;
    verticesCubo[3] = 50.0;
    verticesCubo[4] = -50.0;
    verticesCubo[5] = 50.0;
    verticesCubo[6] = 50.0;
    verticesCubo[7] = -50.0;
    verticesCubo[8] = -50.0;
    verticesCubo[9] = -50.0;
    verticesCubo[10] = -50.0;
    verticesCubo[11] = -50.0;
    verticesCubo[12] = -50.0;
    verticesCubo[13] = 50.0;
    verticesCubo[14] = 50.0;
    verticesCubo[15] = 50.0;
    verticesCubo[16] = 50.0;
    verticesCubo[17] = 50.0;
    verticesCubo[18] = 50.0;
    verticesCubo[19] = 50.0;
    verticesCubo[20] = -50.0;
    verticesCubo[21] = -50.0;
    verticesCubo[22] = 50.0;
    verticesCubo[23] = -50.0;

    carasCubo[0] = 0;
    carasCubo[1] = 1;
    carasCubo[2] = 5;
    carasCubo[3] = 5;
    carasCubo[4] = 4;
    carasCubo[5] = 0;
    carasCubo[6] = 1;
    carasCubo[7] = 2;
    carasCubo[8] = 6;
    carasCubo[9] = 6;
    carasCubo[10] = 5;
    carasCubo[11] = 1;
    carasCubo[12] = 2;
    carasCubo[13] = 3;
    carasCubo[14] = 7;
    carasCubo[15] = 7;
    carasCubo[16] = 6;
    carasCubo[17] = 2;
    carasCubo[18] = 3;
    carasCubo[19] = 0;
    carasCubo[20] = 4;
    carasCubo[21] = 4;
    carasCubo[22] = 7;
    carasCubo[23] = 3;
    carasCubo[24] = 7;
    carasCubo[25] = 4;
    carasCubo[26] = 5;
    carasCubo[27] = 5;
    carasCubo[28] = 6;
    carasCubo[29] = 7;
    carasCubo[30] = 2;
    carasCubo[31] = 1;
    carasCubo[32] = 0; 
    carasCubo[33] = 0; 
    carasCubo[34] = 3;
    carasCubo[35] = 2;


    coloresCubo[0] = 255;
    coloresCubo[1] = 0;
    coloresCubo[2] = 0;
    coloresCubo[3] = 255;
    coloresCubo[4] = 0;
    coloresCubo[5] = 0;
    coloresCubo[6] = 255;
    coloresCubo[7] = 0;
    coloresCubo[8] = 0;
    coloresCubo[9] = 255;
    coloresCubo[10] = 0;
    coloresCubo[11] = 0;
    coloresCubo[12] = 255;
    coloresCubo[13] = 0;
    coloresCubo[14] = 0;
    coloresCubo[15] = 255;
    coloresCubo[16] = 0;
    coloresCubo[17] = 0;
    coloresCubo[18] = 255;
    coloresCubo[19] = 0;
    coloresCubo[20] = 0;
    coloresCubo[21] = 255;
    coloresCubo[22] = 0;
    coloresCubo[23] = 0;
    
    miCubo = new Cubo(carasCubo, verticesCubo, coloresCubo);

    //Se desactiva la vista de miCubo y miTetraedro, para que se pueda elegir cuando se lance el programa
    miCubo->setValido(false);
    miTetraedro->setValido(false);


    // OBJETO EXTRA //
    // INICIALIZACION DEL OBJETO OCTAEDRO
    // Vector de vertices, caras y colores del octaedro
    std::vector<int> carasOctaedro(24, 0);
    std::vector<float> verticesOctaedro(18, 0);
    // El color de cada vertice
    std::vector<float> coloresOctaedro(18,0);

    verticesOctaedro[0] = -50.0;
    verticesOctaedro[1] = 0.0;
    verticesOctaedro[2] = 50.0;
    verticesOctaedro[3] = 50.0;
    verticesOctaedro[4] = 0.0;
    verticesOctaedro[5] = 50.0;
    verticesOctaedro[6] = 50.0;
    verticesOctaedro[7] = 0.0;
    verticesOctaedro[8] = -50.0;
    verticesOctaedro[9] = -50.0;
    verticesOctaedro[10] = 0.0;
    verticesOctaedro[11] = -50.0;
    verticesOctaedro[12] = 0;
    verticesOctaedro[13] = -100.0;
    verticesOctaedro[14] = 0;
    verticesOctaedro[15] = 0;
    verticesOctaedro[16] = 100.0;
    verticesOctaedro[17] = 0;

    carasOctaedro[0] = 0;
    carasOctaedro[1] = 4;
    carasOctaedro[2] = 1;
    carasOctaedro[3] = 1;
    carasOctaedro[4] = 4;
    carasOctaedro[5] = 2;
    carasOctaedro[6] = 2;
    carasOctaedro[7] = 4;
    carasOctaedro[8] = 3;
    carasOctaedro[9] = 3;
    carasOctaedro[10] = 4;
    carasOctaedro[11] = 0;
    carasOctaedro[12] = 1;
    carasOctaedro[13] = 2;
    carasOctaedro[14] = 5;
    carasOctaedro[15] = 2;
    carasOctaedro[16] = 3;
    carasOctaedro[17] = 5;
    carasOctaedro[18] = 3;
    carasOctaedro[19] = 0;
    carasOctaedro[20] = 5;
    carasOctaedro[21] = 0;
    carasOctaedro[22] = 1;
    carasOctaedro[23] = 5;

    coloresOctaedro[0] = 255;
    coloresOctaedro[1] = 0;
    coloresOctaedro[2] = 0;
    coloresOctaedro[3] = 255;
    coloresOctaedro[4] = 0;
    coloresOctaedro[5] = 0;
    coloresOctaedro[6] = 255;
    coloresOctaedro[7] = 0;
    coloresOctaedro[8] = 0;
    coloresOctaedro[9] = 255;
    coloresOctaedro[10] = 0;
    coloresOctaedro[11] = 0;
    coloresOctaedro[12] = 255;
    coloresOctaedro[13] = 0;
    coloresOctaedro[14] = 0;
    coloresOctaedro[15] = 255;
    coloresOctaedro[16] = 0;
    coloresOctaedro[17] = 0;

    miOctaedro = new Octaedro(carasOctaedro, verticesOctaedro, coloresOctaedro);

    miOctaedro->setValido(false);
}

void Escena::inicializar(int UI_window_width,int UI_window_height) {

	glClearColor(1,1,1,1);// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable(GL_DEPTH_TEST);	// se habilita el z-bufer

	this->change_projection();
	Width=UI_window_width/10;
	Height=UI_window_height/10;
	glViewport(0,0,UI_window_width,UI_window_height);

}


//**************************************************************************
// Funcion que dibuja objetos en la escena
//***************************************************************************
// LLama a la funcion dibujar de los dos objetos creados
void Escena::draw_objects() {
	this->miCubo->dibuja();
	this->miTetraedro->dibuja();
	this->miOctaedro->dibuja();
}



void Escena::dibujar() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();
	draw_axis();
	draw_objects();
}


int Escena::teclaPulsada(unsigned char Tecla1,int x,int y) {

    std::cout << "Tecla" << Tecla1<< std::endl;
	if (toupper(Tecla1)=='Q'){
		return 1;
	}
	else{
		switch(toupper(Tecla1)){
			case 'P': 
				miCubo->setTecla('P');
				miTetraedro->setTecla('P');
				miOctaedro->setTecla('P');
				dibujar();
				return 0;
			case 'L': 
				miCubo->setTecla('L');
				miTetraedro->setTecla('L');
				miOctaedro->setTecla('L');
				dibujar();
				return 0;
			case 'F': 
				miCubo->setTecla('F');
				miTetraedro->setTecla('F');
				miOctaedro->setTecla('F');
				dibujar();
				return 0;
			case 'C': 
				miCubo->setTecla('C');
				miTetraedro->setTecla('C');
				miOctaedro->setTecla('C');
				dibujar();
				return 0;
			case '1': 
				miCubo->setValido(false);
				miTetraedro->setValido(true);
				miOctaedro->setValido(false);
				miTetraedro->setTecla('P');
				dibujar();
				return 0;
			case '2': 
				miCubo->setValido(true);
				miTetraedro->setValido(false);
				miOctaedro->setValido(false);
				miCubo->setTecla('P');
				dibujar();
				return 0;
			case '3': 
				miCubo->setValido(false);
				miTetraedro->setValido(false);
				miOctaedro->setValido(true);
				miOctaedro->setTecla('P');
				dibujar();
				return 0;
			default: return 0;
		}
	}
}

void Escena::teclaEspecial(int Tecla1,int x,int y) {
switch (Tecla1){
	case GLUT_KEY_LEFT:Observer_angle_y--;break;
	case GLUT_KEY_RIGHT:Observer_angle_y++;break;
	case GLUT_KEY_UP:Observer_angle_x--;break;
	case GLUT_KEY_DOWN:Observer_angle_x++;break;
	case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
	case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
	}

	std::cout << Observer_distance << std::endl;
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void Escena::change_projection()  {
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFrustum(-Width,Width,-Height,Height,Front_plane,Back_plane);
}


void Escena::redimensionar(int newWidth,int newHeight) {
change_projection();
Width=newWidth/10;
Height=newHeight/10;
glViewport(0,0,newWidth,newHeight);
}


//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************



void Escena::change_observer() {

// posicion del observador
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0,0,-Observer_distance);
glRotatef(Observer_angle_x,1,0,0);
glRotatef(Observer_angle_y,0,1,0);
}


//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void Escena::draw_axis()
{
ejes.draw();
}




