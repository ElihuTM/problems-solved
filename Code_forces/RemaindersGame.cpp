#include <iostream>

using namespace std;

long long int gcd(long long int a,long long int b){
	if(b==0)return a;
	return(gcd(b,a%b));
}

int main(){
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	long long int n,k,a;
	long long ans=1;
	cin>>n>>k;
	for( int i=0;i<n; ++i){
		cin>>a;
		ans = ans * ( a / gcd(ans,a) );
		ans = ans%k;
	}

	if(ans%k==0)cout<<"YES";
	else cout<<"NO";
	return 0;
}