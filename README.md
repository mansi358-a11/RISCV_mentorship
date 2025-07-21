# RISCV_mentorship
This is my RISCV mentorship repository

# Matrix Multiplication Benchmark

This project compares naive vs. cache-aware (tiled) matrix multiplication for square matrices.

## Files
- `naive_mul.cpp`: Standard triple-loop matrix multiply.
- `tiled_mul.cpp`: Optimized using loop tiling for cache efficiency.
- `Makefile`: Easy build script.
- `scripts/plot_results.py`: Basic plot of benchmark results.

## How to Build
```bash
make

