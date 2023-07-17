#include "definiciones.h"
#include "auxiliares.h"

using namespace std;
// aqui se pueden ubicar todas las funciones auxiliares de soporte para la resolucion de los ejercicios

//// ---------------------- EJERCICIO (1) ---------------------- ////
bool esJugadorValido(pair<tablero, int> const &p) {
    return p.second == BLANCO || p.second == NEGRO;

}

bool esMatriz(pair<tablero, int> const &p){
    bool res = true;
    tablero t = p.first;

    if(t.size() == ANCHO_TABLERO) {
        for (int i = 0; i < ANCHO_TABLERO; i++) {
            res = res && t[i].size() == ANCHO_TABLERO;
        }
    } else {
        res = false;
    }
    return res;
}

bool sinPeonesNoCoronados(tablero t) {
    bool res = true;

    for (int i = 0; i < ANCHO_TABLERO; i++)
        if (t[0][i].first == PEON || t[7][i].first == PEON) {
            res = false;
        }
    return res;
}

bool casillas_y_piezas_validas( pair<tablero, int> const &p ) {
    tablero t = p.first;
    vector<int> cantidad(8);

    int columnas = t.size();
    int filas = t[0].size();
    bool res = true;

    for(int a = 0; a < columnas; a++){ // en el for chequeamos que las coords. esten en rango.
        for(int b = 0; b < filas; b++){
            if(casillasValidas(a, b,t)){ //todas las casillas tienen que ser válidas para poder sumar.
                cantidadDePiezas(cantidad, a, b, t);
            } else{
                res = false;
            }
        }
    }

    for(int a = 0; a < 5; a++){
        if(a == 0){
            res = res && cantidad[a] <= 8 && cantidad[a + 4] <= 8;
        } else if(a == 1){
            res = res && cantidad[a] <= 2 && cantidad[a + 4] <= 2;
        } else if(a == 2){
            res = res && cantidad[a] <= 2 + (8 - cantidad[0]) && cantidad[a + 4] <= 2 + (8 - cantidad[4]);
        } else if(a == 3){
            res = res && cantidad[a] == 1 && cantidad[a + 4] == 1;
        }
    }

    return res;
}

bool casillasValidas(int a, int b, tablero t) {
    bool res = false;
    int primerCoord = t[a][b].first;
    int segundaCoord = t[a][b].second;

    if (0 < primerCoord && 5 > primerCoord && 0 < segundaCoord &&  3 > segundaCoord || t[a][b] == cVACIA) {
            res = true;
    }
        return res;
}


void cantidadDePiezas(vector<int>& cantidad, int a, int b, tablero t) { // cantidad = <PN,AN,TN,RN,PB,AB,TB,RB>
    if (t[a][b].second == NEGRO) {
        cantidad[t[a][b].first - 1] = cantidad[t[a][b].first - 1] + 1;
    } else if (t[a][b].second == BLANCO) {
        cantidad[(t[a][b].first + 3)] = cantidad[(t[a][b].first + 3)] + 1;
    }
}




//// ---------------------- EJERCICIO (3) ---------------------- ////


void movimientoPiezaValido(tablero t, int f, int c, int j, vector<coordenada> &cA) {

        if (t[f][c].first == TORRE) {
            movimientoTorreValido(t, f, c, cA);
        } else if (t[f][c].first == ALFIL) {
            movimientoAlfilValido(t, f, c, cA);
        } else if (t[f][c].first == REY) {
            movimientoReyValido(t, f, c, cA);
        } else if(t[f][c].first == PEON){
           movimientoPeonValido(t, f, c, j, cA);
        }
}

void movimientoPeonValido(tablero t, int f, int c, int j,vector<coordenada> &cA){
    if(j == BLANCO){
        movimientoPeonBlanco(t, f, c, cA);
    } else {
        movimientoPeonNegro(t, f, c, cA);
    }
}

void movimientoPeonNegro(tablero t,int f, int c, vector<coordenada> &cA) {
    if (t[f + 1][c] == cVACIA ) {
        cA.push_back(mp(f + 1,c));
    }
}

void movimientoPeonBlanco(tablero t,int f, int c, vector<coordenada> &cA) {
    if (t[f - 1][c] == cVACIA ) {
        cA.push_back(mp(f - 1,c));
    }
}

void movimientoTorreValido(tablero t, int f, int c, vector<coordenada> &cA){
    movTorreDerecha(t, f, c, cA);
    movTorreIzquierda(t, f, c, cA);
    movTorreAbajo(t, f, c, cA);
    movTorreArriba(t, f, c, cA);
}

void movTorreDerecha(tablero t, int f, int c, vector<coordenada> &cA){
    int bton = 0;
    for(int i = c + 1; i < ANCHO_TABLERO && bton == 0; i++){ // ATACADAS DE LA TORRE A DERECHA
        if((t[f][i]).second == VACIO){
            cA.push_back(mp(f,i));
        } else{
            cA.push_back(mp(f,i));
            bton = 1;
        }
    }
}

void movTorreIzquierda(tablero t, int f, int c, vector<coordenada> &cA){
    int bton = 0;
    for(int i = c - 1; i >= 0 && bton == 0; i--){ // ATACADAS DE LA TORRE A IZQUIERDA
        if((t[f][i]).second == VACIO){
            cA.push_back(mp(f,i));
        } else{
            cA.push_back(mp(f,i));
            bton = 1;
        }
    }
}


void movTorreAbajo(tablero t, int f, int c, vector<coordenada> &cA) {
    int bton = 0;
    for(int i = f - 1; i >= 0 && bton == 0; i--){ // ATACADAS DE LA TORRE A ABAJO - hacia fila 0.
        if((t[i][c]).second == VACIO){
            cA.push_back(mp(i,c));
        } else{
            cA.push_back(mp(i,c));
            bton = 1;
        }
    }
}

void movTorreArriba(tablero t, int f, int c, vector<coordenada> &cA) {
    int bton = 0;
    for (int i = f + 1; i < ANCHO_TABLERO && bton == 0; i++) { // ATACADAS DE LA TORRE A ARRIBA - hacia fila 7.
        if ((t[i][c]).second == VACIO) {
            cA.push_back(mp(i, c));
        } else {
            cA.push_back(mp(i, c));
            bton = 1;
        }
    }
}

void capturaPeon(tablero t, int f, int c, int j, vector<coordenada> &cA){
        if (j == BLANCO) {
            atacadasPeonBlanco(t, f, c, cA);
        } else {
            atacadasPeonNegro(t, f, c, cA);
        }
}


void atacadasPeonNegro(tablero t,int f, int c, vector<coordenada> &cA) {
    if (coordenadaEnRango(mp(f + 1, c - 1))) {
        cA.push_back(mp(f + 1, c - 1));
    }
    if (coordenadaEnRango(mp(f + 1, c + 1))) {
        cA.push_back(mp(f + 1, c + 1));
    }
}

void atacadasPeonBlanco(tablero t,int f, int c, vector<coordenada> &cA) {
    if (coordenadaEnRango(mp(f - 1, c - 1))) {
        cA.push_back(mp(f - 1, c - 1));
    }
    if (coordenadaEnRango(mp(f - 1, c + 1))) {
        cA.push_back(mp(f - 1, c + 1));
    }
}

void movimientoAlfilValido(tablero t, int f, int c, vector<coordenada> &cA){
    movAlfilArribaDerecha(t, f, c, cA);
    movAlfilAbajoIzquierda(t, f, c, cA);
    movAlfilAbajoDerecha(t, f, c, cA);
    movAlfilArribaIzquierda(t, f, c, cA);
}

void movAlfilArribaDerecha(tablero t, int f, int c, vector<coordenada> &cA){
    int bton = 0;
    int i = f + 1;
    int k = c + 1;
    while(i < ANCHO_TABLERO && k < ANCHO_TABLERO && bton == 0){
        if((t[i][k]).second == VACIO){
            cA.push_back(mp(i,k));
        } else {
            cA.push_back(mp(i,k));
            bton = 1;
        }
        i++;
        k++;
    }
}

void movAlfilAbajoDerecha(tablero t, int f, int c, vector<coordenada> &cA){
    int bton = 0;
    int i = f - 1;
    int k = c + 1;
    while(i >= 0 && k < ANCHO_TABLERO && bton == 0){
        if((t[i][k]).second == VACIO){
            cA.push_back(mp(i,k));
        } else {
            cA.push_back(mp(i,k));
            bton = 1;
        }
        i--;
        k++;
    }
}
void movAlfilArribaIzquierda(tablero t, int f, int c, vector<coordenada> &cA){
    int bton = 0;
    int i = f + 1;
    int k = c - 1;
    while(i < ANCHO_TABLERO && k >= 0 && bton == 0){
        if((t[i][k]).second == VACIO){
            cA.push_back(mp(i,k));
        } else {
            cA.push_back(mp(i,k));
            bton = 1;
        }
        i++;
        k--;
    }
}

void movAlfilAbajoIzquierda(tablero t, int f, int c, vector<coordenada> &cA){
    int bton = 0;
    int i = f - 1;
    int k = c - 1;
    while(i >= 0 && k >= 0 && bton == 0){
        if((t[i][k]).second == VACIO){
            cA.push_back(mp(i,k));
        } else {
            cA.push_back(mp(i,k));
            bton = 1;
        }
        i--;
        k--;
    }
}

void movimientoReyValido(tablero t, int f, int c, vector<coordenada> &cA){
    for(int i = f - 1; i < f + 2; i++){
        for(int k = c - 1; k < c + 2; k++){
            if(coordenadaEnRango(mp(i,k))) {
                if (t[i][k] != t[f][c]) {
                    cA.push_back(mp(i, k));
                }
            }
        }
    }
}

void vectorSinRepetidos(vector<coordenada> &cA){
    for(int i = 0; i < cA.size(); i++){
        for(int j = i + 1; j < cA.size(); j++){
            if(cA[i] == cA[j]){
               cA.erase(cA.begin() + j);
               j = j - 1;
            }
        }
    }
}



//// -----------------------------EJERCICIO (4)------------------------ ////

bool esJugadaValida(posicion const &p1,coordenada o, coordenada d ) {
    bool res = false;
    tablero t = p1.first;
    vector<coordenada> cA;

    if(colorDePieza(t,d) != p1.second && t[o.first][o.second] != cVACIA) {
        if(tipoDePieza(t,o.first, o.second) == TORRE) {
            res = jugadaValidaTorre(t, o, d, cA);
        } else if (tipoDePieza(t,o.first, o.second) == ALFIL) {
            res = jugadaValidaAlfil(t, o, d, cA);
        } else if (tipoDePieza(t,o.first, o.second) == REY) {
            res = jugadaValidaRey(t, o, d, cA);
        } else if (tipoDePieza(t,o.first, o.second) == PEON) {
            res = jugadaValidaPeon(t, o ,d, cA);
        }
    }
    return res;
}


bool jugadaValidaTorre(tablero t, coordenada o, coordenada d, vector<coordenada> cA) {
    bool res = false;
        if (o.first == d.first && o.second < d.second) { //Moviento TORRE DERECHA
            res = jugValidaTorreDerecha(t, o, d, cA);
        } else if (o.first == d.first && o.second > d.second) { //Moviento TORRE IZQUIERDA
            res = jugValidaTorreIzquierda(t, o, d, cA);
        } else if (o.first > d.first && o.second == d.second) { //Moviento TORRE ABAJO
            res = jugValidaTorreAbajo(t, o, d, cA);
        } else if (o.first < d.first && o.second == d.second) { //Moviento TORRE ARRIBA
            res = jugValidaTorreArriba(t, o, d, cA);
        }
    return res; }


bool jugValidaTorreDerecha(tablero t, coordenada o, coordenada d, vector<coordenada> cA) {
    bool res = false;
    movTorreDerecha(t, o.first, o.second, cA);

    res = pertenece(cA, d);

    cA.clear();
    return res; }

bool jugValidaTorreIzquierda(tablero t, coordenada o, coordenada d, vector<coordenada> cA){
    bool res = false;
    movTorreIzquierda(t, o.first, o.second, cA);

    res = pertenece(cA, d);

    cA.clear();
    return res; }

bool jugValidaTorreAbajo(tablero t, coordenada o, coordenada d, vector<coordenada> cA){
    bool res = false;
    movTorreAbajo(t, o.first, o.second, cA);

    res = pertenece(cA, d);

    cA.clear();
    return res; }

bool jugValidaTorreArriba(tablero t, coordenada o, coordenada d, vector<coordenada> cA){
    bool res = false;
    movTorreArriba(t, o.first, o.second, cA);
    res = pertenece(cA, d);

    cA.clear();
    return res; }


bool jugadaValidaAlfil(tablero t, coordenada o, coordenada d, vector<coordenada> cA){
    bool res = false;
    if (o.first < d.first && o.second < d.second) { //Moviento ALFIL DERECHA ARRIBA
        res = jugValidaAlfilDerechaArriba(t, o, d, cA);
    } else if (o.first > d.first && o.second > d.second) { //Moviento ALFIL IZQUIERDA ABAJO
       res = jugValidaAlfilIzquierdaAbajo(t, o, d, cA);
    } else if (o.first > d.first && o.second < d.second) { //Moviento ALFIL DERECHA ABAJO
        res = jugValidaAlfilDerechaAbajo(t, o, d, cA);
    } else if (o.first < d.first && o.second > d.second) { //Moviento ALFIL IZQUIERDA ARRIBA
        res = jugValidaAlfilIzquierdaArriba(t, o, d, cA);
    }
    return res; }

bool jugValidaAlfilDerechaArriba(tablero t, coordenada o, coordenada d, vector<coordenada> cA) {
    bool res = false;
    movAlfilArribaDerecha(t, o.first, o.second, cA);

    res = pertenece(cA, d);

    cA.clear();
    return res; }

bool jugValidaAlfilDerechaAbajo(tablero t, coordenada o, coordenada d, vector<coordenada> cA) {
    bool res = false;
    movAlfilAbajoDerecha(t, o.first, o.second, cA);

    res = pertenece(cA, d);

    cA.clear();
    return res; }

bool jugValidaAlfilIzquierdaArriba(tablero t, coordenada o, coordenada d, vector<coordenada> cA){
    bool res = false;
    movAlfilArribaIzquierda(t, o.first, o.second, cA);

    res = pertenece(cA, d);

    cA.clear();
    return res; }

bool jugValidaAlfilIzquierdaAbajo(tablero t, coordenada o, coordenada d, vector<coordenada> cA){
    bool res = false;
    movAlfilAbajoIzquierda(t, o.first, o.second, cA);

    res = pertenece(cA, d);

    cA.clear();
    return res; }

bool jugadaValidaRey(tablero t, coordenada o, coordenada d, vector<coordenada> cA) {
    bool res = false;
    movimientoReyValido(t, o.first, o.second, cA);

    res = pertenece(cA, d);

    cA.clear();
    return res; }

bool jugadaValidaPeon(tablero t, coordenada o, coordenada d, vector<coordenada> cA){
    bool res;
    if(t[o.first][o.second] == cPEON_N){
        res = jugadaValidaPeonNegro(t, o, d, cA);
    } else {
        res = jugadaValidaPeonBlanco(t, o, d, cA);
    }
    return res; }

bool jugadaValidaPeonNegro(tablero const t, coordenada o, coordenada d, vector<coordenada> cA) { //FALTA REVISAR QUE EN atacadas Solo estemos atacando las del color opuesto
    bool res = false;

    if(t[d.first][d.second] != cVACIA) {
        atacadasPeonNegro(t, o.first, o.second, cA);
    }

    movimientoPeonNegro(t, o.first, o.second, cA);
    res = pertenece(cA, d);

    cA.clear();
    return res; }

bool jugadaValidaPeonBlanco(tablero t, coordenada o, coordenada d, vector<coordenada> cA) { //FALTA REVISAR QUE EN atacadas Solo estemos atacando las del color opuesto
    bool res = false;

    if(t[d.first][d.second] != cVACIA) {
        atacadasPeonBlanco(t, o.first, o.second, cA);
    }

    movimientoPeonBlanco(t, o.first, o.second, cA);

    res = pertenece(cA, d);
    cA.clear();
    return res; }


bool pertenece(vector <coordenada> cA, coordenada d){
    bool res = false;
    for(int i = 0; i < cA.size(); i++){
        if(cA[i] == d){
            res = true;
        }
    }
    return res;
}

//// -----------------------------EJERCICIO (5)------------------------ ////

void ordenarFila(vector<coordenada> &fila){
    for(int i = 0; i < fila.size(); i++) {
        if(fila[i] != cVACIA) {
            seleccionarMinimo(fila, i);
        }
    }
}

void seleccionarMinimo (vector <coordenada> &fila , int i) {
    int posMinimo = i;
    for(int j = i; j < fila.size() ;j++) {
        if(fila[posMinimo].first > fila[j].first && fila[j] != cVACIA) {
            posMinimo = j;
            swap(fila ,i, posMinimo);
        }
    }
}

void swap (vector <coordenada> &fila ,int i, int j) {
    coordenada k = fila[i];
    fila[i] = fila[j];
    fila[j] = k;
}


//// -----------------------------EJERCICIO (6)------------------------ ////

bool reyAhogado(posicion p, int j){

    return !elReyEstaEnJaque(p, j) && !existenJugadasLegales(p, j);}

bool hayJaqueMate(posicion p, int j){

    return elReyEstaEnJaque(p,j) && !existenJugadasLegales(p,j); }

bool existenJugadasLegales(posicion p, int j){

    bool res = false;
    int columnas = p.first.size();
    vector<coordenada> cA = todosLosMovimientosYLasCapturas(p, p.second);

    for (int a = 0; a < columnas; a++) {
        for (int b = 0; b < columnas; b++) {
            if (colorDePieza(p.first, mp(a, b)) == j) {
                for(int k = 0; k < cA.size(); k++){
                    res = res || esJugadaLegal(p, mp(a, b), cA[k]);
                }
            }
        }
    }
    return res;
}

bool esJugadaLegal(posicion p,coordenada o,coordenada d){
    bool res = false;
    if (esJugadaValida(p, o, d) && !(elReyEstaEnJaque(posSig(p, o, d), p.second))) {
        res = true;
    }
    return res; }

bool soloHayReyes(tablero const t){
    bool res = true;
    vector<int> cantidad(8);

    for(int i = 0; i < t.size(); i++){
        for(int j = 0; j < t.size(); j++){
            cantidadDePiezas(cantidad, i, j, t);
        }
    }
    for(int k = 0; k < cantidad.size(); k++){
       if(k != 3 && k != 7 && cantidad[k] != 0){
            res = false;
        }
    }
    return res;
}

bool elReyEstaEnJaque(posicion p, int j){
    bool res = false;
    vector<coordenada> atacadasOponente = casillasAtacadas(p, colorOpuesto(j));
    coordenada ubicacionRey = coordRey(tableroActual(p),j);

    for(int i = 0; i < atacadasOponente.size(); i++){
        if(ubicacionRey == atacadasOponente[i]){
            res = true;
        }
    }
    return res;
}


coordenada coordRey(tablero t, int j){
    coordenada coord;
    for(int i = 0; i < t.size(); i++){
        for(int k = 0; k < t.size(); k++){
            if(t[i][k] == mp(REY,j)){
                coord = mp(i,k);
            }
        }
    }
    return coord;
}


//// -----------------------------EJERCICIO (7)------------------------ ////

bool jaqueDescubierto(posicion p, int j){

    bool res = false;
    int columnas = p.first.size();

    vector<coordenada> cA = todosLosMovimientosYLasCapturas(p, j);
    for (int a = 0; a < columnas; a++) {
        for (int b = 0; b < columnas; b++) {
            if (colorDePieza(p.first, mp(a, b)) == j) {
                for (int k = 0; k < cA.size(); k++) {
                    if (esJugadaLegal(p, mp(a, b), cA[k])) {
                        posicion posSiguiente = posSig_modificado(p, mp(a, b), cA[k]);
                        res = res || elReyEstaEnJaque(posSiguiente, colorOpuesto(p.second));
                    }
                }
            }
        }
    }
    return res;
}


//// -----------------------------EJERCICIO (8)------------------------ ////

posicion unicaJugadaPosible(posicion p, int j){
    posicion posMedia;
    int columnas = p.first.size();
    vector<coordenada> cA = todosLosMovimientosYLasCapturas(p, j);
    for (int a = 0; a < columnas; a++) {
        for (int b = 0; b < columnas; b++) {
            if (colorDePieza(p.first, mp(a, b)) == j) {
                for (int k = 0; k < cA.size(); k++){
                    if(esJugadaLegal(p, mp(a, b), cA[k])) {
                        posMedia = posSig(p, mp(a, b), cA[k]);
                    }
                }
            }
        }
    }
    return posMedia;
}


//// -----------------------------EJERCICIO (9)------------------------ ////


void movimientoPrimero(posicion p, int &resp) {
    int columnas = p.first.size();
    vector<coordenada> cA = todosLosMovimientosYLasCapturas(p, p.second);

    for (int a = 0; a < columnas; a++) {
        for (int b = 0; b < columnas; b++) {
            if (colorDePieza(p.first, mp(a, b)) == p.second) {
                for (int k = 0; k < cA.size(); k++) {
                    if (esJugadaLegal(p, mp(a, b), cA[k])) {
                        posicion p2 = posSig(p, mp(a, b), cA[k]);

                        if (hayJaqueMate(p2, p2.second)) {
                            resp = 1;
                        } else {
                            if (soloHayUnaJugadaLegal(p2,p2.second)){

                                posicion p2bis = unicaJugadaPosible(p2,p2.second);
                                movimientoSegundo(p2bis, resp);
                            }
                        }
                    }
                }
            }
        }
    }
}


void movimientoSegundo(posicion p, int &resp) {
    int columnas = p.first.size();
    vector <coordenada> cA = todosLosMovimientosYLasCapturas(p, p.second);

    for (int a = 0; a < columnas; a++) {
        for (int b = 0; b < columnas; b++) {
            if (colorDePieza(p.first, mp(a, b)) == p.second) {
                for (int k = 0; k < cA.size(); k++) {
                    if (esJugadaLegal(p, mp(a, b), cA[k])) {
                        posicion p3 = posSig(p, mp(a, b), cA[k]);

                        if (hayJaqueMate(p3, p3.second)) {
                            if (resp == 3 || resp == -1) {
                                resp = 2;
                            }
                        } else {
                            if (soloHayUnaJugadaLegal(p3, p3.second)) {

                                posicion p3bis = unicaJugadaPosible(p3, p3.second);
                                movimientoTercero(p3bis, resp);
                            }
                        }
                    }
                }
            }
        }
    }
}



void movimientoTercero(posicion p, int &resp){
    int columnas = p.first.size();
    vector<coordenada> cA = todosLosMovimientosYLasCapturas(p, p.second);

    for (int a = 0; a < columnas; a++) {
        for (int b = 0; b < columnas; b++) {
            if (colorDePieza(p.first, mp(a, b)) == p.second) {
                for (int k = 0; k < cA.size(); k++){
                    if(esJugadaLegal(p, mp(a, b), cA[k])){
                        posicion pFinal = posSig(p,mp(a,b),cA[k]);

                        if(hayJaqueMate(pFinal, pFinal.second)){
                            if(resp == -1) {
                                resp = 3;
                            }
                        }
                    }
                }
            }
        }
    }
}

//// ------------------------------------------------------------------ ////

bool soloHayUnaJugadaLegal(posicion p, int j){
    int res = 0;
    int columnas = p.first.size();
    vector<coordenada> cA = todosLosMovimientosYLasCapturas(p, p.second);

    for (int a = 0; a < columnas; a++) {
        for (int b = 0; b < columnas; b++) {
            if (colorDePieza(p.first, mp(a, b)) == j) {
                for (int k = 0; k < cA.size(); k++) {
                    if (esJugadaLegal(p, mp(a, b), cA[k])) {
                        res = res + 1;
                    }
                }
            }
        }
    }
    return res == 1;
}



vector<coordenada> todosLosMovimientosYLasCapturas(posicion p, int j) {
    int columnas = p.first.size();
    vector<coordenada> cA = casillasAtacadas(p, j);

    for (int a = 0; a < columnas; a++) {
        for (int b = 0; b < columnas; b++) {
            if (colorDePieza(p.first, mp(a, b)) == j){
                if(p.first[a][b].first == PEON) {
                    sumaMovimientosPeones(p.first, mp(a, b), cA);
                }
            }
        }
    }
    return cA;
}

posicion posSig(posicion p,coordenada o,coordenada d) {
    posicion sig = p;
    sig.second = colorOpuesto(p.second);

    if (tipoDePieza(p.first, o.first, o.second) == PEON && (d.first == 0 || d.first == 7)){
        sig.first[d.first][d.second] = mp(TORRE,p.second);
    } else {
        sig.first[d.first][d.second] = p.first[o.first][o.second];
    }
    (sig.first)[o.first][o.second] = cVACIA;
    return sig;
}

posicion posSig_modificado(posicion p,coordenada o,coordenada d) {
    posicion sig = p;
    sig.second = colorOpuesto(p.second);
    (sig.first)[d.first][d.second] = mp(PEON, colorOpuesto(p.second));
    (sig.first)[o.first][o.second] = cVACIA;
    return sig;
}

void sumaMovimientosPeones(tablero t, coordenada c, vector<coordenada> &cA){

    movimientoPiezaValido(t,c.first,c.second,colorDePieza(t,c), cA);

}

int colorOpuesto(int color){
    if(color == BLANCO){
        return NEGRO;
    } else {
        return BLANCO;
    }
}

int colorDePieza(tablero t, coordenada c){
    return t[c.first][c.second].second;
}
bool coordenadaEnRango(coordenada c) {
    return (-1 < c.first && c.first < 8 && -1 < c.second && c.second < 8);
}

int tipoDePieza(tablero t, int c0, int c1){
   return t[c0][c1].first;
}

pair<int, int> mp(int a, int b) {
    return make_pair(a, b);
}

// TEST
vector<pair<int, int> > ordenarVectorPares(vector<pair<int, int> > &v) {
    sort(v.begin(), v.end());
//    v.erase(unique(v.begin(), v.end()), v.end());
    return v;
}

coordenada setCoord(int i, int j) {
    return make_pair(i, j);
}

tablero tableroActual(posicion const &p) {
    return p.first;
}

//tablero inicializarTablero() {
//    vector<casilla> fila(ANCHO_TABLERO, cVACIA);
//    tablero out(ANCHO_TABLERO, fila);
//    return out;
//}