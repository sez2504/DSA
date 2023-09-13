#include <iostream>
#include <string>
#include <string>
using namespace std;

int keypad(int num, string output[]){
    if (num==0){
        output[0]="";
        return 1;
    }
    int smallernum = num/10;
    int smallOutputSize = keypad(smallernum , output);
    string temp[500];
    for (int k=0 ; k<smallOutputSize ; k++){
        temp[k]=output[k];
    }
    if ((num%10)>=2 && (num%10)<=6){
        for (int j=0 ; j<3; j++){
            for (int i=0 ; i<smallOutputSize ; i++){
                output[j*smallOutputSize+i]=temp[i]+(char)(3*(num%10)+91+j);
            }
        }
        return 3*smallOutputSize;
    }
    else if ((num%10)==7){
        for (int j=0 ; j<4; j++){
            for (int i=0 ; i<smallOutputSize ; i++){
                output[j*smallOutputSize+i]=temp[i]+(char)(112+j);
            }
        }
        return 4*smallOutputSize;
    }
    else if ((num%10)==8){
        for (int j=0 ; j<3; j++){
            for (int i=0 ; i<smallOutputSize ; i++){
                output[j*smallOutputSize+i]=temp[i]+(char)(116+j);
            }
        }
        return 3*smallOutputSize;
    }
    else if ((num%10)==9){
        for (int j=0 ; j<4; j++){
            for (int i=0 ; i<smallOutputSize ; i++){
                output[j*smallOutputSize+i]=temp[i]+(char)(119+j);
            }
        }
        return 4*smallOutputSize;
    }
}

/*alt:-
string getstring(int d){
    switch (d){
        case 2:
            return "abc";
        case 3:
            return "def";  
        case 4:
            return "ghi";    
        case 5:
            return "jkl"; 
        case 6:
            return "mno"; 
        case 7:
            return "pqrs"; 
        case 8:
            return "tuv"; 
        case 9:
            return "wxyz"; 
        default:
            return " ";
    }
}

int keypad(int num, string output[]){
    if (num==0){
        output[0]="";
        return 1;
    }
    int lastdigit = num%10;
    int smallernum = num/10;
    int smallOutputSize = keypad(smallernum , output);
    string options = getstring(lastdigit);
    
    for (int i=0 ; i<options.length()-1 ; i++){
        for (int j=0 ; j<smallOutputSize ; j++){
            output[j+(i+1)*smallOutputSize]=output[j];
        }
    }
   int k=0;
   for (int i=0 ; i<options.length() ; i++){
        for (int j=0 ; j<smallOutputSize ; j++){
            output[k]=output[k]+options[i];
            k++;
        }
    }
    return smallOutputSize*options.length();
}*/

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
