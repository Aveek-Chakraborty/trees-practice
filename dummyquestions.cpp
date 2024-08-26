#include <bits/stdc++.h>
using namespace std;

int dtob(int d)
{
    string b = "";

    while (d)
    {
        int r = d % 2;
        d = d / 2;
        string a = to_string(r);
        b += a;
    }

    reverse(b.begin(), b.end());
    return stoi(b);
}

int btod(int b)
{

    int ans = 0;
    int c = 0;

    while (b)
    {
        int r = b % 10;
        b = b / 10;
        if (r)
        {
            ans += pow(2, c);
        }
        c++;
    }

    return ans;
}

int findDuplicate(vector<int> &nums)
{
    unordered_map<int, int> mp;
    for (auto it : nums)
    {
        mp[it]++;
    }

    for (auto it : mp)
    {
        if (it.second > 1)
        {
            return it.first;
        }
    }

    return 0;
}

vector<int> merge(vector<int>v1 , vector<int>v2){
    vector<int> ans;

    int n1=v1.size() ; int n2=v2.size();
    int i=0;
    int j=0;

    while(i<n1 && j<n2){
        if(v1[i]<v2[j]){
            ans.push_back(v1[i]);
            i++;
        }
        else if(v1[i]>v2[j]){
            ans.push_back(v2[j]);
            j++;
        }else{
            ans.push_back(v1[i]);
            i++;
            j++;
        }
    }

    if(i<n1){
        ans.push_back(v1[i]);
        i++;
    }
    if(j<n2){
        ans.push_back(v2[j]);
        j++;
    }


    return ans;
}

int main()
{

    // cout<<btod(dtob(9));
    vector<int> v1 = {1,3,5,7};
    vector<int> v2 = {2,4,6,8};

    // int mini = INT_MAX;
    // int maxi = INT_MIN;

    // for(auto it : v){
    //     if(it<mini){
    //         mini=it;
    //     }
    //     if(it>maxi){
    //         maxi=it;
    //     }
    // }

    // cout<<mini<<" "<<maxi;

    // for(int i =0 ; i<v.size() ; i+=2){
    //     swap(v[i],v[i+1]);
    // }

    vector<int> v = merge(v1,v2);

    for(auto it: v){
        cout<<it<<" ";
    }

    return 0;
}