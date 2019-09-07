#pragma once
#include "Stack.h"
#include "string"
#include <sstream>
#include "Math.h"


class Calculator
{
private:
	Stack<char> infixStack;
	std::string postfix;
	std::string infix;
	Stack<int> calc;
	bool validChar(char c);

public:
	Calculator() :postfix("") {};
	std::string toPostfix(std::string infix);
	std::string getPostfix();
	bool validFormat(std::string infix, std::string &error);
	int calculate();
};

bool Calculator::validChar(char c)
{
	if ( isdigit(c) || c == '+' || c == '-'
		|| c == '(' || c == ')' || c == '*'
		|| c == '/' || c == '%' || c == '^')
		return true;
	else
		return false;
	
}

std::string Calculator::toPostfix(std::string inf)
{
	infix = inf;
	int size = infix.size();
	postfix = "";
	char prev = ' ';
	char prevPrev = ' ';
	for (int x = 0; x < infix.size(); x++)
	{
		if (infix[x] != ' ')
		{
			if (validChar(infix[x]))
			{

				if (isdigit(infix[x]))
				{
					while (isdigit(infix[x]))
					{
						postfix += infix[x];
						x++;
					}
					x--;
					postfix += ' ';
				}
				else if (infix[x] == '(')
				{
					infixStack.push(infix[x]);
				}
				else if (infix[x] == '^')
				{
					infixStack.push(infix[x]);
				}
				else if (infix[x] == '*' || infix[x] == '/' || infix[x] == '%')
				{
					if (!infixStack.empty())
					{
						if (infixStack.top() == '+' || infixStack.top() == '-' || infixStack.empty())
							infixStack.push(infix[x]);
						else
						{
							while (!infixStack.empty())
							{
								if (infixStack.top() == '('
									|| infixStack.top() == '+' || infixStack.top() == '-')
									break;
								postfix += infixStack.pop();
								postfix += ' ';
							}
							infixStack.push(infix[x]);
						}
					}
					else
						infixStack.push(infix[x]);

				}
				else if (infix[x] == '+' || infix[x] == '-')
				{
					if (infix[x] == '-')
					{
						int search = x + 1;

						while (!validChar(infix[search]) && search < infix.length())
						{
							search++;
						}
						if (isdigit(infix[search]))
						{
							if (prev == '(' || prev == '+' || prev == '-'
								|| prev == '*' || prev == '/' || prev == '%' || prev == '^'
								|| prev == ' ' || prev == '(')
							{
								postfix += '-';
							}
							else
							{
								if (!infixStack.empty())
								{
									while (!infixStack.empty())
									{
										if (infixStack.top() == '(')
											break;
										postfix += infixStack.pop();
										postfix += " ";
									}
								}
								infixStack.push(infix[x]);
							}
								
						}
						else
						{
							while (!infixStack.empty() && infixStack.top() != '(')
							{
								postfix += infixStack.pop();
								postfix += ' ';
							}

							infixStack.push(infix[x]);
						}
					}
					else
					{
						while (!infixStack.empty() && infixStack.top() != '(')
						{
							postfix += infixStack.pop();
							postfix += ' ';
						}

						infixStack.push(infix[x]);
					}
				}
				else
				{
					while (!infixStack.empty() && (infixStack.top() != '('))
					{
						postfix += infixStack.pop();
						postfix += ' ';
					}
					infixStack.pop();
				}
				prevPrev = prev;
				prev = infix[x];
			}

		}
	}
	while (!infixStack.empty() && (infixStack.top() != '('))
	{
		postfix += infixStack.pop();
		if (!infixStack.empty())
			postfix += ' ';
	}

	return postfix;
}

std::string Calculator::getPostfix()
{
	return postfix;
}

int Calculator::calculate()
{
	std::stringstream ss;
	std::string next;
  int nexti;
  int operand1;
  int operand2;
  bool negative = false;
  if (postfix == "")
  return 0;
  else
  {
    ss << postfix;

    while (ss >> next)
    {
      if (isdigit(next[0]) || (next[0] == '-' && next.length() > 1))
      {
        nexti = stoi(next);

        calc.push(nexti);
      }
      else if (validChar(next[0]))
      {
        if (next[0] == '^')
        {
          operand2 = calc.pop();
          operand1 = calc.pop();
          operand1 = pow(operand1, operand2);
          calc.push(operand1);
        }
        else if (next[0] == '*')
        {
          operand2 = calc.pop();
          operand1 = calc.pop();
          operand1 *= operand2;
          calc.push(operand1);
        }
        else if (next[0] == '/')
        {
          operand2 = calc.pop();
          operand1 = calc.pop();
          operand1 /= operand2;
          calc.push(operand1);
        }
        else if (next[0] == '%')
        {
          operand2 = calc.pop();
          operand1 = calc.pop();
          operand1 %= operand2;
          calc.push(operand1);
        }
        else if (next[0] == '+')
        {
          operand2 = calc.pop();
          operand1 = calc.pop();
          operand1 += operand2;
          calc.push(operand1);
        }
        else if (next[0] == '-')
        {
          if (calc.size() > 1)
          {
            operand2 = calc.pop();
            operand1 = calc.pop();
            operand1 -= operand2;
            calc.push(operand1);
          }
          else
            negative = true;
        }

      }
    }
    if (negative)
      return calc.pop() * -1;
    else
      return calc.pop();
  }
}

bool Calculator::validFormat(std::string infix, std::string &error)
{
	error = "Errors:\n";
	char prev = ' ';
	char prevPrev = ' ';
	Stack<char> p;
	std::string invalidSymbol = "";
	for (int x = 0; x < infix.size(); x++)
	{
		if (infix[x] != ' ')
		{
			if (validChar(infix[x]))
			{
				if (x == 0)
				{
					if (!isdigit(infix[x]) && infix[x] != '(' && infix[x] != '-')
					{
						error += "Started with unexpected value: '";
						error += infix[x];
						error += "'.\n";
					}
				}
				else if (isdigit(infix[x]) && isdigit(prev))
				{
					error += "Unexpected '";
					error += infix[x];
					error += "' after '";
					error += infix[x];
					error += "', expected operator.\n";
				}
				else if (prev == '-' && prevPrev == prev && infix[x] == '-')
				{
						error += "Unexpected '";
						error += infix[x];
						error += "' after '";
						error += infix[x];
						error += "'.\n";
				}
				else if (prev == '*' || prev == '/' || prev == '%' || prev == '+' 
					|| prev == '^' || prev == '(' || prev == ')' || prev == '-')
				{
					if (prev == '(')
					{
						if (infix[x] != '(' && !isdigit(infix[x]) && infix[x] != '-')
						{
							error += "Unexpected '";
							error += infix[x];
							error += "' after '";
							error += prev;
							error += "'.\n";
						}
					}
					else if (prev == ')')
					{
						if (isdigit(infix[x]) || infix[x] == '(')
						{
							error += "Unexpected '";
							error += infix[x];
							error += "' after '";
							error += prev;
							error += "'.\n";
						}
					}
					else if (prev == '-')
					{
						if (infix[x] != '(' && !isdigit(infix[x]))
						{
							error += "Unexpected '";
							error += infix[x];
							error += "' after '";
							error += prev;
							error += "'.\n";
						}
					}
					else
					{
						if (infix[x] == '+' || infix[x] == '*' || infix[x] == '/'
							|| infix[x] == '%' || infix[x] == '^' || infix[x] == ')')
						{
							error += "Unexpected '";
							error += infix[x];
							error += "' after '";
							error += prev;
							error += "'.\n";
						}
					}
				}

				if (infix[x] == ')' && prev != ' ')
				{
					if (p.empty())
					{
						error += "Unmatched ')' after '";
						error += prev;
						error += "'.\n";
					}
					else
						p.pop();
				}
				else if (infix[x] == '(')
				{
					p.push(infix[x]);
				}
				
				prevPrev = prev;
				prev = infix[x];
			}
			else
			{
				error += "Invalid Symbol: '";
				error += infix[x];
				error += "' after '";
				error += prev;
				error += "'.\n";
			}
		}
	}
	
	if (!p.empty())
	{
		error += "Unmatched '(' in expression, expected ')'\n";
	}

	if (error != "Errors:\n")
		return false;
	else
		return true;
}
