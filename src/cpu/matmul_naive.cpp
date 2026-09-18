// @"
#include <cstdio>
#include <cstdlib>
#include <chrono>
#include <vector>

// 朴素三重循环:所有优化的起点
void matmul_naive(const float* A, const float* B, float* C, int M, int N, int K) {
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j) {
            float sum = 0.0f;
            for (int k = 0; k < K; ++k)
                sum += A[i * K + k] * B[k * N + j];
            C[i * N + j] = sum;
        }
}

int main(int argc, char** argv) {
    int M = 1024, N = 1024, K = 1024;  // 先用小规模,跑得快
    if (argc == 2) M = N = K = atoi(argv[1]);
    if (argc == 4) { M = atoi(argv[1]); N = atoi(argv[2]); K = atoi(argv[3]); }

    std::vector<float> A(M * K, 1.0f), B(K * N, 1.0f), C(M * N, 0.0f);

    matmul_naive(A.data(), B.data(), C.data(), M, N, K);  // 预热

    double best = 1e18;
    for (int rep = 0; rep < 5; ++rep) {
        auto t0 = std::chrono::steady_clock::now();
        matmul_naive(A.data(), B.data(), C.data(), M, N, K);
        auto t1 = std::chrono::steady_clock::now();
        double ms = std::chrono::duration<double, std::milli>(t1 - t0).count();
        if (ms < best) best = ms;
    }

    double gflops = 2.0 * M * N * K / (best / 1000.0) / 1e9;
    printf("naive  M=N=K=%d  time=%.2f ms  %.2f GFLOPS\n", M, best, gflops);
    return 0;
}
// "@ | Out-File -Encoding utf8 src\cpu\matmul_naive.cpp