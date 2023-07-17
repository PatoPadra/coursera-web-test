#include "gtest/gtest.h"
#include "../auxiliares.h"

using namespace std;



TEST(cantindadVivasTEST, hayVivos){
    toroide t = {
            {true, false, false, true },   // 1
            {false, false, false, true }, // 2
            {false, false, false, false }, // 3
            {true, true, false, true}};  // 4

   // EXPECT_EQ(res,)
}

TEST(cantindadVivasTEST, noHayVivos){
    toroide t = {
            {false, false, false, false },   // 1
            {false, false, false, false }, // 2
            {false, false, false, false }, // 3
            {false, false, false, false}};  // 4

  //  EXPECT_EQ(res,)
}