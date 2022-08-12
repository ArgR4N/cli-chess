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
    float value;
    bool checkMove(vector< vector<int> > positions){
        return false;
    };
    Piece(int t): type(t), value(piecesValues[t]) {};
};

struct Chess {
    vector< int> table;
    vector<Player > players;
    Chess(): players({Player("b"), Player("w")}), table() {};
};

int main(){
    vector< vector<Piece> > initTable (8, vector<Piece> (8, 6));
    //0 => Dama
    //1 => Rey
    //2 => Alfil
    //3 => Torre
    //4 => Caballo
    //5 => Peon
    for(int i = 0; i < initTable.size(); i++){
        for(int j = 0; j < initTable[0].size(); j++){
            if(i > 1 && i < 6) continue;
            if(i == 1 || i == 6){initTable[i][j] = Piece(5); continue;} 
            switch(j){
                case 0: case 7:
                initTable[i][j] = Piece(3);
                break;     
                case 1: case 6:
                initTable[i][j] = Piece(4);
                break;
                case 2: case 5:
                initTable[i][j] = Piece(2);
                break;
                case 4:
                if(j == 0) initTable[i][j] = Piece(1);
                else initTable[i][j] = Piece(0);
                break;
                case 3:
                if(j == 0) initTable[i][j] = Piece(0);
                else initTable[i][j] = Piece(1);
                break;
            }
        }
    }

    while(true){
        for(int i = 0; i <= 8; i++){
            cout << i << " ";
        }
        system("color %");
        cout << endl;
        for(int i = 0; i < initTable.size(); i++){
                cout << i+1 << " ";
            for(int j = 0; j < initTable[0].size(); j++){
                if(initTable[i][j].type == 6){
                    if(i % 2 == 0 && j % 2 != 0 || i % 2 != 0 && j % 2 == 0) cout << piecesFigures[1][initTable[i][j].type] << " ";
                    else cout << piecesFigures[0][initTable[i][j].type] << " ";
                    continue;
                }

                if(i > 4 ) cout << piecesFigures[1][initTable[i][j].type] << " ";
                else cout << piecesFigures[0][initTable[i][j].type] << " ";
            }
            cout << endl;
        }
        Chess game();
        break;
    }

};