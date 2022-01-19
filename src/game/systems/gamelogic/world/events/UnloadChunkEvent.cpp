#include "UnloadChunkEvent.h"

UnloadChunkEvent::UnloadChunkEvent(Chunk *chunk) : Event("UnloadChunk") {
    this->chunk = chunk;
}
