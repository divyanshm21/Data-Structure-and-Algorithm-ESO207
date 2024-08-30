#include <iostream>
#include <vector>
using namespace std;

int maxind(vector <int>& A, int l, int r){
    int max=0, j=l;
    for(int i=l;i<=r;i++){
        if(A[i]>max) {
            max=A[i];
            j=i;
        }
    }
    return j;// O(n) function to determine the index which has maximum value amongst the subarray A[l:r]
}

void findheight(vector <int>& A, int l, int r, vector <int>& ans, int h){
    if(l>r) return;
    if(l==r){
        ans[l]=h;// if we have arrived to a leaf node
        return;
    }
    int i=maxind(A,l,r);// returns the index which has maximum value amongst the subarray A[l:r],  this is our pivot
    ans[i]=h;
    findheight(A,l,i-1,ans,h+1);//Divide step for pre pivot
    findheight(A,i+1,r,ans,h+1);// Divide step for post pivot
}

void fun(){
    int n;
    cin>>n;
    vector <int> A(n),ans(n);// ans array is storing depth for each node
    for(int i=0;i<n;i++) {
        cin>>A[i];
    }
    findheight(A,0,n-1,ans,0);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;// no. of test cases
    while(t--){
        fun();
    }
}