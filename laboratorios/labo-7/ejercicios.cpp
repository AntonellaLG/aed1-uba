#include "ejercicios.h"

//////// Ejercicio 1 ////////////////
vector<vector<int> > productoVectorial(vector<int> u, vector<int> v){
	vector<vector<int>> res;
	for(int i=0; i<u.size(); i++) {
	    vector<int> fila; 
	    for (int j=0; j<v.size(); j++) {
	        fila.push_back(u[i]*v[j]);
	    }
	    res.push_back(fila);
	}
	return res;
}

//////// Ejercicio 2 ////////////////
void trasponer(vector<vector<int> > &m) {
	vector<vector<int>> m1=m;
	for(int i=0; i<m.size(); i++) {
	    for (int j=0; j<m.size(); j++) {
	        m[i][j]=m1[j][i];
	    }
	}
	return;
}

//////// Ejercicio 3 ////////////////
vector<vector<int> > multiplicar(vector<vector<int> > m1, vector<vector<int> > m2){
	vector<vector<int>> res;
	for(int i=0; i<m1.size(); i++) {
	    vector<int> fila; 
	    for (int j=0; j<m2[0].size(); j++) {
	        int v=0;
	        for (int k=0; k<m2.size(); k++) {
	            v+=m1[i][k]*m2[k][j];
	        }
	        fila.push_back(v);
	    }
	    res.push_back(fila);
	}
	return res;
}

//////// Ejercicio 4 ////////////////
vector<vector<int> > promediar(vector<vector<int> > m){
	//COMPLETAR
	vector<vector<int> > res;
	return res;
}

//////// Ejercicio 5 ////////////////
int contarPicos(vector<vector<int> > m){
	//COMPLETAR
	return true;
}

//////// Ejercicio 6 ////////////////
bool esTriangularSuperior(vector<vector<int> > m){ 
    bool res=true;
	for(int i=0; i<m.size(); i++) {        //No se como separar los for en dos casos aparte y que no necesariamente pase por ambos si es 
	    for(int j=0; j<i; j++) {           // que quiero dejar los dos for en un solo programa
	        res=res&&m[i][j]==0;
	    }
	}
	return res;
}
	
bool esTriangularInferior(vector<vector<int> > m){ 	
	bool res=true;
	for(int i=0; i<m.size(); i++) {
	    for(int j=m.size()-1; j>i; j--) {
	        res=res&&m[i][j]==0;
	    }
	}
	return res;
}

bool esTriangular(vector<vector<int> > m){   
	bool res=false;
	if (esTriangularSuperior(m)==true || esTriangularInferior(m)==true) {
	    res=true;
	}
	return res;
}	

//////// Ejercicio 7 ////////////////
bool hayAmenaza(vector<vector<int> > m){
	//COMPLETAR
	return true;
}

//////// Ejercicio 8 ////////////////
int diferenciaDiagonales(vector<vector<int> > m) {
    //COMPLETAR
    return 0;
}