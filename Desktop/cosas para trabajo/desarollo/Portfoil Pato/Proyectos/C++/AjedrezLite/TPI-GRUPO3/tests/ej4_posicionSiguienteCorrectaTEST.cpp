#include "../definiciones.h"
#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
# include <utility>

using namespace std;

TEST(posicionSiguienteCorrectaTEST, adelantoPeon) {
    tablero t_p = {
            {cTORRE_N, cVACIA,  cALFIL_N, cVACIA,  cREY_N,  cALFIL_N, cVACIA,  cTORRE_N},
            {cPEON_N,  cPEON_N, cPEON_N,  cPEON_N, cPEON_N, cPEON_N,  cPEON_N, cPEON_N},
            {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cPEON_B,  cPEON_B, cPEON_B,  cPEON_B, cPEON_B, cPEON_B,  cPEON_B, cPEON_B},
            {cTORRE_B, cVACIA,  cALFIL_B, cVACIA,  cREY_B,  cALFIL_B, cVACIA,  cTORRE_B},
    };

    tablero t_q = {
            {cTORRE_N, cVACIA,  cALFIL_N, cVACIA,  cREY_N,  cALFIL_N, cVACIA,  cTORRE_N},
            {cPEON_N,  cPEON_N, cPEON_N,  cPEON_N, cPEON_N, cPEON_N,  cPEON_N, cPEON_N},
            {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cVACIA,   cVACIA,  cPEON_B,  cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cPEON_B,  cPEON_B, cVACIA,   cPEON_B, cPEON_B, cPEON_B,  cPEON_B, cPEON_B},
            {cTORRE_B, cVACIA,  cALFIL_B, cVACIA,  cREY_B,  cALFIL_B, cVACIA,  cTORRE_B},
    };

    posicion p = make_pair(t_p, BLANCO);
    posicion q = make_pair(t_q, NEGRO);

    coordenada o = setCoord(6, 2);
    coordenada d = setCoord(5, 2);

    EXPECT_TRUE(posicionSiguienteCorrecta(p, q, o, d));
}

TEST(posicionSiguienteCorrectaTEST, peonHaceSaltoDelTigre){
    tablero t_p = {
            {cTORRE_N,  cVACIA,     cALFIL_N,   cVACIA,     cREY_N,     cALFIL_N,   cVACIA,     cTORRE_N},
            {cPEON_N,   cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cPEON_B,   cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B},
            {cTORRE_B,  cVACIA,     cALFIL_B,   cVACIA,     cREY_B,     cALFIL_B,   cVACIA,     cTORRE_B},
    };

    tablero t_q = {
            {cTORRE_N,  cVACIA,     cALFIL_N,   cVACIA,     cREY_N,     cALFIL_N,   cVACIA,     cTORRE_N},
            {cPEON_N,   cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N},
            {cVACIA,    cVACIA,     cPEON_B,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cPEON_B,   cPEON_B,    cVACIA,     cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B},
            {cTORRE_B,  cVACIA,     cALFIL_B,   cVACIA,     cREY_B,     cALFIL_B,   cVACIA,     cTORRE_B},
    };

    posicion p = make_pair(t_p,BLANCO);
    posicion q = make_pair(t_q,NEGRO);

    coordenada o = setCoord(6,2);
    coordenada d = setCoord(2,2);

    EXPECT_FALSE(posicionSiguienteCorrecta(p, q, o, d));
}


TEST(posicionSiguienteCorrectaTEST, coronadoPeon) {
    tablero t_p = {
            {cVACIA, cVACIA,  cVACIA, cVACIA,  cREY_N,  cALFIL_N, cVACIA,  cTORRE_N},
            {cVACIA,  cPEON_B, cVACIA,  cPEON_N, cPEON_N, cPEON_N,  cPEON_N, cPEON_N},
            {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cPEON_B,  cVACIA, cVACIA,  cPEON_B, cPEON_B, cPEON_B,  cPEON_B, cPEON_B},
            {cTORRE_B, cVACIA,  cALFIL_B, cVACIA,  cREY_B,  cALFIL_B, cVACIA,  cTORRE_B},
                };

            tablero t_q = {
                    {cVACIA, cTORRE_B,  cVACIA, cVACIA,  cREY_N,  cALFIL_N, cVACIA,  cTORRE_N},
                    {cVACIA,  cVACIA, cVACIA,  cPEON_N, cPEON_N, cPEON_N,  cPEON_N, cPEON_N},
                    {cVACIA,   cVACIA,  cVACIA,  cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
                    {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
                    {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
                    {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
                    {cPEON_B,  cVACIA, cVACIA,   cPEON_B, cPEON_B, cPEON_B,  cPEON_B, cPEON_B},
                    {cTORRE_B, cVACIA,  cALFIL_B, cVACIA,  cREY_B,  cALFIL_B, cVACIA,  cTORRE_B},
                };

            posicion p = make_pair(t_p, BLANCO);
            posicion q = make_pair(t_q, NEGRO);

            coordenada o = setCoord(1, 1);
            coordenada d = setCoord(0, 1);

            EXPECT_TRUE(posicionSiguienteCorrecta(p, q, o, d));

    }

TEST(posicionSiguienteCorrectaTEST, hayUnaCoordenadaDistinta) {
    tablero t_p = {
            {cTORRE_N, cVACIA,  cALFIL_N, cVACIA,  cREY_N,  cALFIL_N, cVACIA,  cTORRE_N},
            {cPEON_N,  cPEON_N, cPEON_N,  cPEON_N, cPEON_N, cPEON_N,  cPEON_N, cPEON_N},
            {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cPEON_B,  cPEON_B, cPEON_B,  cPEON_B, cPEON_B, cPEON_B,  cPEON_B, cPEON_B},
            {cTORRE_B, cVACIA,  cALFIL_B, cVACIA,  cREY_B,  cALFIL_B, cVACIA,  cTORRE_B},
    };

    tablero t_q = {
            {cTORRE_N, cVACIA,  cALFIL_N, cVACIA,  cREY_N,  cALFIL_N, cVACIA,  cTORRE_N},
            {cPEON_N,  cPEON_N, cPEON_N,  cPEON_N, cPEON_N, cPEON_N,  cPEON_N, cPEON_N},
            {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cVACIA,   cVACIA,  cVACIA,  cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cPEON_B,  cPEON_B, cPEON_N,   cPEON_B, cPEON_B, cPEON_B,  cPEON_B, cPEON_B},
            {cVACIA, cTORRE_B,  cALFIL_B, cVACIA,  cREY_B,  cALFIL_B, cVACIA,  cTORRE_B},
    };

    posicion p = make_pair(t_p, BLANCO);
    posicion q = make_pair(t_q, NEGRO);

    coordenada o = setCoord(7, 0);
    coordenada d = setCoord(7, 1);

    EXPECT_FALSE(posicionSiguienteCorrecta(p, q, o, d));
}

TEST(posicionSiguienteCorrectaTEST, origenNoVacio) {
    tablero t_p = {
            {cTORRE_N, cVACIA,  cALFIL_N, cVACIA,  cREY_N,  cALFIL_N, cVACIA,  cTORRE_N},
            {cPEON_N,  cPEON_N, cPEON_N,  cPEON_N, cPEON_N, cPEON_N,  cPEON_N, cPEON_N},
            {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cPEON_B,  cVACIA},
            {cPEON_B,  cPEON_B, cPEON_B,  cPEON_B, cPEON_B, cPEON_B,  cVACIA, cPEON_B},
            {cTORRE_B, cVACIA,  cALFIL_B, cVACIA,  cREY_B,  cALFIL_B, cVACIA,  cTORRE_B},
    };

    tablero t_q = {
            {cTORRE_N, cVACIA,  cALFIL_N, cVACIA,  cREY_N,  cALFIL_N, cVACIA,  cTORRE_N},
            {cPEON_N,  cPEON_N, cPEON_N,  cPEON_N, cPEON_N, cPEON_N,  cPEON_N, cPEON_N},
            {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cVACIA,   cVACIA,  cVACIA,  cVACIA,  cVACIA,  cVACIA,   cPEON_B,  cALFIL_B},
            {cPEON_B,  cPEON_B, cPEON_B,   cPEON_B, cPEON_B, cPEON_B,  cVACIA, cPEON_B},
            {cTORRE_B, cVACIA,  cALFIL_B, cVACIA,  cREY_B,  cTORRE_B, cVACIA,  cTORRE_B},
    };

    posicion p = make_pair(t_p, BLANCO);
    posicion q = make_pair(t_q, NEGRO);

    coordenada o = setCoord(7, 5);
    coordenada d = setCoord(5, 7);

    EXPECT_FALSE(posicionSiguienteCorrecta(p, q, o, d));
}



TEST(posicionSiguienteCorrectaTEST, peonesNoCoronados){
    tablero t_p = {
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cPEON_B, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cREY_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    tablero t_q = {
            {cVACIA, cVACIA, cVACIA, cPEON_B, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cREY_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
    };


    posicion p = make_pair(t_p, BLANCO);
    posicion q = make_pair(t_q, NEGRO);

    coordenada o = setCoord(1,3);
    coordenada d = setCoord(0,3);

    EXPECT_FALSE(posicionSiguienteCorrecta(p, q, o, d));
}


TEST(posicionSiguienteCorrectaTEST, destinoNoEsPeon) {
    tablero t_p = {
            {cTORRE_N, cVACIA,  cALFIL_N, cVACIA,  cREY_N,  cALFIL_N, cVACIA,  cTORRE_N},
            {cPEON_N,  cPEON_N, cPEON_N,  cPEON_N, cPEON_N, cPEON_N,  cPEON_N, cPEON_N},
            {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cPEON_B,  cPEON_B, cPEON_B,  cPEON_B, cPEON_B, cPEON_B,  cPEON_B, cPEON_B},
            {cTORRE_B, cVACIA,  cALFIL_B, cVACIA,  cREY_B,  cALFIL_B, cVACIA,  cTORRE_B},
    };

    tablero t_q = {
            {cTORRE_N, cVACIA,  cALFIL_N, cVACIA,  cREY_N,  cALFIL_N, cVACIA,  cTORRE_N},
            {cPEON_N,  cPEON_N, cPEON_N,  cPEON_N, cPEON_N, cPEON_N,  cPEON_N, cPEON_N},
            {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cVACIA,   cVACIA,  cTORRE_B,  cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
            {cPEON_B,  cPEON_B, cVACIA,   cPEON_B, cPEON_B, cPEON_B,  cPEON_B, cPEON_B},
            {cTORRE_B, cVACIA,  cALFIL_B, cVACIA,  cREY_B,  cALFIL_B, cVACIA,  cTORRE_B},
    };

    posicion p = make_pair(t_p, BLANCO);
    posicion q = make_pair(t_q, NEGRO);

    coordenada o = setCoord(6, 2);
    coordenada d = setCoord(5, 2);

    EXPECT_FALSE(posicionSiguienteCorrecta(p, q, o, d));
}


TEST(posicionSiguienteCorrectaTEST, destinoNoEsAlfil) {
tablero t_p = {
        {cTORRE_N, cVACIA,  cALFIL_N, cVACIA,  cREY_N,  cALFIL_N, cVACIA,  cTORRE_N},
        {cPEON_N,  cPEON_N, cPEON_N,  cPEON_N, cPEON_N, cPEON_N,  cPEON_N, cPEON_N},
        {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
        {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
        {cVACIA,   cPEON_B,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
        {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
        {cPEON_B,  cVACIA, cPEON_B,  cPEON_B, cPEON_B, cPEON_B,  cPEON_B, cPEON_B},
        {cTORRE_B, cVACIA,  cALFIL_B, cVACIA,  cREY_B,  cALFIL_B, cVACIA,  cTORRE_B},
};

tablero t_q = {
        {cTORRE_N, cVACIA,  cALFIL_N, cVACIA,  cREY_N,  cALFIL_N, cVACIA,  cTORRE_N},
        {cPEON_N,  cPEON_N, cPEON_N,  cPEON_N, cPEON_N, cPEON_N,  cPEON_N, cPEON_N},
        {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
        {cVACIA,   cVACIA,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
        {cVACIA,   cPEON_B,  cVACIA,   cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
        {cTORRE_N,   cVACIA,  cVACIA,  cVACIA,  cVACIA,  cVACIA,   cVACIA,  cVACIA},
        {cPEON_B,  cVACIA, cPEON_B,   cPEON_B, cPEON_B, cPEON_B,  cPEON_B, cPEON_B},
        {cTORRE_B, cVACIA,  cVACIA, cVACIA,  cREY_B,  cALFIL_B, cVACIA,  cTORRE_B},
};

posicion p = make_pair(t_p, BLANCO);
posicion q = make_pair(t_q, NEGRO);

coordenada o = setCoord(7, 2);
coordenada d = setCoord(5, 0);

EXPECT_FALSE(posicionSiguienteCorrecta(p, q, o, d));
}

TEST(posicionSiguienteCorrectaTEST, capturaPeonBlanco){
    tablero t_p = {
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cPEON_B, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_N, cVACIA, cVACIA},
            {cVACIA, cREY_N, cVACIA, cVACIA, cPEON_B, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    tablero t_q = {
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cPEON_B, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B, cVACIA, cVACIA},
            {cVACIA, cREY_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
    };


    posicion p = make_pair(t_p, BLANCO);
    posicion q = make_pair(t_q, NEGRO);

    coordenada o = setCoord(4,4);
    coordenada d = setCoord(3,5);

    EXPECT_TRUE(posicionSiguienteCorrecta(p, q, o, d));
}

TEST(posicionSiguienteCorrectaTEST, capturaPeonNegro){
    tablero t_p = {
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cPEON_B, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_N, cVACIA, cVACIA},
            {cVACIA, cREY_N, cVACIA, cVACIA, cPEON_B, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    tablero t_q = {
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cPEON_B, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cREY_N, cVACIA, cVACIA, cPEON_N, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
    };


    posicion p = make_pair(t_p, NEGRO);
    posicion q = make_pair(t_q, BLANCO);

    coordenada o = setCoord(3,5);
    coordenada d = setCoord(4,4);

    EXPECT_TRUE(posicionSiguienteCorrecta(p, q, o, d));
}

