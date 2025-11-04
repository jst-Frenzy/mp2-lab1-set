#include <iostream>
#include "light.h"
using namespace std;


int main() {
	Crossroad r;
	cout << "Init: \n";
	cout << r;

	for (int i = 0; i < 4; i++) {
		r.switchLight();
		cout << "After switch " << i + 1 << ":" << endl;
		cout << r;
	}
}