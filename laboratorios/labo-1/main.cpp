#include <iostream>
using namespace std;

//Ejercicio 1
int f(int x){
    return x+1;
}

int main () {
    cout << "El resultado es: " << f (10) << std :: endl ;
    return 0;
}

//Ejercicio 2
int f(int x, int y){
    return x+y;
}

//Ejercicio 3
int f(int x, int y){
    int res=0;
    if(x>y){
        res=x+y;
    } else {
        res=x*y;
    }
    return res;
}

//Ejercicio 4
bool esPrimo(int n){
    int divisores=0;
    for(int i=2; i<n; i++){
        if(n % i ==0){
            divisores++;
        }
    }
    if(divisores==0){
        return true;
    } else {
        return false;
    }
}

int main () {
    cout << "Ingrese un número: " << endl;
    int a=0;
    cin >> a;
    bool soyPrimo = esPrimo(a);
    cout << "El número" << a;
    if(soyPrimo){
        cout << "SI" << endl;
    } else {
        cout << "NO" << endl;
    }
    cout << "es Primo" << endl
    return 0;
}

//Ejercicio 5
//Version recursiva
int fibonacciRec(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    } else {
        return(fibonacciRec(n-1)+fibonacciRec(n-2));
    }
}

int main(){
    cout << "Ingrese un número:" << endl;
    int a=0;
    cin>> a;
    cout << "El" << n << "-ésimo número de Fibonacci es" << fibonacciRec(a-1);
    return 0;
}

//Versión iterativa
//Con while
int fibonacciIt(int n){
    int i=0;
    int fib=0;
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    while(i<=n){
        fib=fibonacciIt(i-1)+fibonacciIt(i-2);
        i++;
    }
    return fib;
}

//Con for 
int fibonacciIt2(int n){
    int fib=0;
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    for(int i=0; i<=n; i++){
        fib=fibonacciIt2(i-1)+fibonacciIt2(i-2);
    }
    return fib;
}

//Ejercicio 6
//Versión iterativa
//Con while
int sumaImparesMenores(int n){
    int i=1;
    int sum=0;
    while(i<=n){
        sum=sum+i;
        i=i+2;
    }
    return sum;
}

//Con for
int sumaImparesMenores2(int n){
    int sum=0;
    for(int i=1; i<=n; i=i+2){
        sum=sum+i;
    }
    return sum;
}

//Versión recursiva
int sumaImparesMenoresRec(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    } else {
        return sumaImparesMenoresRec(n-2)+n;
    }
}

int main(){
    cout << "Ingrese un número:" endl;
    int valorParaSumar=0;
    cin >> valorParaSumar;
    int res=sumaImparesMenores(valorParaSumar);
    cout << res << endl;
    return 0;
}

//Ejercicio 7
int sumaDivisores(int n){
    int sum=0;
    for(int i=1; i<=n; i++){
        if(n % i == 0){
            sum+=i;
        }
    }
    return sum;
}

int main(){
    cout << "Ingrese un número:" endl;
    int valorParaSumar=0;
    cin >> valorParaSumar;
    int res=sumaDivisores(valorParaSumar);
    cout << res << endl;
    return 0;
}
