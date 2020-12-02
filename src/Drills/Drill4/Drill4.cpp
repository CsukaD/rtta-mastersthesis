#include "std_lib_facilities.h"
int main()
{
	double values=0;
	double valuesinmeter=0;
	double large=0;
	double small=0;
	int numberofvalues=0;
	double sumofvalues=0;
	int invalidnumbers=0;
	vector <double> allvalues;
	char unit=' ';
	constexpr double metercm = 0.01;
	constexpr double meterin = 0.03;
	constexpr double meterft = 0.3;
cout << "Choose a staring number: ";
cin >> values;
	large=values;
	small=values;
	cout << "Pick a number and a unit (c,m,i,f) :" << endl;
while(cin >> values >> unit)
	{
		//if(i==o)
	//{
		//cout << "The numbers are equal" << endl;
	//}
	//else
	//{
		//if(i<o)
		//{
		//cout << "The smaller value is: " << i << endl;
		//cout << "The larger value is: " << o << endl;
		//if(o-i< 1)
		//{
		//cout << "The numbers are almost equal" << endl;
		//}
	//}
	//else
	//{
		//cout << "The smaller value is: " << o << endl;
		//cout << "The larger value is: " << i << endl;
		//if(i-o< 1)
		///{
		//cout << "The numbers are almost equal" << endl;
		//}
//}
//	}
	if(values<small)
{
	small = values;
	cout << "The smallest so far" << endl;
} 
	if(values>large)
{
	large = values;
	cout << "The largest so far" << endl;
}
switch (unit) {
	case 'c':
	valuesinmeter=values*metercm;
	cout << values << "cm == "<< valuesinmeter << " m" << endl ;
	numberofvalues++;
	allvalues.push_back(valuesinmeter);
	break;
	case 'm':
	valuesinmeter=values;
	cout << values <<"m == "<< valuesinmeter << " m" << endl ;
	numberofvalues++;
	allvalues.push_back(valuesinmeter);
	break;
	case 'i':
	valuesinmeter=values*meterin;
	cout << values <<"inc == "<< valuesinmeter << " m" << endl ;
	numberofvalues++;
	allvalues.push_back(valuesinmeter);
	break;
	case 'f':
	valuesinmeter=values*meterft;
	cout << values <<"feet == "<< valuesinmeter << " m" << endl ;
	numberofvalues++;
	allvalues.push_back(valuesinmeter);
	break;
	default:
	cout << "Invalid unit" << endl;
	invalidnumbers++;
	break;
}
}
for (int i=0;i<allvalues.size();i++)
{
	sumofvalues+=allvalues[i];
}
cout << "Smallest number: " << small << endl;
cout << "Largest number: " << large << endl;
cout << "Number of values: " << numberofvalues << endl;
cout << "The sum of value in meter: " << sumofvalues << " meter" << endl;
cout << "Number of invalid numbers: " <<invalidnumbers << endl;
keep_window_open("|");	
	return 0;
}