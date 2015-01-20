//
//  borrador.cpp
//  PECL2AyC
//
//  Created by Mario on 16/01/15.
//  Copyright (c) 2015 Mario. All rights reserved.
//

#include "borrador.h"

void algoritmo(vector<vector<casilla>> &tab, vector<int> pistas, vector<int> &sol, map<int, int> & sol_par, vector<vecino> &vecinos, int rest)
{
    if (rest == 0) {
        if (sol_valida(tab)) {
            int nsol = handle_sol(tab, sol);
            if (nsol > 0) {
                print(tab);
                cout << nsol << " soluciones encontradas" << endl;
            }
        }
    }else{
        for (int f = 0; f < tab.size(); f++) {
            for (int c = 0; c < tab[f].size(); c++) {
                if (tab[f][c].valor == 0) {
                    vector<vector<casilla>> aux (tab);
                    tab[f][c].valor = pistas[pistas.size()-rest];
                    //si no es solucion repetida
                    if (sol_par.find(get_estado(tab)) == sol_par.end()) {
                        update_adj(tab, vecinos);
                        update_legal(tab, vecinos);
                        rest--;
                        algoritmo(tab, pistas, sol, sol_par, vecinos, rest);
                        rest++;
                        sol_par.insert(pair<int, int>(get_estado(tab),0));
                        //undo_adj(tab, vecinos, f, c);
                        //undo_legal(tab, vecinos);
                    }
                    my_copy(tab, aux);
                    //tab[f][c].valor = 0;
                }
            }
        }
    }
}

void my_copy(vector<vector<casilla>> &destination, vector<vector<casilla>> source)
{
    for (int i = 0; i < source.size(); i++) {
        for (int j = 0; j < source[i].size(); j++) {
            destination[i][j] = source[i][j];
        }
    }
}
int get_estado(vector<vector<casilla>> tab)
{
    int estado = 0;
    for (int i = 0; i < tab.size(); i++) {
        for (int j = 0; j < tab[i].size(); j++) {
            estado = estado*10+tab[i][j].valor;
        }
    }
    return estado;
}

void update_adj(vector<vector<casilla>> & tab, vector<vecino> &vecinos)
{
    for (int i = 0; i < tab.size(); i++) {
        for (int j = 0; j < tab[i].size(); j++) {
            tab[i][j].adj = 0;
            for (int v = 0; v < 8; v++) {
                if ((vecinos[v].inc_f+i >= 0) && (vecinos[v].inc_f+i < tab.size()) && (vecinos[v].inc_c+j>=0) && (vecinos[v].inc_c+j<tab[i].size())) {
                    if (tab[i+vecinos[v].inc_f][j+vecinos[v].inc_c].valor > 0) {
                        tab[i][j].adj++;
                    }
                }
            }
        }
    }
}

void update_legal(vector<vector<casilla>> & tab, vector<vecino> &vecinos)
{
    for (int i = 0; i < tab.size(); i++) {
        for (int j = 0; j < tab[i].size(); j++) {
            if (tab[i][j].valor > 0) {
                if (tab[i][j].adj == tab[i][j].valor) {
                    for (int v = 0; v < 8; v++) {
                        if ((vecinos[v].inc_f+i >= 0) && (vecinos[v].inc_f+i < tab.size()) && (vecinos[v].inc_c+j>=0) && (vecinos[v].inc_c+j<tab[i].size())) {
                            if (tab[i+vecinos[v].inc_f][j+vecinos[v].inc_c].valor == 0) {
                                tab[i+vecinos[v].inc_f][j+vecinos[v].inc_c].valor = -1;
                            }
                        }
                    }
                }
            }
        }
    }
}
void undo_adj(vector<vector<casilla>> & tab, vector<vecino> &vecinos, int i, int j)
{
    for (int v = 0; v < 8; v++) {
        if ((vecinos[v].inc_f+i >= 0) && (vecinos[v].inc_f+i < tab.size()) && (vecinos[v].inc_c+j>=0) && (vecinos[v].inc_c+j<tab[i].size())) {
            if (tab[i+vecinos[v].inc_f][j+vecinos[v].inc_c].adj > 0) {
                tab[i+vecinos[v].inc_f][j+vecinos[v].inc_c].adj--;
            }
        }
    }
}

void undo_legal(vector<vector<casilla>> & tab, vector<vecino> &vecinos)
{
    for (int i = 0; i < tab.size(); i++) {
        for (int j = 0; j < tab[i].size(); j++) {
            if (tab[i][j].valor > -1) {
                if (tab[i][j].adj < tab[i][j].valor) {
                    for (int v = 0; v < 8; v++) {
                        if ((vecinos[v].inc_f+i >= 0) && (vecinos[v].inc_f+i < tab.size()) && (vecinos[v].inc_c+j>=0) && (vecinos[v].inc_c+j<tab[i].size())) {
                            if (tab[i+vecinos[v].inc_f][j+vecinos[v].inc_c].valor < 0 ) {
                                tab[i+vecinos[v].inc_f][j+vecinos[v].inc_c].valor = 0;
                            }
                        }
                    }
                }
            }
        }
    }
}

bool sol_valida(vector<vector<casilla>> input)
{
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size(); j++) {
            if (input[i][j].valor > 0) {
                if (input[i][j].adj != input[i][j].valor) {
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

int handle_sol(vector<vector<casilla>> tab, vector<int> &sol)
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
        return 0;
    }
    sol.push_back(clave);
    return (int) sol.size();
}