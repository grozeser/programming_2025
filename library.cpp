#include"library.hpp"
#include<iostream>

std::string FoundationDate::toString() const{
    return std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year);
}

Budget::Budget() : money(0), capitalPriority(1.0) {}
Budget::Budget(double m, double p) : money(m), capitalPriority(p) {}
Budget::Budget(const Budget& other) : money(other.money), capitalPriority(other.capitalPriority) {}

void Budget::changeMoney(double x){
    money += x;
}

State::State() : name("Default"), capital("None"), area(0), stateBudget(0, 1.0) {}

State::State(std::string n, std::string cap, FoundationDate f, long double a, Budget b)
    : name(n), capital(cap), foundation(f), area(a), stateBudget(b){
}

State::State(const State& other){
    name = other.name;
    capital = other.capital;
    foundation = other.foundation;
    area = other.area;
    cities = other.cities;
    stateBudget = other.stateBudget;
}

State::~State() {}

long State::getPopulation() const{
    long total = 0;
    for (const auto& c : cities) total += c.population;
    return total;
}

void State::addCity(const City& city){
    cities.push_back(city);
}

void State::distributeBudget() {
    double totalWeight = 0;
    for (const auto& c : cities) {
        if (c.name == capital) totalWeight += c.population * stateBudget.getPriority();
        else totalWeight += c.population;
    }

    if (totalWeight <= 0) return;

    for (auto& c : cities){
        double weight = (c.name == capital) ? (c.population * stateBudget.getPriority()) : c.population;
        c.availableMoney = stateBudget.getMoney() * (weight / totalWeight);
    }
}

void State::printInfo() const{
    std::cout << "Страна: \n";

    std::streamsize oldPrec = std::cout.precision();
    std::ios_base::fmtflags oldFlags = std::cout.flags();

    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.precision(2);

    std::cout << "Общий бюджет: " << stateBudget.getMoney() << "\n";
    for (const auto& c : cities){
        std::cout << " - " << c.name << ": Бюджет: " << c.availableMoney << "\n";
    }

    std::cout.precision(oldPrec);
    std::cout.flags(oldFlags);
}

State& State::operator+=(const State& other){
    name += " & " + other.name;
    area += other.area;
    stateBudget.changeMoney(other.stateBudget.getMoney());
    for (const auto& c : other.cities) cities.push_back(c);
    return *this;
}

State State::operator+(const State& other){
    State res = *this;
    res += other;
    return res;
}

State State::operator*(double multiplier){
    State res = *this;
    res.area *= multiplier;
    res.stateBudget.changeMoney(res.stateBudget.getMoney() * (multiplier - 1));
    return res;
}