# Лабораторные работы №13 и №14
# №13 — хеш-таблица "с наложением" (открытая адресация, линейное пробирование)
# №14 — хеш-таблица "со списками" (метод цепочек)

import re

INPUT_FILE = "input.txt"
OUTPUT_FILE = "output.txt"
CHAIN_TABLE_SIZE = 101   # размер таблицы для метода цепочек (простое число)

# Слово = последовательность русских или английских букв
WORD_RE = re.compile(r"[a-zA-Zа-яА-ЯёЁ]+")


# ---------- Общие функции ----------

def hash_function(word, size):
    """Полиномиальная хеш-функция: h = (h * 31 + код символа) mod size."""
    h = 0
    for ch in word:
        h = (h * 31 + ord(ch)) % size
    return h


def is_prime(n):
    if n < 2:
        return False
    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1
    return True


def next_prime(n):
    """Ближайшее простое число >= n."""
    while not is_prime(n):
        n += 1
    return n


def read_words(filename):
    """Построчно читает файл и выдаёт слова по одному (текст любой длины)."""
    with open(filename, encoding="utf-8") as f:
        for line in f:
            for word in WORD_RE.findall(line):
                yield word.lower()


# ---------- Лаба №13: с наложением ----------

class HashTableOpen:
    def __init__(self, size=11):
        self.size = size
        self.keys = [None] * size   # слова
        self.counts = [0] * size    # сколько раз слово встретилось
        self.count = 0              # число занятых ячеек
        self.collisions = 0         # число коллизий

    def _place(self, word, cnt):
        """Кладёт слово в таблицу методом линейного пробирования."""
        i = hash_function(word, self.size)
        while self.keys[i] is not None and self.keys[i] != word:
            self.collisions += 1
            i = (i + 1) % self.size     # ячейка занята — идём в следующую
        if self.keys[i] is None:
            self.keys[i] = word
            self.count += 1
        self.counts[i] += cnt

    def insert(self, word):
        # Если таблица заполнена больше чем на 70% — увеличиваем её
        if (self.count + 1) / self.size > 0.7:
            self._resize()
        self._place(word, 1)

    def _resize(self):
        old = [(k, c) for k, c in zip(self.keys, self.counts) if k is not None]
        self.size = next_prime(self.size * 2)
        self.keys = [None] * self.size
        self.counts = [0] * self.size
        self.count = 0
        self.collisions = 0
        for k, c in old:
            self._place(k, c)

    def find(self, word):
        i = hash_function(word, self.size)
        while self.keys[i] is not None:
            if self.keys[i] == word:
                return self.counts[i]
            i = (i + 1) % self.size
        return 0

    def write(self, f):
        f.write("=== Лаба №13: хеш-таблица с наложением (линейное пробирование) ===\n")
        f.write("Хеш-функция: h = (h * 31 + ord(c)) mod size\n")
        f.write(f"Размер таблицы: {self.size}\n")
        f.write(f"Уникальных слов: {self.count}\n")
        f.write(f"Коэффициент заполнения: {self.count / self.size:.2f}\n")
        f.write(f"Коллизий: {self.collisions}\n\n")
        f.write(f"{'Индекс':>6} | {'Хеш':>6} | {'Кол-во':>6} | Слово\n")
        f.write("-" * 45 + "\n")
        for i in range(self.size):
            if self.keys[i] is None:
                f.write(f"{i:>6} | {'-':>6} | {'-':>6} | (пусто)\n")
            else:
                h = hash_function(self.keys[i], self.size)
                f.write(f"{i:>6} | {h:>6} | {self.counts[i]:>6} | {self.keys[i]}\n")


# ---------- Лаба №14: со списками ----------

class HashTableChain:
    def __init__(self, size=CHAIN_TABLE_SIZE):
        self.size = size
        # Каждая ячейка — список пар [слово, количество]
        self.table = [[] for _ in range(size)]
        self.count = 0

    def insert(self, word):
        i = hash_function(word, self.size)
        for pair in self.table[i]:
            if pair[0] == word:       # слово уже есть — увеличиваем счётчик
                pair[1] += 1
                return
        self.table[i].append([word, 1])   # нет — добавляем в конец списка
        self.count += 1

    def find(self, word):
        i = hash_function(word, self.size)
        for w, c in self.table[i]:
            if w == word:
                return c
        return 0

    def write(self, f):
        used = sum(1 for chain in self.table if chain)
        longest = max(len(chain) for chain in self.table)
        f.write("=== Лаба №14: хеш-таблица со списками (метод цепочек) ===\n")
        f.write("Хеш-функция: h = (h * 31 + ord(c)) mod size\n")
        f.write(f"Размер таблицы: {self.size}\n")
        f.write(f"Уникальных слов: {self.count}\n")
        f.write(f"Занято ячеек: {used}\n")
        f.write(f"Самая длинная цепочка: {longest}\n\n")
        for i, chain in enumerate(self.table):
            if chain:
                items = " -> ".join(f"{w}({c})" for w, c in chain)
            else:
                items = "(пусто)"
            f.write(f"[{i:>3}]: {items}\n")


# ---------- Главная программа ----------

def main():
    open_table = HashTableOpen()
    chain_table = HashTableChain()

    for word in read_words(INPUT_FILE):
        open_table.insert(word)
        chain_table.insert(word)

    with open(OUTPUT_FILE, "w", encoding="utf-8") as f:
        open_table.write(f)
        f.write("\n\n")
        chain_table.write(f)

    print(f"Готово. Обе таблицы записаны в {OUTPUT_FILE}")


if __name__ == "__main__":
    main()
