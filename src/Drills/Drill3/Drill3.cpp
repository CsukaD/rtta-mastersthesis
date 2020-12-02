#include "std_lib_facilities.h"
int main ()
{
	string your_name=""; 
	cout << "Enter your name" << endl;
	cin >> your_name;
	string first_name="";
	cout << "Enter the name of the person you want to write: ";
cin >> first_name;
cout << "Dear " << first_name << "." << endl;
cout << "How are you ?" << endl;
string friend_name="";
cout << "Enter the name of your friend: ";
cin >> friend_name;
cout << "Have you seen " << friend_name << " lately ?" << endl;
char friend_sex=' ';
cout << "Enter her/his sex(f/m): ";
cin >> friend_sex;
if(friend_sex=='m')
{
cout << "If you see " << friend_name << " please ask her to call me!" << endl;
}
else
{
	if(friend_sex=='f')
	cout << "If you see " << friend_name << " please ask him to call me!" << endl;
}
int age =0;
cout << "Age: ";
cin >> age;
if (age <=0 || age >=110)
error("You're kidding");
else
cout << "I hear you just had a birthday and you are " << age << " years old" << endl;
if(age < 12)
cout << "Next year you will be " << age+1 << endl;
if(age == 17)
cout << "Next year you will be able to vote." << endl;
if(age > 70)
cout << "I hope you are enjoying retirement." << endl;
cout << "Yours sincerely" << endl << endl;
cout << your_name  << endl;
	return 0;
}