
#include <iostream>
#include <vector>
using namespace std;

int top = -1;
int front=-1;

vector<int> create_q(int n){
    vector<int> q(n);
    return q;
}

void enq(vector<int> &v ,int x){
    v[++top]=x;
    if(front==-1){
        front++;
    }
}

int deq(vector<int> &v){
    int x = v[front];
    if(front!=top)front++; else {front=-1;top=-1;}
    return x;
}

int ffront(vector<int>& v){
    return v[front];
}
int ssize(vector<int>& v){
    int c=0;
    for(int i = front; i<top ; i++){
        c++;
    }
    return c;
}

void display(vector<int>& v){
    for(int i = front; i<top ; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main() {
    vector<int> v = create_q(10);
    enq(v, 10);
    enq(v, 20);
    enq(v, 30);
    enq(v, 40);
    enq(v, 50);
    enq(v, 60);
    enq(v, 70);
    enq(v, 80);
    cout << deq(v) << endl;
    cout << deq(v) << endl;
    cout << deq(v) << endl;
    cout << deq(v) << endl;
    cout << deq(v) << endl;
    cout << deq(v) << endl;
    cout << deq(v) << endl;
    cout << deq(v) << endl;

    return 0;
}