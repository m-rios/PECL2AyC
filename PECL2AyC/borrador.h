//
//  borrador.h
//  PECL2AyC
//
//  Created by Mario on 16/01/15.
//  Copyright (c) 2015 Mario. All rights reserved.
//

#ifndef __PECL2AyC__borrador__
#define __PECL2AyC__borrador__

#include <stdio.h>
#include <vector>
#include <iostream>
#include "casilla.h"
#include <map>
using namespace std;

void algoritmo(vector<vector<casilla>> &tab, vector<int> pistas, vector<int> &sol, map<int, int> & sol_par,vector<vecino> &vecinos, int rest);
bool sol_valida(vector<vector<casilla>> input);
void print(vector<vector<casilla>> input);
int handle_sol(vector<vector<casilla>> tab, vector<int> &sol);
void update_adj(vector<vector<casilla>> & tab, vector<vecino> &vecinos);
void update_legal(vector<vector<casilla>> & tab, vector<vecino> &vecinos);
void undo_legal(vector<vector<casilla>> & tab, vector<vecino> &vecinos);
void undo_adj(vector<vector<casilla>> & tab, vector<vecino> &vecinos, int i, int j);
int get_estado(vector<vector<casilla>> tab);
void my_copy(vector<vector<casilla>> &destination, vector<vector<casilla>> source);


#endif /* defined(__PECL2AyC__borrador__) */
