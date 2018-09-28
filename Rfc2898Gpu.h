/*****************************************************************************
 * Copyright (c) 2013-2016 Intel Corporation
 * All rights reserved.
 *
 * WARRANTY DISCLAIMER
 *
 * THESE MATERIALS ARE PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL INTEL OR ITS
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THESE
 * MATERIALS, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Intel Corporation is the author of the Materials, and requests that all
 * problem reports or change requests be submitted to it directly
 *****************************************************************************/

typedef unsigned int uint;
typedef unsigned char uchar;

#define KEYLEN 15
#define OUTLEN 48 //32 bytes for AES key and 16 for iv
#define SALTLEN 8

uchar salt[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

uint numberOfHashesPerKernelExecution = 1024;
uint iterationsCount = 1000;

//structs below in OpenCL code are defined in the *.cl file and not in *.h so they are duplicated here so that they are accessible in host code
typedef struct {
	uint  length;
	uchar v[KEYLEN];
} pbkdf2_password;

typedef struct {
	uint  v[(OUTLEN + 3) / 4]; /* output of PBKDF2 */
} pbkdf2_hash;

typedef struct {
	uint  iterations;
	uint  outlen;
	uint  skip_bytes;
	uchar length;
	uchar salt[SALTLEN];
} pbkdf2_salt;