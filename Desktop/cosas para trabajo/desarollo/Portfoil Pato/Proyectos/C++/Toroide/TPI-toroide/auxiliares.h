//


#ifndef REUNIONESREMOTAS_AUXILIARES_H
#define REUNIONESREMOTAS_AUXILIARES_H

#include "definiciones.h"

using namespace std;
bool esRectangulo(const vector<vector<bool>> &t);
// definir aqui las funciones
toroide copiarToroide (const toroide &t);
bool sonIguales (toroide const &t1, toroide const &t2);
bool esCiclico(toroide const &t);
void moverDerecha (toroide &t);
void moverAbajo (toroide &t);
int menorRectanguloVivo (vector<posicion> posicionesVivas);
pair<int,int> mp(int a, int b);
vector<posicion> ordenar(vector<posicion> &v);

#endif //REUNIONESREMOTAS_AUXILIARES_H