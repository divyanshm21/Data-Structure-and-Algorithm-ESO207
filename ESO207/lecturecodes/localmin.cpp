#include <iostream>
using namespace std;
int localmin(int *A, int n){
    int l=0,r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(mid==0 || mid==n-1) return mid;
        if(A[mid]<A[mid+1]){
            if(A[mid]<A[mid-1]) return mid;
            else r=mid-1;
        }else l=mid+1;
    }
    return r;
}
int main(){
    int A[]={4,5,2,4,42,4,5,35,6,51};
    // cout<<sizeof(A)/sizeof(int);
    cout<<localmin(A);
}