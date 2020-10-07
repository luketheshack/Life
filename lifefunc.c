// Luke Marushack
// Fundamentals of Computing : Lab #7
// lifefunc.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lifefunc.h"

void solve_cell(char temp[][maxsize], int row, int col) {
	// conditionoal statements because edges, corner, center
	// of grid must behave differently
	int liveneighbors = 0, deadneighbors = 0;
	int i, j;
	for (i = -1; i <= 1; i++) {
		for (j = -1; j <= 1; j++) {
			if (!(row+i >= maxsize || col+i >= maxsize || row+i < 0 || col+i < 0 || (row == 0 && col == 0))) {
				if (temp[row+i][col+i] == ' ') deadneighbors++;
				if (temp[row+i][col+i] == 'X') liveneighbors++;
			}
		}
	}
	if (temp[row][col] == ' ' && liveneighbors == 3) return 'X';
	if (temp[row][col] == 'X' && !(liveneighbors == 2 || liveneighbors == 3) return ' ';
	else return temp[row][col];
}

void advance_simulation(char real[][maxsize], char temp[][maxsize]) {
	int i, j;
	
}
