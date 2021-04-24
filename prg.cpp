#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    fstream file, file1;
    string word, t, q, filename, filename1;

    FILE *fp;
    
    fp=fopen("sample_output.txt", "w");
    

    // filename of the file
    filename = "sample_input.txt";
    filename1 = "sample_output.txt";
    // opening file
    file.open(filename.c_str());
    file1.open(filename1.c_str());

    // extracting words from the file
    string line;
    vector<pair<int, string>> v;
    int k = 0;
    int countEmp;

    while (getline(file, line)) {
        string key = "";
        string value = "";
        string delimiter = ":";
        if (k == 0) {
            key = line.substr(0, line.find(delimiter) + 2);
            value = line.substr(key.size(), line.size() - key.size() - 1);
            countEmp = stoi(value);
        }
        else if (k == 1 || k == 2 || k == 3) {
        }
        else {
            key = line.substr(0, line.find(delimiter) + 2);
            value = line.substr(key.size(), line.size() - key.size());
            v.push_back(make_pair(stoi(value), key));
        }
        k++;
    }
    //sort the vector
    sort(v.begin(), v.end());

    //main logic
    int result = INT_MAX;
    int n = v.size();
    int minIndex = 0;
    for (int i = 0; i <= (n - countEmp); i++) {
        int diff = v[(i + countEmp - 1)].first - v[i].first;
        if (diff <= result) {
            result = diff;
            minIndex = i;
        }
    }
    fprintf(fp,"The goodies selected for distribution are:\n\n" );
    for (int i = minIndex; i < minIndex + countEmp; i++) {
        string str=v[i].second+" "+to_string(v[i].first)+"\n";
        char char_array[str.size()+1];
        strcpy(char_array, str.c_str());
        fprintf(fp, char_array);
    }
    fprintf(fp,"\nAnd the difference between the chosen goodie with highest price and the lowest price is ");
    string str=to_string(result);
    char char_array[str.size()+1];
    strcpy(char_array, str.c_str());
    fprintf(fp, char_array);
    fclose(fp);

}