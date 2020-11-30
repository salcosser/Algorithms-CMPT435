#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s1 = "add edge 2 - 3  5";
    string s2 = "add edge 2 - 4  8";
    string s3 = "add edge 2 - 5 -4";
    string s4 = "add edge 1 - 2 0";
    string s5 = "add edge 6 - 7 14";
    string s6 = "add edge 4 - 5 -2";
    vector<string> vec = {s1, s2, s3, s4, s5, s6};

    for (int i = 0; i < vec.size(); i++)
    {
        int hyph = vec[i].find("-");

        int num1 = stoi(vec[i].substr((vec[i].find("edge") + 5), 2)); //grabbing both numbers out
        int num2 = stoi(vec[i].substr(hyph + 2, 2));
        int weight = stoi(vec[i].substr(hyph + 4));

        cout << num1 <<endl;
        cout <<num2 << endl;
        cout <<weight <<endl;
        cout << "-------------"<<endl;
    }

}