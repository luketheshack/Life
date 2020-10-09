#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "lifefunc.h"

int main(int argc, char *argv[]) {
	char real[maxsize][maxsize];
	char temp[maxsize][maxsize];
	int i, j;

	for (i = 0; i < maxsize; i++) {
		for (j = 0; j < maxsize; j++) {
			real[i][j] = ' ';
			temp[i][j] = ' ';
		}
	}
	
	if (argc == 1) {
		// interactive mode
		printf("Playing in interactive mode... \n");
		char inp = '\0';
		int a, b;
		while (inp != 'q' && inp != 'p') {
			a = -1;
			b = -1;
			printf("\nEnter an operation: \n");
			printf("a followed by two integers: add new live cell at the specified coordinates\n");
			printf("r followed by two integers: make cell at specified coordinates dead\n");
			printf("n: advance the simulation to the next iteration\n");
			printf("q: quit the program\n");
			printf("p: play the game continuously\n");
			scanf("%c %d %d", &inp, &a, &b);
			printf("%c %d %d\n:", inp, a, b);	
			switch (inp) {
				case 'a':
					if (a >= 40 || b >= 40 || a < 0 || b < 0) {
						printf("Invalid coordinates. Please try again.\n");
						break;
					}
					add_live_cell(real, a, b);
					break;

				case 'r':
					if (a >= 40 || b >= 40 || a < 0 || b < 0) {
						printf("Invalid coordinates. Please try again.\n");
						break;
					}
					make_dead_cell(real, a, b);
					break;

				case 'n':
					advance_simulation(real, temp);
					display_board(real);
					break;

				case 'p':
					while (1) {
						advance_simulation(real, temp);
						display_board(real);
					}

				case 'q':
					printf("Goodbye!\n");
					return 0;

				default:
					printf("You entered an invalid operation. Please try again!\n");
					break;
			}
			
		}
		
		return 0;
	}

	else {
		// batch mode
		printf("Playing in batch mode... \n");
		FILE *fp = fopen(argv[1], "r");

		if (!fp) {
			printf("File not found. Quitting program ... \n");
			return 1;
		}

		char op;
		int row_op, col_op;
		while (1) {
			if (feof(fp)) break;
			// assuming that file line is formatted with single spaces
			// inbetween different alphanumeric characters
			fscanf(fp, "%c %d %d", &op, &row_op, &col_op);
			if (op == 'a') { // live cell
				add_live_cell(real, row_op, col_op);	
			}
			if (op == 'r') { // make cell dead
				make_dead_cell(real, row_op, col_op);
			}
			if (op == 'p') { // play game
				break;
			}
		}
		
		while (1) {
			// display board
			display_board(real);
			// advance simulation
			advance_simulation(real, temp);
			// wait
			usleep(250000);
			// clear screen
			system("clear");
		}
		
	}
	
	return 0;
}
