#include <iostream>
using namespace std;

string AddZeros(int Count, int CountFraction)
{
	int d = Count - CountFraction;
	string Zeros = "";
	for(int i = 0; i < d; i++) {
		Zeros += '0';
	}
	return Zeros;
}

string ConvertFromSymbolic(string Symbolic) {
	int d = Symbolic.length();
	string Number = "";
	bool Fraction = false;
	int CountFraction = 0;
	for (int i = 0; i < d; i++) {
		if (Symbolic[i] == '0' ||
			Symbolic[i] == '1' ||
			Symbolic[i] == '2' ||
			Symbolic[i] == '3' ||
			Symbolic[i] == '4' ||
			Symbolic[i] == '5' ||
			Symbolic[i] == '6' ||
			Symbolic[i] == '7' ||
			Symbolic[i] == '8' ||
			Symbolic[i] == '9') {
			Number += Symbolic[i];
			if (Fraction == true) {
				CountFraction++;
			}
		} else if (Symbolic[i] == '.') {
			Fraction = true;
		} else if (Symbolic[i] == 'M') {
			Number += AddZeros(6, CountFraction);
		} else if (Symbolic[i] == 'B') {
			Number += AddZeros(9, CountFraction);
		} else if (Symbolic[i] == 'T') {
			Number += AddZeros(12, CountFraction);
		} else if (Symbolic[i] == 'Q' && Symbolic[i+1] == 'a') {
			Number += AddZeros(15, CountFraction);
		} else if (Symbolic[i] == 'Q' && Symbolic[i+1] == 'i') {
			Number += AddZeros(18, CountFraction);
		} else if (Symbolic[i] == 'S' && Symbolic[i+1] == 'x') {
			Number += AddZeros(21, CountFraction);
		} else if (Symbolic[i] == 'S' && Symbolic[i+1] == 'p') {
			Number += AddZeros(24, CountFraction);
		} else if (Symbolic[i] == 'O' && Symbolic[i+1] == 'c') {
			Number += AddZeros(27, CountFraction);
		}	 
	}
	return Number;
}

int main () {
	cout << ConvertFromSymbolic("4M") << endl;
	cout << ConvertFromSymbolic("54T") << endl;
	cout << ConvertFromSymbolic("5.434B") << endl;
	return 0;
}
