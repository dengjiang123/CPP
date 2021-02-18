#include<iostream>
#include"stonewt.h"
using std::cout;
void display(const Stonewt st, int n);

int main()
{
    Stonewt a;
    a = Stonewt(100);
    a.show_stn();

    Stonewt b(9, 2.8);
    double star = b;
    cout << star << std::endl;

    return 0;
}

void display(const Stonewt  st, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Wow! ";
        st.show_stn();
    }
}