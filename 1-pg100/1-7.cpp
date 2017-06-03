#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

// helps to look at an example
// 1 2 3        3 6 9
// 4 5 6   ->   2 5 8
// 7 8 9        1 4 7
// your columns become rows..
// last column     -> first row
// 2nd last column -> 2nd last row
vector<vector<int>> rotateMatrix1( vector<vector<int>> matrix ) {
   int cols = matrix[0].size();
   vector<vector<int>> newMatrix;
   vector<int> newRow;
   for( int i = cols-1; i >= 0; --i ) {
      for( int j = 0; j < matrix.size(); ++j ) {
         newRow.push_back(matrix[j][i]);
      }
      newMatrix.push_back(newRow);
      newRow = {};
   }
   return newMatrix;
}

int main() {
   vector<vector<int>> matrix{ {1,2,3},{4,5,6},{7,8,9} };
   vector<vector<int>> newMatrix = rotateMatrix1( matrix );

   for( auto row : newMatrix ) {
      for( auto val : row ) {
         cout << val << ", ";
      }
      cout << endl;
   }

   return 0;
}
