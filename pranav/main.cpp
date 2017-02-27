#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <climits>
#include <iomanip>
using namespace std;

typedef long long ll;

#include "PlayerClass.h"
#include "StateClass.h"
#include "GameClass.h"

int main() {
	//Game runner;
	//runner.begin();
	Game game(3);
	game.simulateGame();
	return 0;
}

