// Luke Marushack
// Fundamentals of Computing : Lab #7
// lifefunc.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lifefunc.h"

// GLIDER NOT WORKING PROPERLY, WHY

char solve_cell(char temp[][maxsize], int row, int col) {
	int liveneighbors = 0, deadneighbors = 0;
	int i, j;
	// check locations around temp[row][col]
	for (i = -1; i <= 1; i++) {
		for (j = -1; j <= 1; j++) {
			// conditional statement to account for where in board (corner, edge, etc.)
			if (!(row+i >= maxsize || col+i >= maxsize || row+i < 0 || col+i < 0 || (i == 0 && j == 0))) {
				if (temp[row+i][col+i] == ' ') deadneighbors++;
				if (temp[row+i][col+i] == 'X') liveneighbors++;
			}
		}
	}
	if (temp[row][col] == ' ' && liveneighbors == 3) return 'X';
	if (temp[row][col] == 'X' && (liveneighbors == 2 || liveneighbors == 3)) return 'X';
	else return ' ';
}

void advance_simulation(char real[][maxsize], char temp[][maxsize]) {
	int i, j;
	// loop through real board, assign new value at location to temp booard
	for (i = 0; i < maxsize; i++) {
		for (j = 0; j < maxsize; j++) {
			temp[i][j] = solve_cell(real, i, j);	
		}
	}
	// loop through boards, assign value stored in temp board to real board
	for (i = 0; i < maxsize; i++) {
		for (j = 0; j < maxsize; j++) {
			real[i][j] = temp[i][j];
		}
	}
}

void display_board(char real[][maxsize]) {
	int i, j;
	printf("\n\n");
	// adding borders:
	printf("#");
	for (i = 0; i < maxsize; i++) {
		printf("--");
	}
	printf("#\n");

	for (i = 0; i < maxsize; i++) {
		printf("|");
		for (j = 0; j < maxsize; j++) {
			printf("%c ", real[i][j]);
		}
		printf("|\n");
	}

	printf("#");
	for (i = 0; i < maxsize; i++) {
		printf("--");
	}
	printf("#\n");
}

void add_live_cell(char real[][maxsize], int row, int col) {
	real[row][col] = 'X';
	return;
}

void make_dead_cell(char real[][maxsize], int row, int col) {
	real[row][col] = ' ';
	return;
}

/*
char get_input(int maxsize) {
	char c;
	int a = 0, b = 0;
	printf("Enter an operation: \n");
	printf("a followed by two integers: add new live cell at the specified coordinates\n");
	printf("r followed by two integers: make cell at specified coordinates dead\n");
	printf("n: advance the simulation to the next iteration\n");
	printf("q: quit the program\n");
	printf("p: play the game continuously\n");
	scanf("%c %d %d", &c, &a, &b);
	
	if (c != 'a' && c != 'r' &&  c != 'n' && c != 'q' && c != 'p') {
		printf("\nYou entered a bad character. Please try again.\n");
		return get_input(maxsize);
	}
	if (a >= maxsize || b >= maxsize) {
		printf("\nYou entered a bad number. Please try again.\n");
		return get_input(maxsize);
	}

	return c;
}
*/
