#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


using namespace std;

int main () {

	std::vector<string> c (33);
	std::vector<std::string> a;
	int i=0;
	std::string line;
	ifstream f;
	f.open("mapfile.txt");
	if(f.is_open())
	{
		while(getline(f, line))
		{
			c[i]= line;
			std::stringstream s(c[i]);
			while(getline(s, line, ','))
			{
				a.push_back(line);
				cout << a[i]<<'\n';
			}
			i++;
		}
		f.close();
	}
	else
		std::cout<<"File not open"<< '\n';
}
