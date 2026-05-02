#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstring>


int is_letter(unsigned char c)
{
    return (c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z') ||
        (c >= 192);
}

int is_letter_or_digit(unsigned char c)
{
    return is_letter(c) || (c >= '0' && c <= '9');
}

unsigned char to_lower(unsigned char c)
{
    if (c >= 'A' && c <= 'Z') return c + 32;
    if (c >= 192 && c <= 223) return c + 32;
    if (c == 168) return 184; 
    return c;
}

unsigned char to_upper(unsigned char c)
{
    if (c >= 'a' && c <= 'z') return c - 32;
    if (c >= 224 && c <= 255) return c - 32;
    if (c == 184) return 168; 
    return c;
}

int is_consonant(unsigned char c)
{
    unsigned char cons[] = {
        'б','в','г','д','ж','з','й','к','л','м','н',
        'п','р','с','т','ф','х','ц','ч','ш','щ'
    };

    for (int i = 0; i < 21; i++)
        if (c == cons[i])
            return 1;

    return 0;
}

int contains_letters(const char* word, unsigned char a, unsigned char b)
{
    int f1 = 0, f2 = 0;

    for (int i = 0; word[i]; i++)
    {
        if ((unsigned char)word[i] == a) f1 = 1;
        if ((unsigned char)word[i] == b) f2 = 1;
    }

    return f1 && f2;
}

int is_unique(char words[][101], int count, const char* w)
{
    for (int i = 0; i < count; i++)
        if (strcmp(words[i], w) == 0)
            return 0;
    return 1;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "Буква / Код:\n";

    for (int c = 'A'; c <= 'Z'; c++)
        std::cout << (char)c << " = " << c << "\n";
    for (int c = 'a'; c <= 'z'; c++)
        std::cout << (char)c << " = " << c << "\n";

    for (int c = 192; c <= 223; c++)
        std::cout << (char)c << " = " << c << "\n";
    for (int c = 224; c <= 255; c++)
        std::cout << (char)c << " = " << c << "\n";

    std::cout << (char)168 << " = 168\n";
    std::cout << (char)184 << " = 184\n"; 

    for (int c = '0'; c <= '9'; c++)
        std::cout << (char)c << " = " << c << "\n";

    const char punct[] = ".,!?;:-()\"'";
    for (int i = 0; i < sizeof(punct) - 1; i++)
        std::cout << punct[i] << " = " << (int)(unsigned char)punct[i] << "\n";

    char str[101];
    std::cout << "\nВведите строку:\n";
    std::cin.getline(str, 101);

    for (int i = 0; str[i]; i++)
    {
        unsigned char c = (unsigned char)str[i];

        unsigned char low = to_lower(c);

        if (is_consonant(low))
            str[i] = to_upper(c);
    }

    std::cout << "\nРезультат пункта 1:\n" << str << "\n";

    std::ifstream fin("input.txt");

    int N;
    char a, b;
    fin >> N >> a >> b;
    fin.close();

    unsigned char A = to_lower((unsigned char)a);
    unsigned char B = to_lower((unsigned char)b);

    std::ifstream ftext("text.txt", std::ios::binary);
    char text[10000];
    ftext.read(text, sizeof(text));
    int len = ftext.gcount();
    ftext.close();

    char words[1000][101];
    int word_count = 0;

    char temp[101];
    int k = 0;

    for (int i = 0; i <= len; i++)
    {
        unsigned char c = (unsigned char)text[i];

        if (is_letter_or_digit(c))
        {
            temp[k++] = to_lower(c);
        }
        else
        {
            if (k > 0)
            {
                temp[k] = '\0';

                int j = k - 1;
                while (j >= 0 && !is_letter((unsigned char)temp[j]))
                    j--;

                if (j >= 0)
                {
                    temp[j + 1] = '\0';

                    if (contains_letters(temp, A, B) &&
                        is_unique(words, word_count, temp))
                    {
                        strcpy(words[word_count++], temp);
                    }
                }

                k = 0;
            }
        }
    }


    for (int i = 0; i < word_count - 1; i++)
        for (int j = i + 1; j < word_count; j++)
            if (strlen(words[i]) > strlen(words[j]))
            {
                char tmp[101];
                strcpy(tmp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], tmp);
            }

    if (word_count > N)
        word_count = N;

    std::ofstream fout("result.txt");

    for (int i = 0; i < word_count; i++)
        fout << words[i] << "\n";

    fout.close();

    std::cout << "\nРезультат пункта 2 записан в result.txt\n";

    return 0;
}
