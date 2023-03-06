#include<cstdio>
#include<cctype>
#include<iostream>
using namespace std;

int main(){
   int n, m, max_index;
   int runcase = 0;
   string answer, output;
   string input;
   bool ac, pe;
   while( scanf( "%d", &n ) != EOF && n != 0 ){
      getchar();
      answer = "";
      output = "";
      for( int i = 0 ; i < n ; i++ ){
         getline( cin, input );
      if( i ) answer += '\n', answer += input;
      else answer = input;
   }
   scanf( "%d", &m );
   getchar();
   for( int i = 0 ; i < m ; i++ ){
      getline( cin, input );
      if( i ) output += '\n', output += input;
      else output = input;
   }
   ac = true;
   if( answer != output ) ac = false;
   if( ac ){
      printf( "Run #%d: Accepted\n", ++runcase );
      continue;
   }
   pe = true;
   for( int i = 0 ; i < answer.length() ; i++ )
      if( !isdigit(answer[i]) ) answer.erase(i,1), i--;
   for( int i = 0 ; i < output.length() ; i++ )
      if( !isdigit(output[i]) ) output.erase(i,1), i--;
    max_index = max( m, n );
    if( answer != output ) pe = false;
    if( pe ){
       printf( "Run #%d: Presentation Error\n", ++runcase );
       continue;
   }
   printf( "Run #%d: Wrong Answer\n", ++runcase );
 }
 return 0;
}
