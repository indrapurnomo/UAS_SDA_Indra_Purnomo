#include <iostream>
#include <vector>
#include <string>

//Indra Purnomo
//230401020031

using namespace std;
struct Data {
    string nama;
    string alamat;
};
// Fungsi mencetak data
void printData(const vector<Data>& data) {
    for (const auto& d : data) {
        cout << d.nama << "\t" << d.alamat << endl;
    }
}
// Bubble Sort
void bubbleSort(vector<Data>& data) {
    int n = data.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (data[j].nama > data[j + 1].nama) {
                swap(data[j], data[j + 1]);
            }
        }
    }
}
// Selection Sort
void selectionSort(vector<Data>& data) {
    int n = data.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (data[j].nama < data[minIndex].nama) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(data[i], data[minIndex]);
        }
    }
}
int main() {
    vector<Data> data = {
        {"Fahmi", "Jakarta"},
        {"Romi", "Solo"},
        {"Andri", "Jakarta"},
        {"Fadillah", "Banyuwangi"},
        {"Ruli", "Bandung"},
        {"Rudi", "Bali"},
        {"Dendi", "Purwokerto"},
        {"Zaki", "Madiun"}
    };

    cout << "Data Awal:" << endl;
    printData(data);

    // Bubble Sort
    vector<Data> bubbleSortedData = data;
    bubbleSort(bubbleSortedData);
    cout << "\nData setelah diurutkan dengan Bubble Sort:" << endl;
    printData(bubbleSortedData);

    // Selection Sort
    vector<Data> selectionSortedData = data;
    selectionSort(selectionSortedData);
    cout << "\nData setelah diurutkan dengan Selection Sort:" << endl;
    printData(selectionSortedData);
    return 0;
}