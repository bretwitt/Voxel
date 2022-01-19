#include "LoadChunkEvent.h"

LoadChunkEvent::LoadChunkEvent(Chunk *chunk) : Event("LoadChunk") {
    this->chunk = chunk;
}
