/**
 *	Dumoulin Mehdi 45570900 et Huberlant Alexis 54701000
 *	Projet 1 Systeme informatique 2
 *
 *	Fichier utilise pour lire les matrices dans un fichier
 **/
#include "matrix_reader.h"

struct matrix_reader {
	FILE *f;
};

matrix_reader_t* matrix_reader_init(const char *filename)
{
	matrix_reader_t * r;
	
	r = malloc(sizeof(*r));
	if (!r)	
		return NULL;

	r->f = fopen(filename, "r");
	if (!r->f) {
		perror("Unable to open file:");
		free(r);
		return NULL;
	}
		
	return r;	
}

matrix* matrix_reader_next(matrix_reader_t *r, int a)
{
	int n_lines, n_columns, val;
	int i, j;
	matrix *m;

	if (fscanf(r->f,"%dx%d\n", &n_lines, &n_columns) == EOF)
		return NULL;
	
	m = matrix_alloc(n_columns, n_lines);
	if(!m)
		return NULL;

	elem* temp= m->first;
		
	for (i = 0; i < n_lines; ++i) {
		for (j = 0; j < n_columns; ++j) {
			if (fscanf(r->f, "%d", &val) == EOF) {
				matrix_free(m);
				return NULL;
			}
			if((val!=0)||(a == 0)){
				matrix_set(temp, i, j, val);
				temp=temp->next;		
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
