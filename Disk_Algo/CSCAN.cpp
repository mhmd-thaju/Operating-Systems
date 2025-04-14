#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void C_SCAN(const vector<int>& req, int head, int disk_size, string dir){
    int st = 0;
    vector<int> left, right, seq;
    
    if (dir == "left") {
        left.push_back(0);
    } else {
        right.push_back(disk_size - 1);
    }

    // Divide requests into left and right based on the initial head position
    for (int r : req) {
        if (r < head) {
            left.push_back(r);
        } else {
            right.push_back(r);
        }
    }


    // Process the requests in C-SCAN manner
    if (dir == "left") {
        sort(left.begin(), left.end(), greater<int>());
        sort(right.begin(), right.end(),greater<int>());
        // First, go from head to 0, and then jump to the farthest side (disk_size - 1) and go back
        seq.insert(seq.end(), left.begin(), left.end());
        seq.push_back(disk_size - 1);  // Move to the farthest end
        seq.insert(seq.end(), right.begin(), right.end());
    } else {
        // First, go from head to disk_size - 1, and then jump to 0 and go back
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        seq.insert(seq.end(), right.begin(), right.end());
        seq.push_back(0);  // Move to the farthest end
        seq.insert(seq.end(), left.begin(), left.end());
    }

    // Calculate the total head movement
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
