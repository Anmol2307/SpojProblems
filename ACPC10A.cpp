#include <iostream>

using namespace std;

int main () {
	int a, b, c;
	while (1) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) break;
		if ((b-a) != 0 && (b-a) == (c-b)) cout << "AP " << c + (b-a) << endl;
		else if ((double)b/a != 0 && (double)c/b == (double)b/a) cout << "GP " << (double)c*b/a << endl;
	}
}