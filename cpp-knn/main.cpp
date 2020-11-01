//codigo em cpp
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iterator>

using namespace std;

int main()
{
    string test_line, train_line, delimiter = ",";
    ifstream TEST_FILE("../bases/test_59_small.data");
    ifstream TRAIN_FILE("../bases/train_59.data");
    if (!(TEST_FILE.is_open() && TRAIN_FILE.is_open()))
        return 0;

    while (getline(TEST_FILE,test_line))
    {
        vector<string> current_test;
        
    }
    
    TEST_FILE.close();
    TRAIN_FILE.close();
}