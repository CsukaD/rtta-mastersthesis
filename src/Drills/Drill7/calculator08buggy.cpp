#include "std_lib_facilities.h"

double expression();

constexpr char number = '8';
constexpr char quit = 'q';
constexpr char print = ';';
constexpr char result = '=';
constexpr char let = '#';
constexpr char name = 'a';
const string declkey = "let";
constexpr char square_root = '@';
const string sqrtkey = "sqrt";
constexpr char pow_root='$';
const string powkey="pow";
const string exitkey ="exit";

class Variable {
public:
	string name;
	double value;
};

vector<Variable> var_table;

bool is_declared(string var)
{
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == var) 
		{
			return true;
		}
	return false;
}

double define_name(string var, double val)
{
	if (is_declared(var))
	{ 
		error("Variable is declared", var);
	}
	var_table.push_back(Variable{var,val});
	return val;
}

double get_value(string s) {
	for (const auto& v : var_table)
		if (v.name == s) return v.value;
	error("get: undefined name ");
}

void set_value(string s, double d)
{
	for (int i = 0; i <= var_table.size(); ++i)
	{
		if (var_table[i].name == s) 
		{
			var_table[i].value = d;
			return;
		}
	}
	error("set: undefined name ", s);
}


class Token
{
public:
	char kind;
	double value;
	string name;
	Token(): kind(0) {}
	Token (char ch): kind(ch), value(0) {}
	Token (char ch, double val): kind(ch), value(val) {}
	Token (char ch, string n): kind(ch), name(n) {}
};

class Token_stream
{
public:
	Token_stream();
	Token get();
	void putback(Token t);
	void ignore(char c);
private:
	bool full;
	Token buffer;
};

Token_stream::Token_stream(): full(false), buffer(0) {}

Token_stream ts; 

void Token_stream::putback(Token t)
{
if (full) error("Token_stream buffer full");
buffer = t;
full = true;
}

Token Token_stream::get()
{
	if (full)
	{
		full = false;
		return buffer;
	}
	char ch;
	cin >> ch;
	switch(ch)
	{
		case quit:
		case print:
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '=':
		case ',':
		return Token(ch);
		case '.':
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		{
			cin.putback(ch);
			double val;
			cin >> val;
			return Token(number,val);
		}
		default:
		if (isalpha(ch)) 
		{
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
			cin.putback(ch);
			if (s == declkey) return Token(let);
			else if (s == sqrtkey) return Token(square_root);
			else if (s == powkey) return Token(pow_root);
			else if (s == exitkey) return Token(quit);
			else if (is_declared(s))
				return Token(number, get_value(s));
			return Token(name, s);
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c)
{
	if (full && c ==buffer.kind)
	{
		full=false;
		return;
	}
	full=false;
	char ch =0;
	while (cin>>ch)
		if (ch==c) return;
}
double calc_sqrt()
{
	char ch;
	if (cin.get(ch) && ch != '(') error("'('expected");
	cin.putback(ch);
	double d =expression();
	if (d<0) error("sqrt: negative value");
		return sqrt(d);
}
double calc_pow()
{
			Token t=ts.get();
	        if (t.kind != '(') error("'(' expected");
	        double d=expression();
	        t=ts.get();
	        if (t.kind!=',') error("',' expected");
	        double i=expression();
	        t=ts.get();
	        if (t.kind != ')') error("')' expected");
	        return pow(d,i);

}

double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error(" ) expected"); //3.
            return d;
    }
    case number:            // we use '8' to represent a number
        return t.value;  // return the number's value
        case '-':
        return - primary();
        case '+':
        return primary();
        case square_root:
        return calc_sqrt();
       	case pow_root:
        return calc_pow();
    default:
        error("primary expected");
        return 0;
    }
}

double term()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;  //7.
        case '/':
        {
            double d = primary();
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        case '%':
        {
        	double d =primary();
        	if (d==0) error("%: zero dividor");
        	left = fmod(left,d);
        	t =ts.get();
        	break;
        }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

double expression()
{
    //5.?
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
        //6.
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

void clean_up_mess()
{
	ts.ignore(print);
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration");
	string var_name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	define_name(var_name, d);
	return d;
}
double statement()
{
	Token t = ts.get();
	switch(t.kind)
	{
		case let:
		return declaration();
		default:
		ts.putback(t);
		return expression();
	}
}
void calculate()
{
	while (cin) 
	try {
	Token t = ts.get();
	while (t.kind == print) t = ts.get();
	if (t.kind == quit) 	return;
	ts.putback(t);
	cout << result << statement() << endl;
	}catch (exception& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()
try{
	define_name("k",1000);
	define_name("e",2.71828);
	define_name("pi",3.14159);
	calculate();
	return 0;
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    return 2;
}