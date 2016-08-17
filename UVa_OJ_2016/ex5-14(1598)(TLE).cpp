#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct Order {
	bool isBuy;
	int p, q, num;
};

struct cmp_greater {
	bool operator() (const Order a, const Order b) const {
		if (a.q != b.q) return a.q < b.q;
		else return a.num > b.num;
	}
};

struct cmp_less {
	bool operator() (const Order a, const Order b) const {
		if (a.q != b.q) return a.q > b.q;
		else return a.num > b.num;
	}
};

priority_queue<Order, vector<Order>, cmp_greater> buyOrders;
priority_queue<Order, vector<Order>, cmp_less> sellOrders;
vector<Order> orders;

void cancelOrder(int num) {
	Order order = orders[num - 1];
	if (order.p <= 0) return;
	queue<Order> temp;
	Order t;
	if (order.isBuy) {
		while (!buyOrders.empty()) {
			t = buyOrders.top();
			buyOrders.pop();
			if (t.num == num) break;
			else {
				temp.push(t);
			}
		}
		while (!temp.empty()) {
			t = temp.front();
			temp.pop();
			buyOrders.push(t);
		}
	}
	else {
		while (!sellOrders.empty()) {
			t = sellOrders.top();
			sellOrders.pop();
			if (t.num == num) break;
			else temp.push(t);
		}
		while (!temp.empty()) {
			t = temp.front();
			temp.pop();
			sellOrders.push(t);
		}
	}
}

void addOrder(Order ord) {
	if (ord.isBuy) {
		buyOrders.push(ord);
	}
	else sellOrders.push(ord);
}

void tradeOrder(Order& ord) {
	int tradeNum, price;
	if (ord.isBuy) {
		Order ordSell = sellOrders.top();
		sellOrders.pop();
		tradeNum = min(ord.p, ordSell.p);
		price = ordSell.q;
		ord.p -= tradeNum;
		ordSell.p -= tradeNum;
		if (ordSell.p) sellOrders.push(ordSell);
		orders[ord.num - 1].p -= tradeNum;
		orders[ordSell.num - 1].p -= tradeNum;
	}
	else {
		Order ordBuy = buyOrders.top();
		buyOrders.pop();
		tradeNum = min(ord.p, ordBuy.p);
		price = ordBuy.q;
		ord.p -= tradeNum;
		ordBuy.p -= tradeNum;
		if (ordBuy.p) buyOrders.push(ordBuy);
		orders[ord.num - 1].p -= tradeNum;
		orders[ordBuy.num - 1].p -= tradeNum;
	}
	cout << "TRADE " << tradeNum << " " << price << endl;
}

void printOrder() {
	int size = 0;
	int price = buyOrders.top().q;
	queue<Order> temp;
	while (!buyOrders.empty() && buyOrders.top().q == price) {
		size += buyOrders.top().p;
		temp.push(buyOrders.top());
		buyOrders.pop();
	}
	while (!temp.empty()) {
		buyOrders.push(temp.front());
		temp.pop();
	}
	cout << "QUOTE " << size << " " << price << " - ";
	size = 0;
	price = sellOrders.top().q;
	while (!sellOrders.empty() && sellOrders.top().q == price) {
		size += sellOrders.top().p;
		temp.push(sellOrders.top());
		sellOrders.pop();
	}
	while (!temp.empty()) {
		sellOrders.push(temp.front());
		temp.pop();
	}
	cout << size << " " << price << endl;
}

int main() {
	int n, kase = 0;
	while (cin >> n) {
		while (!buyOrders.empty()) buyOrders.pop();
		while (!sellOrders.empty()) sellOrders.pop();
		Order o;
		o.p = 0;
		o.q = 0;
		o.num = 0;
		o.isBuy = true;
		buyOrders.push(o);
		o.isBuy = false;
		o.q = 99999;
		sellOrders.push(o);
		for (int i = 1; i <= n; i++) {
			string cmd;
			cin >> cmd;
			if (cmd == "CANCEL") {
				int orderNum;
				cin >> orderNum;
				cancelOrder(orderNum);
				Order ord;
				ord.num = i;
				orders.push_back(ord);
			}
			else {
				int p, q;
				cin >> p >> q;
				Order ord;
				ord.num = i;
				ord.p = p;
				ord.q = q;
				if (cmd == "BUY") {
					ord.isBuy = true;
				}
				else if (cmd == "SELL") {
					ord.isBuy = false;
				}
				//addOrder(ord);
				orders.push_back(ord);
				if (ord.isBuy) {
					while (ord.p && sellOrders.top().q < ord.q) {
						tradeOrder(ord);
					}
				}
				else {
					while (ord.p && buyOrders.top().q > ord.q) {
						tradeOrder(ord);
					}
				}
				if (ord.p) addOrder(ord);
			}
			printOrder();
		}
		if (kase > 0) cout << endl;
		kase++;
	}
	return 0;
}