#include<iostream>
#include"static_list.h"
#include<assert.h>
using namespace std;

StList::StList(int max)
{
    max_size = max;
    elem = new ElemType(max_size);
    assert(elem!=0);
    length = 0;
}

StList::~StList()
{
    delete [] elem;
}

StList::StList(StList &otherL)
{
    ElemType* elem = new ElemType[otherL.GetLength()];
    assert(elem!=0);
    max_size = otherL.GetMaxSize();
    length = otherL.GetLength();
}

StList& StList::operator=(StList &otherL)
{
    delete [] elem;
    elem = new ElemType[otherL.GetLength()];
    length = otherL.GetLength();
    max_size = otherL.GetMaxSize();
    return *this;
}

ElemType StList::DeleteElem(int i)
{
    if(i<0 || i>length)
    {
        cout<<"no element"<<endl;
        return 0;
    }
    int e = elem[i-1];
    for(int j=i;j<=length;j++)
    {
        elem[j-1] = elem[j];
    }
    length--;
    return e;
}

Status StList::Insert(int i,ElemType e)
{
    int j;
    if(i<1 || i>length+1)
    {
        cout<<"index erro"<<endl;
        return ERRO;
    }
    if(length>=max_size)
    {
        max_size += 10;
        ElemType *new_elem = new ElemType[max_size];
        if(new_elem == NULL)
        {
            cout<<"new failed"<<endl;
            return ERRO;
        }
        for(int i=0;i<length;i++)
        {
            new_elem[i] = elem[i];
        }
        delete [] elem;
        elem = new_elem;
        new_elem = NULL;
    }
    for(j=length;j>=i-1;j--)
    {
       elem[j+1] = elem[j] ;
    }
    elem[i-1] = e;
    length++;
    return OK;
}

Status StList::compare(ElemType e,char c,int *index)
{
    int i;
    if(c!='>' || c!='<' || c!='=')
    {
        cout<<"systnax erro"<<endl;
        return ERRO;
    }
    if(c=='>')
    {
        for(i=0;i<length;i++)
        {
            if(elem[i]>e)
                break;
        }
        *index = i;
        return OK;
    }
    if(c=='<')
    {
        for(i=0;i<length;i++)
        {
            if(elem[i]<e)
                break;
        }
        *index = i;
        return OK;
    }
    if(c=='=')
    {
        for(i=0;i<length;i++)
        {
            if(elem[i]==e)
                break;
        }
        *index = i;
        return OK;
    }
}

Status StList::SetEmpty()
{
    length = 0;
    return OK;
}

int StList::GetLength()
{
    return length;
}

int StList::GetMaxSize()
{
    return max_size;
}

bool StList::IsEmpty()
{
    if(length == 0)
        return 1;
    else
        return 0;
}

Status StList::ShowList()
{
    if(length==0)
    {
        cout<<"list is empty"<<endl;
        return OK;
    }
    for(int i=0;i<length;i++)
    {
        cout<<elem[i]<<' ';
    }
    cout<<endl;
    return OK;
}
