//
// Created by shahar on 08/06/2020.
//
#pragma once
#include "Itertool.hpp"
#include <vector>
using namespace std;
#include <iostream>



namespace itertools {
    class plus
    {
    public:
        template <typename T>
         T operator()(const T a, const T b)const{
            return a + b;
        }

    };

//    typedef struct {
//        template <typename U>
//        U operator()( U& a, U& b) const{
//            return a+b;
//        }
//
//    } plus_default;

    template<typename T,typename F=plus>
    class accumulate {  //function
         T collect;   //range /vector<int>
         F func;
//        int start;
//        int endd; // U-in

    public:


        accumulate(T collect , F f=plus()):collect(collect),func(f){}




        auto operator[]( typename T::iterator nIndex) const //  const T &
        {
//            typename T::iterator temp=nIndex;
//            temp++;
//            /////////////today
//             if(typeid(*nIndex)== typeid(string)){
//                 auto sum2="";
//                 for (auto i = collect.begin(); i != temp; i++) {
//                     sum2=this->func(sum2,*i);   //just now
//                 }
//                 return sum2;
//             }
//             //////////////////



//            auto sum=1;
//
//            if(this->func(1,1)==2){    //a plus function
//               sum = 0;
//            }
//            for (auto i = collect.begin(); i != temp; i++) {
//                sum=this->func(sum,*i);   //just now
//            }
//
//            return sum;



            auto t=0;
            return t;

        }


        class iterator {
        private:
            accumulate *myaccumulate;
            typename T::iterator it;   //moves

        public:
            iterator(  accumulate *Accumulate,typename T::iterator place) {
                this->it=place;
                myaccumulate = Accumulate;
               // sum=fnc()
                //myindex = nIndex;
            }

             auto  operator*()  {  //const T&
                return myaccumulate->operator[](it);
            }

            iterator& operator++() {
                ++it;
                return *this;
            }

             iterator& operator++(int) {
                iterator tmp= *this;
                ++it;
                return tmp;
            }

            bool operator!=(const iterator &other) const { return this->it != other.it; }

          //  bool operator==(const Iterator &other) const { return this->it == other.it; }


        };

         iterator begin()  {
            return iterator{this, this->collect.begin()};
        }

        iterator end() {
            return iterator{this, this->collect.end()};
        }

    };
}



//
//    accumulate(vector<string> list) {
//
//        cout<<"in string"<<endl;
//        vector <string> answer;
//        string sum = list[0];
//        int i = 1;
//        while (i <= list.size()) {
//            answer.push_back(sum);
//            sum = sum + list[i];
//
//            i++;
//        }
//
//    }




//
//vector<string> accumulate(vector<char> list) {   //more spesific cause to change from char to string is problem
//    vector <string> answer;
//    string sum = "";
//    sum+= list[0];
//    int i = 1;
//    while (i <= list.size()) {
//        answer.push_back(sum);
//        sum = sum + list[i];
//
//        i++;
//    }
//
//    return answer;
//}
//
//template <typename T>
//vector<T> accumulate(vector<T> list,int (*fcn)(int x,int y)) {
//
//    vector <T> answer;
//    T sum = list[0];
//    int i = 1;
//    while (i <= list.size()) {
//        answer.push_back(sum);
//
//        // cout<<"i="<<list[i]<<endl;
//        sum= fcn(sum,list[i]);
//        i++;
//
//    }
//
//
//    return answer;
//}












