#include <iostream>
using namespace std;
#define ll long long int
ll mod=2021;

ll* mult(ll *A , ll *B){
    ll *ans=(ll*) malloc(4*sizeof(ll));
    for(ll i=0;i<2;i++){
        for(ll j=0;j<2;j++){
            ans[2*i+j]=0;
            for(ll k=0;k<2;k++){
                ans[2*i+j]=(ans[2*i+j]+((A[2*i+k]%mod)*(B[2*k+j]%mod))%mod)%mod;
            }
        }
    }
    return ans;
}
ll* fep(ll *a , ll n){
    if(n==1) return a;
    ll *temp = fep(a,n/2);
    ll *t=   mult(temp,temp);
    if(n%2 ==1 ) t = mult(t,a);
    // else return mult(mult(fep(a,n/2), fep(a,n/2)),a);
    return t;
}
int main(){
    ll n;
    cin>>n;
    ll I[4]={1,1,1,0};
    ll *b=fep(I,n-1);
    cout<<b[0]<<endl;
}