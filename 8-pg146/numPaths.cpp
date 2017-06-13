#include <vector>
#include <iostream>

using namespace std;

/*
 * Find number of paths from top left to bottom right
 * if we can only move right or down, but can go anywhere in the maze
 */

// recursive solution
int numPaths( int r, int c ) {
   if(r == 1 || c == 1) return 1;
   return numPaths(r-1, c) + numPaths(r,c-1);
}

// dp solution
int numPaths2( int r, int c ) {
   vector<vector<int>> grid(r, vector<int>(c,0));

   for( int i = 0; i < r; ++i ) {
      grid[i][0] = 1;
   }
   for( int i = 0; i < c; ++i ) {
      grid[0][i] = 1;
   }

   for( int i = 1; i < r; ++i ) {
      for(int j = 1; j < c; ++j) {
         grid[i][j] = grid[i-1][j] + grid[i][j-1];
      }
   }

   return grid[r-1][c-1];
}

int main() {
   int rows = 10;
   int cols = 10;
   int num = numPaths2(rows, cols);
   cout << num << endl;

   return 0;
}
