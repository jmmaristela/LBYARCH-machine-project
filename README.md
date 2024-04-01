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
| 2<sup>20</sup>       |           |            |
| 2<sup>24</sup>       |           |            |
| 2<sup>30</sup>       |           |            |

## Performance Analysis


(data here)

### Analysis

The performance analysis reveals that...

## Program Output with Correctness Check


### Debug Mode (C)



### Debug Mode (x86-64)



### Release Mode (C)



### Release Mode (x86-64)

