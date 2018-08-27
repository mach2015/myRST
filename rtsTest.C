#include "Base.H"
#include "Derived.H"
//#include<iostream>
using namespace Foam;
//using namespace std;
int main(int argc, char *argv[])
{
    const word& hello = "hello";
    Base b1(hello);
    Derived d1(hello);

    Info<<"myRTS"<<endl;
    b1.hello();
    d1.hello();
	
    return 0;
} 
