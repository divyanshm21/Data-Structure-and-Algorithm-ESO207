->Start BFS from s Until we reach t
->Initialising boolean visited array visited[n]=false  all false initially
->mark visited [s]=true
->Initialising Distance array Distance[n]=infinty(very high value) 
->mark Distance [s]=0
->Initialising empty queue Q
->then pushing s(starting node to it)
Q.push(s)
while(Q is not empty){
    u= Q.front
    Q.pop
    if(u == t) end BFS
    for( each neighbor v of u){
        if( visited[v]==false){
            Distance[v]=Distance[u]+1
            visited[v]=true
            parent [v]=u
            Q.push(v)
        }
    }
}


UpdateMatrix{
    node=t
    while(parent[node]!=-1){
        M[node][parent[node]]=newdistance(node, parent[node])
        M[parent[node]][node]=M[node][parent[node]]
        node= parent node
    }
}

newdistance(node , parent [node]){
    ->Start BFS from s Until we reach t
    ->Initialising boolean visited array visited[n]=false  all false initially
    ->mark visited [s]=true
    ->Initialising Distance array Distance[n]=infinty(very high value) 
    ->mark Distance [s]=0
    ->Initialising empty queue Q
    ->then pushing s(starting node to it)
    Q.push(s)
    while(Q is not empty){
        u= Q.front
        Q.pop
        if(u == t) end BFS
        for( each neighbor v of u){
            if(u== node and v== parent[node]) skip;
            else if( visited[v]==false){
                Distance[v]=Distance[u]+1
                visited[v]=true
                parent [v]=u
                Q.push(v)
            }
        }
    }
    return Distance[t]
}