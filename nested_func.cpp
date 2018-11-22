#include <iostream>
using namespace std;
void fun_1 ( int count)
{
	count += 1;
	cout << "count: " << count;
}
void fun( )
{
	int count = 1;
	fun_1( count );
}
int main()
{
	fun();
	return 0;
}
