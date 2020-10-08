
#include <stdbool.h> 
#include <stdio.h> 

void printSolution(int board[][10], int N) 
{ 
	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < N; j++) 
			printf(" %d ", board[i][j]); 
		printf("\n"); 
	} 
} 

/* A utility function to check if a queen can 
be placed on board[row][col]*/
bool isSafe(int board[][10], int row, int col, int N) 
{ 
	int i, j; 
	
	/* Check this row on left side */
	for (i = 0; i < col; i++) 
		if (board[row][i]) 
			return false; 

	/* Check upper diagonal on left side */
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
		if (board[i][j]) 
			return false; 

	/* Check lower diagonal on left side */
	for (i = row, j = col; j >= 0 && i < N; i++, j--) 
		if (board[i][j]) 
			return false; 

	return true; 
} 

/* A recursive utility function to solve N 
Queen problem */
bool solveNQUtil(int board[][10], int col, int N) 
{ 
	/* base case: If all queens are placed 
	then return true */
	if (col >= N) 
		return true; 

	/* Consider this column and try placing 
	this queen in all rows one by one */
	for (int i = 0; i < N; i++) { 
		/* Check if the queen can be placed on 
		board[i][col] */
		if (isSafe(board, i, col, N)) { 
			/* Place this queen in board[i][col] */
			board[i][col] = 1; 

			/* recur to place rest of the queens */
			if (solveNQUtil(board, col + 1, N)) 
				return true; 

			/* If placing queen in board[i][col] 
			doesn't lead to a solution, then 
			remove queen from board[i][col] */
			board[i][col] = 0; // BACKTRACK 
		} 
	} 

	/* If the queen cannot be placed in any row in 
		this colum col then return false */
	return false; 
} 

bool solveNQ() 
{ 
	int N;
	scanf("%d",&N);
	int board[10][10];
	for(int i=0;i<N;i++){
	for(int j=0;j<N;j++)
		board[i][j]=0;
		}

	if (solveNQUtil(board, 0, N) == false) { 
		printf("Solution does not exist"); 
		return false; 
	} 

	printSolution(board, N); 
	return true; 
} 

int main() 
{ 
	
	solveNQ(); 
	return 0; 
} 

