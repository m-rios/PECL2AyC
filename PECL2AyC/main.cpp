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

int main(int argc, const char * argv[]) {

    
    Parser parser = Parser(argv[1]);
    Tablero tablero = parser.get_tablero();
    
    //crear e inicializar tablero
    vector<vector<int>> tab;
    tab.resize(tablero.M);
    for (int i = 0; i < tablero.M; i++) {
        tab[i].resize(tablero.N);
        for (int j = 0; j < tablero.N; j++) {
            tab[i][j] = 0;
        }
    }
    
    vector<int> sol;
    algoritmo(tab, tablero.pistas, sol, tablero.K);
    cout << "claves:" << endl;
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << endl;
    }
    cout << "codigo: " << sol.size() << endl;
    return 0;
}

