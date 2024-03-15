/*
 * src/wh_flash.c
 *
 * Simple helper library
 *
 */

#include <stddef.h>     /* For NULL */
#include <string.h>     /* For memset, memcpy */

#include "wolfhsm/wh_common.h"
#include "wolfhsm/wh_error.h"

#include "wolfhsm/wh_nvm.h"


int wh_Nvm_Init(whNvmContext* context, const whNvmConfig *config)
{
    if (    (context == NULL) ||
            (context->cb == NULL) ) {
        return WH_ERROR_BADARGS;
    }

    /* No callback? Return ABORTED */
    if (context->cb->Init == NULL) {
        return WH_ERROR_ABORTED;
    }
    return context->cb->Init(context->context, config);
}

int wh_Nvm_Cleanup(whNvmContext* context)
{
    if (    (context == NULL) ||
            (context->cb == NULL) ) {
        return WH_ERROR_BADARGS;
    }

    /* No callback? Return ABORTED */
    if (context->cb->Cleanup == NULL) {
        return WH_ERROR_ABORTED;
    }
    return context->cb->Cleanup(context->context);
}

int wh_Nvm_GetAvailable(whNvmContext* context,
        uint32_t *out_avail_size, whNvmId *out_avail_objects,
        uint32_t *out_reclaim_size, whNvmId *out_reclaim_objects)
{
    if (    (context == NULL) ||
            (context->cb == NULL) ) {
        return WH_ERROR_BADARGS;
    }

    /* No callback? Return ABORTED */
    if (context->cb->GetAvailable == NULL) {
        return WH_ERROR_ABORTED;
    }
    return context->cb->GetAvailable(context->context,
            out_avail_size, out_avail_objects,
            out_reclaim_size, out_reclaim_objects);
}


int wh_Nvm_AddObject(whNvmContext* context, whNvmMetadata *meta,
        whNvmSize data_len, const uint8_t* data)
{
    if (    (context == NULL) ||
            (context->cb == NULL) ) {
        return WH_ERROR_BADARGS;
    }

    /* No callback? Return ABORTED */
    if (context->cb->AddObject == NULL) {
        return WH_ERROR_ABORTED;
    }
    return context->cb->AddObject(context->context, meta, data_len, data);
}

int wh_Nvm_List(whNvmContext* context,
        whNvmAccess access, whNvmFlags flags, whNvmId start_id,
        whNvmId *out_count, whNvmId *out_id)
{
    if (    (context == NULL) ||
            (context->cb == NULL) ) {
        return WH_ERROR_BADARGS;
    }

    /* No callback? Return ABORTED */
    if (context->cb->List == NULL) {
        return WH_ERROR_ABORTED;
    }
    return context->cb->List(context->context, access, flags, start_id,
            out_count, out_id);
}

int wh_Nvm_GetMetadata(whNvmContext* context, whNvmId id,
        whNvmMetadata* meta)
{
    if (    (context == NULL) ||
            (context->cb == NULL) ) {
        return WH_ERROR_BADARGS;
    }

    /* No callback? Return ABORTED */
    if (context->cb->GetMetadata == NULL) {
        return WH_ERROR_ABORTED;
    }
    return context->cb->GetMetadata(context->context, id, meta);
}


int wh_Nvm_DestroyObjects(whNvmContext* context, whNvmId list_count,
        const whNvmId* id_list)
{
    if (    (context == NULL) ||
            (context->cb == NULL) ) {
        return WH_ERROR_BADARGS;
    }

    /* No callback? Return ABORTED */
    if (context->cb->DestroyObjects == NULL) {
        return WH_ERROR_ABORTED;
    }
    return context->cb->DestroyObjects(context->context, list_count, id_list);
}


int wh_Nvm_Read(whNvmContext* context, whNvmId id, whNvmSize offset,
        whNvmSize data_len, uint8_t* data)
{
    if (    (context == NULL) ||
            (context->cb == NULL) ) {
        return WH_ERROR_BADARGS;
    }

    /* No callcack? Return ABORTED */
    if (context->cb->Read == NULL) {
        return WH_ERROR_ABORTED;
    }
    return context->cb->Read(context->context, id, offset, data_len, data);
}

