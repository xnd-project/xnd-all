/*
 * BSD 3-Clause License
 *
 * Copyright (c) 2017, plures
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#include <stdio.h>
#include <assert.h>
#include <setjmp.h>
#include "ndtypes.h"
#include "bpgrammar.h"
#include "bplexer.h"


#ifdef YYDEBUG
int bpdebug = 1;
#endif


/* The yy_fatal_error() function of flex calls exit(). We intercept the function
   and do a longjmp() for proper error handling. */
jmp_buf ndt_bp_lexerror;


ndt_t *
ndt_from_bpformat(const char *input, ndt_context_t *ctx)
{
    volatile yyscan_t scanner = NULL;
    volatile YY_BUFFER_STATE state = NULL;
    char *buffer;
    size_t size;
    ndt_t *ast = NULL;
    int ret;

    size = strlen(input);
    if (size > INT_MAX / 2) {
        /* The code generated by flex truncates size_t in several places. */
        ndt_err_format(ctx, NDT_LexError, "maximum input length: %s", INT_MAX/2);
        return NULL;
    }

    buffer = ndt_alloc(1, size+2);
    if (buffer == NULL) {
        return ndt_memory_error(ctx);
    }
    memcpy(buffer, input, size);
    buffer[size] = '\0';
    buffer[size+1] = '\0';

    if (setjmp(ndt_bp_lexerror) == 0) {
        if (bplex_init_extra(ctx, (yyscan_t *)&scanner) != 0) {
            ndt_err_format(ctx, NDT_LexError, "lexer initialization failed");
            ndt_free(buffer);
            return NULL;
        }

        state = bp_scan_buffer(buffer, size+2, scanner);
        state->yy_bs_lineno = 1;
        state->yy_bs_column = 1;

        ret = bpparse(scanner, &ast, ctx);
        bp_delete_buffer(state, scanner);
        bplex_destroy(scanner);
        ndt_free(buffer);

        if (ret == 2) {
            ndt_err_format(ctx, NDT_MemoryError, "out of memory");
        }

        return ast;
    }
    else { /* fatal lexer error */
        if (state) {
            ndt_free(state);
        }
        if (scanner) {
            bplex_destroy(scanner);
        }
        ndt_free(buffer);
        ndt_err_format(ctx, NDT_MemoryError, "flex: internal lexer error");
        return NULL;
    }
}
