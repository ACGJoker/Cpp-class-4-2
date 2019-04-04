#include <iostream>
#include <cstring>
using namespace std;
class TwoDShape //抽象类，有一个或多个纯虚函数

{
private:
    char name[20];
public:
    TwoDShape(char* s){//构造不能是虚函数
        strcpy(name,s);
        cout <<"construct a TwoDShape"<<endl;
    }
   virtual void draw(){cout<<name <<endl;}
//虚析构函数
    virtual ~TwoDShape(){
        cout <<"destruct a TwoDShape" <<endl;
    }

	virtual void getArea()=0;//纯虚函数，无函数体，派生类中实现
};

class Rectangle:public TwoDShape //若有基类纯虚函数未重写，则依旧为抽象类
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

//void test(TwoDShape tds)  不可以
//TwoDShape f() 不可以

int main()
{
    TwoDShape*p;//可指向任何派生类对象

    p = new Rectangle("rect",2,8);
	Rectangle re("rect",5,8);
	TwoDShape & t(re);
	p->getArea();

    delete p;
	//抽象类使用时：
	//1 不能定义抽象类对象  TwoDShape obj（...）
	//2 可以定义抽象类指针或引用 


}

