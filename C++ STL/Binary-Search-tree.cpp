#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};
Node* getn(int data){
    Node* newn = new Node();
    newn->data = data;
    newn->left = newn->right =NULL;
    return newn;
} 
Node* insert(Node* root, int data){
    if(root==NULL){
        root = getn(data);
    }
    else if(data<= root->data){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
    return root;
}
//Serching a element in BST
bool search(Node* root, int data){
    if(root==NULL){
        return false;
    }
    if(root->data == data){
        return true;
    }
    if(root->data >= data){
        return search(root->left, data);
    }
    else{ 
        return search(root->right,data);
    }
}
//Finding MInimum element with iterative solution
int findmin(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root->data;
}
//Finding Maximum with an recursive solution
int findmax(Node* root){
    if(root->right==NULL){
        return root->data;
    }
    else{
        return(findmax(root->right));
    }
}
//Finding Height of the tree
int findh(Node* root){
    if(root == NULL){
        return -1;
    }
    return max(findh(root->left),findh(root->right))+1;
}
//BFS Travellsal of the BFS
//Time-Complexity O(n);
//Space-Complexity 
    //Best case O(1);
    //Worst Case O(n);
void bfs(Node* root){
    if(root==NULL) return;
    std::queue<Node*> Q;
    Q.push(root);
    while(!Q.empty()){
        Node* curr = Q.front();
        cout<<curr->data<<"\t";
        if(curr->left!=NULL) Q.push(curr->left);
        if(curr->right!=NULL) Q.push(curr->right);
        Q.pop();//REmoving of the visited
    }
}
//Preorder Travellsal of the BST

void Preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<"\t";
    Preorder(root->left);
    Preorder(root->right);
}
void Inorder(Node* root){
    if(root==NULL){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<"\t";
    Inorder(root->right);
}
void Postorder(Node* root){
    if(root==NULL){
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<"\t";
}
//Function to check if tree follows binary tree property
bool islesser(Node* root, int val){
    if(root==NULL){
        return true;
    }
    if(root->data < val && islesser(root->left, val) && islesser(root->right,val)) return true;
    else return false;
}
bool isgreat(Node* root, int val){
    if(root==NULL){
        return true;
    }
    if(root->data > val && isgreat(root->left, val) && isgreat(root->right,val)) return true;
    else return false;
}
bool Check_BST(Node* root){
    if(root==NULL){
        return true;
    }
    if(Check_BST(root->left) && Check_BST(root->right) && isgreat(root->right,root->data) && islesser(root->left,root->data)){
        return true;
    }
    else return false;
}
//DEleting a node in BST
Node* findmn(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
Node* Delete(Node* root, int val){
    if(root==NULL) return root;
    else if(val < root->data) root->left = Delete(root->left,val);
    else if(val > root->data) root->right = Delete(root->right,val);
    else{//Found you finally XD:)
        if(root->left==NULL && root->right==NULL){
            delete root;
            root = NULL;
        }
        else if(root->left==NULL){
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right==NULL){
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        else{
            Node* temp = findmn(root->right);
            root->data = temp->data;
            root->right = Delete(root->right,temp->data);
        }
    }
    return root;
}
int main(){
    Node* root = NULL;
    root = insert(root,10);
    root = insert(root,12);
    root = insert(root,6);  
    root = insert(root,32);
    root = insert(root,2);
    root = insert(root,5);
    root = insert(root,15);
    bool it = search(root,5);
    std::cout << it << std::endl;
    cout<<findmin(root)<<endl;
    cout<<findmax(root)<<endl;
    cout<<findh(root)<<endl;
    bfs(root);cout<<"\n";
    Preorder(root);cout<<"\n";
    Inorder(root);cout<<"\n";
    Postorder(root);cout<<"\n";
    Check_BST(root)? cout<<"It is bst":cout<<"not bst";cout<<"\n";
    root = Delete(root,12);
    Preorder(root);cout<<"\n";
//    Check_BST(root)? cout<<"It is bst":cout<<"not bst";cout<<"\n";
    return 0;
}
