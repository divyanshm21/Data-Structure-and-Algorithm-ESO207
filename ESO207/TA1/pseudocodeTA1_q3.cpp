Nodes prev,first_distortion, second_distortion,first_next all declared NULL inititally
traversal(root)// declared later
if(first_distortion and second_distortion both not NULL) swap(first_distortion val, second_distortion val)
else swap(first_distortion val, first_next val)

traversal(node){
    if(node == NULL) return; 
    traversal(left child of node);
    if (prev is not NULL and (node val < prev val))
    {
        if ( first_distortion is NULL )
        {
            first_distortion = prev
            first_next = node
        }
        else
            second_distortion = node
    }
    prev = node;
    traversal(right child of node)
}


Common_ancestor(node)
{
    node is one of common ancestor

    if(node1 val > node val and node2 val > node val){
        Common_ancestor(right child of node)
    }else if(node1 val < node val and node2 val < node val){
        Common_ancestor(left child of node)
    }else{
        return;
    }
}

inorder[n]
Present_array[G] // all false by default
inorder_traversal(root)
{
    if(root is NULL) return;
    inorder_traversal(left child of root)
    Present_array[node val]=true
    push root in inorder[]
    inorder_traversal(right child of root)
}
j=0,k=0, ans_arr[]
for i from 0 to G-1
{
    if(Present_array==true){
        if(inorder[j]!=i ){
            store i in ans_array
            k++
        }
        j++
    }
}
print k
// dup[] = duplicate(inorder)
// sort(dup)
// k=0
// for i from 0 to n-1
//     if (dup[i]!=inorder[i]) k++
// print k