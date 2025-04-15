#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void C_SCAN(const vector<int>& req, int head, int disk_size, string dir){
    int st = 0;
    vector<int> left, right, seq;
 
    for (int r : req) {
        if (r < head) {
            left.push_back(r);
        } else {
            right.push_back(r);
        }
    }

    if (dir == "left") {
        sort(left.begin(), left.end(), greater<int>());
        sort(right.begin(), right.end(),greater<int>());
        seq.insert(seq.end(), left.begin(), left.end());
        seq.insert(seq.end(), right.begin(), right.end());
    } else {
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        seq.insert(seq.end(), right.begin(), right.end());
        seq.insert(seq.end(), left.begin(), left.end());
    }

    for (int t : seq) {
        st += abs(t - head);
        head = t;
    }

    cout << "C-SCAN Total head movements: " << st << endl;
}

int main() {
    int n, head, disk_size;
    string dir;

    cout << "Enter number of disk requests: ";
    cin >> n;

    vector<int> requests(n);
    cout << "Enter the disk requests: ";
    for (int i = 0; i < n; i++) {
        cin >> requests[i];
    }

    cout << "Enter initial head position: ";
    cin >> head;

    cout << "Enter size of the disk: ";
    cin >> disk_size;

    cout << "Enter the direction of scan (left / right): ";
    cin >> dir;

    C_SCAN(requests, head, disk_size, dir);

    return 0;
}
