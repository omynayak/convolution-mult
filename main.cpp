#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

std::vector<uint8_t> conv_mult(const std::vector<uint8_t>& arr1, const std::vector<uint8_t>& arr2){
    int n = arr1.size();
    int m = arr2.size();
    int iter = n + m - 1;
    std::vector<uint16_t> output(iter, 0);

    for(int k = 0; k < iter; k++){
        for(int i = 0; i < n; i++){
            int j = k - i;
            if(j >= 0 && j < m){
                output[k] += arr1[i] * arr2[j];
            }
        }
    }

    std::vector<uint8_t> result;
    result.reserve(iter + 1);
    
    int carry = 0;
    for(int index = iter - 1; index >= 0; index--){
        output[index] += carry;
        carry = output[index] / 10;
        result.push_back(output[index] % 10);
    }

    if(carry > 0){
        result.push_back(carry);
    }

    std::reverse(result.begin(), result.end());

    return result;
}

int main(void){
    std::vector<uint8_t> arr1 = {1,2,3,4,5,6,7,8,9};
    std::vector<uint8_t> arr2 = {1,2,3,4,5,6,7,8,9};

    std::vector<uint8_t> arr3 = conv_mult(arr1, arr2);

    for(auto val : arr3) std::cout << (int)val;
    std::cout << std::endl;

    return 0;
}