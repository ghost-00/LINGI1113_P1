/**
 *	Dumoulin Mehdi & Zigabe Jos
 *	Projet 1 Multiplication de matrices creuses
 *	
 *	Fichier contenant l'implementation des methodes relatives au buffer 
 *	et a ses cellules
 **/

#include "buffer.h"


buffer *buffer_init(){
    buffer *buf;
    buf = (buffer *)malloc(sizeof(buffer));
    if(!buf)
        exit(EXIT_FAILURE);
	buf->size = 0;
	buf->first = NULL;
	buf->last = NULL;
    buf->current = NULL;
    return buf;
}

struct node *node_init(struct matrix_t *matrix){
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    if(!new)
        exit(EXIT_FAILURE);
    new->next=NULL;
    new->val=matrix;
    return new;
}

void enqueue(buffer *buf, struct node *new){
	if(buf->size==0){
		buf->first = new;
		buf->size = buf->size+1;
        buf->current = new;
		//Dans le cas ou la taille vaut 0 on remplace first par new
	}
	else if(buf->size==1){
		buf->last=new;
		buf->first->next = new;
		buf->size = buf->size+1;
		//Dans le cas ou la taille vaut 1 on remplace last par new
	}
	else if(buf->size > 1){
		(buf->last)->next = new;
		buf->last = new;
		buf->size = buf->size+1;
		//Dans les autres cas on met new a la fin
	}
}

struct matrix_t *dequeue(buffer *buf){
	struct node *tempNode;
	matrix *temp;
	if(buf->size==2){
		temp = (buf->first)->val;
		buf->size=buf->size-1;
		tempNode = buf->first;
		buf->first = buf->last;
		buf->last = NULL;
		node_free(tempNode);
        buf->current = buf->first;
		//Dans le cas ou la taille vaut 2 on remplace first par last et
		//on met last a NULL
	}
	else if(buf->size==1){
		temp = (buf->first)->val;
		tempNode = buf->first;
		buf->size=buf->size-1;
		node_free(tempNode);
		buf->first=NULL;
        buf->current=NULL;
		//Dans le cas ou la taille vaut 1 on remplace first par null
	}
	else if(buf->size > 2){
        if(buf->current == buf->first){
            buf->current = buf->first->next;
        }
		tempNode = buf->first;
		temp = tempNode->val;
		buf->first=(buf->first)->next;
		node_free(tempNode);
		buf->size-=1;
		//Dans le cas ou la taille est superieur a 2 on supprime le premier
		//element et on remplace first par le deuxieme element
	}
	return temp;
}

void node_free(struct node *node){
	free(node);
}

void node_matrix_free(struct node *node){
	matrix_free(node->val);
	node_free(node);
}

void buffer_free(buffer *buf){
	if(buf->size == 0){
		node_free(buf->first);
		free(buf);
	}
	else if(buf->size == 1){
        node_matrix_free(buf->first);
		free(buf);
	}
	else{
		while(buf->first != NULL){
			struct node *temp = buf->first;
			buf->first = buf->first->next;
			node_matrix_free(temp);
		}
		free(buf);
	}
}
