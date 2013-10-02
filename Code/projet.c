/**
 *	Dumoulin Mehdi & Zigabe Jos
 *	Projet 1 Systeme informatique 2
 **/

#include "projet.h"
#include "matrix_reader.h"
#include "matrice.h"


node_t *
read_file(char * inputFile){
	
	matrix_reader_t *reader = matrix_reader_init(inputFile);
	node_t *n = node_init();
    matrix_t *m = NULL;
    while((m = matrix_reader_next(reader))!=NULL){
        matrix_prepend(n, m);
	}
    
    matrix_reader_free(reader);
	return n;
}
/*
 *FIN
 */

matrix* multiplicator(buffer* buf){
	struct node *newcurrent = buf->first;
	while(buf->size != 1){

//Recuperation des deux element courrant + lock de ces deux cellules
	struct node *one = buf->current;
	struct node *two = buf->current->next;
//Diminution de la taille du buffer et suppression de la cellule deux
	buf->size--;
	buf->current = newcurrent;
	one->next = two->next;


//Multiplication des deux matrices et mise de la solution dans one
	matrix *sol = matrix_mult(one->val, two->val);
	matrix *temp = one->val;
	one->val = sol;
//Liberation de l'ancienne matrice de one et de la cellule deux
	matrix_free(temp);
	node_matrix_free(two);

	}

	return dequeue(buf);
}

void matrix_writefile(matrix *sol,char *outFile){
	FILE* fichier = NULL;
	fichier = fopen(outFile, "w");
	if(fichier != NULL){
		if((fprintf(fichier, "%dx%d\n", sol->row, sol->col)) == -1){
			perror("error");
			exit(EXIT_FAILURE);
		}
		int i,j,a;
		bit_t* current=sol->first;
		for(i=0;i<sol->row;i++){
			for(j=0;j<sol->col;j++){
				a=matrix_get(current,i,j);
				if(a){
					//current=current->next;
				}
				if((fprintf(fichier,"%d ",a)) == -1) {
					perror("impossible d'ecrire dans le fichier");
					exit(EXIT_FAILURE);
				}
			}	
		fprintf(fichier,"\n");

		}
	}
	fclose(fichier);
}


