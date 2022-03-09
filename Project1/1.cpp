#include <iostream>

using namespace std;

class Product {
	int var;

public:
	Product(int x = 0) : var(x) {}

	Product& operator++() {
		var += 1;
		return *this;
	}
	Product operator++(int) {
		Product tmp(var);
		var += 1;
		return tmp;
	}
	void print() const { cout << var << "\n"; }
	void set(int x) { var = x; }
};




int main() {
	Product a(10);
	
	a++.print();
	(++a).print();
}