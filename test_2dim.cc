int x[2][3];
void f(int (*p)[3]) {
	p[0][0] = 2;
}
void f_2(int** p){
	p[0][0] = 2;
}
int main() {
	x[0][0] = 3;
	f(x);
	f_2(x);
        return 0
}

