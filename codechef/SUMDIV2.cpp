#include <iostream>
using namespace std;

typedef long long lli;

int main() {
	lli t, n, x, y;
	
	cin >> t;
	
	while (t--) {
	    cin >> x >> y;
	    
	    lli n = x * y - x - y;
	    
	    if (n < 1) {
	        n = 3 * x * y - x - y;
	    }
	     
	    cout << n << endl;
	}
	return 0;
}
