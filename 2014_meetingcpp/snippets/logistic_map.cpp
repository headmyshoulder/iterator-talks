/*
 * logistic_map.cpp
 * Date: 2014-11-10
 * Author: Karsten Ahnert (karsten.ahnert@gmx.de)
 * Copyright: Karsten Ahnert
 *
 *
 */


#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

double logistic_map( double x , double r )
{
    return r * x * ( 1.0 - x );
}

class binner
{
public:

    binner( size_t num_bins = 1000 )
    : m_bins( num_bins , 0 ) {}

    void operator()( double x )
    {
        size_t index = static_cast< size_t >( x * static_cast< double >( m_bins.size() ) );
        assert( index < m_bins.size() );
        m_bins[ index ]++;
    }

    bool is_bin( size_t i ) const { return ( m_bins[i] != 0 ); }

    double bin_value( size_t i ) const { return ( double( i ) + 0.5 ) / double( m_bins.size() ); }

    size_t size( void ) const { return m_bins.size(); }

private:

    std::vector< size_t > m_bins;
};


int main( int argc , char *argv[] )
{
    cout.precision( 14 );
    for( double r = 2.8 ; r < 4.0 ; r += 0.001 )
    {
        double x = 0.5;
        for( size_t i=0 ; i<10000 ; ++i )
        {
            x = logistic_map( x , r );
        }

        // binner bins( 4000 );
        for( size_t i=0 ; i<2000 ; ++i )
        {
            x = logistic_map( x , r );
//             bins( x );
            cout << r << " " << x << "\n";
        }


        // for( size_t i=0 ; i<bins.size() ; ++i )
        // {
        //     if( bins.is_bin( i ) )
        //     {
        //         cout << r << " " << bins.bin_value( i ) << "\n";
        //     }
        // }
    }
    return 0;
}
