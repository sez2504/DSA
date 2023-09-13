/*Write a program to calculate the total salary of a person. The user has to enter the basic salary 
(an integer) and the grade (an uppercase character), and depending upon which the total salary is calculated as -
    totalSalary = basic + hra + da + allow – pf
where :
hra   = 20% of basic
da    = 50% of basic
allow = 1700 if grade = ‘A’
allow = 1500 if grade = ‘B’
allow = 1300 if grade = ‘C' or any other character
pf    = 11% of basic.*/

#include<iostream>
using namespace std;

float percent(int x , int y){
	float ans = (x*y)/100.0;
	return ans;
}

int main() {
	char ch;
	int basSal;
    cin>>basSal;
	cin>>ch;
    int allow;
	if (ch=='A'){
		allow = 1700;
	}
	else if (ch=='B'){
		allow = 1500;
	}
	else {
		allow = 1300;
	}
	float hra=percent(basSal, 20);
	float da=percent(basSal, 50);
	float pf=percent(basSal, 11);
	float totalSalary = basSal + hra + da + allow - pf;
	int integral_part = totalSalary;
	float float_part = totalSalary-integral_part;
	if (float_part>=0.5){
		integral_part++;
	}
	cout << integral_part << endl;
}
