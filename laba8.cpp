#include <iostream>
#include <string>
#include <vector>
#include <limits>

struct Vagon{
    int number;
    std::string cargo;
    double weight;
    Vagon* next;

    Vagon(int n, const std::string& c, double w)
        : number(n), cargo(c), weight(w), next(nullptr){
    }
};

struct Locomotiv{
    int id;
    Vagon* next;

    Locomotiv(int i) : id(i), next(nullptr) {}
    Locomotiv() : id(0), next(nullptr) {}
};

void ClearVagons(Vagon* v){
    while (v){
        Vagon* t = v;
        v = v->next;
        delete t;
    }
}

void Print_All(const std::vector<Locomotiv>& locs){
    std::cout << "Локомотивы:\n";
    for (int i = 0; i < locs.size(); i++)
        std::cout << i + 1 << ". ID: " << locs[i].id << "\n";

    std::cout << "Составы:\n";
    for (int i = 0; i < locs.size(); i++){
        std::cout << "Состав " << i + 1 << " (ID: " << locs[i].id << ")\n";
        int count = 0;
        double weight = 0;

        for (Vagon* v = locs[i].next; v; v = v->next){
            count++;
            weight += v->weight;
        }

        std::cout << "   Вагонов: " << count << ", вес: " << weight << " т\n";
    }
}

void Add_Locomotiv(std::vector<Locomotiv>& locs){
    locs.emplace_back(locs.size() + 1);
    std::cout << "Локомотив создан!\n";
}

void Add_Vagon(std::vector<Locomotiv>& locs){
    int t;
    std::cout << "\nК какому составу добавить вагон? (1-" << locs.size() << "): ";
    std::cin >> t;

    if (t < 1 || t > locs.size()){
        std::cout << "Неверный номер!\n";
        return;
    }

    int num;
    double w;
    std::string c;

    std::cout << "Номер вагона: ";
    std::cin >> num;
    std::cin.ignore(10000, '\n');

    std::cout << "Груз: ";
    std::getline(std::cin, c);

    std::cout << "Вес: ";
    std::cin >> w;

    Vagon* v = new Vagon(num, c, w);
    v->next = locs[t - 1].next;
    locs[t - 1].next = v;

    std::cout << "Вагон добавлен!\n";
}

void Print_Train(const std::vector<Locomotiv>& locs){
    int t;
    std::cout << "\nВыберите состав (1-" << locs.size() << "): ";
    std::cin >> t;

    if (t < 1 || t > locs.size()){
        std::cout << "Неверный номер!\n";
        return;
    }

    std::cout << "Состав " << t << " (ID: " << locs[t - 1].id << ")Вагоны:\n";

    int count = 0;
    double weight = 0;

    for (Vagon* v = locs[t - 1].next; v; v = v->next){
        std::cout << "  " << v->number << ": " << v->cargo << " (" << v->weight << " т)\n";
        count++;
        weight += v->weight;
    }

    std::cout << "Всего: " << count << " вагонов, " << weight << " т\n";
}

void Delete_Last(std::vector<Locomotiv>& locs){
    int t;
    std::cout << "\nОт какого состава отцепить (1-" << locs.size() << "): ";
    std::cin >> t;

    if (t < 1 || t > locs.size()){
        std::cout << "Неверный номер!\n";
        return;
    }

    Vagon*& h = locs[t - 1].next;

    if (!h){
        std::cout << "В составе нет вагонов.\n";
        return;
    }

    if (!h->next){
        delete h;
        h = nullptr;
    }
    else{
        Vagon* v = h;
        while (v->next->next)
            v = v->next;

        delete v->next;
        v->next = nullptr;
    }

    std::cout << "Последний вагон отцеплен!\n";
}

void Init(std::vector<Locomotiv>& locs){
    Add_Locomotiv(locs);
    Add_Locomotiv(locs);
    Add_Locomotiv(locs);

    locs[0].next = new Vagon(101, "Уголь", 25.5);
    locs[0].next->next = new Vagon(102, "Нефть", 32.1);
    locs[0].next->next->next = new Vagon(103, "Зерно", 22.3);

    locs[1].next = new Vagon(201, "Лес", 18.7);
    locs[1].next->next = new Vagon(202, "Бензин", 31.8);

    locs[2].next = new Vagon(301, "Руда", 26.2);
    locs[2].next->next = new Vagon(302, "Продукты", 28.9);
    locs[2].next->next->next = new Vagon(303, "Контейнеры", 19.5);
}

int main(){
    setlocale(LC_ALL, "Russian");

    std::vector<Locomotiv> locs;
    Init(locs);

    int choice;
    do{
        std::cout << "---МЕНЮ---\n"<< "0. Выход\n1. Просмотр\n2. Создать вагон\n"<< "3. Создать локомотив\n4. Вывод состава\n5. Отцепить вагон\nВыберите: ";

        std::cin >> choice;

        switch (choice){
        case 1: Print_All(locs); break;
        case 2: Add_Vagon(locs); break;
        case 3: Add_Locomotiv(locs); break;
        case 4: Print_Train(locs); break;
        case 5: Delete_Last(locs); break;
        case 0: break;
        default: std::cout << "Неверный выбор!\n"; break;
        }

    } while (choice != 0);

    for (auto& l : locs)
        ClearVagons(l.next);

    return 0;
}
