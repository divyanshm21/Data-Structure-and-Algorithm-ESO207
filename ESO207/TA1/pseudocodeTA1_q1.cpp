MULT( matrix a, matrix b){
    for i from 0 to n-1 
        for j from 0 to n-1
            for k from 0 to n-1
                ANSWERMATRIX+= a[i][k] * b[k][j]

    return ANSWERMATRIX
}
Power(x, n){
    if (n=0) return 1; 
    else {      
        𝑡𝑒𝑚𝑝 = Power(x, n/2);
        𝑡𝑒𝑚𝑝 = MULT(𝑡𝑒𝑚𝑝 , 𝑡𝑒𝑚𝑝);
        if (n mod 2=1 ) 𝑡𝑒𝑚𝑝 = MULT(𝑡𝑒𝑚𝑝 , x) ;
        return 𝑡𝑒𝑚𝑝;
    }
}
Wealth_final
{
    Matrix M ^ m calculated as above let it be P matrix
    now multiply it with 2^(m%12)*intitial wealth column matrix W0
    Ans= column matrix showing wealth after m months
    for i from 1 to n
        Ans[i]=0
        for j from 1 to n
            Ans[i]+= P[i][j]*W0[j]*2^(m%12) // this multiplication takes O(1) time since m%12<12 
    
    Ans column matrix has final wealth // this whole step takes O(n^2) time
    
}
