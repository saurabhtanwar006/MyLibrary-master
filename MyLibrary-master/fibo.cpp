void fib(ll n, ll&x, ll&y){
    if(n==0){
        x = 0;
        y = 1;
        return ;
    }
     
    if(n&1){
        fib(n-1, y, x);
        y=(y+x)%mod;
    }else{
        ll a, b;
        fib(n>>1, a, b);
        y = (a*a+b*b)%mod;
        x = (a*b + a*(b-a+mod))%mod;
    }
}
/*
	properties
	1.) F[n+1]*F[n-1] - F[n]*F[n] = (-1)^n
	2.) F[n+k] = F[k]*F[n+1] + F[k-1]*F[n]
	3.) F[2n] = F[n]*(F[n+1]+F[n-1])
	4.) gcd(F[m],F[n])=F[gcd(m,n)]
	5.) from 2 and 3 F[nk]%F[n]==0
	6.) F[0] + F[1] + F[2] + .... F[x] = F[x+2] - 1	
	7.) Zeckendorf theorem
		every n>0 can be represented as
		n = F[k1] + F[k2] + F[k3] + .........
		k1>=k2+2
		k2>=k3+2
		.
		.
		.
*/
