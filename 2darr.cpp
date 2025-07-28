#include <iostream>
#include <random>
#include <climits>
#include <cstring>
using namespace std;
void arr_random(int a[100][100], int n, int m){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0,99);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            a[i][j] = dis(gen);
        }
    } 
}
<<<<<<< HEAD
=======

>>>>>>> a8009ec53428ff8fad16172c0a50f9aad29fb6ba
int maxval = INT_MIN; // max number
int minval = INT_MAX; // min number
int main(){ 
    int n, m, a[100][100];
    // input number
    cout << "Enter the number n = ";
    cin >> n;
    cout << "----------------------" << endl;
    cout << "Enter the number m = ";
    cin >> m;
<<<<<<< HEAD
    arr_random(a, n, m); // random 2d array
    //bubble sort
    int k = 0;
    int temp[100];
    // convert 2d array to 1d array
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            temp[k++] = a[i][j];
        }
    }
    // bubble sort 1d array
    for (int i = 0; i < k - 1; i++){
        for (int j = 0; j < k - i - 1; j++){
            if (temp[j] > temp[j + 1]){
                swap(temp[j], temp[j+1]);
            }
        }
    }
    k = 0;
    // convert bubble sort 1d arry to 2d array
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            a[i][j] = temp[k++];
        }
    }
=======
    bubble_sort(a, n, m); // bubble sort 2d array
>>>>>>> a8009ec53428ff8fad16172c0a50f9aad29fb6ba
    // output array
    cout <<"-----------------------------" << endl;
    cout << "The Output Of A Random 2D Array has elements [i][j]: " << endl;
    cout << "---------------------------" << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << "2D Array [i][j]: " << "[ " << i << " ]" << "[ " << j << " ]" << " = " << a[i][j] << endl;
        }
    }
    
    cout << "---------------------------" << endl;
    cout << "Random 2D Array Output " << endl;
    cout << "---------------------------" << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
    //total array 
    cout << endl;
    cout << "---------------------------" << endl;
    cout << "Total Of The Whole 2D Array: " << endl;
    cout << "---------------------------" << endl;
    int total = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            total += a[i][j];
        }
    }
    cout << "Total 2D Array: " << total << endl;
    cout << endl;
    // total row array
    cout << "----------------------------" << endl;
    cout << "Total Row Of 2D Array: " << endl;
    cout << "---------------------------" << endl;
    for (int i = 0; i < n; i++){
        int row_sum = 0;
        for (int j = 0; j < m; j++){
            row_sum += a[i][j];
        }
        cout << "Row 2D Array " << i + 1 << ": " << row_sum << endl;
    }
    cout << endl;
    // total column array
    cout << "---------------------------" << endl;
    cout << "Total Column Of 2D Array: " << endl;
    cout << "---------------------------" << endl;
    for (int j = 0; j < m; j++){
        int col_sum = 0;
        for (int i = 0; i < n; i++){
            col_sum += a[i][j];
        }
        cout << "Column 2D Array " << j + 1 << ": " << col_sum << endl;
    }
    // max and min array
    cout << endl;
    cout << "---------------------------" << endl;
    cout << "The Maxval And Minval Number In The 2D Array" << endl;
    cout << "---------------------------" << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (a[i][j] > maxval){
                maxval = a[i][j];
            }
            if (a[i][j] < minval){
                minval = a[i][j];
            }
        }
    }
    cout << "Max lvalue number " << maxval << endl;
    cout << "---------------------------" << endl;
    cout << "Min lvalue number " << minval << endl;
    cout << "---------------------------" << endl;
<<<<<<< HEAD
    //total max and min
    cout << endl;
    cout << "----------------------------" << endl;
    cout << "Total maxval and minval " << maxval + minval << endl;
    cout << "----------------------------" << endl;
=======
>>>>>>> a8009ec53428ff8fad16172c0a50f9aad29fb6ba

}