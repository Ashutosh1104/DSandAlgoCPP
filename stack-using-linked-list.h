template < class X >
class Linkstack{
  class node{
    public:
      X item;
      node* next;
  };
  node* first=NULL;
  node* temp;
  public:
    bool IsEmpty(){
      return first == NULL;
    }
    X pop(){
      temp=first;
      X item = first->item;
      first=first->next;
      free(temp);
      return item;
    }
    void push(X abc){
      node* newNode= new node;
      newNode->item=abc;
      newNode->next=first;
      first= newNode;
    }
};