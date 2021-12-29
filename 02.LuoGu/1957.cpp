#include<bits/stdc++.h>
using namespace std;

char buf[1024];

int getT() {
    string line;
    getline(cin, line);
    int T; sscanf(line.c_str(), "%d", &T);
    return T;
}

int main(void){
    int T = getT();

    char type;
    while (T--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        if (isalpha(line[0])) {
            ss >> type;
        }

        int x, y, z; char op;
        ss >> x >> y;
        switch(type) {
        case 'a':
            op = '+', z = x + y;
            break;
        case 'b':
            op = '-', z = x - y;
            break;
        case 'c':
            op = '*', z = x * y;
            break;
        default:
            break;
        }

        sprintf(buf, "%d%c%d=%d", x, op, y, z);
        int n = strlen(buf);
        printf("%s\n%d\n", buf, n);
    }

    return 0;
}
