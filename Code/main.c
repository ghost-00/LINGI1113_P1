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
	int o = 0;
	char *outputFile, *inputFile = NULL;
	int opt = 0;
	
	while((opt=getopt(argc,argv,"o:")) != -1){
		switch (opt){
			case 'o':
				o = 1;
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

    if (o==1) {
        matrix_writefile(buf->n_head,outputFile);
        printf("look at outputFile\n");
    }
    else {
        matrix_print(buf->n_head);
    }

    buf_free(&buf);
	return EXIT_SUCCESS;
     
}
