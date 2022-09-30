#include<iostream>
using namespace std;
template<class t>
class myVector{
private:
    t *vec;
    int cs;
    int ms;

public:
    myVector(int size=1)
    {
        cs=0;
        ms=size;
        vec = new int[ms];
    }
    myVector(int size,t val)
    {
        this->ms = this->cs = size;
        this->vec = new t[size];
        for(int i=0;i<size;i++)
        {
            vec[i] = val;
        } 
    }
    int size(){return this->cs;}
    int capacity(){return this->ms;}
    t get(int i){return vec[i];}
    void push_back(t val);
    void pop_back(){this->cs--;}
    int operator[](int i){return vec[i];}
};
template<class t>
void myVector<t>::push_back(t val)
{
    if(cs == ms)
    {
        t* copy = vec;
        ms = 2*ms;
        vec = new t[ms];
        for(int i=0;i<cs;i++)
        {
            vec[i]=copy[i];
        }
        delete[] copy;
    }
    vec[cs++] = val;
}

int main()
{
    myVector<int> mv;
    mv.push_back(6);
    mv.push_back(7);
    mv.push_back(4);
    mv.push_back(2);
    mv.pop_back();
    cout<<mv.size()<<endl;
    cout<<mv.capacity()<<endl;
    for(int i=0;i<mv.size();i++)
    {
        cout<<mv[i]<<" ";
    }
}