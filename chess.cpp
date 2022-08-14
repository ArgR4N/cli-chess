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
    vector<vector< Piece>> table;
    vector<Player > players;
    bool turn; //true = white || false == black
    void move(vector<int> beg, vector<int> end){
        //Move (TO DO) =>		
        if(beg == end) return; //Check no imposible move
        if(turn != table[beg[0]][beg[1]].color) return; //Check color
        //TO DO => Check if move is illegal, make castle, check jaque mate; 
        table[end[0]][end[1]] = table[beg[0]][beg[1]];
        table[beg[0]][beg[1]] = Piece(6, 0);
        turn = !turn; //Check player turn || TO DO => Move this to other place;
    };

    Chess(): players({Player("b"), Player("w")}), table() {};
  
    void print_table(){
        cout << "  ";
        for(int i = 0; i <= 7; i++){
            cout << i << " ";
        }
        cout << endl;
        for(int i = 0; i < 8; i++){
                cout << i << " ";
            for(int j = 0; j < 8; j++){
                cout << table[i][j].getFigure(i, j) << " ";
            }
            cout << endl;
        }
    };

    void print_turn(){
        turn ? cout << "White" : cout << "Black";
        cout << "`s Turn." << endl;
    }

    void init_game_loop(){
        while(true){
            system("cls"); //Clean terminal*
            system("clear"); //Clean terminal*
            print_turn();
            print_table(); // Print table
            vector<int> beg (2), end (2);
            cout << "beg? "; //Inicio => Pieza || Casilla vacia || Ficha clavada
            cin >> beg[0] >> beg[1];
            while(beg[0] < 0 || beg[0] > 7 || beg[1] < 0 || beg[1] > 7){
                cout << "Ingrese valores entre 0 y 7: ";
                cin >> beg[0] >> beg[1];	
            }
            cout << "end? "; //Fin => Casilla Vacia || Pieza Aliada (Ilegal) || Pieza Enemiga (Comer) || Rey
            cin >> end[0] >> end[1];
            while(end[0] < 0 || end[0] > 7 || end[1] < 0 || end[1] > 7){
                cout << "Ingrese valores entre 0 y 7: ";
                cin >> end[0] >> end[1];	
            }
            move(beg, end);
	    }
    };
};

int main(){
    vector< vector<Piece> > initTable;
    //0 => Dama
    //1 => Rey
    //2 => Alfil
    //3 => Torre
    //4 => Caballo
    //5 => Peon
    //6 => Casilla
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
        Chess game;
        game.table = initTable;
        game.init_game_loop();
        break;
    }
};