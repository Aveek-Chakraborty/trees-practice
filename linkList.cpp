#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int val;
    Node* next;

    Node(int data){
        val=data;
        next=nullptr;
    }
};


void display(Node* head){
    Node* temp = head;

    while(temp){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}

int size(Node* head){
    Node* temp = head;
    int c=0;
    while(temp){
        c++;
        temp=temp->next;
    }

    return c;
}

Node* insertion(Node*head, int d , int pos){
    Node* psd = head;
    int s = size(head);

    if(pos==0){
        Node* temp = new Node(d);
        temp->next=head;
        return temp;
    }

    // if(pos==s){
    //     while(psd->next){
    //         psd=psd->next;
    //     }
    //     Node* temp = new Node(d);
    //     psd->next=temp;
    //     return head;
    // }


    for(int i =1 ; i<pos ; i++){
        psd=psd->next;
    }


    Node* temp=new Node(d);
    temp->next=psd->next;
    psd->next=temp;

    return head;
}

Node* deletion(Node* head, int pos){
    Node* psd = head;
    if(pos==0){
        head=head->next;
        return head;
    }

    for(int i = 1 ; i < pos ;i++){
        psd=psd->next;
    }
    psd->next=psd->next->next;
    return head;
}


Node* updation(Node* head,int pos,int val){
    Node* psd = head;
    for(int i=0 ; i<pos ; i++){
        psd=psd->next;
    }
    psd->val=val;

    return head;
}


Node* reverse(Node* head){
    if(!head || !head->next){
        return head;
    }

    Node* newhead = reverse(head->next);
    Node* front = head->next;
    front->next=head;
    head->next=nullptr;

    return newhead;
}

int middle(Node* head ){
    Node* fast = head;
    Node* slow = head;

    while(fast && fast->next && fast->next->next){
        fast=fast->next->next;
        slow=slow->next;
    }

    return slow->val;
}

bool detectloop(Node* head ){
    Node* fast = head;
    Node* slow = head;

    while(fast && fast->next && fast->next->next){
        fast=fast->next->next;
        slow=slow->next;

        if(fast==slow){
            return true;
        }
    }

    return false;
}




int main(){

    Node* head= new Node(1);
    Node* head1= new Node(2);
    Node* head2= new Node(3);
    Node* head3= new Node(4);
    Node* head4= new Node(5);
    Node* head5= new Node(6);
    Node* head6= new Node(7);
    Node* head7= new Node(8);


    head->next=head1;
    head1->next=head2;
    head2->next=head3;
    head3->next=head4;
    head4->next=head5;
    head5->next=head6;
    head6->next=head7;
    // head7->next=head4;


    // display(head);
    // int c = size(head);
    // cout<<c;

    // head = insertion(head , 10 , 8);
    // display(head);


    // head=deletion(head , 3);
    // display(head);


    // head = updation(head,7,99);
    // display(head);

    // head = reverse(head);
    // display(head);

    // cout<<middle(head);

    if(detectloop(head)){
        cout<<"True";
    }else{
        cout<<"False";
    }

    return 0;
}