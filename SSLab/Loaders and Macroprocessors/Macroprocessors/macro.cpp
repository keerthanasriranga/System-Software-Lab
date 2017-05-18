#include<iostream>
#include<fstream>
#include<string>
#include<map>
using namespace std;
int main()
{
string name,x0,x1,x2;
map<string,string> m = {{"SUM","SUM"},{"DIFF","DIFF"}};
ifstream input1("input.dat");
ofstream out1("output.dat");
input1>>x0>>x1>>x2;
while(x1!="END")
{
	if(x1=="START")
	{
		out1<<x0<<" "<<x1<<" "<<x2<<endl;
	}
	else if(x1=="MACRO")
	{
		name = x0;
		ofstream out2(name+".dat");
		input1>>x0>>x1>>x2;
		while(x1!="MEND")
		{
			out2<<x0<<" "<<x1<<" "<<x2<<endl;
			input1>>x0>>x1>>x2;
		}
	out2<<"**"<<" "<<"**"<<" "<<"**"<<endl;
	}
	else if(x1==m[x1])
	{
		name = x1;
		if(x0!="**")
		out1<<x0<<" ";
		ifstream input2(name+".dat");
		input2>>x0>>x1>>x2;
		while(x1!="**")
		{
			out1<<x0<<" "<<x1<<" "<<x2<<endl;
			input2>>x0>>x1>>x2;
		}
	}
	else
	{
	out1<<x0<<" "<<x1<<" "<<x2<<endl;
	}
	input1>>x0>>x1>>x2;
}
out1<<x0<<" "<<x1<<" "<<x2<<endl;
}
		
		
