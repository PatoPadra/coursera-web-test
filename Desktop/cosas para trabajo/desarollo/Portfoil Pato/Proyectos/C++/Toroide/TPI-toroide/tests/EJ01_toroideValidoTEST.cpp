#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(toroideValidoTEST, toroideVacio){
    toroide t = { vector<bool> () };
    EXPECT_FALSE(toroideValido(t));
}

TEST(toroideValidoTEST, toroideVacio5Filas){
    vector<bool> vacio;
    toroide t = { vacio, vacio, vacio, vacio, vacio };
    EXPECT_FALSE(toroideValido(t));
}

TEST(toroideValidoTEST, diagonalTresPorTres) {
    toroide t = { {true, false, false},
                  {false, true, false},
                  {false, false, true}
    };
    EXPECT_TRUE(toroideValido(t));
}

//tests propios implementados
TEST(toroideInvalidoTEST, cuadrado){
    toroide t = {
            {true, false, false, false },   // 1
            {false, false, false }, // 2
            {false, false, false }, // 3
            {true, true, false}};  // 4

    EXPECT_FALSE(toroideValido(t));
}

TEST(toroideVacioTEST, cuadrado){
    toroide t = {
            };   // 1

    EXPECT_FALSE(toroideValido(t));
}