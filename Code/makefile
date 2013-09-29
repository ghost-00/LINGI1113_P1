matrixprod: buffer.o main.o matrice.o matrix_reader.o projet.o
	gcc -o matrixprod buffer.o main.o matrice.o matrix_reader.o projet.o -Wall -Werror -std=c99 -g

main.o: main.c buffer.o matrice.o matrix_reader.o
	gcc -o main.o -c main.c -Wall -Werror -std=c99 -g

projet.o: projet.c projet.h buffer.o matrix_reader.o matrice.o
	gcc -o projet.o -c projet.c -Wall -Werror -std=c99 -g

buffer.o : buffer.h buffer.c matrice.o
	gcc -o buffer.o -c buffer.c -Wall -Werror -std=c99 -g

matrice.o: matrice.h matrice.c
	gcc -o matrice.o -c matrice.c -Wall -Werror -std=c99 -g

matrix_reader.o: matrix_reader.h matrix_reader.c matrice.h
	gcc -o matrix_reader.o -c matrix_reader.c -Wall -Werror -std=c99 -g

clean:
	rm *.o
