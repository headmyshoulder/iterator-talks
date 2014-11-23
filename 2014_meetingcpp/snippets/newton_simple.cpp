/*
 * newton_simple.cpp
 * Date: 2014-11-23
 * Author: Karsten Ahnert (karsten.ahnert@gmx.de)
 * Copyright: Karsten Ahnert
 *
 *
 */


#include <iostream>
#include <cmath>

using namespace std;


int main( int argc , char *argv[] )
{
    double x = 1.0;
    auto f = []( auto x ) { return exp( - x * x ) - 0.5 ; };
    auto df = []( auto x ) { return -2.0 * x * exp( - x * x ); };

    while( std::abs( f(x) ) > 1.0e-12 )
    {
        cout << x << " " << f(x) << endl;
        x = x - f(x) / df( x );
    }

    return 0;
}
