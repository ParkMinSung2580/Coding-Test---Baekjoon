#include <iostream>
using namespace std;

void Add(int i,int  a, int b)
{
	cout << "Case #" << i + 1 << ": " << a <<" + " << b << " = " << a+b<< "\n";
}
int main()
{
	int num;
	cin >> num;
	int a, b;
	for (int i = 0; i < num; i++)
	{
		cin >> a >> b;
		Add(i,a,b);
	}
}