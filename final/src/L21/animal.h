#ifndef FINAL_REVIEW_ANIMALS_D_H
#define FINAL_REVIEW_ANIMALS_D_H
#include <iostream>
using namespace std;
class Animal {
public:
    virtual void speak() = 0;

    virtual void eat() { cout << "Eat, Eat\n"; };
};

class Sick {

public:
    void takeMed()
    {
        if (med > 0) {
            med--;
            cout << "I feel better\n";
        }

        else
            cout << "I'm dying\n";
    };

protected:
    int med;
};

class Cow : public Animal {

public:
    Cow(int f = 0)
        : grass(f) {};

    virtual void speak() { cout << "Moo.\n"; };

    void eat()
    {
        if (grass > 0) {
            grass--;
            cout << "Thanks I'm full\n";
        }

        else
            cout << "I'm hungry\n";
    };

protected:
    int grass;
};

class SickCow : public virtual Cow, public Sick {

public:
    SickCow(int f = 0, int m = 0)
    {
        grass = f;
        med = m;
    };

    void speak() { cout << "Ahem... Moo\n"; };
};

class MadCow : public virtual Cow {

public:
    MadCow(int f = 0, int p = 0)
    {
        grass = f;
        pills = p;
    };

    void speak() { cout << "Woof\n"; };

    void takePills()
    {
        if (pills > 0) {
            pills--;
            cout << "Moof, that's better\n";
        }

        else
            cout << "Woof woof woof!\n";
    };

protected:
    int pills;
};

class SickMadCow : public SickCow, public MadCow {

public:
    SickMadCow(int f = 0, int m = 0, int p = 0)
    {
        grass = f;
        med = m;
        pills = p;
    };

    void speak() { cout << "Ahem... Woof\n"; };
};

#endif // FINAL_REVIEW_ANIMALS_D_H