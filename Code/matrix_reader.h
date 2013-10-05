/**
 *	Dumoulin Mehdi & Zigabe Jos
 *	Projet 1 Multiplication de matrices creuses
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

matrix_reader_t *
matrix_reader_init(const char *filename);

matrix_t*
matrix_reader_next(matrix_reader_t *r);

void
matrix_reader_free(matrix_reader_t *r);
#endif
