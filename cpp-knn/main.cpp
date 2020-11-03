//codigo em cpp
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef struct Result
{
    string classType;
    float distance;
} Result;

typedef struct ClassResult
{
    int types[6];
} ClassResult;

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

float absolute(float x, float y)
{
    if (x - y < 0)
        return (x - y) * -1;
    return x - y;
}

Result calculateDistance(vector<float> test, vector<float> train, string classtype)
{
    Result aux;
    aux.distance = 0;

    aux.classType = classtype;
    for (int i = 0; i < test.size(); i++)
    {
        aux.distance += absolute(test.at(i), train.at(i));
    }
    return aux;
}

bool compare(Result x, Result y)
{
    return (x.distance < y.distance);
}

void calculateClass(string str, ClassResult *x)
{
    if (str.compare("samba") == 0)
        x->types[0]++;
    else if (str.compare("sertanejo") == 0)
        x->types[1]++;
    else if (str.compare("forro") == 0)
        x->types[2]++;
    else if (str.compare("rap") == 0)
        x->types[3]++;
    else if (str.compare("axe") == 0)
        x->types[4]++;
    else if (str.compare("bossa_nova") == 0)
        x->types[5]++;
}

string resultClass(ClassResult x)
{
    int greater = x.types[0], greaterIndex = 0;
    for (int i = 1; i < 6; i++)
    {
        if (x.types[i] > greater)
        {
            greater = x.types[i];
            greaterIndex = i;
        }   
    }

    if (greaterIndex == 0)
        return "Samba";
    else if (greaterIndex == 1)
        return "Sertanejo";
    else if (greaterIndex == 2)
        return "Forro";
    else if (greaterIndex == 3)
        return "Rap";
    else if (greaterIndex == 4)
        return "Axe";
    else if (greaterIndex == 5)
        return "Bossa Nova";

    return "";
}

int main(int argc, char *argv[])
{
    float sum;
    string test_line, train_line, classtype;
    vector<float> current_test, current_train;
    vector<vector<Result>> result;
    vector<Result> aux;
    ifstream TEST_FILE("../bases/test_59.data");
    ifstream TRAIN_FILE("../bases/train_59.data");
    if (!(TEST_FILE.is_open() && TRAIN_FILE.is_open()))
        return 0;

    while (getline(TEST_FILE, test_line))
    {
        current_test = split(test_line, ",", &classtype);
        aux.clear();

        while (getline(TRAIN_FILE, train_line))
        {
            current_train = split(train_line, ",", &classtype);
            aux.push_back(calculateDistance(current_test, current_train, classtype));
        }
        result.push_back(aux);
        TRAIN_FILE.clear();
        TRAIN_FILE.seekg(0);
    }

    for (int i = 0; i < result.size(); i++)
    {
        sort(result.at(i).begin(), result.at(i).end(), compare);
    }

    int counter = 1;

    ClassResult classResult;
    for (vector<Result> x : result)
    {
        cout << "\n==========Test #" << counter++ << "==========\n";
        for (int i = 0; i < 6; i++)
            classResult.types[i] = 0;
        for (int k = 0; k < stoi(argv[1]); k++)
        {
            calculateClass(x.at(k).classType, &classResult);
        }
        cout << resultClass(classResult);
    }

    TEST_FILE.close();
    TRAIN_FILE.close();

    return 1;
}