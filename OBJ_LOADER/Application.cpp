#include <iostream>
#include <string>
#include <exception>


#include <fstream>
#include <sstream>


using namespace std;





struct Person
{
	string name;
	int age;

	virtual void Print() {}
};


struct Male : public  Person
{
	bool sex{ true };
	//Male() : Person() {}
};

struct Female : public Person
{
	bool sex{ false };
	//Female() : Person() {}
};

int main(int argc, char** argv)
{
	system("pause");
	return 0;
}
