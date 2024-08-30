#include <iostream>
using namespace std;
#define ll long long int
ll mod= 998244353;
int h;
ll* mult(ll *A , ll *B){
    ll *ans=(ll*) malloc(h*h*sizeof(ll));
    for(ll i=0;i<h;i++){
        for(ll j=0;j<h;j++){
            ans[h*i+j]=0;
            for(ll k=0;k<h;k++){
                ans[h*i+j]=(ans[h*i+j]+((A[h*i+k]%mod)*(B[h*k+j]%mod))%mod)%mod;
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
    return t;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin >> n;
        cin>>h;
        ll dp[h];
        // h=6;
        dp[0] =1;
        for(int i=0;i<h;i++){
            dp[i] = 1;
            for(int j=0;j<i;j++){
                dp[i] += dp[j];
            }
        }
        if(n<=h){
            cout << dp[n-1] <<endl;
            continue;
        }
        ll *I= (ll*)calloc(h*h,sizeof(ll));
        for(ll i=0;i<h;i++){
            I[i]=1;
        }
        for(ll i=1;i<h;i++){
            I[i*h+i-1]=1;
        }
        ll* b=fep(I,n-h);
        ll ans=0;
        for(ll i=0;i<h;i++){
            ans= (ans%mod+((b[i]%mod)*(dp[h-i-1]%mod))%mod)%mod;
        }
        cout<<ans<<endl;
    }
}