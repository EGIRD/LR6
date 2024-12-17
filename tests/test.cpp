#include <iostream>
#include <gtest/gtest.h>
#include <sstream>
#include <string>

struct BracketCounts {
    int round_open = 0;
    int round_close = 0;
    int square_open = 0;
    int square_close = 0;
    int curly_open = 0;
    int curly_close = 0;
    int trian_open = 0;
    int trian_close = 0;
};

BracketCounts Task_1(const std::string &input) {
    BracketCounts counts;
    for (char ch : input) {
        switch (ch) {
            case '(': counts.round_open++; break;
            case ')': counts.round_close++; break;
            case '[': counts.square_open++; break;
            case ']': counts.square_close++; break;
            case '{': counts.curly_open++; break;
            case '}': counts.curly_close++; break;
            case '<': counts.trian_open++; break;
            case '>': counts.trian_close++; break;
        }
    }
    return counts;
}

bool Check(char* str1, char* str2) {
    int count[255] = {0};
    for(int i = 0; str1[i]; i++)
        count[(unsigned char)str1[i]]++;
    for(int j = 0; str2[j]; j++)
        count[(unsigned char)str2[j]]--;
    for(int i = 0; i < 255; i++)
        if(count[i] != 0)
            return false;
    return true;
}

void Task_3() {
    const int SIZE = 255;
    char* str1 = new char[SIZE];
    char* str2 = new char[SIZE];

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Вы выбрали задание 3\nВведите первую строку:\n";
    std::cin.getline(str1, SIZE);

    std::cout << "Введите вторую строку:\n";
    std::cin.getline(str2, SIZE);

    if(Check(str1, str2))
        std::cout << "Данные слова являются анаграммами\n";
    else
        std::cout << "Данные слова не являются анаграммами\n";

    delete[] str1;
    delete[] str2;
}

TEST(Task_1, test1) {
    BracketCounts counts = Task_1(std::string(40, '(') + std::string(40, ')') + std::string(20, '{') + std::string(20, '}') + std::string(10, '[') + std::string(10, ']') + std::string(10, '<') + std::string(10, '>'));
    EXPECT_EQ(counts.round_open, 40);
    EXPECT_EQ(counts.round_close, 40);
    EXPECT_EQ(counts.curly_open, 20);
    EXPECT_EQ(counts.curly_close, 20);
    EXPECT_EQ(counts.square_open, 10);
    EXPECT_EQ(counts.square_close, 10);
    EXPECT_EQ(counts.trian_open, 10);
    EXPECT_EQ(counts.trian_close, 10);
}

TEST(Task_1, test2) {
    BracketCounts counts = Task_1("()()()");
    EXPECT_EQ(counts.round_open, 3);
    EXPECT_EQ(counts.round_close, 3);
}

TEST(Task_1, test3)  {
    BracketCounts counts = Task_1("[][[]]");
    EXPECT_EQ(counts.square_open, 3);
    EXPECT_EQ(counts.square_close, 3);
}

TEST(Task_1, test4)  {
    BracketCounts counts = Task_1("{{{}}}");
    EXPECT_EQ(counts.curly_open, 3);
    EXPECT_EQ(counts.curly_close, 3);
}

TEST(Task_1, test5)  {
    BracketCounts counts = Task_1("<<>>");
    EXPECT_EQ(counts.trian_open, 2);
    EXPECT_EQ(counts.trian_close, 2);
}

TEST(Task_1, test6)  {
    BracketCounts counts = Task_1("(()[{}<><>])");
    EXPECT_EQ(counts.round_open, 2);
    EXPECT_EQ(counts.round_close, 2);
    EXPECT_EQ(counts.square_open, 1);
    EXPECT_EQ(counts.square_close, 1);
    EXPECT_EQ(counts.curly_open, 1);
    EXPECT_EQ(counts.curly_close, 1);
    EXPECT_EQ(counts.trian_open, 2);
    EXPECT_EQ(counts.trian_close, 2);
}

TEST(Task_1, test7)  {
    BracketCounts counts = Task_1("([{}<>)]");
    EXPECT_EQ(counts.round_open, 1);
    EXPECT_EQ(counts.round_close, 1);
    EXPECT_EQ(counts.square_open, 1);
    EXPECT_EQ(counts.square_close, 1);
    EXPECT_EQ(counts.curly_open, 1);
    EXPECT_EQ(counts.curly_close, 1);
    EXPECT_EQ(counts.trian_open, 1);
    EXPECT_EQ(counts.trian_close, 1);
}

TEST(Task_1, test8)  {
    BracketCounts counts = Task_1(")))]]]}}}>>>");
    EXPECT_EQ(counts.round_open, 0);
    EXPECT_EQ(counts.round_close, 3);
    EXPECT_EQ(counts.square_open, 0);
    EXPECT_EQ(counts.square_close, 3);
    EXPECT_EQ(counts.curly_open, 0);
    EXPECT_EQ(counts.curly_close, 3);
    EXPECT_EQ(counts.trian_open, 0);
    EXPECT_EQ(counts.trian_close, 3);
}

TEST(Task_1, test9)  {
    BracketCounts counts = Task_1("([{}<>)]");
    EXPECT_EQ(counts.round_open, 1);
    EXPECT_EQ(counts.round_close, 1);
    EXPECT_EQ(counts.square_open, 1);
    EXPECT_EQ(counts.square_close, 1);
    EXPECT_EQ(counts.curly_open, 1);
    EXPECT_EQ(counts.curly_close, 1);
    EXPECT_EQ(counts.trian_open, 1);
    EXPECT_EQ(counts.trian_close, 1);
}

TEST(Task_1, test10)  {
    BracketCounts counts = Task_1("([{}<>()]){[<>()]}");
    EXPECT_EQ(counts.round_open, 3);
    EXPECT_EQ(counts.round_close, 3);
    EXPECT_EQ(counts.square_open, 2);
    EXPECT_EQ(counts.square_close, 2);
    EXPECT_EQ(counts.curly_open, 2);
    EXPECT_EQ(counts.curly_close, 2);
    EXPECT_EQ(counts.trian_open, 2);
    EXPECT_EQ(counts.trian_close, 2);
}

TEST(Task_2, test1) {
    BracketCounts counts = Task_1(std::string(40, '(') + std::string(40, ')') + std::string(20, '{') + std::string(20, '}') + std::string(10, '[') + std::string(10, ']') + std::string(10, '<') + std::string(10, '>'));
    EXPECT_EQ(counts.round_open, 40);
    EXPECT_EQ(counts.round_close, 40);
    EXPECT_EQ(counts.curly_open, 20);
    EXPECT_EQ(counts.curly_close, 20);
    EXPECT_EQ(counts.square_open, 10);
    EXPECT_EQ(counts.square_close, 10);
    EXPECT_EQ(counts.trian_open, 10);
    EXPECT_EQ(counts.trian_close, 10);
}

TEST(Task_2, test2) {
    BracketCounts counts = Task_1("()()()");
    EXPECT_EQ(counts.round_open, 3);
    EXPECT_EQ(counts.round_close, 3);
}

TEST(Task_2, test3)  {
    BracketCounts counts = Task_1("[][[]]");
    EXPECT_EQ(counts.square_open, 3);
    EXPECT_EQ(counts.square_close, 3);
}

TEST(Task_2, test4)  {
    BracketCounts counts = Task_1("{{{}}}");
    EXPECT_EQ(counts.curly_open, 3);
    EXPECT_EQ(counts.curly_close, 3);
}

TEST(Task_2, test5)  {
    BracketCounts counts = Task_1("<<>>");
    EXPECT_EQ(counts.trian_open, 2);
    EXPECT_EQ(counts.trian_close, 2);
}

TEST(Task_2, test6)  {
    BracketCounts counts = Task_1("(()[{}<><>])");
    EXPECT_EQ(counts.round_open, 2);
    EXPECT_EQ(counts.round_close, 2);
    EXPECT_EQ(counts.square_open, 1);
    EXPECT_EQ(counts.square_close, 1);
    EXPECT_EQ(counts.curly_open, 1);
    EXPECT_EQ(counts.curly_close, 1);
    EXPECT_EQ(counts.trian_open, 2);
    EXPECT_EQ(counts.trian_close, 2);
}

TEST(Task_2, test7)  {
    BracketCounts counts = Task_1("([{}<>)]");
    EXPECT_EQ(counts.round_open, 1);
    EXPECT_EQ(counts.round_close, 1);
    EXPECT_EQ(counts.square_open, 1);
    EXPECT_EQ(counts.square_close, 1);
    EXPECT_EQ(counts.curly_open, 1);
    EXPECT_EQ(counts.curly_close, 1);
    EXPECT_EQ(counts.trian_open, 1);
    EXPECT_EQ(counts.trian_close, 1);
}

TEST(Task_2, test8)  {
    BracketCounts counts = Task_1(")))]]]}}}>>>");
    EXPECT_EQ(counts.round_open, 0);
    EXPECT_EQ(counts.round_close, 3);
    EXPECT_EQ(counts.square_open, 0);
    EXPECT_EQ(counts.square_close, 3);
    EXPECT_EQ(counts.curly_open, 0);
    EXPECT_EQ(counts.curly_close, 3);
    EXPECT_EQ(counts.trian_open, 0);
    EXPECT_EQ(counts.trian_close, 3);
}

TEST(Task_2, test9)  {
    BracketCounts counts = Task_1("([{}<>)]");
    EXPECT_EQ(counts.round_open, 1);
    EXPECT_EQ(counts.round_close, 1);
    EXPECT_EQ(counts.square_open, 1);
    EXPECT_EQ(counts.square_close, 1);
    EXPECT_EQ(counts.curly_open, 1);
    EXPECT_EQ(counts.curly_close, 1);
    EXPECT_EQ(counts.trian_open, 1);
    EXPECT_EQ(counts.trian_close, 1);
}

TEST(Task_2, test10)  {
    BracketCounts counts = Task_1("([{}<>()]){[<>()]}");
    EXPECT_EQ(counts.round_open, 3);
    EXPECT_EQ(counts.round_close, 3);
    EXPECT_EQ(counts.square_open, 2);
    EXPECT_EQ(counts.square_close, 2);
    EXPECT_EQ(counts.curly_open, 2);
    EXPECT_EQ(counts.curly_close, 2);
    EXPECT_EQ(counts.trian_open, 2);
    EXPECT_EQ(counts.trian_close, 2);
}

TEST(Task_3, test1) {
    char str1[] = "listen";
    char str2[] = "silent";
    EXPECT_TRUE(Check(str1, str2));
}

TEST(Task_3, test2) {
    char str1[] = "hello";
    char str2[] = "world";
    EXPECT_FALSE(Check(str1, str2));
}

TEST(Task_3, test3) {
    char str1[] = "";
    char str2[] = "";
    EXPECT_TRUE(Check(str1, str2));
}

TEST(Task_3, test4) {
    char str1[] = "abc";
    char str2[] = "abcd";
    EXPECT_FALSE(Check(str1, str2));
}

TEST(Task_3, test5) {
    char str1[] = "Listen";
    char str2[] = "Silent";
    EXPECT_FALSE(Check(str1, str2));
}

TEST(Task_3, test6) {
    char str1[] = "a!b@c#";
    char str2[] = "c#b@a!";
    EXPECT_TRUE(Check(str1, str2));
}

TEST(Task_3, test7) {
    char str1[] = "123abc";
    char str2[] = "cba321";
    EXPECT_TRUE(Check(str1, str2));
}

TEST(Task_3, test8) {
    char str1[] = "a";
    char str2[] = "a";
    EXPECT_TRUE(Check(str1, str2));
}

TEST(Task_3, test9) {
    char str1[] = "a";
    char str2[] = "b";
    EXPECT_FALSE(Check(str1, str2));
}

TEST(Task_3, test10) {
    char str1[] = "a.b,c";
    char str2[] = "c,b.a";
    EXPECT_TRUE(Check(str1, str2));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}






