#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <stdexcept>


using namespace std;

class Matrix
{
public:
	Matrix(int, int);
	Matrix(string);
	void changeValue(int, int, int);
	Matrix addNumber(int);
	int getCell(int, int);
	string getLine(int);
	string getColumn(int);
	string getMatrix();
	void transposed();
	void saveToFile(string);
	Matrix addMatrix(vector<vector<int> >, vector<vector<int> >);
	int getWidth();
	int getHeight();
	bool equalDimensions(Matrix &, Matrix & );
	vector<vector<int> > matrix;
	Matrix add(Matrix &);
	Matrix substract(Matrix &);
	Matrix multiply(Matrix &);
	

private:
	int width;
	int height;
	
};
Matrix::Matrix(int width, int height)
{
	this->height = height;
	this->width = width;
	vector<int> tab;
  	for(int j=0;j<height;j++) {
  		tab.push_back(0);
  	}
	
	for (int i = 0; i < width; i++) {
		this->matrix.push_back(tab);
	}
}

Matrix::Matrix(string name)
{
	string lineFromFile;
	int value;
	
	ifstream file(name.c_str());
	if (file.is_open()) {
		getline(file, lineFromFile);
		this->width = atoi(lineFromFile.c_str());
		getline(file, lineFromFile);
		this->height = atoi(lineFromFile.c_str());
		vector<int> tab ;
  		for(int j=0;j<height;j++) {
  			tab.push_back(0);
  		}
	
		for (int i = 0; i < width; i++) {
			this->matrix.push_back(tab);
		}
		int i = 0;
		while (!file.eof() && i < this->width) {
			getline(file, lineFromFile);
			stringstream line;
			line << lineFromFile;
			for (int j = 0; j < this->height; j++) {
				line >> value;
				this->matrix[i][j] = value;
			}
			i++;	
		}
	}
	file.close();
}

void Matrix::changeValue(int width, int height, int value)
{
	this->matrix[width][height] = value;
}

Matrix Matrix::addNumber(int value)
{
	Matrix added = Matrix(this->getWidth(), this->getHeight());
	for (int i = 0; i < this->getWidth(); i++) {
		for (int j = 0; j < this->getHeight(); j++) {
			added.matrix[i][j] = this->matrix[i][j] + value;
		}
	}
	return added;
}

int Matrix::getCell(int width, int height)
{
	return this->matrix[width][height];
}

string Matrix::getLine(int width)
{
	stringstream line;
	for (int j = 0; j < this->height; j++){ 
		line << this->matrix[width][j] << " ";
	}
	return line.str();
}

string Matrix::getColumn(int height)
{
	stringstream column;
	for (int i = 0; i < this->width; i++){ 
		column << this->matrix[i][height] << " ";
	}
	return column.str();
}

string Matrix::getMatrix()
{
	stringstream matrix;
	for (int i = 0; i < this->width; i++) {
		matrix << this->getLine(i) << endl;
	}
	return matrix.str();
}

void Matrix::transposed()
{
	vector<vector<int> > newMatrix;
	vector<int> tab;
	for(int j=0;j<this->width;j++) {
  		tab.push_back(0);
  	}
	
	for (int i = 0; i < this->height; i++) {
		newMatrix.push_back(tab);
	}
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			newMatrix[j][i] = this->matrix[i][j];
		}
	}
	this->matrix = newMatrix;
	int bufor = this->height;
	this->height = this->width;
	this->width = bufor;
}

void Matrix::saveToFile(string name)
{
	ofstream file(name.c_str());
	if (file.is_open()) {
		file << this->width << endl;
		file << this->height << endl;
		file << this->getMatrix();
	}
	file.close();

}

int Matrix::getHeight()
{
	return this->height;
}

int Matrix::getWidth()
{
	return this->width;
}

bool Matrix::equalDimensions(Matrix & a, Matrix & b)
{
	return (a.getWidth() == b.getWidth() && a.getHeight() == b.getHeight());
}

Matrix Matrix::add(Matrix &toAdd)
{
	if (!this->equalDimensions(toAdd, *this)){
		throw std::runtime_error("Trying to multiply matrices where the lefthand Matrix columnCount and righthand Matrix rowCount don't match!");
	}
	
	Matrix added = Matrix(toAdd.getWidth(), toAdd.getHeight());

	for (int row = 0; row < this->getWidth(); row++)
		for (int column = 0; column < this->getHeight(); column++)
			added.matrix[row][column] = this->matrix[row][column] + toAdd.matrix[row][column];

	return added;
}

Matrix Matrix::substract(Matrix &toSubstract)
{
	if (!this->equalDimensions(toSubstract, *this)){
		throw std::runtime_error("Trying to substract matirces of diffrent sizes!");
 }
	
	Matrix substracted  = Matrix(toSubstract.getWidth(), toSubstract.getHeight());

	for (int row = 0; row < this->getWidth(); row++)
		for (int column = 0; column < this->getHeight(); column++)
			substracted.matrix[row][column] = this->matrix[row][column] - toSubstract.matrix[row][column];

	return substracted;
}

Matrix Matrix::multiply(Matrix &toMultiply)
{
	if (this->getHeight() != toMultiply.getWidth()){
		throw std::runtime_error("Trying to multiply matrices where the lefthand Matrix columnCount and righthand Matrix rowCount don't match!");
	}
	Matrix multiplied = Matrix(this->getWidth(), toMultiply.getHeight());
	for (int row = 0; row < multiplied.getWidth(); row++)
		for (int column = 0; column < multiplied.getHeight(); column++)
			for (int edgeValue = 0; edgeValue < this->getHeight(); edgeValue++)
				multiplied.matrix[row][column] += this->matrix[row][edgeValue] * toMultiply.matrix[edgeValue][column];

	return multiplied;
}

int main()
{
	SYSTEMTIME st;
	stringstream fileName;
	string name;
	Matrix matrixA("macierzA.txt");
	Matrix matrixB("macierzB.txt");
	Matrix matrixC = matrixA.multiply(matrixB);
	cout << "Matrix A" << endl;
	for (int i = 0; i< matrixA.getWidth(); i++){
		cout << matrixA.getLine(i) << "   ";
	}
	cout << endl;
	cout << "Matrix B   Matrix C" << endl;
	for (int i = 0; i< matrixB.getWidth(); i++){
		cout << matrixB.getLine(i) << " " << matrixC.getLine(i) << " " << endl;
	}
	matrixC.saveToFile("macierzC.txt");
	try {
		Matrix matrixX = matrixA.add(matrixB);
	} catch (std::exception& e)
	{
		cout << endl << e.what() << endl << endl;;
	}
	Matrix matrixD("macierzC.txt");
	matrixD = matrixD.addNumber(4);
	Matrix matrixE = matrixC.add(matrixD);
	Matrix matrixF = matrixC.add(matrixD);
	Matrix matrixG = matrixE.substract(matrixF);
	cout << "Matrix C   Matrix D   Matrix E" << endl;
	for (int i = 0; i< matrixC.getWidth(); i++){
		cout << matrixC.getLine(i) << " " << matrixD.getLine(i) << " " << matrixE.getLine(i) << endl;
	}
	
	cout << endl << "Matrix F" << endl;
	cout << matrixF.getMatrix() << endl;
	cout << "Matrix G" << endl;
	cout << matrixG.getMatrix() << endl;
	try {
		Matrix matrixX = matrixA.add(matrixB);
	} catch (std::exception& e)
	{
		cout << e.what() << endl;;
	}
}


