#include <iostream>
#include <vector>

using namespace std;


int coutNum(int clocks[]);
void mapping();
int switches[9][5] ={
    {0, 1, 2},
    {3,7,9, 11},
    {4,10,14,15},
    {0,4,5,6,7},
    {6,7,8,10,12},
    {0,2,14,15},
    {3,14,15},
    {1,2,3,4,5},
    {3,4,5,9,13}};
