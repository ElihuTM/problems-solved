#include <iostream>
#include <string>

using namespace std;

string transfom( string &T, char digit ) {
    string ans = T;
    for (int i = 0; i < ans.size(); ++i)
        if( ans[ i ] == '?' )
            ans[ i ] = digit;
    return ans;
}

int toInt( int dec, int unit ) {
    return dec * 10 + unit;
}

bool is_possible( string &time ) {
    int hours = toInt( time[ 0 ] - '0', time[ 1 ] - '0' );
    int minutes = toInt( time[ 3 ] - '0', time[ 4 ] - '0');

    if( 0 <= hours and hours < 24 )
        if ( 0 <= minutes and minutes < 60 )
            return true;
    return false;
}

string solution(string T) {
    
    for ( char i = '9'; i >= '0' ; --i) {
        string current_time = transfom( T, i );
        
        if( is_possible( current_time ) )
            return current_time;
    }

    return T;
}

int main() {
  // Read from stdin, solve the problem, write answer to stdout.
  string input;
  cin >> input;
  cout << "\"" << solution(input.substr(1, 5)) << "\"";
}
