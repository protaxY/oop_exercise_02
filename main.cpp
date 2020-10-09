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

int main() {
    std::cout << "test literal address:" << "A,B,1,1"_address << "\n";
    std::cout << "input address in \"city,street,house,apartment\"\n";
    std::string currentStr;
    std::cout << "insert address1:";
    std::cin >> currentStr;
    Address address1(currentStr);
    std::cout << "insert address2:";
    std::cin >> currentStr;
    Address address2(currentStr);
    std::cout << "address1 is ";
    address1.print();
    std::cout << "\n";
    std::cout << "address2 is ";
    address2.print();
    std::string locationCity;
    std::cout << "insert city name for location of address1 and address2";
    std::cin >> locationCity;
    std::cout << "is address1 located in this city? " << (address1.IsOnThisCity(locationCity) ? "YES" : "NO") << "\n";
    std::cout << "is address2 located in this city? " << (address2.IsOnThisCity(locationCity) ? "YES" : "NO") << "\n";
    std::string locationStreet;
    std::cout << "insert street name for location of address1 and address2";
    std::cin >> locationStreet;
    std::cout << "is address1 located in this street? " << (address1.IsOnThisStreet(locationStreet, locationStreet) ? "YES" : "NO") << "\n";
    std::cout << "is address2 located in this street " << (address2.IsOnThisStreet(locationStreet, locationStreet) ? "YES" : "NO") << "\n";
    std::cout << "\n";
    std::cout << "is address1 and address2 are neighbors? " << (address1 == address2 ? "YES" : "NO") << "\n";
    std::cout << "is address1 == address2? " << (address1 == address2 ? "YES" : "NO") << "\n";
    std::cout << "is address1 != address2? " << (address1 != address2 ? "YES" : "NO") << "\n";
    std::cout << "is address1 < address2? " << (address1 < address2 ? "YES" : "NO") << "\n";
    std::cout << "is address1 <= address2? " << (address1 <= address2 ? "YES" : "NO") << "\n";
    std::cout << "is address1 > address2? " << (address1 > address2 ? "YES" : "NO") << "\n";
    std::cout << "is address1 >= address2? " << (address1 >= address2 ? "YES" : "NO") << "\n";
    return 0;
}
