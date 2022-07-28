#include <iostream>
#include <stdlib.h>
#include <string>
#define tam 3

/*
	else
	
	
*/

using namespace std;

struct nodo {
	nodo *ant;
	string cadena;
	int nota;
	nodo *sig;	
};

void eliminarMateria(nodo estudiante[], string nombre, string materia) {
	for (int i = 0; i < tam; i++) {
		if (estudiante[i].cadena == nombre) {
			nodo *aux;
			nodo *ant = NULL;
			aux = estudiante[i].sig;
			while (aux != NULL && aux->cadena != materia) {
				ant = aux;
				aux = aux->sig;
			}
			if (aux == NULL) {
				cout << "El elemento no existe...\n";
			} else if (ant == NULL) {
				estudiante[i].sig = aux->sig;
				delete aux;
			} else {
				ant->sig = aux->sig;
				delete aux;
			}
		}
	}
}

double promedio(nodo estudiante[], string nombre) {
	double total;
	int contador=0;
	for (int i = 0; i < tam; i++) {
		if (estudiante[i].cadena == nombre) {
			nodo *aux = estudiante[i].sig;
			nodo *aux2;
			while (aux != NULL) {
				aux2 = aux;
				total += aux->nota;
				contador++;
				aux = aux->sig;
			} 
		}
	}
	total /=contador;
	return total;
}

void crearEstudiante(nodo estudiante[], string nombre) {
	int i=0;
	for (i; i < tam; i++) {
		if (estudiante[i].cadena == "") {
			estudiante[i].cadena = nombre;
			estudiante[i].sig = NULL;
			i = 4;
		} 
	}
}

void mostrarLista(nodo estudiante[], string nombre) {
	bool encontrado = false;
	for (int i = 0; i < tam; i++) {
		if (estudiante[i].cadena == nombre) {
			encontrado = true;
			cout << " Estudiante: ";
			cout << estudiante[i].cadena;
			cout << "\n Materia-Nota: ";
			nodo *aux = estudiante[i].sig;
			nodo *aux2;
			while (aux != NULL) {
				aux2 = aux;
				cout << aux->cadena << " - " << aux->nota << " | ";
				aux = aux->sig;
			} 
			cout << "\n";
		} 
	}
	if (!encontrado) {
		cout << "No hay registros con este nombre...\n";
	}
}

void agregarMateria(nodo estudiante[], string nombre, string materia, int nota) {
	nodo *nuevo = new nodo();
	nuevo->cadena = materia;
	nuevo->nota = nota;
	for (int i=0; i < tam; i++) {
		if (estudiante[i].cadena == nombre) {
			nodo *aux = &estudiante[i];
			nodo *aux2;
			while (aux != NULL) {
				aux2 = aux;
				aux = aux->sig;
			}
			if (&estudiante[i] == aux) {
				estudiante[i].sig = nuevo;
			} else {
				aux2->sig = nuevo;
			}
			nuevo->sig = aux;
		}
	}
}

void cargarDatos(nodo estudiante[]) {
	crearEstudiante(estudiante, "Juan");
	crearEstudiante(estudiante, "Mateo");
	crearEstudiante(estudiante, "Pepe");
	crearEstudiante(estudiante, "Nico");
	agregarMateria(estudiante, "Juan", "Biologia", 10);
	agregarMateria(estudiante, "Juan", "Matematicas", 50);
	agregarMateria(estudiante, "Juan", "Quimica", 45);
	agregarMateria(estudiante, "Mateo", "Biologia", 15);
	agregarMateria(estudiante, "Mateo", "Carpinteria", 35);
	agregarMateria(estudiante, "Pepe", "Biologia", 20);
	agregarMateria(estudiante, "Pepe", "Filosofia", 40);
	agregarMateria(estudiante, "Nico", "Biologia", 20);
	agregarMateria(estudiante, "Nico", "Etica", 30);
}

int main() {
	int opc, nota;
	string nombre, materia;
	nodo estudiante[tam];
	do {
		cout << "\n....::MENU::....\n";
		cout << "1) Crear estudiante.\n";		
		cout << "2) Agregar materia.\n";		
		cout << "3) Eliminar materia.\n";		
		cout << "4) Listar un alumno.\n";		
		cout << "5) Obtener promedio alumno.\n";		
		cout << "6) Cargar datos.\n";
		cout << "9) Salir.\n";
		cout << "Digite opcion: \n";
		cin >> opc;
		switch (opc) {
			case 1: {
				cout << "Ingrese el nombre del estudiante: ";
				cin >> nombre;
				crearEstudiante(estudiante, nombre);
				break;
			}
			case 2: {
				cout << "Ingrese el nombre del estudiante al que se le agregara la materia: \n";
				cin >> nombre;
				cout << "Ingrese el nombre de la materia: \n";
				cin >> materia;
				cout << "Ingrese la nota de la materia: \n";
				cin >> nota;
				agregarMateria(estudiante, nombre, materia, nota);
				break;
			}
			case 3: {
				cout << "Ingrese el nombre del estudiante: ";
				cin >> nombre;
				cout << "Ingrese el nombre de la materia: ";
				cin >> materia;
				eliminarMateria(estudiante, nombre, materia);
				break;
			}
			case 4: {
				cout << "Ingrese el nombre del estudiante: ";
				cin >> nombre;
				cout << "\n";
				mostrarLista(estudiante, nombre);
				break;
			}
			case 5: {
				cout << "Ingrese el nombre del estudiante: ";
				cin >> nombre;
				cout << "\nEl promedio de notas de " << nombre << " es: " << promedio(estudiante, nombre);
				break;
			}
			case 6: {
				cout << "Datos cargados...\n";
				cargarDatos(estudiante);
				break;
			}
			case 9: {
				
				break;
			}
		}
	} while (opc != 9);
}


