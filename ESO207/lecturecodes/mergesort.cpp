//merge sort
void merge( int A[], int l, int r, int C[]){
    int i=l,mid=(l+r)/2, k=0;
    int j=mid+1;
    while(i<mid && j<r){
        if(A[i]<A[j]){
            C[k]=A[i];
            i++;
        }else{
            C[k]=A[j];
            j++;
        }   
        k++;
    }
    while(i<mid){
        C[k]=A[i];
        i++;
        k++;
    }
    while(j<r){
        C[k]=A[j];
        j++;
        k++;
    }
}
void mergesort(int A[], int l, int r){
    if(l<r){
        int mid=(l+r)/2;
        mergesort(A,l,mid);
        mergesort(A,mid+1,r);
        int C[r-l+1];
        merge(A,l,r,C);
        for(int i=l;i<=r;i++){
            A[i]= C[i-l];
        }
    }
}