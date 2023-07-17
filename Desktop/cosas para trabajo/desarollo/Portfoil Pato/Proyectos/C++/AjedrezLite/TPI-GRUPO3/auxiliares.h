//


#ifndef AJEDREZLITE_AUXILIARES_H
#define AJEDREZLITE_AUXILIARES_H

#include "definiciones.h"

using namespace std;
// definir aqui las funciones

//// EJERCICIO (1) ////
bool esJugadorValido( pair< tablero, int > const &p );
bool casillas_y_piezas_validas( pair<tablero, int> const &p );
bool esMatriz(pair<tablero, int> const &p);
bool sinPeonesNoCoronados(tablero t);
bool casillasValidas(int a, int b, tablero t);
void cantidadDePiezas(vector<int>& cantidad, int a, int b, tablero t);

//// EJERCICIO(3) /////
void movimientoPiezaValido(tablero t, int f, int c, int j, vector<coordenada> &cA);
void movimientoPeonValido(tablero t, int f, int c, int j,vector<coordenada> &cA);
void movimientoPeonBlanco(tablero t,int f,int c,vector<coordenada> &cA);
void movimientoPeonNegro(tablero t,int f,int c,vector<coordenada> &cA);
void movimientoTorreValido(tablero t, int f, int c, vector<coordenada> &cA);
void movTorreDerecha(tablero t, int f, int c, vector<coordenada> &cA);
void movTorreIzquierda(tablero t, int f, int c, vector<coordenada> &cA);
void movTorreArriba(tablero t, int f, int c, vector<coordenada> &cA);
void movTorreAbajo(tablero t, int f, int c, vector<coordenada> &cA);
void atacadasPeonBlanco(tablero t,int f, int c, vector<coordenada> &cA);
void atacadasPeonNegro(tablero t,int f, int c, vector<coordenada> &cA);
void movimientoAlfilValido(tablero t, int f, int c, vector<coordenada> &cA);
void movAlfilArribaDerecha(tablero t, int f, int c, vector<coordenada> &cA);
void movAlfilAbajoDerecha(tablero t, int f, int c, vector<coordenada> &cA);
void movAlfilArribaIzquierda(tablero t, int f, int c, vector<coordenada> &cA);
void movAlfilAbajoIzquierda(tablero t, int f, int c, vector<coordenada> &cA);
void capturaPeon(tablero t, int f, int c, int j, vector<coordenada> &cA);
void movimientoReyValido(tablero t, int f, int c, vector<coordenada> &cA);
void vectorSinRepetidos(vector<coordenada> &cA);
vector <coordenada> casillasAtacadas (posicion const &p, int j);

//// EJERCICIO(4) /////
bool esJugadaValida(posicion const &p1,coordenada o, coordenada d );
bool pertenece(vector <coordenada> cA, coordenada d);
bool jugadaValidaTorre(tablero t, coordenada o, coordenada d, vector<coordenada> cA);
bool jugadaValidaRey(tablero t, coordenada o, coordenada d, vector<coordenada> cA);
bool jugadaValidaPeon(tablero t, coordenada o, coordenada d, vector<coordenada> cA);
bool jugadaValidaPeonNegro(tablero t, coordenada o, coordenada d, vector<coordenada> cA);
bool jugadaValidaPeonBlanco(tablero t, coordenada o, coordenada d, vector<coordenada> cA);

bool jugValidaTorreDerecha(tablero t, coordenada o, coordenada d, vector<coordenada> cA);
bool jugValidaTorreIzquierda(tablero t, coordenada o, coordenada d, vector<coordenada> cA);
bool jugValidaTorreAbajo(tablero t, coordenada o, coordenada d, vector<coordenada> cA);
bool jugValidaTorreArriba(tablero t, coordenada o, coordenada d, vector<coordenada> cA);

bool jugadaValidaAlfil(tablero t, coordenada o, coordenada d, vector<coordenada> cA);
bool jugValidaAlfilDerechaArriba(tablero t, coordenada o, coordenada d, vector<coordenada> cA);
bool jugValidaAlfilDerechaAbajo(tablero t, coordenada o, coordenada d, vector<coordenada> cA);
bool jugValidaAlfilIzquierdaAbajo(tablero t, coordenada o, coordenada d, vector<coordenada> cA);
bool jugValidaAlfilIzquierdaArriba (tablero t, coordenada o, coordenada d, vector<coordenada> cA);


//// EJERCICIO (6) /////
bool soloHayReyes(tablero const t);
coordenada coordRey(tablero t, int j);
bool elReyEstaEnJaque(posicion p, int j);
tablero tableroSiguiente(tablero t,coordenada o,coordenada d);
bool esJugadaLegal(posicion p,coordenada o, coordenada d);
bool existenJugadasLegales(posicion p, int j);
bool existeMovimientoParaSalirDelJaque(posicion p, int j);
bool hayJaqueMate(posicion p, int j);
bool reyAhogado(posicion p, int j);

///// EJERCICIO (7) /////
bool jaqueDescubierto(posicion p, int j);
void sumaMovimientosPeones(tablero t, coordenada c, vector<coordenada> &cA);



//// EJERCICIO (8) ////
posicion unicaJugadaPosible(posicion p, int j);

//// EJERCICIO (9) ////
void movimientoPrimero(posicion p, int &resp);
void movimientoSegundo(posicion p, int &resp);
void movimientoTercero(posicion p, int &resp);
bool soloHayUnaJugadaLegal(posicion p, int j);

//// ------------ /////
posicion posSig(posicion p,coordenada o,coordenada d);
posicion posSig_modificado(posicion p,coordenada o,coordenada d);
int colorOpuesto(int color);
int tipoDePieza(tablero t, int c0, int c1);
int colorDePieza(tablero t, coordenada c);
void ordenarFila(vector<coordenada> &arr);
bool coordenadaEnRango(coordenada c);
void swap (vector <coordenada> &lista , int i, int j);
void seleccionarMinimo (vector <coordenada> &lista , int i);

vector<coordenada> todosLosMovimientosYLasCapturas(posicion p, int j);

pair<int,int> mp(int a, int b);
vector<pair<int,int> > ordenarVectorPares(vector<pair<int,int> > &v);
tablero inicializarTablero();
coordenada setCoord(int i, int j);
tablero tableroActual ( posicion const &p );
#endif //AJEDREZLITE_AUXILIARES_H
