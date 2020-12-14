﻿#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
void Matr1(int* a[], const int n1, const int n2, int* b[], const int m1, const int m2, int* c[])
{
    for (int i = 0; i < n1; i++) {             //умножение матриц А и B
        for (int j = 0; j < m2; j++) {
            c[i][j] = 0;
            for (int t = 0; t < n2; t++) {
                c[i][j] += a[i][t] * b[t][j];
            }
        }
    }
}
void Matr2(int* a[], const int n1, const int n2, int* b[], const int m1, const int m2, int* c[])
{
    for (int i = 0; i < n1; i++) {             //умножение матриц А и B
        for (int j = 0; j < m2; j++) {
            c[i][j] = 0;
            for (int t = 0; t < n2; t++) {
                c[i][j] += a[i][t] * b[t][j];
            }
        }
    }
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m2; j++) {
            cout << c[i][j] << "\t";
        }
        cout << endl;
    }
}
int main()
{
    int x;
    int n1, n2;
    ifstream t;
    t.open("1.txt");
    if (!t.is_open())
    {
        cout << "Файл не відкрито!" << endl;
        return 0;
    }
    // Matrix A
    t >> n1 >> n2;
    int** a = new int* [n1];
    for (int i = 0; i < n1; i++)
        a[i] = new int[n2];
    cout << "Matrix 1: " << endl;
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
            t >> a[i][j];
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
            cout << a[i][j] << "\t";
        cout << "\n";
    }
    cout << endl;
    ifstream f;
    f.open("2.txt");
    int m1, m2;
    if (!f.is_open())
    {
        cout << "Файл не відкрито!" << endl;
        return 0;
    }
    //Matrix B
    f >> m1 >> m2;
    int** b = new int* [m1];
    for (int i = 0; i < m1; i++)
        b[i] = new int[m2];
    cout << "Matrix 2: " << endl;
    for (int i = 0; i < m1; i++)
        for (int j = 0; j < m2; j++)
            f >> b[i][j];
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < m2; j++)
            cout << b[i][j] << "\t";
        cout << "\n";
    }

    // Matrix C
    int** c = new int* [n1];
    for (int i = 0; i < n1; i++)
        c[i] = new int[m2];

    Matr1(a, n1, n2, b, m1, m2, c);
    char fname[101];
    cout << "Name of file with result:"; cin >> fname;
    ofstream g(fname);
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m2; j++)
            g << c[i][j] << "\t";
        g << "\n";
    }
    cout << "Answer: Matrix 1 * Matrix 2" << endl;
    Matr2(a, n1, n2, b, m1, m2, c);
    for (int i = 0; i < n1; i++) delete[] a[i];
    delete[] a;
    for (int i = 0; i < m1; i++) delete[] b[i];
    delete[] b;
    for (int i = 0; i < n1; i++) delete[] c[i];
    delete[] c;
    t.close();
    f.close();
    g.close();



}
