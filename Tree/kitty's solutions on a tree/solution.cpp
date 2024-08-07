#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
#define K 1000000007ll
#define L 200001
static int parents[L];
static long long children[L];
bool  valuesSet[200001];
static long long valuesSum;
using namespace std;

int main() {
    int n, q, a, b, k;
    int i, j;
    long long sum;
    cin >> n >> q;

    for (i = 0; i < n - 1; ++i) {
        cin >> a >> b;

        if (a < b) {
            parents[b] = a;
        } else {
            parents[a] = b;
        }
    }

    parents[1] = 0;

    for (i = 0; i < q; ++i) {
        cin >> k;
        for (j = 0; j <=n; ++j)
        valuesSet[j]=false;
        memset(children, 0, sizeof(long long) * n);
        valuesSum = 0;

        for (j = 0; j < k; ++j) {
            cin >> a;
            valuesSum += a;
            // cout<<"valueSum= "<<valuesSum<<endl;
            valuesSet[a] = true;
        }
        sum = 0;
        for (j = n; j > 0; j--) {
            // cout<<" j = "<<j<<endl;
            long long a = children[j];
            // cout<<" childen[j] = "<<children[j]<<endl;
            if (valuesSet[j]) {
                a += j;
                // cout<<"a = "<<a<<endl;
            }

            if (a) {
                long long x = ( (a % K) * ((valuesSum - a) % K) ) % K;
                sum =(sum+ x)%K;
                // cout<<"sum = "<<sum<<endl;
            }

            children[parents[j]] += a;
            // cout<<"children[parents[j]]= "<<children[parents[j]]<<endl;
        }

        cout << sum << endl;
    }
    return 0;
}  
