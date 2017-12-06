int gcd(int a,int b){
	while (a&&b)a>b?a%=b:b%=a;
	return a+b;
}
ll lcm(ll a, ll b){
	return (a*b)/gcd(a,b);
}
