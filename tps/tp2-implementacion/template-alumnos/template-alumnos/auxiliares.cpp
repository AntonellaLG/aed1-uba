#include "definiciones.h"
#include "auxiliares.h"

using namespace std;
// aqui se pueden ubicar todas las funciones auxiliares de soporte para la resolucion de los ejercicios
pair<int,int> mp(int a, int b) {
    return make_pair(a, b);
}


bool esMatriz(tablero q) {
    bool res=true;
    res=q.size()==ANCHO_TABLERO;
    for(int i=0; i<q.size(); i++) {
        res &= (q[i].size()==ANCHO_TABLERO);
    }
    return res;
}


bool casillasValidas(tablero q) {
    bool res=true;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            res &= (q[i][j].first==q[i][j].second==0 || (1<=q[i][j].first<=4 && 1<=q[i][j].second<=4));
        }
    }
    return res;
}


bool cantValidaDePiezas (tablero q) {
    bool res=cantAlfilesValida(q) && cantPeonesyTorresValida(q) &&  cantReyesValida(q);
    return res;
}


bool cantAlfilesValida(tablero q) {

}


bool sinPeonesNoCoronados (tablero q) {
    bool res=true;
}


bool peonesEnCoordenadas (tablero q) {
    bool res=true;
    for (int i=0; i<8; i=i+8) {
        for (int j=0; j<8; j++) {
            res&= q[i][j]==cPEON_N;
        }
    }
    for (int i=6; i<8; i=i+8) {
        for (int j=0; j<8; j++) {
            res&= q[i][j]==cPEON_B;
        }
    }
    return res;
}

bool torresEnCoordenadas(tablero q) {
    bool res=true;
    for (int i=0; i<8; i=i+8) {
        for (int j=0; j<8; j=j+7) {
            res&= q[i][j]==cTORRE_N;
        }
    }
    for (int i=7; i<8; i=i+8) {
        for (int j=0; j<8; j=j+7) {
            res&= q[i][j]==cTORRE_B;
            }
    }
    return res;
}

bool alfilesEnCoordenadas (tablero q) {
    bool res=true;
    for (int i=0; i<8; i=i+8) {
        for (int j=2; j<8; j=j+3) {
            res&= q[i][j]==cALFIL_N;
        }                              
    }
    for (int i=7; i<8; i=i+8) {
        for (int j=2; j<8; j=j+3) {   
            res&= q[i][j]==cALFIL_B;
            }
    }
    return res;
}

bool reyesEnCoordenadas (tablero q) {
    bool res=true;
//    for (int i=0; i<8; i=i+7) {
//        for (int j=4; j<8; j=j+4) {
//             res&= q[i][j]==cREY_N;
//        }
//    }
//    for (int i=7; i<8; i=i+7) {
//        for (int j=4; j<8; j=j+4) {
//             res&= q[i][j]==cREY_B;
//        }
//    }          
    res= ((q[0][4]==cREY_N) && (q[7][4]==cREY_B));
    return res;
}

bool piezasEnCoordenadas (tablero q) {
    bool res=true;
    res = peonesEnCoordenadas(q) && torresEnCoordenadas(q) && alfilesEnCoordenadas(q) && reyesEnCoordenadas(q);
    return res;
}

int aparicionesEnTablero (tablero q, casilla c) {
    int cant=0;
    for (int i=0; i< ANCHO_TABLERO; i++) {        //ACA NOSE SI DEJAR ANCHO_TABLERO...
        for (int j=0; j< ANCHO_TABLERO; j++) {  
            if (q[i][j]==c) {
                cant++;
            } 
        }
    }
    return cant; 
}

bool cantidadPiezasAlInicio (tablero q) {
    bool res=true;
    res&= aparicionesEnTablero(q, cTORRE_N)==2;
    res&= aparicionesEnTablero(q, cTORRE_B)==2;
    res&= aparicionesEnTablero(q, cALFIL_N)==2;
    res&= aparicionesEnTablero(q, cALFIL_B)==2;
    res&= aparicionesEnTablero(q, cPEON_N)==ANCHO_TABLERO;
    res&= aparicionesEnTablero(q, cPEON_B)==ANCHO_TABLERO;
//    res&= aparicionesEnTablero(q, cREY_N)==1;    NO PIDE CANTIDAD DE REYES
//    res&= aparicionesEnTablero(q, cREY_B)==1;
    return res;
}

//int pieza(posicion p, coordenada c) {
//    int res=0;
//    res= (p.first[c.first][c.second]).first;
//    return res;
//}

//int color(posicion p, coordenada c) {
//    int res=0;
//    res= (p.first[c.first][c.second]).second;
//    return res;
//}

bool posicionesIgualesExceptoEn (posicion p1, posicion p2, secuencia c) {
    bool res=true;
    for (int i=0; i<ANCHO_TABLERO; i++) {
        for (int j=0; j<ANCHO_TABLERO; j++) {
            for (int k=0; k<c.size(); k++) {
                if (setCoord(i, j)!=c[k]) {   // (i!=c[k].first && j!=c[k].second)    //REVISAR EL TIPO
                    res&= (p1.first[i][j]).first==(p2.first[i][j]).first;     //PIEZA
                    res&= (p1.first[i][j]).second==(p2.first[i][j]).second;   //COLOR
                }
            }
        }
    }
    return res;
}

bool casillaVacia (tablero q, coordenada c) {
    bool res=true;
    res= q[c.first][c.second]==cVACIA;
    return res;
}

bool enLineaFinalInicial (coordenada c) {
    bool res=true;
    res= c.first==VACIO || c.first==ANCHO_TABLERO-1;
    return res;
}

bool piezaCorrectaEnDestino (posicion p1, posicion p2, coordenada o, coordenada d) {
    bool res=true;
    res&= (p1.first[o.first][o.second]).second==(p2.first[d.first][d.second]).second;
    res&= (enLineaFinalInicial(d) && p2.first[d.first][d.second].first==TORRE) || (!enLineaFinalInicial(d) && p2.first[d.first][d.second]==p1.first[o.first][o.second]);
    return res;                                                         //CHEQUEAR LA NEGACION DE enLineaFinalInicial
}

bool movimientoPeonValido (int a, coordenada o, coordenada d) {
    bool res=true;
    res&= d.second==o.second;
    res&= (a==BLANCO && d.first==o.first-1) || (a==NEGRO && d.first==o.first+1);
    return res;
}

bool mueveEnHorizontal (coordenada o, coordenada d) {
    bool res=true;
    res&= abs(o.first, d.first)==0 || abs(o.second, d.second)==1;
    return res;
}

bool enRango (int x, int m1, int m2) {
    bool res=true;
    res= m1 < x < m2 || m2 < x < m1;
    return res;
}

bool movimientoAlfilValido (tablero q, coordenada o, coordenada d) {
    bool res=true;
    res&= abs(d.first - o.first)==abs(d.second - o.second);
    for (int i=0; i<ANCHO_TABLERO; i++) {
        if (enRango(i, 0, d.first - o.first)) {
            for (int j=0; j<ANCHO_TABLERO; j++) {
                if (enRango(j, 0, d.second - o.second) && abs(i)==abs(j)) {
                    res&= casillaVacia (q, setCoord(o.first + i, o.second + j));  //REVISAR TIPO DE setCoord
                }
            }
        }
    }
    return res;
}

bool movimientoTorreValido (tablero q, coordenada o, coordenada d) {
    bool res=true;
    if (d.second == o.second) {
        for (int i=0; i<ANCHO_TABLERO; i++) {
            if (enRango(i, o.first, d.first)) {
                res= casillaVacia(q, setCoord(i, o.second));
            }
        }
    }
    if (d.first==o.first) {
        for(int j=0; j<ANCHO_TABLERO; j++) {
            if (enRango(j, o.second, d.second)) {
                res|= casillaVacia(q, setCoord(o.first, j));
            }
        }
    }
    return res;
}

bool mueveEnDiagonal (coordenada o, coordenada d) {
    bool res=true;
    res&= abs(o.first, d.first) = 1 && abs(o.second, d.second) = 1;
    return res;
}

bool mueveEnVertical (coordenada o, coordenada d) {
    bool res=true;
    res&= abs(o.first, d.first) = 1 && abs(o.second, d.second) = 0;
    return res;
}

bool movimientoReyValido (coordenada o, coordenada d) {
    bool res=true;
    res= mueveEnDiagonal (o, d) || mueveEnVertical(o, d) || mueveEnHorizontal(o, d);
    return res;
}

bool movimientoPiezaValido (tablero q, coordenada o, coordenada d) {
    bool res=true;
    res= q.first[o.first][o.second]==PEON && movimientoPeonValido (q.second[o.first][o.second], o, d);
    res|= q.first[o.first][o.second]==ALFIL && movimientoAlfilValido(q, o, d);
    res|= q.first [o.first][o.second]==TORRE && movimientoTorreValido(q, o, d);
    res|= q.first[o.first][o.second]==REY && movimientoReyValido(o, d);
    return res;
}

bool esMovimientoValido (posicion p, coordenada o, coordenada d) {
    bool res=true;
    res&= p.second==p.second[o.first][o.second];
    res&= !casillaVacia(p.first, o);
    res&= casillaVacia(p.first, d);
    res&= movimientoPiezaValido(p.first, o, d);
    return res;
}

//En el predicado posicionSiguiente donde dice "< setCoord(o, d) >" debería decir "< o, d >"

bool posicionSiguiente (posicion p1, posicion p2, coordenada o, coordenada d) {
    bool res=true;
    res&= posicionesIgualesExceptoEn(p1, p2, vector<pair<o, d>>);  //posIgualesExcEn toma secuencia de coord
    res&= casillaVacia(p2.first, o);
    res&= esMovimientoValido(p1, o, d) || esCapturaValida(p1, o, d);
    res&= piezaCorrectaEnDestino(p1, p2, o, d);
    return res;
}

// TEST
vector<pair<int,int>> ordenarVectorPares(vector<pair<int,int>> &v) {
    sort(v.begin(), v.end());
//    v.erase(unique(v.begin(), v.end()), v.end());
    return v;
}

coordenada setCoord(int i, int j) {
    return make_pair(i,j);
}

tablero tableroActual ( posicion const &p ) {
    return p.first;
}

tablero inicializarTablero(){
    vector<casilla> fila(ANCHO_TABLERO, cVACIA);
    tablero out(ANCHO_TABLERO, fila);
    return out;
}