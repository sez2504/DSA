/*Write a program to count and print the total number of characters (lowercase english alphabets only), 
digits (0 to 9) and white spaces (single space, tab i.e. '\t' and newline i.e. '\n') entered till '$'.
That is, input will be a stream of characters and you need to consider all the characters which are entered till '$'.
Print count of characters, count of digits and count of white spaces respectively (separated by space).*/

#include<iostream>
using namespace std;

int main(){
	char c;
	c=cin.get();
	int char_count = 0;
	int digit_count = 0;
	int space_count = 0;
	while (c != '$'){
		if (c >= 'a' && c <='z'){
			char_count++;
		}
		else if (c>='0' && c<='9'){
			digit_count++;
		}
		else if(c==' '||c=='\n'||c=='\t'){
			space_count++;
		}
		c=cin.get();
	}
	cout << char_count << " " << digit_count << " " << space_count << endl;
}