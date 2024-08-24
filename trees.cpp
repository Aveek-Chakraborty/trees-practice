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


int ans = INT_MIN;
int maximumpathsum(Node* root){
    if(!root) return 0;

    int l = max(0 , maximumpathsum(root->left));
    int r = max(0 , maximumpathsum(root->right));

    ans = max(ans, l+r+root->data);

    return max(l,r)+root->data;
}


bool same(Node* q , Node* p){
    if(!p && !q) return true;
    if(!p ||!q) return false;

    return (p->data == q->data && same(p->left,q->left) && same(p->right,q->right));
}


vector<vector<int>> zigzag(Node* root){
    vector<vector<int>> res;
    queue<Node*> q;
    q.push(root);

    bool lefttoright=true;

    while(!q.empty()){
        
        int size = q.size();
        vector<int> row(size);

        for(int i = 0 ; i<size ; i++){
            Node* temp = q.front();
            q.pop();

            int index = lefttoright ? i : size-i-1;
            row[index]=temp->data;

            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }

        lefttoright=!lefttoright;
        res.push_back(row);
    }

    return res;

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



    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);

    Node* templ2 =  root2->left;
    Node* tempr2 = root2->right;

    templ2->left = new Node(4);
    templ2->right = new Node(5);

    templ2->right->right = new Node(8); 
    templ2->right->right->right = new Node(9); 

    tempr2->right = new Node(7);
    tempr2->left = new Node(6);




    

    // inorder(root);std::cout<<std::endl;
    // preorder(root);std::cout<<std::endl;
    // postorder(root);std::cout<<std::endl;
    // levelorder(root);std::cout<<std::endl;
    // int h = height(root);
    // std::cout<<h<<std::endl;


    // int result = ifbalanced(root);

    // if(result==-1) std::cout<<"unbalannced"<<std::endl;
    // else{
    //     std::cout<<"Balanced with height "<<result<<std::endl;
    // }

    // diameter(root);
    // std::cout<<maxi<<std::endl;

    // maximumpathsum(root);
    // cout<<ans<<endl;




    // if(same(root,root2)){
    //     cout<<"same tree"<<endl;
    // }
    // else{
    //     cout<<"not same tree"<<endl;
    // }


    vector<vector<int>> ans = zigzag(root);

    for(auto it : ans){
        for(auto its : it){
            cout<<its<<" ";
        }
        cout<<endl;
    }



    return 0;
}