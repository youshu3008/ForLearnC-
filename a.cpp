#include <iostream>
#include <vector>

 using namespace std;

int main(){
    cout << (7 & 3 + 12) << endl;

    vector<int> nums;
    nums.push_back(1);
    nums.emplace_back(2,3,4);
    for(auto num : nums){
        cout << num << endl;
    }

}