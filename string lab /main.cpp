#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstring>

int is_ru_consonant(unsigned char c) {
    unsigned char cons[] = { 225,226,227,228,230,231,233,234,235,236,
    237,239,240,241,242,244,245,246,247,248,249 };

    for (int i = 0; i < 21; i++)
        if (c == cons[i])
            return 1;

    return 0;
}

unsigned char ru_to_upper(unsigned char c) {
    if (c >= 224 && c <= 255)
        return c - 32;

    if (c == 184)
        return 168;

    return c;
}

int is_letter_or_digit(unsigned char c) {
    if (c >= 'a' && c <= 'z') return 1;
    if (c >= 'A' && c <= 'Z') return 1;
    if (c >= '0' && c <= '9') return 1;
    if (c >= 192 && c <= 255) return 1;
    if (c == 168 || c == 184) return 1;
    return 0;
}

void to_lower_char(unsigned char& c) {
    if (c >= 'A' && c <= 'Z')
        c += 32;

    if (c >= 192 && c <= 223)
        c += 32;
}

int contains_letters(char* word, unsigned char a, unsigned char b) {
    int fa = 0, fb = 0;

    for (int i = 0; word[i]; i++) {
        unsigned char c = (unsigned char)word[i];

        to_lower_char(c);

        if (c == a) fa = 1;
        if (c == b) fb = 1;
    }

    return fa && fb;
}

int is_unique(char words[][101], int count, char* w) {
    for (int i = 0; i < count; i++)
        if (strcmp(words[i], w) == 0)
            return 0;

    return 1;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Таблица Буква/Код\n";

    for (int c = 'A'; c <= 'Z'; c++)
        std::cout << (char)c << " = " << c << "\n";

    for (int c = 'a'; c <= 'z'; c++)
        std::cout << (char)c << " = " << c << "\n";

    for (int c = 192; c <= 223; c++)
        std::cout << (char)c << " = " << c << "\n";

    for (int c = 224; c <= 255; c++)
        std::cout << (char)c << " = " << c << "\n";

    std::cout << (char)168 << " = " << 168 << "\n";
    std::cout << (char)184 << " = " << 184 << "\n";

    for (int c = '0'; c <= '9'; c++)
        std::cout << (char)c << " = " << c << "\n";

    const char punct[] = ".,!?;:-()\"'";
    for (int i = 0; i < sizeof(punct) - 1; i++)
        std::cout << punct[i] << " = " << (int)(unsigned char)punct[i] << "\n";

    char str[101];

    std::cout << "\nВведите строку:\n";
    std::cin.getline(str, 101);

    for (int i = 0; str[i]; i++) {
        unsigned char c = (unsigned char)str[i];

        if (c >= 'b' && c <= 'z') {
            if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y'))
                str[i] = c - 32;
        }
        else if (is_ru_consonant(c))
            str[i] = ru_to_upper(c);
    }

    std::cout << "\nРезультат:\n" << str << "\n";

    std::ifstream fin("input.txt");

    int N;
    char a, b;

    fin >> N >> a >> b;
    fin.close();

    unsigned char a_uc = (unsigned char)a;
    unsigned char b_uc = (unsigned char)b;

    to_lower_char(a_uc);
    to_lower_char(b_uc);

    std::ifstream ftext("text.txt", std::ios::binary);

    char text[10000];
    ftext.read(text, sizeof(text));

    int len = ftext.gcount();
    ftext.close();

    char words[1000][101];
    int word_count = 0;

    int k = 0;
    char current[101];

    for (int i = 0; i <= len; i++) {
        unsigned char c = (unsigned char)text[i];

        if (is_letter_or_digit(c)) {
            to_lower_char(c);
            current[k++] = c;
        }
        else {
            if (k > 0) {
                current[k] = '\0';
                strcpy(words[word_count++], current);
                k = 0;
            }
        }
    }

    char result[1000][101];
    int res_count = 0;

    for (int i = 0; i < word_count; i++) {
        if (contains_letters(words[i], a_uc, b_uc)) {
            if (is_unique(result, res_count, words[i])) {
                strcpy(result[res_count], words[i]);
                res_count++;
            }
        }
    }

    for (int i = 0; i < res_count - 1; i++)
        for (int j = i + 1; j < res_count; j++)
            if (strlen(result[i]) > strlen(result[j])) {
                char t[101];
                strcpy(t, result[i]);
                strcpy(result[i], result[j]);
                strcpy(result[j], t);
            }

    if (res_count > N)
        res_count = N;

    std::ofstream fout("result.txt");

    for (int i = 0; i < res_count; i++)
        fout << result[i] << "\n";

    fout.close();

    std::cout << "\nРезультат задачи 2 записан в result.txt\n";

    return 0;
}
