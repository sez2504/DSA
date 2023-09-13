#include <iostream>
#include <string>
using namespace std;

#include <unordered_map>

#include <unordered_map>

string uniqueChar(string str) {
	string ans;
	unordered_map<char,bool> seen;
	for (int i=0 ; i<str.length() ; i++){
		if (seen.count(str[i])>0){
			continue;
		}
		seen[str[i]]=true;
		ans = ans + str[i];
	}
	return ans;
}

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}