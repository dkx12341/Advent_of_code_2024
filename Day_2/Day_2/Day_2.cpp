// Day_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

//part one

vector<vector<int>> get_input(string file_name)
{
    ifstream input_data;
    input_data.open(file_name);

    vector<vector<int>> all_reports;

    if (!input_data) {
        cerr << "Error: Unable to open the file.\n";
    }

    string line;
    
    while (getline(input_data, line)) 
    { 
        std::istringstream iss(line);
        std::vector<int> row;
        int num;

        while (iss >> num)
        { 
            row.push_back(num);
        }

        all_reports.push_back(row);
    }

    input_data.close();

    return all_reports;
}

bool check_row(vector<int> row)
{
    bool safe = true;
    bool asc = true;
    if (row[0] - row[1] > 0)
    {
        asc = false;
    }

    for (int j = 0; j < row.size(); j++)
    {
        if (j != 0 && asc == true && safe == true)
        {
            if (((row[j] - row[j - 1]) >= 4) || ((row[j] - row[j - 1]) <= 0))
            {
                safe = false;
            }
        }
        else if (j != 0 && asc == false && safe == true)
        {
            if (((row[j - 1] - row[j]) >= 4) || ((row[j - 1] - row[j]) <= 0))
            {
                safe = false;
            }
        }
    }
    return safe;
}

int count_safe_reports(string file_name)
{
    vector<vector<int>> all_reports = get_input(file_name);

    int count = 0;

    for (auto i : all_reports)
    {
        if (check_row(i))
        {
            count++;
        }
    }
    return count;
}

//part two

int check_row_with_tolerance(vector<int> row)
{
    int safe = 2;
    bool asc = true;
    if (row[0] - row[1] > 0)
    {
        asc = false;
    }

    for (int j = 0; j < row.size(); j++)
    {
        if (j != 0 && asc == true && safe > 0)
        {
            if (((row[j] - row[j - 1]) >= 4) || ((row[j] - row[j - 1]) <= 0))
            {
                safe += -1;
            }
        }
        else if (j != 0 && asc == false && safe > 0)
        {
            if (((row[j - 1] - row[j]) >= 4) || ((row[j - 1] - row[j]) <= 0))
            {
                safe += -1;
            }
        }
    }
    return safe;
}

int count_safe_reports_with_tolerance(string file_name)
{
    vector<vector<int>> all_reports = get_input(file_name);

    int count = 0;

    for (auto i : all_reports)
    {
        if (check_row_with_tolerance(i)>0)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    //int x = count_safe_reports("input.txt");
    int x = count_safe_reports_with_tolerance("input.txt");
    cout << x;
}

