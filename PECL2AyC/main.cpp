//
//  main.cpp
//  PECL2AyC
//
//  Created by Mario on 16/01/15.
//  Copyright (c) 2015 Mario. All rights reserved.
//

#include <iostream>
#include "borrador.h"
#include "file_parser.h"
#include "tablero.h"
#include "casilla.h"

int main(int argc, const char * argv[]) {

    
    Parser parser = Parser(argv[1]);
    Tablero tablero = parser.get_tablero();
    
    //crear e inicializar tablero
    vector<vector<casilla>> tab;
    tab.resize(tablero.M);
    for (int i = 0; i < tablero.M; i++) {
        tab[i].resize(tablero.N);
        for (int j = 0; j < tablero.N; j++) {
            tab[i][j].valor = 0;
        }
    }
    
    //crear vector de vecinos
    vector<vecino> vecinos;
    vecinos.resize(8);
    vecinos[0].inc_f = -1;  vecinos[0].inc_c = -1;
    vecinos[1].inc_f = -1;  vecinos[1].inc_c =  0;
    vecinos[2].inc_f = -1;  vecinos[2].inc_c = +1;
    vecinos[3].inc_f =  0;  vecinos[3].inc_c = -1;
    vecinos[4].inc_f =  0;  vecinos[4].inc_c = +1;
    vecinos[5].inc_f = +1;  vecinos[5].inc_c = -1;
    vecinos[6].inc_f = +1;  vecinos[6].inc_c =  0;
    vecinos[7].inc_f = +1;  vecinos[7].inc_c = +1;
    
    map<unsigned long long,int> sol;
    map<int, int> sol_par;
    algoritmo(tab, tablero.pistas, sol, sol_par, vecinos, tablero.K);
    cout << "claves:" << endl;
    for(auto it = sol.cbegin(); it != sol.cend(); ++it)
    {
        cout << it->first << endl;
    }
    cout << "codigo: " << sol.size() << endl;
    
    return 0;
}