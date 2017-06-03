#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

bool oneAway( string a, string b ) {
   if( abs((int)a.size() - (int)b.size()) > 1 ) return false;

   bool foundDiff = false;
   int size = 0;
   if( a.size() <= b.size() ) {
      size = a.size();
   } else {
      size = b.size();
   }

   int i = 0;
   while( i < size ) {
      if( a[i] != b[i] ) {
         if(foundDiff == true) return false;
         if( a.size() < b.size() ) {
            b.erase(i, 1);
         } else if ( a.size() > b.size() ) {
            a.erase(i, 1);
         }
         foundDiff = true;
      }
      ++i;
   }
   return true;
}

int main() {
   vector<vector<string>> strings {{"pale","ple"}, {"pales","pale"}, {"pale","bale"}, {"pale","bake"}, {"pale","pale"}};

   for( auto pair : strings ) {
      cout << pair[0] << "," << pair[1] << ": " << oneAway(pair[0],pair[1]) << endl;
   }
   return 0;
}
