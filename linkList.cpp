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

Node* loopstart(Node* head ){
    Node* fast = head;
    Node* slow = head;

    while(fast && fast->next && fast->next->next){
        fast=fast->next->next;
        slow=slow->next;

        if(fast==slow){
            slow=head;

            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }

            return slow;

        }
    }

    return nullptr;
}

bool pallindrome(Node* head){
    Node* slow=head;
    Node* fast=head;

    while(fast&&fast->next&&fast->next->next){
        fast=fast->next->next;
        slow=slow->next;
    }

    slow=reverse(slow);

    Node* temp = head;
    while(temp && slow){
        if(temp->val != slow->val){
            return false;
        }
        slow=slow->next;
        temp=temp->next;
    }

    return true;
}

Node* intersect(Node* h1, Node*h2){

    Node* th1=h1;
    Node* th2=h2;
    
    while(h1!=h2){
        h1=h1->next;
        h2=h2->next;

        if(!h1){
            h1=th2;
        }

        if(!h2){
            h2=th1;
        }
    }

    return h1;
}


Node* segregate(Node *head) {
        
        // Add code here
        int counts[3] = {0};
        
        Node *cur = head;
        while (cur != NULL)
        {
            counts[cur->val] += 1;
            cur = cur->next;
        }
        
        cur = head;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < counts[i]; j++)
            {
                cur->val = i;
                cur = cur->next;
            }
        }
        return head;
}

Node *sortList(Node *head)
{
    vector<int> v;
    Node *temp = head;

    while (temp)
    {
        v.push_back(temp->val);
        temp = temp->next;
    }

    temp = head;
    sort(v.begin(), v.end());

    for (auto it : v)
    {
        temp->val = it;
        temp = temp->next;
    }

    return head;
}

int main(){

    Node* head= new Node(1);
    Node* head1= new Node(2);
    Node* head2= new Node(3);
    Node* head3= new Node(99);
    Node* head4= new Node(4);
    Node* head5= new Node(3);
    Node* head6= new Node(2);
    Node* head7= new Node(1);

    Node* head8= new Node(5);
    Node* head9= new Node(6);
    Node* head10= new Node(7);
    Node* head11= new Node(8);
    Node* head12= new Node(10);


    head->next=head1;
    head1->next=head2;
    head2->next=head3;
    head3->next=head4;
    head4->next=head5;
    head5->next=head6;
    head6->next=head7;
    // head7->next=head4;


    head8->next=head9;
    head9->next=head10;
    head10->next=head3;
    head11->next=head8;
    head12->next=head11;


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

    // if(detectloop(head)){
    //     cout<<"True";
    // }else{
    //     cout<<"False";
    // }

    // Node* ans = loopstart(head);
    // if(ans){
    //     cout<<ans->val;
    // }else{
    //     cout<<"loop not present";
    // }

    // if(pallindrome(head)){
    //     cout<<"yes";
    // }else{
    //     cout<<"no";
    // }

    // Node* ans = intersect(head, head12);
    // cout<<ans->val;

    return 0;
}