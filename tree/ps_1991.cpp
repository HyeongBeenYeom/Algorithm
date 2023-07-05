#include <cstdio>
#include <iostream>
#include <vector>

struct node{
    char l;
    char r;
};

using namespace std;

vector<node> v(26);
int N;

void preorder(char node){
    if(node == '.')
        return;

    cout << node;
    preorder(v[node].l);
    preorder(v[node].r);
}

void inorder(char node){
    if(node == '.')
        return;

    inorder(v[node].l);
    cout << node;
    inorder(v[node].r);
}

void postorder(char node){
    if(node == '.')
        return;

    postorder(v[node].l);
    postorder(v[node].r);
    cout << node;
}
int main(){

    cin >> N;
    char root, left, right;

    for(int i=0;i<N;i++){
        cin >> root >> left >> right;
        v[root].l = left;
        v[root].r = right;
    }

    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    return 0;
}