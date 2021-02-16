#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int N, M, K, n, m;
    cin >> N >> M >> K;
    int* x = new int[N * M];
    int** field = new int* [N];
    for (int i = 0; i < N; i++)
    {
        field[i] = x + i * M;
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            field[i][j] = 0;


    for (int i = 1; i <= K; i++)
    {
        cin >> n >> m;
        field[n - 1][m - 1] = -1;

        if ((n - 2 >= 0) && (m - 2 >= 0) && (n - 2 <= N - 1) && (m - 2 <= M - 1))
            if (field[n - 2][m - 2] != -1) field[n - 2][m - 2]++;

        if ((n - 2 >= 0) && (m - 1 >= 0) && (n - 2 <= N - 1) && (m - 1 <= M - 1))
            if (field[n - 2][m - 1] != -1) field[n - 2][m - 1]++;

        if ((n - 2 >= 0) && (m >= 0) && (n - 2 <= N - 1) && (m <= M - 1))
            if (field[n - 2][m] != -1) field[n - 2][m]++;

        if ((n - 1 >= 0) && (m >= 0) && (n - 1 <= N - 1) && (m <= M - 1))
            if (field[n - 1][m] != -1) field[n - 1][m]++;

        if ((n >= 0) && (m >= 0) && (n <= N - 1) && (m <= M - 1))
            if (field[n][m] != -1) field[n][m]++;

        if ((n >= 0) && (m - 1 >= 0) && (n <= N - 1) && (m - 1 <= M - 1))
            if (field[n][m - 1] != -1) field[n][m - 1]++;

        if ((n >= 0) && (m - 2 >= 0) && (n <= N - 1) && (m - 2 <= M - 1))
            if (field[n][m - 2] != -1) field[n][m - 2]++;

        if ((n - 1 >= 0) && (m - 2 >= 0) && (n - 1 <= N - 1) && (m - 2 <= M - 1))
            if (field[n - 1][m - 2] != -1) field[n - 1][m - 2]++;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << field[i][j] << ' ';
        cout << endl;
    }

    delete[] field;
    delete[] x;

}

