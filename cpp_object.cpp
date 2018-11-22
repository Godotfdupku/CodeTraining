#include <iostream>
#include <vector>
using namespace std;
class Average
{
public:
	Average():count(0), sum(0){ }
	void operator()(double num)
	{
		count++;
		sum += num;
		f_(sum, num);

	}
	double GetAverage(){ return sum / count; }
	void set_callback(int (*f)(int, int)) {}
private:
	int count;
	double sum;
	int (*f_) (int, int);
};
template < class T, class F >
F for_each_non( T begin, T end, F functor )
{
	for ( T iter = begin; iter != end; iter++ )
		functor( *iter );
	return functor;
}
int main()
{
//	std::vector<int> vec = { 1, 2, 3, 4, 5 };
	int a[5] = { 1, 2, 3, 4, 5 };
	std::vector<int> vec(a, a+5);
	Average result;
	auto result_1 = for_each_non( vec.begin(), vec.end(), result );
	cout << result_1.GetAverage() << endl;
	return 0;
}
std::sort(v.begin(), v.end(), [] (int a, int b) { });
