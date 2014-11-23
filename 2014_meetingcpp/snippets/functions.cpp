/*
 * functions.cpp
 * Date: 2014-11-23
 * Author: Karsten Ahnert (karsten.ahnert@gmx.de)
 * Copyright: Karsten Ahnert
 *
 *
 */

#include <boost/range/counting_range.hpp>
#include <boost/range/adaptor/transformed.hpp>
#include <boost/range/algorithm/for_each.hpp>
#include <boost/iterator/zip_iterator.hpp>

#include <iostream>
#include <tuple>

using namespace std;

auto sin_seq( int n , double sampling )
{
    auto seq = boost::counting_range( 0 , n );
    auto seq2 = seq | boost::adaptors::transformed( [sampling]( auto x ) { return sampling * static_cast< double >( x ); } );
    return seq2 | boost::adaptors::transformed( []( auto x ) { return 0.25 * sin( x ) + 0.03; } );
}


template< typename T >
auto arb_seq( int n , double sampling , T f )
{
    auto seq = boost::counting_range( 0 , n );
    return seq | boost::adaptors::transformed( [sampling,f]( auto x ) { return f( sampling * static_cast< double >( x ) ); } );
}

template< typename R1 , typename R2 >
auto zip( R1 r1 , R2 r2 )
{
    return std::make_pair(
        boost::make_zip_iterator( boost::make_tuple( boost::begin( r1 ) , boost::begin( r2 ) ) ) ,
        boost::make_zip_iterator( boost::make_tuple( boost::end( r1 ) , boost::end( r2 ) ) ) );
}

template< typename T >
auto sequence2( int n , double sampling , T f )
{
    auto seq = boost::counting_range( 0 , n );
    return seq | boost::adaptors::transformed( [sampling,f]( auto i ) {
            double x = sampling * static_cast< double >( i );
            return std::make_tuple( x , f( x ) ); } );

}

int main( int argc , char *argv[] )
{
    int n = 10;

    auto seq1 = arb_seq( n , 0.1 , []( auto x ) { return sin( 2.0 * x ) + 0.1; } );
    auto seq2 = arb_seq( n , 0.1 , []( auto x ) { return sin( 2.0 * x + 0.1 ) - 0.1; } );
    auto zipped = zip( seq1 , seq2 );
    boost::for_each( zipped , []( auto x ) {
            cout << boost::get< 0 >( x ) << " " << boost::get< 1 >( x ) << endl; } );


    auto zseq = sequence2( n , 0.1 , []( auto x ) { return sin( 2.0 * x ) + 0.1; } );
    for( auto x : zseq )
        cout << std::get< 0 >( x ) << " " << std::get< 1 >( x ) << "\n";

    return 0;
}
