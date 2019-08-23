#include<iostream>
using namespace std;

class UF{
private:
    int sizeofArray;
    int* unionFind;
    void intialize(){
        unionFind = (int*) calloc (sizeofArray,sizeof(int));
        for(int i=0;i<sizeofArray;i++){
            unionFind[i]=i;//make a forest
        }
    }
    int root(int p){
        while(unionFind[p]!=p){
            p=unionFind[p];
        }
        return(unionFind[p]);
    }
public:
    UF(int i) { 
        sizeofArray = i;  
        intialize();      
    }
    bool findConnected(int p,int q){
        return(root(p)==root(q));
    }
    void Union(int p,int q){
        int proot=root(p);
        int qroot=root(q);
        unionFind[proot]=qroot; 
    }
};
int main(){
    // for Automatic test un-comment

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