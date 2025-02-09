// Luke Marushack
// Fundamentals of Computing : Lab #7
// playlife.c

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
			//scanf("%c %d %d", &inp, &a, &b);
			scanf("%s", &inp);

			switch (inp) {
				case 'a':
					scanf("%d %d", &a, &b);
					if (a >= maxsize || b >= maxsize || a < 0 || b < 0) {
						printf("Invalid coordinates. Please try again.\n");
						break;
					}
					add_live_cell(real, a, b);
					display_board(real);
					break;

				case 'r':
					scanf("%d %d", &a, &b);
					if (a >= maxsize || b >= maxsize || a < 0 || b < 0) {
						printf("Invalid coordinates. Please try again.\n");
						break;
					}
					make_dead_cell(real, a, b);
					display_board(real);
					break;

				case 'n':
					advance_simulation(real, temp);
					display_board(real);
					break;

				case 'p':
					while (1) {
						advance_simulation(real, temp);
						display_board(real);
						usleep(250000);
						system("clear");
					}

				case 'q':
					printf("Goodbye!\n");
					return 0;

				default:
					printf("You entered an invalid operation. Please try again!\n");
					printf("\n%c\n", inp);
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
			fscanf(fp, "%c %d %d", &op, &row_op, &col_op);
			if (op == 'a') { // live cell
				add_live_cell(real, col_op, row_op);
			}
			if (op == 'r') { // dead cell
				make_dead_cell(real, col_op, row_op);
			}
			if (op == 'p') break; // play game
		}

		while (1) {
			display_board(real);
			advance_simulation(real, temp);
			usleep(250000);
			system("clear");
		}
	}

	return 0;
}	
	
