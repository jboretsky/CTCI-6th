#include <vector>
#include <iostream>

using namespace std;

/*
 * Think about getting to the nth step
 * Could have gotten there from step:
 * (n-1)
 * (n-2)
 * (n-3)
 * How many ways could we get to those 3 steps? continue the same way..
 * Top down approach: countWays(n-1) + countWays(n-2) + countWays(n-3);
 */

// bottom up approach
int countWays( int n ) {
   vector<int> memo;
   memo.push_back(1);
   memo.push_back(1);
   memo.push_back(2);
   for(int i = 3; i <= n; ++i) {
      memo.push_back(memo[i-1] + memo[i-2] + memo[i-3]);
   }
   return memo[n];
}


// top down approach
int memoize( vector<int>& memo, int n ) {
   if(memo[n] != -1) {
      return memo[n];
   } else {
      memo[n] = memoize(memo, n-1) + memoize(memo,n-2) + memoize(memo,n-3);
      return memo[n];
   }
}

int countWays2( int n ) {
   vector<int> memo(n+1, -1);
   memo[0] = 1;
   memo[1] = 1;
   memo[2] = 2;
   return memoize(memo, n);
}

int main() {
   cout << countWays2(3) << endl;
   return 0;
}
