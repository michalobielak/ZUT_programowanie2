#include <iostream>
#include <string>
using namespace std;

class Complex
{
public:
	Complex(string);
	string ConvertFromSymbolic();

private:
	string  Number;
	string AddZeros(int, int);
};


Complex::Complex(string  _Number)
{
	Number = _Number;
}


string Complex::AddZeros(int Count, int CountFraction)
{
	int d = Count - CountFraction;
	string Zeros = "";
	for(int i = 0; i < d; i++) {
		Zeros += '0';
	}
	return Zeros;
}

string Complex::ConvertFromSymbolic() {
	int d = Number.length();
	string s = "";
	bool Fraction = false;
	int CountFraction = 0;
	for (int i = 0; i < d; i++) {
		if (Number[i] == '0' ||
			Number[i] == '1' ||
			Number[i] == '2' ||
			Number[i] == '3' ||
			Number[i] == '4' ||
			Number[i] == '5' ||
			Number[i] == '6' ||
			Number[i] == '7' ||
			Number[i] == '8' ||
			Number[i] == '9') {
			s += Number[i];
			if (Fraction == true) {
				CountFraction++;
			}
		} else if (Number[i] == '.') {
			Fraction = true;
		} else if (Number[i] == 'M') {
			s += AddZeros(6, CountFraction);
		} else if (Number[i] == 'B') {
			s += AddZeros(9, CountFraction);
		} else if (Number[i] == 'T') {
			s += AddZeros(12, CountFraction);
		} else if (Number[i] == 'Q' && Number[i+1] == 'a') {
			s += AddZeros(15, CountFraction);
		} else if (Number[i] == 'Q' && Number[i+1] == 'i') {
			s += AddZeros(18, CountFraction);
		} else if (Number[i] == 'S' && Number[i+1] == 'x') {
			s += AddZeros(21, CountFraction);
		} else if (Number[i] == 'S' && Number[i+1] == 'p') {
			s += AddZeros(24, CountFraction);
		} else if (Number[i] == 'O' && Number[i+1] == 'c') {
			s += AddZeros(27, CountFraction);
		}	 
	}
	return s;
}

int main()
{
	Complex firstObject("4M");
	Complex secondComplexObject("54T");
	Complex thirdComplex("5.434B");
	cout << firstObject.ConvertFromSymbolic() << endl;
	cout << secondComplexObject.ConvertFromSymbolic() << std::endl;
	cout << thirdComplex.ConvertFromSymbolic() << std::endl;
}


