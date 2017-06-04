#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void merge( vector<int>& toSort, int low, int mid, int high ) {
   int i = 0;
   int j = 0;

   vector<int> sorted;

   while(i < mid-low+1 && j < high-mid ) {
      if( toSort[low+i] <= toSort[mid+j+1] ) {
         sorted.push_back(toSort[low+i]);
         ++i;
      } else {
         sorted.push_back(toSort[mid+j+1]);
         ++j;
      }
   }
   while( j < high-mid ) {
      sorted.push_back(toSort[mid+j+1]);
      ++j;
   }
   while( i < mid-low+1 ) {
      sorted.push_back(toSort[low+i]);
      ++i;
   }

   i = low;
   for( auto val : sorted ) {
      toSort[i] = val;
      ++i;
   }
}

void mergeSort( vector<int>& toSort, int low, int high ) {
   if( high > low ) {
      int mid = (high + low) / 2;
      mergeSort( toSort, low, mid );
      mergeSort( toSort, mid+1, high );
      merge( toSort, low, mid, high );
   }
}

int main() {
   vector<int> toMerge = {10, 1, 20, 19, 200, 40, 5, 3};
   for( auto val : toMerge ) {
      cout << val << ", ";
   }
   cout << endl;
   int l = 0, h = toMerge.size()-1;
   mergeSort( toMerge, l, h );

   for( auto val : toMerge ) {
      cout << val << ", ";
   }
   cout << endl;

   return 0;
}
