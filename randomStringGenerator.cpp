#include <random>
#include <string>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char random_string()
{
    string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    return str[(int)(rand() % str.size())];
}
int main()
{
    for (int i = 0; i < 15; i++)
    {

        for (int i = 0; i < 22; i++)
            cout << random_string();
        cout << endl;
    }
   cout<<string("AGCCCTAAGGGCTACCTAGCTT").size();
    return 0;
}