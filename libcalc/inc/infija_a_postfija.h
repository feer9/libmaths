#ifndef INFIJA_A_POSTFIJA_H
#define INFIJA_A_POSTFIJA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "libmaths.h"
#include "manejo_nodos.h"
#include "nodo.h"




int check_expr(const char *);
nodo* infijaAPostfija(const char *inf);
int esNum(char);
int esOp(char);
int esOp_(char);
double resolver_postfija(nodo**);
nodo* resolver(nodo* n1, nodo* n2, nodo** op);
void mostrar(nodo*);

#endif
