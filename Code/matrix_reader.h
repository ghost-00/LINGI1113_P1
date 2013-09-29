/**
 *	Dumoulin Mehdi 45570900 et Huberlant Alexis 54701000
 *	Projet 1 Systeme informatique 2
 *
 *	En-tete des methodes pour  lire dans un fichier
 **/
#ifndef __MATRIX_READER_H__
#define __MATRIX_READER_H__

#include <stdio.h>
#include <stdlib.h>

#include "matrice.h"

struct matrix_reader;
typedef struct matrix_reader matrix_reader_t;

matrix_reader_t * matrix_reader_init(const char *filename);

matrix * matrix_reader_next(matrix_reader_t *r,int a);

void
matrix_reader_free(matrix_reader_t *r);

#endif
