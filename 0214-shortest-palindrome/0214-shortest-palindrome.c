bool isPalindrome(char *str, int start, int end) {
    while (start < end) {
        if (str[start++] != str[end--]) return false;
    }
    return true;
}


char* shortestPalindrome(char* s) {
    // s가 palindrome이면 바로 s return(s=""도 포함)
    if (isPalindrome(s, 0, strlen(s)-1)) return s;
    
    // s를 뒤에서 하나씩 빼가면서 palindrome이 되는 순간 찾음. end 뒷부분이 앞에 추가해야할 문자열이 됨
    int end;
    for(end = strlen(s)-1; end >= 0; end--){
        if (isPalindrome(s, 0, end)) break;
    }
    
    // 새롭게 만들어질 palindrome 크기 : 기존 크기 + 앞에 추가해야할 부분 + '\0', strlen(s) + (strlen(s)-end) + 1
    char * result = malloc(sizeof(char) * strlen(s)+strlen(s)-end+1);

    // 1. 
    // 앞에 추가해야할 문자 추가
    for(int i = 0; i < strlen(s)-1-end; i++){
        result[i] = s[strlen(s)-1-i];
    }
    
    // result에 NULL추가해서 일단 문자열로 만들어줌
    result[strlen(s)-end-1] = '\0';
    
    // result 뒤에 s 붙임
    strcat(result, s);

    // 2.     
    // // Filling the result with characters to be added at the front
    // int addLen = strlen(s) - 1 - end;
    // for (int i = 0; i < addLen; i++) {
    //     result[i] = s[strlen(s) - 1 - i];
    // }
    // // Copying the original string s to the result after the added characters
    // strcpy(result + addLen, s);

    return result;

}