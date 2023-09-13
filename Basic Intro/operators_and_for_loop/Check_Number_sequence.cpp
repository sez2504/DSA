#include<iostream>
using namespace std;

int main() {
	bool answer = true;
	int n;
	cin >> n;
	int i;
	int arr[n];
    for (i=0; i<n ; i++){
        cin>>arr[i];
	}
    for (int i = 0 ; i<n ;i++){
        cout<<arr[i]<<" ";
    }
	int flag=0;
    if (n>3){
        for (i=0; i<n-2 ; i++){
            if ((arr[i+2]-arr[i+1])*(arr[i+1]-arr[i])<=0) {
                break;
            }
			if (arr[i+1]-arr[i]>0){
				flag++;
			}
			else{
				flag--;
			}
	    }
        for (; i<n-2 ; i++){
			if (arr[i+1]-arr[i]>0){
				flag--;
			}
			else{
				flag++;
			}
			if (flag!=0){
				if ((arr[i+2]-arr[i+1])*(arr[i+1]-arr[i])<=0) {
               	 	answer=false;
                	break;
           	 	}
			}
	    }
    }

    else if (n==3){
        if (arr[0]==arr[1] || arr[1]==arr[2] || arr[2]==arr[0]){
            answer=false;
        }
    }

    else if (n==2){
        if (arr[0]==arr[1]){
            answer=false;
        }
    }
	
    if (answer) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}

/*alternate:-
#include <iostream>
using namespace std;

int main()
{
    int n;
	cin >> n;
    int prev;
    cin >> prev;
    int count = 2 , current;
    bool isDec =true;
    while (count<=n){
        cin >> current;
        if (current == prev){
            cout<<"false";
            return 0;
        }
        count++;
        if (current < prev){
            if (isDec=false) {
                cout<<"false";
                return 0;
            }  
        }
        else {
            if (isDec==true){
                isDec=false;
            }
        }
        prev=current;
    }
    cout<<"true";
}*/