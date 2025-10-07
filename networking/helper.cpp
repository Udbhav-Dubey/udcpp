#include <bits/stdc++.h>
#include <arpa/inet.h>
using namespace std;
int main (){
    unsigned short port =8080;
    unsigned short network_port=htons(port);
    cout << "Host order " << port << endl;
    cout << "Network order(converted):" << network_port << endl;
    return 0;
}
