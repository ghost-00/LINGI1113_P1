/**
 *	Dumoulin Mehdi 45570900 et Huberlant Alexis 54701000
 *	Projet 1 Systeme informatique 2
 *
 *	Fichier contente l'en-tete des methodes relatives aux matrices
 **/

#ifndef __MATRICE__
#define __MATRICE__

#include <stdio.h>
#include <stdlib.h>


/*
 Structure representant un nombre dans une matrice
*/
typedef struct elemt{
	int rPos,cPos,val;
	struct elemt* next;
}elem;

/*
 Structure representant une matrice
*/
typedef struct{
	int row, col;
	elem *first;
}matrix;


/*
 Methode qui initialise une matrice
 @post : une matrice alloué est renvoyé et contient le nombre de colonne et de ligne
*/
matrix* matrix_alloc(int col, int row);


/*
 Methode qui free une matrice
 @pre : m != NULL
 @post : m est free
*/
void matrix_free(matrix* m);


/*
 Methode qui free un element d'une matrice
 @pre : e != null
 @post : elem est free
*/
void elem_free(elem* e);


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
void matrix_set(elem* m, int row, int col,int val);


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
int get(elem *e, int col, int row);


/*
 Donne l'élément en i,j en connaissant le prochain élément 
 @pre : current != null
 @post : renvoie l'elemen demandee
*/
int matrix_get(elem* current,int i, int j);


#endif
