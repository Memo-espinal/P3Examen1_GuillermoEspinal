#include "Empleado.h"
#include <bits/stdc++.h>
#include <string>
#include <iostream>

using namespace std;

Empleado::Empleado()
{
}

Empleado::Empleado(string name,int age,int level ,int habilidad ,int pereza){
		nombre = name;
		edad = age;
		setNivel(level);
		setPor_habilidad(habilidad);
		setPor_pereza(pereza);
		
}

void Empleado :: setNombre( string name ){
	this->nombre = name;
}
void Empleado:: setEdad(int age ){
	this->edad = age;
}
void Empleado::setNivel(int level){
	while (level >3||level<=0){
		cout <<"Ingrese el nivel que sea de 1 a 3"<< endl;
		cin >>level;
	}
	this->nivel = level;
	
}
void Empleado :: setPor_habilidad( int habilidad){
	while(habilidad>100||habilidad<=0){
		cout << "Ingrese el porcentaje de habilida que este entre 1 a 100 : "<< endl;
		cin>> habilidad;
	}
	this->por_habilidad= habilidad;
	
}
void Empleado :: setPor_pereza( int pereza ){
	while(pereza>100||pereza<=0){
		cout << "Ingrese el porcentaje de habilida que este entre 1 a 100 : "<< endl;
		cin>> pereza;
	}
	this->por_pereza=pereza;
}
void Empleado :: setTarea(Tarea* tareaim){
	tarea=tareaim;
}
//geters
string Empleado :: getNombre(){
	return nombre;
}
int Empleado :: getNivel(){
	return nivel ;
	
}
int Empleado :: getPor_habilidad(){
	return por_habilidad;
}
int Empleado :: getPor_pereza(){
	return por_pereza;
}
Tarea* Empleado :: getTarea(){
	return tarea;
}

Empleado::~Empleado()
{
	delete tarea;
}
