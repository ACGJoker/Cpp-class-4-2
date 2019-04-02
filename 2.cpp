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
   void print(){cout << "person::id"<<id <<endl;}
    ~Person(){cout <<"destruct a Person" <<endl;}
};
class Student:virtual public Person
{
protected:
    int id; //Ñ§ºÅ
public:
    Student(int p_i,int s_i):Person(p_i){
        id = s_i;
        cout <<"construct a Student" <<endl;
    }
    void print(){
        Person::print();
        cout << "student::id"<<id <<endl;}
    ~Student(){cout <<"destruct a Student" <<endl;}
};
class Teacher:virtual public Person
{
protected:
    int id;//Ö°¹¤ºÅ
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
class Assistant:public Student,public Teacher
{
protected:
    int salary;
public:
    Assistant(int p_i,int s_i, int t_i,int s)
    :Student(p_i,s_i),Teacher(p_i,t_i),Person(p_i)//
    {
        salary = s;
        cout <<"construct an Assistant" <<endl;
    }
    ~Assistant(){cout <<"destruct an Assistant" <<endl;}
    void print()
    {
        cout << Person::id << ' '
             << Student::id <<' '
             <<Teacher::id <<' '
             <<salary<<endl;
    }
};
int main()
{
	Assistant as(1,2,3,1000);
	as.print();
}

