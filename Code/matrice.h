/**
 *	Dumoulin Mehdi & Zigabe Jos
 *	Projet 1 Systeme informatique 2
 *
 *	Fichier contente l'en-tete des methodes relatives aux matrices
 **/

#ifndef __MATRICE__
#define __MATRICE__

#include <stdio.h>
#include <stdlib.h>
#include "buffer.h"


/*
 Structure representant un nombre dans une matrice
*/
struct bit_t{
    int rPos,cPos,val;
	struct bit_t *b_next, *b_prev;
};
typedef struct bit_t bit_t;
	


/*
 Structure representant une matrice
*/
struct row_t{
    struct row_t *r_next, *r_prev;
    bit_t *r_head, *r_tail;
};
typedef struct row_t row_t;

typedef struct{
    int nr_col, nr_row;
    row_t *m_head, *m_tail;
}matrix_t;




typedef struct{
	int row, col;
	bit_t *first;
}matrix;


/*
 Methode qui initialise une matrice
 @post : une matrice alloué est renvoyé et contient le nombre de colonne et de ligne
*/
matrix_t* matrix_alloc(int col, int row);


/*
 Methode qui free une matrice
 @pre : m != NULL
 @post : m est free
*/
void matrix_free(matrix_t* m);

void row_free(row_t* row);
/*
 Methode qui free un element d'une matrice
 @pre : e != null
 @post : elem est free
*/
void elem_free(bit_t* e);


/*
 Methode qui affiche sur l'ecran une matrice
 @pre : m != null
 @post : m est affiche e l'ecran
*/
void matrix_print(matrix* m);


/*
 Ajout d'un element dans une matrice a une position donnee
 @pre : m != null
 @post : val est ajoute dans m avec sa position
*/
void matrix_set(bit_t *row_list, int row, int col);


/*
 Multiplication entre deux matrices
 @pre : a != null, b != null
 @post : renvoie du pointeur de la solution de la multiplication entre la matrice a et b
*/
matrix* matrix_mult(matrix* a, matrix* b);


/*
 Obtention d'un element a une position donnee
 @pre : e != null
 @post : renvoie de la valeur de la matrice a la position donne
*/
int get(bit_t *e, int col, int row);


/*
 Donne l'élément en i,j en connaissant le prochain élément 
 @pre : current != null
 @post : renvoie l'elemen demandee
*/
int matrix_get(bit_t* current,int i, int j);

row_t* row_alloc(void);

void row_prepend(row_t *r, int cpos, int rpos);
void matrix_prepend(matrix_t *m);

#endif
