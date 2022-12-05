#include <bits/stdc++.h>
#include <fstream>
using namespace std;
typedef long long ll;

struct CancerGenomics
{
    string sequence;
    string name;
};

typedef struct CancerGenomics cg;

int lcs(vector<vector<int>> v, string s, string t)
{
    for (int i = 0; i < v.size(); i++)
    {
        v[i][0] = 0;
    }
    for (int j = 0; j < v[0].size(); j++)
    {
        v[0][j] = 0;
    }

    for (int i = 1; i < v.size(); i++)
    {
        for (int j = 1; j < v[0].size(); j++)
        {
            if (s[i] != t[j])
                v[i][j] = max(v[i - 1][j], v[i][j - 1]);

            else
                v[i][j] = v[i - 1][j - 1] + 1;
        }
    }
    return v[v.size() - 1][v[0].size() - 1];
}

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

void split_c(string str, CancerGenomics &c)
{
    string w = "";
    for (char x : str)
    {
        if (x == ',')
        {
            c.name = w;
            w = "";
        }
        else
        {
            w = w + x;
        }
    }
    c.sequence = w;
}

int main()
{
    vector<string> v;

    string line, word;

    fstream file("dataset.csv", ios::in);

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
    {
        cout << "Could not open the file\n";
    }

    fstream fout;
    int status;

    fout.open("dna_lcs.csv", ios::out);

    vector<cg> cancerdata(v.size());

    fout << "Name of Cancer"
         << ","
         << "Stage of Cancer"
         << "\n";

    // input person data. Also give option to see demo. Means ask user to input or demo with default person dna sequence

    // string person_dna_sequence = "CXGGBWKFNPPUXWFNFOZVSR";
    // string person_dna_sequence = "WHMSNCBXCOKSFZKVATXDKN";
    string person_dna_sequence = "KDCPWSRTESJWHDIZCOBZCN";
    
    int matched_sequence = 0;
    bool foundCancer = false;
    int cancerStage = 0;
    int total_cancers_found = 0;
    for (int i = 0; i < v.size(); i++)
    {
        split_c(v[i], cancerdata[i]);

        vector<vector<int>> v(person_dna_sequence.length() + 1, vector<int>(cancerdata[i].sequence.length() + 1, 0));
        matched_sequence = lcs(v, person_dna_sequence, cancerdata[i].sequence);
        if (matched_sequence > cancerdata[i].sequence.length() * 0.4)
        {
            foundCancer = true;
            cout << "Found Cancer. Type of cancer: " << cancerdata[i].name << endl;
            cout << "Stage of cancer:  " << (double)matched_sequence / 22 << endl;
            fout << cancerdata[i].name << "," << (double)matched_sequence / 22 << "\n"; // writing data to a csv file
            total_cancers_found++;
            cout << endl;
        }
    }
    fout.close();
    if (foundCancer)
        cout << "\nTotal primary cancers found: " << total_cancers_found;
    if (!foundCancer)
        cout << "Not found any kind of Cancer.";
    return 0;
}