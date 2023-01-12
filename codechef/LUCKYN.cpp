// AC
#include <iostream>
using namespace std;

int main() {
	int t;
	string num;
	bool flag;
	cin >> t;
	
	while (t--) {
	   cin >> num;
	   
	   flag = true;
	   for (auto digit : num) {
	       if (digit == '7') {
	           cout << "YES\n";
	           flag = false;
	           break;
	       }
	   }
	   
	   if (flag) cout << "NO\n";
	   
	}
	
	return 0;
}
