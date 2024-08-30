#include <iostream>
#include <vector>
using namespace std;
#define ll long long int

typedef struct node{
    ll data;
    struct node* left;
    struct node* right;
}Tree;

//a struct node function which returns a Tree node with value data and children pointers as NULL
Tree* newNode(ll data){
    Tree* node=(Tree*) malloc(sizeof(Tree));
    node->data=data;
    node->left =NULL;
    node->right=NULL;
    return node;
}

//boolean function which returns true if the given value is present in the BST or not
bool present(ll val, Tree* root){
    if(root==NULL) return false;
    Tree* curr=root;
    while(curr!=NULL){
        if(curr->data==val) {
            return true;
        }else if( curr->data > val){
            curr=curr->left;
        }else {
            curr=curr->right;
        }
    }
    return false;
}

//insert a node with value val 
void insertnode(ll val, Tree* root) {
    Tree *curr = root;
    bool found=false;
    Tree *nayanode=newNode(val);
    while(found==false) {
        if(curr->data <= val) {
            if(curr->right != NULL) {
                curr = curr->right;
            }
            else {
                //this is the parent whose child is the new node
                found=true;
                curr->right = nayanode;
            }
        } else {
            if(curr->left != NULL) {
                curr = curr->left;
            }
            else {
                //this is the parent whose child is the new node
                found=true;
                curr->left = nayanode;
            }
        }
    }
}

//this function returns a Tree* which will replace the old node
Tree* findingnewchild(Tree* root) {
    if (root->left == NULL){
        return root->right;
    }
    if (root->right == NULL){
        return root->left;
    } 
    Tree* temp = root->left;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    temp->right = root->right;
    return root->left;
}

//function to delete a node
void deletenode(ll val,Tree* root){
    Tree* curr= root;
    bool found=false;
    while (curr != NULL && found==false) {
        if (curr->data > val) {
            if (curr->left != NULL && (curr->left)->data == val) {
                curr->left = findingnewchild(curr->left);
                found=true;
            } else {
                curr = curr->left;
            }
        } else {
            if (curr->right != NULL && (curr->right)->data == val) {
                curr->right = findingnewchild(curr->right);
                found=true;
            } else {
                curr = curr->right;
            }
        }
    }
}

int main(){
    Tree* root = newNode(1e9+1);
    ll n;
    cin>>n;
    char c;
    ll value;
    for(int i=0;i<n;i++){
        cin>>c>>value;
        if(c == 'B'){
            insertnode(value,root);
        }
        else if(c=='S'){
            deletenode(value,root); 
        }
        else{
            if(present(value,root)==true){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
}