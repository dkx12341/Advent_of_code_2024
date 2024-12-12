// Day_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <regex>
using namespace std;

//part one

string get_input(string file_name)
{
    ifstream input_data;
    input_data.open(file_name);

    if (!input_data) 
    {
        cerr << "Error: Unable to open the file.\n";
    }

    string line;
    string data;

    while (input_data>>line)
    {
        data.append(line);
    }
    input_data.close();
    return data;
}

vector<pair<int, int>> find_nums_in_str(string str)
{
    vector<pair<int, int>> nums;


    regex pattern(R"(mul\((\d{0,3}),(\d{0,3})\))");

    string::const_iterator search_start(str.begin());

    smatch numbers;

    while (regex_search(search_start, str.cend(), numbers, pattern))
    {

        if (numbers.size() == 3)
        {
            int first = std::stoi(numbers[1]);
            int second = std::stoi(numbers[2]);
            nums.emplace_back(first, second);
        }
        search_start = numbers.suffix().first;
    }

    return nums;
}



int calculate_result(string file_name)
{
    string data = get_input(file_name);
    vector<pair<int, int>> matches = find_nums_in_str(data);

    int count = 0;

    for (auto i : matches)
    {
        count += i.first * i.second;
    }
    return count;
}


//part two

vector<pair<int, int>> find_matches_in_str(string str)
{
    vector<pair<int, int>> nums;
    
    bool active = 1;


    
    regex num_pattern(R"(mul\((\d{0,3}),(\d{0,3})\))");

    string::const_iterator search_start(str.begin());

    smatch numbers;

    while (regex_search(search_start, str.cend(), numbers, num_pattern))
    {

        if (numbers.size() == 3)
        {
            int first = std::stoi(numbers[1]);
            int second = std::stoi(numbers[2]);
            nums.emplace_back(first, second);
        }
        search_start = numbers.suffix().first;
    }

    return nums;
}



int main()
{
    int x = calculate_result("input.txt");
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
