#include <iostream>
#include <Windows.h>

int setupconsole();
int setconsoletitle();
int setconsolecolour();
int menu();
int selectchoice(std::string input);
int askfornumbers();
int calculator(int number1, int number2);

enum Calculator 
{
    Division, Multiplication, Addition, Subtraction
};

Calculator CalculatorType;

int main()
{
    setupconsole();
    menu();
}

int setupconsole()
{
    system("cls");
    setconsoletitle();
    setconsolecolour();
    return 0;
}

int setconsoletitle()
{
    SetConsoleTitle(TEXT("Fast Calculator"));
    return 0;
}

int setconsolecolour()
{
    HANDLE hConsole;
    int colour = 15;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    FlushConsoleInputBuffer(hConsole);
    SetConsoleTextAttribute(hConsole, colour);
    return 0;
}

int menu()
{
    std::string input;
    std::cout << "Divide, multiply, add, subtract. D/M/A/S: ";
    std::cin >> input;
    selectchoice(input);
    return 0;
}

int selectchoice(std::string input)
{
    if (input == "D")
    {
        CalculatorType = Division;
    }
    else if (input == "M")
    {
        CalculatorType = Multiplication;
    }
    else if (input == "A")
    {
        CalculatorType = Addition;
    }
    else if (input == "S")
    {
        CalculatorType = Subtraction;
    }
    askfornumbers();
    return 0;
}

int askfornumbers()
{
    int number1;
    int number2;
    std::string input;

    std::cout << "\nEnter the first number: ";
    std::cin >> number1;
    std::cout << "Enter the second number: ";
    std::cin >> number2;

    std::cout << "\nAnswer = " << calculator(number1, number2);
    std::cin >> input;

    return 0;
}

int calculator(int number1, int number2)
{
    int answer;
    switch (CalculatorType)
    {
        case Division:
            answer = number1 / number2;
        break;
        case Multiplication:
            answer = number1 * number2;
            break;
        case Addition:
            answer = number1 + number2;
            break;
        case Subtraction:
            answer = number1 - number2;
            break;
    }
    return answer;
}