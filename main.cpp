#include <iostream>
#include <vector>
#include "Empleado.h"
#include "Tarea.h"
#include <bits/stdc++.h>
#include <string>
#include <stdlib.h> 
#include <time.h>


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
				cout<<"INgrese el porcentaje de pereza(de 1 a 100): "<< endl;
				cin>> por_pereza;
				Empleado* nuevo = new Empleado(nombre,edad,nivel,por_habilidad,por_pereza);
				vempleados.push_back(nuevo);
				cout<<"empleado creado!"<<endl;
				
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
					cout<< i<<".- "<<vbacklog[i]->getDescrip()<< " Carga : "<< vbacklog[i]->getCarga()<<endl;
			}
				break;
			}
			case 6 :{
				//sumatoria del proyecto
				int acum=0;
				for (int i =0 ;i<vbacklog.size();i++){
					acum+= vbacklog[i]->getCarga();
					//cout<< acum << " ";
					
				}
				//cout<< "acum es :"<<acum<< endl;
				acum+=acum*0.20;
				vector <Empleado*> trabajando;
				
				
				// la repeticion de los dias 
				do{
					int choose;
					cout<< "Dias para terminar el proyecto :->"<< acum<< endl;
					cout<<"--------------------------------------"<< endl;
					cout<<"1.- Siguiente dia "<<endl;
					cout<<"2.- Generar Reporte"<<endl;
					cout<<"3.- Salir"<<endl;
				 	cin >>choose;
				
				 	int perezosos,trabajadores,nolograron;
				 	switch (choose){
				 		case 1 :{
				 			perezosos=0;
				 			trabajadores=0;
				 			nolograron=0;
				 			if (trabajando.size()==0|| trabajando.size()<=vempleados.size()){
				 				for (int i = 0 ; i<vbacklog.size();i++){
				 					for (int j = 0 ; j<vempleados.size();j++){
				 						if(vempleados[j]->getTarea()==NULL){
				 							if ( vempleados[j]->getNivel() >= vbacklog[i]->getNivelTarea() ){
				 								vempleados[j]->setTarea(vbacklog[i]);
											 	cout<< "se le dio tarea a "<< vempleados[j]->getNombre()<<endl;
											 	trabajando.push_back(vempleados[j]);
											 	vbacklog.erase(vbacklog.begin()+i);
											 	break;
										 	}
									 	}//fin de los if
									 
								 	}//fin del for de j
								 
								 
							 	}//fin del for de i
							 }
							 	Tarea* tarea = NULL;
							 for(int i = 0 ; i<trabajando.size();i++){
							 	int pereza,habilidad;
					 			srand(time(NULL));
					 			pereza = rand()%101;
					 			if (trabajando[i]->getPor_pereza()<pereza){
					 				habilidad = rand()%101;
					 				 if (trabajando[i]->getPor_habilidad()>=habilidad){
					 				 	//vijia esta pasada weon
					 				    tarea = trabajando[i]->getTarea();
					 				    if(tarea->getCarga()<=0){
					 				    	trabajando.erase(trabajando.begin()+i);
					 				    	//backlog.erase
										 }else{
										 	tarea->setCarga(tarea->getCarga()-1);//((trabajando[i]->getTarea()->getCarga())-1);
										 	trabajadores++;
										 }
					 				 	
									  }else{
									  	nolograron++;
									  }
				 				
								 }else{
								 	perezosos++;
								 }
							 
							 }
							
				 		
				 			
				 			
						acum--;
						break;
						}
						case 2:{
							cout<<"Tareas en blacklog : "<<vbacklog.size()<<endl;//-trabajando.size() << endl;
							cout<<"Tareas en Progresso : "<<trabajando.size()<< endl;
							cout<<"Empleados Perezosos:  "<<perezosos<< endl;
							cout<<"Empleados que fallaron: "<<nolograron<< endl;
							cout<<"Empleados que lograron el dia: "<<trabajadores<< endl;							
							break;
						}
						default:{
							for(int i =0;i<vbacklog.size();i++){
								delete vbacklog[i];
								vbacklog[i]=NULL;
								
							}
							for (int i = 0 ; i<trabajando.size();i++){
								delete trabajando[i];
								trabajando[i]=NULL;
							}
							
							
							break;
						}
					 }
					 //do while para que entre almenos una vez
				}while (vbacklog.size()>=0&&trabajando.size()!=0);
			
				
			
				
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
	//FInalizacion del programa y liberacion de memoria
	for(int i =0;i<vempleados.size();i++){
		delete vempleados[i];
		vempleados[i]=NULL;
		
	}
	for(int i =0;i<vbacklog.size();i++){
		delete vbacklog[i];
		vbacklog[i]=NULL;
		
	}
	return 0;
}
