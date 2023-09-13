bool checkPalindrome(char input[]) {
    //cout<<input<<endl;
    int i=0;
    while(input[i]!='\0'){
        i++;
    }
    //cout<<i<<endl;
    if (i==0){
        return true;
    }
    if (input[0]!=input[i-1]){
        return false;
    }
    input[i-1]='\0';
    bool ans = checkPalindrome(input+1);
    return true;
}