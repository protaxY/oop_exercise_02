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


#include "Address.h"

Address::Address(const std::string &city, const std::string &street, const unsigned int &houseNum, const unsigned int &apartmentNum){
    CityName = city;
    StreetName = street;
    HouseNumber = houseNum;
    ApartmentNumber = apartmentNum;
}
Address::Address(const std::string &str){
    int position = 0;
    std::string city;
    while(str[position] != ','){
        city += str[position];
        position += 1;
    }
    position += 1;
    std::string street;
    while(str[position] != ','){
        street += str[position];
        position += 1;
    }
    std::string homeStr;
    while(str[position] != ','){
        homeStr += str[position];
        position += 1;
    }
    int home = std::stoi(homeStr);
    std::string apartmentStr;
    while(position != str.length()){
        apartmentStr += str[position];
        position += 1;
    }
    int apartment = std::stoi(apartmentStr);
    Address result(city, street, home, apartment);
}
std::string Address::IgnoreRegister(const std::string str){
    for (int i = 0; i < str.length(); ++i){
        tolower(str[i]);
    }
    return str;
}
void Address::print(){
    std::cout << CityName << "," << StreetName << "," << HouseNumber << "," << ApartmentNumber;
}
std::ostream & operator << (std::ostream &out, const Address &address){
    out << address.CityName << "," << address.StreetName << "," << address.HouseNumber << "," << address.ApartmentNumber;
    return out;
}
void Address::SetAddress(const std::string newCity, const std::string newStreet, const unsigned int newHouseNumber, const unsigned int newApartmentNumber){
    CityName = newCity;
    StreetName = newStreet;
    HouseNumber = newHouseNumber;
    ApartmentNumber = newApartmentNumber;
}
bool Address::IsOnThisCity(const std::string City){
    return Address::IgnoreRegister(CityName) == Address::IgnoreRegister(City);
}
bool Address::IsOnThisStreet(const std::string City ,const std::string Street){
    return (Address::IgnoreRegister(CityName) == Address::IgnoreRegister(City) && Address::IgnoreRegister(StreetName) == Address::IgnoreRegister(Street));
}
bool operator&(const Address lhs, const Address rhs){
    return (lhs.CityName == rhs.CityName && lhs.StreetName == rhs.StreetName && abs(lhs.HouseNumber - rhs.HouseNumber) == 1);
}
bool operator<(const Address lhs, const Address rhs){
    if (lhs.CityName == rhs.CityName){
        if (lhs.StreetName == rhs.StreetName){
            if (lhs.HouseNumber == rhs.HouseNumber){
                return lhs.ApartmentNumber < rhs.ApartmentNumber;
            }
            else return lhs.HouseNumber < rhs.HouseNumber;
        }
        else return lhs.CityName < rhs.CityName;
    }
    else return lhs.CityName < rhs.CityName;
}
bool operator<=(const Address lhs, const Address rhs){
    if (lhs.CityName == rhs.CityName){
        if (lhs.StreetName == rhs.StreetName){
            if (lhs.HouseNumber == rhs.HouseNumber){
                return lhs.ApartmentNumber <= rhs.ApartmentNumber;
            }
            else return lhs.HouseNumber <= rhs.HouseNumber;
        }
        else return lhs.CityName <= rhs.CityName;
    }
    else return lhs.CityName <= rhs.CityName;
}
bool operator>(const Address lhs, const Address rhs){
    if (lhs.CityName == rhs.CityName){
        if (lhs.StreetName == rhs.StreetName){
            if (lhs.HouseNumber == rhs.HouseNumber){
                return lhs.ApartmentNumber > rhs.ApartmentNumber;
            }
            else return lhs.HouseNumber > rhs.HouseNumber;
        }
        else return lhs.CityName > rhs.CityName;
    }
    else return lhs.CityName > rhs.CityName;
}
bool operator>=(const Address lhs, const Address rhs){
    if (lhs.CityName == rhs.CityName){
        if (lhs.StreetName == rhs.StreetName){
            if (lhs.HouseNumber == rhs.HouseNumber){
                return lhs.ApartmentNumber >= rhs.ApartmentNumber;
            }
            else return lhs.HouseNumber >= rhs.HouseNumber;
        }
        else return lhs.CityName >= rhs.CityName;
    }
    else return lhs.CityName >= rhs.CityName;
}
bool operator==(const Address lhs, const Address rhs){
    if (lhs.CityName == rhs.CityName){
        if (lhs.StreetName == rhs.StreetName){
            if (lhs.HouseNumber == rhs.HouseNumber){
                return lhs.ApartmentNumber == rhs.ApartmentNumber;
            }
            else return lhs.HouseNumber == rhs.HouseNumber;
        }
        else return lhs.CityName == rhs.CityName;
    }
    else return lhs.CityName == rhs.CityName;
}
bool operator!=(const Address lhs, const Address rhs){
    if (lhs.CityName == rhs.CityName){
        if (lhs.StreetName == rhs.StreetName){
            if (lhs.HouseNumber == rhs.HouseNumber){
                return lhs.ApartmentNumber != rhs.ApartmentNumber;
            }
            else return lhs.HouseNumber != rhs.HouseNumber;
        }
        else return lhs.CityName != rhs.CityName;
    }
    else return lhs.CityName != rhs.CityName;
}
const Address operator"" _address(const char* str, size_t size){
    int position = 0;
    std::string city;
    while(str[position] != ','){
        city += str[position];
        position += 1;
    }
    position += 1;
    std::string street;
    while(str[position] != ','){
        street += str[position];
        position += 1;
    }
    position += 1;
    std::string houseStr;
    while(str[position] != ','){
        houseStr += str[position];
        position += 1;
    }
    int house = std::stoi(houseStr);
    position += 1;
    std::string apartmentStr;
    while(position != size){
        apartmentStr += str[position];
        position += 1;
    }
    int apartment = std::stoi(apartmentStr);
    Address result(city, street, house, apartment);
    return result;
}