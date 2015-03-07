#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
 
using namespace std;
 
double det(int n, double mat[3][3])
{
    double submat[3][3];
    float d;
    for (int c = 0; c < n; c++)
    {
        int subi = 0; //submatrix's i value
        for (int i = 1; i < n; i++)
        {
            int subj = 0;
            for (int j = 0; j < n; j++)
            {
                if (j == c)
                    continue;
                submat[subi][subj] = mat[i][j];
                subj++;
            }
            subi++;
 
        }
        d = d + (pow(-1, c) * mat[0][c] * det(n - 1, submat));
    }
    return d;
}
 
int main(int argc, char **argv)
{
 
    cout << "Enter the points of the triangle:\n";
    int x1, x2, x3, x4, y1, y2, y3, y4, z1, z2, z3, z4;
    cin >> x1;
    cin >> x2;
    cin >> x3;
    cin >> x4;
    cin >> y1;
    cin >> y2;
    cin >> y3;
    cin >> y4;
    cin >> z1;
    cin >> z2;
    cin >> z3;
    cin >> z4;
    double mat[4][4];
    mat[0][0] = x1;
    mat[0][1] = x2;
    mat[0][2] = x3;
    mat[0][3] = x4;
    mat[1][0] = y1;
    mat[1][1] = y2;
    mat[1][2] = y3;
    mat[1][3] = y4;
    mat[2][0] = z1;
    mat[2][1] = z2;
    mat[2][2] = z3;
    mat[2][3] = z4;
    mat[3][0] = 1;
    mat[3][1] = 1;
    mat[3][2] = 1;
    mat[3][3] = 1;
 
    cout << "\nMatrix formed by the points: \n";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    double matrix[3][3];
 
    matrix[0][0] = x1 - x4;
    matrix[0][1] = x2 - x4;
    matrix[0][2] = x3 - x4;
    matrix[1][0] = y1 - y4;
    matrix[1][1] = y2 - y4;
    matrix[1][2] = y3 - y4;
    matrix[2][0] = z1 - z4;
    matrix[2][1] = z2 - z4;
    matrix[2][2] = z3 - z4;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    float determinant = det(3, matrix) / 6;
    if (determinant < 0)
        cout << "The Area of the tetrahedron formed by (" << x1 << "," << y1
                << "," << z1 << "), (" << x2 << "," << y2 << "," << z2
                << "), (" << x3 << "," << y3 << "," << z3 << "), (" << x4 << ","
                << y4 << "," << z4 << ") = " << (determinant * -1);
    else
        cout << "The Area of the tetrahedron formed by (" << x1 << "," << y1
                << "," << z1 << "), (" << x2 << "," << y2 << "," << z2
                << "), (" << x3 << "," << y3 << "," << z3 << "), (" << x4 << ","
                << y4 << "," << z4 << ") = " << determinant;
    return 0;
}
