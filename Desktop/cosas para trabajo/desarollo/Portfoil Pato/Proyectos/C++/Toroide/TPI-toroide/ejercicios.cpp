#include <algorithm>
#include "ejercicios.h"
#include "auxiliares.h"

bool esIgual(const toroide &vector, toroide vector1);

// EJERCICIO 1
bool toroideValido(vector<vector<bool>> const &t) {
    bool resp = true;
    resp &= esRectangulo(t);
    resp &= t.size() >= 3;
    resp &= !t.empty() && t[0].size() >= 3;
    return resp;
}


// EJERCICIO 2
bool toroideMuerto(toroide const &t) {

    bool resp = true;
    // Implementacion
    for (int i = 0; i < t.size(); ++i) {
        for (int j = 0; j < t[i].size(); ++j) {
            if (t[i][j]) {
                resp = false;
            }
        }
    }
    return resp;
}

// EJERCICIO 3
vector<posicion> posicionesVivas(toroide const &t) {
    vector<posicion> vivos;
    // Implementacion
    for (int i = 0; i < t.size(); ++i) {
        for (int j = 0; j < t[i].size(); ++j) {
            if (t[i][j] == true) {
                vivos.push_back(make_pair(i, j));
            }
        }
    }
    return vivos;
}

// EJERCICIO 4
float densidadPoblacion(toroide const &t) {
    float resp = -1;
    float estanVivas = posicionesVivas(t).size();
    // Implementacion
    resp = estanVivas / (t.size() * t[0].size());
    return resp;
}

// EJERCICIO 5
int cantidadVecinosVivos(toroide const &t, int f, int c) {
    int resp = 0;
    int xMod = 0;
    int yMod = 0;
    int xSize = t.size();
    int ySize = t[0].size();
    for (int i = f - 1; i <= f + 1; ++i) {
        yMod = (i + ySize) % ySize;
        for (int j = c - 1; j <= c + 1; ++j) {
            xMod = (j + xSize) % xSize;
            if (!(i == f && j == c) && t[yMod][xMod]) {
                resp += 1;
            }
        }
    }
    return resp;
}

// EJERCICIO 6
bool evolucionDePosicion(toroide const &t, posicion x) {
    bool resp = false;
    int vecVivos = cantidadVecinosVivos(t, x.first, x.second);
    // Implementacion
    if (t[x.first][x.second] == true) {
        if (vecVivos >= 2 && vecVivos <= 3) {
            resp = true;
        }
    } else {
        if (vecVivos == 3) {
            resp = true;
        }
    }
    return resp;
}

// EJERCICIO 7
void evolucionToroide(toroide &t) {
    // Implementacions
    toroide tInicial = copiarToroide(t);
    for (int i = 0; i < t.size(); ++i) {
        for (int j = 0; j < t[i].size(); ++j) {
            t[i][j] = evolucionDePosicion(tInicial, make_pair(i, j));
        }
    }
    return;
}

// EJERCICIO 8
toroide evolucionMultiple(toroide const &t, int K) {
    toroide out = copiarToroide(t);
    // Implementacion
    for (int i = 0; i < K; ++i) {
        evolucionToroide(out);
    }
    return out;
}

// EJERCICIO 9
bool esPeriodico(toroide const &t, int &p) {
    bool resp = false;
    // Implementacion
    //use el i < t.size() * t[0].size() como para tener un numero finito de iteraciones, no estoy seguro de si es eso
    // o 2^t.size() * t[0].size() (por cada posicion puede ser T o F) pero me parecia demasiado y para los toroides que dan sirve la cota chica
    for (int i = 1; i < t.size() * t[0].size(); ++i) {
        if (sonIguales(t, evolucionMultiple(t, i))) {
            resp = true;
            p = i;
            break;
        }
    }

    return resp;
}


// EJERCICIO 10
bool primosLejanos(toroide const &t, toroide const &u) {
    bool resp = false;
    for (int i = 0; i < t.size() * t[0].size(); ++i) {
        if (t == evolucionMultiple(u, i)) {
            resp = true;
        }
    }
    // Implementacion
    return resp;
}

// EJERCICIO 11
int seleccionNatural(vector<toroide> ts) {
    int resp = -1;
    // Implementacion
    int ticks = 0;
    for (int i = 0; i < ts.size(); ++i) {
        if (esCiclico(ts[i])) {
            resp = i;
        } else {
            for (int j = 0; j < ts[i].size() * ts[i][0].size(); ++j) {
                if (toroideMuerto(evolucionMultiple(ts[i], j))) {
                    if (j > ticks) {
                        resp = i;
                        ticks = j;
                    }
                    break;
                }

            }
        }
    }
    return resp;
}


// EJERCICIO 12

toroide fusionar(toroide const &t, toroide const &u) {
    toroide out;
    toroide temp(t.size(), vector<bool>());

    // Implementacion
    for (int i = 0; i < t.size(); ++i) {
        for (int j = 0; j < t[i].size(); ++j) {
            temp[i].push_back(t[i][j] && u[i][j]);
        }
    }
    out = temp;
    return out;
}

// EJERCICIO 13
bool vistaTrasladada(toroide const &t, toroide const &u) {
    bool resp = false;
    toroide temp = copiarToroide(t);
    for (int i = 0; i < t.size(); ++i) {
        for (int j = 0; j < t[0].size(); ++j) {
            moverDerecha(temp);
            if (sonIguales(temp, u)) {
                resp = true;
                break;
            }
        }
        if (resp) {
            break;
        }
        moverAbajo(temp);
    }
    // Implementacion
    return resp;
}

// EJERCICIO 14
int menorSuperficieViva(toroide const &t) {
    int resp = -1;
    resp = t.size() * t[0].size();
    // Implementacion
    toroide temp = copiarToroide(t);
    for (int i = 0; i < t.size(); ++i) {
        for (int j = 0; j < t[0].size(); ++j) {
            moverDerecha(temp);
            vector<posicion> posVivas = posicionesVivas(temp);
            int rect = menorRectanguloVivo(posVivas);
            if (resp > rect) {
                resp = rect;
            }
        }
        moverAbajo(temp);
    }
    return resp;
}