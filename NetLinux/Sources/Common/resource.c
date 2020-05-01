#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <malloc.h>
#include <unistd.h>
#include "resource.h"

// resource manager global constants
const size_t RM_MAX_MANAGE = 2048;
const size_t RM_REDUCE_COND = 128;
const float RM_REDUCE_RATIO = 0.5f;

void init_manager(resource_manager* rm, size_t num_buffer, size_t num_desc)
{
	if (rm == NULL)
		return;

	rm->pmemory = (void**)malloc(sizeof(void*) * num_buffer);
	if (rm->pmemory == NULL)
		return;
	rm->pdescriptor = (int*)malloc(sizeof(int) * num_desc);
	if (rm->pdescriptor == NULL)
	{
		free(rm->pmemory);
		return;
	}
	memset(rm->pdescriptor, 0, sizeof(int) * num_desc);

	rm->mem_capacity = num_buffer;	
	rm->mem_size = 0;
	rm->desc_capacity = num_desc;
	rm->desc_size = 0;
}

void init_manager_auto(resource_manager* rm)
{
	init_manager(rm, 10, 10);
}


int bind_memory(resource_manager* rm, void* buffer)
{
	if (rm == NULL)
		return -1;
	
	// reach max capacity
	if (rm->mem_size == rm->mem_capacity)
	{
		// cant extned then return error
		if (rm->mem_capacity >= RM_MAX_MANAGE)
			return -1;
		
		// extend capacity
		size_t new_capacity;
		if (rm->mem_capacity >= RM_MAX_MANAGE / 2)
			new_capacity = RM_MAX_MANAGE;
		else
			new_capacity = rm->mem_capacity * 2;

		void** new_block = realloc(rm->pmemory, sizeof(void*) * new_capacity);
		if (new_capacity != 0 && new_block == NULL)
			return -1;

		rm->pmemory = new_block;
		new_block = NULL;
		rm->mem_capacity = new_capacity;
	}

	rm->pmemory[rm->mem_size++] = buffer;
	return 1;
}

int bind_descriptor(resource_manager* rm, int descriptor)
{
	if (rm == NULL)
		return -1;

	// reach max capacity
	if (rm->desc_size == rm->desc_capacity)
	{
		// cant extned then return error
		if (rm->desc_capacity >= RM_MAX_MANAGE)
			return -1;

		// extend capacity
		size_t new_capacity;
		if (rm->desc_capacity >= RM_MAX_MANAGE / 2)
			new_capacity = RM_MAX_MANAGE;
		else
			new_capacity = rm->desc_capacity * 2;

		int* new_block = (int*)realloc(rm->pdescriptor, sizeof(int) * new_capacity);
		// realloc function is failed because of out of memory
		if (new_capacity != 0 && new_block == NULL)
			return -1;

		rm->pdescriptor = new_block;
		new_block = NULL;
		rm->desc_capacity = new_capacity;
	}

	rm->pdescriptor[rm->desc_size++] = descriptor;
	return 1;
}

int release_memory(resource_manager* rm, void* buffer)
{
	if (rm == NULL)
		return -1;

	if (rm->mem_size == 0)
		return -1;

	int find = -1;
	for (int i = 0; i < rm->mem_size; ++i)
	{
		if (rm->pmemory[i] == buffer)
		{
			// set flag and free buffer
			find = 1;
			free(rm->pmemory[i]);
			rm->mem_size -= 1;

			// move array elems to left
			int src;
			for (int dest = i; dest < rm->mem_size - 1; ++dest)
			{
				src = dest + 1;
				rm->pmemory[dest] = rm->pmemory[src];
			}

			// reduce mem block if condition meets
			size_t reduced_size = (size_t)((float)rm->mem_capacity * RM_REDUCE_RATIO);
			if (rm->mem_capacity >= RM_REDUCE_COND && rm->mem_size <= reduced_size)
			{
				void** reduce_block = realloc(rm->pmemory, (sizeof(void*) * reduced_size));
				if (reduced_size != 0 && reduce_block == NULL)
					return -1;

				rm->pmemory = reduce_block;
				reduce_block = NULL;
				rm->mem_capacity = reduced_size;
			}
			break;
		}
	}
	return find;
}

int release_descriptor(resource_manager* rm, int descriptor)
{
	if (rm == NULL)
		return -1;

	if (rm->desc_size == 0)
		return -1;

	int find = -1;
	for (int i = 0; i < rm->desc_size; ++i)
	{
		if (rm->pdescriptor[i] == descriptor)
		{
			// set flag and close file descriptor
			find = 1;
			close(rm->pdescriptor[i]);
			rm->desc_size -= 1;

			// move array elems to left
			int src;
			for (int dest = i; dest < rm->desc_size - 1; ++dest)
			{
				src = dest + 1;
				rm->pdescriptor[dest] = rm->pdescriptor[src];
			}

			break;
		}
	}
	return find;
}

void release_manager(resource_manager* rm)
{
	if (rm == NULL)
		return;

	for (int i = 0; i < rm->mem_size; ++i)
		free(rm->pmemory[i]);
	for (int i = 0; i < rm->desc_size; ++i)
		close(rm->pdescriptor[i]);

	free(rm->pmemory);
	free(rm->pdescriptor);
	memset(rm, 0, sizeof(resource_manager));
}

void error_exit(resource_manager* rm, const char* str)
{
	perror(str);
	if (rm)	release_manager(rm);
}