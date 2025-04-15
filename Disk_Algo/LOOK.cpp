#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // for abs

using namespace std;

void LOOK(vector<int>& requests, int head, int direction) {
    int totalMovement = 0;

    // Sort the request queue
    sort(requests.begin(), requests.end());

    // Find the first request >= head
    int index = 0;
    while (index < requests.size() && requests[index] < head) {
        index++;
    }

    cout << "\nLOOK Disk Scheduling:\nSeek Sequence: " << head;

    // Direction: 1 for right/up, 0 for left/down
    if (direction == 1) {
        // Move right
        for (int i = index; i < requests.size(); i++) {
            cout << " -> " << requests[i];
            totalMovement += abs(requests[i] - head);
            head = requests[i];
        }
        // Then move left
        for (int i = index - 1; i >= 0; i--) {
            cout << " -> " << requests[i];
            totalMovement += abs(requests[i] - head);
            head = requests[i];
        }
    } else {
        // Move left
        for (int i = index - 1; i >= 0; i--) {
            cout << " -> " << requests[i];
            totalMovement += abs(requests[i] - head);
            head = requests[i];
        }
        // Then move right
        for (int i = index; i < requests.size(); i++) {
            cout << " -> " << requests[i];
            totalMovement += abs(requests[i] - head);
            head = requests[i];
        }
    }

    cout << "\nTotal Head Movement: " << totalMovement << "\n";
}

int main() {
    int n, head, direction;

    cout << "Enter the number of requests: ";
    cin >> n;

    vector<int> requests(n);
    cout << "Enter the request queue: ";
    for (int i = 0; i < n; i++) {
        cin >> requests[i];
    }

    cout << "Enter the initial head position: ";
    cin >> head;

    cout << "Enter direction (1 for right, 0 for left): ";
    cin >> direction;

    LOOK(requests, head, direction);

    return 0;
}
