#include "ejercicios.h"


// Ejercicio 1
bool existePico(vector<int> v){
    bool r=false;
    int i=1;
    int j=-1;
    while (i <= v.size()-2) {
        if (v[i]>v[i-1] && v[i]>v[i+1]) {
            j=i;
        }
        i=i+1;
    }
    if (j!=-1) {
        r=true;
    }
	return r;
}

// Ejercicio 2
int maximo(int x, int y){
  if(x<0)
    x=-x;
  if(y<0)
    y=-y;
  if(x>y)
    return x;
  else
    return y;
}

int minimo(int x, int y){
  if(x<0)
    x=-x;
  if(y<0)
    y=-y;
  if(x<y)
    return x;
  else
    return y;
}

int mcd(int m, int n){
  int a = maximo(m,n);
  int b = minimo(m,n);
  int resto;
  while((b!=0) || (b!=1)){
    resto = a%b;
    b = a;
    a = resto;
  }
  if(a==0)
    return a;
  else
    return 1;
}

// Ejercicio 3
 int indiceMinSubsec(vector<int> v, int l, int r){
    int i=r;
    int res=r;
    while (i>=l) {
        if(v[res]>=v[i]) {
                res=i;
        }
    i=i-1;    
    }
    return res;
}


// Ejercicio 4
void ordenar1(vector<int>& v){
    int i=0;
    int j=0;
    vector<int> w=v;
    while (i<v.size()) {
        w[i]=v[indiceMinSubsec(w, 0, w.size())];
//        w=v-v[i]
        i=i+1;    
    }
	return;
}

// Ejercicio 5
void ordenar2(vector<int>& v){
	return;
}

// Ejercicio 6
tuple<int,int> division(int n, int d){
	return make_tuple(0,0);
}
