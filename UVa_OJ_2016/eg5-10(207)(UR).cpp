// 2017-01-18-chenkuan

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int t;
double reward_all;
double reward_percent[70];
struct Player {
    string name;
    int scores[4];
    bool isamateur;
    bool isfaul1, isfaul2;
    Player(string name, int scores[], bool isamateur, bool isfaul1, bool isfaul2) {
        this->name = name;
        memcpy(this->scores, scores, sizeof(int[4]));
        this->isamateur = isamateur;
        this->isfaul1 = isfaul1;
        this->isfaul2 = isfaul2;
    }
};
int player_num;
vector<Player> players;

int main() {
    cin >> t;
    while (t--) {
        cin >> reward_all;
        for (auto &re : reward_percent) {
            cin >> re;
        }
        cin >> player_num;
        for (int i = 0; i < player_num; i++) {
            string name, score_str;
            cin >> name;
            int scores[4];
            bool isfaul1 = false, isfaul2 = false;
            for (int j = 0; j < 4; j++) {
                cin >> score_str;
                if (score_str == "DQ") {
                    scores[j] = -1;
                    if (j < 2)  isfaul1 = true;
                    else isfaul2 = true;
                    break;
                }
                else {
                    scores[j] = stoi(score_str);
                }
            }
            bool isamateur = false;
            if (name.back() == '*') {
                isamateur = true;
            }
            players.emplace_back(name, scores, isamateur, isfaul1, isfaul2);
        }
        // 对前两轮成绩排序
        sort(players.begin(), players.end(), [](const Player& p1, const Player& p2) {
            if (p1.isfaul1) return false;
            else if (p2.isfaul1) return true;
            else return (p1.scores[0] + p1.scores[1]) < (p2.scores[0] + p2.scores[1]);
        });
        // 取前70名
        int rank_70 = 70;
        int score_70 = players[69].scores[0] + players[69].scores[1];
        for (int i = 70; i < player_num; i++) {
            if (!players[i].isfaul1 &&
                (players[i].scores[0] + players[i].scores[1] == score_70)) {
                rank_70++;
            }
        }
        // 对前70名的四轮总成绩排序
        sort(players.begin(), players.begin() + rank_70, [](const Player& p1, const Player& p2) {
            if (p1.isfaul2 && !p2.isfaul2) return false;
            else if (!p1.isfaul2 && p2.isfaul2) return true;
            else if (p1.isfaul2 && p2.isfaul2) {
                if (p1.scores[2] < 0) {
                    if (p2.scores[2] < 0) return p1.name < p2.name;
                    else return false;
                }
                else if (p2.scores[2] < 0) return p1.name < p2.name;
                else return true;
            }
            else if (p1.scores[2] + p1.scores[3] != p2.scores[2] + p2.scores[3]) {
                return p1.scores[2] + p1.scores[3] < p2.scores[2] + p2.scores[3];
            }
            else return p1.name < p2.name;
        });
        cout << "Player Name         Place  RD1   RD2   RD3   RD4   TOTAL    Money Won  " << endl;
        string _(60, '-');
        cout << _ << endl;
        for (auto it_player = players.begin(); it_player != players.begin() + rank_70; it_player++) {
            cout << it_player->name;
        }
    }
}