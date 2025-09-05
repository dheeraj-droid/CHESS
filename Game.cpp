#include "Game.hpp"
#include "ExtractMove.hpp"
//Input format e2-e4


    Game::Game()
    {
        curr_player = "white";
    }

    void Game::play()  const
    {
        while(true)
        {

            new_board1.display();
            string move;
            cout << "Enter your move %(a1--b2)%" <<endl;
            cin >>  move;
            auto move_coods = ExtractMove::get_move(move);
            if(move_coods.size()==0)
            cout << "INVALID MOVE" << endl;
            else
            cout << move_coods[0].first << move_coods[0].second << move_coods[1].first << move_coods[1].second << endl;        
        }
    }
