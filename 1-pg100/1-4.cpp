#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

bool isPaliPerm( string s ) {
   unordered_set<char> charSet;
   for( auto ch : s ) {
      ch = tolower(ch);
      if( ch == ' ' ) continue;
      if( charSet.find(ch) == charSet.end() ) {
         charSet.emplace(ch);
      } else {
         charSet.erase(ch);
      }
   }
   return ( charSet.size() == 0 || charSet.size() == 1 );
}

int main() {
   cout << isPaliPerm("racecar") << endl;
   return 0;
}
