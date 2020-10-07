// Luke Marushack
// Fundamentals of Computing : Lab #7
// lifefunc.h

const int maxsize = 40;
int show_input();
void add_live_cell(char [][maxsize], int row, int col);
void make_dead_cell(char [][maxsize], int row, int col);
void advance_simulation(char [][maxsize], char [][maxsize]);
char solve_cell(char [][maxsize], int row, int col);
