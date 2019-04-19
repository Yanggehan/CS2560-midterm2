#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
//void printInfo(Human);
class Human
{
private:
	string name;
	int age;
	char sex;
	/*Human() 
	{
		name = "name1";
		age = 0;
		sex = 'M';
	};*/
protected:
	Human() {
		name = "name1";
		age = 0;
		sex = 'M';
	};
	Human(string name1, int age1, char sex1) {
		name = name1;
		age = age1;
		sex = sex1;
	};
	virtual ~Human()

	{

		cout << "Destructing derived \n";

	}
public:
	void setname(string name1) { name = name1; }
	void setage( int age1) { age = age1; }
	void setsex(char sex1) { sex = sex1; }
	
	string getname() { return name ; }
	int getage() { return age; }
	char getsex() { return sex; }
};
class Child : public Human
{
private:
	string momName;
	string dadName;
	int allowance=0;
	Child()
	{
		momName = "";
		dadName = "";
		allowance = 0;
	}
public:
	Child(string name1, int age1, char sex1,string momName1,string dadName1) {
	
		momName = momName1;
		dadName = dadName1;
		
	}
	int getAllowance2() const {
		return allowance+5;
	};
	int getAllowance() const {
		return allowance;
	};
	void printParent()
	{ 
		
		cout << "mom name :" << momName << endl;
	cout << "dad name :" << dadName << endl;
	}
};
class parent : private Human
{
private:
	string name;
	int age;
	char sex;
	vector<string> children;
	parent()
	{
	};
public: 
	parent(string name1, int age1, char sex1) {
		name = name1;
		age = age1;
		sex = sex1;
	}
	void printChild() {};
};
int main(){
	string name;
	int age,momage,fatherage;
	char sex,momsex,fathersex;
	string momName;
	string dadName;
	int allowance;
	/*	cout << "enter children name:";
		cin >> name;
		cout << "enter age:";
		cin >> age;
		cout << "enter sex:";
		cin >> sex;
		cout << "enter mom Name:";
		cin >> momName;
		cout << "enter mom age:";
		cin >> momage;
		cout << "enter mom sex:";
		cin >> momsex;
		cout << "enter dad Name:";
		cin >> dadName;
		cout << "enter father age:";
		cin >> fatherage;
		cout << "enter father sex:";
		cin >> fathersex;*/
		parent parent1("Homer", 36, 'M');
		parent parent2("March", 34, 'F');
		Child child("Lisa", 12, 'F', "Homer", "March");
		Child child2("Bart", 10, 'M', "Homer", "March");
		Child child3("Maggie", 3, 'F', "Homer", "March");
		cout << " Bart¡¯s allowance"<< child.getAllowance() << endl;
		cout << " Bart¡¯s allowance" << child.getAllowance2() << endl;
		child.printParent();
		child2.printParent();
		child3.printParent();
		system("pause");
		return 0;
}
/*void printInfo(Human human1) {
	
	
	cout <<  human1.getage() << endl;
	cout << human1.getname() << endl;
	cout << human1.getsex() << endl;

}*/