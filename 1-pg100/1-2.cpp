#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

// another solution is to sort both, then compare each letter
// if any are different, return false.
bool isPermutation( string a, string b ) {
   if(a.size() != b.size()) return false;
   unordered_map<char, int> chars;
   for( auto ch : a ) {
      chars[ch]++;
   }

   for( auto ch : b ) {
      if( chars.find(ch) == chars.end() || chars[ch] == 0 ) {
         return false;
      }
      chars[ch] -= 1;
   }

   return true;
}

int main() {
   cout << isPermutation("abb","baa") << endl;
   return 0;
}
