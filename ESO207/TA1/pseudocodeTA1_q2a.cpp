// Create_prefix_Sum(S[n])
// low=0, high=n-1
// while(low<=high){
//     mid=(low+high)/2
//     if(check(mid)==true) {
//         ans=mid
//         high=mid-1
//     }else {
//         low=mid+1
//     }
// }

// Create_prefix_Sum(S[n]){
//     S[0]=A[0]
//     for i from 1 to n-1{
//         S[i]=S[i-1]+A[i]
//     }
// }

// check( mid){
//     if(S[i+mid]-S[i]+A[i]>=P){
//         return true
//     }else {
//         return false
//     }    
// }


// // 2b
// low =0, high=0, sum=0
// while(high<n){
//     while(sum<P && high<n){
//         sum+=A[high]
//         high++
//     }
//     while(sum>=P){
//         ans= min(ans,high-low)
//         sum-=A[low]
//         low++
//     }
// }

// 2c
GCD (no1, no2){
    //blackbox function which returns GCD of 2 input
}
 
POW[logn]{// creating array such that POW[j]=2^j
    POW[1]=2
    for i from 2 to logn:
        POW[i]=2*POW[i-1]
}
 
LOG[n+1]// LOG[m]: such that the greatest integer 𝒌 such that 𝟐^𝒌  ≤ 𝒎+1

for i from 0 to n-1
{
    M[i][0]=A[i] // since GCD of a no. is the no. itself
}

for j from 1 to logn
{
    for( int i=0; i+ POW[j] -1 < n; i++){
        M[i][j]= GCD( M[i][j-1], M[i+POW[j-1]][j-1])
    }
}


low =1, high=n, ans
while(low<=high){
    mid=(low+high)/2
    if(check(mid)==true) {
        ans=mid
        low=mid+1}
    else high=mid-1
}
 
check(mid){
    for i from 0 to n-mid
        if( findgcd (i,mid) >= k) return true
        else return false
}
findgcd(i, mid){
    j=i+mid-1
    t=POW[mid];         
    h=LOG[mid];
    if (t == mid)  return  M[i][h]; 
    else  return GCD(M[i][h], M[j-t][h]);
}
