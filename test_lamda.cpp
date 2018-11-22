#include <iostream>
using namespace std;
int main(){
	int a[5] = { 1, 2, 3, 4, 5 };
	int n = 3;
	sort( a, a+5, [](int x, int y){return x > y;} );
	for_each( a, a+5, [](int x){cout<<x<<endl;});
	return 0;
}

