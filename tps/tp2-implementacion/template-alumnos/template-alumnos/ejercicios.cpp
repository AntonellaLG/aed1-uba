#include <algorithm>
#include "ejercicios.h"

// EJERCICIO 1
bool posicionValida ( pair < tablero, int > const &p ) {
    bool resp = false;
    resp = esMatriz(p.first) && casillasValidas(p.first) && (0<=p.second<=2) && cantValidaDePiezas(p.first) && sinPeonesNoCoronados(p.first);
    return resp;
}

// EJERCICIO 2
bool posicionInicial ( posicion const &p ) {
    bool resp = false;
    resp = piezasEnCoordenada(p.first) && cantidadPiezasAlInicio(p.first) && p.second==BLANCO;   //jugador deberia estar
    return resp;                                                                                //como definicion de tipo??
}

// EJERCICIO 3
vector <coordenada> casillasAtacadas ( posicion const &p, int j ) {
    vector <coordenada> cA;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {    //OJO QUE NOS PASAN UN J JUGADOR
            int atacadasIJ=0;
            for (int k=0; k<8; k++) {
                for (int l=0; l<8; l++) {
                    if (p[k][l].second==j && esCapturaValida(p, p[k][j], p[i][j])) {
                        atacadasIJ++;
                    }
                }
            }
            if (atacadasIJ>0) {
                cA.push_back(p[i][j]);
            }
        }
    }
    return cA;
}

// EJERCICIO 4
bool posicionSiguienteCorrecta ( posicion const &p1, posicion const &p2, coordenada o, coordenada d ) {
    bool resp = false;
    resp= posicionSiguiente(p1, p2, o, d);
    return resp;
}

// EJERCICIO 5
void ordenarTablero ( posicion &p ) {
    // completar codigo
    return;
}

// EJERCICIO 6
bool finDeLaPartida ( posicion const &p, int &j ) {
    bool resp = false;
    // completar codigo
    return resp;
}

// EJERCICIO 7
bool hayJaqueDescubierto ( posicion const &p ) {
    bool resp = false;
    // completar codigo
    return resp;
}

// EJERCICIO 8
void ejecutarSecuenciaForzada ( posicion &p, secuencia s ) {
    // completar codigo
    return;
}

// EJERCICIO 9
int seVieneElJaqueEn ( posicion const & p ) {
    int resp = -1;
    // completar codigo
    return resp;
}
