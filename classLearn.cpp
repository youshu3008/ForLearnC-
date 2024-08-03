#include <iostream>

using namespace std;
class classLearn
{
private:
    /* data */
public: 
    int m_num1, m_num2;
    virtual int getResult() = 0;
    ~classLearn(){

    };
};

class AddCalculator : public classLearn{
    public:
        int getResult(){
            return m_num1 + m_num2;
        }
};

void test1(){
    // AddCalculator *addtest = new AddCalculator;
    AddCalculator addtest;
    addtest.m_num1 = 5;
    addtest.m_num2 = 12;
    int result = addtest.getResult();
    cout << addtest.m_num1 << "+" <<  addtest.m_num2 << "=" << result << endl;
    // delete addtest;
}

int main(){
    test1();
}