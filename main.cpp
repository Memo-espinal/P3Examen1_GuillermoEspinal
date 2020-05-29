#include <iostream>
#include <vector>
#include "Empleado.h"
#include "Tarea.h"
#include <bits/stdc++.h>
#include <string>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//Los empleados tienen un nombre, edad, nivel (bajo, medio o alto), porcentaje de habilidad,
// y porcentaje de pereza.El nivel puede ser 1, 2 o 3 (siendo bajo, medio o alto respectivamente). Losporcentajes seránun numero entre 1 y 100.

int main(int argc, char** argv) {
	int resp = 0;
	vector<Empleado*>vempleados;
	vector<Tarea*>vbacklog;
	while (resp!=7){
		cout << "1.Contratar empleado"<<endl;
		cout << "2.Despedir empleado"<<endl;
		cout << "3.Listar empleados"<<endl;
		cout << "4.Crear tarea"<<endl;
		cout << "5.Listar tareas"<<endl;
		cout << "6.Iniciar proyecto"<<endl;
		cout << "7.Salir"<<endl;
		cin >> resp ;
		switch (resp){
			case 1 : {
				string nombre;
				int edad,nivel,por_habilidad,por_pereza;
				cout <<"Ingreese el nombre del empleado:"<< endl;
				cin>>nombre;
				cout<< "Ingrese la edad del empleado: "<< endl;
				cin>> edad;
				cout<<"INgrese el nivel del empleado(de 1 a 3): "<< endl;
				cin>> nivel;
				cout<<"INgrese el porcentaje de habilidad(de 1 a 100): "<< endl;
				cin>>por_habilidad;
				cout<<"INgrese el porcantaje de pereza(de 1 a 100): "<< endl;
				cin>> por_pereza;
				Empleado* nuevo = new Empleado(nombre,edad,nivel,por_habilidad,por_pereza);
				vempleados.push_back(nuevo);
				cout<<"empleado creado!";
				
				break;
			}
			case 2 :{
				int indice;
				for (int i =0 ;i<vempleados.size();i++){
					cout<< i<<".- "<<vempleados[i]->getNombre()<<endl;
				}
				cout<<"A quien quiere despedir ?"<<endl;
				cin>>indice;
				vempleados.erase(vempleados.begin()+indice);
				cout<< "Felicidades es usted un Mounstro :)"<< endl;
				
				break;
			}
			case 3 :{
				for (int i =0 ;i<vempleados.size();i++){
					cout<< i<<".- "<<vempleados[i]->getNombre()<<endl;
				}
				
				break;
			}
			case 4 :{
				int nivel,carga;
				string descrip;
				
				cout<<"Ingrese la descripcion de la tarea: "<<endl;
				cin>>descrip;
				cout<< "Ingrese la carga de la tarea: "<< endl;
				cin>> carga;
				cout << "Ingrese el nivel de la tarea"<< endl;
				cin>> nivel;
				
				Tarea* task = new Tarea(nivel,descrip,carga);
				vbacklog.push_back(task);
				
				break;
			}
			case 5 :{
				for (int i =0 ;i<vbacklog.size();i++){
					cout<< i<<".- "<<vbacklog[i]->getDescrip()<<endl;
			}
				break;
			}
			case 6 :{
				
				break;
			}
			case 7 :{
				
				break;
			}
			default :{
				
				break;
			}
		}
	}
	return 0;
}
