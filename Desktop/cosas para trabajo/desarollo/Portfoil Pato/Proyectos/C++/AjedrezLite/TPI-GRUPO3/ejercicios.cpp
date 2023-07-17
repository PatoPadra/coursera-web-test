#include <algorithm>
#include "ejercicios.h"
#include "auxiliares.h"

// EJERCICIO 1
bool posicionValida ( pair < tablero, int > const &p ) {

    bool resp = esJugadorValido(p) && casillas_y_piezas_validas(p) && esMatriz(p) && sinPeonesNoCoronados(p.first);
    return resp; }

// EJERCICIO 2

bool posicionInicial (posicion const &p) {
    tablero t = p.first;
    int jugador = p.second;
    int columnas = p.first.size();

    bool res = true;
    vector<int> cantidad(8);
    vector<int> vInicial = {TORRE, VACIO, ALFIL, VACIO, REY, ALFIL, VACIO, TORRE};

    if (jugador == BLANCO) { // JUGADOR DEL COLOR CORRECTO
        //PEONES Y VACIAS EN SUS COORDENADAS
        for (int i = 0; i < columnas; i++) {
            if (t[1][i] != cPEON_N || t[6][i] != cPEON_B) {
                res = false;
            }
            for (int j = 2; j < 6; j++) {
                if (t[j][i] != cVACIA) {
                    res = false;
                }
            }
        }
        //TORRES, ALFILES y REYES EN SUS COORDENADAS
        for (int i = 0; i < columnas; i++) {
            if (t[0][i].second == BLANCO || t[0][i].first != vInicial[i]) {
                res = false;
            } else if (t[7][i].second == NEGRO || t[7][i].first != vInicial[i]) {
                res = false;
            }
        }
    } else {
        res = false;
    }
    return res;
}

// EJERCICIO 3
vector <coordenada> casillasAtacadas (posicion const &p, int j) {
    vector <coordenada> cA;
    tablero t = p.first;
    int columnas = p.first.size();
    int filas = p.first[0].size();

    for(int f = 0; f < filas; f++){
        for(int c = 0; c < columnas; c++){
            if(colorDePieza(t,mp(f,c)) == j) {
                if (t[f][c] != cVACIA && tipoDePieza(t, f, c) != PEON) {
                    movimientoPiezaValido(t, f, c, j, cA);
                }
                if (tipoDePieza(t, f, c) == PEON) {
                    capturaPeon(t, f, c, j, cA);
                }
            }
        }
    }

    vectorSinRepetidos(cA);
    return cA;
}
// EJERCICIO 4
bool posicionSiguienteCorrecta ( posicion const &p1, posicion const &p2, coordenada o, coordenada d ) {

    bool res = true;
    tablero t1 = tableroActual(p1);
    tablero tableroSiguiente = tableroActual(p2);

    if (p1.second != p2.second && esJugadaValida(p1, o, d)) {
        for (int a = 0; a < t1.size(); a++) {
            for (int b = 0; b < t1.size(); b++) {
                if (mp(a, b) != o && mp(a, b) != d && t1[a][b] != tableroSiguiente[a][b]) {
                    res = false;
                } else if (mp(a, b) == o && tableroSiguiente[a][b] != cVACIA) {
                    res = false;
                } else if  (mp(a, b) == d) {
                    if (tipoDePieza(t1, o.first, o.second) == PEON){
                        if((d.first == 0 || d.first == 7) && tipoDePieza(tableroSiguiente, a, b) != TORRE && p1.second == tableroSiguiente[a][b].second) {
                            res = false;
                        } else if ((d.first != 0 && d.first != 7)  && t1[o.first][o.second] != tableroSiguiente[a][b]){
                        res = false;
                    }
                } else if (t1[o.first][o.second] != tableroSiguiente[a][b]){
                    res = false ;
                    }
                }
            }
        }
    } else {
        res = false;
    }
    return res;
}
// EJERCICIO 5
void ordenarTablero ( posicion &p ) {
    for(int i = 0; i < ANCHO_TABLERO; i++){
        ordenarFila(p.first[i]);
    }
}


// EJERCICIO 6
bool finDeLaPartida ( posicion const &p, int &j ) {
    bool resp = false;

    if(reyAhogado(p, p.second) || soloHayReyes(tableroActual(p))){
        resp = true;
        j = 0;
    }

    if (hayJaqueMate (p, p.second)){
        resp = true;
        j = colorOpuesto(p.second);

    }

    return resp; }
// EJERCICIO 7
bool hayJaqueDescubierto ( posicion const &p ) {
    return jaqueDescubierto(p, p.second); }
// EJERCICIO 8

void ejecutarSecuenciaForzada ( posicion &p, secuencia s ) {
    posicion posicionMedia;

   for(int i = 0; i < s.size(); i++){
        posicionMedia = posSig(p,s[i].first, s[i].second);
        p = unicaJugadaPosible(posicionMedia, posicionMedia.second);
    }
}

// EJERCICIO 9
int seVieneElJaqueEn ( posicion const & p ) {
    int resp = -1;

    movimientoPrimero(p, resp);

    return resp; }
