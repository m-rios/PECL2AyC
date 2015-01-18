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
        vecinos[6] =  & input[f+1][c];
    }
    if ((f+1<input[f].size())&&(c+1<input[f].size())) {
        vecinos[7] =  & input[f+1][c+1];
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
void casilla::update()
{
    for (int i = 0; i < 8; i++) {
        if (vecinos[i]!=NULL) {
            vecinos[i]->calc_adj();
        }
    }
}

void casilla::calc_adj()
{
    adj = 0;
    for (int i = 0; i < 8; i++) {
        if (vecinos[i]!=NULL) {
            if (vecinos[i]->valor > 0) {
                adj++;
            }
        }
    }
    if (adj == valor) {
        for (int i = 0; i < 8; i++) {
            if (vecinos[i]!=NULL) {
                if (vecinos[i]->valor == 0) {
                    vecinos[i]->valor = -1;
                }
            }
        }
    }
}

int casilla::get_adj()
{
    return this->adj;
}