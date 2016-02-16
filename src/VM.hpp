#ifndef VM_CORE
#define VM_CORE

#include "Types.hpp"
#include <string>


namespace VM
{
	void Initialize( vm_uint Mem_Main_Amount, vm_uint Mem_Temp_Amount );
	void Cleanup();

	vm_uint Mem_Alloc( vm_uint Amount ); // Allocate memory
	void Mem_Free( vm_uint Where );

	void Mem_Copy( vm_uint Where, vm_uint To, vm_uint Amount );

	void Instruction_Pointer_Do();
	void Instruction_Pointer_Set( vm_uint Where );
	vm_uint Instruction_Pointer_Get();

	vm_uint Str_To_Instruct( const std::string& What );
	vm_uint Str_To_Instruct( const char* What );

	void Compile( std::string Source_Name, std::string Output_Name );
}

namespace VM_Instruct
{enum {
	VM_N_A = 0,

	// Regular memory
	VM_SET, VM_MOV = VM_SET, // Single copy
	VM_CPY, // Copy amount

	VM_JMP,

	// Math
	VM_ADD, VM_SUB,
	VM_MUL, VM_DIV,
	VM_POW,

	// General purpose
	VM_EXT, // Extensions

	// VM Related
	VM_PTR, // Set instruct ptr
	VM_ERROR
};}


#endif
