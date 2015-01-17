#ifndef __PECL1AyC__tablero__
#define __PECL1AyC__tablero__


#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX_F 10


class Tablero {
public:
    int M,N,K;
    vector<int> pistas;
    Tablero(int M, int N, int K, vector<int> pistas);
    ~Tablero();
    void print();

};

#endif /* defined(__PECL1AyC__tablero__) */
