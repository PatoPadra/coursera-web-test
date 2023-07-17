#include "../definiciones.h"
#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
# include <utility>

using namespace std;

TEST(ejecutarSecuenciaForzadaTEST, secuenciaForzada) {
	tablero t = {	// Figura 5 del enunciado del TPE
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cPEON_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cREY_N},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cTORRE_B, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cTORRE_B},
    };
    posicion p = make_pair(t, BLANCO);
    secuencia s = {
    	make_pair(make_pair(6,3),make_pair(6,6)), make_pair(make_pair(4,7),make_pair(3,7)),
    	make_pair(make_pair(3,7),make_pair(2,7)), make_pair(make_pair(1,2),make_pair(0,2))
    };

    tablero t_fin = {	
            {cVACIA, cVACIA, cTORRE_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cREY_N},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_B, cVACIA},
            {cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cTORRE_B},
    };
    posicion p_fin = make_pair(t_fin, BLANCO);

    ejecutarSecuenciaForzada(p, s);
    EXPECT_EQ(p_fin, p);
}


TEST(ejecutarSecuenciaForzadaTEST, sec1){
    tablero t = {
            {cVACIA, cVACIA, cVACIA, cVACIA, cREY_N, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cPEON_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cPEON_B, cVACIA, cVACIA, cPEON_B, cTORRE_B},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cALFIL_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B, cALFIL_B},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B, cPEON_B, cPEON_B, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t, BLANCO);
    secuencia s = {
            make_pair(make_pair(2,3),make_pair(1,3)), make_pair(make_pair(1,3),make_pair(0,3)),
            make_pair(make_pair(1,2),make_pair(0,2)), make_pair(make_pair(4,0),make_pair(6,2)),
            make_pair(make_pair(0,3),make_pair(1,3))
    };

    tablero t_fin = {
            {cVACIA, cVACIA, cTORRE_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cTORRE_B, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B, cREY_N},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B, cALFIL_B},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cALFIL_B, cVACIA, cPEON_B, cPEON_B, cPEON_B, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA},
    };
    posicion p_fin = make_pair(t_fin, BLANCO);

    ejecutarSecuenciaForzada(p, s);
    EXPECT_EQ(p_fin, p);
}



TEST(ejecutarSecuenciaForzadaTEST, test2){
    tablero t = {
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cALFIL_N},
            {cVACIA, cTORRE_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cALFIL_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B, cREY_N},
            {cPEON_N, cALFIL_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cREY_B, cPEON_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_N},
            {cVACIA, cVACIA, cPEON_B, cTORRE_N, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cTORRE_N, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t, NEGRO);
    secuencia s = {
            make_pair(make_pair(5,1),make_pair(6,2)), make_pair(make_pair(3,1),make_pair(4,2))
    };
    tablero t_fin = {
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cALFIL_N},
            {cVACIA, cTORRE_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B, cREY_N},
            {cPEON_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cALFIL_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_N},
            {cREY_B, cVACIA, cPEON_N, cTORRE_N, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cTORRE_N, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    posicion p_fin = make_pair(t_fin, NEGRO);

    ejecutarSecuenciaForzada(p, s);
    EXPECT_EQ(p_fin, p);
}


TEST(ejecutarSecuenciaForzadaTEST, unMovimiento){
    tablero t = {
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cREY_B},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_N, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cREY_N},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t, NEGRO);
    secuencia s = {
            make_pair(make_pair(2,7),make_pair(2,6))
    };
    tablero t_fin = {
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cREY_B, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_N, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cREY_N, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    posicion p_fin = make_pair(t_fin, NEGRO);

    ejecutarSecuenciaForzada(p, s);
    EXPECT_EQ(p_fin, p);
}