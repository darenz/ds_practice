typedef int ElemType;
typedef int Status; 
#define OK 1
#define ERRO 0

class StList
{
    public:
        StList(int max);
        ~StList();
        StList(StList &otherL);
        StList& operator=(StList &otherL);
        ElemType DeleteElem(int i);
        Status Insert(int i,ElemType e);
        int compare(ElemType e,char c,int *index);
        Status SetEmpty();
        int GetLength();
        int GetMaxSize();
        bool IsEmpty();
        Status ShowList();

    private:
        int max_size;
        int length;
        ElemType* elem;
};
