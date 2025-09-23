#include "Game.hpp"
#include "ExtractMove.hpp"

// Input format e2-e4

Game::Game()
{
    curr_player_color = PlayerColor::White;
}

bool Game::is_promotion_possible(Piece* curr_piece,int y) const
{
            if (curr_piece->get_type() == PieceType::Pawn)
            {
                if (curr_piece->get_color() == PlayerColor::White && y == 7)
                {
                    return true;
                }
                else if (curr_piece->get_color() == PlayerColor::Black && y == 0)
                {
                    return  true;
                }
            }
            return  false;
}



Piece* Game::promote_pawn(char choice,pair<int,int>& after,PlayerColor color) 
{         
                switch (toupper(choice))
                {
                case 'Q':
                    return new Queen(after.first, after.second, color);
                case 'N':
                    return new Knight(after.first, after.second, color);
                case 'R':
                   return new Rook(after.first, after.second,color);
                case 'B':
                    return new Bishop(after.first, after.second,color);
                default:
                    return new Queen(after.first, after.second,color); 
                }
}

void Game::display_board_and_prompt() const {
    new_board1.display();
    string player_col;
    player_col  = (curr_player_color==PlayerColor::White)?"White" : "Black";
    std::cout << "Player " << player_col  << ", enter your move (e.g., e2--e4): " << std::endl;
}


string Game::get_player_move() const{
    std::string move;
    std::cin >> move;
    return move;
}

void Game::switch_player() {
    curr_player_color = (curr_player_color == PlayerColor::White) ? PlayerColor::Black : PlayerColor::White;
}




bool Game::validate_move(const vector<pair<int, int>>& positions)  const {
       pair<int, int> before = positions[0];
         pair<int, int> after = positions[1];
         Piece *p = new_board1.get_piece_at_pos(before.first, before.second);
     if (p == nullptr)
         {
            cout << "INVALID MOVE: No piece at the starting square.Try again.\n" << endl;
             return false;
         }
         if (p->get_color() != curr_player_color)
         {
             cout << "INVALID MOVE: That piece does not belong to you.Try again.\n" << endl;
             return false;
         }

        auto valid_moves = p->get_valid_moves(new_board1);

         for (const auto &valid_move : valid_moves)
         {
             if (valid_move == positions[1])
             {

                 return true;;
             }
         }
         cout << "INVALID MOVE: The selected piece cannot move to that square.Try again.\n" << endl;
         return false;
}


void Game::execute_castling(const vector<pair<int, int>>& positions,Piece* p)
{
    pair<int, int> before = positions[0];
    pair<int, int> after = positions[1];

       if(before.second  > after.second)
       {
        Piece* rook = new_board1.get_piece_at_pos(before.first,before.second-4);
        rook->set_curr_pos(after.first,after.second+1);
        new_board1.set_piece_at_pos(nullptr,before.first,before.second - 4);
        new_board1.set_piece_at_pos(rook,after.first,after.second+1);
       }
       else
       {
        Piece* rook = new_board1.get_piece_at_pos(before.first,before.second+3);
        rook->set_curr_pos(after.first,after.second-1);
        new_board1.set_piece_at_pos(nullptr,before.first,before.second + 3);
        new_board1.set_piece_at_pos(rook,after.first,after.second - 1);
       }
       return;
}


void Game::execute_move(const vector<pair<int, int>>& positions) {
    pair<int, int> before = positions[0];
    pair<int, int> after = positions[1];
    Piece *p = new_board1.get_piece_at_pos(before.first, before.second);

      if(p->get_type() == PieceType::King && abs(before.second - after.second) > 1)
        execute_castling(positions,p);

    bool is_promotion = is_promotion_possible(p, after.first);

    p->set_curr_pos(after.first, after.second);
    Piece *captured_piece = new_board1.get_piece_at_pos(after.first, after.second);

    if (captured_piece != nullptr) {
        captured_piece->set_capture(true);
        captured_piece->set_curr_pos(-1, -1);
    }

    new_board1.set_piece_at_pos(nullptr, before.first, before.second);
    new_board1.set_piece_at_pos(p, after.first, after.second);

    

    if (is_promotion) {
        cout << "Pawn promotion! Enter Q for Queen, N for Knight, R for Rook, B for Bishop: ";
        char choice;
        cin >> choice;
        Piece *new_piece = promote_pawn(choice, after, p->get_color());
        delete p;
        p = nullptr;
        new_board1.set_piece_at_pos(new_piece, after.first, after.second);
        p = new_piece;
    }

    if (!p->get_if_moved())
        p->set_if_moved(true);

    if (captured_piece != nullptr && captured_piece != p) {
        delete captured_piece;
        captured_piece = nullptr;
    }
}

bool Game::check_game_end() {
    // Check for checkmate, stalemate, etc.
    // Return true if game should end
    return false;
}

void Game::play()
{

    while (true)
    {
        display_board_and_prompt();
        string move = get_player_move();
        if (!ExtractMove::match_pattern(move)) {
            cout << "Invalid move format. Try again.\n";
            continue;
        }
        

        auto positions = ExtractMove::get_move(move);
        if (!validate_move(positions)) {
            continue;
        }

        execute_move(positions);

        if (check_game_end()) break;
        switch_player();


     
    }
}
