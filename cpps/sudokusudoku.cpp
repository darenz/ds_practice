#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int numbers[9];
int table[81];
int crr_fill;

bool JugdeLine(int tryNum)
{
    int lineStart = (crr_fill/9)*9; //左闭右开
    int lineEnd = lineStart + 9;
    for(int i=lineStart;i<lineEnd;i++)
        if(table[i] == tryNum)
            return false;
    return true;
}

bool JugdeRow(int tryNum)
{
    int rowStart = crr_fill%9 - 1;
    for(int i=0;i<9;i++)
    {
        if(table[rowStart+i*9] == tryNum) 
            return false;
    }
    return true;
}

bool JugdeBox(int tryNum)
{
    int inl = (crr_fill/9)%3 ;// 0,1,2
    int inr = (crr_fill%9)%3; //0,1,2
    int boxStart = (crr_fill - inr) - inl*9;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(table[boxStart+i*9+j]==tryNum)
                return false;
        }
    }
    return true;
}

bool JugdeValid(int tryNum)
{
    bool line_flag,row_flag,box_flag;
    line_flag = JugdeLine(tryNum);
    row_flag = JugdeRow(tryNum);
    box_flag = JugdeBox(tryNum);
    return line_flag && row_flag && box_flag;
}

bool allTried(int *tryTable,int n)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(tryTable[i]==1)
            count++;
    }
    if(count==n)
        return true;
    else 
        return false;
}

void PrintTable()
{
    int *out[4];
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
            cout<<out[i][j];
        cout<<endl;
    }
}

bool generate()
{
    if(crr_fill==81)
        return true;
    int tried[9]= {};
    while(true){
        int randIndex = rand()%9;
        if(tried[randIndex]==1)
            continue;
        tried[randIndex] = 1;
        bool valid_flag = JugdeValid(numbers[randIndex]);
        if(valid_flag == true)
        {
            table[crr_fill] = numbers[randIndex];
            crr_fill++;
            bool flag = generate();
            if(flag == true) return true;
            crr_fill--;
        }
        if(allTried(tried,9))
            return false;
   }
}

int main()
{
    for(int i=0;i<9;i++)    
        numbers[i] = i+1;
    srand((int)time(0)) ;
    generate();
//    while(1)
//    {
//        int tried[9] = {};
//        int randIndex;
//        bool valid_flag; 
//        while(1)
//        {
//            randIndex = rand()%9;
//            if(tried[randIndex]==1)
//                continue;
//            tried[randIndex] = 1;
//            int tryNum = numbers[randIndex];
//            valid_flag = JugdeValid(tryNum);
//            if(valid_flag == 1)
//                break;
//            else if(allTried(tried,9)) //valid_flag==0,allTried()=1
//                break;
//            else ;
//        }
//        if(valid_flag == 1)
//        {
//            table[crr_fill] = numbers[randIndex];
//            crr_fill++;
//            if(crr_fill==81)
//                break;
//        }
//        else if(valid_flag == 0)
//            crr_fill -= 10;
//    }
    PrintTable();
    return 0;
}

