#include<iostream>
#include<string>

using namespace std;

int getSubStrLength(string s1,string s2)
{
    int max_length = 0;
    for(int i=0;i<(int)s1.length();i++)
    {
        for(int j=0;j<(int)s2.length();j++)
        {
            if(s2[j] != s1[i])
                continue;
            else    
            {
                int l = 0;
                int t_i = i;
                int t_j = j;

                while(t_i<(int)s1.length() && t_j<(int)s2.length()
                        && s1[t_i] == s2[t_j])
                {
                    t_i++;
                    t_j++;
                }
                l = t_i - i;

                if(l>max_length)
                    max_length = l;
            }
        }
    }
    return max_length;
}

int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    int l = getSubStrLength(s1,s2);
    cout<<l<<endl;
}
