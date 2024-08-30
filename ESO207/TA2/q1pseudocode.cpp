Search Complicated(arr,n,k,q){
    sort(arr+n-k-1, arr+n-1);// sort all elements from n-k to n ,(0 based indexing)
    maxl=locatemax(arr,0,n-1);
    while(q--){
        input(val);
        if(findinc(val,0,maxl) || finddec(val,maxl,n-1) ==true) mark present;
        else mark not present;
    }
}
 
findinc(val, l, r){
    while(l<=r){
        mid=(l+r)/2;
        if(arr[mid]==val) return true;
        else if(arr[mid]>val) r=mid-1;
        else l=mid+1;
    }
}

finddec(val, l, r){
    while(l<=r){
        mid=(l+r)/2;
        if(arr[mid]==val) return true;
        else if(arr[mid]<val) r=mid-1;
        else l=mid+1;
    }
}

//logn function to find maximum element using binary search
locatemax(arr,l,r){
    while(l<=r){
        mid=(l+r)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
        else if(arr[mid]<arr[mid-1]) r= mid-1;
        else l=mid+1;
    }
}