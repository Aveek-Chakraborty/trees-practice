#include <bits/stdc++.h>
using namespace std;

int top = -1;

vector<int> create_stack(int n){
    vector<int> s(n);
    return s;
}

void ppush(vector<int> &v, int x){
    top++;
    v[top] = x;
}

int ppop(vector<int> &v){
    int pt = v[top];
    top--;
    return pt;
}

int ttop(vector<int> v){
    return v[top];
}

int ssize(vector<int> v){
    int c;
    for(int i = 0; i<top ; i++){
        c++;
    }
    return c;
}

void display(vector<int> v){
    for(int i = 0; i<top ; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> v = create_stack(10);
    ppush(v, 10);
    ppush(v, 20);
    ppush(v, 30);
    ppush(v, 40);
    ppush(v, 50);
    ppush(v, 60);
    ppush(v, 70);
    ppush(v, 80);
    ppush(v, 90);
    ppush(v, 100);
    // ppush(v, 110);
    display(v);
    cout<<ppop(v)<<endl;
    display(v);
    cout<<ttop(v)<<endl;
    cout<<ssize(v)<<endl;
    display(v);


    return 0;
}