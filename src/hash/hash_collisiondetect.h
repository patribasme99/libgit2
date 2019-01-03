/*
 * Copyright (C) the libgit2 contributors. All rights reserved.
 *
 * This file is part of libgit2, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included COPYING file.
 */

#ifndef INCLUDE_hash_hash_collisiondetect_h__
#define INCLUDE_hash_hash_collisiondetect_h__

#include "hash.h"
#include "sha1dc/sha1.h"

struct git_hash_ctx {
	SHA1_CTX c;
};

#define git_hash_ctx_init(ctx) git_hash_init(ctx)
#define git_hash_ctx_cleanup(ctx)

GIT_INLINE(int) git_hash_global_init(void)
{
	return 0;
}

GIT_INLINE(int) git_hash_init(git_hash_ctx *ctx)
{
	assert(ctx);
	SHA1DCInit(&ctx->c);
	return 0;
}

GIT_INLINE(int) git_hash_update(git_hash_ctx *ctx, const void *data, size_t len)
{
	assert(ctx);
	SHA1DCUpdate(&ctx->c, data, len);
	return 0;
}

GIT_INLINE(int) git_hash_final(git_oid *out, git_hash_ctx *ctx)
{
	assert(ctx);
	if (SHA1DCFinal(out->id, &ctx->c)) {
		giterr_set(GITERR_SHA1, "SHA1 collision attack detected");
		return -1;
	}

	return 0;
}

#endif
