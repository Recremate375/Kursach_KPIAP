#include<iostream>
#include<string>

using namespace std;

class Human
{
protected:
    int ID_;
    int day_;
    int mounth_;
    int year_;
    string name_, surname_, midname_;
    string job_, education_, place_of_study_;
    virtual void show() const = 0;
};