/**
 * File: reverse_byte.c
 * Author: Jack Liao
 * Description: 
 * Created on: 2025-10-25 16:42:08
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

uint16_t swap_uint16( uint16_t val ) 
{
	return (val >> 8) | (val << 8);
}

//! Byte swap short
int16_t swap_int16( int16_t val ) 
{
	return (val << 8) | ((val >> 8) & 0xFF);
}

//! Byte swap unsigned int
uint32_t swap_uint32( uint32_t val )
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return ((val << 16) & 0xFFFF0000) | ((val >> 16) & 0xFFFF);
}

//! Byte swap int
int32_t swap_int32( int32_t val )
{
	//12345678 22345678 32345678 42345678
	// f   f    0   0    f   f    0   0  
	// 0   0    f   f    0   0    f   f
	//2234567812345678 4234567832345678
	// 0   0   0   0     f   f   f   f
	// f   f   f   f     0   0   0   0
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0x00FF00FF);
	return ((val << 16) & 0xFFFF0000) | ((val >> 16) & 0x0000FFFF);
}

int64_t swap_int64( int64_t val )
{
}

uint64_t swap_uint64( uint64_t val )
{
}

int main(int argc, char *argv[]) {

	unsigned short input = 0x1234;
	uint16_t u16 = 0x1234;
	int16_t  s16 = 0x1234;
	uint32_t u32 = 0x12345678;
	int32_t  s32 = 0x12345678;
	uint64_t u64 = 0x1122334455667788ULL;
	int64_t  s64 = 0x1122334455667788LL;

	printf("Original 16-bit (unsigned): 0x%04X -> Swapped: 0x%04X\n", u16, swap_uint16(u16));
	printf("Original 16-bit (signed):   0x%04X -> Swapped: 0x%04X\n", (uint16_t)s16, (uint16_t)swap_int16(s16));

	printf("Original 32-bit (unsigned): 0x%08X -> Swapped: 0x%08X\n", u32, swap_uint32(u32));
	printf("Original 32-bit (signed):   0x%08X -> Swapped: 0x%08X\n", (uint32_t)s32, (uint32_t)swap_int32(s32));

	//printf("Original 64-bit (unsigned): 0x%016llX -> Swapped: 0x%016llX\n",(unsigned long long)u64, (unsigned long long)swap_uint64(u64));

	//printf("Original 64-bit (signed):   0x%016llX -> Swapped: 0x%016llX\n",(unsigned long long)s64, (unsigned long long)swap_int64(s64));

	return 0;
}


