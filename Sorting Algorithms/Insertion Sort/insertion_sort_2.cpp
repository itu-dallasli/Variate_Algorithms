#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


 void printArr(int n, vector<int> arr){
    for (int j = 0; j < n; j++) {
        std::cout << arr[j] << " ";
    }

    return;
}

vector<int> insertionSort1(int n, vector<int> arr) {
    
    int i = n-1;
    int ins_value = arr[i];
    
    while (0 < i && arr[i-1] > ins_value){
        arr[i] = arr[i-1];
        i--;
    }
    
    arr[i] = ins_value;
    return arr;
}

void insertionSort2(int n, vector<int> arr) {
    
    int j = 0;
    vector<int> img_arr;
    
    img_arr.insert(img_arr.end(), arr[j]);
    img_arr = insertionSort1(j, img_arr);
    j++;
    
    while (j < n){
        img_arr.insert(img_arr.end(), arr[j]);
        img_arr = insertionSort1(j, img_arr);
        
        if (j != 1){
            printArr(j, img_arr);
            for (int k = j; k < n; k++) {
                std::cout << arr[k] << " ";
            }
            std::cout << std::endl;
        }
        
        j++;
    }
    
    img_arr = insertionSort1(j, img_arr);
    printArr(j, img_arr);
    for (int k = j; k < n-1; k++) {
        std::cout << arr[k] << " ";
    }
    std::cout << std::endl;
    
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    insertionSort2(n, arr);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
