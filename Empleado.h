#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <bits/stdc++.h>
#include <string>
#include "Tarea.h"
#include <iostream>

using namespace std;

//Los empleados tienen un nombre, edad, nivel (bajo, medio o alto), porcentaje de habilidad,
// y porcentaje de pereza.El nivel puede ser 1, 2 o 3 (siendo bajo, medio o alto respectivamente). Losporcentajes seránun numero entre 1 y 100.

class Empleado
{
	public:
		Empleado();
		//constructor sobrecargado
		Empleado (string,int ,int ,int ,int);
		
		//Mutadores
		//sets
		void setNombre( string );
		void setEdad(int );
		void setNivel(int );
		void setPor_habilidad( int);
		void setPor_pereza( int );
		void setTarea(Tarea*);
		//geters
		string getNombre();
		int getNivel();
		int getPor_habilidad();
		int getPor_pereza();
		Tarea* getTarea();
		
		 
		
	
		~Empleado();
	protected:
		
	private :
		string nombre;
		int edad ;
		int nivel ;
		int por_habilidad;
		int por_pereza;
		Tarea* tarea=NULL;
		
		
};

#endif
