#include <iostream>
#include <random>
#include <climits>
#include <cstring>
#include <map>
#include <cmath>
#include <iomanip>
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
//function check prime number
bool check(int n){
    if (n < 2){
        return false;
    }
    for (int i = 2; i < sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
void rotateMatrix(int a[100][100], int n, int m){
    for (int i = 0; i < m ; i++){
        for (int j = 0; j < n + 1; j++){
            swap(a[i][j], a[j][i] );
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m / 2; j++){
            swap(a[i][j], a[i][n - 1 - j]);
        }
    }
}
void print_matrix(int a[100][100], int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
}
int maxval = INT_MIN; // max number
int minval = INT_MAX; // min number

int main(){
    int n, m, a[100][100];
    // input number
    cout << "Enter the number n = ";
    cin >> n;
    cout << "----------------------\n";
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
    cout <<"-----------------------------\n";
    cout << "The Output Of A Random 2D Array has elements [i][j]: \n";
    cout << "---------------------------\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << "2D Array [i][j]: " << "[ " << i << " ]" << "[ " << j << " ]" << " = " << a[i][j] << endl;
        }
    }

    cout << "---------------------------\n";
    cout << "Random 2D Array Output \n";
    cout << "---------------------------\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
    cout << "--------------------------\n";
    cout << " \n";
    cout << "--------------------------\n";
    rotateMatrix(a, n, m);
    print_matrix(a, n, m);
    //total array 
    cout << endl;
    cout << "---------------------------\n";
    cout << "Total Of The Whole 2D Array: \n";
    cout << "---------------------------\n";
    int total = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            total += a[i][j];
        }
    }
    cout << "Total 2D Array: " << total << endl;
    cout << endl;
    // total row array
    cout << "----------------------------\n";
    cout << "Total Row Of 2D Array: \n";
    cout << "---------------------------\n";
    for (int i = 0; i < n; i++){
        int row_sum = 0;
        for (int j = 0; j < m; j++){
            row_sum += a[i][j];
        }
        cout << "Row 2D Array " << i + 1 << ": " << row_sum << endl;
    }
    cout << endl;
    // total column array
    cout << "---------------------------\n";
    cout << "Total Column Of 2D Array: \n";
    cout << "---------------------------\n";
    for (int j = 0; j < m; j++){
        int col_sum = 0;
        for (int i = 0; i < n; i++){
            col_sum += a[i][j];
        }
        cout << "Column 2D Array " << j + 1 << ": " << col_sum << endl;
    }
    // average row array
    cout << endl;
    cout << "---------------------------\n";
    cout << "Average row of 2d array\n";
    cout << "---------------------------\n";
    for (int i = 0; i < n; i++){
        int row_ave = 0;
        for (int j = 0; j < m; j++){
            row_ave += a[i][j];
        }
        double row_average = (double)row_ave / m;
        cout << "Average row array " << row_average << endl;
    }
    //average column array
    cout << endl;
    cout << "---------------------------\n";
    cout << "Average column of 2d array\n";
    cout << "---------------------------\n";
    for (int j = 0; j < m; j++){
        int col_ave = 0;
        for (int i = 0; i < n; i++){
            col_ave += a[i][j];
        }
        double col_average = (double)col_ave;
        cout << "Average column array " << col_average << endl;
    }
    // max and min array
    cout << endl;
    cout << "---------------------------\n";
    cout << "The Maxval And Minval In The 2D Array\n";
    cout << "---------------------------\n";
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
    cout << "Max lvalue number " << maxval << '\n';
    cout << "---------------------------\n";
    cout << "Min lvalue number " << minval << '\n';
    cout << "---------------------------\n";
    //total max and min
    cout << endl;
    cout << "----------------------------\n";
    cout << "Total maxval and minval " << maxval + minval << '\n';
    cout << "----------------------------\n";
    cout << endl;
    // even and odd
    cout << "-----------------------------\n";
    cout << "Count The Number Of Even And Odd\n";
    cout << "-----------------------------\n";
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
    cout << "Number Of Even Numbers " << even_number << "  Number\n";
    cout << "------------------------\n";
    cout << "Number Of Odd Numbers " << odd_number << " Number\n";
    cout << "----------------------------\n";
    cout << endl;
    cout << "----------------------------\n";
    //check prime numbers 
    cout << "Prime Number\n";
    cout << "----------------------------\n";
    map <int, bool> mp;
    int count = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (check(a[i][j]) && mp[a[i][j]] == false){
                cout << a[i][j] << " ";
                count++;
                mp[a[i][j]] = true;
            }
        }
        cout << endl;
    }
    cout << "----------------------------------\n";
    cout << "There is a total number of primes " << count << endl; 
    cout << "----------------------------------\n";
    // the diagonal of the 2d array
    cout << "The diagonal of the 2d array\n";
    for (int i = 0; i < n && i < m; i++){
        cout << "[ " << i << " ]" << "[ " << i << " ]" << " = " << a[i][i] << endl; 
    }
    cout << "---------------------------------\n";
    cout << endl;
    // total diagonal array
    cout << "total diagonal array\n";
    int counts = 0;
    for (int i = 0; i < n && i < m; i++){
        counts += a[i][i];
    }
    cout << "total diagonal array " << counts << endl;
    cout << "----------------------------------\n";
    cout << endl;
    cout << "-----------------------------\n";
}