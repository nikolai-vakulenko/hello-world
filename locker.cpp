#include <iostream>


using namespace std;



template <class T, void(T::*Do)(void), void(T::*Undo)(void)> struct LockerT
{
    LockerT(T& m) : m_(m)
	{ (m_.*Do)();
	};
    ~LockerT()
	{ (m_.*Undo)();
	};
    T& m_;
};


struct targetType
{
    void begin(void){cout<<"begin"<<endl;};
    void end(void){cout<<"end"<<endl;};
};

typedef LockerT< targetType, &targetType::begin, &targetType::end > inst1;


int main (void){
targetType tobj;

inst1 obj(tobj);
cout<<"savecode"<<endl;

return 0;
};
