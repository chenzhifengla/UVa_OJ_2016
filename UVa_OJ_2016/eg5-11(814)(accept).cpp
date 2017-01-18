//#include <iostream>
//#include <string>
//#include <vector>
//#include <set>
//#include <map>
//using namespace std;
//
//void parse_address(const string& s, string& user, string& mta) {
//	int k = s.find('@');
//	user = s.substr(0, k);
//	mta = s.substr(k + 1);
//}
//
//int main() {
//    //freopen("eg5-11(814).in", "r", stdin);
//	int k;
//	string s, t, user1, mta1, user2, mta2;
//	set<string> addr;
//	
//	while (cin >> s && s != "*") {
//		cin >> s >> k;
//		while (k--) {
//			cin >> t;
//			addr.insert(t + "@" + s);
//		}
//	}
//
//	while (cin >> s && s != "*") {
//		parse_address(s, user1, mta1);
//		vector<string> mta;
//		map<string, vector<string> > dest;
//		set<string> vis;
//		while (cin >> t && t != "*") {
//			parse_address(t, user2, mta2);
//			if (vis.count(t)) continue;
//			vis.insert(t);
//			if (!dest.count(mta2)) {
//				mta.push_back(mta2);
//				dest[mta2] = vector<string>();
//			}
//			dest[mta2].push_back(t);
//		}
//		getline(cin, t);
//
//		string data;
//		while (getline(cin, t) && t[0] != '*') {
//			data += "     " + t + "\n";
//		}
//		for (int i = 0; i < mta.size(); i++) {
//			string mta2 = mta[i];
//			vector<string > users = dest[mta2];
//			cout << "Connection between " << mta1 << " and " << mta2 << endl;
//			cout << "     HELO " << mta1 << "\n";
//			cout << "     250\n";
//			cout << "     MAIL FROM:<" << s << ">\n";
//			cout << "     250\n";
//			bool ok = false;
//			for (int i = 0; i < users.size(); i++) {
//				cout << "     RCPT TO:<" << users[i] << ">\n";
//				if (addr.count(users[i])) {
//					ok = true;
//					cout << "     250\n";
//				}
//				else cout << "     550\n";
//			}
//			if (ok) {
//				cout << "     DATA\n";
//				cout << "     354\n";
//				cout << data;
//				cout << "     .\n";
//				cout << "     250\n";
//			}
//			cout << "     QUIT\n";
//			cout << "     221\n";
//		}
//	}
//	return 0;
//}


// 2017-01-18-chenkuan

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
using namespace std;

void parseAddr(const string& mail, string& user, string& mta) {
    int k = mail.find('@');
    user = mail.substr(0, k);
    mta = mail.substr(k + 1);
}

int main() {
    //freopen("eg5-11(814).in", "r", stdin);
    set<string> addr;   // 记录所有邮件地址
    string s;
    int n;
    while (cin >> s && s != "*") {
        cin >> s >> n;
        string recv;
        while (n--) {
            cin >> recv;
            addr.insert(recv + "@" + s);
        }
    }
    while (cin >> s && s != "*") {
        string user_send, mta_send, user_recv, mta_recv;
        parseAddr(s, user_send, mta_send);
        vector<string> mta; // 所有需要连接的mta
        map<string, vector<string>> dest;   // 每个mta需要发送的用户
        set<string> recvs;  // 记录当前行所有的收件人邮件地址
        string t;
        while (cin >> t && t != "*") {
            parseAddr(t, user_recv, mta_recv);
            if (recvs.find(t) != recvs.end()) {
                continue;
            }
            recvs.insert(t);
            if (dest.find(mta_recv) == dest.end()) {
                dest[mta_recv] = vector<string>();
                mta.push_back(mta_recv);
            }
            dest[mta_recv].push_back(t);
        }
        getline(cin, t);
        string data;
        while (getline(cin, t) && t != "*") {
            data += "     " + t + "\n";
        }
        for (int i = 0; i < mta.size(); i++) {
            mta_recv = mta[i];
            vector<string> users = dest[mta_recv];
            cout << "Connection between " << mta_send << " and " << mta_recv << endl;
            cout << "     HELO " << mta_send << endl;
            cout << "     250" << endl;
            cout << "     MAIL FROM:<" << s << ">" << endl;
            cout << "     250" << endl;
            bool has_correct_user = false;
            for (auto user : users) {
                cout << "     RCPT TO:<" << user << ">" << endl;
                if (addr.find(user) != addr.end()) {
                    has_correct_user = true;
                    cout << "     250" << endl;
                }
                else {
                    cout << "     550" << endl;
                }
            }
            if (has_correct_user) {
                cout << "     DATA" << endl;
                cout << "     354" << endl;
                cout << data;
                cout << "     ." << endl;
                cout << "     250" << endl;
            }
            cout << "     QUIT" << endl;
            cout << "     221" << endl;
        }
    }
    return 0;
}