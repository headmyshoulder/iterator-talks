/*
 * examples_io.cpp
 * Date: 2014-10-26
 * Author: Karsten Ahnert (karsten.ahnert@gmx.de)
 * Copyright: Karsten Ahnert
 *
 *
 */


#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;



int main( int argc , char *argv[] )
{
    vector< double > values;

    // use CTRL+d for eof
    copy_if( istream_iterator< double >( cin ) ,
             istream_iterator< double >() ,
             back_inserter( values ) ,
             []( double x ) { return x > 0.0; } );
    copy_if( values.begin() , values.end() ,
             ostream_iterator< double >( std::cout , "\n" ) ,
             []( double x ) { return x < 10.0; } );

    return 0;
}
