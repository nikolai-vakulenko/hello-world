#include <iostream>

class TBase
{
public:
    void doHello()
    {
        std::cout << "TBase::Hello()" << std::endl;
    }
};

class Left : public TBase
{
public:
    void doHello()
    {
        std::cout << "Left::Hello()" << std::endl;
    }
};

int main()
{
	TBase *a;
	a=new Left;
    a->doHello();
    static_cast<Left*>(a)->doHello();
    return 0;
}
