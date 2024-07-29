#include <iostream>
#include <vector>
#include <algorithm>

//Indra Purnomo
//230401020031

using namespace std;

// Struktur data untuk menyimpan nilai dan indeks asli
struct IndexedValue {
    int value;
    int originalIndex;
};

// Binary Search
vector<int> binarySearch(const vector<IndexedValue>& arr, int target) {
    vector<int> indices;
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid].value == target) {
            // Temukan semua elemen yang sama dengan target
            int temp = mid;
            while (temp >= left && arr[temp].value == target) {
                indices.push_back(arr[temp].originalIndex + 1); // +1 untuk mengubah ke 1-based index
                temp--;
            }
            temp = mid + 1;
            while (temp <= right && arr[temp].value == target) {
                indices.push_back(arr[temp].originalIndex + 1); // +1 untuk mengubah ke 1-based index
                temp++;
            }
            break;
        }
        if (arr[mid].value < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    sort(indices.begin(), indices.end());
    return indices;
}

int main() {
    vector<IndexedValue> arr = {
        {19, 0}, {40, 1}, {10, 2}, {90, 3}, {2, 4}, 
        {50, 5}, {60, 6}, {50, 7}, {1, 8}
    };

    cout << "Array: ";
    for (const auto& item : arr) {
        cout << item.value << " ";
    }
    cout << endl;

    // Urutkan array berdasarkan nilai
    sort(arr.begin(), arr.end(), [](const IndexedValue& a, const IndexedValue& b) {
        return a.value < b.value;
    });

    while (true) {
        string input;
        cout << "Masukkan input angka yang ingin dicari (atau ketik 'selesai' untuk mengakhiri): ";
        cin >> input;

        if (input == "selesai") {
            cout << "Program diakhiri." << endl;
            break;
        }

        int testCase;
        try {
            testCase = stoi(input);  // Konversi string ke integer
        } catch (invalid_argument& e) {
            cout << "Input tidak valid. Silakan masukkan angka atau ketik 'selesai'." << endl;
            continue;
        }

        vector<int> result = binarySearch(arr, testCase);
        if (!result.empty()) {
            cout << "Angka " << testCase << " ada di indeks ke ";
            for (size_t i = 0; i < result.size(); ++i) {
                if (i > 0) cout << " dan ";
                cout << result[i];
            }
            cout << endl;
        } else {
            cout << "Angka " << testCase << " tidak ada dalam array" << endl;
        }
    }

    return 0;
}