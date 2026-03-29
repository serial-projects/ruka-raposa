/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#include "3xJson/Decoder/Tokenizer/EatToken.h"

#include "3xJson/Decoder/Tokenizer.h"
#include "3xJson/Decoder/Tokenizer/GetCharacter.h"
#include "3xJson/Decoder/Tokenizer/Rewind.h"
#include "3xJson/Redirects.h"

const XJ_Result
XJ_DecoderTokenizerEatToken(
    XJ_DecoderTokenizer* tokenizer,
    const XJ_S32 entrypoint
)
{
    XJ_Result good = true;
    XJ_S32 cc;
    NK_DynamicStringPush(&tokenizer->token, (XJ_C8)(entrypoint));
top_position:
    cc = XJ_DecoderTokenizerGetCharacter(tokenizer);
    if(cc != -1)
    {
        switch(cc)
        {
            case ' ':
            case '\t':
            case '\n':
            case '\r':
                break;
            case '\'':
            case '"':
            case '{':
            case '}':
            case '[':
            case ']':
                /** This leaves to the next stage to check up. */
                XJ_DecoderTokenizerRewind(tokenizer, 1);
                break;
            default:
                /** Build the token. */
                NK_DynamicStringPush(&tokenizer->token, (XJ_C8)(entrypoint));
                goto top_position;
        }
    }

    /** NOTE: For now, this should always return good. */
    return good;
}