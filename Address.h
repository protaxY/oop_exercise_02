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

#ifndef OOP_EXERCISE_02_ADDRESS_H
#define OOP_EXERCISE_02_ADDRESS_H

#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>

class Address{
    private:
        std::string CityName;
        std::string StreetName;
        unsigned int HouseNumber;
        unsigned int ApartmentNumber;
        std::string IgnoreRegister(const std::string str);
    public:
        Address(const std::string &city, const std::string &street, const unsigned int &houseNum, const unsigned int &apartmentNum);
        Address(const std::string &str);
        void print();
        friend std::ostream & operator << (std::ostream &out, const Address &address);
        void SetAddress(const std::string newCity, const std::string newStreet, const unsigned int newHouseNumber, const unsigned int newApartmentNumber);
        bool IsOnThisCity(std::string City);
        bool IsOnThisStreet(std::string City ,std::string Street);
        friend bool operator&(const Address lhs, const Address rhs);
        friend bool operator<(const Address lhs, const Address rhs);
        friend bool operator<=(const Address lhs, const Address rhs);
        friend bool operator>(const Address lhs, const Address rhs);
        friend bool operator>=(const Address lhs, const Address rhs);
        friend bool operator==(const Address lhs, const Address rhs);
        friend bool operator!=(const Address lhs, const Address rhs);
};

const Address operator"" _address(const char* str, size_t size);

#endif //OOP_EXERCISE_02_ADDRESS_H
