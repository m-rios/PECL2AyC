//
//  casilla.h
//  PECL2AyC
//
//  Created by Mario on 18/01/15.
//  Copyright (c) 2015 Mario. All rights reserved.
//

#ifndef __PECL2AyC__casilla__
#define __PECL2AyC__casilla__

#include <stdio.h>
using namespace std;

struct casilla {
    int valor;
    int adj;
};

struct vecino {
    short inc_f;
    short inc_c;
};

#endif /* defined(__PECL2AyC__casilla__) */
