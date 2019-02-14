#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

typedef struct student
{
    char name[15];
    char sex;
    char ID[15];
    int grade;
} student;

int main()
{
    int n;
    scanf("%d",&n);
    student a[n];
    int pos_low_male = -1;
    int low_male_grade = 200;
    int pos_hst_female = -1;
    int hst_female_grade = 0;
    for(int i=0;i<n;i++)
    {
        scanf("%s %c %s %d",&a[i].name,&a[i].sex,&a[i].ID,&a[i].grade);
        if(a[i].sex == 'F') { if(a[i].grade > hst_female_grade)
            {
                pos_hst_female = i;
                hst_female_grade = a[i].grade;
            }
        }
        if(a[i].sex == 'M')
        {
            if(a[i].grade < low_male_grade)
            {
                pos_low_male = i;
                low_male_grade = a[i].grade;
            }
        }
    }

    if(pos_hst_female == -1)
        printf("Absent\n");
    else
        printf("%s %s\n",a[pos_hst_female].name,a[pos_hst_female].ID);

    if(pos_low_male == -1)
        printf("Absent\n");
    else
        printf("%s %s\n",a[pos_low_male].name,a[pos_low_male].ID);

    if(pos_low_male == -1 || pos_hst_female == -1)
        printf("NA");
    else
        printf("%d",a[pos_hst_female].grade - a[pos_low_male].grade);
    
    return 0;
}
