#include <bits/stdc++.h>

using namespace std;

// Complete the candies function below.
long candies(int n, vector<int> arr) {
    long ans=0;
    vector<int> candies(arr.size(), 1);
    if(arr[0]>arr[1]) candies[0]+=1;
    else if(arr[1]>arr[0])candies[1]+=1;
    for(int i=1; i<arr.size(); i++){
        if(arr[i]>arr[i-1]) candies[i] = candies[i-1]+1;
        else if(arr[i]<arr[i-1] && arr[i]>arr[i+1]) candies[i] = candies[i+1]+1;
    }
    for(int i=0; i<candies.size(); i++){
        ans+=candies[i];
    }
    return ans;

}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    cout << result << "\n";

    // fout.close();

    return 0;
}
