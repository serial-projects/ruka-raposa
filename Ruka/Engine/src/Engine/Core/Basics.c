/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */

#include "Engine/Core/Basics.h"
#include "Engine/Redirects/NK.h"
#include "Engine/Config.h"

/** NOTE: WE need to add this. */
#include <stdio.h>

EN_CoreBasics*
EN_CoreBasicsNew()
{
    EN_CoreBasics* new_basics =
        (EN_CoreBasics*)(
            NK_AllocatorGet(sizeof(EN_CoreBasics))
        );
    return new_basics;
}

void
EN_CoreBasicsFree(
    EN_CoreBasics* basics
)
{
    NK_AllocatorFree(basics);
}

typedef
void(*NK_ValidatorListenerCallback)(
    NK_ValidatorContent* content,
    const NK_C8* message
);

static
void
P_EN_CoreBasicsConstructAttachDebugListenerOnValidatorDebugListener(
    NK_ValidatorContent* content,
    const NK_C8* message
)
{
    printf(
        "[%f] [TC: %lu / DC: %lu] [Debug]       %s\n",
        (EN_F32)(content->buffer_counter)/(EN_F32)(content->buffer_limit),
        ((EN_CoreBasics*)(content->userdata))->tick_counter,
        ((EN_CoreBasics*)(content->userdata))->draw_counter,
        message
    );
}

static
void
P_EN_CoreBasicsConstructAttachDebugListenerOnValidatorLogListener(
    NK_ValidatorContent* content,
    const NK_C8* message
)
{
    printf(
        "[%f] [TC: %lu / DC: %lu] [Log]         %s\n",
        (EN_F32)(content->buffer_counter)/(EN_F32)(content->buffer_limit),
        ((EN_CoreBasics*)(content->userdata))->tick_counter,
        ((EN_CoreBasics*)(content->userdata))->draw_counter,
        message
    );
}

static
void
P_EN_CoreBasicsConstructAttachDebugListenerOnValidatorWarningListener(
    NK_ValidatorContent* content,
    const NK_C8* message
)
{
    printf(
        "[%f] [TC: %lu / DC: %lu] [Warning]     %s\n",
        (EN_F32)(content->buffer_counter)/(EN_F32)(content->buffer_limit),
        ((EN_CoreBasics*)(content->userdata))->tick_counter,
        ((EN_CoreBasics*)(content->userdata))->draw_counter,
        message
    );
}

static
void
P_EN_CoreBasicsConstructAttachDebugListenerOnValidatorErrorListener(
    NK_ValidatorContent* content,
    const NK_C8* message
)
{
    printf(
        "[%f] [TC: %lu / DC: %lu] [Error]       %s\n",
        (EN_F32)(content->buffer_counter)/(EN_F32)(content->buffer_limit),
        ((EN_CoreBasics*)(content->userdata))->tick_counter,
        ((EN_CoreBasics*)(content->userdata))->draw_counter,
        message
    );
}

static
void
P_EN_CoreBasicsConstructAttachDebugListenerOnValidator(
    EN_CoreBasics* basics
)
{
    NK_ValidatorAddListener(
        &basics->master_validator,
        NK_VALIDATOR_LEVEL_DEBUG,
        P_EN_CoreBasicsConstructAttachDebugListenerOnValidatorDebugListener
    );
    NK_ValidatorAddListener(
        &basics->master_validator,
        NK_VALIDATOR_LEVEL_LOG,
        P_EN_CoreBasicsConstructAttachDebugListenerOnValidatorLogListener
    );
    NK_ValidatorAddListener(
        &basics->master_validator,
        NK_VALIDATOR_LEVEL_WARNING,
        P_EN_CoreBasicsConstructAttachDebugListenerOnValidatorWarningListener
    );
    NK_ValidatorAddListener(
        &basics->master_validator,
        NK_VALIDATOR_LEVEL_ERROR,
        P_EN_CoreBasicsConstructAttachDebugListenerOnValidatorErrorListener
    );
}

void
EN_CoreBasicsConstruct(
    EN_CoreBasics* basics
)
{
    /** NOTE: We can simply set everything to zero. */
    NK_RedirectMemset(
        basics,
        0,
        sizeof(EN_CoreBasics)
    );

    /**
     * NOTE: We need to define an rate for the game.
     *  Why `draw_rate` is 25? Because when the game is starting, we want to do
     *  more `tick` than `draw`, the loading screen is less important than for
     *  example, loading the cache.
     */
    basics->draw_rate = 25;
    basics->tick_rate = 60;

    /**
     * NOTE: This validator holds an pointer to the `EN_CoreBasics` attached to
     * it. It is to have access to better debug messages.
     */
    NK_ValidatorConstruct(
        &basics->master_validator,
        EN_CONFIG_BASICS_MASTER_VALIDATOR_CAPACITY
    );

    NK_ValidatorAssignUserdata(
        &basics->master_validator,
        (void*)(basics)
    );

    #ifdef EN_CONFIG_BASICS_MASTER_VALIDATOR_DEBUG
        /**
         * NOTE: When this is enabled (during compilation time, the -d/-debug)
         * debug becomes redundant and won't do anything inside the code.
         */
        P_EN_CoreBasicsConstructAttachDebugListenerOnValidator(
            basics
        );
    #endif
}

void
EN_CoreBasicsDestruct(
    EN_CoreBasics* basics
)
{
    NK_ValidatorDestruct(
        &basics->master_validator
    );
    NK_RedirectMemset(
        basics,
        0,
        sizeof(EN_CoreBasics)
    );
}