#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

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

void fun2(vector<int> vec, int sum, int & cnt) {

}

int main() {
    auto time_begin = clock();
    vector<int> vec(21);
    for (int &i : vec) {
        i = -1;
    }
    int cnt = 0;
    fun1(vec, cnt);
    cout << cnt << endl;
    auto time_end = clock();

    cout << static_cast<double>(time_end - time_begin) / CLOCKS_PER_SEC << endl;

    return 0;
}