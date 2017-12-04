//Sort given player and names in descending order
//
#include <iostream>
#include <vector>

using namespace std;

struct Player {
    string name;
    int score;
}; 

int isLesser ( Player player1, Player player2 ) {

	if ( player1.score < player2.score )
		return true;
	else if ( ( player1.score == player2.score ) && ( player1.name.compare ( player2.name ) > 0) )
		return true;

	else
		return false;
}

void swap(Player &player1, Player &player2) {

	Player temp = player1;
	player1 = player2;
	player2 = temp;
}


int partition ( vector<Player>& players, int low, int high) {

	Player pivot = players[high];
	
	int i = low-1;

	for ( int j = low; j < high; j ++ ){

		//Not flag to make it descending
	
		if ( !isLesser ( players[j], pivot ) ){
				
			i++;
			swap(players[i], players[j]);

		}
	
	}

	swap( players[i+1], players[high] );
	return i+1;


}


void quickSort( vector<Player>& players, int low, int high) {

	if ( low < high ) {
	
		int p = partition( players, low, high);

		quickSort( players, low, p-1);
		quickSort ( players, p+1, high);
	}

}

vector<Player> comparator(vector<Player> players) {

	quickSort( players , 0, players.size() - 1);
	return players;

}

int main() {
    
    int n;
    cin >> n;
    vector< Player > players;
    string name;
    int score;
    for(int i = 0; i < n; i++){
	    cout<<"\nEnter name and score of player "<<i+1<<" :";
        cin >> name >> score;
        Player p1;
        p1.name = name, p1.score = score;
        players.push_back(p1);
    }
    
    vector<Player > answer = comparator(players);
    cout<<"\n Sorted Players\n";
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i].name << " " << answer[i].score << endl;
    }
    return 0;
}
