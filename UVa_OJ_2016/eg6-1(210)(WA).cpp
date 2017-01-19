// 2017-01-19-chenkuan

#include <iostream>
#include <queue>
#include <deque>
#include <map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    //freopen("eg6-1(210).in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int n, t[5], Q;
        cin >> n;
        for (auto &tmp : t) {
            cin >> tmp;
        }
        cin >> Q;
        deque<int> ready_q;
        vector<queue<string>> processes;
        int pro_num = 0;
        string cmd;
        getline(cin, cmd);
        while (pro_num < n) {
            processes.push_back(queue<string>());
            while (getline(cin, cmd)) {
                processes[pro_num].push(cmd);
                if (cmd.substr(0, 3) == "end") break;
            }
            ready_q.push_back(pro_num);
            pro_num++;
        }
        queue<int> block_q;
        map<char, int> vars;    // 变量对应的值
        int lock = -1;  // lock所属的程序
        while (!ready_q.empty()) {
            pro_num = ready_q.front(); ready_q.pop_front(); // 弹出一个程序
            //cout << "弹出程序" << pro_num + 1 << endl;
            int used_time = 0;
            bool block = false; // 是否要进入阻止队列
            bool isend = false; // 是否指令全部结束
            while (used_time < Q && !processes[pro_num].empty()) {
                cmd = processes[pro_num].front();
                //cout << "  弹出程序" << pro_num + 1 << "的指令" << cmd << endl;
                if (cmd.substr(0, 4) == "lock") {
                    if (lock < 0) {
                        lock = pro_num;
                        used_time += t[2];
                        //cout << "    程序" << pro_num + 1 << "lock了所有变量" << endl;
                    }
                    else {
                        block = true;
                        //cout << "    程序" << pro_num + 1 << "lock变量失败，";
                        break;
                    }
                }
                else if (cmd.substr(0, 6) == "unlock") {
                    lock = -1;
                    used_time += t[3];
                    //cout << "    程序" << pro_num + 1 << "unlock了所有变量" << endl;
                    if (!block_q.empty()) {
                        int pro_num_block = block_q.front();
                        block_q.pop();
                        ready_q.push_front(pro_num_block);
                        //cout << "      程序" << pro_num_block + 1 << "从阻止队列取出，加到等待队列首部" << endl;
                    }
                }
                else if (cmd.substr(0, 3) == "end") {
                    isend = true;
                    used_time += t[4];
                    //cout << "    程序" << pro_num + 1 << "运行结束" << endl;
                    break;
                }
                else if (cmd.substr(0, 5) == "print") {
                    stringstream ss(cmd);
                    string var;
                    ss >> var; ss >> var;
                    //string var = cmd.substr(6);
                    //cout << "    程序" << pro_num + 1 << "即将打印变量" << var << "的值" << endl;
                    cout << pro_num + 1 << ": " << vars[var[0]] << endl;
                    used_time += t[1];
                }
                else {
                    stringstream ss(cmd);
                    string var, value_s;
                    ss >> var;
                    ss >> value_s; ss >> value_s;
                    //string var = cmd.substr(0, 1);
                    //int value = stoi(cmd.substr(4));
                    int value = stoi(value_s);
                    if (lock < 0 || lock == pro_num) {
                        vars[var[0]] = value;
                        used_time += t[0];
                        //cout << "    程序" << pro_num + 1 << "将变量" << var << "的值变为" << value << endl;
                    }
                }
                processes[pro_num].pop();   // 弹出一个指令
            }
            if (block) {    // 执行lock时失败，进入阻止队列
                block_q.push(pro_num);
                //cout << "程序" << pro_num + 1 << "进入阻止队列" << endl;
            }
            else if (!isend) {  // 时间配额用尽但没结束，放入等待队列
                ready_q.push_back(pro_num);
                //cout << "    程序" << pro_num + 1 << "时间配额用尽，加入等待队列尾部" << endl;
            }
        }
        if (T > 0) cout << endl;
    }
    return 0;
}