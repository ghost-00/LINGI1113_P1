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
    n->n_head = NULL;
    n->n_tail = NULL;
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
    if (r==NULL) {
        printf("row_print : r == NULL");
        exit(EXIT_FAILURE);
    }
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
    if (c==NULL) {
        printf("col_print : c == NULL");
        exit(EXIT_FAILURE);
    }
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
    if (m==NULL) {
        printf("matrix_print : m == NULL");
        exit(EXIT_FAILURE);
    }
    int bit=0, row=0, col=0;
    
    
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
                bit_prepend(c_new, c-1, b_temp->rPos);
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

matrix_t*
matrix_mul(matrix_t *m_one, matrix_t *m_two){
    matrix_t *m_result = matrix_alloc(m_two->nr_col, m_one->nr_row);
	int i=0, j=0, bit;
    row_t *row=NULL, *col=NULL ;
    
    for (i=0; i<m_two->nr_col; i++) {
        row_prepend(m_result);
        row = row_get(m_one, (i+1));
        for (j=0; j<m_one->nr_row; j++) {
            col = col_get(m_two, (j+1));
            
            if (col!=NULL && row!=NULL) {
                bit = row_mul(row, col, i, j);
                if (bit==1) {
                    bit_prepend(m_result->m_tail, j, i);
                }
            }
	    row_free(&col);
        }
    }
    
    matrix_free(&m_one); /*on libère l'espace mémoire attribué à ces deux matrices*/
    matrix_free(&m_two);
    
    return m_result;
}

int
row_mul(row_t *row, row_t *col, int rPos, int cPos){
    
    int i=0, r_bit, c_bit, acc=0;
    
    bit_t *rowb_temp = row->r_head;
    bit_t *colb_temp = col->r_head;
    
    for (i=0; i < row->r_length; i++) {
        r_bit = bit_getnext(rowb_temp, rPos, i);
        c_bit = bit_getnext(colb_temp, i, cPos);
        acc = acc + (r_bit * c_bit);
        if (r_bit == 1) {
            rowb_temp = rowb_temp->b_next;
        }
        if (c_bit == 1) {
            colb_temp = colb_temp->b_next;
        }
    }
    return acc;
}


void
buf_free(node_t **n){
    if (*n != NULL)
    {
        matrix_t *m_temp = (*n)->n_head;
        while (m_temp != NULL)
        {
            matrix_t *m_del = m_temp;
            m_temp = m_temp->m_next;

            matrix_free(&m_del);
        }
        free(*n), *n=NULL;
    }
}

void
matrix_free(matrix_t **m){
    if (*m != NULL)
    {
        row_t *r_temp = (*m)->m_head;
        while (r_temp != NULL)
        {
            row_t *r_del = r_temp;
            r_temp = r_temp->r_next;
            row_free(&r_del);
        }
        free(*m), *m=NULL;
    }
}

void
row_free(row_t **r){
    if (*r != NULL)
    {
        bit_t *b_temp = (*r)->r_head;
        while (b_temp != NULL)
        {
            bit_t *b_del = b_temp;
            b_temp = b_temp->b_next;
            free(b_del);
        }
        free(*r), *r=NULL;
    }
}
