bool isPalindrome(char* s1, char *s2, int n);
bool isPalindromeHelp(char* sub, int i, int j);

bool checkPalindromeFormation(char* a, char* b) {
    int n = 0;
    while (a[n] != '\0') {
        n++;
    }
    return (isPalindrome(a, b, n)) || (isPalindrome(b, a, n));
}

bool isPalindrome(char* s1, char *s2, int n) {
    int i = 0;
    int j = n-1;

    while (i < j) {
        if (s1[i] != s2[j]) {
            break;
        }
        i++;
        j--;
    }
    return isPalindromeHelp(s1, i, j) || isPalindromeHelp(s2, i, j);
}

bool isPalindromeHelp(char* sub, int i, int j) {
    while (i < j) {
        if (sub[i] != sub[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}