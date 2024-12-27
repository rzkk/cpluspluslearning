/*
 * @Author: rzk ruanzk2098@gmial.com
 * @Date: 2024-12-14 16:37:30
 * @LastEditors: rzk ruanzk2098@gmial.com
 * @LastEditTime: 2024-12-26 16:49:57
 * @FilePath: /cplusplus/src/inheritance.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>

using std::cout;
using std::endl;

namespace PointTest{
class Point{
public:
    Point(int  x,int y):_ix(x) ,_iy(y){
        cout<<"Point()"<<endl;
    }
    void print(){
        cout<<" ( "<<_ix<<","<<_iy<<" ) ";
    }
    ~Point(){cout<<"~Point()"<<endl;}
public :
    int _ix;
    int _iy;
};

class Point3D: public Point{
public:
    //Point3D(int x, int y , int z):_ix(x), _iy(y),_iz(z){}
    Point3D(int x, int y , int z):Point(x,y),_iz(z){ 
        cout<<"Point3D ()"<<endl;
    }
    ~Point3D(){cout<<"~Point3D()"<<endl;}
    void display(){
        print();
        cout<<_ix<<endl;
        cout<<" + "<<_iz <<endl;
    }
private:
    int _iz;
};

void test(){
    Point3D d1(1,2,3);
    d1.display();
    d1._ix;
}
}

namespace BaseTest{
class Test{
public:Test(int x ): _test(x){}
private: 
    long _test;
};

class Base{
public:
    Base(long x ):_base(x) {
        cout<<"Base()"<<endl;
    }
    void print(){
        cout<<"Base:: print()"<<endl;
    }
    long _data =100; 
private:
    long _base; 
};

class Derived: public Base{
public:
    Derived(long x ,long y):Base(y),_derived(x),_test(x){
        cout<<"Derived()"<<endl;
    }
    long _data = 10;
    // void print(int x ){
    //     cout<<"Derived:: print()"<<endl;
    // }
private: 
    long _derived; 
    Test _test;
};
void test(){
    Derived d(1,2);
    cout<<d._data<<endl;
    cout<<d.Base::_data<<endl;
    d.print();
    //d.print(2);
}
}

namespace mutiInheritanceTest{
class A{
public:
    A(){}
    A(int x):_a(x){}
    void print(){
        cout<<"A:: print()"<<endl;
    }
    int _a;
};

class B : virtual public A{
public:
    B():A(8){}
    int _b = 0;
};
class C: virtual public A{
public:
    C():A(5){}
    int _c = 0;
};

class D : public B ,public C{
public:
 int _d = 0;
};


void test1(){
    D d;
    cout<<d.C::_a<<endl;; 
    cout<<d.B::_a<<endl;; 
    //d.print();
    //d.B::_a;
    //d.C::print();
    // 
}

}
#include<cstring>
namespace test{

class Base{
public:
    // Base(){
    //     cout<<"Base ()"<<endl;
    // }
    Base(long x, const char * pstring):_base(x), _pbase(new char[strlen(pstring)+1]()){
        strcpy(_pbase , pstring);
        cout<<"Base (long x)"<<endl;
    }
    Base(const Base & rhs ):_base(rhs._base) ,_pbase(new char[strlen(rhs._pbase)+1]()){
        strcpy(_pbase , rhs._pbase);
        cout<<"const Base & rhs"<<endl;
    }

    Base&operator=(const Base & rhs){
        if(this != &rhs){
            if(_pbase){
                delete[] _pbase;
                _pbase = new char[strlen(rhs._pbase)+1]();
                strcpy(_pbase , rhs._pbase);
            }
            _base= rhs._base;
        }
        cout<<"Base operator =  "<<endl;;
        
        return *this;
    }
    ~Base(){
        if(_pbase){
            delete[] _pbase;
            _pbase = nullptr;
        }
    }
    void print()const{
        cout<<"_base+ _pbase  "<<_base<<" "<<_pbase;
    }
private:
    long  _base; 
    char * _pbase;
};

class Derived: public Base{
public:
    Derived(const char * pstring,long x , long y):Base(x,pstring), _derived(y){
        cout<<"Derived(long x , long y) "<<endl;
    }
    // Derived(const Derived & rhs):
    //         Base(rhs),    //Base 的拷贝构造 ， 没有的话就默认
    //         _derived(rhs._derived){
    //     cout<<"Derived(const Derived & rhs) "<<endl;
    // }

    // Derived&operator=(const Derived & rhs){
    //     cout<<"Derived operator =  "<<endl;
    //     _derived= rhs._derived;
    //     Base::operator=(rhs);
    //     return *this;
    // }
    void print()const{
        Base::print();
        cout<<"    _derived "<<_derived<<endl;
    }
private:
   int _derived;
};

void test(){
    //Base base(10);
    //Derived d(4,6);
    //base.opreerator=(d);
    //base = d;
    //base.print();
}
void test1(){
    Derived d1("hello",4,6);
    Derived d2("world",5,7);
    d1.print();

    d1 = d2;

    d1.print();

    Derived d3 = d1;  
    d3.print();
}
}
namespace PloymorphismTest
{  

#if 1
class Base{
public:
    Base(long x):_base(x){}
    
    virtual 
    void display() const {
        cout<<"Base display()"<<endl;
    }
    virtual 
    void show() const {
        cout<<"Base show()"<<endl;
    }
    virtual 
    void show1() const {
        cout<<"Base show()"<<endl;
    }
private:
    long _base;
    int a;
};


class Derived :public Base{
public:
    Derived(long base , long derived):Base(base),_derived(derived){}

    void display()const{
        cout<<"Derived display()"<<endl;

    }
 private: 
    long _derived;
};


void test(){
    Derived d1(4,8);
    Base * pb = &d1;
    //在数据成员公有化的情况下， 
    //父类指针指向子类 ， 只能访问父类子对象中的部分
    //pb->_base;
    //pb->_derived;//error , 父类只能访问自己的一亩三分地
    pb->display();  // Base 的

    cout<<sizeof(Base)<<endl;

    cout<<sizeof(Derived)<<endl;
    

    
}
#endif
#if 0 
class Grandpa
{
public:
    Grandpa(){ cout << "Grandpa()" << endl; }
    ~Grandpa(){ cout << "~Grandpa()" << endl; }

    virtual void func1() {
        cout << "Grandpa::func1()" << endl;
    }

    virtual void func2(){
        cout << "Grandpa::func2()" << endl;
    }
};

class Parent
: public Grandpa
{
public:
    Parent(){
        cout << "Parent()" << endl;
        func1();//构造函数中调用虚函数
    }

    ~Parent(){
        cout << "~Parent()" << endl;
        func2();//析构函数中调用虚函 数
    }
     virtual void func1() override {
        cout << "Parent::func1()" << endl;
    }

    virtual void func2() override{
        cout << "Parent::func2()" << endl;
    }
};

class Son
: public Parent
{
public:
    Son() { cout << "Son()" << endl; }
    ~Son() { cout << "~Son()" << endl; }

    virtual void func1() override {
        cout << "Son::func1()" << endl;
    }

    virtual void func2() override{
        cout << "Son::func2()" << endl;
    }

};

void test1(){
    Son ss;
    // Grandpa * p = &ss;
    // p->func1();
    // p->func2();

    cout << sizeof(Grandpa)<<endl;
    cout << sizeof(Parent)<<endl;
    cout << sizeof(Son)<<endl;
}


class Base{
public:
    Base(long x)
    : _base(x)
    {}

    virtual void display() const{
        cout << "Base::display()" << endl;
    }

    void func1(){  //普通成员函数中调用虚函数
        display();
        cout << _base << endl;
    }

    void func2(){
        Base::display();
    }
private:
    long _base = 10;
};


class Derived
: public Base
{
public:
    Derived(long base,long derived)
    : Base(base)
    , _derived(derived)
    {}
    void func1(){  //普通成员函数中调用虚函数
        display();
        //cout << _base << endl;
    }
    void display() const override{
        cout << "Derived::display()" << endl;
    }
private:
    long _derived;
};

void test2(){
    Base base(10);
    Derived derived(1,2);

    //base.func1();
    //base.func2();

    derived.func1(); // Derived的display 
    //derived.func2();
}
#endif
} // namespace PloymorphismTest
    

namespace CopyControlTest
{
class Base{
public:
    Base(long x):_base(x){}
    void print()const {
        cout<<_base;
    }
private:
    long _base = 10;
};


class Derived : public Base{
public:
    Derived(long x, long y ):Base(x),_derived(y){}
    // Derived(const Derived&c):Base(c),_derived(c._derived){
    //     cout<<"Derived(const Derived&c) "<<endl;
    // }

    // Derived& operator=(const Derived & rhs){
    //     Base::operator=(rhs);
    //     _derived = rhs._derived;
    // }
    void print()const {
        Base::print();
        cout <<"  " << _derived<<endl;
    }
private:
    long _derived = 12;
};

void test(){
    Derived d1(2,3);

    Derived d2(4,5);

    d2.print();
    d2 = d1;

    d2.print();

}


} // namespace test


int main(){
    PloymorphismTest::test();
}