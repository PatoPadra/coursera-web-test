#include "definiciones.h"
#include "auxiliares.h"
#include "ejercicios.h"

int filas();

using namespace std;

//Se verifica si el toroide es rectangular
bool esRectangulo(const vector<vector<bool>> &t) {
    if (t.empty()) {
        return false;
    }
    int k = t[0].size();
    if (k == 0) {
        return false;
    }
    for (int i = 1; i < t.size(); ++i) {
        if (t[i].size() != k) {
            return false;
        }
    }
    return true;
}

//copia un toroide, me resulto necesario para poder hacer las evoluciones sin que se altere la comparacion
toroide copiarToroide(const toroide &t) {
    toroide tInicial(t.size(), vector<bool>());
    for (int i = 0; i < t.size(); ++i) {
        for (int j = 0; j < t[i].size(); ++j) {
            tInicial[i].push_back(t[i][j]);
        }
    }
    return tInicial;
}

// compara posición a posición si dos toroides son iguales
bool sonIguales(toroide const &t1, toroide const &t2) {
    bool resp = true;
    for (int i = 0; i < t1.size(); ++i) {
        for (int j = 0; j < t1[i].size(); ++j) {
            if (t1[i][j] != t2[i][j]) {
                resp = false;
            }
        }
    }
    return resp;
}

// es basicamente esPeriodico pero sin la necesidad de un K como paramentro
bool esCiclico(toroide const &t) {
    int p = 0;
    return esPeriodico(t, p);
}

//mueve el toroide a la derecha
void moverDerecha(toroide &t) {
    toroide tInicial = copiarToroide(t);
    int xSize = t[0].size(); //lo use para que quede mas prolijo
    for (int i = 0; i < t.size(); ++i) {
        for (int j = 0; j < xSize; ++j) {
            int x = (j + 1) % xSize;
            t[i][x] = tInicial[i][j];
        }
    }
}

//mueve el toroide para abajo
void moverAbajo(toroide &t) {
    toroide tInicial = copiarToroide(t);
    int ySize = t.size(); //lo use para que quede mas prolijo
    for (int i = 0; i < t.size(); ++i) {
        for (int j = 0; j < t[0].size(); ++j) {
            int y = (i + 1) % ySize;
            t[y][j] = tInicial[i][j];
        }
    }
}

// retorna superficie de menor rectangulo vivo
// aclaración: por la forma que esta contruido el vector de posiciones vivas
// sabemos que el 1er elemento siempra va a ser el menor Y posible
int menorRectanguloVivo(vector<posicion> posicionesVivas) {
    if (posicionesVivas.size() == 0) {
        return 0;
    }
    int minX = posicionesVivas[0].second;
    int maxX = posicionesVivas[0].second;
    int minY = posicionesVivas[0].first;
    int maxY = posicionesVivas[0].first;
    int x = 0;
    int y = 0;
    int res = 0;
    for (int i = 0; i < posicionesVivas.size(); ++i) {
        if (posicionesVivas[i].second < minX) {
            minX = posicionesVivas[i].second;
        }
        if (posicionesVivas[i].second > maxX) {
            maxX = posicionesVivas[i].second;
        }
        if (posicionesVivas[i].first > maxY) {
            maxY = posicionesVivas[i].first;
        }
    }
    x = maxX - minX + 1;
    y = maxY - minY + 1;
    res = x * y;
    return res;
}

// aqui se pueden ubicar todas las funciones auxiliares de soporte para la resolucion de los ejercicios
pair<int, int> mp(int a, int b) {
    return make_pair(a, b);
}

//No pueden usar esta función para resolver el TPI.
//Tampoco pueden usar iteradores, como usa esta función.
vector<posicion> ordenar(vector<posicion> &v) {
    sort(v.begin(), v.end());
    return v;
}