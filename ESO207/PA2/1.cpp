#include <iostream>
#include <vector>
using namespace std;
#define ll long long int

ll merge( vector <ll>& A, int l, int r){
    int mid=(l+r)/2;
    int i=l,j=mid+1;
    ll jsmaleri=0;// no. of j smaller than i
    vector <ll> temp;// will store merged sorted array in it
    while( i<=mid && j<=r){// merging and counting step
        if(A[i]<=A[j]){
            temp.push_back(A[i]);
            i++;
        }else{
            temp.push_back(A[j]);
            j++;
            jsmaleri+=mid-i+1;//counting step
        }
    }
    while(i<=mid){
        temp.push_back(A[i]);//merging remaining elements of premid
        i++;
    }
    while(j<=r){
        temp.push_back(A[j]);// merging remaining elements of postmid
        j++;
    
    }
    for(int s=l;s<=r;s++){
        A[s]=temp[s-l];//pasting back the sorted temp array to origional array 
    }
    return jsmaleri;
}

ll mergesort(vector <ll>& A, int l , int r){
    if(l>=r){
        return 0;
    }else{
        int mid=(l+r)/2;
        ll premid=mergesort(A,l,mid);// dividing array  from l to mid
        ll postmid=mergesort(A,mid+1,r);// dividing array from mid+1 to r
        ll count=merge(A,l,r);// conquer step including count for inversions between two subarrays
        return premid+postmid+count;
    }
}

void fun(){
    int n;
    cin>>n;
    vector <ll> A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    ll ans=mergesort(A,0,n-1);
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;//no. of test case
    while(t--){
        fun();
    }
}