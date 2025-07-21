#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void matmul_naive(const vector<vector<float>>& A, const vector<vector<float>>& B, vector<vector<float>>& C, int N) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                C[i][j] += A[i][k] * B[k][j];
}

int main() {
    int N = 512;
    vector<vector<float>> A(N, vector<float>(N, 1.0));
    vector<vector<float>> B(N, vector<float>(N, 1.0));
    vector<vector<float>> C(N, vector<float>(N, 0.0));

    auto start = high_resolution_clock::now();
    matmul_naive(A, B, C, N);
    auto end = high_resolution_clock::now();

    duration<double> diff = end - start;
    cout << "Naive multiplication time: " << diff.count() << " s" << endl;

    return 0;
}
