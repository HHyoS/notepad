#include <iostream>
#include <stdio.h>
#include<vector>

using namespace std;
int N;
int M;
int K;
std::vector<int> Mulp(vector<int>& mA, vector<int>& mB) {
    vector <int>mC(K * N);
    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < K; ++b) {
            for (int c = 0; c < M; ++c) {
                mC[a * K + b] = mC[a * K + b] + mA[a * M + c] * mB[c * K + b];
            }
        }
    }
    return mC;
}

std::vector<int> setVector(int X, int Y) {
    vector<int > array(X * Y);
    for (int i = 0; i < X * Y; ++i)
        scanf("%d", &array[i]);

    scanf("%*c", array);

    return array;
}
int main() {
    scanf("%d %d", &N, &M);
    scanf("%*c", N, M);
    vector<int> arrayA(M* N);
    arrayA = setVector(M, N);
    scanf("%d %d", &M, &K);
    scanf("%*c", M, K);
    vector<int> arrayB(K * M);
    arrayB = setVector(K,M);
    vector<int> arrayC(K * N);
    arrayC = Mulp(arrayA, arrayB);

    for (int c = 0; c < N; ++c) {
        for (int d = 0; d < K; ++d) {
            printf("%d ", arrayC[c * K + d]);
        }
        printf("\n");
    }
    return 0;

}
