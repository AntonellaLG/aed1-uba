#include <iostream>
using namespace std;

//Ejercicio 1
float suma(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j){
    return a+b+c+d+e+f+g+h+i+j;
}

float promedio(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j){
    return suma(a,b,c,d,e,f,g,h,i,j)/10;
}

int main(){
    cout << "Ingrese el número" << endl;
    int a=0;
    cin >> a;
    cout << "Ingrese el número" << endl;
    int b=0;
    cin >> b;
    cout << "Ingrese el número" << endl;
    int c=0;
    cin >> c;
    cout << "Ingrese el número" << endl;
    int d=0;
    cin >> d;
    cout << "Ingrese el número" << endl;
    int e=0;
    cin >> e;
    cout << "Ingrese el número" << endl;
    int f=0;
    cin >> f;
    cout << "Ingrese el número" << endl;
    int g=0;
    cin >> g;
    cout << "Ingrese el número" << endl;
    int h=0;
    cin >> h;
    cout << "Ingrese el número" << endl;
    int i=0;
    cin >> i;
    cout << "Ingrese el número" << endl;
    int j=0;
    cin >> j;
    cout << "La suma total es " << suma(a,b,c,d,e,f,g,h,i,j) << "y el promedio es " << promedio(a,b,c,d,e,f,g,h,i,j) << endl;
    return 0;
}

//Ejercicio 2
int main(){
    int i=0;
    int cont=0;
    int sum=0;
    int prom=0;
    cout << "Ingrese el número" << endl;
    cin >> i;
    while(i!=-1){
        sum+=i;
        cont++;
    }
    prom=sum/cont;
    cout << "La suma total es " << cont << "y el promedio es " << prom << endl;
    return 0;
}

//Ejercicio 3
int main(){
    int i=0;
    int contAprobados=0;
    int contDesaprobados=0;
    cout << "Ingrese el número" << endl;
    cin >> i;
    while(i!=-1){
        if(i>6){
            contAprobados++;
        } else {
            contDesaprobados++;
        }
    }
    int cont=contAprobados+contDesaprobados;
    if(cont<6){
        cout << "Error" << endl;
    } else {
        if(contAprobados>2*cont/3){
            cout << "Se puede incrementar el número de plazas en el curso" << endl;
        }
    }
    return 0;
}

//Ejercicio 7
void swap(int &a, int&b){
    int n=a;
    a=b;
    b=n;
}

int main(){
    cout << "Ingrese un número" << endl;
    int a=0;
    cin >>  a;
    cout << "Ingrese un número" << endl;
    int b=0;
    cin >> b;
    swap(a,b);
    printf("a=%d, b=%d\n", a, b);
    return 0;
}

//Ejercicio 9
void division(int dividendo, int divisor, int &cociente, int &resto){
    while(dividendo>=divisor){
        dividendo=dividendo-divisor;
        cociente++;
    }
    resto=dividendo;
}

void division2(int dividendo, int divisor, int &cociente, int &resto){
    while(resto>=divisor){
        cociente++;
        resto=dividendo-divisor*cociente;
    }
}

int main(){
    int cociente=0;
    int resto=0;
    cout << "Ingrese un número" << endl;
    int a=0;
    cin >> a;
    cout << "Ingrese un número" << endl;
    int b=0;
    cin >> b;
    int cociente2=0;
    int resto2=b;
    division(a,b,cociente,resto);
    cout << "cociente: " << cociente << endl;
    cout << "resto: " << resto << endl;
    division2(a,b,cociente2,resto2);
    cout << "cociente: " << cociente2 << endl;
    cout << "resto: " << resto2 << endl;
}

//Versión recursiva
void divisionRec(int dividendo, int divisor, int &cociente, int &resto){
    if(dividendo<divisor){
        resto=dividendo;
    } else {
        dividendo=dividendo-divisor;
        cociente++;
        divisionRec(dividendo,divisor,cociente,resto);
    }
}

int main(){
    int cociente=0;
    int resto=0;
    cout << "Ingrese un número" << endl;
    int a=0;
    cin >> a;
    cout << "Ingrese un número" << endl;
    int b=0;
    cin >> b;
    divisionRec(a,b,cociente,resto);
    cout << "cociente: " << cociente << ", resto: " << resto << endl;
    return 0;
}
