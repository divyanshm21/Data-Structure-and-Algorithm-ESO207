#include <iostream>
#include <vector>
using namespace std;
#define ll long long int

bool check(vector <ll> A, vector <ll>& x, vector <ll> & l, vector <ll>& r, ll mid, ll k){
    ll count=0,n=A.size(),s=l.size();
    for(ll i=0;i<=mid;i++){
        A[x[i]-1]=1;
    }
    vector <ll> prefixsum;
    ll sum=0;
    for(ll i=0;i<n;i++){
        sum+=A[i];
        prefixsum.push_back(sum);
    }
    for(ll i=0;i<s;i++){
        //sum of subsegment A[l:r] is PreSum[r]- Presum[l]+A[l] 
        if(prefixsum[r[i]-1]-prefixsum[l[i]-1]+A[l[i]-1]>0) count++;
    }
    if(count>=k ) return true;
    else return false;
}

void fun(){
    ll n,s;
    cin>>n>>s;
    vector <ll> A(n);
    for(ll i=0;i<n;i++){
        cin>>A[i];
    }
    vector <ll> l(s),r(s);
    for(ll i=0;i<s;i++){
        cin>>l[i]>>r[i];
    }
    ll q,k;
    cin>>q>>k;
    vector <ll> x(q);
    for(ll i=0;i<q;i++){
        cin>>x[i];
    }

    ll low=-1,high=q-1,ans=-2;
    while(low<=high){
        ll mid=(low+high)/2;
        if(check(A,x,l,r,mid,k)==true){       
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    cout<<ans+1<<endl;

}
int main(){
    ll t;
    cin>>t;//no. of test cases
    while(t--){
        fun();
    }
}