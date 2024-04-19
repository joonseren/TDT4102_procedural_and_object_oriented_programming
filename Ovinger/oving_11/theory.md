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

## Task 2: Vector Operations and Memory Management

### Questions and Answers

- **What happens when the size surpasses the capacity?**
  - The capacity doubles each time it is surpassed (1, 2, 4, 8, 16, 32, 64, ...).

- **What happens when using `vec.reserve(20)`?**
  - The capacity is set to 20, while the length remains as before, unaffected by this operation.

- **What happens if `vec.resize()` is used?**
  - Both the length and capacity start at 20. The length increases with each iteration, and the capacity doubles when surpassed.

### Performance with 1,000,000 Elements in a `std::vector`

- **Without Optimization Improvements:**
  - **Iterations:** 1,000,000
  - **Total Time:** 0.028078s
  - **Average Time per Iteration:** 2.8078e-08s

- **With Optimization Improvements (`reserve(n)`):**
  - **Iterations:** 1,000,000
  - **Total Time:** 0.01438s
  - **Average Time per Iteration:** 1.438e-08s

- **With Optimization Improvements (`resize(n)`):**
  - **Iterations:** 1,000,000
  - **Total Time:** 0.033826s
  - **Average Time per Iteration:** 3.3826e-08s

### Analysis

- **Using `reserve()` is the fastest method**, showing significant performance gains by pre-allocating memory, thus reducing the need for frequent memory reallocation.


## Task 3
>Take the time before optimization

Time: 8.16793 s.

>Optimaze as much as you can, comment and take the time for every change.
1. Added ```matrix.reserve(matrixSize);``` before creating the matrix. Reserving memory that is needed. Time: 7.96011 s.

2. Added `column.reserve(matrixSize);`before creating each column in matrix. column. Time: 5.9243 s.

3. Changed the nested for-loop in sumMatrix to a singel for-loop.
```cpp
double sumMatrix(std::vector<std::vector<double>> matrix){
    double sum;
    for (int i = 0; i < matrix.size() && i < matrix.at(i).size(); i++) {
        double value = matrix.at(i).at(i); 
        sum += value;            
    }
    return sum;
}
```