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
#include <thread>
#include <chrono>

using namespace std;

static const size_t dim_x = 24;
static const size_t dim_y = 24;

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
    std::cout << "\n";
}

size_t get_index( int i , size_t dim )
{
    if( i < 0 ) return i + dim;
    if( i >= dim ) return i - dim;
    return i;
}

size_t get_neighbors( board b , size_t i , size_t j )
{
    size_t count = 0;
    for( int k=-1 ; k<=1 ; ++k )
    {
        for( int l=-1 ; l<=1 ; ++l )
        {
            if( ( k == 0 ) && ( l == 0 ) ) continue;
            size_t index1 = get_index( int( i ) + k , dim_y );
            size_t index2 = get_index( int( j ) + l , dim_x );
            if( b[index1][index2] ) ++count;
        }
    }
    return count;
}

board next( board const& b )
{
    board new_board = get_empty_board();
    for( size_t i=0 ; i<b.size() ; ++i )
    {
        for( size_t j=0 ; j<b[i].size() ; ++j )
        {
            size_t neighbors = get_neighbors( b , i , j );
            if ( neighbors == 3 ) new_board[i][j] = true;
            else if( ( b[i][j] == true ) && ( neighbors == 2 ) ) new_board[i][j] = true;
        }
    }
    return new_board;
}




int main( int argc , char *argv[] )
{
    using namespace std;

    board b = get_empty_board();
    // b[10][10] = true;
    // b[10][11] = true;
    // b[11][10] = true;
    // b[11][11] = true;
    b[10][10] = true;
    b[10][11] = true;
    b[10][12] = true;

auto r = 

    for( size_t i=0 ; i<100 ; ++i )
    {
        std::cout << "Iteration " << i << std::endl;
        show_board( b );
        b = next( b );
        std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
    }

    return 0;
}
