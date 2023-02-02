#include <stdio.h>

__global__ void VecAdd(int* A, int* B, int* C)
{
    int i = threadIdx.x;
    C[i] = A[i] + B[i];
}

int main()
{
    int *h_a, *h_b, *h_c;
    h_a = (int *)malloc(16 * sizeof(int));
    h_b = (int *)malloc(16 * sizeof(int));
    h_c = (int *)malloc(16 * sizeof(int));
    int *d_a, *d_b, *d_c;
    cudaMalloc(&d_a, 16);
    cudaMalloc(&d_b, 16);
    cudaMalloc(&d_c, 16);
    cudaMemcpy(d_a, h_a, 16, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, 16, cudaMemcpyHostToDevice);
    cudaMemcpy(d_c, h_c, 16, cudaMemcpyHostToDevice);
    VecAdd<<<1, 16>>>(d_a, d_b, d_c);
    cudaMemcpy(h_c, d_c, size, cudaMemcpyDeviceToHost);
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);
    printf("the result is %d\n", h_c[6]);

}
