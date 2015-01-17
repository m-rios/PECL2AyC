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
using namespace std;

void algoritmo(vector<vector<int>> &tab, vector<int> pistas, vector<int> &sol, int rest);
bool sol_valida(vector<vector<int>> input);
void print(vector<vector<int>> input);
void test(vector<int> &v);
bool handle_sol(vector<vector<int>> tab, vector<int> &sol);
#endif /* defined(__PECL2AyC__borrador__) */
