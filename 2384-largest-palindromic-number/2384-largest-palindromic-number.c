char* largestPalindromic(char* num) {
    int hash[10] = {0};
    int len = strlen(num);
    int ind = 0;
    char output[len+1];
    

    for(int i = 0; i < len; i++) {//output char초기화와 Hashing 동시 진행
        ind = num[i]-'0';
        output[i] = ' ';
        hash[ind]++;
    }

    output[len] = '\0';

    char max_med = ' ';
    int fill = 0;
    int finlen = 0;
    for(int i = 9; i >= 0; i--) { //Hash 돌면서, Output 맨 앞,끝부터 하나씩 채워줌
        if(hash[i]%2 == 1) { //홀수인 경우, 가장 큰 숫자만 1개 넣어줌
            if(max_med == ' ') {
                max_med = i + '0';
                hash[i]--;
            }
        }
        else if (i==0 && fill==0 && max_med == ' '){ //'0' 까지도 아무것도 안 채워져 있었으면, 0을 하나 넣어줌.
            max_med = '0';
            hash[i]--;
        }
        
        if(hash[i]>1) {
            while(hash[i] > 1) {
                if(i==0 && fill == 0) {
                    break;
                }
                output[fill] = i + '0';
                output[len-1-fill] = i +'0';
                fill++;
                hash[i] -= 2;
                finlen+=2;
            }
        }
    }
    if(max_med != ' ') { //가운데 값 있었으면 채워줌
        output[len/2] = max_med;
        finlen++;
    }
    
    //중간의 ' ' 지운 새로운 char array output으로 보냄
    char* fin_out = (char*)malloc((finlen + 1) * sizeof(char));

    int new_ind = 0;
    for(int i = 0; i < len; i++) {
        if(output[i] != ' ') {
            fin_out[new_ind] = output[i];
            new_ind++;
        }
    }
    fin_out[finlen] = '\0';
    return fin_out;
}