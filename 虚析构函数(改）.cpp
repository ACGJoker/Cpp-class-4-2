#include <iostream>
#include <cstring>
using namespace std;
class TwoDShape //�����࣬��һ���������麯��

{
private:
    char name[20];
public:
    TwoDShape(char* s){//���첻�����麯��
        strcpy(name,s);
        cout <<"construct a TwoDShape"<<endl;
    }
   virtual void draw(){cout<<name <<endl;}
//����������
    virtual ~TwoDShape(){
        cout <<"destruct a TwoDShape" <<endl;
    }

	virtual void getArea()=0;//���麯�����޺����壬��������ʵ��
};

class Rectangle:public TwoDShape //���л��ി�麯��δ��д��������Ϊ������
{
private:
    float x,y;
public:
    Rectangle(char* s,float x,float y)
    :TwoDShape(s){
        this->x = x;this->y = y;
        cout <<"construct a Rectangle"<<endl;
    }
    void draw(){
        TwoDShape::draw();
        cout << "length is " <<x << ' '
        <<"width is "<< y <<endl;
    }
    ~Rectangle(){
        cout <<"destruct a Rectangle" <<endl;
    }
	void getArea(){
		cout<<"Area is "<<x*y<<endl;
	}
};

//void test(TwoDShape tds)  ������
//TwoDShape f() ������

int main()
{
    TwoDShape*p;//��ָ���κ����������

    p = new Rectangle("rect",2,8);
	Rectangle re("rect",5,8);
	TwoDShape & t(re);
	p->getArea();

    delete p;
	//������ʹ��ʱ��
	//1 ���ܶ�����������  TwoDShape obj��...��
	//2 ���Զ��������ָ������� 


}

