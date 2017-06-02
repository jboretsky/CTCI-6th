#include <string>
#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string compressString( string a ) {
   if( a.size() == 0 ) return "";
   string newString = "";
   int count = 0;
   char curChar;
   for( int i = 0; i < a.size(); ++i ) {
      if( curChar && a[i] != curChar ) {
         newString += curChar;
         newString += to_string(count);
         count = 0;
      }
      curChar = a[i];
      ++count;
   }
   newString += curChar;
   newString += to_string(count);
   return newString;
}

int main() {
   vector<string> strings {"aabccccaaa", "aaaaaaaaaa", "aaaaaaaaaabbbbbbbbbbbbbbbc", "", "a" };
   for( auto str : strings ) {
      cout << str << ": " << compressString(str) << endl;
   }
   return 0;
}
