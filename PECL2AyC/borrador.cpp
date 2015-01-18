//
//  borrador.cpp
//  PECL2AyC
//
//  Created by Mario on 16/01/15.
//  Copyright (c) 2015 Mario. All rights reserved.
//

#include "borrador.h"

void algoritmo(vector<vector<casilla>> &tab, vector<int> pistas, vector<int> &sol, int rest)
{
    if (rest == 0) {
        if (sol_valida(tab)) {
            if (handle_sol(tab,sol)) {
                print(tab);
            }
        }
    }else{
        for (int f = 0; f < tab.size(); f++) {
            for (int c = 0; c < tab[f].size(); c++) {
                if (tab[f][c].valor == 0) {
                    tab[f][c].valor = pistas[pistas.size()-rest];
                    tab[f][c].update();
                    rest--;
                    algoritmo(tab, pistas, sol, rest);
                    rest++;
                    tab[f][c].valor = 0;
                }
            }
        }
    }
}

bool sol_valida(vector<vector<casilla>> input)
{
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size(); j++) {
            if (input[i][j].valor != 0) {
                if (input[i][j].get_adj() != input[i][j].valor) {
                    return false;
                }
            }
        }
    }
    return true;
}

void print(vector<vector<casilla>> input)
{
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size(); j++) {
            cout << input[i][j].valor;
        }
        cout << endl;
    }
    cout << "___" << endl;
}

void test(vector<int> &v)
{
    v[2] = -1;
}

bool handle_sol(vector<vector<casilla>> tab, vector<int> &sol)
{
    int clave = 0;
    for (int i = 0; i < tab.size(); i++) {
        for (int j = 0; j < tab[i].size(); j++) {
            if (tab[i][j].valor > 0) {
                clave = clave*10+tab[i][j].valor;
            }
        }
    }
    if (find(sol.begin(), sol.end(), clave) != sol.end()) {
        return false;
    }
    sol.push_back(clave);
    return true;
}