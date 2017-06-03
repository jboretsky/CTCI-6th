#include <iostream>
#include <string>

using namespace std;

// suppose b is a rotation of a, then if we concatenate it with itself,
// a will appear in the concatenation, so a should be a substring of b+b
// There should however be the extra assurance that the strings are the same length
// otherwise, ( waterbottle, erbottle!!!!wat ) would still pass

bool isSubstring(string a, string b) {
   return a.find(b) != string::npos;
}

bool isRotation(string a, string b) {
   if( a.size() != b.size() ) return false;
   return isSubstring(b+b, a);
}

int main() {
   cout << isRotation("waterbottle", "erbottlewat") << endl;
   return 0;
}
