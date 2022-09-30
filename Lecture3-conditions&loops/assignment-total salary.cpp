#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    float basic;char grade;int total;
	cin>>basic>>grade;
	float hra = basic*0.2;
	float da = basic*0.5;
	float pf = (11*basic)/100;
	if((int)grade == 65){
		total = round(basic + hra + da + 1700 - pf);}
	else if ((int)grade == 66){
		total = round(basic + hra + da + 1500 - pf);}
	else total = round(basic + hra + da + 1300 - pf);
	cout<<(total);

    return 0;
}
	