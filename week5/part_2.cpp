/*
魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。

红司令部，City 1，City 2，……，City n，蓝司令部

两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值这两种属性。

有的武士可以拥有武器。武器有三种，sword, bomb,和arrow，编号分别为0,1,2。

双方的武士编号都是从1开始计算。红方制造出来的第 n 个武士，编号就是n。同样，蓝方制造出来的第 n 个武士，编号也是n。

不同的武士有不同的特点。

dragon 可以拥有一件武器。编号为n的dragon降生时即获得编号为 n%3 的武器。dragon还有“士气”这个属性，是个浮点数，其值为它降生后其司令部剩余生命元的数量除以造dragon所需的生命元数量。

ninjia可以拥有两件武器。编号为n的ninjia降生时即获得编号为 n%3 和 (n+1)%3的武器。

iceman有一件武器。编号为n的iceman降生时即获得编号为 n%3 的武器。

lion 有“忠诚度”这个属性，其值等于它降生后其司令部剩余生命元的数目。

wolf没特点。

请注意，在以后的题目里，武士的士气，生命值，忠诚度在其生存期间都可能发生变化，都有作用，武士手中的武器随着使用攻击力也会发生变化。

武士在刚降生的时候有一个生命值。

在每个整点，双方的司令部中各有一个武士降生。

红方司令部按照 iceman、lion、wolf、ninja、dragon 的顺序循环制造武士。

蓝方司令部按照 lion、dragon、ninja、iceman、wolf 的顺序循环制造武士。

制造武士需要生命元。

制造一个初始生命值为 m 的武士，司令部中的生命元就要减少 m 个。

如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。

给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。

一共有两种事件，其对应的输出样例如下：

1) 武士降生

输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter

表示在 4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5,降生后蓝魔司令部里共有2个lion武士。(为简单起见，不考虑单词的复数形式)注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。

如果造出的是dragon，那么还要输出一行，例：

It has a arrow,and it's morale is 23.34

表示该dragon降生时得到了arrow,其士气是23.34（为简单起见，本题中arrow前面的冠词用a,不用an，士气精确到小数点后面2位，四舍五入）

如果造出的是ninjia，那么还要输出一行，例：

It has a bomb and a arrow

表示该ninjia降生时得到了bomb和arrow。

如果造出的是iceman，那么还要输出一行，例：

It has a sword

表示该iceman降生时得到了sword。

如果造出的是lion，那么还要输出一行，例：

It's loyalty is 24

表示该lion降生时的忠诚度是24。

2) 司令部停止制造武士

输出样例： 010 red headquarter stops making warriors

表示在 10点整，红方司令部停止制造武士

输出事件时：

首先按时间顺序输出；

同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。

输入
第一行是一个整数,代表测试数据组数。

每组测试数据共两行。

第一行，一个整数M。其含义为： 每个司令部一开始都有M个生命元( 1 <= M <= 10000)

第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000

输出
对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。

对每组测试数据，首先输出“Case:n" n是测试数据的编号，从1开始

接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int cost[2][5] = {{2, 3, 4, 1, 0}, {3, 0, 1, 2, 4}};
string team_name[2] = {"red", "blue"};
string warrior_name[5] = {"dragon","ninja","iceman","lion","wolf"};
string weapon_name[3] = {"sword", "bomb", "arrow"};

class warrior {
	int id;
	int strength;
public:
	warrior(int id, int strength):id(id), strength(strength){}
};

class dragon : public warrior {
	int weapon_id;
	double morality;
public:
	dragon(int id, int strength, int remain_strength):warrior(id, strength){
		weapon_id = id % 3;
		morality = (double)remain_strength / strength;
		cout<<"It has a "<<weapon_name[weapon_id]<<",and it's morale is "<<fixed<<setprecision(2)<<morality<<endl;
	}
};

class ninja : public warrior {
	int weapon_id1;
	int weapon_id2;
public:
	ninja(int id, int strength): warrior(id, strength) {
		weapon_id1 = id % 3;
		weapon_id2 = (id + 1) % 3;
		cout<<"It has a "<<weapon_name[weapon_id1]<<" and a "<<weapon_name[weapon_id2]<<endl;
	}
};

class iceman : public warrior {
	int weapon_id;
public:
	iceman(int id,int strength):warrior(id,strength){
		weapon_id = id%3;
		cout<<"It has a "<<weapon_name[weapon_id]<<endl;
	}
};

class lion : public warrior {
	int loyalty;
public:
	lion(int id, int strength, int remain_strength) : warrior(id,strength) {
		loyalty = remain_strength;
		cout<<"It's loyalty is "<<loyalty<<endl;
	}
};

class wolf : public warrior {
public:
	wolf(int id, int strength) : warrior(id, strength) {}
};

class headquarter {
	int num[5]; //  how many times i-th warreor has been used
	int total_strength; //
	int strength[5]; 
	int id; // headquator identifier
	int current; // current hero
	int warrior_id;
	bool cant[5];
	int sumcant;
public:
	headquarter(int id, int total_strength, int strength[]) {
		current = 0;
		warrior_id = 0;
		sumcant = 0;
		this->id = id;
		this->total_strength = total_strength;
		memset(num, 0, sizeof(int) * 5);
		memset(cant, false, sizeof(bool)*5);
		for (int i = 0; i < 5; ++i) {
			this->strength[i] = strength[i];
		}
	}
	bool canmake() {
		return (sumcant < 5);
	}
	void make() {
		while(canmake()) {
			int need_id = cost[id][current];
			if (cant[need_id]) continue;
			if (total_strength < strength[need_id]) {
				cant[need_id] = true;
				current = (current + 1) % 5;
				sumcant++;
				if (!canmake()) {
					cout << team_name[id] << " headquarter stops making warriors" << endl;
				}
			} else {
				warrior_id++;
				num[need_id]++;
				current = (current + 1) % 5;
				total_strength -= strength[need_id];
				cout << team_name[id] << " " << warrior_name[need_id] << " " << warrior_id 
						<< " born with strength " << strength[need_id] << "," << num[need_id] << " " 
						<< warrior_name[need_id] << " in " << team_name[id] << " headquarter" << endl;
				Printwarrior(need_id,warrior_id);
				break;

			}
		}
	}
	void Printwarrior(int need_id, int warrior_id) {
		switch(need_id){// dragon0 、ninja1、iceman2、lion3、wolf 4
			case 0: {dragon dg(warrior_id, strength[need_id], total_strength); break; }
			case 1: {ninja nj(warrior_id, strength[need_id]); break; }
			case 2: {iceman im(warrior_id, strength[need_id]); break; }
			case 3: {lion ln(warrior_id, strength[need_id], total_strength); break; }
			case 4: {wolf wf(warrior_id, strength[need_id]); break; }
		}
	}
};

int main(){
	int total_case;
	cin >> total_case;
	int total_strength_input;
	int strength_input[5];
    for(int caseid = 1; caseid <=  total_case; ++caseid) {
    	cin >> total_strength_input;
    	for (int i = 0; i < 5; ++i) {
    		cin >> strength_input[i];
    	}
    	cout<<"Case:"<<caseid<<endl;
    	headquarter red(0, total_strength_input, strength_input);
    	headquarter blue(1, total_strength_input, strength_input);
    	int time = 0;

    	while(red.canmake() || blue.canmake()) {
    		if (red.canmake()) {
    			cout << setw(3) << setfill('0') << time << " ";
    			red.make();
    		}
    		if (blue.canmake()) {
    			cout << setw(3) << setfill('0') << time << " ";
    			blue.make();
    		}
    		time++;
    	}
    }
	return 0;
}
