#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of resources: ";
    cin >> m;

    vector<vector<int>> alloc(n, vector<int>(m));
    vector<vector<int>> max(n, vector<int>(m));
    vector<vector<int>> need(n, vector<int>(m));
    vector<int> avail(m);

    cout << "Enter allocation matrix (" << n << " x " << m << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> alloc[i][j];

    cout << "Enter maximum matrix (" << n << " x " << m << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> max[i][j];

    cout << "Enter available resources (" << m << " values):\n";
    for (int i = 0; i < m; i++)
        cin >> avail[i];

    // Calculate need matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    vector<bool> finish(n, false);
    vector<int> safeSeq;
    vector<int> work = avail;

    int count = 0;
    while (count < n) {
        bool found = false;

        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool canRun = true;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        canRun = false;
                        break;
                    }
                }

                if (canRun) {
                    for (int k = 0; k < m; k++)
                        work[k] += alloc[i][k];
                    safeSeq.push_back(i);
                    finish[i] = true;
                    count++;
                    found = true;
                }
            }
        }

        if (!found) {
            cout << "\nSystem is not in a safe state.\n";
            return 0;
        }
    }

    cout << "\nSystem is in a safe state.\nSafe sequence is: ";
    for (int i = 0; i < n; i++)
        cout << "P" << safeSeq[i] << " ";
    cout << endl;

    return 0;
}
