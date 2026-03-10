/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef NKCoreValidator_h
#define NKCoreValidator_h

#include "NK/Types/Containers/Vector.h"

/**
 * Due the nature of the validator holding ephemeral messages, it makes no
 * sense to be holding messages forever, it would only clog the system.
 */
#include "NK/Types/String/Dynamic.h"

/**
 * @brief This is the function that is called when the `NK_Validator` has an 
 * `Broadcast`, each broadcast has a level(s), and the `NK_ValidatorListener`
 * contains the *TUNED* channels the `NK_ValidatorListener` is listening to.
 */
typedef
void(*NK_ValidatorCallback)(
    NK_Validator* validator,
    void* userdata
);

/**
 * @brief This is a listener, it contains an `NK_ValidatorCallback` and a 
 * `NK_U8` holding the channels it can listen to.
 */
typedef struct NK_ValidatorListener
{
    NK_ValidatorCallback callback;
    /**
     * @brief There are a few channels you can tune: DEBUG, LOG, WARNING, etc.
     */
    NK_U8 channels_tuned;
} NK_ValidatorListener;

/**
 * @brief This is a union of a logger and a validator. You can have: userdata,
 * code (holds the current state) and the buffer containing all the messages.
 */
typedef struct NK_Validator
{
    /**
     * @brief Despite this being an `NK_Vector` what the `NK_Validator` does is
     * a circular buffer, it means the log messages kinda wrap around the limit
     * imposed on the `NK_ValidatorConstruct`, this guarantees that we don't 
     * need to be resizing things around.
     */
    NK_DynamicString* buffer;

    /**
     * @brief How many messages it can contain.
     */
    NK_Size buffer_limit;

    /**
     * @brief How many messages there is, this is a counter, means each 
     * message is actually counted.
     */
    NK_Size buffer_index;

    /**
     * @brief Contain all the listeners.
     */
    NK_Vector listeners;
} NK_Validator;

/**
 * @brief Creates an new `NK_Validator` on the heap.
 */
NK_Validator*
NK_ValidatorNew();

/**
 * @brief Frees an `NK_Validator` created by `NK_ValidatorNew`
 * @warning Does not imply on `NK_ValidatorDestruct`!
 */
void
NK_ValidatorFree(
    NK_Validator* validator
);

/**
 * @brief Construct the `NK_Validator` object, allocates the buffers and all.
 */
void
NK_ValidatorConstruct(
    NK_Validator* validator,
    const NK_Size buffer_limit
);

/**
 * @brief Desconstruct the buffer `NK_Validator`, frees the strings and all.
 */
void
NK_ValidatorDestruct(
    NK_Validator* validator
);

#endif