/*
 * game_of_life.cpp
 * Date: 2014-11-26
 * Author: Karsten Ahnert (karsten.ahnert@gmx.de)
 * Copyright: Karsten Ahnert
 *
 *
 */


#include <iostream>
#include <array>

static const size_t dim_x = 32;
static const size_t dim_y = 16;

using board = std::array< std::array< bool , dim_x > , dim_y >;

board get_empty_board( void )
{
    board b;
    for( auto& line : b )
        for( auto& elem : line )
            elem = 0;
    return b;
}

void show_board( board const& b )
{
    for( auto const& line : b )
    {
        for( auto const& elem : line )
        {
            if( elem ) std::cout << "x"; else std::cout << " ";
        }
        std::cout << "\n";
    }
}

board next( board const& b )
{
}




int main( int argc , char *argv[] )
{
    board b = get_empty_board();
    b[10][10] = true;
    show_board( b );
    return 0;
}
