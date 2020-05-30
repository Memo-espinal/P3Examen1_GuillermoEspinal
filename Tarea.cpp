#include "Tarea.h"
#include <bits/stdc++.h>
#include <string>
#include <iostream>

using namespace std;

Tarea::Tarea()
{
}

Tarea:: Tarea(int level_tarea,string descripdada,int cargadada){
	descrip=descripdada;
	setNivelTarea(level_tarea);
	carga=cargadada;;
}
		//sets
	void Tarea:: setNivelTarea(int level){
		while (level >3||level<=0){
		cout <<"Ingrese el nivel que sea de 1 a 3"<< endl;
		cin >>level;
		}
	this->nivel_tarea = level;
	}
	void Tarea:: setCarga(int cargadada ){
		this->carga=cargadada;
	}
//	void Tarea::setEmpleado(Empleado* encargado){
//		this->empleado = encargado;
//	}
		//gets
	int Tarea:: getCarga(){
		return carga;
	}
	int Tarea:: getNivelTarea(){
		return nivel_tarea;
	}
	string Tarea:: getDescrip(){
		return descrip;
	}
//	Empleado* Tarea::getEmpleado(){
//		return encargado;
//	}
	

Tarea::~Tarea()
{
}
