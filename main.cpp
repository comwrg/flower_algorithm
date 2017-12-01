#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <ctime>
#include <numeric>

using namespace std;

/**
2 0 0 0 0 0 0 0 0 0
1 1 0 0 0 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0
1 0 0 1 0 0 0 0 0 1
1 0 0 0 1 0 0 0 0 0
1 0 0 0 0 1 0 0 0 0
1 0 0 0 0 0 1 0 0 0
1 0 0 0 0 0 0 1 0 0
1 0 0 0 0 0 0 0 1 0
1 0 0 0 0 0 0 0 0 1
0 2 0 0 0 0 0 0 0 0
0 1 1 0 0 0 0 0 0 0
0 1 0 1 0 0 0 0 0 0
0 1 0 0 1 0 0 0 0 0
0 1 0 0 0 1 0 0 0 0
0 1 0 0 0 0 1 0 0 0
0 1 0 0 0 0 0 1 0 0
0 1 0 0 0 0 0 0 1 0
0 1 0 0 0 0 0 0 0 1
0 0 2 0 0 0 0 0 0 0
0 0 1 1 0 0 0 0 0 0
0 0 1 0 1 0 0 0 0 0
0 0 1 0 0 1 0 0 0 0
0 0 1 0 0 0 1 0 0 0
0 0 1 0 0 0 0 1 0 0
0 0 1 0 0 0 0 0 1 0
0 0 1 0 0 0 0 0 0 1
0 0 0 2 0 0 0 0 0 0
0 0 0 1 1 0 0 0 0 0
0 0 0 1 0 1 0 0 0 0
0 0 0 1 0 0 1 0 0 0
0 0 0 1 0 0 0 1 0 0
0 0 0 1 0 0 0 0 1 0
0 0 0 1 0 0 0 0 0 1
0 0 0 0 2 0 0 0 0 0
0 0 0 0 1 1 0 0 0 0
0 0 0 0 1 0 1 0 0 0
0 0 0 0 1 0 0 1 0 0
0 0 0 0 1 0 0 0 1 0
0 0 0 0 1 0 0 0 0 1
0 0 0 0 0 2 0 0 0 0
0 0 0 0 0 1 1 0 0 0
0 0 0 0 0 1 0 1 0 0
0 0 0 0 0 1 0 0 1 0
0 0 0 0 0 1 0 0 0 1
0 0 0 0 0 0 2 0 0 0
0 0 0 0 0 0 1 1 0 0
0 0 0 0 0 0 1 0 1 0
0 0 0 0 0 0 1 0 0 1
0 0 0 0 0 0 0 2 0 0
0 0 0 0 0 0 0 1 1 0
0 0 0 0 0 0 0 1 0 1
0 0 0 0 0 0 0 0 2 0
0 0 0 0 0 0 0 0 1 1
0 0 0 0 0 0 0 0 0 2
66
 */
static vector<vector<int>> arr(10);

bool add(const vector<int> & v1, const vector<int> & v2, vector<int> & v3) {
    auto size = v1.size();
    int r = 0;
    for (int i = 0; i < size; i++) {
        int sum = v1[i] + v2[i] + r;
        v3[i] = sum % 10;
        r = sum / 10;
    }
    return r == 0;
}

bool multiply(vector<int> & v, int n) {
    int r = 0;
    for (int & i : v) {
        int sum = i * n;
        sum += r;
        i = sum % 10;
        r = sum / 10;
    }
    return r == 0;
}

void init_arr() {
    for (int i = 0; i < 10; i++) {
        auto& v = arr[i];
        v = vector<int>(21);
        v[0] = 1;
        for (int j = 0; j < 21; j++) {
            multiply(v, i);
        }

        // print
        for (int j = 0; j < 21; j++) {
            cout << v[j] << " ";
        }
        cout << endl;
    }
    cout << "----" << endl;
}

void handle(const vector<int> & vec) {
    // vec len is 10
    // 21 0 0 0
    // 21 * 0**21
    auto size = vec.size();
    vector<int> sum(21);
    for (int i = 0; i < size; i++) {
        vector<int> v(arr[i]);
        bool b;
        b = multiply(v, vec[i]);
        if (!b) return;
        b = add(v, sum, sum);
        if (!b) return;
    }
    if (sum[20] == 0) return;
    vector<int> counter(10);
    for (int i = 0; i < 21; i++) {
        counter[sum[i]]++;
    }
    for (int i = 0; i < 10; i++) {
        if (counter[i] != vec[i])
            return;
    }

    for (int i = 0; i < 21; i++) {
        cout << sum[i] << " ";
    }
    cout << endl;

}

void fun1(vector<int> vec, int & cnt) {
    cnt++;
    auto pos = distance(vec.begin(), find(vec.begin(), vec.end(), -1));

    if (pos == vec.size()) {
//        for (int i: vec) {
//            cout << i << " ";
//        }
//        cout << endl;

//        map<int, int> mp;
//        for (int i = 0; i < 10; i++) {
//            mp[i] = 0;
//        }
//        for (int i : vec) {
//            mp[i]++;
//        }
//        for (int i = 0; i < 10; i++) {
//            cout << mp[i] << " ";
//        }
//        cout << endl;
        return;
    }

    int pos_begin;
    if (pos == 0) {
        pos_begin = 0;
    } else {
        pos_begin = vec[pos - 1];
    }

    for (int i = pos_begin; i < 10; i++) {
        vector<int> vec_copy(vec);
        vec_copy[pos] = i;
        fun1(vec_copy, cnt);
    }
}

void fun2(vector<int> vec, int sum, int left, int & cnt) {
    auto it = find(vec.begin(), vec.end(), -1);
    auto pos = distance(vec.begin(), it);


    if (pos == vec.size() - 1) {
        cnt++;
        vec[pos] = left;
//        for (int i : vec) {
//            cout << i << " ";
//        }
//        cout << endl;

        handle(vec);
        return;
    }

    for (int i = left; i > -1; i--) {
        vec[pos] = i;
        fun2(vec, sum, left - i, cnt);
    }
}

/**
 * -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
 *      2 -1 -1 -1 -1 -1 -1 -1 -1 -1
 *          2 0 -1 -1 -1 -1 -1 -1 -1 -1
 *              2 0 0
 *              ...
 *              2 0 0 0 0 0 0 0 0 0 0
 *      1 -1 -1 -1 -1 -1 -1 -1 -1 -1
 *          1 1 -1 -1 -1 -1 -1 -1 -1 -1
 *              ...
 *          1 0 -1 -1 -1 -1 -1 -1 -1 -1
 *              1 0 1 0 0 0 0 0 0 0 0 0
 *              1 0 0 1
 *
 *
 */

int main() {
    auto time_begin = clock();
    init_arr();
    vector<int> vec(10);
    for (int &i : vec) {
        i = -1;
    }
    int cnt = 0;
    fun2(vec, 21, 21, cnt);
    cout << cnt << endl;
    auto time_end = clock();

    cout << static_cast<double>(time_end - time_begin) / CLOCKS_PER_SEC << endl;

    return 0;
}