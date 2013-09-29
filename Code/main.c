/**
 *	Dumoulin Mehdi 45570900 et Huberlant Alexis 54701000
 *	Projet 1 Systeme informatique 2
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
	int output = 0;
	int c;
	char *outFile = NULL;
	int a = 0;
	
	while((c=getopt(argc,argv,"ao:")) != -1){
		switch (c){
        	case 'a':
				a = 1;
       			break;
			case 'o':
				output = 1;
				outFile = optarg;
				break;
        	case '?':
       	 	break;
        	default:
        	printf ("Option non valide\n");
        }
	}

	char *path=(char*)argv[optind];
	buffer* buf = lecture(path,a);

	matrix* sol = multiplicator(buf);
	if(output == 0)
		matrix_print(sol);
	else
		matrix_writefile(sol,outFile);

	matrix_free(sol);
	buffer_free(buf);
	return EXIT_SUCCESS;
}
