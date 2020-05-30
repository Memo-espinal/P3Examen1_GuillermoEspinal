#ifndef TAREA_H
#define TAREA_H
#include <bits/stdc++.h>
#include <string>
//#include "Empleado.h"

using namespace std;

//Las tareas tienen una descripción, nivel (bajo, medio o alto)ycarga de tarea.
//El nivel puede ser 1, 2 o 3 (siendo bajo, medio o alto respectivamente). La carga de tarea es el número de días que tomará la tarea en completarse.

class Tarea
{
	public:
		Tarea();
		
		Tarea(int ,string ,int );
		//sets
		void setNivelTarea(int);
		void setCarga(int);
		
		//void setEmpleado(Empleado*);
		//gets
		int getCarga();
		int getNivelTarea();
		string getDescrip();
		//Empleado* getEmpleado();
		
		
		~Tarea();
	protected:
	private :
		string descrip;
		int nivel_tarea ;
		int carga ;
		//Empleado* empleado=NULL;
		
};

#endif
