/**
 *	Dumoulin Mehdi 45570900 et Huberlant Alexis 54701000
 *	Projet 1 Systeme informatique 2
 **/

#ifndef __PROJET__
#define __PROJET__

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <sys/file.h>
#include <string.h>

#include "buffer.h"
#include "matrix_reader.h"
#include "matrice.h"

#define TRUE 1
#define FALSE 0

/*
 Methode qui lit dans un fichier et stocke les matrices dans un buffer
 @post : buffer est renvoye avec toutes les matrices
*/
buffer * lecture(char * name, int a);	


/*
 Methode qui multiplie entre elles toutes les matrices d'un buffer
 @pre : buf != null
 @post : renvoie d'une matrice qui contient la solution
*/
matrix* multiplicator(buffer* buf);


/*
 Methode qui ecrit une matrice dans un fichier
 @pre : sol != null
 @post : sol est ecrite dans le fichier avec le path outFile
*/
void matrix_writefile(matrix *sol,char *outFile);

#endif
