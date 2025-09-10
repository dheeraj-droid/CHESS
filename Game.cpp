#include "Game.hpp"
#include "ExtractMove.hpp"
//Input format e2-e4



    Game::Game()
    {
        curr_player = "white";
    }

    void Game::play() {

    while (true) 
    {

        new_board1.display();
        string move;
        cout << "Player " << curr_player << ", enter your move (e.g., e2--e4): " << endl;
        cin >> move;

        auto move_coods = ExtractMove::get_move(move);
        if (move_coods.empty()) { 
            cout << "INVALID MOVE FORMAT. Please use format like 'a1-b2'." << endl;
            continue;
        }

        pair<int, int> before = move_coods[0];
        pair<int, int> after = move_coods[1];

        Piece* p = new_board1.get_piece_at_pos(before.first, before.second);

       
        if (p == nullptr) {
            cout << "INVALID MOVE: No piece at the starting square." << endl;
            continue;
        }
        if (p->get_color() != curr_player) { 
            cout << "INVALID MOVE: That piece does not belong to you." << endl;
            continue;
        }

        

        auto valid_moves = p->get_valid_moves(new_board1);
        bool move_is_legal = false;

       
        for (const auto& valid_move : valid_moves) {
            if (valid_move == after) {
                move_is_legal = true;
                break;
            }
        }

        if (move_is_legal) {

            p->set_curr_pos(after.first,after.second);
            Piece* captured_piece = new_board1.get_piece_at_pos(after.first,after.second);
            
            if(captured_piece!=nullptr)
            {
            captured_piece->set_capture(true);
            captured_piece->set_curr_pos(-1,-1); 
            }

            new_board1.set_piece_at_pos(nullptr, before.first, before.second);
            new_board1.set_piece_at_pos(p, after.first, after.second);
        
            if(!p->get_if_moved())
            p->set_if_moved(true);

            
            curr_player = (curr_player == "white") ? "black" : "white";
            delete captured_piece;
        } else {
            cout << "INVALID MOVE: The selected piece cannot move to that square." << endl;
        }

    }
}
