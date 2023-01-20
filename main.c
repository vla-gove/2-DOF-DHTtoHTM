#include <stdio.h>
#include <math.h>

void print(double mat[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%.2f ", mat[i][j]);
        }
        printf("\n");
    }
}

void multiply(double a[4][4], double b[4][4], double result[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void homogeneous_transformation(double theta1, double theta2, double a1, double a2, double alpha1, double alpha2, double d1, double d2, double result[4][4]) {
    double T1[4][4] = {{cos(theta1), -sin(theta1)*cos(alpha1), sin(theta1)*sin(alpha1), a1*cos(theta1)},
                       {sin(theta1), cos(theta1)*cos(alpha1), -cos(theta1)*sin(alpha1), a1*sin(theta1)},
                       {0, sin(alpha1), cos(alpha1), d1},
                       {0, 0, 0, 1}};
    double T2[4][4] = {{cos(theta2), -sin(theta2)*cos(alpha2), sin(theta2)*sin(alpha2), a2*cos(theta2)},
                       {sin(theta2), cos(theta2)*cos(alpha2), -cos(theta2)*sin(alpha2), a2*sin(theta2)},
                       {0, sin(alpha2), cos(alpha2), d2},
                       {0, 0, 0, 1}};
    multiply(T1, T2, result);
}

int main() {
    //configure dh table parameters here
    double theta1 = M_PI / 2;
    double theta2 = M_PI / 6;
    double a1 = 3;
    double a2 = 1;
    double alpha1 = 0;
    double alpha2 = 0;
    double d1 = 0;
    double d2 = 0;
    double result[4][4];
    //calculate and print the homogenous transformation matrix
    homogeneous_transformation(theta1, theta2, a1, a2, alpha1, alpha2, d1, d2, result);
    printf("homogenous transformation matrix is given with:\n");
    print(result);
    return 0;
}