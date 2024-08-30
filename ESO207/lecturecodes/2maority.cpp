//2majority problem
int main(){
    vector <int> arr;
    int count =1;
    int x=arr[0];
    for(int i=1;i<n;i++){
        if(count==0){
            x=arr[i];
            count++;
        }else if(x!=arr[i]) count--;
        else count++;
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==x) count++;
    }
    if(count>=n/2) cout<<x<<endl;
    else cout<<"FAlse"<<endl;
}