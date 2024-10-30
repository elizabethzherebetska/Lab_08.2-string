#include <iostream>
#include <string>

using namespace std;

string TrimAndReduceSpaces(const string& s)
{
    string result = s;
    size_t start = result.find_first_not_of(' '); // Знаходимо перший непробільний символ
    size_t end = result.find_last_not_of(' '); // Знаходимо останній непробільний символ

    if (start == string::npos) // Якщо тільки пробіли, повертаємо порожній рядок
        return "";

    result = result.substr(start, end - start + 1); // Видаляємо початкові та кінцеві пробіли

    string finalResult;
    bool inSpace = false;

    for (char c : result)
    {
        if (c != ' ')
        {
            finalResult += c;
            inSpace = false;
        }
        else if (!inSpace) // Додаємо один пробіл для кожної групи пробілів
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
