#include <iostream>
#include <cmath>
using namespace std;

pair <int,int> converttopqform (float decimal) {

	int num = 0;
	while ((decimal - floor(decimal))  != 0) {
		num++;
		decimal *= 10;
	}
	//cout << "EERE " << decimal << endl; 
	
	int denom = pow(10,num);
	int i =1; 
	int numer = decimal;
	
	//cout << "Numer " << numer << " Denom " << denom << endl;

	while ( i <= num && numer%((int)pow(2,i)) == 0) {
		i++;
	}
	numer = numer/pow(2,i-1);
	denom = denom/pow(2,i-1);
	
	i =1; 
	while ( i <= num && numer%((int)pow(5,i)) == 0) {
		i++;
	}
	numer = numer/pow(5,i-1);
	denom = denom/pow(5,i-1);
	
	pair <int,int> p = make_pair(numer,denom);

	return p;
}

double myintpow(double a, int n) {
	if (n==0) return 1;
	if (n==1) return a;
	double ans = myintpow(a,n/2);
	return ans*ans*myintpow(a,n%2);
}

double mydoublepow(double a, double n) {

	double root = 1;
	double y = pow(root,n) - a;
	while (abs(y) >= 0.0001) {
		if (root != 0) root += ((double)(-1*y))/((double)(n*pow(root,n-1)));
		else root += 1.3;
	 	y = pow(root,n) - a;
	 }
	cout << "Root " << root << " " << a << endl;
	return root;
}

double mypow (double a, double n) {
	int intn = floor(n);
	float floatn = n - intn;
	cout << "idhar " << intn << " " << floatn << endl;
	pair <int,int> p = converttopqform(floatn);
	cout << "Numerator = " << p.first << " Denominator = " << p.second << endl; 
	double first = myintpow(a,intn);
	cout << "FIRST " << first << endl;
	double second = mydoublepow(myintpow(a,p.first),p.second);
	//cout << "SECOND " << second << endl;
	return first * second;

}

int main () {

	double a, n;
	cin >> a >> n;

	double ans = mypow(a,n);

	cout << "Ans " << ans << endl;

	//double x = 0.8;

	//pair <int,int> p = converttopqform(x);
	//cout << "Numerator = " << p.first << " Denominator = " << p.second << endl; 
}