#include<stdio.h>
#include<string.h>
#include<time.h>
#pragma warning(disable :4996)
#define MAX_SIZE 50
double cal(double det[][MAX_SIZE], int size);
int main(int argNum, char* args[])
{
    long long start = 0, end;
    int size, i, j;
    double input[MAX_SIZE][MAX_SIZE] = { 0 };
    printf("size:");
    scanf("%d", &size);
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            scanf("%lf", &input[i][j]);
        }
    }
    start = clock();
    printf("result:%lf\n", cal(input, size));
    end = clock();
    printf("time used: %d ms\n", (end - start) / (CLOCKS_PER_SEC / 1000));
    printf("press enter to quit");
    rewind(stdin);
    getchar();

}
void addRow(int size,double det[][MAX_SIZE], int dst, int row, double multiple)
{
    register int i;
    for (i = 0; i < size; i++)
    {
        det[dst][i] += det[row][i]*multiple;
    }
}
double _cal(double det[][MAX_SIZE], int size)
{
    register int i;
    register double res;
    for (i = 0,res = 1; i < size; i++)
    {
        res *= det[i][i];
    }
    return res;
}
void swapRow(double row1[MAX_SIZE], double row2[MAX_SIZE], int size)
{
    double temp[MAX_SIZE];
    memcpy(temp, row1, sizeof(double) * size);
    memcpy(row1, row2, sizeof(double) * size);
    memcpy(row2,temp, sizeof(double) * size);
}
double cal(double det[][MAX_SIZE],int size)
{
    int i, j;
    int k;
    for (i = 0; i +1< size; i++)
    {
        for (j = i+1; j < size; j++)
        {
            if (!det[i][i])
            {
                for (k = i;k<size;k++)
                {
                    if (det[k][i])
                    {
                        swapRow(det[i], det[k],size);
                        break;
                    }
                }
                if (k == size)return 0;
            }
            addRow(size,det,j,i,-det[j][i]/det[i][i]);
        }
    }
    return _cal(det,size);
}