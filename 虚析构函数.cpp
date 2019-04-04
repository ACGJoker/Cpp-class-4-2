#include <iostream>
#include <cstring>
using namespace std;
class TwoDShape
{
private:
    char name[20];
public:
    TwoDShape(char* s){
        strcpy(name,s);
        cout <<"construct a TwoDShape"<<endl;
    }
   virtual void draw(){cout<<name <<endl;}
//ÐéÎö¹¹º¯Êý
    virtual ~TwoDShape()
    {
        cout <<"destruct a TwoDShape" <<endl;
    }
};

class Rectangle:public TwoDShape
{
private:
    float x,y;
public:
    Rectangle(char* s,float x,float y)
    :TwoDShape(s)
    {
        this->x = x;this->y = y;
        cout <<"construct a Rectangle"<<endl;
    }
    void draw()
    {
        TwoDShape::draw();
        cout << "length is " <<x << ' '
        <<"width is "<< y <<endl;
    }
    ~Rectangle()
    {
        cout <<"destruct a Rectangle" <<endl;
    }
};

int main()
{
    TwoDShape*p;
    p = new Rectangle("rect",2,8);

    delete p;

}
