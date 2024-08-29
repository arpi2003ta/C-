#include <iostream>
#include <cmath>
using namespace std;

// Function to check if a number is prime
bool isPrime(int n) 
{
    int i;
    if(n<=1)
        return false;
    for(i=2;i<n;i++)
    {
        if(n%i==0)
        {
           
           return false;
        }
    }
    return true;
}

// Function to check if a number is a Fibonacci number
bool fib(int n)
{
    if (n == 0 || n == 1) 
        return true;
    int t1 = 0, t2 = 1;
    int nexterm = t1 + t2;
    while (nexterm <= n)
    {
        if (nexterm == n) return true;
        t1 = t2;
        t2 = nexterm;
        nexterm = t1 + t2;
    }
    return false;
}
// Function to check if a number is both prime and Fibonacci
int isPrimeAndFibonacci(int n) {
    if (isPrime(n) && fib(n)) {
        return 1;
    }
    return 0;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    int result = isPrimeAndFibonacci(number);
    cout << "Result: " << result << endl;

    return 0;
}