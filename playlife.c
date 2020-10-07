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
