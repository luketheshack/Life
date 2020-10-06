#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "lifefunc.h"

const int MAX = 40;

int main(int argc, char *argv[]) {
	char current[MAX][MAX];
	char temp[MAX][MAX];
	int i, j;

	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			current[i][j] = ' ';
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

		char line[10];
		char op;
		int row_op, col_op;
		while (1) {
			fgets(line, 10, fp);
			if (feof(fp)) break;
			if (line[0] == 'p') break;
			// assuming that file line is formatted with single spaces
			// inbetween different alphanumeric characters
			op = line[0];
			row_op = line[2];
			col_op = line[4];
		}
	}
	
	return 0;
}
