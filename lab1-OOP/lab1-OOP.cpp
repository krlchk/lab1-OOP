#include <iostream>

#include "Date.h"
#include "Time.h"
#include "DateTime.h"
#include "TimeSpan.h"

#include "ArrayList.h"

using namespace std;

template<typename T>
void selectionSort(T* arr, int length)
{
    int min_index;

    for (int i = 0; i < length - 1; i++)
    {
        min_index = i;
        for (int j = i + 1; j < length; j++)
        {
            if (arr[j] < arr[min_index])
                min_index = j;
        }

        if (min_index != i)
            swap(arr[min_index], arr[i]);
    }
}

int main()
{
    srand((unsigned int)time(0));
    //ArrayList<int> arr;
    //ArrayList<Time> arr;
    ArrayList<Date> arr;
    for (size_t i = 0; i < 5; i++)
    {
        //arr.append(rand() % 90 + 10);
        //cout << arr[i] << " ";
        //arr.append(Time(rand() % 24, rand() % 60, rand() % 60));
        //cout << arr[i].toString() << " ";
        arr.append(Date(rand() % 10 + 2015, rand() % 12 + 1, rand() % 28 + 1));
        cout << arr[i].toString() << " ";
    }
    cout << endl;
    arr.swapSort();
    for (size_t i = 0; i < arr.getLength(); i++)
    {
        //cout << arr[i] << " ";
        //cout << arr[i].toString() << " ";
        cout << arr[i].toString() << " ";
    }
    cout << endl;

    Date date1(2023, 9, 26);
    Date date2(2023, 9, 28);
    Time time1(16, 19, 55);
    Time time2(18, 15, 25);
    DateTime dateTime1(2023, 9, 27, 15, 44, 28);
    DateTime dateTime2(2023, 9, 26, 16, 19, 55);

    cout << date1.toString() << endl;
    cout << date2.toString() << endl;
    cout << date1.difference(date2).toString() << endl;
    cout << time1.toString() << endl;
    cout << time2.toString() << endl;
    cout << time1.difference(time2).toString() << endl;
    cout << dateTime1.toString() << endl;
    cout << dateTime2.toString() << endl;
    cout << dateTime2.difference(dateTime1).toString() << endl;
}