#include<iostream>
using namespace std;
class UF{
private:
   int sizeofArray;
    int* UnionFind;
    void intialize(){
        UnionFind = (int*) calloc (sizeofArray,sizeof(int));
        for(int i=0;i<sizeofArray;i++){
            UnionFind[i]=i;//make a forest
        }
    }
public:
    UF(int i) { 
        sizeofArray = i;  
        intialize();      
    }
    bool connected(int p,int q){
        return (UnionFind[p]==UnionFind[q]);
    }
    void Union(int p,int q){
        int pid=UnionFind[p];
        int qid=UnionFind[q];
        for(int i=0;i<sizeofArray;i++){
            if(UnionFind[i]==qid){
                UnionFind[i]=pid;
            }
        }
        cout<<endl;
    }
};
int main(){
    // for Automatic test un-comment

    UF U1(10);
    U1.Union(4,3);
    U1.Union(3,8);
    U1.Union(6,5);
    U1.Union(9,4);
    U1.Union(2,1);
    cout<<U1.connected(8,9)<<endl;//true
    cout<<U1.connected(5,4)<<endl;//false
    U1.Union(5,0);
    U1.Union(7,2);
    U1.Union(6,1);
    U1.Union(7,3);

    // int n,p,q;
    // char choice='Y',opeartion;
    // cout<<"Enter the no of objects You have: ";
    // cin>>n;
    // UF U1(n);
    // cout<<"You can do two perations \n For Union Enter: U objNo objNo \t For Find Enter: F objNo objNo\n";
    // cout<<"Are you ready to perform operations (Y/N) or (y/n) ?: ";
    // cin>>choice;
    // while(choice=='Y' || choice=='y'){
    //     cout<<"Enter Operation: ";
    //     cin>>opeartion>>p>>q;
    //     if(opeartion=='U'){
    //         U1.Union(p,q);
    //     }
    //     else{
    //         cout<<U1.connected(p,q)<<endl;
    //     }
    //     cout<<"Continue (Y/N) or (y/n) ?: ";
    //     cin>>choice;
    // }
    // return(0);
}