// GaussianKernelCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <math.h>

#define PI 3.1415926535
#define e  2.718281828459
#define cos45 0.52532198881
#define sin45 0.85090352453

int main()
{
    while (true)
    {
        double Sigma = 0;
        std::cout << "Sigma:" << std::endl;
        std::cin >> Sigma;

        double KernelSize = 0;
        std::cout << "Kernel Size:" << std::endl;
        std::cin >> KernelSize;

        int r = KernelSize / 2;

        double Sum = 0;
        double Gxy = 0;
        for (int y = -r; y <= r; y++)
        {
            for (int x = -r; x <= r; x++)
            {
                Gxy = (1.0 / (2 * PI * Sigma*Sigma)) * pow(e, -(x*x + y * y) / (2 * Sigma*Sigma));
                printf("%0.4f\t", Gxy);

                Sum += Gxy;
            }
            std::cout << "\n";
        }
        printf("Sum: %0.4f\n", Sum);

        // min value of the matrix
        double minValue = (1.0 / (2 * PI * Sigma*Sigma)) * pow(e, -(r * r + r * r) / (2 * Sigma*Sigma));

        // all elements divided this value to make sure the edge is '1'

        // output interger matrix
        int iSum = 0;
        int iGxy = 0;
        for (int y = -r; y <= r; y++)
        {
            for (int x = -r; x <= r; x++)
            {
                double s = (1.0 / (2 * PI * Sigma*Sigma)) * pow(e, -( x * x + y * y) / (2 * Sigma*Sigma));

                iGxy = s / minValue;
                printf("%d\t", iGxy);

                iSum += iGxy;
            }
            std::cout << "\n";
        }
        printf("Sum: %d\n\n", iSum);
    }
}
