#include<iostream>

typedef int ElemType;
class Node
{
    public:
        Node(ElemType e) ;
        ~Node();
        Node* addr();
        void setData(ElemType e);
        ElemType getData();
        void setNext(Node* next);
        Node* getNext();
        
    private:
        ElemType data;
        Node* next;
};

class LinkList
{
    public:
        LinkList();
        ~LinkList();
        void creat();
        void display();
        Node* findByLoc(int i);
        Node* findByElem(ElemType e,int order);
        void insertLoc(int i,ElemType e);
        void insertElemBefore(ElemType aime,int i,ElemType ine);
        void insertElemAfter(ElemType aime,int i,ElemType ine);
        ElemType del(int i);

    private:
        Node* Head;
        int length;
};

