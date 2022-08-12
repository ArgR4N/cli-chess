#include<bits/stdc++.h>

using namespace std;

struct Player {
    string name; 
    Player(string s ): name(s) {};
};

float piecesValues[6] = {9, 0, 5, 3.5, 3, 1};
string piecesFigures[2][7] = {{"♕", "♔", "♗", "♖" , "♘", "♙", "■"}, {"♛", "♚", "♝",  "♜", "♞", "♟", "□"}};

struct Piece {
    int type; 
    int color;
    float value;
    bool checkMove(vector< vector<int> > positions){
        return false;
    };

    string getFigure(int x, int y){
        if(type == 6){
            if(x % 2 == 0 && y % 2 != 0 || x % 2 != 0 && y % 2 == 0) return piecesFigures[1][type];
            else return piecesFigures[0][type];
        }
        return piecesFigures[color][type];
    }
    Piece(int t, int pos): type(t), value(piecesValues[t]), color(pos >= 4 ? 1 : 0) {};
};

struct Chess {
    vector< int> table;
    vector<Player > players;
    Chess(): players({Player("b"), Player("w")}), table() {};
};

int main(){
    vector< vector<Piece> > initTable;
    //0 => Dama
    //1 => Rey
    //2 => Alfil
    //3 => Torre
    //4 => Caballo
    //5 => Peon
    for(int i = 0; i < 8; i++){
        vector< Piece> newRow;
        for(int j = 0; j < 8; j++){
            if(i > 1 && i < 6) {newRow.push_back(Piece(6, i)); continue;} 
            if(i == 1 || i == 6){newRow.push_back(Piece(5, i)); continue;} 
            switch(j){
                case 0: case 7:
                newRow.push_back(Piece(3, i));
                break;     
                case 1: case 6:
                newRow.push_back(Piece(4, i));
                break;
                case 2: case 5:
                newRow.push_back(Piece(2, i));
                break;
                case 4:
                if(j == 0) {newRow.push_back(Piece(1, i)); break;}
                newRow.push_back(Piece(0, i)); break;
                case 3:
                if(j == 0) {newRow.push_back(Piece(0, i)); break;}
                newRow.push_back(Piece(1, i)); break;
            }
        }
        initTable.push_back(newRow);
    }

    while(true){
        for(int i = 0; i <= 8; i++){
            cout << i << " ";
        }
        cout << endl;
        for(int i = 0; i < 8; i++){
                cout << i+1 << " ";
            for(int j = 0; j < 8; j++){
                cout << initTable[i][j].getFigure(i, j) << " ";
            }
            cout << endl;
        }
        Chess game();
        break;
    }
};