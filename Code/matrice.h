/**
 *	Dumoulin Mehdi & Zigabe Jos
 *	Projet 1 Multiplication de matrices creuses
 *
 *	Fichier contente l'en-tete des methodes relatives aux matrices
 **/

#ifndef __MATRICE__
#define __MATRICE__

#include <stdio.h>
#include <stdlib.h>
#include "buffer.h"


/*
 *Structure representant un bit dans une matrice
 */
struct bit_t{
    int rPos,cPos,val;
	struct bit_t *b_next, *b_prev;
};
typedef struct bit_t bit_t;
/*
 *Structure representant les lignes des matrices
 */
struct row_t{
    int r_length, c_length;
    struct row_t *r_next, *r_prev;
    bit_t *r_head, *r_tail;
};
typedef struct row_t row_t;
/*
 *Structure représentant les matrices
 */
struct matrix_t{
    int nr_col, nr_row;
    struct matrix_t *m_next, *m_prev;
    row_t *m_head, *m_tail;
};
typedef struct matrix_t matrix_t;
/*
 *Structure qui représente la liste contenant toutes les matrices
 */
typedef struct{
    int n_length;
    matrix_t *n_head, *n_tail;
}node_t;

/*
 Methode qui initialise une liste
 @post : une structure node_t alloué est renvoyé avec length initialisé à 0
 */
node_t*
node_init();
/*
 Methode qui initialise une matrice
 @post : une matrice alloué est renvoyé et contient le nombre de colonne et de ligne
 */
matrix_t*
matrix_alloc(int col, int row);
/*
 Methode qui initialise une ligne de la matrice
 @post : une structure row_t alloué est renvoyé
 */
row_t*
row_alloc(matrix_t *m);
/*
 Methode qui ajoute au debut de la liste r un bit dont les coordonnées sont donnée par cpos et rpos
 et qui aura en mémoire la position du prochain et du précédent bit de sa rangé
 @post : un bit est ajouté en debut de la liste r.
 */
void
bit_prepend(row_t *r, int cpos, int rpos);
/*
 Methode qui ajoute au debut de la liste m une ligne
 et qui aura en mémoire la position de la prochaine et de la précédente ligne de la matrice
 @post : une ligne est ajoutée en debut de la liste m.
 */
void
row_prepend(matrix_t *m);
/*
 Methode qui ajoute au debut de la liste n la matrice m
 et qui aura en mémoire la position de la prochaine et de la précédente matrice
 @post : une matrice est ajouté en debut de la liste n.
 */
void
matrix_prepend(node_t *n, matrix_t *m);
/*
 Obtention d'un bit a une position d'une ligne donnee
 @pre : b != null
 @post : renvoie de la valeur de la matrice a la position donne
 */
int
bit_getnext(bit_t *b, int col, int row);
/*
 Obtention de la m ieme matrice
 @pre : n != null
 @post : renvoie la matrice se trouvant à la position donnée
 */
matrix_t*
matrix_get(node_t* n, int m);
/*
 Obtention de la r ieme ligne d'une matrice
 @pre : m != null
 @post : renvoie la ligne se trouvant à la position donnée
 */
row_t*
row_get(matrix_t *m, int r);
/*
 Obtention de la c ieme colonne d'une matrice
 @pre : m != null
 @post : renvoie la colonne se trouvant à la position donnée
 */
row_t*
col_get(matrix_t *m, int c);
/*
 Methode qui affiche sur l'ecran une ligne r d'une matrice
 @pre : r != null
 @post : r est affiché à l'ecran
 */
void
row_print(row_t *r);
/*
 Methode qui affiche sur l'ecran une colonne c d'une matrice
 @pre : c != null
 @post : c est affiche à l'ecran
 */
void
col_print(row_t *c);
/*
 Methode qui affiche sur l'ecran une matrice
 @pre : m != null
 @post : m est affiche e l'ecran
 */
void
matrix_print(matrix_t *m);

 /************************************************************************************************/
 /*FIN de la structure, le reste est à arranger ou à refaire ou à retirer en fonction des besoins*/
 /************************************************************************************************/


typedef struct{
	int row, col;
	bit_t *first;
}matrix;
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
 Multiplication entre deux matrices
 @pre : a != null, b != null
 @post : renvoie du pointeur de la solution de la multiplication entre la matrice a et b
*/
matrix* matrix_mult(matrix* a, matrix* b);

#endif
