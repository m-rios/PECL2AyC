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
    int c = 0;
    for (int i = 0; i < tablero.M; i++) {
        tab[i].resize(tablero.N);
        for (int j = 0; j < tablero.N; j++) {
            tab[i][j] = casilla(i, j);
            tab[i][j].set_value(c);
            c++;
        }
    }
    cout << "vecinos: " << endl;
    for (int i = 0; i < tablero.M; i++) {
        for (int j = 0; j < tablero.N; j++) {
            tab[i][j].init_vecinos(tab);
            tab[i][j].print_vecinos();
        }
    }
    
    cout << "hola" << endl;
    /*
    vector<int> sol;
    algoritmo(tab, tablero.pistas, sol, tablero.K);
    cout << "claves:" << endl;
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << endl;
    }
    cout << "codigo: " << sol.size() << endl;
    */
    return 0;
}

