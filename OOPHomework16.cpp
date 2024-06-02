#include <iostream>
#include <vector>

using namespace std;

class Automobile {
public:
    string name;
    int year;
    double engine_volume;
    double price;

    Automobile(string n, int y, double ev, double p) : name(n), year(y), engine_volume(ev), price(p) {}
};
struct CompareName 
{
    bool operator()(const Automobile& a, const Automobile& b)
    {
        return a.name < b.name;
    }
};
struct CompareYear 
{
    bool operator()(const Automobile& a, const Automobile& b) 
    {
        return a.year < b.year;
    }
};
struct CompareEngineVolume
{
    bool operator()(const Automobile& a, const Automobile& b) 
    {
        return a.engine_volume < b.engine_volume;
    }
};
struct ComparePrice
{
    bool operator()(const Automobile& a, const Automobile& b) 
    {
        return a.price < b.price;
    }
};
void addCar(vector<Automobile>& cars, const string& name, int year, double engine_volume, double price) 
{
    cars.push_back(Automobile(name, year, engine_volume, price));
}
void removeCar(vector<Automobile>& cars, const string& name)
{
    for (auto it = cars.begin(); it != cars.end(); ++it) 
    {
        if (it->name == name) {
            cars.erase(it);
            break;
        }
    }
}
void displayCars(const vector<Automobile>& cars) 
{
    for (const auto& car : cars)
    {
        cout << "Name: " << car.name << ", Year: " << car.year << ", Engine Volume: " << car.engine_volume << ", Price: " << car.price << '\n';
    }
}
void sortCarsByName(vector<Automobile>& cars)
{
    for (int i = 0; i < cars.size() - 1; ++i)
    {
        for (int j = i + 1; j < cars.size(); ++j) 
        {
            if (cars[i].name > cars[j].name) 
            {
                swap(cars[i], cars[j]);
            }
        }
    }
}
void sortCarsByYear(vector<Automobile>& cars)
{
    for (int i = 0; i < cars.size() - 1; ++i)
    {
        for (int j = i + 1; j < cars.size(); ++j) 
        {
            if (cars[i].year > cars[j].year)
            {
                swap(cars[i], cars[j]);
            }
        }
    }
}
void sortCarsByEngineVolume(vector<Automobile>& cars) 
{
    for (int i = 0; i < cars.size() - 1; ++i)
    {
        for (int j = i + 1; j < cars.size(); ++j)
        {
            if (cars[i].engine_volume > cars[j].engine_volume)
            {
                swap(cars[i], cars[j]);
            }
        }
    }
}
void sortCarsByPrice(vector<Automobile>& cars) 
{
    for (int i = 0; i < cars.size() - 1; ++i) 
    {
        for (int j = i + 1; j < cars.size(); ++j) 
        {
            if (cars[i].price > cars[j].price)
            {
                swap(cars[i], cars[j]);
            }
        }
    }
}
Automobile findCarByName(const vector<Automobile>& cars, const string& name) 
{
    for (const auto& car : cars)
    {
        if (car.name == name) 
        {
            return car;
        }
    }
}
Automobile findCarByYear(const vector<Automobile>& cars, int year)
{
    for (const auto& car : cars) 
    {
        if (car.year == year)
        {
            return car;
        }
    }
}
Automobile findCarByEngineVolume(const vector<Automobile>& cars, double volume) 
{
    for (const auto& car : cars)
    {
        if (car.engine_volume == volume) 
        {
            return car;
        }
    }
}
Automobile findCarByPrice(const vector<Automobile>& cars, double price) 
{
    for (const auto& car : cars) 
    {
        if (car.price == price) 
        {
            return car;
        }
    }
}
int main() 
{
    vector<Automobile> cars;

    addCar(cars, "BMW M5 E60", 2007, 5.0, 150000);
    addCar(cars, "BMW M5 E34", 1993, 3.8, 213000);
    addCar(cars, "BMW M6 Coupe", 2013, 4.4, 70000);

    displayCars(cars);

    sortCarsByName(cars);
    cout << "Sorted by name:\n";
    displayCars(cars);

    removeCar(cars, "BMW M6 Coupe");
    cout << "After removing BMW M6 Coupe :\n";
    displayCars(cars);

    Automobile foundCar = findCarByYear(cars, 1993);
    cout << "Found car by year: " << foundCar.name << '\n';
}