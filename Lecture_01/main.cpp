1111111111111111111111111111111111111111111111111111111111111111111111111111111

s = input("Введите строку: ")

stack = []
ok = True

for c in s:
    if c in "([{":
        stack.append(c)
    else:
        if len(stack) == 0:
            ok = False
            break
        last = stack.pop()
        if c == ")" and last != "(":
            ok = False
            break
        if c == "]" and last != "[":
            ok = False
            break
        if c == "}" and last != "{":
            ok = False
            break

if len(stack) != 0:
    ok = False

if ok:
    print("Строка существует")
else:
    print("Строка не существует")


222222222222222222222222222222222222222222222222222222222222222222222222222222
numbers = []
ops = []
error = ""     


def apply():
    # берём одну операцию и два последних числа
    global error
    op = ops.pop()
    b = numbers.pop()
    a = numbers.pop()
    if op == "+":
        numbers.append(a + b)
    elif op == "-":
        numbers.append(a - b)
    elif op == "*":
        numbers.append(a * b)
    else:
        if b == 0:
            error = "деление на ноль"
            numbers.append(0)
        else:
            numbers.append(a / b)


s = input("Введите выражение: ").replace(" ", "")

if not s.endswith("="):
    print("Ошибка: выражение должно заканчиваться знаком =")
else:
    s = s[:-1]              # убираем "="
    expect_number = True    # ждём число (или "(")? Если False, ждём операцию
    i = 0

    while i < len(s) and error == "":
        c = s[i]

        if c in "0123456789.":
            if not expect_number:
                error = "пропущена операция"
            else:
                j = i
                while j < len(s) and s[j] in "0123456789.":
                    j = j + 1
                text = s[i:j]
                if text.count(".") > 1 or text == ".":
                    error = "неверная запись числа"
                else:
                    numbers.append(float(text))
                    expect_number = False
                i = j - 1

        elif c == "(":
            if not expect_number:
                error = "пропущена операция перед скобкой"
            else:
                ops.append(c)

        elif c == ")":
            if expect_number:
                error = "пропущено число перед закрывающей скобкой"
            else:
                while len(ops) > 0 and ops[-1] != "(" and error == "":
                    apply()
                if error == "":
                    if len(ops) == 0:
                        error = "лишняя закрывающая скобка"
                    else:
                        ops.pop()   # убираем "("

        elif c in "+-*/":
            if expect_number:
                error = "две операции подряд или операция в начале"
            else:
                # выполняем операции из стека, которые важнее или равны по приоритету
                while len(ops) > 0 and error == "":
                    top = ops[-1]
                    if top != "(" and (top in "*/" or c in "+-"):
                        apply()
                    else:
                        break
                if error == "":
                    ops.append(c)
                    expect_number = True

        else:
            error = "недопустимый символ " + c

        i = i + 1

    if error == "" and expect_number:
        error = "выражение не закончено"

    while len(ops) > 0 and error == "":
        if ops[-1] == "(":
            error = "не закрыта скобка"
        else:
            apply()

    if error != "":
        print("Ошибка:", error)
    else:
        result = numbers[0]
        if result == int(result):
            result = int(result)
        print("Результат:", result)



333333333333333333333333333333333333333333333333333333333333333333333333333333

x = int(input("Введите число x: "))

result = []

a = 1
while a <= x:          # a = 3^K
    b = a
    while b <= x:      # b = 3^K * 5^L
        c = b
        while c <= x:  # c = 3^K * 5^L * 7^M
            result.append(c)
            c = c * 7
        b = b * 5
    a = a * 3

result.sort()

for n in result:
    print(n)
44444444444444444444444444444444444444444444444444444444444444444444444
# 4 Сортировка прочёсыванием
def a_sort(a):
    n = len(a)
    gap = n
    swapped = True
    while gap > 1 or swapped:
        gap = int(gap / 1.247)
        if gap < 1:
            gap = 1
        swapped = False
        for i in range(n - gap):
            if a[i] > a[i + gap]:
                tmp = a[i]
                a[i] = a[i + gap]
                a[i + gap] = tmp
                swapped = True
    return a


# 5 Сортировка вставками
def b_sort(a):
    for i in range(1, len(a)):
        x = a[i]
        j = i - 1
        while j >= 0 and a[j] > x:
            a[j + 1] = a[j]
            j = j - 1
        a[j + 1] = x
    return a


# 6 Сортировка выбором
def c_sort(a):
    n = len(a)
    for i in range(n - 1):
        m = i
        for j in range(i + 1, n):
            if a[j] < a[m]:
                m = j
        tmp = a[i]
        a[i] = a[m]
        a[m] = tmp
    return a


# 7 Сортировка Шелла
def d_sort(a):
    n = len(a)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            x = a[i]
            j = i
            while j >= gap and a[j - gap] > x:
                a[j] = a[j - gap]
                j = j - gap
            a[j] = x
        gap = gap // 2
    return a



choice = input("Выберите номер лабораторной работы (4-7): ")
a = []
for t in input("Введите числа через пробел: ").split():
    a.append(float(t))

if choice == "4":
    a = a_sort(a)
elif choice == "5":
    a = b_sort(a)
elif choice == "6":
    a = c_sort(a)
else:
    a = d_sort(a)

for x in a:
    if x == int(x):
        x = int(x)
    print(x, end=" ")
print()



