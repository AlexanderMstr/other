#include<iostream>
#include<string>
#include<bitset>
using namespace std;
int main()
{
	cout << (1 << 8) << endl; // чтобы посмотреть сколько значений в 1 байте

	uint8_t a = 0b10111101;
	a &= ~((1 << 3) - 1);
	cout << bitset<8>(a) << endl;

	int x = 8;
	x >>= 1;
	cout <<x << endl;

	uint8_t q = 0b101;
	cout << bitset<sizeof(q) * 8>(q) << endl;
	cout << static_cast<int>(q) << endl;


	return 0;
}