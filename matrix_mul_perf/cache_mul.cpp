#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void matmul_tiled(const vector<vector<float>>& A, const vector<vector<float>>& B, vector<vector<float>>& C, int N, int blockSize) {
    for (int i0 = 0; i0 < N; i0 += blockSize)
        for (int j0 = 0; j0 < N; j0 += blockSize)
            for (int k0 = 0; k0 < N; k0 += blockSize)
                for (int i = i0; i < min(i0 + blockSize, N); ++i)
                    for (int j = j0; j < min(j0 + blockSize, N); ++j)
                        for (int k = k0; k < min(k0 + blockSize, N); ++k)
                            C[i][j] += A[i][k] * B[k][j];
}

int main() {
    int N = 512;
    int blockSize = 64;
    vector<vector<float>> A(N, vector<float>(N, 1.0));
    vector<vector<float>> B(N, vector<float>(N, 1.0));
    vector<vector<float>> C(N, vector<float>(N, 0.0));

    auto start = high_resolution_clock::now();
    matmul_tiled(A, B, C, N, blockSize);
    auto end = high_resolution_clock::now();

    duration<double> diff = end - start;
    cout << "Tiled multiplication time: " << diff.count() << " s" << endl;

    return 0;
}
