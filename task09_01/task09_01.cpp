// task09_01.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


void viseversa(int* arr, int** arr1, int n, int m, int tudaobratno)
{
    if (tudaobratno == 0) {
        for (int i = 0; i < n * m; i++)
        {
            arr1[i / m][i % m] = arr[i];
        }
    }

    else if (tudaobratno > 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                arr[i * m + j] = arr1[i][j];
            }

        }
    }
}



void output01(int* arr, int n, int m)
{
    for (int i = 0; i < n * m; i++) {
        printf_s("%d ", arr[i]);
    }
    printf_s("\n");
}

void output02(int** arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf_s("%d ", arr[i][j]);
        }
        printf_s("\n");
    }

}


void task09_01()
{
    int n = 0, m, vd;

    setlocale(LC_ALL, "Russian");

    printf_s("Введите количество строк и столбцов \n");
    scanf_s("%d%d", &n, &m);

    int** arr = (int**)malloc(n * sizeof(int**));
    for (int j = 0; j < n; j++)
    {
        arr[j] = (int*)malloc(m * sizeof(int*));
    }


    int** arr1 = (int**)malloc(n * sizeof(int**));
    for (int j = 0; j < n; j++)
    {
        arr1[j] = (int*)malloc(m * sizeof(int*));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            arr[i][j] = abs(i - j) + 1;
        }
    }

    int curel = 1;

    int  l = 0;
    int k = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr1[i][j] = 0;
        }
    }

    if (n % 2 == 1)
        k = n / 2 + 1;
    else  k = n / 2;
    while (l <= k)
    {
        for (int i = l; i < m - l - 1; i++)
        {
            if (arr1[l][i] == 0)
            {
                arr1[l][i] = curel;
                curel++;
            }
        }

        for (int j = l; j < n - l - 1; j++)
        {
            if (arr1[j][m - l - 1] == 0)
            {
                arr1[j][m - l - 1] = curel;
                curel++;
            }
        }

        for (int i = m - l - 1; i > l; i--)
        {
            if (arr1[n - l - 1][i] == 0)
            {
                arr1[n - l - 1][i] = curel;
                curel++;
            }
        }

        for (int j = n - l - 1; j > l; j--)
        {
            if (arr1[j][l] == 0)
            {
                arr1[j][l] = curel;
                curel++;
            }
        }
        l++;
    }
    if (n == m)
    {
        arr1[n / 2][m / 2] = n * m;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf_s("%d ", arr[i][j]);
        }
        printf_s("\n");
    }
    printf_s("\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr1[i][j] / 10 == 0)
                printf_s("%d  ", arr1[i][j]);
            else
                printf_s("%d ", arr1[i][j]);
        }
        printf_s("\n");
    }
}
void task09_02() {
    int n = 0, m, vd, l;

    setlocale(LC_ALL, "Russian");



    l = 5;
    while (l != 0)
    {
        printf_s("Выберите действие:\n");
        printf_s(" 1 - преобразование двумерного массива в одномерный,2 - пребразование одномерного массива в двумерный, 0 - завершение\n");
        scanf_s("%d", &vd);

        if (vd == 1)
        {
            printf_s("Введите количество строк и столбцов \n");
            scanf_s("%d%d", &n, &m);

            int* arr = (int*)malloc((n * m) * sizeof(int));
            int** arr1 = (int**)malloc(n * sizeof(int**));
            for (int j = 0; j < n; j++)
            {
                arr1[j] = (int*)malloc(m * sizeof(int*));
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    printf("arr[%i][%i] = ", i, j);
                    scanf_s("%d", &arr1[i][j]);
                }

            }

            viseversa(arr, arr1, n, m, 1);
            output01(arr, n, m);

        }
        else if (vd == 2)
        {
            printf_s("Введите количество строк и столбцов \n");
            scanf_s("%d%d", &n, &m);

            int* arr = (int*)malloc((n * m) * sizeof(int));
            int** arr1 = (int**)malloc(n * sizeof(int**));
            for (int j = 0; j < n; j++)
            {
                arr1[j] = (int*)malloc(m * sizeof(int*));
            }

            for (int i = 0; i < n * m; i++)
            {
                printf("arr[%i] = ", i);
                scanf_s("%d", &arr[i]);
            }
            viseversa(arr, arr1, n, m, 0);
            output02(arr1, n, m);
        }
        else l = vd;


    }
}


void swap(double& a, double& b) {
    double t;

    t = a;
    a = b;
    b = t;
}


void sysoutput(double** arr, double* y, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf_s("%f*x", arr[i][j]);
            if (j < n - 1)
                printf_s(" + ");
        }
        printf_s(" = %f\n", y[i]);
    }
    return;
}


double** triangular_matrix(double** arr, int n, double* y) {

    int k = 0, index;

    while (k < n)
    {
        //туда

        // если коэффициент ноль, меняем строки
        if (arr[k][k] == 0)
        {
            index = 0;
            for (int i = k + 1; i < n; i++)
            {
                if (arr[i][k] != 0)
                {
                    index = i;
                    break;
                }
            }

            if (index == 0)
            {
                printf_s("Решения нет (");
                return 0;
            }

            else
            {
                for (int j = 0; j < n; j++)
                    swap(arr[k][j], arr[index][j]);
                swap(y[k], y[index]);
            }

        }
        else {
            for (int i = k; i < n; i++)
            {
                double curcoeff = arr[i][k];
                if (curcoeff != 0)
                {
                    for (int j = 0; j < n; j++)
                        arr[i][j] = arr[i][j] / curcoeff;
                    y[i] = y[i] / curcoeff;
                    if (i != k)
                    {
                        for (int j = 0; j < n; j++)
                            arr[i][j] = arr[i][j] - arr[k][j];
                        y[i] = y[i] - y[k];
                    }
                }
            }

        }
        k++;
    }
    return arr;

}



double* solution(double** arr, int n, double* y)
{
    double* resh = (double*)malloc(n * sizeof(double));
    int k = 0;
    //обратно
    for (k = n - 1; k >= 0; k--)
    {
        resh[k] = y[k];
        for (int i = 0; i < k; i++)
            y[i] = y[i] - arr[i][k] * resh[k];
    }
    return resh;
}



void Gauss() {
    int n;

    setlocale(LC_ALL, "Russian");



    printf_s("Введите количество уравнений: ");
    scanf_s("%d", &n);

    double** arr = (double**)malloc(n * sizeof(double**));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (double*)malloc(n * sizeof(double*));
    }
    double* y = (double*)malloc(n * sizeof(double));
    double* answ = (double*)malloc(n * sizeof(double));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf_s("arr[%d][%d] = ", i, j);
            scanf_s("%lf", &arr[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf_s("y[%d] = ", i);
        scanf_s("%lf", &y[i]);
    }
    sysoutput(arr, y, n);
    triangular_matrix(arr, n, y);
    answ = solution(arr, n, y);

    printf_s("\n");

    for (int i = 0; i < n; i++)
        printf_s("x[%d] = %lf", i, answ[i]);
}


int main()
{
    
        setlocale(LC_ALL, "Russian");

        int n = 5;

        while (n != 0) {
            printf("\nВведите номер задания\n");
            printf("\n1-task 9.1, 2- task 9.2, 3- решение уравнений методом Гаусса, любая другая клавиша - завершение программы\n");
            scanf_s("%d", &n);

            switch (n) {
            case 1:
                task09_01();

                break;

            case 2:
                task09_02();
                break;

            case 3:
                Gauss();
                break;
            default:
                n = 0;
                break;
            }
           
        }
   
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
