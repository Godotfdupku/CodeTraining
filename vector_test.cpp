#include<vector>
#include<iostream>
using namespace std;
int main()
{
	vector<int> vec;
        for ( int i = 1; i <= 6; i++)
	{
		vec.push_back( 2*i + 5 );
	}
	for ( int i = 1; i <= 5; i++ )
	{
		cout << vec[i] << endl;
	}
	return 0;
}
