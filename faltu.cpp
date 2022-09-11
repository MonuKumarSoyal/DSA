#include<iostream>
#include<vector>
using namespace std;


    float finding_median(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<int> resultant;
        int i = 0;
        int j = 0;
        while(i != size1 && j != size2){
            if(nums1[i] < nums2[j]){
                resultant.push_back(nums1[i]);
                i++;
            }
            else{
                resultant.push_back(nums2[j]);
                j++;
            }
        }
        while(i!=size1){
            resultant.push_back(nums1[i]);
            i++;
        }
        while(j!=size2){
            resultant.push_back(nums2[j]);
            j++;
        }
        float median;
        int size_of_resultant = resultant.size();
        if(size_of_resultant%2 == 0){
            cout<<"anil"<<endl;
            for(int k = 0; k<size_of_resultant; k++){
                cout<<resultant[k]<<" "<<endl;
            }
            median = (resultant[(size_of_resultant)/2 - 1] + resultant[size_of_resultant/2]);
            median = median/2;
        }
        else{
            median = resultant[(size_of_resultant-1)/2];
        }
        return median;
    }

int main(){

    vector<int> anil;
    vector<int> monu;
    anil.push_back(1);
    anil.push_back(2);
    monu.push_back(3);
    monu.push_back(4);
    cout<<finding_median(anil, monu);
}
