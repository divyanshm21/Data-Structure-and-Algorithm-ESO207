if(check(matrix)==false){
    return false;
}else{
    for(i from 0 to n-1){
        out[i]=0;
        for(j from 0 to n-1){
            out[i]=out[i]+matrix[i][j];
        }   
    }
    sort(out.begin, out.end);
    for(i from 0 to n-1){
        if(i!=out[i]) return false;
    }
    return true;
}
check(matrix){
    for(i from 0 t0 n-1){
        for(j from 0 to n-1){
            if(matrix[i][j]+matrix[j][i]!=1) return false; 
        }
    }
    return true;
}