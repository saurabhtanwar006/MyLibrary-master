vector<int> VI;
typedef pair<int,int> PII;
int mod(int a, int b) {
	return ((a%b)+b)%b;
}
int gcd(int a, int b) {
	int tmp;
	while(b){a%=b; tmp=a; a=b; b=tmp;}
	return a;
}
int lcm(int a, int b) {
	return a/gcd(a,b)*b;
}
int extended_euclid(int a, int b, int &x, int &y) {
	int xx = y = 0;
	int yy = x = 1;
	while (b) {
		int q = a/b;
		int t = b; b = a%b; a = t;
		t = xx; xx = x-q*xx; x = t;
		t = yy; yy = y-q*yy; y = t;
	}
	return a;
}
VI modular_linear_equation_solver(int a, int b, int n) {
	int x, y;
	VI solutions;
	int d = extended_euclid(a, n, x, y);
	if (!(b%d)) {
		x = mod (x*(b/d), n);
		for (int i = 0; i < d; i++)
			solutions.push_back(mod(x + i*(n/d), n));
	}
	return solutions;
}
int mod_inverse(int a, int n) {
	int x, y;
	int d = extended_euclid(a, n, x, y);
	if (d > 1) return -1;
	return mod(x,n);
}
PII chinese_remainder_theorem(int x, int a, int y, int b) {
	int s, t;
	int d = extended_euclid(x, y, s, t);
	12University of Southampton
		if (a%d != b%d) return make_pair(0, -1);
	return make_pair(mod(s*b*x+t*a*y,x*y)/d, x*y/d);
}
PII chinese_remainder_theorem(const VI &x, const VI &a) {
	PII ret = make_pair(a[0], x[0]);
	for (int i = 1; i < x.size(); i++) {
		ret = chinese_remainder_theorem(ret.second, ret.first, x[i], a[i]);
		if (ret.second == -1) break;
	}
	return ret;
}
void linear_diophantine(int a, int b, int c, int &x, int &y) {
	int d = gcd(a,b);
	if (c%d) {
		x = y = -1;
	} else {
		x = c/d * mod_inverse(a/d, b/d);
		y = (c-a*x)/b;
	}
}
