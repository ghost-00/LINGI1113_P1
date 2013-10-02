/**
 *	Dumoulin Mehdi 45570900 et Huberlant Alexis 54701000
 *	Projet 1 Systeme informatique 2
 *
 *	Fichier implementant les methodes relatives au matrice
 **/

#include "matrice.h"

matrix_t* matrix_alloc(int col, int row){
	matrix_t *m;
	m = (matrix_t*)malloc(sizeof(matrix_t));
	if(!m)
	{
		exit(EXIT_FAILURE);
	}
    m->nr_col = col;
    m->nr_row = row;
    m->m_head = NULL;
    m->m_tail = NULL;
    return m;
}

row_t* row_alloc(void){
    row_t *r_new = malloc(sizeof (row_t));
    if (r_new != NULL)
    {
        r_new->r_head = NULL;
        r_new->r_tail = NULL;
    }
    return r_new;
}
void matrix_free(matrix_t* m){
	free(m);
}
void row_free(row_t* row){
    free(row);
}


void bit_t_free(bit_t* e){
	free(e);
}


void matrix_print(matrix* m)
{
	int i,j,a;
	bit_t* current=m->first;
	for(i=0;i<m->row;i++)
	{
		for(j=0;j<m->col;j++)
		{
			a=matrix_get(current,i,j);
			if(a)
			{
				//current=current->next;
			}
			printf("%d ",a);
		}
		printf("\n");
	}
}


int matrix_get(bit_t* current,int i, int j)
{
	if(current->rPos!=-1)
	{
		if((current->rPos==i)&&(current->cPos==j))
		{
			return current->val;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}


int get(bit_t *e, int col, int row){
	
	if((e->cPos == col)&&(e->rPos == row))
		return e->val;
    
	if((e->cPos > col)&&(e->rPos > row))
		return 0;
    
	if(e->cPos == -1)
		return 0;
    
	return 0;//get(e->next, col, row);
    
}


matrix* matrix_mult(matrix* a, matrix* b){
    matrix* sol = matrix_alloc(b->col,a->row);
	bit_t* temp=sol->first;
	int m=0;
    for(int i=0;i<a->row;i++)
	{
        for(int j=0;j<b->col;j++)
		{
            m=0;
            for(int k=0;k<b->row;k++)
			{
                m += (get(a->first,k,i)*get(b->first,j,k));
            }
			if(m!=0)
			{
				//matrix_set(temp,i,j,m);
				//temp=temp->next;
			}
            
        }
    }
    return sol;
}

void row_prepend(row_t *r, int col, int row){
    
    if (r!=NULL) {
        bit_t *b_new = malloc(sizeof(bit_t));
        if (!b_new) {
            free(r);
        }
        b_new->val = 1;
        b_new->cPos = col;
        b_new->rPos = row;
        
        b_new->b_prev = NULL;
        if (r->r_tail == NULL) /* Cas où notre liste est vide (pointeur vers fin de liste à  NULL) */
        {
            b_new->b_next = NULL; /* On fait pointer p_prev vers NULL */
            r->r_head = b_new; /* On fait pointer la tête de liste vers le nouvel élément */
            r->r_tail = b_new; /* On fait pointer la fin de liste vers le nouvel élément */
        }
        else /* Cas où des éléments sont déjà présents dans notre liste */
        {
            r->r_head->b_prev = b_new; /* On relie le dernier élément de la liste vers notre nouvel élément (début du chaînage) */
            b_new->b_next = r->r_head; /* On fait pointer p_prev vers le dernier élément de la liste */
            r->r_head = b_new; /* On fait pointer la fin de liste vers notre nouvel élément (fin du chaînage: 3 étapes) */
        }
    }
}

void matrix_prepend(matrix_t *m){
    
    if (m!=NULL) {
        row_t *r_new = malloc(sizeof(row_t));
        if (!r_new) {
            free(m);
        }
        
        
        r_new->r_prev = NULL;
        if (m->m_tail == NULL) /* Cas où notre liste est vide (pointeur vers fin de liste à  NULL) */
        {
            r_new->r_next = NULL; /* On fait pointer p_prev vers NULL */
            m->m_head = r_new; /* On fait pointer la tête de liste vers le nouvel élément */
            m->m_tail = r_new; /* On fait pointer la fin de liste vers le nouvel élément */
        }
        else /* Cas où des éléments sont déjà présents dans notre liste */
        {
            m->m_head->r_prev = r_new; /* On relie le dernier élément de la liste vers notre nouvel élément (début du chaînage) */
            r_new->r_next = m->m_head; /* On fait pointer p_prev vers le dernier élément de la liste */
            m->m_head = r_new; /* On fait pointer la fin de liste vers notre nouvel élément (fin du chaînage: 3 étapes) */
        }
        
    }
}


