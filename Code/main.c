/**
 *	Dumoulin Mehdi & Zigabe jos
 *	Projet 1 Multiplication de matrices creuses
 *
 *	main
 **/

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include <stdarg.h>

#include "matrice.h"
#include "buffer.h"
#include "matrix_reader.h"
#include "projet.h"


int main (int argc, char* argv[])
{
	int o;
	char *outputFile, *inputFile = NULL;
	int opt = FALSE;
	
	while((opt=getopt(argc,argv,"o:")) != -1){
		switch (opt){
			case 'o':
				o = TRUE;
				outputFile = optarg; /*On récupère le outputPath*/
				break;
        	case '?':
                break;
                printf ("Option non valide\n");
        	default:
                printf ("Option non valide\n");
        }
	}
    
    inputFile = (char*)argv[optind]; /*On récupère le inputpath*/

	node_t* buf = read_file(inputFile); /*On extrait les matrices du fichier inputFile*/
    
    printf("nombre de matrice(s) : %d\n", buf->n_length);
    
    matrix_print(matrix_get(buf, 1));
        
	//matrix_t* p = multiplicator(buf);
    
    //matrix_print(p);
    /*
	if(output == 0)
		matrix_print(sol);
	else
		matrix_writefile(sol,outFile);
    
	matrix_free(sol);
	*/
    //buffer_free(buf);
	return EXIT_SUCCESS;
     
}
