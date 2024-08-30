#include <iostream> 
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long arr[n],ans[n]={0};
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        ans[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            if(ans[i+1]<0) ans[i]=arr[i];
            else ans[i]=ans[i+1]+arr[i];
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";

        }
        cout<<endl;
    }
}