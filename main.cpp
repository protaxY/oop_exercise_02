//Федоров А. С. М8О-207Б-19
//вариант 19
//
//Создать класс Address для работы с адресами домов. Адрес должен состоять из строк с названием города и улицы и чисел с
//номером дома и квартиры. Реализовать операции сравнения адресов, а также операции проверки принадлежности адреса к
//улице и городу. В операциях не должен учитываться регистр строки. Так же необходимо сделать операцию, которая
//возвращает истину если два адреса находятся по соседству (на одной улице в одном городе и дома стоят подряд).
//Операцию сравнения равенства реализовать в виде перегрузки оператора. Операцию нахождения «по соседству» реализовать
//в виде перегрузки оператора &.
//Необходимо реализовать пользовательский литерал для работы с константами типа Address.

#include <iostream>
#include "Address.h"

bool CheckFormat(std::string &str){
    int position = 0;
    while(str[position] != ',' && position < str.length()){
        position += 1;
    }
    if(position == str.length()){
        return false;
    }
    position += 1;
    while(str[position] != ',' && position < str.length()){
        position += 1;
    }
    if(position == str.length()){
        return false;
    }
    position += 1;
    while(str[position] != ',' && position < str.length()){
        if(str[position] < '0' || str[position] > '9'){
            return false;
        }
        position += 1;
    }
    if(position == str.length()){
        return false;
    }
    position += 1;
    while(position != str.length()){
        if(str[position] < '0' || str[position] > '9'){
            return false;
        }
        position += 1;
    }
    return true;
}

int main() {
    std::cout << "test literal address:" << "Here's city name,Here's street name,12,34"_address << "\n";
    std::cout << "input address in \"city,street,house,apartment\" format\n";
    std::string currentStr;
    std::cout << "insert address1:";
    std::getline(std::cin, currentStr);
    if (!CheckFormat(currentStr)){
        std::cout << "invalid format\n";
        return 0;
    };
    Address address1(currentStr);
    std::cout << "insert address2:";
    std::getline(std::cin, currentStr);
    if (!CheckFormat(currentStr)){
        std::cout << "invalid format\n";
        return 0;
    };
    Address address2(currentStr);
    std::cout << "address1 is ";
    address1.print();
    std::cout << "\n";
    std::cout << "address2 is ";
    address2.print();
    std::cout << "\n";
    std::string locationCity;
    std::cout << "insert city name for location of address1 and address2:";
    std::getline(std::cin, locationCity);
    std::cout << "is address1 located in this city? " << (address1.IsOnThisCity(locationCity) ? "YES" : "NO") << "\n";
    std::cout << "is address2 located in this city? " << (address2.IsOnThisCity(locationCity) ? "YES" : "NO") << "\n";
    std::string locationStreet;
    std::cout << "insert street name for location of address1 and address2:";
    std::getline(std::cin, locationStreet);
    std::cout << "is address1 located on this street? " << (address1.IsOnThisStreet(locationCity, locationStreet) ? "YES" : "NO") << "\n";
    std::cout << "is address2 located on this street? " << (address2.IsOnThisStreet(locationCity, locationStreet) ? "YES" : "NO") << "\n";
    std::cout << "\n";
    std::cout << "is address1 and address2 are neighbors? " << (address1 & address2 ? "YES" : "NO") << "\n";
    std::cout << "is address1 == address2? " << (address1 == address2 ? "YES" : "NO") << "\n";
    std::cout << "is address1 != address2? " << (address1 != address2 ? "YES" : "NO") << "\n";
    std::cout << "is address1 < address2? " << (address1 < address2 ? "YES" : "NO") << "\n";
    std::cout << "is address1 <= address2? " << (address1 <= address2 ? "YES" : "NO") << "\n";
    std::cout << "is address1 > address2? " << (address1 > address2 ? "YES" : "NO") << "\n";
    std::cout << "is address1 >= address2? " << (address1 >= address2 ? "YES" : "NO") << "\n";
    return 0;
}
