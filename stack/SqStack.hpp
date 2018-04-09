#include<iostream>
using namespace std;
#define OK 1
#define ERRO 0
typedef int Status;

template<typename ElemType>
class SqStack 
{
    public:
        Status pop(ElemType& e);
        Status push(ElemType e);
        bool isEmpty() const;
        bool isFull() const;
        int getLength() const;
        int getStackSize() const;
        SqStack<ElemType>& operator=(const SqStack<ElemType>& otherS);
        void show() const;
    

        SqStack(int max_length);
        ~SqStack();
        SqStack(SqStack<ElemType>& otherS);

    private:
        ElemType* top;
        ElemType* base;
        int max_length;
};


template<typename ElemType>
Status SqStack<ElemType>::pop(ElemType& e)
{
    if(isEmpty())
    {
        cout<<"stack is empty"<<endl;
        return ERRO;
    }
    top--;
    e = *top;
    return OK;
}


template<typename ElemType>
Status SqStack<ElemType>::push(ElemType e)
{
    if(isFull())
    {
        cout<<"stack is full"<<endl;
        return ERRO;
    }
    *top = e;
    top++;
    return OK;
}

template<typename ElemType>
bool SqStack<ElemType>::isFull() const
{
    if(getLength() == max_length)
        return 1;
    return 0;
}

template<typename ElemType>
bool SqStack<ElemType>::isEmpty() const
{
    if(top == base)
        return 1;
    return 0;
}

template<typename ElemType>
int SqStack<ElemType>::getLength() const
{
    return (top-base);                  //? automatically caculate the +1/-1 size of the pointer?
}


template<typename ElemType>
int SqStack<ElemType>::getStackSize() const
{
    return getLength()*sizeof(ElemType);
}

template<typename ElemType>
SqStack<ElemType>& SqStack<ElemType>::operator=(const SqStack<ElemType>& otherS) //not deep copy
{
    delete [] base;
    top = NULL;
    max_length = otherS.max_length;
    base = new ElemType[otherS.max_length];
    top = base;
    ElemType t;
    while( otherS.pop(&t))
        push(t);
}

template<typename ElemType>
void SqStack<ElemType>::show() const
{
    ElemType* p=base;
    while(p!=top)
        cout<<*(p++)<<' ';
    cout<<endl;
}

template<typename ElemType>
SqStack<ElemType>::SqStack(SqStack<ElemType>& otherS)
{
    max_length = otherS.max_length;
    base = new ElemType[max_length];
    top = base+otherS.getLength();
    ElemType* p = base;
    ElemType* q = otherS.base;
    while(p != top)
    {
        *p = *q;
        p++;
        q++;
    }
}

template<typename ElemType>
SqStack<ElemType>::~SqStack()
{
    delete [] base;
    top = NULL;
}

template<typename ElemType>
SqStack<ElemType>::SqStack(int max_length)
{
    this->max_length = max_length;
   base = new ElemType[this->max_length]; 
   top = base;
}
