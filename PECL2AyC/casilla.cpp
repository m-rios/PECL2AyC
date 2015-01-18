//
//  casilla.cpp
//  PECL2AyC
//
//  Created by Mario on 18/01/15.
//  Copyright (c) 2015 Mario. All rights reserved.
//

#include "casilla.h"

casilla::casilla(int f, int c)
{
    valor = 0;
    adj = 0;
    this->f = f;
    this->c = c;
    vecinos.resize(8);
}

casilla::casilla()
{
    
}

void casilla::init_vecinos(vector<vector<casilla>> input)
{
    /*
     int v = 0;
     for (int i = -1; i < 2; i++) {
     for (int j = -1; j < 2; j++) {
     if (!(i==0) && !(j==0)) {
     vecinos[v] = NULL;
     if ((c+j >= 0) && (c+j < input[f+i].size()) && (f+i >= 0) && (f+i < input.size())) {
     vecinos[v] = & input[f+i][c+j];
     }
     v++;
     }
     else if(!(i==0)){
     vecinos[v] = NULL;
     if ((f+i >= 0) && (f+i < input.size())) {
     vecinos[v] = & input[f+i][c+j];
     }
     v++;
     }
     else if (!(j==0)) {
     vecinos[v] = NULL;
     if ((c+j >= 0) && (c+j < input[f+i].size())) {
     vecinos[v] = & input[f+i][c+j];
     }
     v++;
     }
     }
     }
     */
    
    
    if ((f-1 > -1) &&(c-1 > -1)) {
        vecinos[0] =  & input[f-1][c-1];
    }
    if (f-1 > -1) {
        vecinos[1] =  & input[f-1][c];
    }
    if ((f-1 > -1)&&(c+1 < input[f].size())) {
        vecinos[2] =  & input[f-1][c+1];
    }
    if (c-1 > -1) {
        vecinos[3] =  & input[f][c-1];
    }
    if (c+1 < input[f].size()) {
        vecinos[4] =  & input[f][c+1];
    }
    if ((f+1 < input[f].size())&&(c-1>-1)) {
        vecinos[5] =  & input[f+1][c-1];
    }
    if (f+1<input[f].size()) {
        int n = input[f+1][c].valor;
        vecinos[6] =  & input[f+1][c];
    }
    if ((f+1<input[f].size())&&(c+1<input[f].size())) {
        vecinos[7] =  & input[f+1][c+1];
    }
}

casilla::casilla(int f, int c, vector<vector<casilla>> input)
{
    valor = 0;
    adj = 0;
    this->f = f;
    this->c = c;
    vecinos.resize(8);
    int v = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (!((i==0) && (j==0)) ) {
                vecinos[v] = NULL;
                if ((c+j > 0) && (c+j <= input[i].size()) && (f+i > 0) && (f+i <= input.size())) {
                    vecinos[v] = & input[i][j];
                }
                v++;
            }
        }
    }
}

void casilla::set_value(int n)
{
    this->valor = n;
}

void casilla::print_vecinos()
{
    for (int i = 0; i < 8; i++) {
        if (vecinos[i] != NULL) {
            cout << " " << vecinos[i]->valor << ",";
        }else{
            cout << "-1,";
        }
    }
    cout << endl;
}