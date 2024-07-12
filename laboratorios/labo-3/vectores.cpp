#include "vectores.h"

// Función para probar en main.cpp si este módulo fue cargado correctamente
void holaModuloVectores(){
    cout << "El módulo vectores fue cargado correctamente" << endl;
}


//Ejercicio
bool divide(vector<int> v, int a){
	// Dados un vector v y un int a, decide si a divide a todos los numeros de v.
	bool res=true;
	for(int i=0; i<v.size() && res; i++){
		if(v[i] % a != 0) {
			res=false;
		}
	}
	return res;
}

//Ejercicio
int mayor(vector<int> v){
	// Dado un vector v, devuelve el valor maximo encontrado.
	int max=v[0];
	for(int i=0; i<v.size(); i++){
		if(max<v[i]){
			max=v[i];
		}
	}
	return max;
}

//Ejercicio
vector<int> reverso(vector<int> v){
	// Dado un vector v, devuelve el reverso.
	vector<int> res;
	for(int i=v.size()-1; i>=0; i--){
		res.push_back(v[i]);
	}
	return res;
}

//Ejercicio
vector<int> rotar(vector<int> v, int k){
	// Dado un vector v y un entero k, rotar k posiciones los elementos de v.
	// [1,2,3,4,5,6] rotado 2, deberia dar [3,4,5,6,1,2].
	vector<int> res;
	for(int i=k; i<v.size(); i++){
		res.push_back(v[i]);
	}
	for(int i=0; i<k; i++){
		res.push_back(v[i]);
	}
	return res;
}

//Ejercicio
bool esPrimo(int n){
	bool res=true;
	for(int i=2; i<n && res; i++){
		if(n % i == 0){
			res=false;
		}
	}
	return res;
}

vector<int> factoresPrimos(int n){
	//que dado un entero devuelve un vector con los factores primos del mismo
	vector<int> res;
	for(int i=2; i<n; i++){
		if(esPrimo(i) && (n % i == 0)){
			res.push_back(i);
		}
	}
	return res;
}

//Ejercicio
void mostrarVector(vector<int> v){
	//que dado un vector de enteros muestra por la salida estándar, el vector
	// Ejemplo: si el vector es <1, 2, 5, 65> se debe mostrar en pantalla [1, 2, 5, 65]
	/*
	if(v.size()==0){
		cout << "[v[0]]" << endl;
	} else {
		for(int i=0; i<v.size()-1; i++){
			cout << "[v[i], " << endl;
		}
		cout << "v[v.size()-1]]" << endl;
	}
	*/
}
