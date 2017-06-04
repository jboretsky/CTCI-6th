#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int rearrange( vector<int>& toSort, int low, int high ) {
   int pivot = toSort[high];
   int swapPos = low; // will be index of low vals
   for( int i = low; i < high; ++i ) {
      if( toSort[i] <= pivot ) {
         swap(toSort[swapPos], toSort[i]);
         ++swapPos;
      }
   }
   swap(toSort[swapPos], toSort[high]);
   return swapPos;
}


void quickSort( vector<int>& toSort, int low, int high ) {
   // pick pivot as middle
   // move all elements smaller than middle element to left side, all elements greater to right side
   // all elements equal to mid
   // quicksort both those sides
   if( high > low ) {
      int pivot = rearrange( toSort, low, high );
      quickSort( toSort, low, pivot - 1);
      quickSort( toSort, pivot + 1, high );
   }
}

int main() {
   vector<int> toMerge = {10, 1, 20, 19, 200, 40, 5, 3};
   for( auto val : toMerge ) {
      cout << val << ", ";
   }
   cout << endl;
   int l = 0, h = toMerge.size()-1;
   quickSort( toMerge, l, h );

   for( auto val : toMerge ) {
      cout << val << ", ";
   }
   cout << endl;

   return 0;
}
