#pragma warning(disable : 4996)
#include <iostream>
#include "Clubs.h"

int main()
{
    Clubs d;
    std::cout << d.AddFolkClub("33", 10, 40, "Galena");
    std::cout << d.AddFolkClub("33", 40, 40, "Galena");
    User u("Ivan", 18, 180, 2, 2, ListeningTo::House);
    std::cout << d.AddToClub(u, "33");
}
