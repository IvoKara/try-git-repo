#include<iostream>

using namespace std;

void sum(int a, int b)
{
	cout<< a+b << endl;
}

void sum(double a, double b)
{
	cout << a+b << endl;
}

int main(int argc, char **argv)
{
	string str = "Hello World!";
	cout << str << endl;
	sum(23,5);
	sum(12.34, 45.54);
	return 0;
}
