#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <chrono>
#include "Logger.h"

class Car {
public:
    int id;
    std::string brand;
    std::string model;
    int year;
    std::string color;
    double price;
    std::string registrationNumber;

    // Default constructor
    Car() {}

    // Constructor with parameters
    Car(int _id, const std::string& _brand, const std::string& _model, int _year,
        const std::string& _color, double _price, const std::string& _regNumber)
        : id(_id), brand(_brand), model(_model), year(_year),
          color(_color), price(_price), registrationNumber(_regNumber) {}

    // Operator overload <<
    friend std::ostream& operator<<(std::ostream& os, const Car& car) {
        os << "Car #" << car.id << ": " << car.brand << " " << car.model
           << " (" << car.year << "), Color: " << car.color
           << ", Price: $" << car.price << ", Reg. Number: " << car.registrationNumber;
        return os;
    }
};

int main() {

    Logger logger("aboba.log");
    logger << "Program started";
    // Array of objects Car
    std::vector<Car> cars = {
        {1, "Toyota", "Camry", 2018, "Blue", 25000, "AB1234FF"},
        {2, "Honda", "Civic", 2019, "Red", 22000, "KA5678FF"},
        {3, "Mazda", "X5", 2017, "Red", 30000, "AB5533FF"},
        {4, "Ford", "Focus", 2016, "White", 27000, "BC9876GH"},
        {5, "Volkswagen", "Golf", 2018, "Black", 19000, "AA4321CC"},
        {6, "Lanos", "Sens", 2015, "Green", 50000, "BB8765LL"},
        {7, "Toyota", "Corolla", 2020, "Gray", 15000, "KA1122DD"},
        {8, "Mazda", "CX-5", 2019, "Blue", 23000, "BC3344EE"},
        {9, "Ford", "Fiesta", 2017, "Yellow", 31000, "AA5566GG"},
        {10, "Volkswagen", "Passat", 2018, "Silver", 18000, "CC7788HH"},
        {11, "Ford", "Focus", 2011, "White", 27000, "BC9876GH"},
        {12, "Honda", "Civic", 2009, "Red", 22000, "AC5028FF"},
        {13, "Volkswagen", "Golf", 2012, "Green", 18000, "CA7628CC"},
        {14, "Toyota", "RAV4", 1998, "Blue", 10000, "AA9988GG"},
        {15, "Toyota", "Corolla", 2015, "Gray", 15000, "KA1122DD"},
        {16, "Toyota", "Camry", 2021, "Red", 12000, "CC3344HH"},
        {17, "Mazda", "X5", 2018, "White", 25000, "BB5678FF"},
        {18, "Ford", "Focus", 2020, "Blue", 14000, "DD9988GG"},
        {19, "Volkswagen", "Passat", 2019, "Green", 21000, "FF4433HH"},
        {20, "Lanos", "Sens", 2016, "Yellow", 40000, "GG2233LL"},
        {21, "Toyota", "Corolla", 2022, "Silver", 8000, "HH6677KK"},
        {22, "Mazda", "CX-5", 2021, "Gray", 18000, "JJ8899MM"},
        {23, "Ford", "Fiesta", 2018, "Black", 23000, "KK2233NN"},
        {24, "Volkswagen", "Golf", 2020, "White", 17000, "LL5566OO"},
        {25, "Lanos", "Sens", 2019, "Blue", 30000, "MM3344PP"}
    };

    int choice;

    std::cout << "Chose sorting parameter:" << std::endl;
    std::cout << "1. Mark" << std::endl;
    std::cout << "2. Model + Usage time" << std::endl;
    std::cout << "3. Manufacture year + Price" << std::endl;
    std::cout << "Your choice: ";
    std::cin >> choice;

    switch (choice)
    {
        case 1:
            {
                logger << "Sorting by Mark was chosen";
                std::string targetBrand;
                std::cout << "Make your choice:" << std::endl;
                std::cout << "Toyota, Mazda, Ford, Volkswagen, Lanos: ";
                std::cin >> targetBrand;
                logger << "The chosen Mark is: " << targetBrand;
                for (const auto& car : cars)
                {
                    if (car.brand == targetBrand)
                    {
                        std::cout << car << std::endl;
                    }
                }
                break;
            }

        case 2:
            {
                logger << "Sorting by Model + Usage time was chosen";
                std::string targetModel;
                int n;
                std::cout << "Choose model: Camry, Civic, X5, Focus, Golf, Sens, Corolla, CX-5, Fiesta, Passat," << std::endl;
                std::cout << "Focus, Civic, Golf, RAV4, Corolla: ";
                std::cin >> targetModel;
                logger << "The chosen Model is: " << targetModel;
                std::cout << "Older than how many years should it be: ";
                std::cin >> n;
                logger << "How much older it was chosen to be: " << n;
                for (const Car& car : cars)
                {
                    if (car.year < 2024 - n && car.model == targetModel)
                    {
                        std::cout << car << std::endl;
                    }
                }
                break;
            }
        case 3:
            {
                logger << "Sorting by Manufacture year + Price time was chosen";
                int targetYear;
                int price;
                std::cout << "Choose production year: ";
                std::cin >> targetYear;
                logger << "The chosen production year is: " << targetYear;
                std::cout << "More than what number should it cost (in $): ";
                std::cin >> price;
                logger << "It has to cost more than: " << price;
                for (const Car& car : cars)
                {
                    if (car.year == targetYear && car.price > price)
                    {
                        std::cout << car << std::endl;
                    }
                }
                break;
            }
        default:
            logger << "The user might have dyslexia";
            std::cout << "Put your glasses on" << std::endl;
            break;
    }
    logger << "Finished successfully";
    return 0;
}

