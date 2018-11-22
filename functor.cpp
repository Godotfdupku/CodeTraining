#include <iostream>
#include <vector>
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
class functor
{
public:
	functor():count(0),sum(0){}
	void operator()(double num)
	{
		count++;
		sum += num;
		cout << "count inside functor: " << count << endl;
		cout << "sum inside functor: " << sum << endl;
	}
private:
	int count;
	double sum;
};
int main()
{
	fun();
	fun();
	int a[5] = { 1, 2, 3, 4, 5 };
	vector<double> vec(a, a+5);
	functor add;
	add(*a);
	for_each(vec.begin(), vec.end(), add);
	return 0;
}
