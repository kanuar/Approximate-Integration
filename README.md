# Parallel Approximate Integration Algorithms

## Course Information
- **Course Code**: UE21CS343AB1
- **Course Name**: Heterogenous Parallelism

This course introduces the concepts of heterogeneous computing systems, focusing on the integration and collaboration of multiple architectures to solve computationally intensive problems more efficiently.

## Project Title
Parallel Approximate Integration Algorithms

## Project Description
This project investigates various approximate integration algorithms and their parallel implementations on heterogeneous platforms. By simulating code compilation and execution on both x86 and RISC-V architectures, we aim to analyze and compare the performance statistics for each platform. 

The RISC-V simulations are performed using [Spike](https://github.com/riscv-software-src/spike), the RISC-V ISA simulator, which provides an environment to execute and evaluate RISC-V programs. Spike allows us to capture essential runtime data such as execution cycles, memory usage, and register activity, enabling a direct comparison with x86 architecture. 

Parallelism in this project is achieved using the OpenMP library in C++, allowing us to efficiently implement parallel computation for integration algorithms across different architectures.

## Theory Summary
Approximate integration is a method used in calculus to estimate the value of definite integrals, especially when exact analytical integration is complex or impossible. Various techniques like the Trapezoidal Rule, Simpson’s Rule, and Midpoint Rule provide a way to approximate integrals by summing areas under curves represented by polygons. Each method has different levels of accuracy, complexity, and suitability for parallelization, making them interesting candidates for comparison across different computational architectures. 

For more details, refer to the theory on [Approximate Integration](https://math.libretexts.org/Bookshelves/Calculus/Map%3A_Calculus__Early_Transcendentals_(Stewart)/07%3A_Techniques_of_Integration/7.07%3A_Approximate_Integration).

## Goals and Objectives
- Implement approximate integration algorithms using OpenMP for parallelization.
- Compile and test code on both x86 and RISC-V platforms.
- Analyze performance differences in terms of execution time, memory usage, and computation efficiency.
- Draw insights into how heterogeneous parallelism can enhance computational performance for integration algorithms.

## Tools and Dependencies
- **Spike**: The RISC-V ISA Simulator for testing RISC-V binaries.
- **x86 and RISC-V Compilers**: Compilers for generating architecture-specific binaries.
- **OpenMP Library**: For parallelizing integration algorithms in C++.

## Results and Analysis
Performance metrics from both x86 and RISC-V platforms will be gathered, including:
- Execution Time
- Memory Usage
- CPU Cycles
- Instruction Count

The analysis will help understand the trade-offs and advantages of using different architectures for parallel computational tasks, especially in the context of approximate integration.

## Conclusion
This project demonstrates the potential benefits and limitations of heterogeneous parallelism for numerical integration algorithms, offering insights for more efficient computational approaches across diverse architectures.
