#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(densidadPoblacionTEST, toroideDiagonal){
    vector<bool> a = { true, true, true, true };
    toroide t = { a, a, a, a, a };
    EXPECT_NEAR(densidadPoblacion(t), 1.0, 0.01);
}
//test propio
TEST(cantindadVivasTEST, hayVivos){
    toroide t = {
            {true, false, false, true },   // 1
            {false, false, false, true }, // 2
            {false, false, false, false }, // 3
            {true, true, false, true}};  // 4

     EXPECT_EQ(densidadPoblacion(t),6.0/16);
}