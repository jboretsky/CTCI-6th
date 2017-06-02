#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool isUnique( string s ) {
   unordered_set<char> chars;
   for( auto ch : s ) {
      if(chars.find(ch) != chars.end() ) return false;
      chars.emplace(ch);
   }
   return true;
}

bool isUnique2( string s ) {
   sort( s.begin(), s.end() );
   for( int i = 0; i < s.size() - 1; ++i ) {
      if(s[i] == s[i+1]) return false;
   }
   return true;
}

int main() {
   cout << isUnique2("hello") << endl;
   return 0;
}
