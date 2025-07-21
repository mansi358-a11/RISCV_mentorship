#include <iostream>
#include <vector>
#include <chrono>

void naive_multiply(const std::vector<std::vector<int>> &A,
                    const std::vector<std::vector<int>> &B,
                    std::vector<std::vector<int>> &C);

void cache_optimized_multiply(const std::vector<std::vector<int>> &A,
                               const std::vector<std::vector<int>> &B,
                               std::vector<std::vector<int>> &C);

std::vector<std::vector<int>> generate_matrix(int n, int m) {
    std::vector<std::vector<int>> mat(n, std::vector<int>(m, 1)); // All ones
    return mat;
}

int main() {
    int size = 512;

    auto A = generate_matrix(size, size);
    auto B = generate_matrix(size, size);
    std::vector<std::vector<int>> C1(size, std::vector<int>(size));
    std::vector<std::vector<int>> C2(size, std::vector<int>(size));

    // Benchmark naive
    auto start_naive = std::chrono::high_resolution_clock::now();
    naive_multiply(A, B, C1);
    auto end_naive = std::chrono::high_resolution_clock::now();
    auto duration_naive = std::chrono::duration_cast<std::chrono::milliseconds>(end_naive - start_naive).count();

    // Benchmark cache-optimized
    auto start_cache = std::chrono::high_resolution_clock::now();
    cache_optimized_multiply(A, B, C2);
    auto end_cache = std::chrono::high_resolution_clock::now();
    auto duration_cache = std::chrono::duration_cast<std::chrono::milliseconds>(end_cache - start_cache).count();

    std::cout << "Naive Multiply Time: " << duration_naive << " ms" << std::endl;
    std::cout << "Cache Optimized Multiply Time: " << duration_cache << " ms" << std::endl;

    return 0;
}
