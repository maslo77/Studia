#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
using namespace std;
template <typename T>
T min(T a, T b){
    if(a<b)
        return a;
    else
        return b;
}
//1
template <typename T>
T& minBetween(T *b, T *e){
    T &min=*b;
    for(T *i=b;i<e;i++){
        if(min>*i)
            min=*i;
    }
    return min;
}
//2
template <>
string& minBetween(string *b, string *e){
    string *pos;
    string minCopy= *b;
    string current;
    transform(minCopy.begin(),minCopy.end(), minCopy.begin(), ::toupper);
    for(string *i = b; i<e; i++){
       current = *i;
       transform(current.begin(),current.end(), current.begin(), ::toupper);
    if(minCopy.compare(current)>0)
        minCopy = current;
        pos = i;
    }
    return *pos;
}
//3
template <template <typename ...> class C, typename T>
T &minofContainer(C<T> &container){
    T &min = *container.begin();
    for(const T& it: container){
        if(it<min)
            min = it;
    }
    return min;
}


int main()
{  // string a[]={"kota","Ma","Ala","aaa"};
    //cout<<minBetween(a,a+4)<<endl;
    vector<int> a;
    a.push_back(2);
    a.push_back(7);
    a.push_back(9);
    a.push_back(-2);
    a.push_back(21);

    cout<<minofContainer(a)<<endl;


    return 0;
}
