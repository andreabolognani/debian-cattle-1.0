
/* Generated data (by glib-mkenums) */


/* enumerations from "cattle-error.h" */
#include "cattle-error.h"

GType
cattle_error_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GEnumValue values[] = {
            { CATTLE_ERROR_BAD_UTF8, "CATTLE_ERROR_BAD_UTF8", "bad-utf8" },
            { CATTLE_ERROR_IO, "CATTLE_ERROR_IO", "io" },
            { CATTLE_ERROR_UNBALANCED_BRACKETS, "CATTLE_ERROR_UNBALANCED_BRACKETS", "unbalanced-brackets" },
            { CATTLE_ERROR_INPUT_OUT_OF_RANGE, "CATTLE_ERROR_INPUT_OUT_OF_RANGE", "input-out-of-range" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("CattleError", values);
    }
    return etype;
}

/* enumerations from "cattle-instruction.h" */
#include "cattle-instruction.h"

GType
cattle_instruction_value_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GEnumValue values[] = {
            { CATTLE_INSTRUCTION_NONE, "CATTLE_INSTRUCTION_NONE", "none" },
            { CATTLE_INSTRUCTION_MOVE_LEFT, "CATTLE_INSTRUCTION_MOVE_LEFT", "move-left" },
            { CATTLE_INSTRUCTION_MOVE_RIGHT, "CATTLE_INSTRUCTION_MOVE_RIGHT", "move-right" },
            { CATTLE_INSTRUCTION_INCREASE, "CATTLE_INSTRUCTION_INCREASE", "increase" },
            { CATTLE_INSTRUCTION_DECREASE, "CATTLE_INSTRUCTION_DECREASE", "decrease" },
            { CATTLE_INSTRUCTION_LOOP_BEGIN, "CATTLE_INSTRUCTION_LOOP_BEGIN", "loop-begin" },
            { CATTLE_INSTRUCTION_LOOP_END, "CATTLE_INSTRUCTION_LOOP_END", "loop-end" },
            { CATTLE_INSTRUCTION_READ, "CATTLE_INSTRUCTION_READ", "read" },
            { CATTLE_INSTRUCTION_PRINT, "CATTLE_INSTRUCTION_PRINT", "print" },
            { CATTLE_INSTRUCTION_DEBUG, "CATTLE_INSTRUCTION_DEBUG", "debug" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("CattleInstructionValue", values);
    }
    return etype;
}

/* enumerations from "cattle-configuration.h" */
#include "cattle-configuration.h"

GType
cattle_on_eof_action_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GEnumValue values[] = {
            { CATTLE_ON_EOF_STORE_ZERO, "CATTLE_ON_EOF_STORE_ZERO", "store-zero" },
            { CATTLE_ON_EOF_STORE_EOF, "CATTLE_ON_EOF_STORE_EOF", "store-eof" },
            { CATTLE_ON_EOF_DO_NOTHING, "CATTLE_ON_EOF_DO_NOTHING", "do-nothing" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("CattleOnEOFAction", values);
    }
    return etype;
}

/* Generated data ends here */

