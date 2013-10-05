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

matrix_t*
multiplicator(node_t* buf){
    
    matrix_t *m_one = buf->n_head; /*On récupère la 1er matrice*/
	matrix_t *m_temp = buf->n_head->m_next; /*on récupére la seconde matrice*/
    
    while(m_temp!=NULL){
        m_one = matrix_mul(m_one, m_temp);
        m_temp= m_temp->m_next;
	}
	return m_one;
}
/*
 *FIN
 */

/*
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
 */

