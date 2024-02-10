#include<stdio.h>
struct tree
{
    /* data */
    int data ;
    struct tree* left;
    struct tree* right;
};
struct tree* root = NULL;

void inorder(struct tree* root){
    if(root == NULL) return;
    inoder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);

}
void preorder(struct tree* root){
    if (root == NULL){
        return ;

    }
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct tree* root){
    if(root== NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);
}
int main(){

return 0;
}