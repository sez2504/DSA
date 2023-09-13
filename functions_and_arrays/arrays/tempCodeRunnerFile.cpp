bool splitArray(int *input, int size) {
    sort_3_and_5(input,size);
    int sum1=0 , sum2 = 0;
    for (int i=0 ; i<size ; i++){
        if (input[i]%5==0){
            sum1+=input[i];
        }
        else if (input[i]%3==0){
            sum2+=input[i];
        }
        else {
            if (sum1>sum2){
                sum2+=input[i];
            }
            else if (sum1<=sum2){
                sum1+=input[i];
            }
        }
        cout<<"sum1 : "<<sum1;
        cout<<" sum2 : "<<sum2<<endl;
    }
    if (sum1==sum2){
        return true;
    }
    else{
        return false;
    }
}