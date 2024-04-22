
#include<iostream>
#include<string>
using namespace std;

int main() {
    int n;
    string city[20];
    int adj_matrix[50][50];

    cout << "Enter the number of cities: ";
    cin >> n;

    // Input city names
    for (int i = 0; i < n; i++) {
        cout << "Enter the name of city " << i + 1 << ": ";
        cin >> city[i];
    }

    // Input time required to travel between cities and construct adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if(i == j){
                adj_matrix[i][j] = 0;
                continue;
            }
            cout << "Enter the time required to travel from city " << city[i] << " to " << city[j] << ": ";
            cin >> adj_matrix[i][j];
            adj_matrix[j][i] = adj_matrix[i][j];
        }
    }

    // Print adjacency matrix
    cout << "\n\t";
    for (int i = 0; i < n; i++) {
        cout << city[i] << "\t";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << city[i] << "\t";
        for (int j = 0; j < n; j++) {
            cout << adj_matrix[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
