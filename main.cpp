#include <iostream>
#include <vector>

std::vector<int> conv_mult(const std::vector<int>& arr1, const std::vector<int>& arr2){
    int n = arr1.size();
    int m = arr2.size();
    int iter = arr1.size() + arr2.size() - 1;
    std::vector<int> output(iter, 0);

    for(int k{}; k < iter; k++){
        for(int i{}; i < n; i++){
            int j = k - i;
            if(j >= 0 && j < m){
                output[k] += arr1[i] * arr2[j];
            }
        }
    }

    output.insert(output.begin(), 0);
    int index = iter;
    int carry = 0;
    while(index >= 0){
        if(carry){ 
            output[index] += carry;
            carry = 0;
        }
        if(output[index] >= 10){
            carry = output[index] / 10;
            output[index] %= 10;
        }
        index--;
    }

    return output;
}

int main(void){
    std::vector<int> arr1 = {1,2,3,4,5,6,7,8,9};
    std::vector<int> arr2 = {1,2,3,4,5,6,7,8,9};

    std::vector<int> arr3 = conv_mult(arr1, arr2);

    for(auto val : arr3) std::cout << val << "\t";
    std::cout << std::endl;

    return 0;
}