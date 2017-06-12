# Notes on Recursion and Dynamic Programming

- "Design an algorithm to compute the nth..." common recursive problem.
- Divides a problem into subproblems.

## Recursion

### Bottom up approach

- Often most intuitive.
- Start with knowing how to solve the problem for a simple case, like a list with only 1 element
- Figure out how to solve for 2 elements, then 3, and so on.

### Top down approach

- More complex.
- Think of how we can divide the problem for case N into subproblems.

### Half and half approach

- Often effective to divide the data set in half.
- Ex. Merge sort uses the half and half approach (see chapter 8, sorting algs)

### Do we really need recursion?

- Often can be solved iteratively with much better space efficiency.
- Should think about whether there is a simple solution that is iterative first.

## Dynamic Programming & Memoization

- Means taking a recursive algorithm, and finding the overlapping subproblems.
- Top down dp is sometimes called "memoization" whereas bottom up is called "dynamic programming".

### Fibonacci Example

#### Recursive

```
// runtime is O(2^n)
int fibonacci(int i) {
   if( i == 0 ) return 0;
   if( i == 1 ) return 1;
   return fibonacci( i - 1 ) + fibonacci( i - 2 );
}
```

#### Top down dynamic programming (or memoization)

- In the recursive solution, we end up making the same calls multiple times
   - For example fib(5) -> fib(4) + fib(3)    and fib(4) -> fib(3) + fib(2)
   - See how fib(3) is called twice
- We shouldnt need to do more than O(n) calls, since there are only O(n) possible values.
- Each time we compute fib(i), we can just cache the result and use it later again.

```
int fibonacci(int n) {
   return fibonacci(n, new int[n+1]);
}

int fibonacci(int i, int[] memo) {
   if(i == 0 || i == 1) return i;

   if(memo[i] == 0) {
      memo[i] = fibonacci(i-1, memo) + fibonacci(i-2, memo);
   }
   return memo[i];
}
```

#### Bottom up dynamic programming

- We can just go from the start, instead of the end and add up our values until we hit the number we're looking for.
- This no longer needs to be recursive.
- ends up being the most intuitive.

```
int fibonacci(int n) {
   if(n == 0) return 0;
   if(n == 1) return 1;
   int[] memo = new int[n];

   memo[0] = 0;
   memo[1] = 1;
   for( int i = 2; i < n; i++) {
      memo[i] = memo[i-1] + memo[i-2];
   }
   return memo[n-1] + memo[n-2];
}
```
