#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

// another solution is to sort both, then compare each letter
// if any are different, return false.
bool isPermutation( string a, string b ) {
   unordered_map<char, int> chars;
   for( auto ch : a ) {
      if( chars.find(ch) == chars.end() ) {
         chars[ch] = 0;
      }
      chars[ch] += 1;
   }

   for( auto ch : b ) {
      if( chars.find(ch) == chars.end() ) {
         return false;
      } else if( chars[ch] == 0 ) {
         return false;
      } else {
         chars[ch] -= 1;
      }
   }
   return true;
}

int main() {
   cout << isPermutation("","") << endl;
   return 0;
}
