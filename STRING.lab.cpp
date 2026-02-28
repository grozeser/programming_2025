#include <iostream>
#include <fstream>
#include <cstring>

const char LOWER_TO_UPPER_CASE_DIFF = 32;

char to_lower(char c) {
    if ('A' <= c && c <= 'Z')
        return c + LOWER_TO_UPPER_CASE_DIFF;
    if ('А' <= c && c <= 'Я')
        return c + LOWER_TO_UPPER_CASE_DIFF;
    return c;
}

bool is_digit(char c) {
    return ('0' <= c && c <= '9');
}

bool is_eng_alpha(char c) {
    return ('a' <= c && c <= 'z') ||
        ('A' <= c && c <= 'Z');
}

bool is_rus_alpha(char c) {
    return (unsigned char)c >= 192 &&
        (unsigned char)c <= 255;
}

bool is_alpha(char c) {
    return is_eng_alpha(c) || is_rus_alpha(c);
}

void copy_word(char dst[], char src[]) {
    int i = 0;
    while (src[i]) {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}

void print_table() {

    std::cout << "Английский алфавит (строчные)\n";
    for (char c = 'a'; c <= 'z'; ++c)
        std::cout << c << " " << (int)c << std::endl;

    std::cout << "\nАнглийский алфавит (заглавные)\n";
    for (char c = 'A'; c <= 'Z'; ++c)
        std::cout << c << " " << (int)c << std::endl;

    std::cout << "\nРусский алфавит (строчные)\n";
    for (int c = 224; c <= 255; ++c)
        std::cout << (char)c << " " << c << std::endl;

    std::cout << "\nРусский алфавит (заглавные)\n";
    for (int c = 192; c <= 223; ++c)
        std::cout << (char)c << " " << c << std::endl;

    std::cout << "\nЦифры\n";
    for (char c = '0'; c <= '9'; ++c)
        std::cout << c << " " << (int)c << std::endl;

    std::cout << "\nЗнаки препинания\n";
    for (char c = 33; c <= 47; ++c)
        std::cout << c << " " << (int)c << std::endl;
}

bool is_consonant(char c) {

    const char consonants[] =
        "бвгджзйклмнпрстфхцчшщ";

    c = to_lower(c);

    for (int i = 0; consonants[i]; ++i)
        if (c == consonants[i])
            return true;

    return false;
}

void make_consonants_upper(char str[]) {
    for (int i = 0; str[i]; ++i)
        if (is_consonant(str[i]))
            str[i] -= LOWER_TO_UPPER_CASE_DIFF;
}

bool valid_start(char c) {
    return is_alpha(c) || is_digit(c);
}

bool contains_letters(char word[], char a, char b) {

    bool f1 = false, f2 = false;

    for (int i = 0; word[i]; ++i) {
        char c = to_lower(word[i]);
        if (c == a) f1 = true;
        if (c == b) f2 = true;
    }

    return f1 && f2;
}

bool equal_words(char a[], char b[]) {

    int i = 0;
    while (a[i] && b[i]) {
        if (to_lower(a[i]) != to_lower(b[i]))
            return false;
        i++;
    }
    return a[i] == b[i];
}

int word_length(char w[]) {
    int i = 0;
    while (w[i]) i++;
    return i;
}

void sort_words(char words[][100], int count) {
   
    for (int i = 0; i < count; i++)
        for (int j = i + 1; j < count; j++)
            if (word_length(words[i]) >
                word_length(words[j])) {

                char tmp[100];
                copy_word(tmp, words[i]);
                copy_word(words[i], words[j]);
                copy_word(words[j], tmp);
            }
}

void process_text() {

    std::ifstream inText("text.txt");
    std::ifstream in("input.txt");
    std::ofstream out("result.txt");

    int N;
    char A, B;

    in >> N >> A >> B;

    A = to_lower(A);
    B = to_lower(B);

    char words[1000][100];
    int wordCount = 0;

    char line[256];

    while (inText.getline(line, 256)) {

        char word[100];
        int k = 0;

        for (int i = 0;; ++i) {

            if (valid_start(line[i])) {
                word[k++] = line[i];
            }
            else {
                if (k > 0) {

                    word[k] = '\0';

                    while (k > 0 &&
                        !is_alpha(word[k - 1]))
                        word[--k] = '\0';

                    if (contains_letters(word, A, B)) {

                        bool unique = true;

                        for (int j = 0; j < wordCount; j++)
                            if (equal_words(words[j], word))
                                unique = false;

                        if (unique)
                            copy_word(words[wordCount++], word);
                    }
                    k = 0;
                }
            }

            if (line[i] == '\0')
                break;
        }
    }

    sort_words(words, wordCount);

    for (int i = 0; i < wordCount && i < N; i++)
        out << words[i] << std::endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    print_table();

    char str[100];
    std::cout << "\nВведите строку\n";
    std::cin.getline(str, 100);

    make_consonants_upper(str);

    std::cout << str << std::endl;

    process_text();

    return 0;
}