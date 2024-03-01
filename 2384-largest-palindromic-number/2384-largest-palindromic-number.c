char* largestPalindromic(char* num) {
    int countArr[10] = {0}; // 0부터 9까지의 개수 세기
    int n = strlen(num);
    for (int i = 0; i < n; i++) {
        countArr[num[i] - '0']++;
    }

    char* front = (char*)malloc(n + 1); // 충분한 크기 할당
    front[0] = '\0'; // 초기화
    char middle[2] = ""; // 홀수 개 있는 숫자 추가하기 위한 변수
    
    // palindrome의 앞부분 구성
    for (int i = 9; i >= 0; i--) {
        int share = countArr[i] / 2;
        if (i == 0 && strlen(front) == 0) continue; // 0으로 시작하는 숫자는 제외
        for (int j = 0; j < share; j++) {
            char temp[2] = {i + '0', '\0'};
            strcat(front, temp);
        }
        countArr[i] %= 2; // 나머지만 남김
    }

    // 홀수개 있는 숫자 추가하기
    for (int i = 9; i >= 0; i--) {
        if (countArr[i]) {
            middle[0] = i + '0';
            break;
        }
    }

    if (strlen(front) == 0 && strlen(middle) == 0) {
        free(front); // 메모리 해제
        return "0";
    }

    char* result = (char*)malloc(2 * n + 2); // 결과를 저장할 충분한 크기 할당
    strcpy(result, front);
    if (strlen(middle) > 0) strcat(result, middle);
    
    char* reverseFront = (char*)malloc(strlen(front) + 1);
    strcpy(reverseFront, front);
    
    // front 문자열 뒤집기
    int len = strlen(front);
    for (int i = 0; i < len / 2; i++) {
        char temp = reverseFront[i];
        reverseFront[i] = reverseFront[len - i - 1];
        reverseFront[len - i - 1] = temp;
    }
    strcat(result, reverseFront);

    free(front); // 더 이상 필요 없으므로 메모리 해제
    free(reverseFront); // 메모리 해제

    return result; // 결과 반환
}
