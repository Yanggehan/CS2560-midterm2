#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

class Human
{
private:
	string name;
	int age;
	char sex;
	Human();
	
protected:
	Human(string n, int a, char s) {
		age = a;
		sex = s;
		name = n;
	}
	/*virtual ~Human()

	{

		cout << "Destructing derived \n";

	}*/
public:
	//void printInfo(Human h);
	void setname(string n) { name = n; }
	void setage( int a) { age = a; }
	void setsex(char s) { sex = s; }
	
	const string getname() const {
		return name;
	}
	int getage() { return age; }
	char getsex() { return sex; }
};
class Child : public Human
{
private:
	friend class Parent;
	string momName;
	string dadName;
	int allowance;
	Child():Human("name", 10, 'f')
	{
	
	}
public:
	Child(string name1, int age1, char sex1,string momName1,string dadName1) :Human(name1, age1, sex1){
	
		allowance = 0;
		momName = momName1;
		dadName = dadName1;
	}
	void setAllowance(int a) {
		allowance = a;
	}
	/*int getAllowance2() const {
		return allowance+5;
	};*/
	int getAllowance() const {
		return allowance;
	};
	void printParent()
	{ 
		
		cout << "mom name :" << momName << endl;
	cout << "dad name :" << dadName << endl;
	}
};
class parent : public Human
{
private:

	string name;
	int age;
	char sex;
	vector<Child> children;
	parent() :Human("name", 10, 'f')
	{

	}
 public:
	parent(string name1, int age1, char sex1) :Human(name1, age1, sex1) {
		name = name1;
		age = age1;
		sex = sex1;
	}
	void printChild() {
		for (unsigned i = 0; i < children.size(); ++i)
			std::cout << children[i].getname() << ",";
		std::cout << "\n";
	}
	void setChild(Child c) {
		children.push_back(c);
	}

	void setChildAllowance(int a, Child &c) {
		c.setAllowance(a);
	};
	void printInfo(Human h) {
		std::cout << "Name" << h.getname() << "\n";
		std::cout << "Age" << h.getage() << "\n";
		std::cout << "Sex" << h.getsex() << "\n";
	}
};
void printInfo(Human h) {
	std::cout << "Name: " << h.getname() << " Age: " << h.getage() << " Sex: " << h.getsex() << "\n" << std::endl;
}

int main() {
	
		parent Homer("Homer", 36, 'M');
		parent March("March", 34, 'F');
		Child Lisa("Lisa", 12, 'F', "Homer", "March");
		Child Bart("Bart", 10, 'M', "Homer", "March");
		Child Maggie("Maggie", 3, 'F', "Homer", "March");
		Homer.setChild(Lisa);
		Homer.setChild(Bart);
		Homer.setChild(Maggie);
		March.setChild(Lisa);
		March.setChild(Bart);
		March.setChild(Maggie);
		cout << "Bart's allowance: " << Bart.getAllowance() <<endl;
		Homer.setChildAllowance(5, Bart);
		cout << "Bart's allowance: " << Bart.getAllowance() << endl;
		Bart.printParent();
		printInfo(March);
		printInfo(Lisa);
		system("pause");
		return 0;
	}

