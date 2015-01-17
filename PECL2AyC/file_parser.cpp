#include "file_parser.h"

Parser::Parser(const char* path)
{
    ifstream file (path);
    string input ("\0");
    if (file.is_open()) {
        string tmp ("\0");
            
            //Primer comentario
        getline(file, tmp);

            //numero de Filas M
        getline(file, tmp);
        M = stoi(tmp);

            //numero de columnas N
        getline(file, tmp);
        N = stoi(tmp);

            //numero de pistas K
        getline(file, tmp);
        K = stoi(tmp);

            //comentario de las pistas
        getline(file,tmp);

            //iterar sobre el numero de las pistas
        for (int i = 0; i < K; ++i)
        {
            getline(file,tmp);
            pistas.push_back(stoi(tmp));
        }
    }
    else
        cout << "could not open file" << endl;
    
}

Tablero Parser::get_tablero()
{
    
    return Tablero(M,N,K,pistas);
}

Parser::~Parser()
{
    
}