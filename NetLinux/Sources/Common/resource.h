#pragma once
#include <stdlib.h>

extern const size_t RM_MAX_MANAGE;
extern const size_t RM_REDUCE_COND;
extern const float RM_REDUCE_RATIO;

// manages registered buffers and descriptors
// using bind/release functions
typedef struct _resource_manager
{
	void** pmemory;
	size_t mem_size;
	size_t mem_capacity;
	int* pdescriptor;
	size_t desc_size;
	size_t desc_capacity;
} resource_manager;

// initializes resource manager
void init_manager(resource_manager* rm, size_t num_buffer, size_t num_descriptor);
// initializes helper function
void init_manager_auto(resource_manager* rm);
// releases all binding resources
void release_manager(resource_manager* rm);


// bind memory to resource_manager. return 1 if success, otherwise -1
int bind_memory(resource_manager* rm, void* buffer);
// bind descriptor(os resources) to resource_manager. return 1 if success, 0 if full capacity, -1 if error
int bind_descriptor(resource_manager* rm, int descriptor);
// release memory specified pointer. return 1 if success, otherwise -1
int release_memory(resource_manager* rm, void* buffer);
// release descriptor specified pointer. return 1 if success, otherwise -1. (no implements currently)
int release_descriptor(resource_manager* rm, int descriptor);

