# Theory Questions and Answers

## Task 1: Measuring Initialization Time

Measure the time it takes to initialize a `std::unique_ptr` and a `std::shared_ptr`, and compare these to stack and heap allocation times. Below are the results comparing the initialization times for both pointer types across different iteration counts, along with stack and heap allocation times.

### Comparison of Initialization Times

#### std::unique_ptr
- **10,000,000 Iterations:**
  - **Total Time:** 0.331961s
  - **Average Time per Iteration:** 3.31961e-08s
- **25,000,000 Iterations:**
  - **Total Time:** 0.849097s
  - **Average Time per Iteration:** 3.39639e-08s
- **50,000,000 Iterations:**
  - **Total Time:** 1.65231s
  - **Average Time per Iteration:** 3.30462e-08s

#### std::shared_ptr
- **10,000,000 Iterations:**
  - **Total Time:** 1.03757s
  - **Average Time per Iteration:** 1.03757e-07s
- **25,000,000 Iterations:**
  - **Total Time:** 2.61114s
  - **Average Time per Iteration:** 1.04446e-07s
- **50,000,000 Iterations:**
  - **Total Time:** 5.15279s
  - **Average Time per Iteration:** 1.03056e-07s
- **100,000,000 Iterations:**
  - **Total Time:** 2.02564s
  - **Average Time per Iteration:** 2.02564e-08s

### Stack vs Heap Allocation Times

#### Stack Allocation
- **250,000,000 Iterations:**
  - **Total Time:** 0.522055s
  - **Average Time per Iteration:** 2.08822e-09s
- **500,000,000 Iterations:**
  - **Total Time:** 1.06775s
  - **Average Time per Iteration:** 2.13549e-09s

#### Heap Allocation
- **250,000,000 Iterations:**
  - **Total Time:** 5.05604s
  - **Average Time per Iteration:** 2.02242e-08s
- **500,000,000 Iterations:**
  - **Total Time:** 10.1136s
  - **Average Time per Iteration:** 2.02272e-08s

### Time Comparison Analysis

- **For std::unique_ptr vs std::shared_ptr:**
  - The `std::unique_ptr` consistently shows faster initialization times, approximately **3 times faster** than the `std::shared_ptr` across various iterations.
- **Stack vs Heap Allocation:**
  - Stack allocation is significantly faster than heap allocation, showing more than **9 times faster** performance, illustrating the efficiency of memory usage on the stack compared to the heap.

This data provides a clear illustration of the performance differences between pointer initialization and memory allocation strategies across a range of operation scales.

## Task 2
>What happens when the size surpasses the capasy?
It doubleas the capasty for every times it surpassse. 1, 2, 4, 8, 16, 32, 64, ...

> What happens when using vec.reserve(20)?
The capaxity stays constant at 20, and the length is as before

> What happens if vec.resize() is used?
It appers that the length and capacity starts at 20, and the length is increasing by iteratoins, the capacity is doubled when it surpassed the capacity

> 1000000 elements in a std:::vector:

Without optimiztion improvements
Iterations: 1000000
Time: 0.028078s
Average time per iteration: 2.8078e-08s

With optimiztion improvements: reserve(n)
Iterations: 1000000
Time: 0.01438s
Average time per iteration: 1.438e-08s