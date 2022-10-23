#include <iostream> 
using namespace std;

int N = 10; // размер массива 
class ochered
{
private:
    int* arr; // указатель на массив 
    int head, tail; //переменная для начала и конца очереди
public:
    ochered()
    {
        head = 0;
        tail = 0;
        arr = new int[N];
    }
    ochered(int m)
    {
        head = 0;
        tail = 0;
        arr = new int[m];
    }
    ~ochered() //деструктор 
    {
        delete[] arr;
    }
    void add_item(int a) //функция добавления элемента 
    {
        if (head == (tail + 1) % (N + 1)) //проверка наличия места в очереди 
            cout << "очередь переполнена!";
        else
        {
            arr[tail] = a; //записываем значение в массив
            tail = (tail + 1) % (N + 1); //присваиваем концу номер последнего элемента 
        }

    }
    void extra_item() //функция извлечения элемента 
    {
        if (head != tail) //проверка наличия элементов в очереди 
        {
            cout << arr[head]; //выводим на экран последний в очереди элемент 
            head = (head + 1) % (N + 1); //присваиваем началу номер следующего элемента 
        }
        else cout << "Очередь пуста";
    }
};
int main()
{
    int znach;
    bool r; //укажем логический тип данных для проверки логических условий 
    cout << "Элементов в массиве: ";
    cin >> N;
    ochered one(N);
    do {
        cout << "Ввод 1, извлечь 0 ";
        cin >> r;
        if (r)
        {
            cout << "Введите значение ";
            cin >> znach;
            one.add_item(znach);
        }
        else
        {
            cout << "Значение равно ";
            one.extra_item();
            cout << endl;
        }
    } 
    while (true);
    return 0;
}