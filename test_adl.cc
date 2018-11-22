#include <algorithm>
#include <vector>
namespace xxx {
template<typename T>
void sort(T begin, T end);

bool f(int a, int b) {
	return a < b;
}
}
int main() {
	std::vector<int> v = {1,2,3,4,5};
	sort(v.begin(), v.end(), xxx::f);
}
