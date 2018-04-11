#define ERRO 0
#define OK 1
typedef int Status;

template<typename ElemType>
class LinkList
{
        class LinkNode
        {
             public:
                ElemType elem;
                LinkNode* next;
        };
        typedef LinkNode* NodePointer;

        LinkList();
        ~LinkList();
        LinkList& LinkList(LinkList& otherL);
        
        Status append(ElemType e);
        Status insert(int i,ElemType e);
        Status deleteElem(ElemType e);
        Status clear();
        int getLength();
        NodePointer getHead();
        Status showList();
    private:
        NodePointer head;
        int length;
};
