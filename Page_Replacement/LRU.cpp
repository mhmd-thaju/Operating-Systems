#include <iostream>
using namespace std;

int main() {
    int g = 0, a[5], b[20], p = 0, q = 0, m = 0, h, k, i, q1 = 1, j, u, n;
    char f = 'F';

    cout << "Enter the number of pages: ";
    cin >> n;

    cout << "Enter " << n << " Page Numbers: ";
    for(i = 0; i < n; i++) {
        cin >> b[i];
    }

    for(i = 0; i < n; i++) {
        if(p == 0) {
            if(q >= 3) {
                q = 0;
            }
            a[q] = b[i];
            q++;

            if(q1 < 3) {
                q1 = q;
            }
        }

        cout << "\n" << b[i];
        cout << "\t";

        for(h = 0; h < q1; h++) {
            cout << a[h];
        }

        if((p == 0) && (q <= 3)) {
            cout << "-->" << f;
            m++;
        }

        p = 0;
        g = 0;

        if(q1 == 3) {
            for(k = 0; k < q1; k++) {
                if(b[i + 1] == a[k]) {
                    p = 1;
                }
            }

            for(j = 0; j < q1; j++) {
                u = 0;
                k = i;

                while(k >= (i - 1) && k >= 0) {
                    if(b[k] == a[j]) {
                        u++;
                    }
                    k--;
                }

                if(u == 0) {
                    q = j;
                }
            }
        } else {
            for(k = 0; k < q; k++) {
                if(b[i + 1] == a[k]) {
                    p = 1;
                }
            }
        }
    }

    cout << "\nNo of faults: " << m;

    return 0;
}
