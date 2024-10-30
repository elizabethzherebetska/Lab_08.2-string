#include <iostream>
#include <string>

using namespace std;

string TrimAndReduceSpaces(const string& s)
{
    string result = s;
    size_t start = result.find_first_not_of(' '); // ��������� ������ ����������� ������
    size_t end = result.find_last_not_of(' '); // ��������� ������� ����������� ������

    if (start == string::npos) // ���� ����� ������, ��������� ������� �����
        return "";

    result = result.substr(start, end - start + 1); // ��������� �������� �� ����� ������

    string finalResult;
    bool inSpace = false;

    for (char c : result)
    {
        if (c != ' ')
        {
            finalResult += c;
            inSpace = false;
        }
        else if (!inSpace) // ������ ���� ����� ��� ����� ����� ������
        {
            finalResult += ' ';
            inSpace = true;
        }
    }
    return finalResult;
}

int main()
{
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);
    cout << "Transformed string: \"" << TrimAndReduceSpaces(str) << "\"" << endl;
    return 0;
}
