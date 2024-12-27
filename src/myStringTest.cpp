/*
 * @Author: rzk ruanzk2098@gmial.com
 * @Date: 2024-12-08 19:33:30
 * @LastEditors: rzk ruanzk2098@gmial.com
 * @LastEditTime: 2024-12-09 18:05:35
 * @FilePath: /cplusplus/src/myStringTest.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "myString.h"

using std::cout;
using std::endl;
using std::size_t;

void test1(){
    String s1;
    String s2("Hello word!");
    String s3(s2);
    std::cout<<s2.c_str()<<std::endl;
    std::cout<<s3.c_str()<<std::endl;
   
    String s4 = s2;
    String s5 = "nihao !";
    s4 = s3;
    s5 = "qwert";

    std::cout<<s4.c_str()<<endl;
    std::cout<<s5.c_str()<<endl;

    s5 += s4;

    cout<<s5.c_str()<<endl;

    s5+= " dsds";
    cout<<s5.c_str()<<endl;
}
void test2(){
    String s1("Hello");
    //  cout<<s1.size()<<endl;
    //  for(size_t i = 0;i< s1.size();++i ){
    //     cout<<s1[i]<<" ";
    //  }
    //  cout<<endl<<s1<<endl;

    //  cout<<endl;
    //  const String s2("hhhh");
    //  cout<<s2[2]<<endl;;
     std::cin>>s1;
     cout<<s1<<endl;;
     cout<<s1.size()<<endl;
}


int main(){
    test2();
}