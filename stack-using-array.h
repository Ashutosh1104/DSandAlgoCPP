template<class X>
class ArrayStack{
    X* a =new X[1];
    unsigned long long int top=0;
    unsigned long long int length=1;
    void resize(unsigned long long int size){
        X* temp=new X[size];
        cout<<"resizing to "<<size<<endl;
        memmove(temp, a, length * sizeof(int));
        length=size;
        delete []a;
        a=temp;                
    }
public:
    void push(X item){
        if(top==length){
            resize(length*2);
        }
        a[top++]=item;
    }
    X pop(){
        if(top<=length/4){
            resize(length/2);
        }
        return a[--top];
    }
    bool IsEmpty(){
        return top==0;
    }        
};

