#include "ejercicios.h"

/* Para compilar */ 

using namespace std;

vector<string> split(string s, char delim){
	vector<string> v;
	return v;
}

string darVueltaPalabra(string s){
	string res;
	return res;
}

// Decidir si s1 es substring o subsecuencia de s2
bool subsecuencia(string s1, string s2) {
	int i=0; //ASSERT_TRUE(subsecuencia("asd", "juasdop"))
	int j=0;
	while(i<s1.size() && j<s2.size()){
		if(s1[i]==s2[j]){
			j++;
		}
		i++
	}
	return i==s1.size();
}


int cantidadApariciones(string s, char e) {
    int res=0;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == e){
			res++;
		}
    }
    return res;
}

bool esAnagrama(string s1, string s2) {
	bool res=true
    for(int i=0; i<s1.size() && res; i++){
        res = cantidadApariciones(s1, s1[i]) == cantidadApariciones(s2, s1[i]);
    }
    return res;
}

// Mismo orden relativo de conjunto de anagramas y dentro de cada vector y con repetidos
vector<vector<string> > agruparAnagramas(vector<string> v){
	vector<vector<string> > res;
	int i=0;
	while(i<v.size()){
		int j=i+1;
		while(j<v.size() && !esAnagrama(v[j], v[i])){
			j++;
		}
		if(j<v.size()){
			res[i].push_back(v[i]);
		} else {
			res.push_back({v[i]});
		}
		i++;
	}
	return res;
}

bool esPalindromo(string s){
	bool cumple = true;
	for(int i=0; i<s.size() && cumple; i++){
		cumple = s[i]==s[s.size()-1-i];
	}
	return cumple;
}

bool tieneRepetidos(string s){
	bool repetido = false;
	for(int i=0; i<s.size()-1; i++){
		for(int j=i+1; j<s.size() && !repetido; j++){
			if(s[i]==s[j]){
				repetido=true;
			}
		}
	}
	return repetido;
}

string rotar(string s, int j){ 
	string res(s);			  
	for(int i=0; i<s.size(); i++){
		res[i] = s[(s.size() + i - (j % s.size())) % s.size()];
	}
	return res;
}

// no se puede usar substring
string darVueltaK(string s, int k){
	string res(s);
	return res;
}

string abueloLaino(string s){
    string res="S";
	for(int j=0; j<s.size(); j++){
		if(s[j]=='i'){
			res="N";
	}
    return res;
	}
}

int cantidadDeFelicitaciones(vector<string> v){
    int res;
    return res;
}

int middleOut(string s, string t){
    return 0;
}
