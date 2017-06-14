#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> bomberman( vector<vector<int>> matrix ) {
   for(int row = 0; row < matrix.size(); ++row) {
      for(int col = 0; col < matrix[0].size(); ++col) {
         if(matrix[row][col] == 0) {
            matrix[row][0] = 0;
            matrix[0][col] = 0;
         }
      }
   }
   for(int row = 0; row < matrix.size(); ++row) {
      for(int col = 0; col < matrix[0].size(); ++col) {
         if(matrix[row][0] == 0 || matrix[0][col] == 0) {
            matrix[row][col] = 0;
         }
      }
   }
   return matrix;
}

int main() {
   vector<vector<int>> matrix{
      {1,2,3,4,5},
      {6,7,8,9,1},
      {1,2,3,0,4},
      {9,4,8,6,5},
      {2,4,4,5,6}};
   vector<vector<int>> ret = bomberman(matrix);
   for(auto row : ret) {
      for(auto val : row) {
         cout << val << ", ";
      }
      cout << endl;
   }
   return 0;
}
