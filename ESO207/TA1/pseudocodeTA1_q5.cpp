ispalindrome(i,j){
    blackbox function which return true or false whether S(i,j) is palindrome in O(1) time
}
sum=0
for i from 0 to n-1
{
    low=0, high= min{i,n-i-1}, ans
    while(low <= high){
        mid=(low+high)/2
        if(ispalindrome(i-mid,i+mid)== true){
            ans=mid
            low=mid+1
        }else{
            high=mid-1
        }
    }
    sum= sum+ ans+1 // +1 because length 0 also counts as palindrome
    if( i<n-1 and ispalindrome(i,i+1)==true){
        low=0, high= min{i,n-i-2}, ans=0
        while(low <= high){
            mid=(low+high)/2
            if(ispalindrome(i-mid,i+mid+1)== true){
                ans=mid
                low=mid+1
            }else{
                high=mid-1
            }
        }
        sum= sum+ans
    }
}
print(sum)