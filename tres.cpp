#include<bits/stdc++.h>
using namespace std;


class Node{
    public:

    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }

};

void inorder(Node* root){
    if(!root){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    if(!root){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void preorder(Node* root){
    if(!root){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void levelorder(Node* root){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }

        cout<<temp->data<<" ";
    }
}




int height(Node* root){

    if(!root){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);


    return 1+ max(left,right);

}



int ifbalanced(Node* root){

    if(!root){
        return 0;
    }

    int l = ifbalanced(root->left);
    if(l==-1) return -1;

    int r = ifbalanced(root->right);
    if(r==-1) return -1;


    if(abs(l-r) > 1) return -1;

    return 1+max(l,r); 

}

int maxi=0;
int diameter(Node* root){
    if(!root) return 0;

    int l = diameter(root->left);
    int r = diameter(root->right);

    if(l+r>maxi){
        maxi=l+r;
    }

    return 1+max(l,r);
}







int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    Node* templ =  root->left;
    Node* tempr = root->right;

    templ->left = new Node(4);
    templ->right = new Node(5);

    templ->right->right = new Node(8); 
    templ->right->right->right = new Node(9); 

    tempr->right = new Node(7);
    tempr->left = new Node(6);


    // inorder(root);cout<<endl;
    // preorder(root);cout<<endl;
    // postorder(root);cout<<endl;
    // levelorder(root);cout<<endl;
    // int h = height(root);
    // cout<<h<<endl;


    // int result = ifbalanced(root);

    // if(result==-1) cout<<"unbalannced"<<endl;
    // else{
    //     cout<<"Balanced with height "<<result<<endl;
    // }

    diameter(root);
    cout<<maxi<<endl;



    return 0;
}