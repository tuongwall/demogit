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
    arr_random(a, n, m); // random 2d array

    //bubble sort
    int k = 0;
    int temp[10000]; // increase size to handle up to 100x100 elements
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
    k = 0; //reset zero
    // convert bubble sort 1d array to 2d array
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            a[i][j] = temp[k++];
        }
    }

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
    //total max and min
    cout << endl;
    cout << "----------------------------" << endl;
    cout << "Total maxval and minval " << maxval + minval << endl;
    cout << "----------------------------" << endl;
    // even and odd
    cout << "Count The Number Of Even And Odd" << endl;
    cout << "-----------------------------" << endl;
    int even_number = 0;
    int odd_number = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (a[i][j] % 2 == 0) {
                even_number++;
            }
            else{
                odd_number++;
            }
        }
    }
    cout << "Number Of Even Numbers " << even_number << endl;
    cout << "------------------------" << endl;
    cout << "Number Of Odd Numbers " << odd_number << endl;

}