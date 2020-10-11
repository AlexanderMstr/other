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
	cout << "Созданы студенты: " << s1.name() << " и " << pS2->name() << endl;
	cout << "Колличество студентов равно " << s1.number() << endl;
	//Уберем 1 студент и спросим еще раз:
	cout << "Удаление " << pS2->name() << endl;
	delete pS2;
	cout << "Колличество студентов равно " << Student::number() << endl;
	cout << "Остался студент: " << s1.name() << endl;
	

	return 0;
	system("pause");
}