/* indent - Indent a Brainfuck program
 * Copyright (C) 2008-2020  Andrea Bolognani <eof@kiyuko.org>
 * This file is part of Cattle
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * Homepage: https://kiyuko.org/software/cattle
 */

#include <glib.h>
#include <glib-object.h>
#include <cattle/cattle.h>
#include "common.h"

static void
indent (CattleProgram *program)
{
    CattleInstruction        *first;
    CattleInstruction        *current;
    CattleInstruction        *next;
    CattleInstructionValue    value;
    g_autoptr (CattleBuffer)  input = NULL;
    g_autoptr (GSList)        stack = NULL;
    gulong                    level;
    gulong                    quantity;
    gulong                    size;
    gulong                    i;

    /* Start at indentation level 0 */
    level = 0;

    first = cattle_program_get_instructions (program);
    g_object_ref (first);
    current = first;

    while (current != NULL)
    {
        value = cattle_instruction_get_value (current);
        quantity = cattle_instruction_get_quantity (current);

        /* Decrease the indentation level at the end of a loop */
        if (value == CATTLE_INSTRUCTION_LOOP_END)
        {
            level--;
        }

        /* Print two spaces for each level of indentation */
        for (i = 0; i < level; i++)
        {
            g_print ("  ");
        }

        /* Print the correct number of instructions */
        for (i = 0; i < quantity; i++)
        {
            g_print ("%c", value);
        }

        /* End the line */
        g_print ("\n");

        /* Increase the indentation level at the beginning of a loop */
        if (value == CATTLE_INSTRUCTION_LOOP_BEGIN)
        {
            level++;
        }

        switch (value)
        {
            case CATTLE_INSTRUCTION_LOOP_BEGIN:

                /* Push the next instruction on top of the stack */
                next = cattle_instruction_get_next (current);
                stack = g_slist_prepend (stack, next);

                /* Start indenting the loop */
                next = cattle_instruction_get_loop (current);
                g_object_unref (current);
                current = next;

                break;

            case CATTLE_INSTRUCTION_LOOP_END:

                g_assert (stack != NULL);

                /* Pop the next instruction off the stack */
                next = CATTLE_INSTRUCTION (stack->data);
                stack = g_slist_delete_link (stack, stack);
                g_object_unref (current);
                current = next;

                break;

            default:

                /* Go on with the next instruction */
                next = cattle_instruction_get_next (current);
                g_object_unref (current);
                current = next;

                break;
        }
    }

    g_object_unref (first);

    input = cattle_program_get_input (program);
    size = cattle_buffer_get_size (input);

    /* Print input if available */
    if (size > 0)
    {
        g_print ("!");

        for (i = 0; i < size; i++)
        {
            value = cattle_buffer_get_value (input, i);

            g_print ("%c", value);
        }
    }
}

gint
main (gint    argc,
      gchar **argv)
{
    g_autoptr (CattleProgram) program = NULL;
    g_autoptr (CattleBuffer)  buffer = NULL;
    g_autoptr (GError)        error = NULL;

    g_set_prgname ("indent");

    if (argc != 2)
    {
        g_warning ("Usage: %s FILENAME", argv[0]);

        return 1;
    }

    error = NULL;
    buffer = read_file_contents (argv[1], &error);

    if (error != NULL)
    {
        g_warning ("%s: %s", argv[1], error->message);

        return 1;
    }

    /* Create a new program */
    program = cattle_program_new ();

    /* Load the program from file, aborting on error */
    error = NULL;
    if (!cattle_program_load (program, buffer, &error))
    {
        g_warning ("Load error: %s", error->message);

        return 1;
    }

    /* Indent the program */
    indent (program);

    return 0;
}
