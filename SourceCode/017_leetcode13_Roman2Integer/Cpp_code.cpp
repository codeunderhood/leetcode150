#include <iostream>
using namespace std;

int value(char ch)
{
    switch(ch)
    {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
    return 0;
}

int romanToInt(string s)
{
    int result = 0;

    for(int i = 0; i < s.length(); i++)
    {
        int current = value(s[i]);
        int next = value(s[i + 1]);

        if(current < next)
        {
            result -= current;
        }
        else
        {
            result += current;
        }
    }

    return result;
}

int main()
{
    string s = "MCMXCIV";

    cout << romanToInt(s);

    return 0;
}
