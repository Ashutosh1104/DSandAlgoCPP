#include<iostream>
using namespace std;

class UF{
private:
    int* UnionFind;
    int* sz;
    int sizeofArray;
    void Intailize(){
        UnionFind=(int*)calloc(sizeofArray,sizeof(int));
        sz=(int*)calloc(sizeofArray,sizeof(int));
        for(int i=0;i<sizeofArray;i++){
            UnionFind[i]=i;
            sz[i]=1;
        }
    }
    int root(int p){
        while(UnionFind[p]!=p){
            UnionFind[p]=UnionFind[UnionFind[p]];
            p=UnionFind[p];
        }
        return(UnionFind[p]);
    }
public:
    UF(int i){      //Paramitarized Constructer
        sizeofArray=i;
        Intailize();
    }
    bool findConnected(int p ,int q){
        return (root(p)==root(q));
    }
    void Union(int p ,int q){
        int proot=root(p);
        int qroot=root(q);
        if(sz[proot]<sz[qroot]){
            UnionFind[proot]=qroot;
            sz[qroot] =sz[proot]+sz[qroot];
        }
        else{
            UnionFind[qroot]=proot;
            sz[proot]=sz[qroot]+sz[proot];
        }
        for(int i=0;i<sizeofArray;i++){
            cout<<UnionFind[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<sizeofArray;i++){
            cout<<sz[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    // //for Automatic test un-comment

    // UF U1(10);
    // U1.Union(4,3);
    // U1.Union(3,8);
    // U1.Union(6,5);
    // U1.Union(9,4);
    // U1.Union(2,1);
    // cout<<U1.findConnected(8,9)<<endl;//true
    // cout<<U1.findConnected(5,4)<<endl;//false
    // U1.Union(5,0);
    // U1.Union(7,2);
    // U1.Union(6,1);
    // U1.Union(7,3);

    int n,p,q;
    char choice='Y',opeartion;
    cout<<"Enter the no of objects You have: ";
    cin>>n;
    UF U1(n);
    cout<<"You can do two perations \n For Union Enter: U objNo objNo \t For Find Enter: F objNo objNo\n";
    cout<<"Are you ready to perform operations (Y/N) or (y/n) ?: ";
    cin>>choice;
    while(choice=='Y' || choice=='y'){
        cout<<"Enter Operation: ";
        cin>>opeartion>>p>>q;
        if(opeartion=='U'){
            U1.Union(p,q);
        }
        else{
            cout<<U1.findConnected(p,q)<<endl;
        }
        cout<<"Continue (Y/N) or (y/n) ?: ";
        cin>>choice;
    }
     return(0);
}