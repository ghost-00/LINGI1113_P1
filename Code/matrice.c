/**
 *	Dumoulin Mehdi 45570900 et Huberlant Alexis 54701000
 *	Projet 1 Systeme informatique 2
 *
 *	Fichier implementant les methodes relatives au matrice
 **/

#include "matrice.h"

matrix* matrix_alloc(int col, int row){
	matrix *m;
	m = (matrix*)malloc(sizeof(matrix));
	if(!m)
	{
		exit(EXIT_FAILURE);
	}
	m->first = (elem*)malloc(sizeof(elem));
	if(!m->first)
	{
		free(m);
		exit(EXIT_FAILURE);
	}
	m->row = row;
	m->col = col;
	m->first->rPos=-1;
	m->first->cPos=-1;
	m->first->val=-1;
	return m;
}

void matrix_free(matrix* m){
	elem *temp = m->first;
	while(((temp->rPos <= m->row)||(temp->cPos <= m->col))&&((temp->rPos != -1)||(temp->cPos != -1))){
		elem* temp2 = temp->next;
		free(temp);
		temp = temp2;
	}
	free(temp);
	free(m);
}


void elem_free(elem* e){
	free(e);
}


void matrix_print(matrix* m)
{
	int i,j,a;
	elem* current=m->first;
	for(i=0;i<m->row;i++)
	{
		for(j=0;j<m->col;j++)
		{
			a=matrix_get(current,i,j);
			if(a)
			{
				current=current->next;
			}
			printf("%d ",a);
		}
		printf("\n");
	}
}


int matrix_get(elem* current,int i, int j)
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


int get(elem *e, int col, int row){
	
	if((e->cPos == col)&&(e->rPos == row))
		return e->val;

	if((e->cPos > col)&&(e->rPos > row))
		return 0;

	if(e->cPos == -1)
		return 0;

	return get(e->next, col, row);

}


matrix* matrix_mult(matrix* a, matrix* b){
    matrix* sol = matrix_alloc(b->col,a->row);
	elem* temp=sol->first;
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
				matrix_set(temp,i,j,m);
				temp=temp->next;
			}	

        	}
    	}
    return sol;
}


void matrix_set(elem* m, int row, int col,int val)
{
	elem* e;
	e=(elem*)malloc(sizeof(elem));
	if(!e)
		exit(EXIT_FAILURE);
	m->rPos=row;
	m->cPos=col;
	m->val=val;
	m->next=e;
	e->rPos=-1;
	e->cPos=-1;
	e->val=-1;
}


