#include<iostream>
#include<cstdio>
#define ll long long
ll  gcd(ll a,ll b,ll&aa,ll&bb){
	ll ab=0,ba=0;aa=1;bb=1;
	while(1){
		if(a==0){aa=ba;return b;}
		ba-=(b/a)*aa;bb-=(b/a)*ab;b%=a;
		if(b==0){bb=ab;return a;}
		aa-=(a/b)*ba;ab-=(a/b)*bb;a%=b;
	}
}
ll mod_inverse(ll a,ll mod){
	ll res,temp;
	ll d=gcd(a,mod,res,temp);
	if(d==1)return res;
	return -1;
}
int main(){
	ll p,q,e,d;
	p = 473398607161;
	q = 4511491;
	e = 17;
	std::cout<<mod_inverse(e,(p-1)*(q-1))<<std::endl;
}
