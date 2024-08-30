//partitioning
#include <iostream>
using namespace std;
void partition( int *A,int l,int r){
    // for(int i=l-1;i>=lin;i--){
    //     if(A[i]>A[l]){
    //         swap(A[i],A[l]);
    //         l=i;
    //     }
    // }
}  
int main(){
    int A[]={3,1,6,4,2,5,0};
    int n=sizeof(A)/sizeof(int);
    partition(A,0,n);
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
}