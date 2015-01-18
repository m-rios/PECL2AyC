//
//  casilla.h
//  PECL2AyC
//
//  Created by Mario on 18/01/15.
//  Copyright (c) 2015 Mario. All rights reserved.
//

#ifndef __PECL2AyC__casilla__
#define __PECL2AyC__casilla__

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

class casilla {

    int adj;
    int f, c;
    //vecinos
    vector<casilla *> vecinos;
    
public:
    int valor;
    casilla(int f, int c);
    casilla();
    casilla(int f, int c, vector<vector<casilla>> input);
    int get_adj();
    void set_value(int n);
    void init_vecinos(vector<vector<casilla>> input);
    void print_vecinos();
};

#endif /* defined(__PECL2AyC__casilla__) */
