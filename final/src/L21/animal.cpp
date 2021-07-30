#include <iostream>
using namespace std;
#include "animal.h"

int main()
{
    Animal* animal;
    Cow cow(1);
    SickCow sickCow(1, 1);
    MadCow madCow(0, 0);
    SickMadCow sickMadCow(1, 1, 1);

    sickCow.eat();
    sickCow.speak();
    sickCow.takeMed();

    cout << "\n";

    animal = &cow;
    animal->eat();
    animal->speak();

    cout << "\n";

    animal = &sickCow;
    animal->eat();
    animal->speak();

    cout << "\n";

    Animal& victim = sickMadCow;
    victim.eat();
    victim.speak();

    cout << "\n";

    MadCow* someCow = new SickMadCow(0, 0, 0);
    someCow->takePills();
    someCow->eat();
    someCow->speak();
}