#include <iostream>
using namespace std;
class Person
{
protected:
    int id;
public:
    Person(int i):id(i){
        cout <<"construct a Person" <<endl;
    }
   virtual void print(){cout << "person::id"<<id <<endl;}//�麯��
    ~Person(){cout <<"destruct a Person" <<endl;}
};
class Student: public Person
{
protected:
    int id; //ѧ��
public:
    Student(int p_i,int s_i):Person(p_i){//Assistant��Person�ѵ���
        id = s_i;
        cout <<"construct a Student" <<endl;
    }
    void print(){
        Person::print();
        cout << "student::id"<<id <<endl;}
    ~Student(){cout <<"destruct a Student" <<endl;}
};
class Teacher: public Person
{
protected:
    int id;//ְ����
public:
    Teacher(int p_i,int t_i ):Person(p_i){
        id = t_i;
        cout <<"construct a Teacher" <<endl;
    }
    void print(){
        Person::print();
        cout << "teacher::id"<<id <<endl;}
    ~Teacher(){cout <<"destruct a Teacher" <<endl;}
};

void test(Person &ref)
{
	ref.print();//�ͺ��,�������;���ִ�о����print();
}

int main()
{
	//Student s(1,101);
	//test(s);
	Person* p;
	int choice;
	cin>>choice;
	if(choice==1)
		p=new Person(1);
	else if(choice==2)
		p=new Student(2,29);
	else 
		p=new Teacher(1,22222);
	p->print();//��̬��̬
}

