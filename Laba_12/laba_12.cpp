#include <iostream>
#include <set>
#include <stdlib.h>

#define PERCENTS(X, Y) (Y >= ((X - X/10)) && (Y <= (X + X/10)))

enum {
    ADD_REG = 1,
    PRINT_REGS,
    MENU_REG,
    CLEAR
};

struct Reg;
bool operator < (const Reg &a, const Reg &b);

class Registragtions {
private:
    std::set<Reg> regList;
public:
    Registragtions(Registragtions& regs);
    Registragtions() {}
    ~Registragtions() {}
    void add(struct Reg reg);
    void print();
    void menu();
    const std::set<Reg>& getRegList();
};

struct Reg {
    std::string surname;
    std::string initials;
    struct apartment {
        unsigned int rooms;
        unsigned int squere;
        unsigned int floor;
        unsigned int district;
    } first_apartment, second_apartment;
};
bool operator < (const Reg &a, const Reg &b) {
    return a.surname < b.surname;
    return a.initials < b.initials;
    return a.second_apartment.squere < b.first_apartment.squere;
    return a.second_apartment.rooms < b.first_apartment.rooms;
    
}

Registragtions::Registragtions(Registragtions& regs) {
    regList.clear();
    const std::set<Reg> reg = regs.getRegList();
    regList.insert(reg.begin(), reg.end());
}

void Registragtions::add(struct Reg reg) {
    std::set<Reg>::iterator itr = regList.begin();
    for (unsigned i=0; i < regList.size(); i++, itr++) {
        if ((reg.first_apartment.rooms == (*itr).first_apartment.rooms) && PERCENTS(reg.first_apartment.squere, (*itr).first_apartment.squere)) {
            std::cout << "{" << std::endl;
            std::cout << "surname: " << (*itr).surname << std::endl;
            std::cout << "initials: " << (*itr).initials << std::endl;
            std::cout << "first_apartment {" << std::endl;
            std::cout << "\trooms: " << (*itr).first_apartment.rooms << std::endl;
            std::cout << "\tsquere: " << (*itr).first_apartment.squere << std::endl;
            std::cout << "\tfloor: " << (*itr).first_apartment.floor << std::endl;
            std::cout << "\tdistrict: " << (*itr).first_apartment.district << std::endl;
            std::cout << "}" << std::endl;
            std::cout << "secontd_apartment {" << std::endl;
            std::cout << "\trooms: " << (*itr).second_apartment.rooms << std::endl;
            std::cout << "\tsquere: " << (*itr).second_apartment.squere << std::endl;
            std::cout << "\tfloor: " << (*itr).second_apartment.floor << std::endl;
            std::cout << "\tdistrict: " << (*itr).second_apartment.district << std::endl;
            std::cout << "}" << std::endl;
            regList.erase(itr);
            return;
        }
    }
    regList.insert(reg);
}
void Registragtions::print() {
    std::set<Reg>::iterator itr = regList.begin();
    for (unsigned i=0; i < regList.size(); i++, itr++) {
        std::cout << "{" << std::endl;
        std::cout << "surname: " << (*itr).surname << std::endl;
        std::cout << "initials: " << (*itr).initials << std::endl;
        std::cout << "first_apartment {" << std::endl;
        std::cout << "\trooms: " << (*itr).first_apartment.rooms << std::endl;
        std::cout << "\tsquere: " << (*itr).first_apartment.squere << std::endl;
        std::cout << "\tfloor: " << (*itr).first_apartment.floor << std::endl;
        std::cout << "\tdistrict: " << (*itr).first_apartment.district << std::endl;
        std::cout << "}" << std::endl;
        std::cout << "secontd_apartment {" << std::endl;
        std::cout << "\trooms: " << (*itr).second_apartment.rooms << std::endl;
        std::cout << "\tsquere: " << (*itr).second_apartment.squere << std::endl;
        std::cout << "\tfloor: " << (*itr).second_apartment.floor << std::endl;
        std::cout << "\tdistrict: " << (*itr).second_apartment.district << std::endl;
        std::cout << "}" << std::endl;
    }
}
void Registragtions::menu() {
    std::cout << "Menu:" << std::endl;
    std::cout << "1) Make a registration" << std::endl;
    std::cout << "2) Print all" << std::endl;
    std::cout << "3) Menu" << std::endl;
    std::cout << "4) Clear" << std::endl;
}

const std::set<Reg>& Registragtions::getRegList() {
    return regList;
}

int main() {
    Registragtions registragtions;
    Reg reg;
    std::string str;
    int c;
    int num;
    registragtions.menu();

    registragtions.add({"John", "Ericson", {4, 123, 2, 13}, {5, 150, 4, 12}});
    registragtions.add({"Peter", "Godfree", {5, 134, 2, 13}, {5, 150, 4, 12}});
    registragtions.add({"Stive", "Washington", {3, 50, 2, 13}, {5, 150, 4, 12}});
    
    for (;;) {
        std::cout << "--> ";
        std::cin >> c;
        switch (c) {
            case ADD_REG:
                std::cout << "Surname: ";
                std::cin >> str;
                reg.surname = str;

                std::cout << "Initials: ";
                std::cin >> str;
                reg.initials = str;

                std::cout << "First apartment" << std::endl;
                std::cout << "rooms: ";
                std::cin >> num;
                reg.first_apartment.rooms = num;

                std::cout << "squere: ";
                std::cin >> num;
                reg.first_apartment.squere = num;

                std::cout << "floor: ";
                std::cin >> num;
                reg.first_apartment.floor = num;

                std::cout << "district: ";
                std::cin >> num;
                reg.first_apartment.district = num;

                std::cout << "Second apartment" << std::endl;
                std::cout << "rooms: ";
                std::cin >> num;
                reg.second_apartment.rooms = num;

                std::cout << "squere: ";
                std::cin >> num;
                reg.second_apartment.squere = num;

                std::cout << "floor: ";
                std::cin >> num;
                reg.second_apartment.floor = num;

                std::cout << "district: ";
                std::cin >> num;
                reg.second_apartment.district = num;

                registragtions.add(reg);
                break;
            case PRINT_REGS:
                registragtions.print();
                break;
            case MENU_REG:
                registragtions.menu();
                break;
            case CLEAR:
                system("clear");
                break;
        }
    }
    return 0;
}