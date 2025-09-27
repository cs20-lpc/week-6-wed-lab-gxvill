#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
 * Function prototypes
*******************************************************************************/

unsigned fact(unsigned, unsigned);
unsigned fib(unsigned, unsigned, unsigned);
unsigned mult(unsigned, unsigned, unsigned);
unsigned power(unsigned, unsigned, unsigned);
unsigned product(unsigned, unsigned, unsigned);

/*******************************************************************************
 * Description:
 * Starting point of the program. Calls various recursive functions that can be
 * optimized using tail recursion.
 * 
 * Input:
 * N/A
 *
 * Output:
 * An integer to signal to the OS the exit code.
*******************************************************************************/

int main() {
    // try a ridiculous case that won't work without tail recursion
    cout << "6 * 123000 = " << mult(6, 123000, 0) << endl;
    
    // these functions can't demonstrate the usefulness of tail recursion
    // due to data type overflow, but still, good practice
    cout << "3 ^ 10 = " << power(3, 10, 1) << endl;
    cout << "8 * 9 * ... * 15 = " << product(8, 15, 1) << endl;
    cout << "10! = " << fact(10, 1) << endl;

    // without tail recursion, this next call is going to take a while
    cout << "50th Fibonacci number is " << fib(50, 0, 1) << endl;

    // terminate
    return 0;
}

/*******************************************************************************
 * Function definitions below are NOT tail recursive!
 * TODO: make them tail recursive :)
*******************************************************************************/

unsigned fact(unsigned n, unsigned res = 1) {
    // base cases (combined)
    if (n <= 1) {
        return res;
    }

    // recursive case
    return fact(n - 1, res * n);
}

unsigned fib(unsigned n, unsigned x = 0, unsigned y = 1) {
    // base case 1
    if (n == 0) {
        return x;
    }

    // base case 2
    else if (n == 1) {
        return y;
    }

    // recursive case
    return fib(n - 1, y, x + y);
}

unsigned mult(unsigned x, unsigned y, unsigned res = 0) {
    // base case
    if (y == 0) {
        return res;
    }

    // recursive case
    return mult(x, y - 1, res + x);
}

unsigned power(unsigned x, unsigned y, unsigned res = 0) {
    // base case
    if (y == 0) {
        return res;
    }

    // recursive case
    return power(x, y - 1, res * x);
}

unsigned product(unsigned x, unsigned y, unsigned res = 1) {
    // base case
    if (x > y) {
        return res;
    }

    // recursive case
    return product(x + 1, y, res * x);
}
