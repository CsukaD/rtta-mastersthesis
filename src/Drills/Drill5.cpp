#include "std_lib_facilities.h"
int main ()
try{
	cout << "1. ";
	cout << "Success!\n"; 			//Cout << "Success!\n";
	//////////////////////////////////////////////////////////////
	cout << "2. ";
	cout << "Success!\n"; 			//cout << "Success!\n;
	//////////////////////////////////////////////////////////////
	cout << "3. ";
	cout << "Success" << "!\n"; 	//cout <<" Success"<< !\n"
	//////////////////////////////////////////////////////////////
	cout << "4. ";
	cout << "Success!"<< endl; 		//cout <<success<< endl;
	//////////////////////////////////////////////////////////////
	cout << "5. ";
	int res = 7;  					//string res= 7;
	vector<int> v(10); 				//vector<int> v(10);
	v[5] = res; 					//v[5]=res;
	cout << "Success!\n";  			//cout << "Success!\n";
	//////////////////////////////////////////////////////////////
	cout << "6. ";
	vector<int>v6(10);				//vector<int>v(10);
	v6[5]=7;						//v(5)=7;
	if(v6[5]==7)					//if (v(5)!=7)
	cout << "Success!\n";			//cout<<"Success!\n";
	//////////////////////////////////////////////////////////////
	cout << "7. ";
	if(true)						//if (cond)
	cout << "Success!\n";			//cout << "Success!\n";
	else							//else
	cout << "Fail!\n";				//cout << "Fail!\n";
	//////////////////////////////////////////////////////////////
	cout << "8. ";
	bool c = false;					//bool c = false;
	if(c==false)					//if (c)
	cout << "Success!\n";			//cout << "Success!\n";
	else							//else
	cout << "Fail!\n";				//cout << "Fail!\n";
	//////////////////////////////////////////////////////////////
	cout << "9. ";
	string s = "ape";				//string s="ape";
	bool c9 = false;				//boo c="fool"<s;
	if (c9 == false)				//if(c)
	cout << "Success!\n";			//cout << "Success!\n";
	//////////////////////////////////////////////////////////////
	cout << "10. ";				
	string s10="ape";				//string s="ape";
	if(s10=="ape")					//if(s=="fool")
	cout << "Success!\n";			//cout << "Success!\n";
	//////////////////////////////////////////////////////////////
	cout << "11. ";
	string s11 = "ape";				//string s="ape";
	if(s11=="ape")					//if(s=="fool")
	cout <<"Success!\n";			//cout < "Success!\n";
	//////////////////////////////////////////////////////////////
	cout << "12. ";
	string s12="ape";				//string s="ape";
	if(s12=="ape")					//if(s+"fool")
	cout <<"Success!\n";			//cout < "Success!\n";
	//////////////////////////////////////////////////////////////
	cout << "13. ";
	vector<char> v13(5);			//vector<char>v(5);
	for(int i=0;i<v13.size();++i)	//for(int i=0; 0<=v.size();++i)
	cout << " Success!\n";			//cout << "Success!\n";
	//////////////////////////////////////////////////////////////
	cout << "14. ";
	vector<char> v14(5);			//vector<char>v(5);
	for(int i=0;i<=v14.size();++i)	//for(int i=0;i<=v.size();++i)
	cout << " Success!\n";			//cout << "Success!\n";
	//////////////////////////////////////////////////////////////
	cout <<"15. ";
	string s15 ="Success!\n";		//string s ="Success!\n";
	for (int i=0;i<8;++i)			//for(int i=0;i<6;++i)
	cout << s15[i];
	cout << endl;					//cout << s[i];
	//////////////////////////////////////////////////////////////
	cout <<"16. ";
	if (true)						//if (true)
	cout << "Success!\n";			//then
	else							//cout << "Success!\n";
	cout << "Success!\n";			//else
									//cout << "Fail!\n";
	//////////////////////////////////////////////////////////////
	cout <<"17. ";
	int x=2000;						//int x=2000;
	int c17=x;						//char c=x;
	if (c17==2000)					//if(c==2000)
	cout << "Success!\n";			//cout << "Success!\n";
	///////s///////////////////////////////////////////////////////
	cout <<"18. ";
	string s18 = "Success!\n";		//string s = "Success!\n";
	for (int i=0;i<10;++i)			//for (int i=0;i<10;++i)
	cout << s18[i];					//cout << s[i];
	//////////////////////////////////////////////////////////////
	cout <<"19. ";
	vector<int> v19(5);				//vector v(5);
	for (int i=0;i<=v19.size();++i)	//for (int i=0;i<=v.size();++i)
	cout << " Success!\n";			//cout << "Success!\n";
	//////////////////////////////////////////////////////////////
	cout <<"20. ";
	int i=0;						//int i=0;
	int j=9;						//int j=9;
	while (i<10)					//while (i<10)
	++i;							//++j;
	if(j<i)							//if(j<i)
	cout<< "Success!\n";			//cout << "Success!\n";
	//////////////////////////////////////////////////////////////
	cout <<"21. ";
	double x21=4;						//int x=2;
	double d=5/(x21-2);				//double d=5/(x-2);
	if(d==x21/2+0.5)				//if(d==2*x+0.5)
	cout << "Success!\n";			//cout << "Success!\n";
	//////////////////////////////////////////////////////////////
	cout <<"22. ";
	string s22="Success!\n";		//string<char> s="Success!\n";
	for (int i=0;i<=9	;++i)			//for (int i=0;i<=10;++i)
	cout << s22[i];					//cout << s[i];
	//////////////////////////////////////////////////////////////
	cout <<"23. ";
	int i23=0;						//int i=0;
	int j23=0;						//while(i<10)
	while(i23<10)					//++j;
	++i23;							//if(j<i)
	if(j23<i)						//cout << "Success!\n";
	cout <<	"Success!\n";
	//////////////////////////////////////////////////////////////
	cout <<"24. ";	
	double x24=4;						//int x=4;
	double d24=5/(x-2);				//double d=5/(x-2);
	if(d24=x24/2+0.5)					//if(d==2*x+0.5)
	cout <<"Success!\n";			//cout <<"Success!\n";
	//////////////////////////////////////////////////////////////
	cout <<"25. ";
	cout <<"Success!\n";			//cin <<"Success!\n";
	//////////////////////////////////////////////////////////////
	keep_window_open();
	return 0;
}
catch(exception& e) {
	cerr << "error: " << e.what()<<'\n';
	keep_window_open();
	return 1;
}
catch(...) {
	cerr << "Oops: unknown exception!\n";
	keep_window_open();
	return 2;
}