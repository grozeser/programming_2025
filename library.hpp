#pragma once

#include<iostream>
#include<vector>
#include<string>

class FoundationDate{
public:
    int day, month, year;
    FoundationDate(int d = 1, int m = 1, int y = 2024) : day(d), month(m), year(y) {}
    std::string toString() const;
};

struct City{
    std::string name;
    long population;
    double availableMoney;
};

class Budget{
private:
    double money;
    double capitalPriority; 

public:
    Budget(); 
    Budget(double m, double p); 
    Budget(const Budget& other); 

    void changeMoney(double x);
    double getMoney() const { return money; }
    double getPriority() const { return capitalPriority; }
    void setMoney(double m) { money = m; }
};

class State{
private:
    std::string name;
    std::string capital;
    FoundationDate foundation;
    long double area;
    std::vector<City> cities;
    Budget stateBudget;

public:
   
    State(); 
    State(std::string n, std::string cap, FoundationDate f, long double a, Budget b); // С параметрами
    State(const State& other);
    ~State(); 
    
    void setName(std::string n) { name = n; }
    std::string getName() const { return name; }
    void setCapital(std::string c) { capital = c; }
    std::string getCapital() const { return capital; }
    void setArea(long double a) { area = a; }
    long double getArea() const { return area; }
    void addCity(const City& city);

    long getPopulation() const;
    void printInfo() const;
    void distributeBudget(); 
   
    State& operator+=(const State& other);
    State operator+(const State& other);
    State operator*(double multiplier);
};
