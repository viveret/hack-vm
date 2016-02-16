#include "VM.hpp"
#include "Core.hpp"

namespace VM
{
	ubyte* Memory_Main = NULL;
	ubyte* Memory_Temp = NULL;

	vm_uint Mem_Main_Size = 0;
	vm_uint Mem_Temp_Size = 0;

	vm_uint Instruct_Ptr = 0;
}
using namespace VM;
using namespace VM_Instruct;

#define MEM(X) *(((vm_uint*)Memory_Main) + X)

vm_uint VM::Mem_Alloc( vm_uint Amount )
{
	return 0;
}

void VM::Mem_Free( vm_uint Where )
{

}

void VM::Mem_Copy( vm_uint Where, vm_uint To, vm_uint Amount )
{

}

void VM::Instruction_Pointer_Do()
{
	switch( Memory_Main[ Instruct_Ptr ] )
	{
		case VM_SET:
			// Next 2 ints describe memory locations
			MEM(MEM(Instruct_Ptr + sizeof(vm_uint))) = MEM(MEM(Instruct_Ptr + vm_uint_SIZE * 2));
			Instruct_Ptr += vm_uint_SIZE * 2;
			break;
		case VM_ADD:
			// Next 2 ints describe memory locations
			MEM(MEM(Instruct_Ptr + vm_uint_SIZE)) += MEM(MEM(Instruct_Ptr + vm_uint_SIZE * 2));
			Instruct_Ptr += vm_uint_SIZE * 2;
			break;
		case VM_SUB:
			// Next 2 ints describe memory locations
			MEM(MEM(Instruct_Ptr + vm_uint_SIZE)) -= MEM(MEM(Instruct_Ptr + vm_uint_SIZE * 2));
			Instruct_Ptr += vm_uint_SIZE * 2;
			break;
		case VM_MUL:
			// Next 2 ints describe memory locations
			MEM(MEM(Instruct_Ptr + vm_uint_SIZE)) *= MEM(MEM(Instruct_Ptr + vm_uint_SIZE * 2));
			Instruct_Ptr += vm_uint_SIZE * 2;
			break;
		case VM_DIV:
			// Next 2 ints describe memory locations
			MEM(MEM(Instruct_Ptr + vm_uint_SIZE)) /= MEM(MEM(Instruct_Ptr + vm_uint_SIZE * 2));
			Instruct_Ptr += vm_uint_SIZE * 2;
			break;
		case VM_POW:
			break;
		case VM_EXT:
			break;
	}

	Instruct_Ptr += vm_uint_SIZE;
}

void VM::Instruction_Pointer_Set( vm_uint Where )
{
	Instruct_Ptr = Where;
}

vm_uint VM::Instruction_Pointer_Get()
{
	return Instruct_Ptr;
}


#include <fstream>
#include <sstream>
#include <vector>

struct Name_Val
{
	std::string Name;
	vm_uint Value;
};

void VM::Compile( std::string Source_Name, std::string Output_Name )
{
	printf( "Source name: '%s', Output name: '%s'\n", Source_Name.c_str(), Output_Name.c_str() );

	std::string Source;
	{
		std::ifstream Source_F( Source_Name );
		std::stringstream Get_Src; Get_Src << Source_F.rdbuf();
		Source = Get_Src.str();
	}

//	printf( "Content: %s\n", Source.c_str() );

	std::vector<std::string> Tokens;

	for( ssize_t i = 0; i < Source.length(); i++ )
	{
		if( Source[i] == '\n' || Source[i] == '\r' )
			Source[i] = ' ';
	}

	ssize_t Src_Pos;
	while( (Src_Pos = Source.find( ' ' )) != std::string::npos )
	{
		std::string nToken = Source.substr( 0, Src_Pos );
		Tokens.push_back( nToken );
		Source.erase( 0, Src_Pos + 1 );
	}

	std::vector< vm_uint > VM_Tokens;
	std::map< Name_Val, uchar > Names; // Names + types

	for( vm_uint t = 0; t < Tokens.size(); t++ )
	{
		if( Tokens[t][0] == ':' ) // label
		{
			
		}
		else
			VM_Tokens.push_back( Str_To_Instruct( Tokens[t] ) );

		bool Check_Name = false;
		if( Tokens[t] == "set" || Tokens[t] == "mov" )
		{

//			if( Tokens[t]
//			VM_Tokens.push_back( );
		}
	}


	// Now output binary
	std::ofstream Out_F( Output_Name, std::ios::binary | std::fstream::out );
//	if( Out_F.is_good() )
	{
		unsigned int Sig_Buf = VM_SIGNATURE;
		Out_F.write( (char*)&Sig_Buf, sizeof(int) );
		for( vm_uint i = 0; i < VM_Tokens.size(); i++ )
			Out_F.write( (char*)VM_Tokens.data() + i * sizeof(vm_uint), sizeof(vm_uint) );
	}

	printf( "Successfully compiled '%s'\n", Source_Name.c_str() );
}

vm_uint VM::Str_To_Instruct( const std::string& What )
{
	return 0;
}

vm_uint VM::Str_To_Instruct( const char* What )
{
	return 0;
}

void VM::Initialize( vm_uint Mem_Main_Amount, vm_uint Mem_Temp_Amount )
{

}

void VM::Cleanup()
{

}
