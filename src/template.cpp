/*
 * @Author: rzk ruanzk2098@gmial.com
 * @Date: 2025-01-22 23:52:07
 * @LastEditors: rzk ruanzk2098@gmial.com
 * @LastEditTime: 2025-01-23 17:17:26
 * @FilePath: /cplusplus/src/template.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>

using std::cout;
using std::endl;
#if 0

template<class T>
T add(T t1 , T t2){
    return t1 +t2;
}

void test(){
    int    i1 = 1, i2 = 2;
    double d1 = 3.3 , d2 = 4.4;
    cout<<"a + b " <<  add(i1,i2)<<endl;
    //cout<<"d1 + d2 " <<add(i1,d2)<<endl;
    cout<<add<int>(d1,i1)<<endl;
}
#endif

#if 0

template<class T>
T add(T t1 , T t2){
    cout<<"template<class T>  ";
    return t1 +t2;
}

template<class T1 , class T2>
T1 add(T1 t1 , T2 t2){
    cout<<"template<class T1 , class T2>  ";
    return t1 +t2;
}

void test(){
    int    i1 = 1, i2 = 2;
    double d1 = 30.3 , d2 = 40.4;
    cout<<add(i1,i2)<<endl;

    cout<<add(i1,d1)<<endl;
    cout<<add(d1,i1)<<endl;

    cout<<add<int>(d1,i1)<<endl; //template<class T> 
    cout<<add<int>(i1,d1)<<endl; //template<class T1 , class T2>
}
#endif
#if 0

template<class T>
T add(T t1 , T t2){
    cout<<"模板一   "<<endl;;
    return t1 +t2;
}

template<class T1, class T2>
T1 add(T1 t1 , T2 t2){
    cout<<"模板二   "<<endl;;
    return t1 +t2;
}

template<class T1, class T2>
T1 add(T2 t2 , T1 t1){
    cout<<"模板三   "<<endl;;
    return t1 +t2;
}


void test(){
    int a = 10;
    double d = 1.2;
    //add(a,d);
    add<double>(a,d);  //三

    add<int>(a,d);     //二

    add<double>(d,a); // 二

    add<int>(d,a);    // 三
}
#endif

#if 1

template<class T>
T add(T t1 , T t2);




void test(){
    int a1 = 10 , a2 = 10;

    add(a1,a2);
}

template<class T>
T add(T t1 , T t2){
    return t1 +t2;
}

#endif
int main(){
    test();
}