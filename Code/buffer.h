/**
 *	Dumoulin Mehdi 45570900 et Huberlant Alexis 54701000
 *	Projet 1 Systeme informatique 2
 *
 *	Fichier contenant la structure du buffer ainsi que de ses cellules
 *	et l'entete des methodes relative a son utilisation
 **/

#ifndef __BUFFER__
#define __BUFFER__


#include "matrice.h"
#include <stdlib.h>
#include <stdio.h>


/*
 Structure représentant une cellule du buffer avec un pointeur vers la cellule 
 suivante, la matrice.
*/
struct node{
	struct matrix_t *val;
	struct node* next;
};

/*
 Structure representant le buffer, elle contient 2 pointeurs pointant vers le
 premier et le dernier element du buffer ainsi qu'un pointeur vers l'element 
 courant et la taille du buffer.
*/
typedef struct{
	struct node *first;
	struct node *last;
	struct node *current;
	int size;
}buffer;


/*
 Methode qui initialise et renvoie un buffer.
 @post : un pointeur vers un buffer initialise est renvoye.
*/
buffer* buffer_init();


/*
 Methode qui insert une cellule a la fin du buffer
 @pre : buf != NULL
 @post :new est rajoute a la fin de buf
*/
void enqueue(buffer *buf, struct node *new);


/*
 Renvoie et supprime le premier element du buffer
 @pre : buf != NULL et current->size > 0
 @post : la matrice du premier element de buf est renvoye
*/
struct matrix_t *dequeue(buffer *buf);


/*
 Methode qui "free" le buffer.
 @pre : buf != NULL.
 @post : buf et ses eventuels elements sont liberes.
*/
void buffer_free(buffer *buf);

/*
 Methode qui initialise et renvoie une node.
 @post : un pointeur vers une cellule initialisee est renvoye et la matrice
	en parametre est ajoute a celle-ci.
*/
struct node *node_init(struct matrix_t *matrix);


/*
 Methode qui "free" la node
 @pre : node != NULL
 @post : la node est libere mais pas sa matrice
*/
void node_free(struct node *node);


/*
 Methode qui free une cellule et sa matrice
 @pre : node != NULL
 @post : la cellule et sa matrice sont libere
*/
void node_matrix_free(struct node *node);

#endif
