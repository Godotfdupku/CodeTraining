int f(int a, int b, int (*cb) (int, int)) {
	return cb(a, b);
}

int sum(int a, int b) {
	return a + b;
}

int main() {
	return f(1, 2, &sum);
};
