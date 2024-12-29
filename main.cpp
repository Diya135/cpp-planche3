#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <algorithm>
#include <utility>
#include <tuple>
using namespace std;
//Exercise 1:
void fillArray(int *arr,int size) {
    for (int i=0;i<size;++i){
        cout<<"Enter value for arr["<<i<<"]: ";
        cin>>arr[i];
    }
}

int countPositive(int* arr,int size){
    int count=0;
    for (int i=0;i<size;++i){
        if(arr[i]>0){
            count++;
        }
    }
    return count;
}

//Exercise 2:
void fillArray(vector<int>& vec) {
    for (size_t i=0;i<vec.size();++i){
        cout<<"Enter value for vec["<<i<<"]: ";
        cin>>vec[i];
    }
}

void searchValue(const vector<int>& vec, int value) {
    auto it=find(vec.begin(), vec.end(), value);
    if (it!=vec.end()){
        cout<<value<<" is found at position " <<distance(vec.begin(), it)<<endl;
    } else{
        cout<<value<<" is not found in the array."<<endl;
    }
}

//Exercise 3:
int scalarProduct(const vector<int>& U,const vector<int>& V){
    int product=0;
    for(size_t i=0;i<U.size();++i){
        product +=U[i]*V[i];
    }
    return product;
}

//Exercise 4:
pair<int, int> minMax(const vector<int>& A) {
    int minVal=A[0];
    int maxVal=A[0];
    for (int num : A) {
        if (num<minVal) minVal=num;
        if (num>maxVal) maxVal=num;
    }
    return make_pair(minVal,maxVal);
}

//Exercise 5:
struct City {
    string name;
    pair<double, double> position;
};

void searchCity(const map<string, City>& cities, const string& cityName) {
    auto it=cities.find(cityName);
    if (it != cities.end()){
        cout<<"City: "<<it->second.name<<", Position: (" 
                 <<it->second.position.first<<", " 
                 <<it->second.position.second<<")"<< endl;
    } else{
        cout<<"City not found."<<endl;
    }
}

//Exercise 6:
namespace ArrayUtils {
    void display(const vector<int>&vec){
        for (int num : vec){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    void sortArray(vector<int>& vec){
        sort(vec.begin(),vec.end());
    }
}

//Main Function
int main() {
    //Exercise 1
    int size;
    cout<<"Enter size of the array: ";
    cin>>size;
    int* arr=new int[size];
    fillArray(arr, size);
    cout<<"Number of positive integers: "<<countPositive(arr, size)<<endl;
    delete[] arr;

    //Exercise 2
    size_t N;
    cout<<"Enter size of the vector: ";
    cin>>N;
    vector<int> vec(N);
    fillArray(vec);
    int valueToSearch;
    cout<<"Enter value to search: ";
    cin>>valueToSearch;
    searchValue(vec, valueToSearch);

    //Exercise 3
    vector<int> U={1, 2, 3};
    vector<int> V={4, 5, 6};
    cout<<"Scalar product: "<<scalarProduct(U, V)<<endl;

    //Exercise 4
    auto [minVal, maxVal]=minMax(vec);
    cout<<"Min: "<<minVal<<", Max: "<<maxVal<<endl;

    //Exercise 5
    map<string, City> cities;
    cities["Tunis"]={"Tunis", {10.1658, 36.8065}};
    cities["Sfax"]={"Sfax", {10.7603, 34.7404}};
    cities["Sousse"]={"Sousse", {10.6250, 35.8256}};

    string cityName;
    cout<<"Enter city name to search: ";
    cin>>cityName;
    searchCity(cities, cityName);

    //Exercise 6
    cout<<"Displaying vector: ";
    ArrayUtils::display(vec);
    ArrayUtils::sortArray(vec);
    cout<<"Sorted vector: ";
    ArrayUtils::display(vec);

    return 0;
}