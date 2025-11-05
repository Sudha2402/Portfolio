#include <iostream>
#include <string>
using namespace std;

string encryp(string str)
{
    string ans;
    for (int i = 0; i < str.size(); i++)
    {
        ans += (str[i] - 3) % ('z' - 'a'+1);
    }

    return ans;
}

int main()
{
    string ans = encryp("abcd");
    // cout<<('z' - 'a')<<endl;
    cout<<ans<<endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
}