// catalan number = 2n!/(n!*(n+1)!)
// basically (2n,n) *(1/n+1);
// (2n,n) = sum of i = 0 , n (n,i)*(n,i)
ll catalan(int n){
	if(n==0)
		return (ll)1;
	ll num = 4*n+2;
	num = num*catalan(n-1);
	num/=(n+2);
	return num;
}
