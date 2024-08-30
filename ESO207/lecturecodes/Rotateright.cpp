Rotaterightaboutnode(x->left){
    temp =x->left;
    temp2= temp->left;
    temp->left=temp2->right;
    x->left=temp2;
    temp2->right=temp;
}   