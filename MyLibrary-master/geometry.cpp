#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <functional>
#include <sstream>
#include <fstream>
#include <valarray>
#include <complex>
#include <queue>
#include <cassert>
#include <bitset>
using namespace std;
#ifdef LOCAL
#define debug_flag 1
#else
#define debug_flag 0
#endif
	template <class T1, class T2 >
std::ostream& operator << (std::ostream& os, const pair<T1, T2> &p) 
{
	os << "[" << p.first << ", " << p.second << "]";
	return os;
}
	template <class T >
std::ostream& operator << (std::ostream& os, const std::vector<T>& v) 
{
	os << "[";
	bool first = true;
	for (typename std::vector<T>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		if (!first)
			os << ", ";
		first = false;
		os << *it;
	}
	os << "]";
	return os;
}
#define dbg(args...) { if (debug_flag) { _print(_split(#args, ',').begin(), args); cerr << endl; } else { void(0);} }
vector<string> _split(const string& s, char c) {
	vector<string> v;
	stringstream ss(s);
	string x;
	while (getline(ss, x, c))
		v.emplace_back(x);
	return v;
}
void _print(vector<string>::iterator) {}
template<typename T, typename... Args>
void _print(vector<string>::iterator it, T a, Args... args) {
	string name = it -> substr((*it)[0] == ' ', it -> length());
	if (isalpha(name[0]))
		cerr << name  << " = " << a << " ";
	else
		cerr << name << " ";
	_print(++it, args...);
}
typedef long long int int64;
const int SIZE = 3;
const int64 MAX_ABS = 1e8;
struct Point
{
	int64 x, y;
	Point() : x(), y() {}
	Point(int64 _x, int64 _y) : x(_x), y(_y) {}
	void scan()
	{
		scanf("%lld%lld", &x, &y);
	}
	Point operator + (const Point &p) const
	{
		return Point(x + p.x, y + p.y);
	}
	Point operator - (const Point &p) const
	{
		return Point(x - p.x, y - p.y);
	}
	int64 operator % (const Point &p) const
	{
		return x * p.x + y * p.y;
	}
	int64 operator * (const Point &p) const
	{
		return x * p.y - y * p.x;
	}
	int64 length2() const
	{
		return *this % *this;
	}
	Point rotate() const
	{
		return Point(-y, x);
	}
};
std::ostream& operator << (std::ostream& os, const Point &p) 
{
	os << "{" << p.x << ", " << p.y << "}";
	return os;
}
struct Matrix
{
	int64 a[SIZE][SIZE];
	Matrix()
	{
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
				a[i][j] = 0;
	}
	int64* operator [] (int k) 
	{
		return a[k];
	}
	Matrix operator * (Matrix b) 
	{
		Matrix res;
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
				for (int k = 0; k < SIZE; k++)
					res[i][j] += a[i][k] * b[k][j];
		return res;
	}
};
bool cmp_by_cords(Point A, Point B)
{
	if (A.x != B.x)
		return A.x < B.x;
	return A.y < B.y;
}
vector<Point> shift(vector<Point> points)
{
	int n = (int)points.size();
	int ind = min_element(points.begin(), points.end(), cmp_by_cords) - points.begin();
	int sh = n - ind;
	vector<Point> res(n);
	for (int i = 0; i < n; i++)
		res[(i + sh) % n] = points[i];
	return res;
}
int64 get_area(Point A, Point B, Point C)
{
	return abs((B - A) * (C - A));
}
bool check_inside(Point O, Point A, Point B, Point C)
{
	return get_area(A, B, C) == get_area(A, B, O) + get_area(B, C, O) + get_area(C, A, O);
}
bool check_inside(const vector<Point> &points, Point O)
{
	int n = (int)points.size();
	int l = 1;
	int r = n - 1;
	while (r - l > 1)
	{
		int mid = (l + r) / 2;
		int64 mul = (points[mid] - points[0]) * (O - points[0]);
		if (mul >= 0)
			l = mid;
		else
			r = mid;
	}
	return check_inside(O, points[0], points[l], points[l + 1]);
}
void print(Matrix mat)
{
	printf("----");
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			printf("%lld ", mat[i][j]);
		printf("\n");
	}
}
int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif
	int n, q;
	scanf("%d%d", &n, &q);
	vector<Point> points(n);
	for (int i = 0; i < n; i++)
		points[i].scan();
	points = shift(points);
	Matrix undo_matrix;
	for (int i = 0; i < SIZE; i++)
		undo_matrix[i][i] = 1;
	for (int it = 0; it < q; it++)
	{
		int type;
		Point O;
		scanf("%d", &type);
		O.scan();
		if (type == 1)
		{
			Matrix coef;
			coef[1][0] = 1;
			coef[2][0] = O.x - O.y;
			coef[0][1] = -1;
			coef[2][1] = O.x + O.y;
			coef[2][2] = 1;
			undo_matrix = coef * undo_matrix;
		}
		else if (type == 2)
		{
			Matrix coef;
			coef[0][0] = -1;
			coef[2][0] = 2 * O.x;
			coef[1][1] = -1;
			coef[2][1] = 2 * O.y;
			coef[2][2] = 1;
			undo_matrix = coef * undo_matrix;
		}
		else
		{
			Matrix row;
			row[0][0] = O.x;
			row[0][1] = O.y;
			row[0][2] = 1;
			Matrix undo_row = row * undo_matrix;
			Point undo_O = Point(undo_row[0][0], undo_row[0][1]);

			bool is_in;
			if (max(abs(undo_O.x), abs(undo_O.y)) > MAX_ABS)
				is_in = false;
			else
				is_in = check_inside(points, undo_O);
			printf("%s\n", is_in ? "Yes" : "No");
		}
	}
	return 0;
}
