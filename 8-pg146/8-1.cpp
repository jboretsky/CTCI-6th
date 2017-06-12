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
 * bottom up approach: start from 0 steps, then 1 step, then 2 steps.
 */

int countWays( int n ) {
   vector<int> memo;
   // how many ways of going up 1 step?
   // how many ways of going up 2 steps?
   // how many ways of going up 3 steps?
   memo.push_back(1);
   memo.push_back(1);
   memo.push_back(2);
   for(int i = 3; i <= n; ++i) {
      memo.push_back(memo[i-1] + memo[i-2] + memo[i-3]);
   }
   return memo[n];
}

int main() {
   cout << countWays(6) << endl;
   return 0;
}
