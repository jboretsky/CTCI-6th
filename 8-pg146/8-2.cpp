#include <vector>
#include <iostream>

using namespace std;

/*
 * Idea: can you find a path from the current position?
 * Start at end. if you can find a path to the left, or above, then you can find a path to end
 * continue like that.
 * if you've gone too far left, or too far up, or the current square you're on is a wall,
 * then this path couldn't be right
 */

bool findPath( vector<vector<int>>& grid, int r, int c ) {
   if( r < 0 || c < 0 || grid[r][c] == 1) return false;
   if(findPath(grid, r-1, c) || findPath(grid,r,c-1) || ( r == 0 && c == 0 )) {
      grid[r][c] = 2;
      return true;
   }
   return false;
}

int main() {
   vector<vector<int>> grid =
   {{0,0,1,0,0,0,0,0},
    {1,0,1,1,1,1,1,0},
    {1,0,1,0,0,0,0,0},
    {0,0,1,0,1,1,1,0},
    {1,0,0,0,1,0,0,0},
    {1,1,1,0,1,0,1,1},
    {0,0,0,0,0,0,0,0}};

   bool ret = findPath(grid, grid.size()-1, grid[0].size()-1);
   for( auto row : grid ) {
      for( auto val : row ) {
         cout << val << ", ";
      }
      cout << endl;
   }

   return 0;
}
