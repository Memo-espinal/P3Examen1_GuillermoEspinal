#ifndef TAREA_H
#define TAREA_H
#include <bits/stdc++.h>
#include <string>

using namespace std;

//Las tareas tienen una descripci�n, nivel (bajo, medio o alto)ycarga de tarea.
//El nivel puede ser 1, 2 o 3 (siendo bajo, medio o alto respectivamente). La carga de tarea es el n�mero de d�as que tomar� la tarea en completarse.

class Tarea
{
	public:
		Tarea();
		
		Tarea(int ,string ,int );
		//sets
		void setNivelTarea(int);
		void setCarga(int);
		//gets
		int getCarga();
		int getNivelTarea();
		string getDescrip();
		
		
		~Tarea();
	protected:
	private :
		string descrip;
		int nivel_tarea ;
		int carga ;
		
};

#endif
