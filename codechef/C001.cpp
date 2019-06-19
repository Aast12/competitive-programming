#include <iostream>
#include <stack>

using namespace std;

struct Operation {
    int code, i_arg;
    string deleted, s_arg;
    Operation(int c, int a, string d) {
        code = c;
        i_arg = a;
        deleted = d;
    }
    Operation(int c, string a) {
        code = c;
        s_arg = a;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int queries, op;
    stack<Operation> op_stack;
    string line = "";
    
    cin >> queries;

    while (queries--) {
        cin >> op;
        string s_in, del;
        int i_in;
        switch (op) {
        case 1:
            cin >> s_in;
            line += s_in;
            op_stack.push(Operation(op, s_in));
            break;
        case 2:
            cin >> i_in;
            del = line.substr(line.size() - i_in, i_in);
            op_stack.push(Operation(op, i_in, del));
            line.erase(line.size() - i_in, i_in);
            break;
        case 3:
            cin >> i_in;
            cout << line[i_in - 1] << endl;
            break;
        case 4:
            Operation curr = op_stack.top();
            switch (curr.code) {
                case 1:
                    line.erase(line.size() - curr.s_arg.size(), curr.s_arg.size());
                    break;
                case 2:
                    line += curr.deleted;
                    break;
            }
            op_stack.pop();
            break;
        }
    }
}