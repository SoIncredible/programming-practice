#pragma once

template <typename T>
// 结构体和Class的区别是什么?
struct Node
{
    T *data;
    Node<T> *next;

    T GetData()
    {
        return *data;
    };
};
