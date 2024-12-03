// Day_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//part one

pair <vector<int>, vector<int>> get_input(string file_name)
{
    ifstream input_data;
    input_data.open(file_name);

    if (!input_data) {
        cerr << "Error: Unable to open the file.\n";
    }

    int fir_list, sec_list;
    pair <vector<int>, vector<int>> data_lists;

    while (input_data>>fir_list>>sec_list)
    {
        
        data_lists.first.push_back(fir_list);
        data_lists.second.push_back(sec_list);
    }

    input_data.close();
    return data_lists;
}

void sort(pair <vector<int>, vector<int>>& data)
{
    sort(data.first.begin(), data.first.end());
    sort(data.second.begin(), data.second.end());
}


int find_difference(string file_name)
{
    pair <vector<int>, vector<int>> data_lists = get_input(file_name);
    sort(data_lists);

    int difference = 0;

    for (int i = 0; i < data_lists.first.size(); i++)
    {
        difference = difference + (abs(data_lists.first[i] - data_lists.second[i]));
    }
    return difference;
}

//part two

int find_similarity(string file_name)
{
    pair <vector<int>, vector<int>> data_lists = get_input(file_name);
    sort(data_lists);

    int similarity = 0;

    for (int i = 0; i < data_lists.first.size(); i++)
    {
        int x = count(data_lists.second.begin(), data_lists.second.end(), data_lists.first[i]);
        similarity = similarity + (abs(data_lists.first[i]*x));
    }
    return similarity;
}


int main()
{
    //int x = find_difference("input.txt");
    int x = find_similarity("input.txt");
    cout << x;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
