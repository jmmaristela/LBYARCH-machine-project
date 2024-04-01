# LBYARCH Machine Project 2

## DAXPY Kernel Implementation in C and x86-64 Assembly


<h4>BACOSA, Gabriel Luis B.<h4>
<h4>MARISTELA, Joseph Miguel A.<h4>
<h4>Section S16<h4>
    
## Introduction

This repository contains implementations of the DAXPY (A*X + Y) function kernel in both C and x86-64 assembly language.

## Implementation Details / Project Specifications

The kernel performs the following operation:

Z[i] = A * X[i] + Y[i]

Where:
- A is a double-precision float scalar.
- X, Y, and Z are double-precision float vectors of length n.

Functional scalar SIMD registers and floating-point instructions are utilized for both versions.

Input: Scalar variable n (integer) contains the length of the vector; Scalar variable A is a double-precision float. Vectors X, Y and Z are double-precision float.

Output: store result in vector Z. Display the result of 1st ten elements of vector Z for all versions of kernel (i.e., C and x86-64).

Note: 
1.) Write a C main program to call the kernels of the C version and x86-64 assembly language.
2.) Time the kernel portion only. Both for debug mode and release mode

## Debug Mode

### Average Execution Time (in seconds)
|   Size     |     C     | x86-64     |
| ---------- | --------- | ---------- |
| 2<sup>20</sup>       | 2.066667 ms         | 2.600000 ms           |
| 2<sup>24</sup>       | 33.700000 ms          | 37.633333 ms           |
| 2<sup>25</sup>       | 62.666667 ms         | 56.533333 ms          |
| 2<sup>26</sup>       | 140.566667 ms         | 111.966667 ms           |
| 2<sup>27</sup>       | 482.600000 ms          | 190.233333 ms           |
| 2<sup>30</sup>       | Memory allocation failed          | Memory allocation failed           |

The average execution times reveal varying trends in the performance of the C and x86-64 assembly (ASM) implementations across different vector sizes.

Size 2<sup>20</sup>:

Both the C and ASM implementations demonstrate relatively similar execution times, with the C kernel averaging 2.066667 milliseconds and the ASM kernel averaging 2.600000 milliseconds. The comparable performance at this dataset size suggests similar efficiency in processing smaller datasets for both implementations.

Size 2<sup>24</sup>:

As the dataset size increases, both implementations exhibit significantly longer execution times. The C kernel averages 33.700000 milliseconds, while the ASM kernel averages 37.633333 milliseconds. Despite the increase in execution times, the relative performance difference between the two implementations remains consistent.

Size 2<sup>25</sup>:

The trend of increasing execution times continues for both implementations. The C kernel averages 62.666667 milliseconds, while the ASM kernel demonstrates slightly improved performance with an average of 56.533333 milliseconds. This slight deviation suggests that the ASM implementation may handle larger datasets more efficiently compared to the C implementation.

Size 2<sup>26</sup>:

The performance gap between the C and ASM implementations becomes more pronounced as the dataset size further increases. The C kernel averages 140.566667 milliseconds, while the ASM kernel shows significantly better performance, averaging 111.966667 milliseconds. This suggests that the ASM implementation's optimization and utilization of SIMD instructions contribute to its superior performance, particularly for larger datasets.

Size 2<sup>27</sup>:

For even larger datasets, the performance difference between the C and ASM implementations becomes even more apparent. The C kernel exhibits significantly longer execution times, averaging 482.600000 milliseconds, while the ASM kernel maintains its efficiency with an average of 190.233333 milliseconds. This substantial performance gap underscores the ASM implementation's scalability and efficiency in handling large datasets.

Size 2<sup>30</sup>:

Attempting to process a dataset of this size results in memory allocation failure for both implementations, indicating that the system's memory capacity is insufficient to accommodate the data. As such, further optimization or distributed computing strategies may be necessary to handle datasets of this magnitude effectively.

In summary, the performance analysis highlights the scalability and efficiency differences between the C and x86-64 assembly (ASM) implementations of the DAXPY kernel, with the ASM implementation demonstrating superior performance, particularly for larger datasets.

## Release Mode

### Average Execution Time (in seconds)
|   Size     |     C     | x86-64     |
| ---------- | --------- | ---------- |
| 2<sup>20</sup>       |  ms         |  ms           |
| 2<sup>24</sup>       |  ms          |  ms           |
| 2<sup>25</sup>       |  ms         |  ms          |
| 2<sup>26</sup>       |  ms         |  ms           |
| 2<sup>27</sup>       |  ms          |  ms           |
| 2<sup>30</sup>       |           |           |

## Program Output with Correctness Check
In order to check the accuracy of the output, we placed a condition to check if the results of the C function match the results from the x86-4 function.

``` c
if (check != 0) {
	printf("All elements are the same for both vectors. Thus, both C and x86-64 functions share the same results\n\n\n");
}
else {
	printf("There is a difference...");
}
```

Below are the screenshots of the program output: 

### Debug Mode (C and x86-64)
<img width="800" alt="Screenshot 2024-04-02 010105" src="https://github.com/jmmaristela/LBYARCH-machine-project/assets/97452438/fda6929d-e58a-4b01-9c19-da2aca465a7e">
<img width="800" alt="Screenshot 2024-04-02 005910" src="https://github.com/jmmaristela/LBYARCH-machine-project/assets/97452438/48624b83-dbba-4d87-b82d-5d93efa15e2a">
<img width="800" alt="Screenshot 2024-04-02 005809" src="https://github.com/jmmaristela/LBYARCH-machine-project/assets/97452438/24640d79-b926-4d84-9447-ec9c4eeda24a">
<img width="800" alt="Screenshot 2024-04-02 005723" src="https://github.com/jmmaristela/LBYARCH-machine-project/assets/97452438/1688dec1-da93-4b2a-8ae1-eee1574d7a78">
<img width="800" alt="Screenshot 2024-04-02 005554" src="https://github.com/jmmaristela/LBYARCH-machine-project/assets/97452438/bd95a66e-cd40-454a-b5c7-f9b8814af2fb">
<img width="800" alt="Screenshot 2024-04-02 010814" src="https://github.com/jmmaristela/LBYARCH-machine-project/assets/97452438/e03757bd-5f61-47cb-a319-d61b63eae20f">


### Release Mode (C and x86-64)
<img width="800" alt="Screenshot 2024-04-02 022417" src="https://github.com/jmmaristela/LBYARCH-machine-project/assets/97452438/143586bc-086b-43d7-b86f-2c99502a1b6a">
<img width="800" alt="Screenshot 2024-04-02 022545" src="https://github.com/jmmaristela/LBYARCH-machine-project/assets/97452438/0fd5f0d3-9812-4e82-9120-04c72c0655cf">
<img width="800" alt="Screenshot 2024-04-02 022735" src="https://github.com/jmmaristela/LBYARCH-machine-project/assets/97452438/ee31c21d-81a6-4550-b218-31b2b5791362">
<img width="800" alt="Screenshot 2024-04-02 023139" src="https://github.com/jmmaristela/LBYARCH-machine-project/assets/97452438/4fb6cac9-a8d5-4d52-937f-fa1dd50992ae">
<img width="800" alt="Screenshot 2024-04-02 023312" src="https://github.com/jmmaristela/LBYARCH-machine-project/assets/97452438/a7b634e6-a825-4530-b6ae-c40e04d27fac">



