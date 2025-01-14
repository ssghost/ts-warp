/* ------------------------------------------------------------------------------------------------------------------ */
/* TS-Pass - Password encoder for TS-Warp                                                                             */
/* ------------------------------------------------------------------------------------------------------------------ */

/*
* Copyright (c) 2021-2023, Mikhail Zakharov <zmey20000@yahoo.com>
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
* following conditions are met:
*
* 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following
*    disclaimer.
*
* 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
*    the following disclaimer in the documentation and/or other materials provided with the distribution.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
* INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
* WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


/* ------------------------------------------------------------------------------------------------------------------ */

/* TODO: Read password from stdin with echo off to hide plaintext password */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#include "xedec.h"


/* ------------------------------------------------------------------------------------------------------------------ */
int main(int argc, char* argv[]) {
    char *xkey = NULL;
    char *pref = XEDEC_TSW01;
    char *result = NULL;

    if (argc != 2) {
        printf("Usage:\n\tts_pass Password2Encode\n\n");
        exit(1);
    }

    xkey = init_xcrypt(XEDEC_XKEY_LEN);
    if (!(result = xencrypt(xkey, pref, argv[1]))) {
        printf("Error encrypting the password!\n");
        exit(1);
    }
    printf("%s\n", result);
    
    free(xkey);
    free(result);
    exit(0);
}
