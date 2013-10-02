/**
 *	Dumoulin Mehdi & Zigabe Jos
 *	Projet 1 Multiplication de matrices creuses
 *
 *	Fichier implementant les methodes relatives au matrice
 **/

#include "matrice.h"

node_t*
node_init(){
    node_t *n = malloc(sizeof(node_t)); /*allocation mémoire pour la structure n de type node_t*/
    if (!n) {
        printf("allocation mémoire impossible");
        exit(EXIT_FAILURE);
    }
    n->n_length=0; /*initialisation de la sous varialble length à zéro*/
    return n;
}
matrix_t*
matrix_alloc(int col, int row){
	matrix_t *m;
	m = (matrix_t*)malloc(sizeof(matrix_t));
	if(!m)
	{
        printf("allocation mémoire impossible");
		exit(EXIT_FAILURE);
	}
    m->nr_col = col;
    m->nr_row = row;
    m->m_head = NULL;
    m->m_tail = NULL;
    return m;
}

row_t*
row_alloc(matrix_t *m){
    row_t *r_new = malloc(sizeof (row_t));
    if (r_new != NULL)
    {
        r_new->r_head = NULL;
        r_new->r_tail = NULL;
    }
    r_new->r_length = m->nr_col;
    r_new->c_length = m->nr_row;
    return r_new;
}

void
bit_prepend(row_t *r, int col, int row){
    
    if (r!=NULL) {
        bit_t *b_new = malloc(sizeof(bit_t));
        if (!b_new) {
            free(r);
        }
        b_new->val = 1;
        b_new->cPos = col;
        b_new->rPos = row;
        
        b_new->b_next = NULL;
        if (r->r_tail == NULL) /* Cas où notre liste est vide (pointeur vers fin de liste à  NULL) */
        {
            b_new->b_prev = NULL; /* On fait pointer p_prev vers NULL */
            r->r_head = b_new; /* On fait pointer la tête de liste vers le nouvel élément */
            r->r_tail = b_new; /* On fait pointer la fin de liste vers le nouvel élément */
        }
        else /* Cas où des éléments sont déjà présents dans notre liste */
        {
            r->r_tail->b_next = b_new; /* On relie le dernier élément de la liste vers notre nouvel élément (début du chaînage) */
            b_new->b_prev = r->r_tail; /* On fait pointer p_prev vers le dernier élément de la liste */
            r->r_tail = b_new; /* On fait pointer la fin de liste vers notre nouvel élément (fin du chaînage: 3 étapes) */
        }
    }
}

void
row_prepend(matrix_t *m){
    
    if (m!=NULL) {
        row_t *r_new = row_alloc(m);
        if (!r_new) {
            free(m);
        }
        
        
        r_new->r_next = NULL;
        if (m->m_tail == NULL) /* Cas où notre liste est vide (pointeur vers fin de liste à  NULL) */
        {
            r_new->r_prev = NULL; /* On fait pointer p_prev vers NULL */
            m->m_head = r_new; /* On fait pointer la tête de liste vers le nouvel élément */
            m->m_tail = r_new; /* On fait pointer la fin de liste vers le nouvel élément */
        }
        else /* Cas où des éléments sont déjà présents dans notre liste */
        {
            m->m_tail->r_next = r_new; /* On relie le dernier élément de la liste vers notre nouvel élément (début du chaînage) */
            r_new->r_prev = m->m_tail; /* On fait pointer p_prev vers le dernier élément de la liste */
            m->m_tail = r_new; /* On fait pointer la fin de liste vers notre nouvel élément (fin du chaînage: 3 étapes) */
        }
        
    }
}

void
matrix_prepend(node_t *n, matrix_t *m){
    
    if (n!=NULL && m!=NULL) {
        m->m_next = NULL;
        if (n->n_tail == NULL) /* Cas où notre liste est vide (pointeur vers fin de liste à  NULL) */
        {
            m->m_prev = NULL; /* On fait pointer p_prev vers NULL */
            n->n_head = m; /* On fait pointer la tête de liste vers le nouvel élément */
            n->n_tail = m; /* On fait pointer la fin de liste vers le nouvel élément */
        }
        else /* Cas où des éléments sont déjà présents dans notre liste */
        {
            n->n_tail->m_next = m; /* On relie le dernier élément de la liste vers notre nouvel élément (début du chaînage) */
            m->m_prev = n->n_tail; /* On fait pointer p_prev vers le dernier élément de la liste */
            n->n_tail = m; /* On fait pointer la fin de liste vers notre nouvel élément (fin du chaînage: 3 étapes) */
        }
        n->n_length++;
    }
    
}

void
row_print(row_t *r)
{
    printf("row : \n");
    int row=0;
    bit_t *b_temp = r->r_head;
    
    for (row=0; row < r->r_length; row++) {
        if (b_temp!=NULL) {
            if(b_temp->cPos == row){
                printf("%d ", 1);
                b_temp = b_temp->b_next;
            }else{
                printf("%d ", 0);
            }
        }else{
            printf("%d ", 0);
        }
    }
    printf("\n");
}
void
col_print(row_t *c)
{
    printf("col :\n");
    int row=0;
    bit_t *r_temp = c->r_head;
    
    for (row=0; row < c->c_length; row++) {
        if (r_temp!=NULL) {
            if(r_temp->rPos == row){
                printf("%d\n", 1);
                r_temp = r_temp->b_next;
            }else{
                printf("%d\n", 0);
            }
        }else{
            printf("%d\n", 0);
        }
    }
    printf("\n");
}

void
matrix_print(matrix_t *m)
{
    int bit=0, row=0, col=0;
    
    if (m!=NULL) {
        printf("%dx%d\n", m->nr_row, m->nr_col);
        
        row_t *r_temp = m->m_head;
        for (row=0; row < m->nr_row; row++) {
            bit_t *b_temp = r_temp->r_head;
            for (col=0; col < m->nr_col; col++) {
                
                bit = bit_getnext(b_temp, row, col);
                
                if (bit == 1) {
                    printf("%d ", 1);
                    if (b_temp->b_next!=NULL) {
                        b_temp = b_temp->b_next;
                    }
                }else{
                    printf("%d ", 0);
                }
            }
            printf("\n");
            r_temp = r_temp->r_next;
        }
    }
}

int
bit_getnext(bit_t* current_b,int current_row, int current_col)
{
	if(current_b!=NULL)
	{
		if ((current_b->rPos == current_row) && (current_b->cPos == current_col)) {
            return 1;
        }
	}
    
    return 0;
}

row_t*
row_get(matrix_t *m, int r){
    if (r > m->nr_row) {
        printf("row_get : r doit être =< %d\n", m->nr_row);
        return NULL;
    }
    
    int i=0;
    row_t *r_temp = m->m_head;
    
    while (r_temp != NULL && i<(r-1))
    {
        r_temp = r_temp->r_next;
        i++;
    }
    
    return r_temp;
}

row_t*
col_get(matrix_t *m, int c)
{
    if (c > m->nr_col) {
        printf("col_get : r doit être =< %d\n", m->nr_col);
        return NULL;
    }
    
    row_t *c_new = row_alloc(m);
    row_t *r_temp = m->m_head;
    while (r_temp != NULL)
    {
        bit_t *b_temp = r_temp->r_head;
        while (b_temp!=NULL) {
            
            if (b_temp->cPos == (c-1)) {
                bit_prepend(c_new, c, b_temp->rPos);
                //printf("%d \n",b_temp->val);
            }
            b_temp = b_temp->b_next;
        }
         r_temp = r_temp->r_next;
    }
    
    return c_new;
}

matrix_t*
matrix_get(node_t* n, int m){
    
    if (m > n->n_length) {
        printf("matrix_get : m doit être =< %d\n", n->n_length);
        return NULL;
    }
    
    int i=0;
    matrix_t *m_temp = n->n_head;
    
    while (m_temp != NULL && i<(m-1))
    {
        m_temp = m_temp->m_next;
        i++;
    }
    
    return m_temp;
}


/**********************/
/*Le reste est à faire*/
/**********************/

void matrix_free(matrix_t* m){
	free(m);
}
void row_free(row_t* row){
    free(row);
}


void bit_t_free(bit_t* e){
	free(e);
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



