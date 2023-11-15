#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <conio.h>
using namespace std;

int checkPres(char op);
string ChangeToPostfix(string s);
string ChangeToPrefix(string s);
int EvaluatePostFix(string s);
int EvaluatePrefix(string s);
int Menu();
int ConvertMenu();
int EvaluateOption();
string InputInfix();

int main()
{
    int option = 0;
    int convertOption = 0;
    int evaluateOption = 0;
    string infix = "(2 + 3) * 4";
    string postfix;
    string prefix;
    int postEval;
    int preEval;


    while (option != 3)
    {
        system("cls");
        option = Menu();
        
        if (option == 1)
        {
            while (convertOption != 3)
            {
                system("cls");
                convertOption = ConvertMenu();
                
                if (convertOption == 1)
                {
                    infix = InputInfix();
                    postfix = ChangeToPostfix(infix);
                    cout << "PostFix = " << postfix;
                    _getch();
                }

                if (convertOption == 2)
                {
                    infix = InputInfix();
                    prefix = ChangeToPrefix(infix);
                    cout << "PreFix = " << prefix;
                    _getch();
                }

                system("cls");
            }
        }

        if (option == 2)
        {
            
            while (evaluateOption != 3)
            {
                system("cls");
                evaluateOption = EvaluateOption();
                
                if (evaluateOption == 1)
                {
                    infix = InputInfix();
                    postEval = EvaluatePostFix(infix);
                    cout << "PostFix = " << postEval;
                    _getch();
                }

                if (evaluateOption == 2)
                {
                    infix = InputInfix();
                    preEval = EvaluatePrefix(infix);
                    cout << "PreFix = " << preEval;
                    _getch();
                }
            }
        }
        
    }
    

    return 0;
}

int checkPres(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    return -1;
}

string ChangeToPostfix(string s)
{
    stack<char> exp;
    string expression;

    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
        {
            expression += s[i];
        }
        if (s[i] == '(')
        {
            exp.push(s[i]);
        }
        if (s[i] == ')')
        {
            while (!exp.empty() && exp.top() != '(')
            {
                expression += exp.top();
                exp.pop();
            }
            exp.pop();
        }
        if (!exp.empty() && (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'))
        {
            while (!exp.empty() && checkPres(s[i]) <= checkPres(exp.top()))
            {
                expression += exp.top();
                exp.pop();
            }
            exp.push(s[i]);
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            exp.push(s[i]);
        }
    }

    while (!exp.empty())
    {
        expression += exp.top();
        exp.pop();
    }

    return expression;
}

string ChangeToPrefix(string s)
{
    reverse(s.begin(), s.end());
    

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            s[i] = ')';
        }
        else if (s[i] == ')')
        {
            s[i] = '(';
        }
    }

    cout << s;

    string postfix = ChangeToPostfix(s);
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int EvaluatePostFix(string s)
{
    stack<int> ans;

    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
        {
            ans.push(int(s[i]) - int('0'));
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            int num2 = ans.top();
            ans.pop();
            int num1 = ans.top();
            ans.pop();

            int result;
            if (s[i] == '+')
            {
                result = num1 + num2;
            }
            else if (s[i] == '-')
            {
                result = num1 - num2;
            }
            else if (s[i] == '*')
            {
                result = num1 * num2;
            }
            else if (s[i] == '/')
            {
                result = num1 / num2;
            }
            ans.push(result);
        }
    }

    return ans.top();
}

int EvaluatePrefix(string s)
{
    stack<int> ans;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (isdigit(s[i]))
        {
            ans.push(int(s[i]) - int('0'));
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            int num1 = ans.top();
            ans.pop();
            int num2 = ans.top();
            ans.pop();

            int result;
            if (s[i] == '+')
            {
                result = num1 + num2;
            }
            else if (s[i] == '-')
            {
                result = num1 - num2;
            }
            else if (s[i] == '*')
            {
                result = num1 * num2;
            }
            else if (s[i] == '/')
            {
                result = num1 / num2;
            }
            ans.push(result);
        }
    }

    return ans.top();
}


int Menu()
{
    int option = 0;
    cout << "1.Convert" << endl;
    cout << "2.Evaluate" << endl;
    cout << "3.Exit" << endl;
    cin >> option;
    return option;
}

int ConvertMenu()
{
    int option = 0;
    cout << "1.Convert to PostFix" << endl;
    cout << "2.Convert to PreFix" << endl;
    cout << "3.Exit" << endl;
    cin >> option;
    return option;
}

string InputInfix()
{
    string exp;
    cout << "Enter expression: ";
    cin >> exp;
    return exp;
}


int EvaluateOption()
{
    int option = 0;
    cout << "1.Evaluate PostFix" << endl;
    cout << "2.Evaluate PreFix" << endl;
    cout << "3.Exit" << endl;
    cin >> option;
    return option;
}