#include <string>
#include <iostream>
#include <regex>

using namespace std;

string URLify( string s ) {
   regex r(" ");
   return regex_replace(s, r, "%20");
}

int main() {
   cout << URLify("hello world") << endl;
   return 0;
}
