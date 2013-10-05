/**
 *	Dumoulin Mehdi & Zigabe Jos
 *	Projet 1 Multiplication de matrices creuses
 *
 *	Fichier utilise pour lire les matrices dans un fichier
 **/
#include "matrix_reader.h"

struct matrix_reader {
	FILE *f;
};

matrix_reader_t*
matrix_reader_init(const char *inputFile)
{
	matrix_reader_t * r;
	
	r = malloc(sizeof(*r)); /*Allocation mémoire*/
	if (!r)
		return NULL;
    
	r->f = fopen(inputFile, "r");
	if (!r->f) {
		perror("Unable to open file");
		free(r);
		return NULL;
	}
    
	return r;
}

matrix_t
*matrix_reader_next(matrix_reader_t *reader)
{
	int bit=0, i=0, j=0, col=0, row=0;
    
    if (fscanf(reader->f,"%dx%d\n", &row, &col) == EOF)
        return 0;
    
    matrix_t *m = matrix_alloc(col, row); /*Allocation mémoire*/
    
	for (i = 0; i < m->nr_row; ++i) {
        row_prepend(m); /*On ajoute la nouvelle ligne en début de la liste m*/
        for (j = 0; j < m->nr_col; ++j) {
            
			if (fscanf(reader->f, "%d", &bit) == EOF) {
				free(m);
				exit(EXIT_FAILURE);
			}
			if(bit!=0){
                /*On ajoute le nouveau bit en fin de la liste m->m_tail 
                 *qui est liste de type row_t
                 */
                bit_prepend(m->m_tail, j, i); 
            }
		}
	}
    return m;
}

void
matrix_reader_free(matrix_reader_t *r)
{
	fclose(r->f);
	free(r);
}
