// д/з: Из методички 3 № 4, 6, 12, 16.
#include <iostream>
#include <vector>
using namespace std;
float dz_4(int y = 10, int x = 1 );// x - счего начинается отсчет, y - последене зачение для формулы
float dz_6(int y = 50, int x = 1 );// x - счего начинается отсчет, y - последене зачение для формулы 
vector<int> dz_12(int y = 99, int x = 10 );// x - первоезначение, y - последнее значение 
int dz_16(int y = 9999, int x = 1000);// x - первоезначение, y - последнее значение 
int sum_num(int x); // выдаёт сумму цифр в числе
int count_num(int x);// считает сколько цифр в числе

int main()
{
    setlocale(LC_ALL, "RUS");
    int dz;//  номер домашнего задания
    bool work = true;// отвечанет за выход из программы, пока true программа работает
    cout << "привет!\n";
    while (work)
    {
        cout << "выбери дз, написав номер с 1 по 4. Для выхода из программы введите 5.\n";
        cin >> dz;
        switch (dz)
        {
        case 1:
            cout << "1/sin(1) + ... + 1/(sin(1) + ... + sin(10))\n";
            cout << dz_4() << "\n";// запуск подпрограммы для выполнения 4 задания
            break;
        case 2:
            cout << "sqrt(1+sqrt(2+...sqrt(50)\n";
            cout << dz_6() << "\n";// запуск подпрограммы для выполнения 6 задания
            break;
        case 3:
            cout << "Найти все двузначные числа, которые кратны 4 и у которых сумма цифр также кратна 4\n";
            for (auto i : dz_12())// запуск подпрограммы для выполнения 12 задания
            {
                cout << i << "\n";
            }
            break;
        case 4:
            cout << "Найти четырёхзначное число, которое при делении на 133 даёт в остатке 125, а при делении на 134 даёт в остатке 111\n";
            cout << dz_16() << "\n";
            break;
        case 5:
            work = false;
            cout << "До свидания\n";
            break;
        default:
            cout << "вы ошиблись\n";
            break;
        }
    }
}


float dz_4(int y, int x) 
{
    float rezult = 0;
    float sin_sum = 0;
    int end;
    for (int i = x; i < y + 1; i ++)
    {
        end = i;
        sin_sum = 0;
        for (int i = x; i < end + 1; i++)
        {
            sin_sum += sin(i);
        }
        rezult += 1/sin_sum;
    }
    return rezult;

}


float dz_6(int y, int x)
{
    float rezult = sqrt(y);
    for (int i = y - 1; i > x - 1; i--)
    {
        rezult = sqrt(i + rezult);  
    }
    return rezult;
}


vector<int> dz_12(int y, int x)
{
    vector<int> arr;
    float rezult = 0;
    for (int i = x; i < y + 1; i++)
    {
        if (i % 4 == 0 && sum_num(i) % 4 == 0)
            arr.push_back(i);
    } 
    return arr;
}
 

int dz_16(int y, int x) 
{
    int rezult = 0;
    for (int i = x; i < y + 1; i++) 
    {
        if (i % 133 == 125 && i % 134 == 111)
            rezult = i;
        
    }
    return rezult;
}


int sum_num(int x)
{
    int sum = 0;
    int num = count_num(x)-1;
    x = abs(x);
    for (int i = num; i > -1; i --)
    {
        if (i == 0)
            sum += x;
        else
            sum += int(x / pow(10, i));
            x = abs(x - int(x / pow(10, i)) * pow(10, i));
    }
    return sum;
}


int count_num(int x)
{
    int count = 0;
    while (x != 0)
    {
        x /= 10;
        count++; 
    }
    return count;
}