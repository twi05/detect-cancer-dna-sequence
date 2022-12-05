#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*-------------------------For Reading csv file----------------*/

int len(string str)
{
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++)
        length++;

    return length;
}

// create custom split() function
void split(string str, char seperator, vector<string> &strings)
{
    int currIndex = 0, i = 0;
    int startIndex = 0, endIndex = 0;
    while (i <= len(str))
    {
        if (str[i] == seperator || i == len(str))
        {
            endIndex = i;
            string subStr = "";
            subStr.append(str, startIndex, endIndex - startIndex);
            // strings[currIndex] = subStr;
            strings.push_back(subStr);
            currIndex += 1;
            startIndex = endIndex + 1;
        }
        i++;
    }
}
char random_string()
{
    string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    return str[(int)(rand() % str.size())];
}

int main()
{
    vector<string> v;

    string line, word;
    // fstream file("Stock_data.csv", ios::in);
    // fstream file("ADANIPORTS.csv", ios::in);

    fstream file("dataset.csv", ios::in);
    // fstream file("NIFTY50_all.csv", ios::in);

    vector<string> strings;
    char seperator = ',';

    int i = 0;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            i++;
            if (i == 1)
                continue;

            split(line, seperator, strings);
            // cout << strings[2] << endl;

            strings.clear();
            string d = strings[0];
            d += ",";
            string randomstring;

            for (int i = 0; i < 22; i++)
                randomstring += random_string();
            v.push_back(d + randomstring);
        }
    }

    else
        cout << "Could not open the file\n";

    for (int i =0 ; i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
        return 0;
}