#ifndef __PECL1AyC__file_parser__
#define __PECL1AyC__file_parser__

#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "tablero.h"
using namespace std;

#define MAX_F 10

class Parser {
private:
    char* path;
    int M, N, K;
    vector<int> pistas;
    
public:
    Parser(const char* path);
    ~Parser();
    Tablero get_tablero();

};

#endif /* defined(__PECL1AyC__file_parser__) */
