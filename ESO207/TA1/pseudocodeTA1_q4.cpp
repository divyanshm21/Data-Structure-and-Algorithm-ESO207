low= 0, high = n-1
found= false
while( found is false and low <= high){
    mid =(low + high)/2
    if( A[n-1]> A[mid] && A[n-1]< A[mid-1]){
        i=mid
        found=true
    }else if( A[n-1] > A[mid] && A[n-1] > A[mid-1]){
        r=mid-1
    }else{
        l=mid+1
    }
}
print( n-i-1)