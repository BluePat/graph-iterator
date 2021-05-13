#ifndef ITERATOR_H
#define ITERATOR_H

#include <vector>

#include "../model/graph.h"

/** Base class used for deriving DFS and BFS iterators. */
class Iterator {

public:

    /**Pure virtual funcion, places a vertex with the lowest int value onto the iterato's data structure. */
    virtual void reset() = 0;

    /** Pure virtual funcion, provides the implementaion of the iterator move. */
    virtual void next() = 0;

    /** Pure virtual funcion, returns int value of currently processed vertex. */
    virtual int currentKey() = 0;

    /** Returns true if all verticis have been visited. */
    virtual bool isEnd() = 0;
};

#endif
