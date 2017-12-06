#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

#define fst first
#define snd second
#define all(c) ((c).begin()), ((c).end())

struct suffix_array {
	int n;
	vector<int> x;
	suffix_array(const char *s) : n(strlen(s)), x(n) { 
		vector<int> r(n), t(n); 
		for (int i = 0; i < n; ++i) r[x[i] = i] = s[i];
		for (int h = 1; t[n-1] != n-1; h *= 2) {
			auto cmp = [&](int i, int j) {
				if (r[i] != r[j]) return r[i] < r[j];
				return i+h < n && j+h < n ? r[i+h] < r[j+h] : i > j;
			};
			sort(all(x), cmp);
			for (int i = 0; i+1 < n; ++i) t[i+1] = t[i] + cmp(x[i], x[i+1]);
			for (int i = 0; i < n; ++i)   r[x[i]] = t[i];
		}
	}
	int operator[](int i) const { return x[i]; }
};

int main() {
	char s[100010];
	scanf("%s", s);
	suffix_array sary(s);
	for (int i = 0; i < sary.n; ++i){
		printf("%d\n", sary[i]);
		//printf("%s\n",s+sary[i]);
	}
}
