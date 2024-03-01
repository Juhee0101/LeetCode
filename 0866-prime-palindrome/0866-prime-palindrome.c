#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int reverse(int num) {
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

bool is_palindrome(int num) {
    return num == reverse(num);
}

// int next_palindrome(int n) {
//     while (true) {
//         n++;
//         if (is_palindrome(n)) return n;
//     }
// }

int primePalindrome(int n) {
    if (n <= 2) return 2;
    if (n % 2 == 0) n++;  // Ensure n is odd to skip even numbers
    while (true) {
        if (is_palindrome(n) && is_prime(n)) return n;
        n += 2;  // Increment by 2 to maintain oddness
    }
}
