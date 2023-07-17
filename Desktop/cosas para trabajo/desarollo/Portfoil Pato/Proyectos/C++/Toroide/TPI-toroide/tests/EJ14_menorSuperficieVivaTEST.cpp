#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(menorSuperficieVivaTEST, enunciado){
    toroide t = {
            {true, false, false, true},   // 1
            {false, false, false, false}, // 2
            {false, false, false, false}, // 3
            {true, true, false, false}};  // 4

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 6);
}

//tests propios
TEST(menorSuperficieViva2TEST, enunciado){
    toroide t = {
            {false, true, false, false},//1
            {true, false, false, true},   // 2
            {false, false, false, false}, // 3
            {false, true, false, false}};  // 4

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 9);
}

TEST(menorSuperficieMuerto2TEST, enunciado){
    toroide t = {
            {false, false, false, false},//1
            {false, false, false, false},   // 2
            {false, false, false, false}, // 3
            {false, false, false, false}};  // 4

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 0);
}