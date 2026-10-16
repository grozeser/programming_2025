# Лабораторные работы №15, №16, №17
# №15 — односвязный список
# №16 — двусвязный список
# №17 — циклический список
# Сортировка: по возрастанию вещественной (дробной) части элементов


def sort_key(x):
    """Условие сортировки: вещественная (дробная) часть числа.
    3.75 -> 0.75, -2.4 -> 0.4, 5.0 -> 0.0"""
    x = abs(x)
    return x - int(x)


# ---------- №15: Односвязный список ----------

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None      # ссылка на следующий элемент


class SinglyLinkedList:
    def __init__(self):
        self.head = None      # первый элемент

    def add(self, data):
        """Добавление в конец списка."""
        new = Node(data)
        if self.head is None:
            self.head = new
            return
        cur = self.head
        while cur.next is not None:
            cur = cur.next
        cur.next = new

    def remove(self, data):
        """Удаление первого элемента с таким значением."""
        if self.head is None:
            return False
        if self.head.data == data:
            self.head = self.head.next
            return True
        cur = self.head
        while cur.next is not None:
            if cur.next.data == data:
                cur.next = cur.next.next    # "перепрыгиваем" удаляемый
                return True
            cur = cur.next
        return False

    def sort(self):
        """Сортировка пузырьком: меняем местами значения в узлах."""
        if self.head is None:
            return
        swapped = True
        while swapped:
            swapped = False
            cur = self.head
            while cur.next is not None:
                if sort_key(cur.data) > sort_key(cur.next.data):
                    cur.data, cur.next.data = cur.next.data, cur.data
                    swapped = True
                cur = cur.next

    def show(self):
        items = []
        cur = self.head
        while cur is not None:
            items.append(str(cur.data))
            cur = cur.next
        print("Список:", " -> ".join(items) if items else "(пусто)")


# ---------- №16: Двусвязный список ----------

class DNode:
    def __init__(self, data):
        self.data = data
        self.next = None      # ссылка вперёд
        self.prev = None      # ссылка назад


class DoublyLinkedList:
    def __init__(self):
        self.head = None      # первый элемент
        self.tail = None      # последний элемент

    def add(self, data):
        """Добавление в конец — сразу через tail, без прохода по списку."""
        new = DNode(data)
        if self.head is None:
            self.head = self.tail = new
        else:
            new.prev = self.tail
            self.tail.next = new
            self.tail = new

    def remove(self, data):
        cur = self.head
        while cur is not None:
            if cur.data == data:
                if cur.prev is not None:
                    cur.prev.next = cur.next
                else:
                    self.head = cur.next        # удаляем первый
                if cur.next is not None:
                    cur.next.prev = cur.prev
                else:
                    self.tail = cur.prev        # удаляем последний
                return True
            cur = cur.next
        return False

    def sort(self):
        if self.head is None:
            return
        swapped = True
        while swapped:
            swapped = False
            cur = self.head
            while cur.next is not None:
                if sort_key(cur.data) > sort_key(cur.next.data):
                    cur.data, cur.next.data = cur.next.data, cur.data
                    swapped = True
                cur = cur.next

    def show(self):
        forward = []
        cur = self.head
        while cur is not None:
            forward.append(str(cur.data))
            cur = cur.next
        backward = []
        cur = self.tail
        while cur is not None:
            backward.append(str(cur.data))
            cur = cur.prev
        if not forward:
            print("Список: (пусто)")
        else:
            print("Вперёд:", " <-> ".join(forward))
            print("Назад: ", " <-> ".join(backward))


# ---------- №17: Циклический список ----------

class CircularLinkedList:
    def __init__(self):
        self.tail = None      # последний элемент; tail.next — это первый

    def add(self, data):
        new = Node(data)
        if self.tail is None:
            new.next = new            # один элемент ссылается сам на себя
            self.tail = new
        else:
            new.next = self.tail.next  # новый указывает на первый
            self.tail.next = new
            self.tail = new

    def remove(self, data):
        if self.tail is None:
            return False
        prev = self.tail
        cur = self.tail.next          # начинаем с первого
        while True:
            if cur.data == data:
                if cur == prev:               # был единственный элемент
                    self.tail = None
                else:
                    prev.next = cur.next
                    if cur == self.tail:      # удалили последний
                        self.tail = prev
                return True
            prev = cur
            cur = cur.next
            if cur == self.tail.next:         # сделали полный круг
                return False

    def sort(self):
        if self.tail is None:
            return
        first = self.tail.next
        swapped = True
        while swapped:
            swapped = False
            cur = first
            while cur.next != first:          # идём до конца круга
                if sort_key(cur.data) > sort_key(cur.next.data):
                    cur.data, cur.next.data = cur.next.data, cur.data
                    swapped = True
                cur = cur.next

    def show(self):
        if self.tail is None:
            print("Список: (пусто)")
            return
        items = []
        cur = self.tail.next
        while True:
            items.append(str(cur.data))
            cur = cur.next
            if cur == self.tail.next:
                break
        print("Список:", " -> ".join(items), "-> (снова", items[0] + ")")


# ---------- Ввод и меню ----------

def read_number(prompt):
    while True:
        try:
            return float(input(prompt).replace(",", "."))
        except ValueError:
            print("Ошибка: введите вещественное число.")


def read_sequence(lst):
    """N заранее неизвестно — вводим числа, пока не будет пустой строки."""
    print("Вводите вещественные числа (можно по несколько через пробел).")
    print("Пустая строка — конец ввода.")
    while True:
        line = input("> ").strip()
        if line == "":
            break
        for part in line.replace(",", ".").split():
            try:
                lst.add(float(part))
            except ValueError:
                print(f"'{part}' — не число, пропущено.")


def menu(lst):
    while True:
        print("\n1 — добавить элемент")
        print("2 — удалить элемент")
        print("3 — сортировать (по возрастанию дробной части)")
        print("4 — показать список")
        print("0 — выход")
        choice = input("Выбор: ").strip()
        if choice == "1":
            lst.add(read_number("Число: "))
            lst.show()
        elif choice == "2":
            x = read_number("Какое число удалить: ")
            if lst.remove(x):
                print("Удалено.")
            else:
                print("Такого элемента нет.")
            lst.show()
        elif choice == "3":
            lst.sort()
            print("Отсортировано.")
            lst.show()
        elif choice == "4":
            lst.show()
        elif choice == "0":
            break
        else:
            print("Нет такого пункта.")


def main():
    print("Выберите лабораторную:")
    print("15 — односвязный список")
    print("16 — двусвязный список")
    print("17 — циклический список")
    kinds = {"15": SinglyLinkedList, "16": DoublyLinkedList, "17": CircularLinkedList}
    choice = input("Номер: ").strip()
    while choice not in kinds:
        choice = input("Введите 15, 16 или 17: ").strip()

    lst = kinds[choice]()
    read_sequence(lst)
    lst.show()
    menu(lst)


if __name__ == "__main__":
    main()
