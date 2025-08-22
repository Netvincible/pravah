#ifndef PRAVAH_H
#define PRAVAH_H
#include <initializer_list>
#include <type_traits>
#include <memory>
#include <iostream>
using namespace std;
template <typename T> class pravah
{
    private:
        size_t sz;

    public:
        T *pr;
        pravah()
        {
            pr=nullptr;
            sz=0;
        }
        pravah(size_t s):sz(s)
        {
            T value;
            if constexpr (is_integral<T>::value || is_floating_point<T>::value) {
            value = 0;
        }
            
            pr = new T[sz];               // new uses malloc internally
            
            for(int i=0;i<sz;i++)
                pr[i]=value;
        }
        pravah(size_t s, T value)
        {
            sz=s;
            pr=new T[sz+1];
            for(int i=0;i<sz;i++)
                pr[i]=value;
        }
        pravah(initializer_list<T> initial_list)
        {
            sz=initial_list.size();
            pr=new T [sz];
            int i=0;
            for(auto v:initial_list)
            {
                pr[i]=v;
                i++;
            }
        }
        void nivesh(int index,T value)
        {
            T* temp=new T[sz+1];
            for(int i=0;i<sz;i++)
            {
                if(i<index)
                    temp[i]=pr[i];
                else if(i>index)
                    temp[i+1]=pr[i];
                else
                    temp[i]=value;
            }
            delete[] pr;
            pr=temp;
            sz++;
        }
        void vinivesh(int index)
        {
            T* temp=new T[sz-1];
            for(int i=0;i<sz;i++)
            {
                if(i<index)
                    temp[i]=pr[i];
                else if(i>index)
                    temp[i-1]=pr[i];
            }
            delete[] pr;
            pr=temp;
            sz--;
        }
        int dhundho(T value)
        {
            for(int i=0;i<sz;i++)
            {
                if(value==pr[i])
                    return i;
            }
            return -1;
        }
        int maap()
        {
            return sz;
        }
        void kram()
        {
            for(int i=0;i<sz;i++)
            {
                bool flag=true;
                for(int j=0;j<sz-i-1;j++)
                {
                    if(pr[j]>pr[j+1])
                    {
                        T temp=pr[j];
                        pr[j]=pr[j+1];
                        pr[j+1]=temp;
                        flag=false;
                    }
                }
                if (flag)
                    break;
            }
        }
        void viprit()
        {
            for(int i=0;i<(sz/2 +1);i++)
            {
                T temp=pr[i];
                pr[i]=pr[sz-i-1];
                pr[sz-i-1]=temp;
            }
        }

        void nakal(pravah& obj)   //Here you can understand why do we call method of object in which value is to be copied and why the value to copied is passed as argument
        {                           // also we here call obj by reference because using call by value will call copy variable's destructor, the problem is copy variable's destructor destroys the memory at which pointer is pointing to which is same as our original variable
            size_t newS=obj.maap();
            if(pr==nullptr)
                pr=new T[newS];
            for(int i=0;i<newS;i++)
                pr[i]=obj.pr[i];
            sz=newS;
        }
        void maap_parivartan(size_t s)
        {
            
            size_t n = (s < sz) ? s : sz;
            T *newpr;
            newpr= new T[s];
            for (size_t i = 0; i < n; i++)
            {
                newpr[i] = pr[i];
            }
            delete[] pr;
            pr = newpr;
            newpr=nullptr;
            sz = s;
        }
        ~pravah()
        {
            
            delete[] pr;
            pr=nullptr;
        }
};
#endif