//codigo em cpp
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iterator>

typedef struct Result
{
    string classType;
    float distacne;
} Result;
using namespace std;

vector<float> split(string str, string delimiter, string *end)
{
    size_t position = 0;
    vector<float> train_result;

    while ((position = str.find(delimiter)) != string::npos)
    {
        train_result.push_back(stof(str.substr(0, position)));
        str.erase(0, position + delimiter.length());
    }
    *end = str;

    return train_result;
}

int main()
{
    float sum;
    string test_line, train_line, classtype;
    vector<float> current_test, current_train;
    vector<Result> result;
    ifstream TEST_FILE("../bases/test_59_small.data");
    ifstream TRAIN_FILE("../bases/train_59_small.data");
    if (!(TEST_FILE.is_open() && TRAIN_FILE.is_open()))
        return 0;

    while (getline(TEST_FILE, test_line))
    {
        current_test = split(test_line, ",", &classtype);

        while (getline(TRAIN_FILE, train_line))
        {
            current_train = split(train_line, ",", &classtype);
        }
    }

    TEST_FILE.close();
    TRAIN_FILE.close();

    return 1;
}