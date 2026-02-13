#include<iostream>
#include<vector>
#include<string>
#include<limits>
#include<ctime>
#include<cstdlib>

class FoundationDate{
private:
    unsigned short day = 1;
    unsigned short month = 1;
    int year = 1;

public:
    FoundationDate() = default;

    FoundationDate(unsigned short d, unsigned short m, int y)
        : day(d), month(m), year(y) {
    }

    std::string toString() const{
        return std::to_string(day) + "." +
            std::to_string(month) + "." +
            std::to_string(year);
    }
};

class State{
private:
    std::string name;
    std::string capital;
    FoundationDate foundation;
    long double area{};
    std::vector<std::string> cities;

    bool cityExists(const std::string& city) const{
        for (const auto& c : cities)
            if (c == city)
                return true;
        return false;
    }

public:
    
    State()
        : name("Россия"),
        capital("Москва"),
        foundation(12, 12, 1991),
        area(17100000){
        cities.push_back(capital);
        std::cout << "Создано государство: " << name << "\n";
    }

    State(const std::string& n,
        const std::string& c,
        const FoundationDate& f,
        long double a,
        const std::vector<std::string>& cityList)
        : name(n), capital(c), foundation(f), area(a), cities(cityList){
        std::cout << "Создано государство: " << name << "\n";
    }

    State(const State& other)
        : name(other.name),
        capital(other.capital),
        foundation(other.foundation),
        area(other.area),
        cities(other.cities){
        std::cout << "Копия государства: " << name << "\n";
    }

    State& operator=(const State& other){
        if (this != &other){
            name = other.name;
            capital = other.capital;
            foundation = other.foundation;
            area = other.area;
            cities = other.cities;
        }
        return *this;
    }

    ~State(){
        std::cout << "Удалено государство: " << name << "\n";
    }

    State& operator+=(const State& other){
        name += "-" + other.name;
        area += other.area;

        if (other.area > area)
            capital = other.capital;

        for (const auto& city : other.cities){
            if (cityExists(city))
                cities.push_back(city + " (дубликат)");
            else
                cities.push_back(city);
        }

        return *this;
    }

    friend State operator+(State left, const State& right){
        left += right;
        return left;
    }

    friend State operator*(const State& a, const State& b){
        static bool seeded = false;
        if (!seeded){
            std::srand(static_cast<unsigned>(std::time(nullptr)));
            seeded = true;
        }

        State route;
        route.name = "Маршрут: " + a.name + " -> " + b.name;
        route.capital = "отсутствует";
        route.foundation = a.foundation;
        route.area = std::min(a.area, b.area);
        route.cities.clear();

        route.cities.push_back(a.capital);
        route.cities.push_back(b.capital);

        if (!a.cities.empty())
            route.cities.push_back(a.cities[std::rand() % a.cities.size()]);

        if (!b.cities.empty())
            route.cities.push_back(b.cities[std::rand() % b.cities.size()]);

        return route;
    }

    void print() const{
        std::cout << "\n Государство\n";
        std::cout << "Название: " << name << "\n";
        std::cout << "Столица: " << capital << "\n";
        std::cout << "Основано: " << foundation.toString() << "\n";
        std::cout << "Площадь: " << static_cast<long long>(area) << " кв.км\n";
        std::cout << "Города: ";

        for (const auto& city : cities)
            std::cout << city << " ";

        std::cout << "\n";
    }
};

void showMenu(){
    std::cout << "\n===== МЕНЮ =====\n"
        << "0 - Выход\n"
        << "1 - Показать список стран\n"
        << "2 - Добавить государство\n"
        << "3 - Операция +=\n"
        << "4 - Операция +\n"
        << "5 - Операция *\n"
        << "6 - Присваивание\n"
        << "Выбор: ";
}

int main(){
    setlocale(LC_ALL, "Russian");

    std::vector<State> states{
        State(),
        State("Япония", "Токио", FoundationDate(11, 2, -660), 377975, {"Токио", "Осака", "Киото"}),
        State("Испания", "Мадрид", FoundationDate(12, 10, 1492), 506030, {"Мадрид", "Капела", "Ланзада"}),
        State("Италия", "Рим", FoundationDate(2, 6, 1946), 302073, {"Рим", "Милан", "Венеция"}),
     
    };

    int choice;

    do{
        showMenu();
        std::cin >> choice;

        if (choice == 1){
            for (size_t i = 0; i < states.size(); ++i){
                std::cout << "\nИндекс: " << i;
                states[i].print();
            }
        }

        else if (choice == 2){
            std::string name, capital, city;
            int day, month, year;
            long double area;
            int count;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Название: ";
            std::getline(std::cin, name);

            std::cout << "Столица: ";
            std::getline(std::cin, capital);

            std::cout << "Дата основания (д м г): ";
            std::cin >> day >> month >> year;

            std::cout << "Площадь: ";
            std::cin >> area;

            std::cout << "Количество городов: ";
            std::cin >> count;

            std::vector<std::string> cityList;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            for (int i = 0; i < count; ++i){
                std::cout << "Город " << i + 1 << ": ";
                std::getline(std::cin, city);
                cityList.push_back(city);
            }

            states.emplace_back(name, capital, FoundationDate(day, month, year), area, cityList);
        }

        else if (choice == 3 || choice == 4 || choice == 5 || choice == 6){
            int a, b;
            std::cout << "Первый индекс: ";
            std::cin >> a;
            std::cout << "Второй индекс: ";
            std::cin >> b;

            if (a >= 0 && a < states.size() && b >= 0 && b < states.size()){
                if (choice == 3)
                    states[a] += states[b];
                else if (choice == 4)
                    states.push_back(states[a] + states[b]);
                else if (choice == 5)
                    states.push_back(states[a] * states[b]);
                else if (choice == 6)
                    states[a] = states[b];
            }
        }

    } while (choice != 0);

    return 0;
}
