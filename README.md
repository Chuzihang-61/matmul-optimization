@"
# Matrix Multiplication Optimization

从朴素实现出发,逐级优化 CPU 与 GPU 上的 FP32 矩阵乘法,记录每一步的性能数据与瓶颈分析。

## CPU 优化阶梯

| 阶段 | 实现 | GFLOPS | 峰值占比 | 瓶颈 | 状态 |
|---|---|---|---|---|---|
| 0 | 朴素三重循环 | - | - | - | 进行中 |
| 1 | 循环重排 (ikj) | - | - | - | 待开始 |
| 2 | 分块 tiling | - | - | - | 待开始 |
| 3 | AVX2 向量化 | - | - | - | 待开始 |
| 4 | OpenMP 多线程 | - | - | - | 待开始 |

## 测试环境

- CPU: (待填)
- 编译器: (待填)
- 矩阵规模: M = N = K = 4096, FP32
"@ | Out-File -Encoding utf8 README.md