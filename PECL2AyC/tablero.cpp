#include "tablero.h"


Tablero::Tablero(int M, int N, int K, vector<int> pistas)
{
    this->M = M;
    this->N = N;
    this->K = K;
    this->pistas = pistas;
}
Tablero::~Tablero(){}

void Tablero::print(){

    cout << "Filas: " << M << endl;
    cout << "Columnas: " << N << endl;
    cout << "Numero de pistas: " << K << endl;
    cout << "Pistas: ";
    for (int i = 0; i < K; ++i)
    {
        cout << "[" << pistas[i] << "]";
    }
    cout << endl;

}