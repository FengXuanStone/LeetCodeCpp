//
// Created by fengxuan on 2016/9/12.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

using namespace std;
#define BLOCK_SIZE 24
void *first_block=NULL;

//brk将break指针直接设置为某个地址，而sbrk将break从当前位置移动increment所指定的增量。
//brk在执行成功时返回0，否则返回-1并设置errno为ENOMEM；
//sbrk成功时返回break移动之前所指向的地址，否则返回(void *)-1。

//一个小技巧是，如果将increment设置为0，则可以获得当前break的地址。

typedef struct s_block *t_block;
struct t_block {
    size_t size;  /* 数据区大小 */
    t_block prev; /* 指向上个块的指针 */
    t_block next; /* 指向下个块的指针 */
    int free;     /* 是否是空闲块 */
    int padding;  /* 填充4字节，保证meta块长度为8的倍数 */
    void *ptr;    /* Magic pointer，指向data */
    char data[1];  /* 这是一个虚拟字段，表示数据块的第一个字节，长度不应计入meta */
};

/* First fit */
t_block find_block(t_block *last, size_t size) {
    t_block b = first_block;
    while(b && !(b->free && b->size >= size)) {
        *last = b;
        b = b->next;
    }
    return b;
}
//堆空间用尽， 开辟新的block
t_block extend_heap(t_block last, size_t s) {
    t_block b;
    b = sbrk(0);
    if(sbrk(BLOCK_SIZE + s) == (void *)-1)
        return NULL;
    b->size = s;
    b->next = NULL;
    if(last)
        last->next = b;
    b->free = 0;
    return b;
}
//如果一个空间大于需要的空间，则分裂
void split_block(t_block b, size_t s) {
    t_block new_block;
    new_block = b->data + s;
    new_block->size = b->size - s - BLOCK_SIZE ;
    new_block->next = b->next;
    new_block->free = 1;
    b->size = s;
    b->next = new_block;
}

size_t align8(size_t s) {
    if(s & 0x7 == 0)
        return s;
    return ((s >> 3) + 1) << 3;
}

void* myMalloc(size_t size) {
    t_block b, last;
    size_t s;
    /* 对齐地址 */
    s = align8(size);
    if(first_block) {
        /* 查找合适的block */
        last = first_block;
        b = find_block(&last, s);
        if(b) {
            /* 如果可以，则分裂 */
            if ((b->size - s) >= ( BLOCK_SIZE + 8))
                split_block(b, s);
            b->free = 0;
        } else {
            /* 没有合适的block，开辟一个新的 */
            b = extend_heap(last, s);
            if(!b)
                return NULL;
        }
    } else {
        b = extend_heap(NULL, s);
        //函数原型：static void *extend_heap(size_t words);
        //拓展堆的可用空间，返回原堆顶地址(mem_brk),失败返回NULL
        if(!b)
            return NULL;
        first_block = b;
    }
    return b->data;
}

void *calloc(size_t number, size_t size) {
    size_t *new_block;
    size_t s8, i;
    new_block = malloc(number * size);
    if(new_block) {
        s8 = align8(number * size) >> 3;
        for(i = 0; i < s8; i++)
            new_block[i] = 0;
    }
    return new_block;
}

//====================================================free function=====================================================

t_block get_block(void *p) {
    char *tmp;
    tmp = p;
    return (p = tmp -= BLOCK_SIZE);
}

int valid_addr(void *p) {
    if(first_block) {
        if(p > first_block && p < sbrk(0)) {
            return p == (get_block(p))->ptr;
        }
    }
    return 0;
}

t_block fusion(t_block b) {
    if (b->next && b->next->free) {
        b->size += BLOCK_SIZE + b->next->size;
        b->next = b->next->next;
        if(b->next)
            b->next->prev = b;
    }
    return b;
}

void free(void *p) {
    t_block b;
    if(valid_addr(p)) {
        b = get_block(p);
        b->free = 1;
        if(b->prev && b->prev->free)
            b = fusion(b->prev);
        if(b->next)
            fusion(b);
        else {
            if(b->prev)
                b->prev->prev = NULL;
            else
                first_block = NULL;
            brk(b);
        }
    }
}


int main() {
    cout << "Hello world" << endl;


    return 0;
}
