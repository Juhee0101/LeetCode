int countPalindromicSubsequence(char* s) {
    int cnt = 0, i = 0, j = 0, letters = 0;
    int len = strlen(s);
    char visited[26] = {0,};
    int endidx = 0;

    for (i = 0; i < len - 1; i++) {
        if (visited[s[i]-'a']) continue;
        int frequency[26] = {0,};
        visited[s[i]-'a'] = 1;
        endidx = 0;
        for (j = len-1; j > i; j--) {
            if (endidx)
                frequency[s[j] - 'a']++;
            else if (s[j] == s[i]) endidx = j;
        }
        if (endidx > i+1) {
            for (j = 0 ; j < 26; j++) {
                if (frequency[j]) cnt++;
            }
        }
    }
  
    return cnt;
}