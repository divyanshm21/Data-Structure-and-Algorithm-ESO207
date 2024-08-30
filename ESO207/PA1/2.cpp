#include <iostream> 
using namespace std;
bool check(long long int A[], int n, long long int k, long long int mid ){
    long long int sum=0, reqheight=mid*(mid+1)/2;
    for(int i=0;i<n;i++){
        if(A[i]>mid) sum+=A[i]*(A[i]+1)/2-reqheight;
        if(sum>k) return false;
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        long long int k;
        long long int l=0,ans, r=0;
        cin>>n>>k;
        long long int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
            r=max(r,A[i]);
        }
        while(l<=r){
            long long int mid=(l+r)/2;
            if(check(A,n,k, mid)==true){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        cout<<ans<<endl;
    }
}