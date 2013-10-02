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

matrix_reader_t* matrix_reader_init(const char *inputFile)
{
	matrix_reader_t * r;
	
	r = malloc(sizeof(*r));
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

matrix_t* matrix_reader_next(matrix_reader_t *reader, int o)
{
	int bit=0, i=0, j=0, col=0, row=0;
    matrix_t *m_list = NULL;
    
    if (reader==NULL)
        return NULL;
    
    if (fscanf(reader->f,"%dx%d\n", &row, &col) == EOF)
        return NULL;
    
    m_list = matrix_alloc(col, row);
    
    printf("%dx%d\n", m_list->nr_row, m_list->nr_col);
    
	for (i = 0; i < m_list->nr_row; ++i) {
        matrix_prepend(m_list);
        
        for (j = 0; j < m_list->nr_col; ++j) {
            
			if (fscanf(reader->f, "%d", &bit) == EOF) {
				free(m_list);
				return NULL;
			}
			if(bit!=0){
                row_prepend(m_list->m_tail, j, i);
                printf("%d ", m_list->m_tail->r_tail->val);
            }
            else{
                printf("%d ", bit);
            }
		}
        printf("\n");
	}
	return NULL;
}

void
matrix_reader_free(matrix_reader_t *r)
{
	fclose(r->f);
	free(r);
}
