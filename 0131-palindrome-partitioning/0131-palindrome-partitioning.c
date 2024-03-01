int isPalindrome(char* s, int start, int end) {
    while (start < end) {
        if (s[start++] != s[end--]) return 0;
    }
    return 1;
}

// Recursive function to find palindrome partitioning
void dfs(char* s, int start, char*** result, int* returnSize, int** returnColumnSizes, char** path, int pathSize) {
    if (s[start] == '\0') { // Base case: reach the end of the string
        result[*returnSize] = (char**)malloc(sizeof(char*) * pathSize);
        (*returnColumnSizes)[*returnSize] = pathSize;
        for (int i = 0; i < pathSize; ++i) {
            result[*returnSize][i] = (char*)malloc(strlen(path[i]) + 1);
            strcpy(result[*returnSize][i], path[i]);
        }
        (*returnSize)++;
        return;
    }
    for (int i = start; s[i] != '\0'; ++i) {
        if (isPalindrome(s, start, i)) {
            // If s[start...i] is a palindrome, add it to the path and recurse
            path[pathSize] = (char*)malloc(i - start + 2);
            strncpy(path[pathSize], s + start, i - start + 1);
            path[pathSize][i - start + 1] = '\0'; // Null-terminate the new string
            dfs(s, i + 1, result, returnSize, returnColumnSizes, path, pathSize + 1);
            free(path[pathSize]); // Backtrack
        }
    }
}

char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    int len = strlen(s);
    char*** result = (char***)malloc(sizeof(char**) * pow(2, len)); // Assuming max 1000 partitions
    *returnColumnSizes = (int*)malloc(sizeof(int) * pow(2, len));
    *returnSize = 0;
    char** path = (char**)malloc(sizeof(char*) * len); // Maximum possible partition length is len
    dfs(s, 0, result, returnSize, returnColumnSizes, path, 0);
    free(path);
    return result;
}