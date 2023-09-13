#include <iostream>
using namespace std;

void replacePi(char str[]) {
	int len=0;
	while (str[len]!='\0'){
		len++;
	}
	if (len==0||len==1){
		return;
	}
	if (str[0]=='p'&&str[1]=='i'){
		for (int j=0 ; j<2 ; j++){
			int len=0;
			while (str[len]!='\0'){
				len++;
			}
			str[len+1]='\0';
			for (int i=len-1 ; i>=2 ; i--){
				str[i+1]=str[i];
			}
		}
		str[0]='3';
		str[1]='.';
		str[2]='1';
		str[3]='4';
	}
	replacePi(str+1);
}

/*alt:-
void replacePiHelper(char str[], int start)
{
 
    // Base condition
    // if the string is empty
    // or of length one
    if (str[start] == '\0' || str[start + 1] == '\0') {
        return;
    }
 
    // Getting the answer from
    // recursion for the smaller
    // problem
    replacePiHelper(str, start + 1);
 
    // Small calculation part
    // if the first character is 'p'
    // and the first character of the part
    // passed to recursion is 'i' then replace
    // "pi" with "3.14"
    if (str[start] == 'p' && str[start + 1] == 'i') {
 
        // Shifting the characters to
        // right side to put 3.14 in
        // the character array
        for (int i = strlen(str); i >= start + 2; i--) {
            str[i + 2] = str[i];
        }
 
        // Replacing with "3.14"
        str[start] = '3';
        str[start + 1] = '.';
        str[start + 2] = '1';
        str[start + 3] = '4';
    }
}
 
// Function to replace pi with 3.14
void replacePi(char str[])
{
    replacePiHelper(str, 0);
}*/

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}