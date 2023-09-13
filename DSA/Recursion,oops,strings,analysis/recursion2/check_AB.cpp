#include <iostream>
using namespace std;

using namespace std;

bool checkAB(char input[]) {
	static int flag=0;
	if (input[0]=='\0'){
		return true;
	}
	if (input[0]=='a'){
		flag++;
		if (input[1]=='\0'||input[1]=='a'||(input[1]=='b'&&input[2]=='b')){
			checkAB(input+1);
		}
		else{
			return false;
		}
	}
	else if (input[0]=='b'&&input[1]=='b'){
		if (flag==0){
			return false;
		}
		else {
				if (input[2]=='a'||input[2]=='\0'){
				checkAB(input+2);
			}
			else{
				return false;
			}
		}
	}
}

int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}
