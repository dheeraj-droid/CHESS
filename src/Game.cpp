#include "Game.hpp"
#include "ExtractMove.hpp"

// Input format e2-e4

Game::Game()
{
    curr_player = "white";
}

bool Game::is_promotion_possible(Piece* curr_piece,int y) const
{
            if (curr_piece->get_type() == "P")
            {
                if (curr_piece->get_color() == "white" && y == 7)
                {
                    return true;
                }
                else if (curr_piece->get_color() == "black" && y == 0)
                {
                    return  true;
                }
            }
            return  false;
}



Piece* Game::promote_pawn(char choice,pair<int,int>& after,string color) 
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
    std::cout << "Player " << curr_player << ", enter your move (e.g., e2--e4): " << std::endl;
}


string Game::get_player_move() const{
    std::string move;
    std::cin >> move;
    return move;
}

void Game::switch_player() {
    curr_player = (curr_player == "white") ? "black" : "white";
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
         if (p->get_color() != curr_player)
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

void Game::execute_move(const vector<pair<int, int>>& positions) {
    pair<int, int> before = positions[0];
    pair<int, int> after = positions[1];
    Piece *p = new_board1.get_piece_at_pos(before.first, before.second);

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
