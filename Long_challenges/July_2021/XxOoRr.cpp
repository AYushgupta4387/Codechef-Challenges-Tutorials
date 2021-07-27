#include<iostream>
#include<cmath>
using namespace std; 

int main() {
    int T;
    cin >> T;

    for(int i=0; i<T; i++) {
        int n, k;
        cin >> n >> k;

        int a[100000] = {0};

        for(int j=0; j<n; j++) {
            cin >> a[j];
        }

        int one = 1;
        int result = 0;

        for(int j=1; j<=64; j++) {

            int count = 0;

            for(int k=0; k<n; k++) {
                
                if((a[k] & one) > 0) {
                    count++;
                    a[k] = a[k] ^ one;
                }
            }

            if(count > 0) {
                if(count % k == 0) {
                    result = result + (count / k);
                }
                else {
                    result = result + ((count / k) + 1);
                }    
            }
            one = one << 1;
        }
        cout << result << endl;
    }

    return 0;
}