#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int optimalPageReplacement(int pages[], int n, int frameCount) {
    vector<int> frames(frameCount, -1);  // Initialize frame with -1 (empty).
    int pageFaults = 0;

    for (int i = 0; i < n; i++) {
        bool pageFound = false;

        // Check if page is already in a frame
        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == pages[i]) {
                pageFound = true;
                break;
            }
        }

        // If the page is not found in the frame, we have a page fault
        if (!pageFound) {
            pageFaults++;

            // If there is an empty frame, place the page there
            bool placed = false;
            for (int j = 0; j < frameCount; j++) {
                if (frames[j] == -1) {
                    frames[j] = pages[i];
                    placed = true;
                    break;
                }
            }

            // If no empty frame, replace the page using the optimal algorithm
            if (!placed) {
                int farthest = -1;
                int indexToReplace = -1;

                // Find the page that will not be used for the longest period of time
                for (int j = 0; j < frameCount; j++) {
                    int nextUse = -1;
                    for (int k = i + 1; k < n; k++) {
                        if (frames[j] == pages[k]) {
                            nextUse = k;
                            break;
                        }
                    }
                    if (nextUse == -1) {
                        indexToReplace = j;
                        break;
                    }

                    if (nextUse > farthest) {
                        farthest = nextUse;
                        indexToReplace = j;
                    }
                }

                // Replace the page at indexToReplace with the current page
                frames[indexToReplace] = pages[i];
            }
        }

        // Display the current frame status
        cout << "Frame status after page " << pages[i] << ": ";
        for (int j = 0; j < frameCount; j++) {
            if (frames[j] != -1)
                cout << frames[j] << " ";
            else
                cout << "_ ";  // Empty frame
        }
        cout << endl;
    }

    return pageFaults;
}

int main() {
    int n, frameCount;

    cout << "Enter the number of pages: ";
    cin >> n;

    int pages[n];
    cout << "Enter " << n << " page numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    cout << "Enter the number of frames: ";
    cin >> frameCount;

    int pageFaults = optimalPageReplacement(pages, n, frameCount);

    cout << "\nTotal number of page faults: " << pageFaults << endl;

    return 0;
}
