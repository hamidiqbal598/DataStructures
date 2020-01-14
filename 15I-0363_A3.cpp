//----------------------------------
//Name: Hamid Iqbal & Talha Shafique
//Roll NO: i15-0363 & f15-8103
//Section: A (DS-Summer)
// Assignment-3
//----------------------------------

#include<iostream>
#include<stack>
#include<string>
const int Size = 50;
using namespace std;
bool check_operand(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return true;
	}
	else
	{
		return false;
	}

}
bool check_operator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '$' || c == '^')
	{
		return true;
	}
	else
	{
		return false;
	}
}
int operator_precedence(char c)
{
	int temp;
	if (c == '+' || c == '-')
	{
		temp = 1;
	}
	else if (c == '*' || c == '/')
	{
		temp = 2;
	}
	else if (c == '$' || c == '^')
	{
		temp = 3;
	}
	else
	{
		temp = 0;
	}
	return temp;
}
string last(string c)
{
	string temp = c;
	int k = c.length();
	for (int i = k - 2; i >= 0; i--)
	{
		if (check_operand(c[i]))
		{
			temp[i + 1] = ' ';
			for (int j = i + 2; j < c.length(); j++)
			{
				temp[j] = c[j - 1];
			}
			i = -1;
		}
	}
	return temp;
}
int check_precedence(char c1, char c2)
{
	int c1_W = operator_precedence(c1);
	int c2_W = operator_precedence(c2);
	if (c1_W >= c2_W)
	{
		return true;
	}
	else
	{
		return false;
	}
}
string infix_postfix(string expression)
{
	stack<char> S;
	string postfix = "";
	for (int i = 0; i< expression.length(); i++)
	{
		if (expression[i] == ' ' || expression[i] == ',')
		{
			//no problem
		} 
		else if (check_operator(expression[i]))
		{
			postfix += " ";
			while (!S.empty() && S.top() != '(' && check_precedence(S.top(), expression[i]))
			{
				postfix += S.top();
				postfix += " ";
				S.pop();
			}
			S.push(expression[i]);
		}
		else if (check_operand(expression[i]))
		{
			postfix += expression[i];
		}
		else if (expression[i] == '(')
		{
			S.push(expression[i]);
		}
		else if (expression[i] == ')')
		{
			while (!S.empty() && S.top() != '(') {
				postfix += S.top();
				postfix += " ";
				S.pop();
			}
			S.pop();
		}
	}
	while (!S.empty()) 
	{
		postfix += S.top();
		postfix += " ";
		S.pop();
	}
	int k = postfix.length();
	char t = postfix[k - 2];
	postfix[k - 2] = ' ';
	postfix[k - 1] = t;
	return postfix;
}
int expression(string result)
{
	int k = 0;
	stack<int> array;
	string convert = result;
	string con;
	int *ar, res, num;
	string temp;
	int len = result.length();
	for (int j = 0; j < len; j++)
	{
		if (result[j] != '+' && result[j] != '-' && result[j] != '*' && result[j] != '/' && result[j] != '^' && result[j] != ' ')
		{
			while (result[j] != '+' && result[j] != '-' && result[j] != '*' && result[j] != '/' && result[j] != '^' && result[j] != ' ')
			{
				con += result[j];
				j++;
			}
			if (con != "+" && con != "-" && con != "*" && con != "/" && con != "^" && con != "%" && con != " ")
			{
				num = atoi(con.c_str());
				array.push(num);
				//push_in(num);
				con = " ";
			}
		}
		else
		{
			res = array.top();
			array.pop();
			//res = pop_out();
			if (result[j] == '+')
			{
				res = (array.top()) + res;
				//push_in(res);
			}
			else if (result[j] == '-')
			{
				res = (array.top()) - res;
			}
			else if (result[j] == '*')
			{
				res = (array.top()) * res;
			}
			else if (result[j] == '/')
			{
				res = (array.top()) / res;
			}
			else if (result[j] == '^')
			{
				res = (array.top()) ^ res;
			}
			array.pop();
			array.push(res);
			j++;
		}
	}
		res = array.top();
		array.pop();
		//res = pop_out();
		return res;
}
class infix
{
protected:
	char target[Size], stack[Size];
	string s;
	char  *t;
	int top, l;
public:
	infix()
	{
		top = -1;
		strcpy_s(target, "");
		strcpy_s(stack, "");
		l = 0;
	}
	void set(string str);
	void push(char c);
	char pop();
	string convert();
};
void infix::set(string str)
{
	s = str;
	reverse(s.begin(), s.end());
	l = s.length();
	*(target + l) = '\0';
	t = target + (l - 1);
}
void infix::push(char c)
{
	if (top == Size - 1)
		cout << "\nStack is full\n";
	else
	{
		top++;
		stack[top] = c;
	}
}
char infix::pop()
{
	if (top == -1)
	{
		cout << "Stack is empty\n";
		return -1;
	}
	else
	{
		char item = stack[top];
		top--;
		return item;
	}
}
string infix::convert()
{
	int len = s.length();
	char operand;
	int i = 0;
	while (i<len)
	{
		if (s[i] == ' ' || s[i] == '\t')
		{
			//no problem
		}
		if (check_operand(s[i]))
		{
			while (isdigit(s[i]) || isalpha(s[i]))
			{
				*t = s[i];
				i++;
				t--;
			}
		}
		if (s[i] == ')')
		{
			push(s[i]);
			i++;
		}
		if (check_operator(s[i]))
		{
			if (top != -1)
			{
				operand = pop();
				while (operator_precedence(operand) > operator_precedence(s[i]))
				{
					*t = operand;
					t--;
					operand = pop();
				}
				push(operand);
				push(s[i]);
			}
			else
				push(s[i]);
			i++;
		}

		if (s[i] == '(')
		{
			operand = pop();
			while ((operand) != ')')
			{
				*t = operand;
				t--;
				operand = pop();
			}
			i++;
		}
	}

	while (top != -1)
	{
		operand = pop();
		*t = operand;
		t--;
	}
	t++;
	string temp=" ";
	while (*t)
	{
		temp += *t;
		t++;
	}
	return temp;
}
int main()
{
	int a;
	cout << "1) Enter In-fix Expression For Post-Fix Conversion : "<<endl;
	cout << "2) Enter In-fix Expression For Pre-Fix Conversion : "<<endl;
	do
	{
		cout << "Enter : ";
		cin >> a;
		cin.ignore();
	} while (a != 1 && a != 2);
	string str,convert;
	int Answer=0;
	if (a == 1)
	{
		cout << "Enter Required Equation : ";
		getline(cin, str);
		str += ' ';
		str=last(str);
		convert = infix_postfix(str);
		cout << "----------In-Fix  to  Post-Fix-----------" << endl;
		cout << "a) The input equation : " << str << endl;
		cout << "b) Converted expression : " << convert << endl;
		Answer = expression(convert);
		cout << "c) Answer to the equation : " << Answer << endl;
	}
	else
	{
		infix Con;
		cout << "Enter Required Equation : ";
		getline(cin, str);

		Con.set(str);
		convert = Con.convert();
		cout << "----------In-Fix  to  Pre-Fix-----------" << endl;
		cout << "a) The input equation : " << str << endl;
		cout << "b) Converted expression : "<< convert << endl;
		//Answer = expression(convert);
		cout << "c) Answer to the equation : " << Answer << endl;
	}
	system("pause>NULL");
}
