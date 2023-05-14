#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void shellSort(int arr[], int n) {
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void writeArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n, i, start, end, log;
    clock_t t1, t2;

    cout << "Введите размер массива: ";
		scanf("%d", &n);
    cout << "Введите минимальное случайное число: ";
		scanf("%d", &start);
    cout << "Введите максимальное случайное число: ";
		scanf("%d", &end);
    cout << "Выводить массивы? (введите 1 для вывода): ";
		scanf("%d", &log);
		
    end -= start - 1;

    int* arr1 = new int[n];
    int* arr2 = new int[n];
    srand(time(0));

    for (i = 0; i < n; i++)
        arr1[i] = arr2[i] = rand() % end + start;
		if (log == 1) {
			printf("Исходный массив:\n");
			writeArray(arr1, n);
		}

    t1 = clock();
    shellSort(arr1, n);
    t2 = clock();
		if (log == 1) {
			printf("Сортировка Шелла:\n");
			writeArray(arr1, n);
		}
    printf("Время, затраченное на сортировку Шелла: %.6f секунд\n", (double)(t2 - t1) / CLOCKS_PER_SEC);

    t1 = clock();
    bubbleSort(arr2, n);
    t2 = clock();
		if (log == 1) {
			printf("Сортировка пузырьком:\n");
			writeArray(arr2, n);
		}
    printf("Время, затраченное на сортировку пузырьком: %.6f секунд\n", (double)(t2 - t1) / CLOCKS_PER_SEC);
}
