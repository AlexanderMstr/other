#include<iostream>
#include<string>
using namespace std;

class Student
{
public:
	Student(const char* pN = "no name") :sName(pN)
	{
		noOfStudents++;
	}
	~Student() 
	{ noOfStudents--;
	}
	const string& name()
	{
		return sName;
	}
	static int number()
	{
		return noOfStudents;
	}
protected:
	string sName;
	static int noOfStudents;
};
int Student::noOfStudents = 0;
int main()
{
	setlocale(LC_ALL, "RU");
	Student s1("Chexter");
	Student* pS2 = new Student("Scooter");
	cout << "������� ��������: " << s1.name() << " � " << pS2->name() << endl;
	cout << "����������� ��������� ����� " << s1.number() << endl;
	//������ 1 ������� � ������� ��� ���:
	cout << "�������� " << pS2->name() << endl;
	delete pS2;
	cout << "����������� ��������� ����� " << Student::number() << endl;
	cout << "������� �������: " << s1.name() << endl;
	

	return 0;
	system("pause");
}