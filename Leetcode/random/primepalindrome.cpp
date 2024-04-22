class Solution {
public:
    bool ispalindrome(int n) {
        int reversed = 0, original = n;
        while (n > 0) {
            reversed = reversed * 10 + n % 10;
            n /= 10;
        }
        return original == reversed;
    }

    bool isprime(int num) {
        if (num <= 1) {
            return false;
        }
        if (num == 2) {
            return true;
        }
        if (num % 2 == 0) {
            return false;
        }
        for (int i = 3; i <= num / 2; i += 2) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    int primePalindrome(int n) {
        while (true) {
            if (n >= 2 && ispalindrome(n) && isprime(n)) {
                return n;
            }
            n++;
            if (n >= 10'000'000 && n < 100'000'000) { // skip to next odd-length palindrome
                n = 100'000'000;
            }
        }
    }
};