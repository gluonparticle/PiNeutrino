#include <stdio.h>
#include <stdbool.h>
#define MAX 20
int n, queens[MAX];
int solution_count = 0;
bool is_safe(int row, int col) {
for (int i = 0; i < row; i++) {
if (queens[i] == col ||
queens[i] - i == col - row ||
queens[i] + i == col + row)
return false;
}
return true;
}
void print_board() {
printf("Solution %d:\n", ++solution_count);
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
printf(j == queens[i] ? "Q " : "- ");
}
printf("\n");
}
printf("\n");
}
void solve(int row) {
for (int col = 0; col < n; col++) {
if (is_safe(row, col)) {
queens[row] = col;
solve(row + 1);
}
}
if (row == n) {
print_board();
return;
}
}
int main() {
printf("Enter board size N: ");
scanf("%d", &n);
solve(0);
if (solution_count == 0)
printf("No solutions exist for N = %d\n", n);
return 0;
}