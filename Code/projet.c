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
	node_t *n = node_init(); /*Initialisation du buffer qui contiendra les matrice extraite du fichier*/
    matrix_t *m = NULL;
    while((m = matrix_reader_next(reader))!=NULL)
    {/*Tant qu'il y aura une matrice à lire dans le fichier, on les rajoute dans notre buffer*/
        matrix_prepend(n, m);
        if (n->n_length == 2)
        {/*Si on a deux matrice dans notre buffer on effectue la multiplication*/
            matrix_prepend(n, multiplicator(n));/*Le résltat est directement placé dans le buffer*/
        }
	}
    matrix_reader_free(reader);
	return n;
}

matrix_t*
multiplicator(node_t* buf){
    
    matrix_t *m_one = buf->n_head; /*On récupère la 1er matrice*/
	matrix_t *m_two = buf->n_head->m_next; /*on récupére la seconde matrice*/
    
    m_one = matrix_mul(m_one, m_two);
    
    buf->n_head = NULL;
    buf->n_tail = NULL;
    buf->n_length = 0;
    
	return m_one;
}

void
matrix_writefile(matrix_t *result,char *outputFile){
    
    if (result!=NULL)
    {
        FILE* file = NULL;
        file = fopen(outputFile, "w");
        if(file != NULL){
            if((fprintf(file, "%dx%d\n", result->nr_row, result->nr_col)) == -1){
                perror("error");
                exit(EXIT_FAILURE);
            }
            
            int row=0,col=0,bit=0;
            row_t *r_temp = result->m_head;
            for (row=0; row < result->nr_row; row++)
            {
                bit_t *b_temp = r_temp->r_head;
                for (col=0; col < result->nr_col; col++)
                {
                    bit = bit_getnext(b_temp, row, col);
                    if (bit == 1) {
                        if((fprintf(file,"%d ",1)) == -1) {
                            perror("impossible d'ecrire dans le fichier");
                            exit(EXIT_FAILURE);
                        }
                        
                        if (b_temp->b_next!=NULL) {
                            b_temp = b_temp->b_next;
                        }
                    }else{
                        if((fprintf(file,"%d ",0)) == -1) {
                            perror("impossible d'ecrire dans le fichier");
                            exit(EXIT_FAILURE);
                        }
                    }
                }
                fprintf(file,"\n");
                r_temp = r_temp->r_next;
            }
        }
        fclose(file);
    }
}


