#include "VM.hpp"
using namespace VM;

#include <memory>
#include <string.h>


#define cmp_str( X, Y ) (strcmp(X, Y) == 0)
int main( int argc, char** argv )
{
	for( int i = 0; i < argc; i++ )
	{
//		if( strcmp(argv[i], "--mem-main=
	}

	VM::Initialize( 1024, 16 );

	printf( "~~ Welcome to VM! (by Bennettbugs) ~~\n" );
	char In_Buf[256];
	memset( In_Buf, 0, 256 );

	std::string In_Str;

	while( true )
	{
		printf( "\n\nInput code: " );
		gets( In_Buf );
		In_Str = In_Buf;

		if( In_Str == "exit" || In_Str == "quit" )
			break;

		else if( In_Str == "help" || In_Str == "?")
		{
			printf( "COMMANDS:\n" );
			printf( "compile <source> <output>\n" );
			printf( "run <input> [args]\n" );
		}
		else if( In_Str.find("compile") == 0 )
		{
			In_Str.erase( 0, strlen("compile") + 1 );
			std::string Source, Output_F;
			ssize_t Str_End = 0;

			if( In_Str[0] == '\'' )
			{
				Str_End = In_Str.find( '\'', 2 );
				Source = In_Str.substr( 1, Str_End - 1 );
//				In_Str.erase( 0, Str_End + 1 );
			}
			else if( In_Str[0] == '\"' )
			{
				Str_End = In_Str.find( '\"', 2 );
				Source = In_Str.substr( 1, Str_End - 1 );
//				In_Str.erase( 0, Str_End + 1 );
			}
			else
			{
				Str_End = In_Str.find( ' ', 2 );
				Source = In_Str.substr( 1, Str_End - 1 );
//				In_Str.erase( 0, Str_End + 1 );
			}

			In_Str.erase( 0, Str_End + 2 );

			if( In_Str[0] == '\'' )
			{
				Str_End = In_Str.find( '\'', 2 );
				Output_F = In_Str.substr( 1, Str_End - 1 );
				In_Str.erase( 0, Str_End );
			}
			else if( In_Str[0] == '\"' )
			{
				Str_End = In_Str.find( '\"', 2 );
				Output_F = In_Str.substr( 1, Str_End - 1 );
				In_Str.erase( 0, Str_End );
			}
			else
			{
				Str_End = In_Str.length();
				Output_F = In_Str.substr( 0, Str_End );
				In_Str.erase( 0, Str_End );
			}
			VM::Compile( Source, Output_F );
		}
		else
		{
			printf( "Bad input\n" );
		}
	}

	return 0;
}
