vector<int> prime; 
int mu[SIZE];
void calculateMobiusFunction( int n ) {
  for ( int i = 1; i <= n; i++ ) mu[i] = 1;
  int sqrtn = sqrt ( SIZE );

  /*Remove the numbers with squares*/
  for ( int i = 0; i < prime.size(); i++ ){
    if ( prime[i] > sqrtn ) break;
    int x = prime[i] * prime[i];

    /*Mark every multiple of x as 0, cause they are divisible by prime^2*/
    for ( int j = x; j <= n; j += x ) mobius[j] = 0;
  }

  for ( int i = 0; i < prime.size(); i++ ){

    /*Multiply every multiple of prime[i] with -1*/
    for ( int j = prime[i]; j <= SIZE; j += prime[i] ) {
      mobius[j] *= -1;
    }
  }
}
	/*
	n>0
	μ(n) =  1   n is square-free , even number of prime factors.
	μ(n) = −1   n is a square-free , odd number of prime factors.
	μ(n) =  0   n has a squared prime factor.
	*/

