/*
 * Copyright (C) 2020 BrianYi, All rights reserved
 */
#pragma once
#include <stdio.h>
#include <string.h>
#include <string>
#include <assert.h>
#include <unordered_map>
#include <mutex>
#include <atomic>
#include <vector>
#include <queue>
#include <algorithm>
#include <list>
#include <atomic>

#if __linux__
#include <unistd.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <sys/time.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <endian.h>
#include <pthread.h>
#include <sys/epoll.h>
#include <semaphore.h>
#endif

#if __linux__
#define ntohll		be64toh
#define htonll		htobe64
#define msleep(ms)	usleep(1000 * ms)
#endif


inline uint64_t get_timestamp_ms( )
{
	struct timeval tv;
	gettimeofday( &tv, nullptr );
	return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

#if WIN32
#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif
#endif
