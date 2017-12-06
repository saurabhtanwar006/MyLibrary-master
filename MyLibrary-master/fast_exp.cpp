ll fast_exp(ll base, ll exp){
	ll res = 1;
	while(exp>0){
		if(exp&1) res = ((res%mod)*(base%mod))%mod;
		base = ((base%mod)*(base%mod))%mod;
		exp>>=1;
	}
	return res%mod;
}
